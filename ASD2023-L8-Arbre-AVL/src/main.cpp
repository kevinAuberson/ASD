#include <iostream>
#include <ostream>
#include <sstream>
#include "avlTree.h"

using namespace std;

#define LINE_BREAK std::cout << std::endl

int main() {

   avlTree<int> t;

   static const int EASY_VALUES[] = {2, 4, 6, 8, 12, 14, 16, 18, 20};
   static const int MEDIUM_VALUES[] = {7, 1, 15, 11, 5, 19, 9, 13, 3, 8, 10, 14, 18, 4, 16, 6, 12, 2, 17};
   static const int HARDCORE_VALUES[] = {-8, 23, -22, 11, -4, 25, 10, -15, -21, -7, -5, 6, 9, -3, -17, 12, -23, -12,
                                         24, -25, -6, -13, -20, -2, 5, 18, 7, 15, 13};

   for (int i: EASY_VALUES) {
      t.insert(i);
   }
      t.showIndented();

      LINE_BREAK;
      cout << "MIN : " << t.max();
      LINE_BREAK;
      cout << "MAX : " << t.min();
      LINE_BREAK;
      LINE_BREAK;

      cout << t << endl;
      t.insert(5);
      cout << t << endl;

      LINE_BREAK;

      avlTree<int> tree;
      stringstream ss;
      ss << t;
      ss >> tree;

      cout << tree << endl;

}