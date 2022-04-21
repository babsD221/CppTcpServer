#include "Client.hpp"

#include <iostream>

TcpClient::TcpClient() {
    
}

void TcpClient::create_socket() {
    m_clientSocket = socket(AF_INET,SOCK_STREAM,0);
    if(m_clientSocket == -1) {
        std::cout << "Could not create socket";
    }
}

void TcpClient::connectToServer() {
    std::string serverIpAddr = "127.0.0.1";
    m_serverAdress_in.sin_port = htons(54000);
    m_serverAdress_in.sin_family = AF_INET;
    inet_pton(AF_INET, serverIpAddr.c_str(), (struct sockaddr*)&m_serverAdress_in.sin_addr);
    
    if(connect(m_clientSocket,(struct sockaddr*)&m_serverAdress_in,sizeof(m_serverAdress_in)) == -1) {
        std::cerr<<"Could not connect to server !";
    }
}

void TcpClient::sendMessage(std::string message) {
    if(send(m_clientSocket,message.c_str(),message.size() + 1,0) == -1 ) {
        std::cerr<<"Could not send message";
    }
}

void TcpClient::recvFromServer() {
    
}

void TcpClient::closeConnection() {
    int closed =close(m_clientSocket);
}

void TcpClient::init() {
    create_socket();
    connectToServer();    
}
