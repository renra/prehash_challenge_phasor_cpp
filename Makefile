all:
	g++ -Wall phasor_test.cpp -std=c++11 -o phasor_test
clean:
	rm -rf phasor_test
