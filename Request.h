#ifndef REQUEST_H
#define REQUEST_H

class Request
{
private:
    int a1, a2, a3, a4; // ipv4 address is 4 random integers 0-255. this is IP in
    int b1, b2, b3, b4; // IP out
    int time;           // time to process request
public:
    Request(); // default constructor
    int *get_IP_in();
    int *get_IP_out();
    int get_time();
};

#endif