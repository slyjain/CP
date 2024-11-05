
#include<bits/stdc++.h>
#include <vector>
#include <algorithm>
int main(){

std::vector<int> vector = {1, 0, 2, 0, 3,242,44,1,0000,0,0,46,0,0,6,9,90,0,0,01,0,33};
vector.erase(std::remove(vector.begin(), vector.end(), 0), vector.end());

for (int element : vector) {
    std::cout << element << " ";
}
}
