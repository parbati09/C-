# include <iostream>
using namespace std;
bool checkpalindrome(int n)
{
    int rev=0;
    int n0=n;
    while(n0>0)
    {
        int digit=n0%10;
        rev*=10;
        rev+=digit;
        n0/=10;
    }
    if(rev==n)
    return true;
    else
    return false;
}
int main()
{
    int a;
    cout<<"Accept integer: ";
    cin>>a;
    if(checkpalindrome(a))
    cout<<"Palindrome Integer";
    else
    cout<<"Not Palindrome";
}
