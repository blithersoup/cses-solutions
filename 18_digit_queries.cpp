#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

#define ll long long

ll E(ll i) {
  ll res = 1LL;
  for (int j = 0; j < i; j++) {
    res *= 10LL;
  }
  return res;
}

int solve() {
  ll t;
  cin >> t;

  if (t < 10LL) {
    return t;
  } 

  ll tot = 0LL, add = 10LL, i = 1LL;
  
  // find order of number
  while (tot + add <= t) { // until reaches upper bound

    tot += add; // adds next order of numbers
    i++; //increment order

    add = E(i) - E(i - 1); // number of numbers to add, E(i-1) have already been passed
    add *= i; // order is digits per number
  }
  
  // input adjusted for start of order
  t -= tot;
  
  // position of queried digit in number
  ll reversemod = i - (t % i) - 1;
  
  // number query is looking for
  ll ret = (t / i) + E(i - 1); 
  
  // digit found from position in number, cannot divide by zero
  if (reversemod) ret /= E(reversemod);
  ret %= 10;

  return ret;
}

int main() {
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cout << solve() << "\n";
  }
 
}

