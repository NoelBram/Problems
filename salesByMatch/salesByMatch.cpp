/*  Created: 12/9/20
    Modified: 12/10/20
    Completed: 12/10/20
Description:
    Alex works at a clothing store. There is a large pile of socks that must be paired by color for sale. 
    Given an array of integers representing the color of each sock, determine how many pairs of socks with 
    matching colors there are.
    For example, there are  socks with colors . There is one pair of color  and one of color . 
    There are three odd socks left, one of each color. The number of pairs is .
    Function Description:
    Complete the sockMerchant function in the editor below. It must return an integer representing the 
    number of matching pairs of socks that are available.
    sockMerchant has the following parameter(s):
    n: the number of socks in the pile
    ar: the colors of each sock
    Input Format
    The first line contains an integer , the number of socks represented in . 
    The second line contains  space-separated integers describing the colors  of the socks in the pile.
    Constraints
    1 <= n <= 100
    1 <= ar[i] <= 100, where 0 <= i < n
 where 
Output Format
Return the total number of matching pairs of socks that Alex can sell.
   
*/
#include "brambila.h"

vector<string> split_string(string);

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    if((n < 1) || (n > 100)){
        cout << " Error: n must be >= 1 && n must be <= 100. \n";
        return 0;
    }
    if((ar.size() < 1) || (ar.size() > n)){
        cout << " Error: ar must be >= 1 && ar must be <= n. \n";
        return 0;
    }

    int a, b;

    vector<int> copy(ar.begin(), ar.end()); 
    int pairs = 0;

    for(size_t i = 0; i < copy.size() - 1;  ++i){
        if((copy[i] < 1) || (copy[i] > 100)){
            cout << " Error: ar[i] must be >= 0 && ar[i] must be < 100. \n    at index " << i << " equals " << ar[i];
            return 0;
        }
        a = copy[i];
        for(size_t j = i + 1; j < copy.size(); ++j){
            b = copy[j];
            if(b == a){
                pairs++;
                copy.erase(copy.begin() + j);
                break;
            }
        }
    }

    return pairs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = sockMerchant(n, ar);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
