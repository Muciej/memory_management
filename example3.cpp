#include <iostream>
#include <stdexcept>
#include <memory>
#include <cstring>

void validateArguments(int argc)
{
    if (argc != 2)
    {
        std::cerr << "You need to pass 1 argument" << std::endl;
        exit(-1);
    }
}

class MyException : public std::logic_error
{
    public:
    MyException(std::string message) : std::logic_error(message){
        message.append(" from my exception");
    }
};

class Resource
{
public:
    void use(const char *arg)
    {
        std::cout << "Using resource. Passed " << *arg << std::endl;
        if (*arg == 'd')
        {
            throw MyException("Passed d. d is prohibited.");
        }
    }
};

int main(int argc, char *argv[])
{
    validateArguments(argc);

    const char *argument = argv[1];
    // Resource* rsc = nullptr;
    // rsc = new Resource();
    try
    {
        // rsc = new Resource();
        std::unique_ptr<Resource> rsc = std::make_unique<Resource>();
        rsc->use(argument);
        // delete rsc;
    }
    catch (std::logic_error &e)
    {
        std::cout << e.what() << std::endl;
    }
    // delete rsc;
    return 0;
}
