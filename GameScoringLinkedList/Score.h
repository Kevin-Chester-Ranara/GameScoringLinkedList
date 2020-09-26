#pragma once

#include "Entry.h"
#include <iostream>

class Score
{
public:
	class Iterator
	{
	public:
		Iterator() = default;
		Iterator(Entry* elemento)
			:
			pTop(elemento)
		{}
		Iterator& operator++()
		{
			pTop = pTop->pNext;
			return *this;
		}
		int operator*() const
		{
			return pTop->GetScore();
		}
		bool operator!=(const Iterator& rhs)const
		{
			return pTop != rhs.pTop;
		}
	private:
		Entry* pTop = nullptr;
	};
public:
	/*void AddScore(std::string& name, int score)
	{
		Entry* cur = topentry;
		if (IsEmpty())
		{
			topentry = new Entry(score, name, topentry);
		}
		else if (score >= topentry->GetScore())
		{
			topentry = new Entry(score, name, topentry);
		}
		else
		{
			for (; cur != nullptr; cur = cur->pNext)
			{
				Entry* next = cur->pNext;
				if (score <= cur->GetScore() && next == nullptr)
				{
					cur->pNext = new Entry(score, name, next);
					break;
				}
				else if (score <= cur->GetScore() && score >= next->GetScore())
				{
					cur->pNext = new Entry(score, name, next);
					break;
				}
			}
		}
	}*/
	void AddScore(const std::string& name, int score)
	{
		topentry = Adding(name, score, topentry);
	}
	std::string remove(const std::string& name)
	{
		Entry* prev = nullptr;
		Entry* cur = topentry;
		Entry* next = cur->pNext;
		for (; cur != nullptr; prev=cur,cur = cur->pNext)
		{
			if (topentry->GetName()._Equal(name))
			{
				Entry* temp;
				std::string n = topentry->GetName();
				temp = topentry;
				topentry = topentry->disconnect();
				delete temp;
				return n;
			}
			else if(cur->GetName()._Equal(name))
			{
				Entry* temp = cur;
				std::string n = cur->GetName();
				prev->pNext = cur->disconnect();
				delete temp;
				return n;
			}
		}
	}
	Iterator begin()
	{
		return { topentry };
	}
	Iterator end()
	{
		return {};
	}
	int GetAverage()
	{
		return topentry->OverallScore() / topentry->Count();
	}
	void Display()
	{
		Entry* d = topentry;
		while (d != nullptr)
		{
			std::cout << d->GetName() << std::endl;
			std::cout << d->GetScore() << std::endl;
			d = d->pNext;
		}
	}
	bool IsEmpty()
	{
		return topentry == nullptr;
	}

private:
	Entry* Adding(const std::string& name, int score, Entry* pNext)
	{
		if (IsEmpty())
		{
			pNext = new Entry(score, name, pNext);
		}
		else if (score >= pNext->GetScore())
		{
			pNext = new Entry(score, name, pNext);
		}
		else if (pNext->pNext == nullptr)
		{
			pNext->pNext = new Entry(score, name, pNext->pNext);
		}
		else if (score <= pNext->GetScore() && score >= pNext->pNext->GetScore())
		{
			pNext->pNext = new Entry(score, name, pNext->pNext);
		}
		else if (score <= pNext->GetScore())
		{
			pNext->pNext = Adding(name, score, pNext->pNext);
		}
		return pNext;
	}
private:
	Entry* topentry = nullptr;
};