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
    time = rand() % 1000 + 5; // between 1-50 clock cycles
}

std::vector<int> Request::get_IP_in()
{
    std::vector<int> ip;
    ip.push_back(a1);
    ip.push_back(a2);
    ip.push_back(a3);
    ip.push_back(a4);
    return ip;
}

std::vector<int> Request::get_IP_out()
{
    std::vector<int> ip;
    ip.push_back(b1);
    ip.push_back(b2);
    ip.push_back(b3);
    ip.push_back(b4);
    return ip;
}

int Request::get_time()
{
    return time;
}

void Request::time_dec()
{
    time--;
}

bool Request::complete()
{
    if (time <= 0)
    {
        return true;
    }
    return false;
}
