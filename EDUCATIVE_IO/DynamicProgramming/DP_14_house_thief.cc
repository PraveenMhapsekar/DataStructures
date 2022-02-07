using namespace std;

#include <iostream>
#include <vector>

class HouseThief {

public:
  int findMaxSteal(const vector<int> &wealth) {
    if (wealth.empty()) {
      return 0;
    }
    vector<int> dp(wealth.size() + 1); // '+1' to handle the zero house
    dp[0] = 0;                         // if there are no houses, the thief can't steal anything
    dp[1] = wealth[0];                 // only one house, so the thief have to steal from it

     cout << dp[1] << " ";
    // please note that dp[] has one extra element to handle zero house
    for (int i = 1; i < wealth.size(); i++) {
      dp[i + 1] = max(wealth[i] + dp[i - 1], dp[i]);
      cout << dp[i+1] << " ";
    }
    cout << endl;
    return dp[wealth.size()];
  }
};

int main(int argc, char *argv[]) {
  HouseThief *ht = new HouseThief();
  vector<int> wealth = {2, 5, 1, 3, 6, 2, 4};
  for(int i = 0; i < wealth.size(); i++)
   cout << wealth[i] << " ";
  cout << endl;
  cout << ht->findMaxSteal(wealth) << endl;
  wealth = vector<int>{2, 10, 14, 8, 1};

  for(int i = 0; i < wealth.size(); i++)
   cout << wealth[i] << " ";
  cout << endl;
  cout << ht->findMaxSteal(wealth) << endl;

  delete ht;
}

