#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <cstdlib>
#include <sys/types.h>

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout << "用法: ./server <端口号>\n";
        return -1;
    }

    // 1. 创建服务端套接字
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd == -1) {
        perror("socket failed");
        return -1;
    }

    int opt = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 2. 绑定 IP 和端口
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[1]));
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // 监听本机所有网卡 IP<websource>source_group_web_4</websource>

    if(bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) != 0) {
        perror("bind failed");
        close(listenfd);
        return -1;
    }

    // 3. 开始监听
    if(listen(listenfd, 128) != 0) {
        perror("listen failed");
        close(listenfd);
        return -1;
    }
    cout << "服务端已启动，正在监听端口: " << argv << endl;

    while(true) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        
        int clientfd = accept(listenfd, (struct sockaddr*)&client_addr, &client_len);
        if(clientfd == -1) {
            perror("accept failed");
            continue;
        }
        cout << "新客户端已连接\n";

        // 内层循环：处理当前客户端的通信
        char buf[1024];
        while(true) {
            memset(buf, 0, sizeof(buf));
            ssize_t ret = recv(clientfd, buf, sizeof(buf) - 1, 0);
            
            if(ret > 0) {
                cout << "接收到消息: " << buf << endl;

                const char* reply = "ok";
                ssize_t send_ret = send(clientfd, reply, strlen(reply), 0);
                if(send_ret <= 0) {
                    perror("send failed");
                    break;
                }
                cout << "已回复: ok\n";
            } 
            else if(ret == 0) {
                // 客户端主动断开连接
                cout << "客户端已断开连接\n";
                break;
            } 
            else {
                // 接收发生网络错误
                perror("recv failed");
                break;
            }
        }
        close(clientfd);
    }

    close(listenfd);
    return 0;
}