#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    int* pattern = new int[n];
    int* arr = new int[m];

    for(int i = 0; i < n; i++)
        std::cin >> pattern[i];

    for(int i = 0; i < m; i++)
        std::cin >> arr[i];


    bool found = false;
    for(int i = 0; i <= m - n && !found; i++) {
        found = true;
        for(int j = 0; j < n && found; j++) {
            if(arr[i+j] != pattern[j])
                found = false;
        }
    }

    std::cout << found <<std::endl;
}
