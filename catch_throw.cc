#include <iostream>
#include <exception>
#include <string>
	
namespace my_cpp {

/**
 * basic exception class for my_cpp
 **/
class my_error : public std::exception {
public:
    explicit my_error(const std::string& msg) : msg_(msg) {}
    const char* what() const throw() override { return msg_.c_str(); }
private:
    std::string msg_;
};

} // namespace my_cpp

int main()
{
	try{
		if (1 < 2){
			//throw my_cpp::my_error("this is my_error");
			throw std::runtime_error("runtime_error!");
		}
	}catch(my_cpp::my_error e){
		std::cout<< e.what() << std::endl;
	}catch(std::runtime_error e){
		std::cout<< e.what() << std::endl;
	}

}