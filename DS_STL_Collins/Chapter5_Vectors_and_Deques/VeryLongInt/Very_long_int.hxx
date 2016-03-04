#ifndef VERYLONGINT_HXX
#define VERYLONGINT_HXX

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Very_long_int
{

  public:
    Very_long_int();
    Very_long_int(size_t inst_szt              , int bse = 10); // construct a 
    Very_long_int(int inst_int                 , int bse = 10); // construct a very long int from an ordinary integar value
    Very_long_int(const  std::string &inst_str , int bse = 10);
    Very_long_int(const char* inst_arr         , int bse = 10);

    ~Very_long_int();

    friend std::ostream& operator<< (std::ostream& ostr, const Very_long_int& vli);
    friend std::istream& operator>> (std::istream& ostr, Very_long_int& vli);


    friend Very_long_int operator+ (const Very_long_int& addend_first, const Very_long_int& addend_second);
    // friend Very_long_int operator- (const Very_long_int subtrahend);
    // friend Very_long_int operator* (const Very long_int mu);
    // friend Very_long_int operator/ (const Very_long_int dividend);
    // friend Very_long_int operator% (const Very_long_int modulo);

    // friend Very_long_int operator+(Very_long_int addend_primary, Very_long_int addend_second)
    // friend Very_long_int operator-(Very_long_int subtrahend_, Very_long_int addend_friend)

    // bool operator> (const Very_long_int & gt_comp_val) const;
    // bool operator< (const Very_long_int & lt_comp_val) const;
    // bool operator== (const Very_long_int & equ_comp_val) const;
    // Very_long_int& operator=   (const Very_long_int & assign_val);
    // Very_long_int& operator++  (const Very_long_int incr_val);
    // Very_long_int& operator--  (const Very_long_int decr_val);
    // Very_long_int& operator += (const Very_long_int & increment);
    // Very_long_int& operator -= (const Very_long_int & decrement);

    // Very_long_int & factorial_recursive();
    // Very_long_int & factorial_non_recursive();

    // void negate();
    // void reset();

    // Very_long_int & abs();

    // Very_long_int & natural_log();
    // Very_long_int & log(double base);

    // Very_long_int pow(double exponent); // _power function for base_10 exponents

    // // functions to return return an std::string with the decimal representation
    // // of the very long integer
    // const std::string & to_string_decimal() const; 
    // const std::string & to_string_binary() const;
    // const std::string & to_string_octal() const;
    // const std::string & to_string_hex() const;

    char least(unsigned int i) const;


  protected:
    int base; // restrict the default base to be positive
    std::string string_rep; // string 
    std::vector<int> digits;
};

#endif
