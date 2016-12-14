#pragma once
#include <vector>
#include <queue>
template<typename T>

//Global Contiguous Data
//POD

//                                                                           IS NOT COMPLETE!

class GCData
{
	int index;
	bool isVacant;

	static std::vector<int> &getQueue() { static std::queue<int> q; return q; }

public:
	static std::vector<T> &getData() {static std::vector<T> d; return d; }

	static T &at(unsigned i) { return getData()[i]; }
	

	static void free(int i)
	{
		if (at(i).isVacant())getQueue().push(i); at(i).isVacant = true;
	}

	static int make()
	{
		int i = -1;
		if (getQueue().size() > 0)
		{
			i = getQueue().front();
			getQueue().pop();
		}
		else
		{

			i = getData().size();
			getData().emplace_back();
		}

		at(i).index = i;
		at(i).isVacant = true;
		
		return i;
	}

	int getIndex() { return index; }
	bool getActive() { return isVacant; }
};