#include <iostream>

class Sentence{
    char * data;

    void erase()
    {
        delete [] data;
    }

    void copy(Sentence const & other)
    {
        size_t len = 0;
        while (other.data[len] != '\0')
        {
            len++;
        }
        
        data = new char[len + 1];
        for (size_t i = 0; i < len; i++)
        {
            data[i] = other.data[i];
        }
    }
public:
    Sentence()
    {
        data = nullptr;
    }

    Sentence(Sentence const & other)
    {
        copy(other);
    }

    Sentence & operator=(Sentence const & other)
    {
        if(this != &other)
        {
            erase();
            copy(other);
        }
        return *this;
    }

    Sentence(const char * str)
    {
        size_t len = 0;
        while (str[len] != '\0')
        {
            len++;
        }
        
        data = new char[len + 1];
        for (size_t i = 0; i < len; i++)
        {
            data[i] = str[i];
        }
    }

    ~Sentence()
    {
        erase();
    }

    void print()
    {
        for (size_t i = 0; data[i] != '\0'; i++)
        {
            std::cout << data[i];
        }
        std::cout << '\n';
    }
};

int main()
{
    Sentence s;
    Sentence ss("ala bala portokala");
    Sentence sss = ss;
    //Sentence ssss = "34324";
    sss.print();
    ss.print();
    s = ss;
    s.print();
    //ssss.print();
    return 0;
}
