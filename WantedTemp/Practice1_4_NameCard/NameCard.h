#pragma once
class NameCard
{
public:
	NameCard(const char* _name, 
		const char* _phoneNum, 
		const char* _email,
		const char* _job);
	~NameCard();
	void ShowData();

private:
	char* m_name = nullptr;
	char* m_phoneNumber = nullptr;
	char* m_email = nullptr;
	char* m_job = nullptr;
};

