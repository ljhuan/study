#include <qpid/messaging/Address.h>
#include <qpid/messaging/Connection.h>
#include <qpid/messaging/Message.h>
#include <qpid/messaging/Receiver.h>
#include <qpid/messaging/Sender.h>
#include <qpid/messaging/Session.h>
#include <boost/lexical_cast.hpp>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <sstream>
#include <unistd.h>
using namespace qpid::messaging;

using std::stringstream;
using std::string;

int main(int argc, char const *argv[]) {
    const char* url = argc>1 ? argv[1] : "amqp:tcp:202.169.88.115:5672";
    std::string connectionOptions = argc > 2 ? argv[2] : ""; 
    Connection connection(url, connectionOptions);
    connection.setOption("username", "qpid");
    connection.setOption("password", "qpid");
    // connection.setOption("sasl_mechanisms", "CRAM-MD5");
    connection.setOption("reconnect", true);
    // connection.setOption("reconnect_timeout", 5);
    connection.setOption("reconnect_interval", 3); 
    Address address("service_queu; {create: always, node:{durable: True}}");
    std::cout << "get" << address.getOptions() << std::endl;
    int i = 0;
    int n = 10; 
    try {
        connection.open();
        std::cout << connection.getAuthenticatedUsername() << std::endl;
        Session session = connection.createSession();
        Sender sender = session.createSender(address);
        while(n--) {
            Message message;
            sender.setCapacity(5);
            std::cout << "get:" << sender.getUnsettled() << " " << sender.getAvailable() << std::endl;
            string str = boost::lexical_cast<string>(i++);
            message.setContentObject(str); // set message
            message.setDurable(true); // set message is durable but need queue is durable when queue is be created
            sender.send(message); // 可设置为同步模式，发送阻塞知道broker确认收到消息，默认是false
            // sender.send(message, true);
            sleep(1);
        }
        sender.close();
        connection.close();
    } catch(const std::exception& ex) {
        std::cout << ex.what() << std::endl;
        connection.close();
        return 1;
    }
    return 0;
}
