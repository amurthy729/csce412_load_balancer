#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "Request.h"
#include "Webserver.h"
#include <queue>
#include <vector>

class LoadBalancer
{
private:
    std::queue<Request> requests;   // requests queue
    std::vector<Webserver> servers; // server list

public:
    void assignRequest();         // assigns request to least busy server
    void addRequest(Request rq);  // adds request to requests queue
    void addServer(Webserver ws); // adds server to server list
    int requestsRemaining();
};

#endif