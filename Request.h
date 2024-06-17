#ifndef REQUEST_H
#define REQUEST_H

#include <vector>

class Request
{
private:
    int a1, a2, a3, a4; // ipv4 address is 4 random integers 0-255. this is IP in
    int b1, b2, b3, b4; // IP out
    int time;           // time to process request
public:
    Request();                     // default constructor
    std::vector<int> get_IP_in();  // return ip in
    std::vector<int> get_IP_out(); // return ip out
    int get_time();                // time remaining on request
    void time_dec();               // reduce time by 1
    bool complete();               // return if the request is complete
};

#endif