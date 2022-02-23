// Given a list of daily stock prices (integers for simplicity), return the buy and sell prices for making the maximum profit.
#include <tuple>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

tuple <int, int>
find_buy_sell_stock_prices(vector<int> &A) {
  int size = A.size();
  int curMin = A[0];
  int gblSell = A[1];
  int curProfit = 0;
  int gblProfit = gblSell - curMin;

  // note :
  // wrt min number so far, what is the curret profit?
  // if current profit is optimal profit? if yes capture it and sell price
  for (int i = 1; i < size; i++) {
    curProfit = A[i] - curMin; // Current profit is current rate minus current buy;

    if (curMin > A[i]) { // capture minimum price as buy price
      curMin = A[i];
    }

    if (curProfit > gblProfit) { // save maximun current profit as global profit
      gblProfit = curProfit;
      gblSell   = A[i];
    }
  }
  
  // return buy & sell (buy price : sell price miuns profit)
	tuple <int, int> result(std::make_pair(gblSell - gblProfit, gblSell));
	return result;
}

int main() {
  vector<int> array = {1, 2, 3, 4, 3, 2, 1, 2, 5};
  tuple <int, int> result;
  result = find_buy_sell_stock_prices(array);
  cout << "Buy Price: " << get<0>(result) << ", Sell Price: " << get<1>(result) << endl;
  vector<int> array2 = {6, 7, 8, 4, 7, 2, 1};
  result = find_buy_sell_stock_prices(array2);
  cout << "Buy Price: " << get<0>(result) << ", Sell Price: " << get<1>(result) << endl;

  vector<int> array3 = {8, 6, 85, -14, 3, 71, 1};
  result = find_buy_sell_stock_prices(array3);
  cout << "Buy Price: " << get<0>(result) << ", Sell Price: " << get<1>(result) << endl;
}
