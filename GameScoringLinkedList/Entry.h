#pragma once
#include <string>
class Entry
{
public:
	Entry() = default;
	Entry(int score, const std::string& name,Entry* p )
		:
		score(score),
		name(name),
		pNext(p)
	{}
	Entry(const Entry& src)
		:
		score(src.score),
		name(src.name)
	{
		if (src.pNext != nullptr)
		{
			pNext = new Entry(*src.pNext);
		}
	}
	~Entry()
	{
		delete pNext;
		pNext = nullptr;
	}
	Entry* disconnect()
	{
		Entry* temp = pNext;
		pNext = nullptr;
		return temp;
	}
	int GetScore() const
	{
		return score;
	}
	int OverallScore()
	{
		if (pNext != nullptr)
		{
			return pNext->OverallScore() + score;
		}
		else
			return score;
	}
	int Count()
	{
		if (pNext != nullptr)
		{
			return pNext->Count() + 1;
		}
		else
			return 1;
	}
	std::string GetName() const
	{
		return name;
	}
private:
	std::string name;
	int score;
public:
	Entry* pNext = nullptr;
};