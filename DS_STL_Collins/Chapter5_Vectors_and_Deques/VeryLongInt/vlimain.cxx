
#include "Very_long_int.hxx"

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{

  std::string num1_str("1244586970348769990217564920134956101023567");
  std::string num2_str("96842329100098492931132948696045664324566788922843577");

  std::cout << "instantiating first very_long_int with value"  << num1_str
	    << std::endl;
  Very_long_int vli_first(num1_str);


  std::cout << "instantiating second Very_long_int with value" << num2_str
            << std::endl;
  Very_long_int vli_second(num2_str);


  // first just check that you can stream out the objects using the overloaded
  // stream operator
  std::cout << "The value of vli_first = " << vli_first << std::endl;

  std::cout << "The value of vli_second = " << vli_second << std::endl;

 
  Very_long_int vli_sum(vli_first + vli_second);

  std::cout << "The value of vli_sum = " << vli_sum << std::endl;

   return 0;
}
