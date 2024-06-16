#include <stdlib.h>
#include "Request.h"

Request::Request()
{
    a1 = rand() % 256;
    a2 = rand() % 256;
    a3 = rand() % 256;
    a4 = rand() % 256;
    b1 = rand() % 256;
    b2 = rand() % 256;
    b3 = rand() % 256;
    b4 = rand() % 256;
}

int *Request::get_IP_in()
{
    int ip[4] = {a1, a2, a3, a4};
    return ip;
}

int *Request::get_IP_out()
{
    int ip[4] = {b1, b2, b3, b4};
}

int Request::get_time()
{
    return time;
}