#include "HexInt.h"
#include <iostream>
#include <string.h>

HexInt::HexInt(const char* str)
{
    //constructor populates value with zeroes before re-assigning 
    //some with the given str value. By the end, value will have
    //leading zeroes from the first half, with the rest matching 
    //the str argument.
    int zeroes = 20 - strlen(str);
    for (int i = 0, k = 0; i < 21; i++){
        if (i < zeroes){
            value[i] = '0';
        }
        else{
            value[i] = *(str + k);
            k++;
        }
    }
}

HexInt::~HexInt(){}

//toString takes the value of the HexInt it is called with
//and allocates a char* on its own with the same elements
char* HexInt::toString()
{
    char* newStr;
    newStr = new char[21];
    for (int i = 0; i < 21; i++){
        *(newStr + i) = this->value[i];
    }
    return newStr;
}

//TotrimmedString does the same as toString, but only starts
//assigning elements to the new char* when they are no longer
//zeroes.
char* HexInt::toTrimmedString()
{
    int k = 0; //amount of leading zeroes
    for (int i = 0; i < 21; i++){
        if (this->value[i] != '0'){
            break;
        }
        k++;
    }

    char* newStr;
    newStr = new char[21 - k];
    for (int i = 0; i < 21 - k; i++){
        *(newStr + i) = this->value[k + i];
    }
    return newStr;
}

char toChar(int num) //Convert individual integers into their hexadecimal char counterparts
{
    switch(num){
        case 0:
            return '0';
            break;
        case 1:
            return '1';
            break;
        case 2:
            return '2';
            break;
        case 3:
            return '3';
            break;
        case 4:
            return '4';
            break;
        case 5:
            return '5';
            break;
        case 6:
            return '6';
            break;
        case 7:
            return '7';
            break;
        case 8:
            return '8';
            break;
        case 9:
            return '9';
            break;
        case 10:
            return 'A';
            break;
        case 11:
            return 'B';
            break;
        case 12:
            return 'C';
            break;
        case 13:
            return 'D';
            break;
        case 14:
            return 'E';
            break;
        case 15:
            return 'F';
            break;
    }

}

int toDec(char num) //Does the opposite of toChar, converting a char to an int and hex values A-F to 10-15
{
    switch (num) {
        case 'A':
            return 10;
            break;
        case 'B':
            return 11;
            break;
        case 'C':
            return 12;
            break;
        case 'D':
            return 13;
            break;
        case 'E':
            return 14;
            break;
        case 'F':
            return 15;
            break;
        default:
            return num - '0';
            break;
    }
}

char* flip(HexInt hex) //Takes a char* and flips it to make addition easier
{
    char* oldStr = hex.toString();
    char* newStr;
    newStr = new char[strlen(oldStr)];
    int k = strlen(oldStr) - 1;
    for (int i = 0; i <= k; i++){
        *(newStr + i) = *(oldStr + k - i);
    }
    return newStr;
}


//Required method add(HexInt&, HexInt&) uses the given addition algorithm, which accounts for
//converting back to hex. The resulting value must still be converted to A-F as the case may
//be.
HexInt* HexInt::add(HexInt& lhs, HexInt& rhs)
{
    char* left;
    left = flip(lhs);
    char* right;
    right = flip(rhs);
    int outputInt[21] = {0};
    char outputChar[21] = {'0'};
    int carry = 0;
    int digit1;
    int digit2;
    int sum = 0;
    for (int i = 0; left[i] || right[i]; i++){
        (left[i]) ? digit1 = toDec(left[i]) : digit1 = 0;
        (right[i]) ? digit2 = toDec(right[i]) : digit2 = 0;
        sum = digit1 + digit2 + carry;
        carry = sum / 16;
        outputInt[i] = sum % 16;
    }
    for (int i = 0; i <= 21; i++){
        outputChar[i] = toChar(outputInt[i]);
    }
    HexInt* sumHex = new HexInt(flip(outputChar));
    return sumHex;
}
