CC = gcc
CFLAGS = -Wall -Werror
all: loadbalancer
loadbalancer: balancer.o utils.o
	$(CC) $(CFLAGS) -o loadbalancer balancer.o utils.o
balancer.o: LoadBalancer.cpp
	$(CC) $(CFLAGS) -c LoadBalancer.cpp
utils.o: 