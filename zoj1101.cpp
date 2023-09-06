#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int a[1010];
int b[1010];
int n,q;
int search(int m,int x, int y, int z)
{
	if (m == a[x] + a[y] + a[z]) return 1;
    else if (z == q && y == q - 1 && x == q - 2) return 0;
	else if (z < q) return search(m, x, y, z + 1);
	else if (z == q && y< q - 1 && x < q - 2) return search(m, x, y + 1, y + 2);
	else if (y == q-1 && z == q&&x<q-2) return search(m, x + 1, x + 2, x + 3);
}
int main()
{
	while (cin >> n && n != 0)
	{
		q = n - 1;
		memset(a, 0, 1010);
		memset(b, 0, 1010);
		
		if (n < 4)
		{
			for (int i = 1; i <= n; i++)
		    {
			cin >> a[i];
		    }
			cout << "no solution" << endl;
			continue;
		}
		else
		{   int j = 0;
		    int s;
			for (int i = 1; i <= n; i++)
			{
				cin >> a[i];
			}
			int l;
			int t;
			for (int i = 1; i <= n; i++)
			{
				if (i != 1)
				{
                     for (int k = n; k >= t; k--)
				     {
					    if (k == t) a[t] = l;
					    else a[k] = a[k - 1];
				     }
				}
				l = a[i];
				t = i;
				for (int k = i; k <= n ; k++)
				{
					if (k == n) continue;
					else a[k] = a[k + 1];
				}
                  if (search(l, 1, 2, 3) == 1)
			    {
				    j++;
				    b[j] = l;
					if (j == 1) s = b[j];
				    else if (b[j] >= b[j - 1]) s = b[j];
			    }
			}
            if(j==0)  cout << "no solution" << endl;
		    else
		    {
			    cout << s << endl;
		    }
		}
	}
	return 0;
}