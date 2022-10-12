#include "Data.hpp"
#include <iomanip>
#include <stdint.h> //uintptr_t 

/*
**  uintptr_t:
**  used to convert any void* to this type, with no altercation 
**  between conversion in both side convertion
**
**  reinterpret_cast:
**  used to convert a ptr of some data type into another ptr of
**  another data type
*/

static uintptr_t    serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

static Data*    deserialize(uintptr_t ptr)
{
    return (reinterpret_cast<Data *>(ptr));
}

int main(void)
{
    Data    data1("data");

    uintptr_t data_test = serialize(&data1);

    Data *data2 = deserialize(data_test);

    std::cout << std::endl;
    std::cout << "Data1 address: " << &data1 << std::endl;
    std::cout << "Data2 address: " << data2 << std::endl;
    std::cout << std::endl;
    std::cout << "Data1 name: " << data1.getName() << std::endl;
    std::cout << "Data2 name: " << (*data2).getName() << std::endl;
    std::cout << std::endl;
    return (0);
}