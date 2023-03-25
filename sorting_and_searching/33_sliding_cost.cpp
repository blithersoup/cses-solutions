#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

#define ll long long

/*
 *
 * not pretty, calculates sums left and right of median and subtracts difference using size of each set
 *
 */



int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, k, x;
  cin >> n >> k;

  multiset<ll> l, r;

  vector<ll> v(n);

  for (int i = 0; i < n; i++) {
    cin >> x;
    v[i] = x;
  }
  
  if (k == 1) {
    for (int i = 0; i < n; i++) {
      cout << "0 ";
    }
    cout << "\n";
    return 0;
  }

  ll rsum = 0, lsum = 0, lsize = 0, rsize = 0;

  for (int i = 0; i < k; i++) {
    rsum += v[i];
    rsize++;
    r.emplace(v[i]);
  }

  for (int i = 0; i < (k / 2); i++) {
    rsum -= *r.begin();
    lsum += *r.begin();
    lsize++;
    rsize--;
    l.emplace(*r.begin());
    r.erase(r.begin());
  }

  n -= k;

  cout << (((*r.begin() * lsize) - lsum) + (rsum - (*r.begin() * rsize))) << " ";

  for (int i = 0; i < n; i++) {
    if (v[i] < *r.begin()) {
      lsum -= v[i];
      l.erase(l.find(v[i]));
      
      rsum += v[i + k];
      r.emplace(v[i + k]);
      
      lsum += *r.begin();
      l.emplace(*r.begin());
      
      rsum -= *r.begin();
      r.erase(r.begin());
    } else {
      rsum -= v[i];
      r.erase(r.find(v[i]));
      
      rsum += v[i + k];
      r.emplace(v[i + k]);
      
      rsum += *(--l.end());
      r.emplace(*(--l.end()));
      
      lsum -= *(--l.end());
      l.erase(--l.end());
      
      lsum += *r.begin();
      l.emplace(*r.begin());
      
      rsum -= *r.begin();
      r.erase(r.begin());
    }

    cout << (((*r.begin() * lsize) - lsum) + (rsum - (*r.begin() * rsize))) << " ";

  }
}
