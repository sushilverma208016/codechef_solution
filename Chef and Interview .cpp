#include <iostream>
#define ll long long int
using std::cout; using std::endl; using std::cin;

int main() {
  ll count, number;
   cin >> count;
   for (ll i = 0; i < count; ++i) {
      cin >> number;
      if(number==1) {cout <<"1"<< endl; continue; }
      else if(number==2) {cout <<"3"<< endl; continue; }
      if(number==3) {cout <<"4"<< endl; continue; }
      if(number==4) {cout <<"7"<< endl; continue; }
      ll sum = 1+number;
    //  cout << sum << endl;
      for ( ll j = 2; j * j <= number; ++j ) {
         if ( number % j == 0 ) {
            sum += j;
           // cout << sum << endl;
            sum += number / j;
           // cout << sum << endl;
         }
         if ( j * j == number ) sum -= j; // recalculate twice
      }
      cout << sum << endl;
   }
}