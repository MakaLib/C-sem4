#pragma once


class Punkt
{
public:
	Punkt(const int &x, const int &y);
	template<int T> int wsp() const
	{
		if(T == 0) return P_x;
		return P_y;
	};

	template <typename T> static T min(const T &x, const T &y)
	{
		if(x < y) return x;
		else return y;
	}

	template <typename T> static T max(const T &x, const T &y)
	{
		if(x < y) return y;
		else return x;
	}

	bool operator <(const Punkt &p) const
	{
		if(P_x < p.P_x) return true;
		else if (P_x == p.P_x)
		{
			if(P_y < p.P_y) return true;
			else return false;
		}
		else return false;
	}

private:
	int P_x;
	int P_y;
};