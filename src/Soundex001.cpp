//============================================================================
// Name        : Soundex001.cpp
// Author      : Xiao Li
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;

int main() {

	string name;
	string soundexCode;
	int iLen;
	int i;
	cout << "Enter your name in lower case: ";
	cin>> name;
	iLen = name.length(); //  calculate the length after input
	//now change all the letters to digits
	for (i = 0; i <iLen; i++)
	{if (name[i] == 'b' || name[i] == 'f' || name[i] == 'p'|| name[i] == 'v')

         {  soundexCode+='1';

        }

	else if (name[i] == 'c' || name[i] == 'g' || name[i] == 'j'|| name[i] == 'k' || name[i] == 'q' || name[i] == 's'
		  || name[i] == 'x' || name[i] == 'z')

        {  soundexCode+='2';

        }

    else if (name[i] == 'd' || name[i] == 't')

        {  soundexCode+= '3';

        }

    else if (name[i] == 'l')

        {  soundexCode+= '4';

        }

    else if (name[i] == 'm' || name[i] == 'n')
         {  soundexCode+='5';

         }

    else if (name[i] == 'r')
        {   soundexCode+= '6';

        }
    else if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u' || name[i] == 'y'
    || name[i] == 'h' || name[i] == 'w')

         { soundexCode+= '7';
         }

    }
    int sLen = soundexCode.length();
	// start to modify the soundexCode to make it into 4 digits
    i=0; // check from i=0
 	while(i<sLen-1)
 	{
 				if (soundexCode[i] == soundexCode[i+1])

 					{
 			    	soundexCode.erase(i+1, 1);
 			    	i-=1; //need to check i again since the i+1 become i after erasing
 					}
 					i+=1;
 					sLen = soundexCode.length();
 	 			}
 	           soundexCode[0]=toupper(name[0]);
 	          i=0;
 	while(i<sLen-2)
 	{
 					if ((soundexCode[i] == soundexCode[i+2])
 	 						&& (name[i+1] == 'h' || name[i+1] == 'w'))
 	 					{
 	 					soundexCode.erase(i+2, 1);
 	 					i-=1;  //need to check i again since the i+1 become i after erasing
 	 					}
 					i+=1;
 					sLen = soundexCode.length();
 	 				}

 	i=0; // start from 0 for another condition
 	while(i<sLen)
 	{
 		if (soundexCode[i]=='7')
		    	{
		    	soundexCode.erase(i, 1);
		        i-=1; //need to check i again since the i+1 become i after erase
		    	}
		i+=1;
		sLen = soundexCode.length();
		  }
		soundexCode +="000";
		soundexCode = soundexCode.substr(0, 4);
      cout << "the Soundex code of the name is: " <<soundexCode << endl;
      return 0;

}
