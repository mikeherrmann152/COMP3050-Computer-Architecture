

#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


string toHex(string binary){
  string b = "";
  int hex = 0;
  string hexCode("0123456789abcdef");
  for (int i = binary.length() - 1; i > 0; i -= 5){
    hex = pow(2, 0) * (binary[i] - '0');
    hex += pow(2, 1) * (binary[i - 1] - '0');
    hex += pow(2, 2) * (binary[i - 2] - '0');
    if (i -3 >= 0) hex += pow(2, 3) * (binary[i - 3] -'0');
    b = hexCode[hex] + b;
  }
  return b;
}


int main(int argc, char * argv[])
{


  union float_32{
    float   floating_value_in_32_bits;
    int     floating_value_as_int;
    struct  sign_exp_mantissa{
      unsigned  mantissa:23;
      unsigned  exponent:8;
      unsigned      sign:1;
    } f_bits;
    struct single_bits{
      unsigned  b0 :1;
      unsigned  b1 :1;
      unsigned  b2 :1;
      unsigned  b3 :1;
      unsigned  b4 :1;
      unsigned  b5 :1;
      unsigned  b6 :1;
      unsigned  b7 :1;
      unsigned  b8 :1;
      unsigned  b9 :1;
      unsigned  b10:1;
      unsigned  b11:1;
      unsigned  b12:1;
      unsigned  b13:1;
      unsigned  b14:1;
      unsigned  b15:1;
      unsigned  b16:1;
      unsigned  b17:1;
      unsigned  b18:1;
      unsigned  b19:1;
      unsigned  b20:1;
      unsigned  b21:1;
      unsigned  b22:1;
      unsigned  b23:1;
      unsigned  b24:1;
      unsigned  b25:1;
      unsigned  b26:1;
      unsigned  b27:1;
      unsigned  b28:1;
      unsigned  b29:1;
      unsigned  b30:1;
      unsigned  b31:1;
    }bit;
  } float_32;

  char bit_string[43];

  std::string binary;


  for(int i=0; i<42; i++){
    bit_string[i] = ' ';
  }
  bit_string[42] = '\0';

  printf("please enter a floating point number and new-line: ");
  scanf("%g", &float_32.floating_value_in_32_bits);

  bit_string[0] = float_32.bit.b31?'1':'0';

  bit_string[2] = float_32.bit.b30?'1':'0';
  bit_string[3] = float_32.bit.b29?'1':'0';
  bit_string[4] = float_32.bit.b28?'1':'0';
  bit_string[5] = float_32.bit.b27?'1':'0';

  bit_string[7] = float_32.bit.b26?'1':'0';
  bit_string[8] = float_32.bit.b25?'1':'0';
  bit_string[9] = float_32.bit.b24?'1':'0';
  bit_string[10] = float_32.bit.b23?'1':'0';

  bit_string[12] = float_32.bit.b22?'1':'0';
  bit_string[13] = float_32.bit.b21?'1':'0';
  bit_string[14] = float_32.bit.b20?'1':'0';

  bit_string[16] = float_32.bit.b19?'1':'0';
  bit_string[17] = float_32.bit.b18?'1':'0';
  bit_string[18] = float_32.bit.b17?'1':'0';
  bit_string[19] = float_32.bit.b16?'1':'0';

  bit_string[21] = float_32.bit.b15?'1':'0';
  bit_string[22] = float_32.bit.b14?'1':'0';
  bit_string[23] = float_32.bit.b13?'1':'0';
  bit_string[24] = float_32.bit.b12?'1':'0';

  bit_string[26] = float_32.bit.b11?'1':'0';
  bit_string[27] = float_32.bit.b10?'1':'0';
  bit_string[28] = float_32.bit.b9?'1':'0';
  bit_string[29] = float_32.bit.b8?'1':'0';

  bit_string[31] = float_32.bit.b7?'1':'0';
  bit_string[32] = float_32.bit.b6?'1':'0';
  bit_string[33] = float_32.bit.b5?'1':'0';
  bit_string[34] = float_32.bit.b4?'1':'0';

  bit_string[36] = float_32.bit.b3?'1':'0';
  bit_string[37] = float_32.bit.b2?'1':'0';
  bit_string[38] = float_32.bit.b1?'1':'0';
  bit_string[39] = float_32.bit.b0?'1':'0';


  binary = bit_string;
  string mant = binary.substr(12, 28);
  string exp = binary.substr(2, 9);


  cout << right << setw(12) << "mantissa: " << left << setw(2)
       << "0x" << toHex(mant)  <<  "\tor:\t\t" << mant << endl;

  cout << right << setw(12) << "exponent: " << left << setw(2)
       << "0x" << toHex(exp) << "\tor:   " << exp << endl;

  cout << right << setw(12) << "sign: " << left << setw(9)
       << '0' <<  "\tor: " << bit_string[0] << endl;

  cout << right << setw(12) <<  "in base 10: " << left << setw(9)
       << fixed << setprecision(1)
        << float_32.floating_value_in_32_bits
       << "\tor: " << binary << endl;
}
