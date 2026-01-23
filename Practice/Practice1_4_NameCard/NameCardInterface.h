#pragma once
#include "NameCard.h"


class NameCardInterface
{
public:
    NameCardInterface();
    ~NameCardInterface();

    NameCardInterface(const NameCardInterface&) = delete;
    NameCardInterface& operator=(const NameCardInterface&) = delete;

    void RecvData();

private:
    void CreateCard(int index,
        const char* name,
        const char* phone,
        const char* email,
        const char* job);

    void DestroyCard(int index);
    void DestroyAll();
    void PrintData() const;

private:
    NameCard* m_nameCards[3];
};
