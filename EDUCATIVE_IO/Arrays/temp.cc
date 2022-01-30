#include <tuple>
#include <iostream>
#include <climits>
using namespace std;

tuple <int, int>
find_buy_sell_stock_prices(int *A, int size) {
  int curMin = A[0];
  int gblSell = A[1];
  int meh = 0;
  int msf = gblSell - curMin;
  // note :
  // wrt min number so far, what is the curret profit?
  // if current profit is optimal profit? if yes capture it and sell price

  for (int i = 1; i < size; i++) {
    meh = A[i] - curMin; // Current profit is current rate minus current buy;

    if (curMin > A[i]) { // capture minimum price as buy price
      curMin = A[i];
    }

    if (meh > msf) { // save maximun current profit as global profit
      msf = meh;
      gblSell  = A[i];
    }
  }
  
  // return buy & sell (buy price : sell price miuns profit)
	tuple <int, int> result(std::make_pair(gblSell - msf, gblSell));
	return result;
}

int main() {
//  int array[] = {1, 2, 3, 4, 3, 2, 1, 2, 5};
  int array[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
  tuple <int, int> result;
  result = find_buy_sell_stock_prices(array, 9);
  cout << "Buy Price: " << get<0>(result) << ", Sell Price: " << get<1>(result) << endl;
  int array2[] = {6, 7, 8, 4, 7, 2, 1};
  result = find_buy_sell_stock_prices(array2, 7);
  cout << "Buy Price: " << get<0>(result) << ", Sell Price: " << get<1>(result) << endl;

  int array3[] = {8, -6, 85, -14, 3, 71, 1};
  result = find_buy_sell_stock_prices(array3, 7);
  cout << "Buy Price: " << get<0>(result) << ", Sell Price: " << get<1>(result) << endl;
}