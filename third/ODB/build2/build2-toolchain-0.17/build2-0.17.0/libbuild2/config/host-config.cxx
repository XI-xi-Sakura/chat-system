// file      : libbuild2/config/host-config.cxx.in -*- C++ -*-
// license   : MIT; see accompanying LICENSE file

namespace build2
{
  namespace config
  {
    // This is a raw string literal, in case you are unfamiliar.
    //
    extern const char host_config[] = R"###(config.version = 1
config.config.environment = CPATH CPLUS_INCLUDE_PATH LIBRARY_PATH LD_RUN_PATH SOURCE_DATE_EPOCH GCC_EXEC_PREFIX COMPILER_PATH C_INCLUDE_PATH PATH=/usr/local/bin:/home/ubuntu/.vscode-server/cli/servers/Stable-488a1f239235055e34e673291fb8d8c810886f81/server/bin/remote-cli:/home/ubuntu/miniconda3/bin:/home/ubuntu/miniconda3/condabin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin LD_LIBRARY_PATH
config.cc.poptions = [null]
config.cc.coptions = -O3
config.cc.loptions = [null]
config.cc.aoptions = [null]
config.cc.libs = [null]
config.cxx = g++
config.cxx.poptions = [null]
config.cxx.coptions = [null]
config.cxx.loptions = [null]
config.cxx.aoptions = [null]
config.cxx.libs = [null]
config.c = gcc
config.c.poptions = [null]
config.c.coptions = [null]
config.c.loptions = [null]
config.c.aoptions = [null]
config.c.libs = [null]
config.bin.rpath = /usr/local/lib/
config.bin.rpath_link = [null]
)###";
    extern const char build2_config[] = R"###(config.version = 1
config.config.environment = CPATH CPLUS_INCLUDE_PATH LIBRARY_PATH LD_RUN_PATH SOURCE_DATE_EPOCH GCC_EXEC_PREFIX COMPILER_PATH C_INCLUDE_PATH PATH=/usr/local/bin:/home/ubuntu/.vscode-server/cli/servers/Stable-488a1f239235055e34e673291fb8d8c810886f81/server/bin/remote-cli:/home/ubuntu/miniconda3/bin:/home/ubuntu/miniconda3/condabin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin LD_LIBRARY_PATH
config.build2.libpkgconf = false
config.cc.poptions = [null]
config.cc.coptions = -O3
config.cc.loptions = [null]
config.cc.aoptions = [null]
config.cc.libs = [null]
config.cxx = g++
config.cxx.poptions = [null]
config.cxx.coptions = [null]
config.cxx.loptions = [null]
config.cxx.aoptions = [null]
config.cxx.libs = [null]
config.c = gcc
config.c.poptions = [null]
config.c.coptions = [null]
config.c.loptions = [null]
config.c.aoptions = [null]
config.c.libs = [null]
config.bin.lib = shared
config.bin.exe.lib = shared static
config.bin.liba.lib = static shared
config.bin.libs.lib = shared static
config.bin.rpath = /usr/local/lib/
config.bin.rpath_link = [null]
config.install.relocatable = false
config.install.private = [null]
config.install.filter = [null]
config.install.cmd = install
config.install.options = [null]
config.install.mode = 644
config.install.dir_mode = 755
config.install.sudo = sudo
config.install.root = /usr/local/
config.install.data_root = root/
config.install.exec_root = root/
config.install.exec_root.mode = 755
config.install.sbin = exec_root/sbin/
config.install.bin = exec_root/bin/
config.install.lib = exec_root/lib/<private>/
config.install.libexec = exec_root/libexec/<private>/<project>/
config.install.pkgconfig = lib/pkgconfig/
config.install.pkgconfig.mode = 644
config.install.etc = data_root/etc/
config.install.include = data_root/include/<private>/
config.install.include_arch = include/
config.install.share = data_root/share/
config.install.data = share/<private>/<project>/
config.install.buildfile = share/build2/export/<project>/
config.install.doc = share/doc/<private>/<project>/
config.install.legal = doc/
config.install.man = share/man/
config.install.man1 = man/man1/
)###";

    extern const char host_config_no_warnings[] = R"###(config.version = 1
config.config.environment = CPATH CPLUS_INCLUDE_PATH LIBRARY_PATH LD_RUN_PATH SOURCE_DATE_EPOCH GCC_EXEC_PREFIX COMPILER_PATH C_INCLUDE_PATH PATH=/usr/local/bin:/home/ubuntu/.vscode-server/cli/servers/Stable-488a1f239235055e34e673291fb8d8c810886f81/server/bin/remote-cli:/home/ubuntu/miniconda3/bin:/home/ubuntu/miniconda3/condabin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin LD_LIBRARY_PATH
config.cc.poptions = [null]
config.cc.coptions = -O3
config.cc.loptions = [null]
config.cc.aoptions = [null]
config.cc.libs = [null]
config.cxx = g++
config.cxx.poptions = [null]
config.cxx.coptions = -w
config.cxx.loptions = [null]
config.cxx.aoptions = [null]
config.cxx.libs = [null]
config.c = gcc
config.c.poptions = [null]
config.c.coptions = -w
config.c.loptions = [null]
config.c.aoptions = [null]
config.c.libs = [null]
config.bin.rpath = /usr/local/lib/
config.bin.rpath_link = [null]
)###";
    extern const char build2_config_no_warnings[] = R"###(config.version = 1
config.config.environment = CPATH CPLUS_INCLUDE_PATH LIBRARY_PATH LD_RUN_PATH SOURCE_DATE_EPOCH GCC_EXEC_PREFIX COMPILER_PATH C_INCLUDE_PATH PATH=/usr/local/bin:/home/ubuntu/.vscode-server/cli/servers/Stable-488a1f239235055e34e673291fb8d8c810886f81/server/bin/remote-cli:/home/ubuntu/miniconda3/bin:/home/ubuntu/miniconda3/condabin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin LD_LIBRARY_PATH
config.build2.libpkgconf = false
config.cc.poptions = [null]
config.cc.coptions = -O3
config.cc.loptions = [null]
config.cc.aoptions = [null]
config.cc.libs = [null]
config.cxx = g++
config.cxx.poptions = [null]
config.cxx.coptions = -w
config.cxx.loptions = [null]
config.cxx.aoptions = [null]
config.cxx.libs = [null]
config.c = gcc
config.c.poptions = [null]
config.c.coptions = -w
config.c.loptions = [null]
config.c.aoptions = [null]
config.c.libs = [null]
config.bin.lib = shared
config.bin.exe.lib = shared static
config.bin.liba.lib = static shared
config.bin.libs.lib = shared static
config.bin.rpath = /usr/local/lib/
config.bin.rpath_link = [null]
config.install.relocatable = false
config.install.private = [null]
config.install.filter = [null]
config.install.cmd = install
config.install.options = [null]
config.install.mode = 644
config.install.dir_mode = 755
config.install.sudo = sudo
config.install.root = /usr/local/
config.install.data_root = root/
config.install.exec_root = root/
config.install.exec_root.mode = 755
config.install.sbin = exec_root/sbin/
config.install.bin = exec_root/bin/
config.install.lib = exec_root/lib/<private>/
config.install.libexec = exec_root/libexec/<private>/<project>/
config.install.pkgconfig = lib/pkgconfig/
config.install.pkgconfig.mode = 644
config.install.etc = data_root/etc/
config.install.include = data_root/include/<private>/
config.install.include_arch = include/
config.install.share = data_root/share/
config.install.data = share/<private>/<project>/
config.install.buildfile = share/build2/export/<project>/
config.install.doc = share/doc/<private>/<project>/
config.install.legal = doc/
config.install.man = share/man/
config.install.man1 = man/man1/
)###";
  }
}
