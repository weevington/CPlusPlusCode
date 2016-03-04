
#include "Very_long_int.hxx"

Very_long_int::Very_long_int()
:base(10)
{
 
   digits.erase(digits.begin(), digits.end());

}

Very_long_int::Very_long_int(size_t inst_szt, int bse)
:base(bse)
{
 
   do
   {
	   digits.push_back(inst_szt % bse);
	   inst_szt = inst_szt/bse;
   }
   while (inst_szt > 0);

   reverse (digits.begin(), digits.end());
   
}

Very_long_int::Very_long_int(int inst_int, int bse)
:base(bse)
{
  do
  {
    digits.push_back(inst_int % bse);
    inst_int = inst_int / bse;
  } 
  while (inst_int > 0);

  reverse (digits.begin(), digits.end());

}

Very_long_int::Very_long_int(const std::string &inst_str, int bse)
:base(bse)
{

  std::string::const_iterator itr = inst_str.begin();

  std::istringstream iss;

  for (; itr != inst_str.end(); ++itr)  {
    int ia = (*itr) - '0';
    digits.push_back(ia);
  }

  std::cout << "reversing digits" << std::endl;
  //reverse (digits.begin(), digits.end());
}

Very_long_int::Very_long_int(const char* inst_arr, int bse)
{
  size_t arr_sz = std::char_traits<char>::length(inst_arr);

  for(unsigned int k; k < arr_sz; ++k) {
    digits.push_back(inst_arr[k]);
  } 

  std::cout << "reversing digits" << std::endl;
  //reverse(digits.begin(), digits.end());
}


// destructor
Very_long_int::~Very_long_int()
{

}

std::ostream& operator<< (std::ostream& outstream, const Very_long_int& vli)
{
    for (unsigned int i = 0; i < vli.digits.size(); i++)
    	outstream << (vli.digits.at(i));
    return outstream;
} // operator<<

std::istream& operator>> (std::istream& istr, Very_long_int& vli)
{
  const char LOWEST_DIGIT_CHAR  = '0';

  const char HIGHEST_DIGIT_CHAR = '9';

  const char SENTINEL = 'X';

  char digit_char;

  vli.digits.erase (vli.digits.begin(), vli.digits.end());


  do
  {
	// Loop invariant: Each digit read in so far has been appended to digits.
	istr >> digit_char;
	if ((LOWEST_DIGIT_CHAR <= digit_char) &&
		(digit_char <= HIGHEST_DIGIT_CHAR))
	    vli.digits.push_back (digit_char - LOWEST_DIGIT_CHAR);
     } // while
     while (digit_char != SENTINEL);

     return istr;

}

Very_long_int operator+(const Very_long_int& addend_first, const Very_long_int& addend_second) 
{
  int carry = 0;
  int larger_size;
  int partial_sum;

  Very_long_int sum;
  long int sum_size = 0;


  // if(addend_first.digits.size() > addend_second.digits.size()) {
  //   std::cout << "addend_first.digits.size() = " << addend_first.digits.size() << std::endl; 
  //   sum_size = addend_first.digits.size();
  // } else if(addend_first.digits.size() < addend_second.digits.size()) {
  //   std::cout << "addend.digits.size() = " << addend.digits.size() << std::endl; 
  //   larger_size = addend_second.digits.size();
  // } else {
  //   if (digits.size() == addend.digits.size()) {
  //     if (digits.front() + addend.digits.front() > base)
  //       sum_size = digits.size() + 1;
  //   }
  // }

  // sum.digits.reserve(sum_size);

  // //std::vector
  // for(unsigned i = 0; i < sum_size; i++)
  // {
  //   partial_sum = least(i) + addend.least(i) + carry;
  //   carry = partial_sum / 10;
  //   sum.digits.push_back(partial_sum % 10);
  // }

  // if(carry == 1) {
  //   sum.digits.push_back(carry);
  // }

  // reverse (sum.digits.begin(), sum.digits.end());

  //   return sum;

  if (addend_first.digits.size() > addend_second.digits.size())
    larger_size = addend_first.digits.size();
  else
    larger_size = addend_second.digits.size();

  for (unsigned i = 0; i < larger_size; i++)
  {
        // Loop invariant: The (i-1)st least significant digits in
        //                            the calling object and addend_second
        //                            have been added.
        partial_sum = addend_first.least(i) + addend_second.least(i) +  carry;
        carry = partial_sum / 10;
        sum.digits.push_back (partial_sum % 10);
  } // for

  if (carry == 1)
    sum.digits.push_back (carry);
  reverse (sum.digits.begin(), sum.digits.end());
  return sum;

} // overloading +


char Very_long_int::least(unsigned i) const
{
  if (i >= digits.size())
    return 0;
  else
    return digits [digits.size() - i - 1] ;
} // least


// Very_long_int Very_long_int::operator- (const Very_long_int& subtrahend) 
// {
//     int carry = 0,
//     int larger_size,
//     int partial_sum;
// 
//     Very_long_int difference;
// 
//     if (digits.size() > subtrahend.digits.size())
//         larger_size = digits.size();
//     else
//         larger_size = addend.size();
// 
//     for (unsigned i = 0; i < larger_size; i++)
//     {
//         // Loop invariant: The (i-1)st least significant digits in
//         //                            the calling object and addend_very_long
//         //                            have been added.
//         partial_sum = least(i) - addend.least(i) +  carry;
//         carry = partial_sum / 10;
//         sum.digits.push_back (partial_sum % 10);
//     } // for
// 
//     if (carry == 1) {
//         sum.digits.push_back(carry);
//     }
// 
//     reverse (sum.digits.begin(), sum.digits.end());
// 
//     return sum;
// } // overloading operator -
// 
// Very_long_int& Very_long_int::operator-- (Very_long_int& vli)
// {
// 
// 
//   return *this;
// }
// 
// Very_long_int& Very_long_int::operator++ (Very_long_int& vli)
// {
// 
//   return *this;
// }
