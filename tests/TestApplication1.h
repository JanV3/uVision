#ifndef TEST_APPLICATION1_H
#define TEST_APPLICATION1_H
#include "../uvision/uVision.h"

namespace Test {
class Application1 : public uVision::Application {
public:
    Application1()
        : uVision::Application{"Default Application1 name"} {};

    explicit Application1(std::string name)
        : uVision::Application{name} {};

private:
    void init() final
    {
        std::cout << "Initialising application '" << name_ << "'" << std::endl;
    }
};
}
#endif /* ifndef TEST_APPLICATION1_H */
