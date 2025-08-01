## ODB2.5 安装：
整个安装过程在3 - 5小时左右，视网络情况而定

### 安装 build2：
因为 build2 安装时，有可能会版本更新，从16变成17，或从17变18，因此注意，先从 build2 官网查看安装步骤...
安装步骤: https://build2.org/install.xhtml#nix

```PowerShell
$ curl -sSfO https://download.build2.org/0.17.0/build2-install-0.17.0.sh
$ sh build2-install-0.17.0.sh
```

安装中因为网络问题，超时失败，解决：将超时时间设置的长一些

```Shell
$ sh build2-install-0.17.0.sh --timeout 1800
```

### 安装 odb-compiler
```PowerShell
$ sudo apt-get install gcc-11-plugin-dev
$ mkdir odb-build && cd odb-build
$ bpkg create -d odb-gcc-N cc \
config.cxx=g++ \
config.cc.coptions=-O3 \
config.bin.path=/usr/lib \
config.install.root=/usr/ \
config.install.sudo=sudo 

$ cd odb-gcc-N
$ bpkg build odb@https://pkg.cppget.org/1/beta 
$ bpkg test odb
tested odb-2.5.0-b.25.1/tests/testscript{testscript}
tested odb-2.5.0-b.25.1

$ bpkg install odb
$ odb --version
bash: /usr/bin/odb: No such file or directory
#如果报错了，找不到 odb，那就在执行下边的命令
$ sudo echo 'export PATH=${PATH}:/usr/local/bin' >> ~/.bashrc
$ export PATH=${PATH}:/usr/local/bin
$ odb --version
ODB object-relational mapping (ORM) compiler for C++ 2.5.0-b.25
Copyright (c) 2009-2023 Code Synthesis Tools CC.
This is free software; see the source for copying conditions.
There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

### 安装 ODB 运行时库：
```PowerShell
dev@dev-host:~/workspace/odb-build/odb-gcc-N$ cd ..
dev@dev-host:~/workspace/odb-build$ bpkg create -d libodb-gcc-N cc \
config.cxx=g++              \
config.cc.coptions=-O3      \
config.install.root=/usr/   \
config.install.sudo=sudo 
$ cd libodb-gcc-N
$ bpkg add https://pkg.cppget.org/1/beta
$ bpkg fetch

$ bpkg build libodb
$ bpkg build libodb-mysql
```

### 安装 mysql 和客户端开发包
```C++
sudo apt install mysql-server
sudo apt install -y libmysqlclient-dev
```

#### 配置 mysql
```C++
sudo vim /etc/my.cnf 或者 /etc/mysql/my.cnf 有哪个修改哪个就行
#添加以下内容
[client]
default-character-set=utf8
[mysql]
default-character-set=utf8
[mysqld]
character-set-server=utf8
bind-address = 0.0.0.0
```

#### 修改 root 用户密码
```C++
dev@bite:~$ sudo cat /etc/mysql/debian.cnf
# Automatically generated for Debian scripts. DO NOT TOUCH!
[client]
host     = localhost
user     = debian-sys-maint
password = UWcn9v0YkrbMRc
socket   = /var/run/mysqld/mysqld.sock
[mysql_upgrade]
host     = localhost
user     = debian-sys-maint
password = UWcn9v0YkrbMRc
socket   = /var/run/mysqld/mysqld.sock
dev@bite:~$ sudo mysql -u debian-sys-maint -p
Enter password: #这里输入上边第6行看到的密码
mysql> ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'xxxxxx';
Query OK, 0 rows affected (0.01 sec)

mysql> FLUSH PRIVILEGES;
Query OK, 0 rows affected (0.01 sec)

mysql> quit
```

#### 重启 mysql，并设置开机启动
```C++
sudo systemctl restart mysql
sudo systemctl enable mysql
```

### 安装 boost profile 库
```PowerShell
$ bpkg build libodb-boost
```

#### 总体打包安装：
```PowerShell
$ bpkg install --all --recursive
```

#### 总体卸载：
```PowerShell
$ bpkg uninstall --all --recursive
```

#### 总体升级：
```PowerShell
$ bpkg fetch
$ bpkg status
$ bpkg uninstall --all --recursive
$ bpkg build --upgrade --recursive
$ bpkg install --all --recursive
```

### 测试样例：
编写数据结构文件：person.hxx

```cpp
#pragma once
#include <string>
#include <cstddef> // std::size_t
#include <boost/date_time/posix_time/posix_time.hpp>

/*
    在 C++ 中，要使用 ODB 将类声明为持久化类，需要包含 ODB 的核心头文件，并使用 #pragma db object 指令
    #pragma db object 指示 ODB 编译器将 person 类视为一个持久化类。
*/
#include <odb/core.hxx>

typedef boost::posix_time::ptime ptime;

#pragma db object
class Person {
public:
    Person(const std::string &name, int age, const ptime &update)
        : _name(name), _age(age), _update(update) {}

    void age(int val) { _age = val; }
    int age() const { return _age; }

    void name(const std::string &val) { _name = val; }
    std::string name() const { return _name; }

    void update(const ptime &update) { _update = update; }
    std::string update() { return boost::posix_time::to_simple_string(_update); }

private:
    // 将 odb::access 类作为 person 类的朋友。
    // 这是使数据库支持代码可访问默认构造函数和数据成员所必需的。
    // 如果类具有公共默认构造函数和公共数据成员或数据成员的公共访问器和修饰符，则不需要友元声明
    friend class odb::access;
    Person() {}

    // _id 成员前面的 pragma 告诉 ODB 编译器，以下成员是对象的标识符。auto 说明符指示它是数据库分配的 ID。
    #pragma db id auto // 表示 ID 字段将自动生成（通常是数据库中的主键）。
    unsigned long _id;
    unsigned short _age;
    std::string _name;
    #pragma db type("TIMESTAMP") not_null
    boost::posix_time::ptime _update;
};
// 将 ODB 编译指示组合在一起，并放在类定义之后。它们也可以移动到一个单独的标头中，使原始类完全保持不变
// #pragma db object(person)
// #pragma db member(person::_name) id

// 完成后，需要使用 odb 编译器将当前所写的代码生成数据库支持代码
// odb -d mysql --generate-query --generate-schema person.hxx

// 如果用到了 boost 库中的接口，则需要使用选项 ：--profile boost/date-time
// odb -d mysql --generate-query --generate-schema --profile boost/date-time person.hxx
```

生成数据库支持的代码文件：

```cpp
$ odb -d mysql --std c++11 --generate-query --generate-schema --profile boost/date-time person.hxx
$ ls
person-odb.cxx  person-odb.hxx  person-odb.ixx  person.hxx  person.sql
```

编写主函数代码：test.cc

```cpp
#include <string>
#include <memory>  // std::auto_ptr
#include <cstdlib> // std::exit
#include <iostream>

#include <odb/database.hxx>
#include <odb/mysql/database.hxx>

#include "person.hxx"
#include "person-odb.hxx"

int main() {
    std::shared_ptr<odb::core::database> db(
        new odb::mysql::database("root", "Zwc111...",
                                 "mytest", "127.0.0.1", 0, 0, "utf8"));
    if (!db) { return -1; }

    ptime p = boost::posix_time::second_clock::local_time();
    Person zhang("小张", 18, p);
    Person wang("小王", 19, p);

    typedef odb::query<Person> query;
    typedef odb::result<Person> result;
    {
        odb::core::transaction t(db->begin());
        size_t zid = db->persist(zhang);
        size_t wid = db->persist(wang);
        t.commit();
    }
    {
        ptime p = boost::posix_time::time_from_string("2024-05-22 09:09:39");
        ptime e = boost::posix_time::time_from_string("2024-05-22 09:13:29");
        odb::core::transaction t(db->begin());
        result r(db->query<Person>(query::update < e && query::update > p));
        for (result::iterator i(r.begin()); i != r.end(); ++i) {
            std::cout << "Hello, " << i->name() << " ";
            std::cout << i->age() << " " << i->update() << std::endl;
        }
        t.commit();
    }
    return 0;
}

// 如果用到了 boost 库中的接口，需要链接库： -lodb-boost

// c++ -o mysql_test mysql_test.cpp person-odb.cxx -lodb-mysql -lodb -lodb-boost
```

代码编译：

```cpp
$ c++ -o test test.cpp person-odb.cxx -lodb-mysql -lodb -lodb-boost
```

运行时报错：这有可能是因为库文件安装在/usr/local/lib 下了
如果前边默认设置将库安装在/usr 下，应该不会有这个问题

```cpp
$ ./test
./test: error while loading shared libraries: libodb-2.5.0-b.25.so: cannot open shared object file: No such file or directory
```

```cpp
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
```

