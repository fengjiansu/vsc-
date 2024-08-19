#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
using namespace std;
 
int main() {
    int m, n;
    cout << "输入m、n";
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    int i, j; 
    for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
    a[i][j] = 1 + rand() % 100;
     
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
        }
    cout << "\n";
 
    
	for (vector<vector<int> >::iterator it = a.begin(); it != a.end(); ++it)
	{
		sort(it->begin(), it->end());
	}

 
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
 
    return 0;
}