#include<iostream>

#include "List.h"

int main() {
    int n, k, m;
    std::cout << ": "; std::cin >> n >> k >> m;    

    List people;
    for(int index = 0; index < n; index++) {
        people.add(index);
    }

    int index = k;
    while(!people.is_one()) {
        people.remove(index + m);
        index = (index + m) % n;
    }

    std::cout << people.print() << std::endl;

    return 0;
}