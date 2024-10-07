#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;

int newExp = 0;
typedef union float_32{
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


string toBinary(int dec, int digit){
  string b = "", binary("01");
  while (dec > 0){
    b = binary[dec % 2] + b;
    dec = (dec - (dec % 2)) / 2;
  }

  if (b.length() > 24) newExp = 1;

  for (int i = b.length(); i <= digit ; i++) b = '0' + b;

  return b.substr(b.length() - digit, b.length());
}

int addNumber(int num1, int num2){ //adding numbers with bitwise
  while (num2 != 0){
    int carry = (num1 & num2);
    num1 = (num1 ^ num2);
    num2 = (carry << 1);
  }

  return num1;
}



string bitString(float_32 myFloat){

  char bit_string[43];

  for(int i=0; i<42; i++){
    bit_string[i] = ' ';
  }

  bit_string[42] = '\0';



  bit_string[0] = myFloat.bit.b31?'1':'0';

  bit_string[2] = myFloat.bit.b30?'1':'0';
  bit_string[3] = myFloat.bit.b29?'1':'0';
  bit_string[4] = myFloat.bit.b28?'1':'0';
  bit_string[5] = myFloat.bit.b27?'1':'0';

  bit_string[7] = myFloat.bit.b26?'1':'0';
  bit_string[8] = myFloat.bit.b25?'1':'0';
  bit_string[9] = myFloat.bit.b24?'1':'0';
  bit_string[10] = myFloat.bit.b23?'1':'0';

  bit_string[12] = myFloat.bit.b22?'1':'0';
  bit_string[13] = myFloat.bit.b21?'1':'0';
  bit_string[14] = myFloat.bit.b20?'1':'0';

  bit_string[16] = myFloat.bit.b19?'1':'0';
  bit_string[17] = myFloat.bit.b18?'1':'0';
  bit_string[18] = myFloat.bit.b17?'1':'0';
  bit_string[19] = myFloat.bit.b16?'1':'0';

  bit_string[21] = myFloat.bit.b15?'1':'0';
  bit_string[22] = myFloat.bit.b14?'1':'0';
  bit_string[23] = myFloat.bit.b13?'1':'0';
  bit_string[24] = myFloat.bit.b12?'1':'0';

  bit_string[26] = myFloat.bit.b11?'1':'0';
  bit_string[27] = myFloat.bit.b10?'1':'0';
  bit_string[28] = myFloat.bit.b9?'1':'0';
  bit_string[29] = myFloat.bit.b8?'1':'0';

  bit_string[31] = myFloat.bit.b7?'1':'0';
  bit_string[32] = myFloat.bit.b6?'1':'0';
  bit_string[33] = myFloat.bit.b5?'1':'0';
  bit_string[34] = myFloat.bit.b4?'1':'0';

  bit_string[36] = myFloat.bit.b3?'1':'0';
  bit_string[37] = myFloat.bit.b2?'1':'0';
  bit_string[38] = myFloat.bit.b1?'1':'0';
  bit_string[39] = myFloat.bit.b0?'1':'0';


  return bit_string;
}






int main(int argc, char * argv[])
{


  float f1 = 0, f2 = 0;

  float_32 myFloat_1;
  float_32 myFloat_2;



  cout << "Please enter two positive floating point values each with:" << endl;
  cout << "        - no more than 6 significant digits" << endl;
  cout << "        - a value between + 10**37 and 10**-37" << endl << endl;



  printf("Enter Float 1: ");
  scanf("%g", &myFloat_1.floating_value_in_32_bits);

  printf("Enter Float 2: ");
  scanf("%g", &myFloat_2.floating_value_in_32_bits);

  string bit_string_1 = bitString(myFloat_1);

  string bit_string_2 = bitString(myFloat_2);



  int exp_1 = myFloat_1.f_bits.exponent;
  int exp_2 = myFloat_2.f_bits.exponent;
  int mantissa_1 = myFloat_1.f_bits.mantissa;
  int mantissa_2 = myFloat_2.f_bits.mantissa;
  f1 = myFloat_1.floating_value_in_32_bits;
  f2 = myFloat_2.floating_value_in_32_bits;

  if (exp_1){ //if normalize shift 1 to the right
    mantissa_1 |= (1 << 23);
  }

  if (exp_2 ){ //if normalize shift 1 to the right
    mantissa_2 |= (1 << 23);
  }


  int exp = 0;
  int shift_exp = 0;

  if (exp_2 > exp_1){
    exp = exp_2;
    shift_exp = exp_2 - exp_1; // (exp_2 - 127) - (exp_1 - 127)
    mantissa_1 >>= shift_exp;
  }else{
    exp = exp_1;
    shift_exp = exp_1 - exp_2; // (exp_1 - 127) - (exp_2 - 127)
    mantissa_2 >>= shift_exp;
  }

  exp += newExp;

  if (exp == 255){
    mantissa_1 = 0;
    mantissa_2 = 0;
  }




  string mantissa_bitstring = toBinary(addNumber(mantissa_1, mantissa_2), 24).substr(1, 24);


  exp += newExp;

  if (exp == 255){
    mantissa_bitstring = "";
    for (int i = 0; i < 23; i++)
      mantissa_bitstring += '0';
  }


  string exponent_bitstring = toBinary(exp, 8);
  string pattern_result = exponent_bitstring.substr(0, 4) + ' ' + exponent_bitstring.substr(4, 4) + ' ' +
    mantissa_bitstring.substr(0, 3) + ' ' + mantissa_bitstring.substr(3, 4) + ' ' +
    mantissa_bitstring.substr(7, 4) + ' ' + mantissa_bitstring.substr(11, 4) + ' ' +
    mantissa_bitstring.substr(15, 4) + ' ' + mantissa_bitstring.substr(19, 23);

  float emulation = 0;
  for (int j = 0; j < 23; j++){
    if (mantissa_bitstring[j] == '1')
      emulation += pow(2, (j + 1) * -1);
  }

  emulation = pow(2, (exp - 127)) * (emulation + 1);

  float floating_result = f1 + f2;


  cout << endl;
  cout << right << setw(29) << "Original pattern of float 1: " << bit_string_1 << endl;

  cout << right << setw(29) << "Original pattern of float 2: " << bit_string_2 << endl;

  cout << right << setw(29) << "Bit pattern of result      : " << myFloat_1.f_bits.sign << " " << pattern_result << endl;

  cout << "EMULATED FLOATING RESULT FROM PRINTF ==>>> " << emulation << endl;

  cout << "HARDWARE FLOATING RESULT FROM PRINTF ==>>> " << floating_result << endl;



}

