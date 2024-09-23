#include "Account.hpp"

Account::Account(int initial_deposit)
{
	this->_totalAmount = initial_deposit;
}

Account::~Account(void)
{
	return ;
}
int	 Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}
void	Account::displayAccountsInfos( void )
{
	std::cout << "index: "<< RED << this->_accountIndex << RESET << ";";
	std::cout << "amount: "<< RED << Account::_totalAmount << RESET << ";";
	std::cout << "deposits: "<< RED << this->_nbDeposits << RESET << ";";
	std::cout << "withdrawals: "<< RED << this->_nbWithdrawals<< RESET << ";";
}

void	Account::makeDeposit( int deposit )
{
	std::cout << "index:"<< RED << this->_accountIndex << RESET << ";";
	std::cout << "p_amount:"<< RED << Account::_totalAmount << RESET << ";";
	std::cout << "deposit:"<< RED << deposit << RESET << ";";
	this->_nbDeposits += 1;
	this->_totalAmount += deposit;
	std::cout << "amount:"<< RED << Account::_totalAmount << RESET << ";";
	std::cout << "nb_deposits:"<< RED << this->_nbDeposits<< RESET << ";";
}

void	makeWithdrawal( int withdrawal )
{
	std::cout << "index:"<< RED << this->_accountIndex << RESET << ";";
	std::cout << "p_amount:"<< RED << Account::_totalAmount << RESET << ";";
	std::cout << "withdrawal:"<< RED << withdrawal << RESET << ";";
	this->nbWithdrawals += 1;
	this->_totalAmount -= withdrawal;
	std::cout << "amount:"<< RED << Account::_totalAmount << RESET << ";";
	std::cout << "nb_withdrawals:"<< RED << this->_nbWithdrawals<< RESET << ";";
}