#include<iostream>

using std::cin;
using std::cout;
using std::cerr;

class Dog
{
private:
    char * name;
    unsigned int age;
public:
    Dog()
    {
        name = nullptr;
        age = 0;
    }

    Dog(char * name, unsigned int age)
    {
        size_t len = 0;
        while (name[len] != '\0')
        {
            len++;
        }
        
        this->name = new char[len + 1];
        for (size_t i = 0; i < len; i++)
        {
            this->name[i] = name[i];
        }
        this->age = age;
    }

    char * getName()
    {
        return this->name;
    }

    void greet()
    {
        cout << "Hi, I am a dog, my name is " << name 
             << " and I am " << age << " years old. ";
    }

    ~Dog()
    {
        delete [] name;
    }
};

int main()
{
    Dog dog = Dog("Sharo", 7);
    dog.greet();
    //cout << dog.getName();
    //dog.~Dog();
    return 0;
}
