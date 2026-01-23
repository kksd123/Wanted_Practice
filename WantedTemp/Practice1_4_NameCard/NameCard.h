#pragma once
class NameCard
{
public:
	NameCard(const char* _name, 
		const char* _phoneNum, 
		const char* _email,
		const char* _job);
	~NameCard();
	NameCard(const NameCard&) = delete;
	NameCard& operator=(const NameCard&) = delete;
	void ShowData() const;

private:
	char* m_name = nullptr;
	char* m_phoneNumber = nullptr;
	char* m_email = nullptr;
	char* m_job = nullptr;
};

