#include <iostream>
using namespace std;



// Fast Modular Exponentiation
long long power(long long base, long long exp, long long mod)
{
    long long result = 1 % mod;//if mode=1 then result must be =0
    base = base % mod;

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }


        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}





int main()
{
    long long p, g;
    long long a, b;
    long long A, B;
    long long Ka, Kb;

    cout << "Enter prime number p: ";
    cin >> p;

    cout << "Enter primitive root g: ";
    cin >> g;

    cout << "Enter Alice private key a: ";
    cin >> a;

    cout << "Enter Bob private key b: ";
    cin >> b;

    // Public keys
    A = power(g, a, p);
    B = power(g, b, p);

    cout << "\nAlice public key (A): " << A << endl;
    cout << "Bob public key (B): " << B << endl;

    // Shared secret keys
    Ka = power(B, a, p);
    Kb = power(A, b, p);

    cout << "\nShared secret key for Alice: " << Ka << endl;
    cout << "Shared secret key for Bob: " << Kb << endl;

    return 0;
}
