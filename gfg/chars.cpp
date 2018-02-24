// to_string example
#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
using namespace std;
int main ()
{
  int Number = 123;//number to convert int a string
string Result;//string which will contain the result

stringstream ss; // stringstream used for the conversion

ss << Number;//add the value of Number to the characters in the stream

Result = ss.str();//set Result to the content of the stream

//Result now is equal to "123" 
cout<<Result;
}