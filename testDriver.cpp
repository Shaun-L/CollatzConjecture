// Shaun Lim
// CECS 325-01
// Prog 7 – 3n + 1 BigInt
// Due Date (5/3/2023)
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BigInt
{
    private:
        vector<char> v;
    public:

        BigInt(){};

        BigInt(int n)
        {
            char digit;
            while(n > 9)
            {  
                digit = n%10;
                n /= 10;
                v.push_back(digit);
            }
            digit = n;
            v.push_back(digit);
            
        }

        BigInt(string s)
        {
            for(int i = s.length()-1; i >= 0; i--)
            {
                v.push_back((char)((int)s[i]-48));
            }
        }

        BigInt operator+(BigInt n)
        {
            BigInt x;
            bool carry = false;

            while(n.size() > v.size())
            {
                v.push_back(0);
            }
            while(v.size() > n.size())
            {
                n.v.push_back(0);
            }
            for(int i = 0; i < n.size(); i++)
            {
                if (carry)
                {
                    if(((int)v[i] + (int)n[i])<9)
                    {
                        x.v.push_back((int)v[i] + (int)n[i] + 1);
                        carry = false;
                    } else {
                        x.v.push_back(((int)v[i] + (int)n[i] + 1)%10);
                    }
                } else {
                    if(((int)v[i] + (int)n[i])<10)
                    {
                        x.v.push_back((int)v[i] + (int)n[i]);
                    } else {
                        x.v.push_back(((int)v[i] + (int)n[i])%10);
                        carry = true;
                    }
                }
            }
            if(carry)
            {
                x.v.push_back(1);
            }
            while(x.v.back() == 0)
            {
                x.v.pop_back();
            }
            return x;
        }

        BigInt operator++()
        {
            bool carry = true;
            for(int i = 0; i < v.size(); i++)
            {
                if(carry && (int)v[i] < 9)
                {
                    v[i] = (int)v[i] + 1;
                    carry = false;
                } else if(carry && (int)v[i] == 9) {
                    v[i] = 0;
                } else {
                    break;
                }
            }
            if(carry)
            {
                v.push_back(1);
            }
            return *this;
            
        }

        BigInt operator++(int)
        {
            BigInt temp = *this;
            bool carry = true;
            for(int i = 0; i < v.size(); i++)
            {
                if(carry && (int)v[i] < 9)
                {
                    v[i] = (int)v[i] + 1;
                    carry = false;
                } else if(carry && (int)v[i] == 9) {
                    v[i] = 0;
                } else {
                    break;
                }
            }
            if(carry)
            {
                v.push_back(1);
            }
            return temp;
        }


        BigInt operator*(BigInt n)
        {
            BigInt temp = *this;
            for(int i = 1; i < (int)n[0]; i++)
            {
                *this = *this + temp;
            }
            return *this;
        }

        
        BigInt half()
        {
            int num;
            bool carry = false;
            BigInt temp;
            for(int i = v.size()-1; i >= 0; i--)
            {
                if(carry)
                {
                    num = 10+(int)v[i];
                } else {
                    num = (int)v[i];
                }

                if(num%2 != 0)
                {
                    temp.v.push_back(num/2);
                    carry = true;
                } else {
                    temp.v.push_back(num/2);
                    carry = false;
                }
            }
            reverse(temp.v.begin(), temp.v.end());
            while(temp.v.back() == 0)
            {
                temp.v.pop_back();
            }
            return temp;
        }

        bool operator<(BigInt n)
        {
            if(v.size() < n.size())
            {
                return true;
            } else if(v.size() > n.size()) {
                return false;
            }

            for(int i = v.size()-1; i >= 0; i--)
            {
                if((int)v[i] < (int)n.v[i])
                {
                    return true;
                } else if((int)v[i] > (int)n.v[i]) {
                    return false;
                }
            }
            return false;

        }

        bool isOdd()
        {
            if((int)v[0]%2 == 0)
            {
                return false;
            }
            return true;
        }

        bool isEven()
        {
            if((int)v[0]%2 == 0)
            {
                return true;
            }
            return false;
        }

        bool operator==(BigInt n)
        {
            if(v.size() != n.size())
            {
                return false;
            }
            for(int i = 0; i < v.size(); i++)
            {
                if((int)v[i] != (int)n.v[i])
                {
                    return false;
                }
            }
            return true;
        }


        int operator[](int n) const
        {
            return v[n];
        }

        int size() const
        {
            return v.size();
        }


};
ostream& operator<<(ostream& out, const BigInt& n)
{
    if(n.size()<=8)
    {
        for(int i = n.size()-1; i >=0; i--)
        {
            cout << (int)n[i];
        }
    } else {
        cout << (int)n[n.size()-1] << ".";
        for(int i = n.size()-2; i >= n.size()-8; i--)
        {
            cout <<(int)n[i];
        }
        cout <<"e"<<n.size()-1;
    }
    return out;
}



struct ThreeNp1{

    BigInt start;
    BigInt steps;
    BigInt max;
    BigInt odds;
    BigInt evens;

};

void print(ThreeNp1 temp) 
{
    cout << "start:"<<temp.start<<endl;
    cout << "steps:"<<temp.steps<<endl;
    cout << "max:"<<temp.max<<endl;
    cout << "odds:"<<temp.odds<<endl;
    cout << "evens:"<<temp.evens<<endl;

}



void findThreeNp1(BigInt n, ThreeNp1 & Np1, bool printSteps = false)
{
    if (printSteps)
    {
        cout << "->"<<'('<< n <<')';
    }
    if (Np1.max < n) // BigInt::operator<( )
        Np1.max = n; // No need to overload - C++ provides operator=( )

    if (n == BigInt(1)) // BigInt::operator==( )
    {
        return; // we are done
    }
    else if (n.isEven()) // BigInt::isEven()
    {
        Np1.evens++; // BigInt::operator++( )
        Np1.steps++;
        //findThreeNp1(n/2,N, printSteps); // BigInt::operator/( ) - Hard…
        findThreeNp1(n.half(), Np1, printSteps); //BigInt::half( ) - Easy
    }
    else if (n.isOdd()) // BigInt::isOdd( )
    {
        Np1.odds++;
        Np1.steps++;
        BigInt tempN(n); // BigInt constructor
        findThreeNp1(tempN*BigInt(3)+BigInt(1), Np1, printSteps); //BigInt::operator*( )
        //BigInt::operator+( )
    }
    else
    {
        cout << "How the hell did I get here?\n";
    return;
    }
}


int main()
{
    
    BigInt MAX(INT_MAX);
    cout << "The largest integer is "<< MAX<<endl;
    cout << "Twice the largest integer is "<< MAX + MAX << endl;
    BigInt start(INT_MAX); // BigInt constructor - use for submission
    //BigInt start(12); // BigInt constructor – use for testing
    bool printSteps = true;
    ThreeNp1 N = {start,0,0,0,0}; // initialize N
    findThreeNp1(start, N); // print out the steps
    cout << endl;
    print(N);
    

    return 0;
}