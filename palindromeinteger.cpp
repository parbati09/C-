// Program to check whether an integer is palindromic or not

# include <iostream>

bool checkPalindrome(int number) {

    int reverse = 0;

    int temp = number;

    while (temp > 0) {    //Repeat this process until number is reduced to zero

        int lastDigit = temp % 10;    //Isolate the last digit in number

        reverse = (reverse * 10) + lastDigit;   //Append lastDigit to reverse

        temp = temp / 10;   //Remove last digit from number
    }

    return (reverse == number);
}

int main() {

    int number;

    std::cout << "Enter an integer: ";

    std::cin >> number;

    (checkPalindrome(number)) ? std::cout << "true" : std::cout << "false";

    return 0;
}