#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<cstdlib>
#include<WinSock2.h>
#include<Windows.h>

#pragma warning(disable:4996)
#pragma comment(lib,"ws2_32.lib")

uint16_t serverport = 8888;
std::string serverip = "112.74.40.147";

int main()
{
	std::cout << "hello client" << std::endl;
	WSADATA wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);

    struct sockaddr_in server;
    //bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(serverport); //?
    server.sin_addr.s_addr = inet_addr(serverip.c_str());
    //socklen_t len = sizeof(server);

    SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == SOCKET_ERROR)
    {
        std::cout << "socker error" << std::endl;
        return 1;
    }

    // client 要bind吗？要！只不过不需要用户显示的bind！一般有OS自由随机选择！
    // 一个端口号只能被一个进程bind，对server是如此，对于client，也是如此！
    // 其实client的port是多少，其实不重要，只要能保证主机上的唯一性就可以！
    // 系统什么时候给我bind呢？首次发送数据的时候

    std::string message;
    char buffer[1024];
    while (true)
    {
        std::cout << "Please Enter@ ";
        getline(std::cin, message);
        std::cout << message << std::endl;

        // std::cout << message << std::endl;
        // 1. 数据 2. 给谁发
        sendto(sockfd, message.c_str(), message.size(), 0, (const sockaddr*)&server, sizeof(server));

        struct sockaddr_in temp;
        int len = sizeof(temp);

        int s = recvfrom(sockfd, buffer, 1023, 0, (struct sockaddr*)&temp, &len);
        if (s > 0)
        {
            buffer[s] = 0;
            std::cout << buffer << std::endl;
        }
    }

    closesocket(sockfd);
    WSACleanup();
    return 0;
}