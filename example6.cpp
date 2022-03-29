#include <cstdio>
#include <memory>
#include <string>

using ShoppingList = std::shared_ptr<std::FILE>;

auto deleterList = [](FILE* f){ fclose(f);};

ShoppingList makeFile(const char* filename, const char* flags)
{
    auto file = ShoppingList( fopen(filename, flags), deleterList );
    return file;
}

class Partner
{
public:
    void addToFile(std::string element)
    {
        fprintf(shoppingList.get(), "%s\n", element.c_str() );
    }
    ShoppingList shoppingList;
    
};

int main()
{
    Partner boy{};
    boy.shoppingList = makeFile("ShoppingList", "wb");

    Partner girl{};
    girl.shoppingList = boy.shoppingList;
    girl.addToFile("Butter");
    girl.addToFile("Milk");
}
