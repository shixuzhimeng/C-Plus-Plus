#include <iostream>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio::ip;

const int MAX = 1024;

int main() {
    try {
        boost::asio::io_context ioc;
        tcp::endpoint remote_ep(address::from_string("127.0.0.1"), 6666);
        tcp::socket socket(ioc);
        boost::system::error_code error = boost::asio::error::host_not_found;
        socket.connect(remote_ep, error);
        if(error) {
            cout << "connect failed, code is " << error.value() << "error msg is" << error.message() << endl;
            return 0;
        }

        cout << "enter message:" << endl;
        
        char request[MAX];
        cin.getline(request, MAX);
        size_t request_len = strlen(request);
        boost::asio::write(socket, boost::asio::buffer(request, request_len));

        char reply[MAX];
        size_t reply_len = boost::asio::read(socket, boost::asio::buffer(reply, request_len));
        cout << "reply is" << string(reply, reply_len) << endl;
        getchar();
    }
    catch(std::exception& e) {
        std::cerr << "Exceptions is" << e.what() << endl; 
    }
    return 0;
}