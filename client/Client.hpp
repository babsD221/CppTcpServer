#ifndef TCP_CLIENT
#define TCP_CLIENT

#include <sys/socket.h>
#include <sys/types.h> 
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <vector>


class TcpClient {
public:
    TcpClient();
    void create_socket();
    void connectToServer();
    void init();
    void sendMessage(std::string message);
    void recvFromServer();
    void closeConnection();


    private:
        struct sockaddr_in m_serverAdress_in;
        int m_clientSocket;

};


#endif