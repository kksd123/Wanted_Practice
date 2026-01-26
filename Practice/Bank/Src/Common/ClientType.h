#pragma once
//enum 대신 enumclass를 쓴건 StateType 이름이 나와서 BankStateType::Idle 이런식으로
//가독성이 더 좋을것이라 판단
enum class BankStateType
{
	Idle,
	CreateAccount,
	Deposit,
	Withdraw,
	Inquire
};

enum AccountType
{
	None = 0,
	eNormal,
	eCredit,
	eDonation,
	Max
};