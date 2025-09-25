#include <iostream>
#include <string>

using namespace std;

int main()
{
   int random_ikä;
   int* antton_ikä;

   random_ikä = 20;

   antton_ikä = &random_ikä;

   cout << "random ikä ====" << random_ikä << endl << endl << endl;
   cout << "antton ikä ====" << antton_ikä << endl << endl << endl;
}
