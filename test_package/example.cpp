#include <iostream>
#include <boost/filesystem.hpp>

int main() {
    std::cout << "Current path is " << boost::filesystem::current_path().string() << std::endl;
}
