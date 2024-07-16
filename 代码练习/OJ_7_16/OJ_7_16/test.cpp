#include <iostream>
using namespace std;

//int main() {
//    float a, c, count;
//    char b;
//    cin >> a >> b;
//    if (a < 1.0)
//    {
//        if (b == 'y')
//        {
//            count = 25;
//        }
//        if (b == 'n')
//        {
//            count = 20;
//        }
//    }
//    else
//    {
//        if (b == 'y')
//        {
//            c = int(a - 1)+1;
//            count = 25 + c;
//        }
//        if (b == 'n')
//        {
//            c = int(a - 1)+1;
//            count = 20 + c;
//        }
//
//    }
//    cout << count << endl;
//
//}


#include<vector>

int Cost(vector<int> c)
{
    int cost = 0;
    auto first = c.begin();
    auto cur = c.begin() + 1;
    auto pre = c.begin() + 2;
    while (first != c.end())
    {
        int cost = 0;
        if (c.size() < 2) return cost; // 如果向量少于两个元素，则直接返回0  

        auto cur = c.begin();
        auto next = cur + 1;
        while (next != c.end()) {
            if (*cur < *next) {
                cost += *cur;
                cur++;
                next++;
            }
            else {
                cost += *next;
                cur++;
                next++; cur++;
                next++;
            }
            
        }
        return cost;
    }

}
int main() {
    const int i=3;
    int cost[i + 1];
    
    for (int j = 0; j < i; j++)
    {
        cin >> cost[j];
    }
    
    cost[i] = 0;
    vector<int> c;
    
    for (int j = 0; j < i + 1; j++)
    {
        c.push_back(cost[j]);
    }
    int money = Cost(c);
    cout << money << endl;

    return 0;
}