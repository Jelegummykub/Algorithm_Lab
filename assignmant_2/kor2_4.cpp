#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    const int Time = 100000;
    int timeslot[Time] = {0};

    for(int i = 0 ; i < n ; i++){
        int A , B;
        cin >> A >> B;

        timeslot[A]++;
        timeslot[B + 1]--;
    }

    int tempcus = 0;
    int maxcus = 0;
    int start = -1;
    int end = -1;


    for(int i = 0 ; i < Time ; i++){
        tempcus += timeslot[i];

        if(tempcus > maxcus){
            maxcus = tempcus;
            start = i;
        }

    }

    for (int i = start ; i < Time ; i++) {
        if (timeslot[i] < 0) {
            end = i - 1;
            break;
        }
    }

    cout << start << " " << end << " " << maxcus << endl;
    

}