#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <netdb.h>

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    // 1. 检查命令行参数 (约定: argv=IP, argv=端口)
    if(argc != 3) {
        cout << "用法: ./client <服务端IP> <服务端端口>\n";
        cout << "示例: ./client 127.0.0.1 8080\n";
        return -1;
    }

    // 2. 创建客户端套接字
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(socketfd == -1) {
        perror("socket failed");
        return -1;
    }

    // 3. 解析服务器 IP 地址
    struct hostent* h = gethostbyname(argv[1]);
    if(h == nullptr) {
        cout << "gethostbyname failed for IP: " << argv << endl;
        close(socketfd);
        return -1;
    }

    // 4. 配置服务器地址结构体
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    memcpy(&serv_addr.sin_addr, h->h_addr, h->h_length);

    // 5. 发起连接请求
    if(connect(socketfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) != 0) {
        perror("connect failed");
        close(socketfd);
        return -1;
    }
    cout << "成功连接到服务器 " << argv << ":" << argv << endl;

    // 6. 通信循环
    char buf[1024];
    for(int i = 0; i < 3; i++) {
        memset(buf, 0, sizeof(buf));
        snprintf(buf, sizeof(buf), "Hello Server, this is message %d", i + 1);
        
        ssize_t send_len = send(socketfd, buf, strlen(buf), 0);
        if(send_len <= 0) {
            perror("send failed");
            break;
        }
        cout << "已发送: " << buf << endl;

        // 接收服务器的回应 (对应服务端的 "ok")
        memset(buf, 0, sizeof(buf));
        ssize_t recv_len = recv(socketfd, buf, sizeof(buf) - 1, 0); // 预留1字节给'\0'
        if(recv_len <= 0) {
            if(recv_len == 0) cout << "服务器主动断开了连接" << endl;
            else perror("recv failed");
            break;
        }
        
        buf[recv_len] = '\0'; 
        cout << "接收到: " << buf << endl;
        
        sleep(1);
    }

    // 7. 关闭套接字，释放资源
    close(socketfd);
    return 0;
}