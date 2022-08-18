#include <iostream>
using namespace std;
#include "map.h"

  
int main()
{
    cout << endl;
    cout << "Hi! You are the up-and-coming trendy mall in your area!";
    cout << " Unfortunately, because your mall is so big and trendy, it is a little difficult for customers to navigate." << endl;
    cout << "But, you're the trendiest mall in the area, of course you have a high-tech solution!" << endl;
    cout << "Introducing you to the Google Maps of shopping complexes..." << endl;
    cout << "-------- NaviShop --------" << endl;
    cout << "Revolutionizing shopping experiences, so you stop dreading shopping, and start dreading your bank statement! ;)" << endl;
    cout << endl;
    cout << "As the mall operator, you must provide some information about your complex: " << endl;


    int num_stores;
    cout << "Number of stores: ";
    cin >> num_stores;

    int stores;
    stores = num_stores;

    Map *m = new Map(num_stores);

    m->prompt(num_stores);

    //m->print_map(num_stores);
    

    /*
    if(start > end) {
        m->find_path_reverse(start, end, num_stores, 0);
    } else {
        m->find_path(start, end, num_stores, 0);
    }*/

    
    
   return 0;    
}


