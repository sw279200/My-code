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

    // client Ҫbind��Ҫ��ֻ��������Ҫ�û���ʾ��bind��һ����OS�������ѡ��
    // һ���˿ں�ֻ�ܱ�һ������bind����server����ˣ�����client��Ҳ����ˣ�
    // ��ʵclient��port�Ƕ��٣���ʵ����Ҫ��ֻҪ�ܱ�֤�����ϵ�Ψһ�ԾͿ��ԣ�
    // ϵͳʲôʱ�����bind�أ��״η������ݵ�ʱ��

    std::string message;
    char buffer[1024];
    while (true)
    {
        std::cout << "Please Enter@ ";
        getline(std::cin, message);
        std::cout << message << std::endl;

        // std::cout << message << std::endl;
        // 1. ���� 2. ��˭��
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