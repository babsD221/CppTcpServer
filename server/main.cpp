#include <iostream>
#include "Server.hpp"
#include <cstring>
#include <string>
#include <thread>


int main(int argc, char const *argv[])
{

    // create a socket
    // bind the socket to a IP port

    Server tcpServer("127.0.0.1",54000);
    std::cout<< "Hello chat app"<<std::endl;   
    char buffer[4096];

    tcpServer.init();

    tcpServer.listenToClients(100);


    for(;;)
    {
        tcpServer.acceptClients();

        memset(buffer,0,4096);
        int receivedBytes = tcpServer.receiveFromClient(buffer);
        if(receivedBytes != 0 && receivedBytes != -1) {
            std::cout <<"Received message "<< std::string(buffer)<<std::endl;
        }
    }
    tcpServer.closeConnection();
    return 0;
}
