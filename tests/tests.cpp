#include <thread>

#include "TestApplication1.h"

int main()
{
    std::thread t([]() {
        Test::Application1 app1{"Test1"};
        app1.run();
    });

    Test::Application1 app2;
    app2.setName("Test2");
    app2.run();

    t.join();

    return 0;
}
