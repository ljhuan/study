#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <openssl/md5.h>

#define FLAGS(x) FLAGS_##x
#define FLAGS_test "OOO"
DEFINE_int32(test, 180, "for test");

int main() {
    std::stringstream ss; 
    MD5_CTX ctx;
    uint8_t buf[16] = {}; 
    const std::string &secret = "123456";
    MD5_Init(&ctx);
    MD5_Update(&ctx, secret.c_str(), secret.length());
    MD5_Final(buf, &ctx);
    for (int i = 0; i < 16; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << buf[i];
    }   
    std::string str = ss.str();
    std::cout << str << std::endl;
    std::cout << FLAGS(test) << std::endl;

    return 0;    
}
