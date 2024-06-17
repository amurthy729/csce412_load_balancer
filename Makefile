CXX = g++
CPPFLAGS = -Wall -Werror -g
all: myprogram
myprogram: LoadBalancer.o Request.o Webserver.o main.o
	$(CXX) $(CPPFLAGS) -o myprogram LoadBalancer.o Request.o Webserver.o main.o
LoadBalancer.o: LoadBalancer.cpp
	$(CXX) $(CPPFLAGS) -c LoadBalancer.cpp
Request.o: Request.cpp
	$(CXX) $(CPPFLAGS) -c Request.cpp
Webserver.o: Webserver.cpp
	$(CXX) $(CPPFLAGS) -c Webserver.cpp
main.o:
	$(CXX) $(CPPFLAGS) -c main.cpp
clean:
	rm -f myprogram *.o