#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

/*ATM system:-
 1.check Balance
 2.Cash withdraw
 3.User Details
 4.Update phone no.
 5.Exit
*/
class atm
{
private:
    long int Acc_no;
    int pin_no;
    string Name;
    long double Balance;
    string Mobile_no;

public:
    void setData(long int acc, int pin, string name, double bala, string ph_no)
    {
        Acc_no = acc;
        pin_no = pin;
        Name = name;
        Balance = bala;
        Mobile_no = ph_no;
    }
    long int getAccNo()
    {
        return Acc_no;
    }
    string getName()
    {
        return Name;
    }
    int getPin()
    {
        return pin_no;
    }
    long double getbalance()
    {
        return Balance;
    }
    string getmobileNo()
    {
        return Mobile_no;
    }
    void SetMobileNo(string oldNo, string newNo)
    {
        if (Mobile_no == oldNo)
        {
            Mobile_no = newNo;
            cout << "Your Mobile NO. is updated" << endl;
            _getch();
        }
        else
        {
            cout << "Incorrect!!! old mobile no" << endl;
            _getch();
        }
    }
    void cashWithdraw(double amount)
    {
        if ((amount > 0) && (amount < Balance))
        {
            Balance -= amount;
            cout << "Please collect your cash" << endl;
            _getch();
        }
        else
        {
            cout << "You put invalid amount" << endl;
            _getch();
        }
    }
};
int main()
{
    system("cls");
    atm user[10];
    int choice = 0;
    user[0].setData(1234567, 111, "Sikandar", 345979.53, "9137893430");
    user[1].setData(8912343, 222, "Shardul", 45979.53, "3423452312");
    do
    {
        long int EnterAcc;
        int Enterpin;
        cout << "Enter your Account no" << endl;
        cin >> EnterAcc;
        cout << "Enter your Pin No." << endl;
        cin >> Enterpin;
        for (int i = 0; i < 2; i++)
        {

            if ((EnterAcc == user[i].getAccNo()) && (Enterpin == user[i].getPin()))
            {
                do
                {
                    string oldNo, newNo;
                    cout << "***********WELCOME TO ATM*************" << endl;
                    cout << "select one option" << endl;
                    cout << " 1. check Balance" << endl;
                    cout << " 2. cash withdraw" << endl;
                    cout << " 3. User Details" << endl;
                    cout << " 4. Update phone no." << endl;
                    cout << " 5. Exit" << endl;
                    cin >> choice;

                    switch (choice)
                    {
                    case 1:
                        cout << "Your Bank Balance : " << user[i].getbalance() << endl;
                        _getch();
                        break;
                    case 2:
                        double amount;
                        cout << "Enter the amount:";
                        cin >> amount;
                        user[i].cashWithdraw(amount);
                        cout << "Available Balance:" << user[i].getbalance();
                        _getch();
                        break;
                    case 3:
                        cout << "Name:" << user[i].getName() << endl;
                        cout << "Account NO.:" << user[i].getAccNo() << endl;
                        cout << "Pin No.:" << user[i].getPin() << endl;
                        cout << "Balance:" << user[i].getbalance() << endl;
                        cout << "Mobile No.:" << user[i].getmobileNo() << endl;
                        _getch();
                        break;
                    case 4:
                        cout << "Enter old mobile no.:" << endl;
                        cin >> oldNo;
                        cout << "Enter new mobile no.:" << endl;
                        cin >> newNo;
                        user[i].SetMobileNo(oldNo, newNo);
                        break;
                    case 5:
                        exit(0);
                    }

                } while (1);
            }
        }
        cout << "User details are invalid" << endl;
        break;

    } while (1);

    return 0;
}