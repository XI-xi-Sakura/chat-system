# 默认目标，依赖 test1 和 test2 目标，执行 make 命令时会编译这两个目标
all: test1 test2

test1 : test1.cc
	g++ -std=c++17 $^ -o $@ -lspdlog -lfmt -pthread

test2 : logger.cc
	g++ -std=c++17 $^ -o $@ -lspdlog -lfmt -pthread

.PHONY : clean all

clean :
	@# 删除所有生成的可执行文件
	rm -f test1 test2