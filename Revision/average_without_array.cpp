//write a program that will take N as input and compute their average (restrctions:without using array
#include<iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cout << "Enter the number: ";
        cin >> num;
        sum += num;
    }
    cout << "The average is: " << sum / N << endl;


  return 0;
}