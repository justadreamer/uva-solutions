#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <iomanip>
#include <list>
#include <stack>
#include <queue>
#include <bitset>
#include <numeric>

#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

typedef vector<int> vi;
const int MAX_LEDS = 10;
const int MAX_PARTS = 7;

int main(int argc, char* argv[]) {
    int N;
    
    string leds[] = {
        "YYYYYYN", //0
        "NYYNNNN", //1
        "YYNYYNY", //2
        "YYYYNNY", //3
        "NYYNNYY", //4
        "YNYYNYY", //5
        "YNYYYYY", //6
        "YYYNNNN", //7
        "YYYYYYY", //8
        "YYYYNYY"  //9
    };
    const string INIT_BURNED_MASK = "TTTTTTTT";
    
    int numbers[] = {1,2,3,4,5,6,7,8,9,10};
    
    while (cin>>N && N) {
        set<int> previous_matches(numbers,numbers+10);
        string burned_masks[MAX_LEDS+1];
        for (int i=0;i<=MAX_LEDS;++i) {
            burned_masks[i] = INIT_BURNED_MASK;
        }
        vector<string> input_leds;
        for (int i=0;i<N;++i) {
            string current_led; cin>>current_led;
            input_leds.push_back(current_led);
        }
        
        for (int ii=0;ii<N;++ii) {
            string current_led = input_leds[ii];
            set<int> new_matches;
            for (int i=0;i<MAX_LEDS;++i) {
                if (previous_matches.find(i+1)==previous_matches.end())
                    continue;
                //G = Good, B = Bad, T = Not Tested
                string burned_mask=INIT_BURNED_MASK;
                bool is_matching = true;
                for (int j=0;j<MAX_PARTS;++j) {
                    
                    if (current_led[j]=='Y' && leds[i][j]=='N') {
                        is_matching = false;
                        break;
                    } else if (current_led[j]=='N' && leds[i][j]=='Y') {
                        burned_mask[j]='B';
                    } else if (current_led[j]=='Y' && leds[i][j]=='Y') {
                        burned_mask[j]='G';
                    }
                }
                
                if (is_matching) {
                    bool is_burned_mask_matching = true;
                    for (int j=0;j<MAX_PARTS;++j) {
                        if (burned_mask[j]=='G' && burned_masks[i+1][j]=='B') {
                            is_burned_mask_matching = false;
                            break;
                        } else if (burned_mask[j]=='T') {
                            burned_mask[j]=burned_masks[i+1][j];
                        }
                    }
                    if (is_burned_mask_matching) {
                        new_matches.insert(i);
                        burned_masks[i]=burned_mask;
                    }
                }
            }
            
            previous_matches = new_matches;

            if (previous_matches.size()==0) {
                break;
            }
        }
        
        cout<<(previous_matches.size()>0 ? "MATCH" : "MISMATCH")<<endl;
        
    }
    return 0;
}