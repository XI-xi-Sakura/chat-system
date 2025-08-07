all: registry discoverer

registry: registry.cc
	g++ -std=c++17 $^ -o $@ -letcd-cpp-api -lcpprest

discoverer: discoverer.cc
	g++ -std=c++17 $^ -o $@ -letcd-cpp-api -lcpprest

.PHONY: clean
clean:
	rm -f put get
