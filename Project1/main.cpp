#include <iostream>
#include <vector>
#include <string>

using namespace std;





string operator * (unsigned n, const string &text)       // Multiplicarea stringului
{
	string result;
	while (n--) result += text;
	return result;
}





void multiplyByTens(vector<int> &V, int tens)            // Multiplicari cu puteri ale lui 10
{
	V.resize(V.size() + tens);
	for (int j = V.size() - 1; j >= tens; j--) V[j] = V[j - tens];
	for (int j = 0; j < tens; j++) V[j] = 0;
}





vector<int> operator * (int n, const vector<int> &V)     // Multiplicare int * BigInt
{
	if (n == 0) return vector<int>(1, 0);

	vector<int> result;

	int i = 0;
	int carry = 0;
	while (i < V.size() || carry > 0)
	{
		if (i < V.size()) carry += n * V[i];
		int digit = carry % 10;
		carry /= 10;
		result.push_back(digit);
		i++;
	}
	return result;
}





vector<int> operator - (const vector<int> &A, const vector<int> &B)       // Scadere
{
	vector<int> result = A;

	int i = 0;
	int borrow = 0;
	while (i < B.size() || borrow > 0)
	{
		int digit = result[i] - borrow;
		if (i < B.size()) digit -= B[i];
		borrow = 0;
		while (digit < 0)
		{
			borrow++;
			digit += 10;
		}
		result[i] = digit;
		i++;
	}

	// Stergerea de zerouri terminale 
	i = result.size() - 1;
	while (i > 0 && result[i] == 0)
	{
		result.pop_back();
		i--;
	}

	return result;
}





bool operator <= (const vector<int> &A, const vector<int> &B)      // Comparare BigInts
{
	if (A.size() < B.size()) return true;
	if (A.size() > B.size()) return false;

	for (int i = A.size() - 1; i >= 0; i--)
	{
		if (A[i] < B[i]) return true;
		if (A[i] > B[i]) return false;
	}

	return true;
}





ostream &operator << (ostream &strm, const vector<int> &V)     //Afisare
{
	for (int i = V.size() - 1; i >= 0; i--) strm << V[i];
	return strm;
}





vector<int> isqrt(const string &Nstring)
{
	string number = Nstring;
	if (number.size() % 2) number = "0" + number;         // Folosim perechi de cifre, ne asiguram ca avem un numar par de cifre 

	vector<int> C, RHS;                                     // C -> radacina in crestere
	while (number != "")                                  // Cat timp mai sunt perechi de luat in calcul
	{
		// Multiplicam RHS ( = T - 100 * C * C )  cu 100 si luam urmatoarele 2 cifre
		multiplyByTens(RHS, 2);
		RHS[1] = number[0] - '0';   RHS[0] = number[1] - '0';
		number.erase(0, 2);

		// Multiplicam C cu 10 si efectuam pentru ultima cifra
		multiplyByTens(C, 1);
		vector<int> twentyC = 2 * C;                         // 20C
		int x = 9;
		for (; x; x--)
		{
			vector<int> test = twentyC;
			test[0] = x;                                      // 20C + x
			test = x * test;                                  // x(20C + x)
			if (test <= RHS)                                // Gasim cel mai mare x astfel incat (10C+x)^2 <= T
			{                                                 //                     acesta este x(20C+x) <= T-(10C)^2 = RHS
				C[0] = x;
				RHS = RHS - test;
				break;
			}
		}
	}

	return C;
}





int main()
{
	string Nstring = "31";
	//Nstring = 100 * Nstring;                                // 1000-cifre string 
	//Nstring = 5 * Nstring;                                //   50-cifre string 

	cout << "isqrt(" << Nstring << ") \n = " << isqrt(Nstring) << '\n';
	
	int a; cin >> a;
}


