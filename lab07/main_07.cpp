#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;



int main() {
    vector<string> frutis{"melon","strawberry","raspberry","apple"
    };

    auto it = find_if(frutis.begin(),frutis.end(), [](const string& e) {
        return e.find("berry") != string::npos;
    });

    if (it != frutis.end()) {
        cout << *it << endl;
    }else {
        cout << "not found";
    }

    vector<int> szamok{2,4,81,12};

    bool allEven=all_of(szamok.begin(),szamok.end(),[] (const int& m) {
        return m % 2 == 0;
    });

    cout << (allEven? "Minden elem paros" : "Nem minden elem paros") << endl;

    for_each(szamok.begin(),szamok.end(),[](int& m) {
        m = m*2;
    });

    for_each(szamok.begin(),szamok.end(), [](int& m) {
        cout << m << " ";
    });

    vector<string> months{
    "January","February","March","April","May","June","July","August","September","October","November","December"
    };

    int countFive = count_if(months.begin(),months.end(), [](const string& m) {
       return m.size() == 5;
    });


    cout <<endl << "Ennyi 5 betubol alo honap:" << countFive << endl;

    vector<double> nums {1.24,6.4,3.64,8.65,254.4};

    sort(nums.begin(),nums.end(),[](double &a, double&b)
    {
        return a > b;
    });

    for_each(nums.begin(),nums.end(),[](const double& n)
    {
        cout << n << " " ;
    });

    cout << endl;
    sort(nums.begin(),nums.end(),greater<double>());

    for_each(nums.begin(),nums.end(),[](const double& n)
    {
        cout << n << " " ;
    });

    vector<pair<string, double>> temps{
            {"January", 0.5}, {"February", 1.2}, {"March", 5.8},
            {"April", 10.1}, {"May", 15.3}, {"June", 19.6},
            {"July", 21.8}, {"August", 21.2}, {"September", 16.3},
            {"October", 10.5}, {"November", 5.0}, {"December", 1.0}
    };


    cout << endl;
    sort(temps.begin(),temps.end(),[](const auto&a, const auto&b)
    {
        return a.second < b.second;
    });

    for_each(temps.begin(),temps.end(),[](const auto& a)
    {
        cout << a.first << " " << a.second << "  ";
    });

    vector<double> numss{-5.4, 3.2, -1.1, 0.0, 7.8};

    sort(numss.begin(),numss.end(),[](double a, double b)
    {
        return abs(a) < abs(b);
    });
    cout << endl;
    for_each(numss.begin(),numss.end(),[](double a)
    {
        cout << a << " ";
    });

    transform(months.begin(),months.end(), months.begin(), [](string m)
    {
        m[0] = tolower(m[0]);
        return m;
    });

    cout << endl;
    for_each(months.begin(),months.end(),[](const auto& a)
    {
        cout << a << " ";
    });

    vector<char> abc(26);
    iota(abc.begin(),abc.end(),'a');

    

    return 0;
    }