test : test.cc
	g++ -std=c++17 $^ -o $@ -lspdlog -lfmt -pthread
.PHONY : clean
clean :
	rm -f test