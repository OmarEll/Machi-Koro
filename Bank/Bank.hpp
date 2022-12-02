
class Bank{
private:
    int solde;
    static Bank* uniqueBank;
public:
    void deposit(int);
    int withdraw(int);
    Bank(int b):solde(b){};
    Bank(Bank&);
    ~Bank();
    static Bank& giveInstance();
    static void freeInstance();
    void deposit(int);
    int withdraw(int);
};
