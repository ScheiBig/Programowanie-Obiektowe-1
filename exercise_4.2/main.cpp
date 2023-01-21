#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>

// https://www.geeksforgeeks.org/measure-execution-time-function-cpp/

struct test_time
{
    size_t test_onsite(std::string _path)
    {
        std::fstream f{ _path, f.in };
        std::stringstream s;

        s << f.rdbuf();

        s.seekg(0, std::ios::end);

        return s.tellp();
    }

    virtual size_t test_vtable(std::string _path)
    {
        std::fstream f{ _path, f.in };
        std::stringstream s;

        s << f.rdbuf();

        s.seekg(0, std::ios::end);

        return s.tellp();
    }
};

struct tester: public test_time {};

int main()
{
    tester t;

    auto start1 = std::chrono::high_resolution_clock::now();
    size_t size1 = t.test_onsite("CMakeLists.txt");
    auto stop1 = std::chrono::high_resolution_clock::now();

    auto start2 = std::chrono::high_resolution_clock::now();
    size_t size2 = t.test_vtable("CMakeLists.txt");
    auto stop2 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);
    
    std::cout << "On-stite function call: read " << size1 << " bytes in " << duration1.count() << " microseconds.\n";
    std::cout << "VTable function call: read " << size2 << " bytes in " << duration2.count() << " microseconds.\n\n";



    auto start3 = std::chrono::high_resolution_clock::now();
    size_t size4 = t.test_vtable(".ninja_log");
    auto stop3 = std::chrono::high_resolution_clock::now();

    auto start4 = std::chrono::high_resolution_clock::now();
    size_t size3 = t.test_onsite(".ninja_log");
    auto stop4 = std::chrono::high_resolution_clock::now();

    auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(stop3 - start3);
    auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(stop4 - start4);

    std::cout << "On-stite function call: read " << size3 << " bytes in " << duration3.count() << " microseconds.\n";
    std::cout << "VTable function call: read " << size4 << " bytes in " << duration4.count() << " microseconds.\n\n";

    return 0;
}
