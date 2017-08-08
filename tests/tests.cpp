#include <thread>

#include "TestApplication1.h"

int main()
{
    std::thread t([]() {
        Test::Application1 app1{"Test1"};
        app1.start();
    });

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    Test::Application1 app2;
    app2.setName("Test2");
    app2.start();

    t.join();

    return 0;
}
