// Team G\
// Amanda Lowe, Josh Minton, Brady Prince

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sync.c>

using namespace std;

int main() {
    // n = trainers
    // m = couches
	int nMin = 3;
	int mMin = 3;
	int nMax = 5;
	int mMax = 6;
	int useCouch = 0;
	
	bool trainer == true;
	bool cust == true;
    bool couch == true;
    
    char onCouch = "Customer is on couch";
    char trainerOnUni = "Trainer goes to waiting room on electric unicycle scooter";
    char trainerAss = "Trainer assists";
	
	    for (int i = 0; i < 100; i++) {

            // if customer arrives to fitness center
            // no trainer is available

            while (!trainer) {
                // if all couches occupied, customer leaves
                if (couch < mMin || couch > mMax) {
                    cust == false;
                }

                // customer goes to waiting room to take couch
                else if (cust) {
                    printf("%c %d\n", onCouch, i);
					useCouch++;
					if (useCouch > mMax) {
						cust[i] == false;
					}
					
                }
            }

            // if trainer becomes available
            while (trainer) {
				// pick customer based on FCFS
                // if customer arrives and trainer is available
                // trainer immediately assists walk in
               if (cust) {
					printf("%c\n", trainerAss);
					if (useCouch >= mMin || useCouch <= mMax) {
						sync.unfair(useCouch);
					}
                
					// goes to waiting room on electric unicycle scooter
					printf("%c\n", trainerOnUni);
					if (useCouch >= mMin || useCouch <= mMax) {
						sync.deadlock(useCouch, trainer, cust);
					}
					if (!trainer) {
						sync.starvation(useCouch, trainer);
					}
            	}
                    
                    
                }

                
            }
        }
		
return 0;
	

}
