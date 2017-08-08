#ifndef UVISION_APPLICATION_H
#define UVISION_APPLICATION_H

#include <atomic>
#include <condition_variable>
#include <csignal>
#include <iostream>
#include <mutex>

namespace uVision {

/// forward declaration of signal handler
void signalHandler(int);

/// Represents stop event for uVison applications
class ApplicationStopEvent {
public:
    static ApplicationStopEvent* getInstance()
    {
        static ApplicationStopEvent* ast = new ApplicationStopEvent();
        return ast;
    }

    void invoke()
    {
        std::unique_lock<std::mutex> lock(mtx);
        stopFlag = true;
        cv.notify_all();
    }

    void waitOn()
    {
        std::unique_lock<std::mutex> lock{mtx};
        cv.wait(lock, [&]() { return stopFlag != false; });
    }

private:
    ApplicationStopEvent()
        : stopFlag{false}
    {
        std::signal(SIGINT, signalHandler);
        std::signal(SIGTERM, signalHandler);
    }

    std::atomic_bool stopFlag;
    std::condition_variable cv;
    std::mutex mtx;
};

/// @brief Handler of SIGINT/SIGTERM signals
///
/// @param signal received signal
void signalHandler(int signal)
{
    if (signal == SIGINT)
        std::cout << "SIGINT received." << std::endl;
    else if (signal == SIGTERM)
        std::cout << "SIGTERM received." << std::endl;
    ApplicationStopEvent::getInstance()->invoke();
}

/// @brief Base class of uVison framework application
class Application {
public:
    Application(std::string name)
        : name_(name){};

    Application()
        : name_("default"){};

    virtual ~Application() = default;

    /// @brief Set application name.
    ///
    /// Usefull to distinguish if there is more than one application.
    /// @param name name of application
    void setName(std::string name)
    {
        name_ = name;
    }

    /// @brief Initialise application using virtual init() function and
    /// starts listen to SIGINT/SIGTERM signals
    void start()
    {
        std::cout << "Starting application '" << name_ << "'" << std::endl;

        // initialise application
        init();

        // wait for stop event
        ApplicationStopEvent::getInstance()->waitOn();

        std::cout << "Application '" << name_ << "' stopped." << std::endl;
    }

protected:
    std::string name_;

private:
    virtual void init() = 0;
};
}

#endif /* UVISION_APPLICATION_H */
