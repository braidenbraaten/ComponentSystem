#include <vector>

template<typename _inIt, typename _Pr> inline
std::vector<_inIt> find_all(_inIt _First, _inIt _Last, _Pr _Pred)
{
	std::vector<_inIt>l_results;

	for (; _First != _Last; ++_First)
	{
		if (_Pred(*_First))
		{
			l_results.push_back(_First);
		}
	}

	return l_results;
}
