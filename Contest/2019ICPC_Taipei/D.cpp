#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define PB push_back
#define PII par<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()

int main(void)
{
    string str1, str2, str3;

    cin >> str1 >> str2 >> str3;

    bool flag = true;

    int cnt = 0;

    if(str1 != "tapioka" && str1 != "bubble")
    {
        cout << str1;
        flag = false;
        cnt++;
    }
    if(!flag)
        printf(" ");

    flag = true;

    if(str2 != "tapioka" && str2 != "bubble")
    {
        cout << str2;
        flag = false;
        cnt++;
    }

    if(!flag)
        printf(" ");

    if(str3 != "tapioka" && str3 != "bubble")
    {
        cout << str3;
        cnt++;
    }

    if(cnt == 0)
        printf("nothing");

    cout << '\n';
}
