# docker 常用指令
## 容器操作
### 查看
```
docker ps -a
docker container ls -a
# -a 所有容器
# -q 仅显示容器 ID
```
### 删除
```
docker rm container_id
docker container rm container_id

docker container rm $(docker container ls -a -q)
```
### 启动
```
docker run  [options] [image:version]
# options:
#   -d, --detach : 运行容器于后台，并打印容器 ID
#   -e, --env list :  设置运行环境变量  -e DB_USER=myuser
#   -i, --interactive :  即使没有连接，也要保持 STDIN 打开
#   -p, --publish list :  设置于宿主机器端口映射  -p 3306:3306
#   -t, --tty : 申请终端
#   -v, --volume list :  设置与宿主机文件挂载 -v ./data:/var/lib/mysql: rw
```
### 停止
```
docker container stop container_id
docker container stop $(docker container ls -a -q)
```
## 镜像操作
### 拉取
```
docker pull image_name:version
```
### 查看
```
docker images
```
```
docker image ls -a
```
### 创建
```
docker build [options] path
# options:
#   -f, --file string : 指定构建镜像的 dockerfile
#   -t, --tag stringArray :  设置镜像名称与版本  -t myimage:version
```
### 删除
```
docker rmi image_id
docker image rm image_id
```
### 导入/导出
```
docker save -o myimage.tar myimage:latest

docker load -i myimage.tar
```
### 缓存及镜像清理
```
docker system df
docker system prune -a
```
## dockerfile 编写规则简介
样例:
```
FROM ubuntu:22.04
LABEL MAINTAINER="xixi"

ENV REDIS_VERSION=5.0.3

WORKDIR /im

RUN mkdir -p /im/data &&\
    mkdir -p /im/logs &&\
    mkdir -p /im/conf &&\
    mkdir -p /im/bin
COPY build/file_server /im/bin/
COPY depends/ /usr/lib/x86_64-linux-gnu/
EXPOSE 10001/tcp
CMD "/im/bin/file_server" "-flagfile=/im/conf/server_file.conf"
```
注释:
- FROM：注明所使用的镜像 
- LABEL：构建镜像时设置键值对，这里 MAINTAINER 表示维护人 
- ENV：用于设置镜像中的环境变量 
- WORKDIR：设定镜像中的工作路径（该目录会在镜像系统中自动创建） 
- RUN：在镜像中执行的指令 
- COPY：将宿主机中的文件拷贝到镜像系统指定路径下 
- EXPOSE：对外暴露端口 
- CMD：设置容器启动时默认执行的命令 

## dockercompose 编写规则简介
样例:
```
version:  "3.8"
services:
  mysql:
    image: mysql:8.0.39
    container_name: docker-mysql-service
    volumes:
      - ./sql/docker-entrypoint-initdb.d/
      - ./middleware/mysql/data:/var/lib/mysql:rw
      - ./middleware/mysql/logs:/var/log/mysql:rw
      - ./middleware/mysql/conf:/etc/mysql/
    environment:
      MYSQL_ROOT_PASSWORD: 123456
    ports:
      - 3306:3306
    restart: always
    depends_on:
      - etcd
```
注释:
- version：docker-compose 语法版本 
- services：要启动的服务 
- mysql：第 4 行的 mysql 为对应的服务名称，在这里其实就是个标识 
- image：来源镜像及版本 
- container_name：用户设定的容器名称 
- volumes：挂载卷，其实就是将宿主机上的指定文件或目录与镜像进行挂载。 
- environment：设定镜像中的环境变量 
- ports：宿主机与镜像的端口映射 
- restart：容器重启策略，always 表示无论退出状态如何，容器总是重新启动。 
- depends_on：启动依赖，通过依赖关系控制容器启动顺序。 
项目部署
编写项目部署文件 