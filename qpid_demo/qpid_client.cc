#include <qpid/messaging/Session.h>

#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <sstream>

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
    connection.setOption("reconnect_interval", 3); 
    try {
        connection.open();
        Session session = connection.createSession();
        Receiver receiver = session.createReceiver("service_queu; {create: always}");

        while(1) {
            receiver.setCapacity(5);
            std::cout << "get:" << receiver.getAvailable() << std::endl;
            Message request = receiver.fetch();
            std::cout << request.getContentObject() << std::endl;
            // session.release(request);
            // session.reject(request);
            session.acknowledge(request);
            // session.sync();
        }   
        receiver.close();
        connection.close();
    } catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
        connection.close();
        return 1;
    }   
    return 0;
}
