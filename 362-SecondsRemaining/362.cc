#include <iostream>

using namespace std;

int main() {

   int CASE = 0, data;

   while (cin >> data && data) {

      cout << "Output for data set " << ++CASE << ", "
	   << data << " bytes:" << endl;


      int d, time = 0, delta = 0, total_time = 0;
      while (cin >> d) {
	 time++; total_time++;

	 data -= d;
	 delta += d;

	 //-- print out.
	 if (time >= 5) {
	    time = 0;
	    cout << "   Time remaining: ";

	    if (delta == 0) {
	       cout << "stalled" << endl;
	       continue;
	    }

	    if (data < 0) {
	       data = 0;
	    }

	       
	    int sec = ((data * 5) + delta - 1) / delta;
	    cout << sec << " seconds" << endl;

	    delta = 0;
	 }

	 if (data == 0)
	    break;
      }
      
      cout << "Total time: " << total_time << " seconds" << endl << endl;
   }
   
   return 0;
}
