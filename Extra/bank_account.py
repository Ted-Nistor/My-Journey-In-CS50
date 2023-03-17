class BankAccount:
    def __init__(self, _balance, __account_number):
        self._balance = _balance
        self.__account_number = __account_number

    def deposit(self, amount):
        self._balance += amount
        return self._balance

    def withdraw(self,_balance, amount):
        if amount > self._balance:
            return False
        else:
            self._balance -= amount
            return True

    def get_balance(self):
        return self._balance

    def get_account_number(self):
        return self.__account_number

class CheckAccount(BankAccount):
    def __init__(self, balance, account_number, transaction_fee):
        super().__init__(balance, account_number)
        self.transaction_fee = transaction_fee

    def withdraw(self, amount):
        total_withdrawal = amount + self.transaction_fee
        if total_withdrawal > self._balance:
            print("Withdrawal failed!")
            return False
        else:
            self._balance -= total_withdrawal
            return True

class SavingAccount(BankAccount):
    def __init__(self, balance, account_number, interest_rate):
        super().__init__(balance, account_number)
        self.interest_rate = interest_rate

    def add_interest(self):
        interest = self._balance * self.interest_rate
        self._balance += interest

    def get_interest_rate(self, interest_rate):
        return self.interest_rate

def main():
    account1 = BankAccount(254.36, 1234)
    print(account1.get_balance())

    account2 = CheckAccount(1000, 5678, 1.50)
    account2.deposit(500)
    print(account2.get_balance())
    success = account2.withdraw(700)
    if success:
        print("Withdrawal successful!")
    else:
        print("Withdrawal failed!")
    print(account2.get_balance())

    account3 = SavingAccount(5000, 9012, 0.02)
    account3.add_interest()
    print(account3.get_balance())
main()
