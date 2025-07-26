all: put get

put:
	g++ -o put put.cc -letcd-cpp-api -lcpprest
get:
	g++ -o get get.cc -letcd-cpp-api -lcpprest

.PHONY: clean
clean:
	rm -f put get