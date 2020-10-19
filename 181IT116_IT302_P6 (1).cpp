#include <bits/stdc++.h>
#include <string.h>
using namespace std;

bool check(string str, int &a)
{
	for (int a = 0; a < str.size(); a++)
	{
		if (str[a] >= '0' && str[a] <= '9')
		{
			continue;
		}
		
		a = INT_MIN;
		return false;
	}
	
	a = atoi(str.c_str());
	return true;
}

long long int ncr(int n, int r)
{  
    if (r > n - r) 
    {
    	r = n - r; 
	}
	
	long long int ans = 1;
    for (int i = 0; i < r; ++i)
	{ 
        ans *= (n - i); 
        ans /= (i + 1); 
    } 
  
    return ans; 	
}

long long int Prob(int m, int n, int o, int a, int x, int y)
{
	if ((x+y) > a)
	{
		return 0;
	}
	
	int z = a-(x+y);
	if (z > o)
	{
		return 0;
	}
	
	return ncr(m, x)*ncr(n, y)*ncr(o, z);
}

int main()
{
	ofstream file("181IT116_IT302_P6_Output_TC6.txt");
	if (!file)
	{
		cout << "File could not be opened" << endl;
		exit(1);
	}
	
	int m, n, o, a;
	string str;
	
	cout << "Enter (m): ";
	cin >> str;
    cout << endl;
	if (!check(str, m))
	{		
		cout << "Input not valid." << endl;
		file << "Input not valid." << endl;
		file.close();
		exit(0);
	}
	
	cout << "Enter (n): ";
	cin >> str;
    cout << endl;
	if (!check(str, n))
	{		
		cout << "Input not valid." << endl;
		file << "Input not valid." << endl;
		file.close();
		exit(0);
	}
	
	cout << "Enter (o): ";
	cin >> str;
    cout << endl;
	if (!check(str, o))
	{		
		cout << "Input not valid." << endl;
		file << "Input not valid." << endl;
		file.close();
		exit(0);
	}
	
	cout << "Enter (a): ";
	cin >> str;
    cout << endl;
	if (!check(str, a) || (a > m+n+o))
	{		
		cout << "Input not valid." << endl;
		file << "Input not valid." << endl;
		file.close();
		exit(0);
	}
	
	long double prob[m+1][n+1], exy = 0, ux = 0, uy = 0;
	memset(prob, 0, sizeof(prob));
	
	long long int den = ncr(m+n+o, a);

    cout << "Intermediate Answers: \n" << endl;
    file << "Intermediate Answers: \n" << endl;

	cout << endl << "Total number of ways of selecting: " << den << endl;
	file << endl << "Total number of ways of selecting: " << den << endl;
	
    cout << "Probability: " << "\n" << endl;
	file << "Probability: " << "\n" << endl;

	for (int x = 0; x <= m; x++)
	{
		for (int y = 0; y <= n; y++)
		{
			prob[x][y] = Prob(m, n, o, a, x, y) / (long double) den;
			cout << "f(" << x << ", " << y << ") = " << prob[x][y] << "    ";
			file << "f(" << x << ", " << y << ") = " << prob[x][y] << "    ";
			exy += x*y*prob[x][y];
			ux += x*prob[x][y];
			uy += y*prob[x][y];
		}
        cout << endl;
	}

	cout << endl << "E(X, Y) = " << exy << endl;
	file << endl << "E(X, Y) = " << exy << endl;
	
    cout << "UX = " << ux << endl;
	file << "UX = " << ux << endl;
	
    cout << "UY = " << uy << endl;
	file << "UY = " << uy << endl;
	
    cout << "Final Answer: " << endl;
    file << "Final Answer: " << endl;
	
    cout << endl << "Covariance = E(X, Y) - UX*UY = " << exy -ux*uy << endl;
	file << endl << "Covariance = E(X, Y) - UX*UY = " << exy -ux*uy << endl;
	
	file.close();
}
