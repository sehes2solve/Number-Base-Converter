#include <bits/stdc++.h>

using namespace std;

void print_digits(long long value,short order)
{
    if(value == 0)
        return;
    char out;
    if(value % order > 9)
        out = value % order + 'a' - 10;
    else
        out = value % order + '0';
    print_digits(value / order,order);
    cout << out;
}
int main()
{
    short st_order,sd_order,value;
    long long dec_value = 0;
    string number;
    cin >> st_order >> sd_order >> number;
    reverse(number.begin(),number.end());
    for(int i = 0; i < number.size(); i++)
    {
        if(number[i] >= 'A' && number[i] <= 'F')
            number[i] = tolower(number[i]);
        if(number[i] >= 'a' && number[i] <= 'f')
            value = number[i] - 'a' + 10;
        else
            value = number[i] - '0';
        value *= pow((long long)st_order,i);
        dec_value += value;
    }
    print_digits(dec_value,sd_order);
    return 0;
}
