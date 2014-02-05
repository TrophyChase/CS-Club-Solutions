//Created by: Jordan Snyder
//Solution for Problem S2 CCC 2010

#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    int num_char;
    int length=1;
    char character;
    string code;
    string sequence;
    map <string,char> huffman;

    cin >> num_char;

    //get the characters and their associated codes
    for (int x=1;x<=num_char; x++)
    {
        cin >> character;
        cin >> code;
        huffman[code]=character;
    }
    //get the sequence
    cin >> sequence;

    while(sequence.length()>0)
    {   //if the substring maps to a character, output the character, erase the substring, and set length to 1
        if (huffman.find(sequence.substr(0,length))!= huffman.end())
        {
             cout<<huffman[sequence.substr(0,length)];
             sequence.erase(0,length);
             length=1;
        }
        //otherwise, increase the size of the substring to check
        else
            length++;
    }

}
