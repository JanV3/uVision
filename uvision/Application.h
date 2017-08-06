#ifndef UVISION_APPLICATION_H
#define UVISION_APPLICATION_H

namespace uVision {
/// @brief Base class of uVison framework application
class Application {
public:
    Application() = default;
    virtual ~Application() = default;

    void run()
    {
        init();
    }

private:
    virtual void init() = 0;
};
}

#endif /* UVISION_APPLICATION_H */
