#pragma once
class NameCard
{
public:
	NameCard() = default;
	NameCard(const NameCard& other);
	~NameCard();

	//기본복사 못하게 막기 (Deep Copy 만 가능)
	//NameCard는 힙 메모리 직접 소유 하는 점
	//소멸자에서 delete[] (생성자에선 new[])
	//NameCard a 만든후 NameCard b = a; 로 기본복사하면 두 객체가 같은 메모리 가르켜서 소멸자에서 에러
	//NameCard(const NameCard&) = delete; //복사 생성자 사용을 위해 주석 처리
	NameCard& operator=(const NameCard&) = delete;

	void CopyData(const char* name,
		const char* phone,
		const char* email,
		const char* job);

	void ShowData() const;

private:
	char* m_name = nullptr;
	char* m_phoneNumber = nullptr;
	char* m_email = nullptr;
	char* m_job = nullptr;
};

