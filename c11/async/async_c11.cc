// promise example
#include <iostream>       // std::cout
#include <functional>     // std::ref
#include <thread>         // std::thread
#include <future>         // std::promise, std::future
#include <chrono>

void print_int (std::future<int>& fut) {
    std::future_status status;
     
    do {
        status = fut.wait_for(std::chrono::seconds(1));
        if(status == std::future_status::deferred) {
            std::cout << "not even begun" << std::endl;
        } else if (status == std::future_status::timeout) {
            std::cout << "time out" << std::endl;
        }   
    } while (status != std::future_status::ready);
    int x = fut.get();
    std::cout << "value: " << x << '\n';
}

int main () {
    std::promise<int> prom;                      // create promise
    std::future<int> fut = prom.get_future();    // engagement with future
    
    // usage 1
    /*  
    std::thread th1 (print_int, std::ref(fut));  // send future to new thread
    fut.wait_for(std::chrono::seconds(2));
    prom.set_value (10);                         // fulfill promise
                                               // (synchronizes with getting the future)
    std::cout << "1" << std::endl;
    th1.join();
    */
    // usage 2
    /*std::thread t([](std::promise<int> &p){p.set_value(9);}, std::ref(prom));
    std::cout << fut.get() << std::endl;
    t.join();*/

    // async
    auto fut2 = std::async(std::launch::async, [](){
            std::this_thread::sleep_for(std::chrono::seconds(3));
            return 8;});
    
    std::cout << "waiting..." << std::endl;
    std::future_status status;
    do {
        status = fut2.wait_for(std::chrono::seconds(1));
        if(status == std::future_status::deferred) {
            std::cout << "deferred!" << std::endl;
        } else if (status == std::future_status::timeout) {
            std::cout << "time out" << std::endl;
        }
    } while (status != std::future_status::ready);

    std::cout << "result:" << fut2.get() << std::endl;
    return 0;
}
