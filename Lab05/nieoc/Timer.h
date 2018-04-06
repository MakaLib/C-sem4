#pragma once

#include <vector>
#include <iostream>
#include <algorithm>



class Timer {
public:
	Timer (): m_start(0), m_end(0) {}

	virtual ~Timer () {}

	void Attach (Timer *server) { server->m_timers.push_back(this);}

	void Detach (Timer *server) {
		int pos = std::find(server->m_timers.begin(), server->m_timers.end(), this) - server->m_timers.begin();
		Timer * tmp = server->m_timers[pos];
		server->m_timers[pos] = server->m_timers.back();
		server->m_timers.back() = tmp;

		server->m_timers.pop_back();
	}	

	int Get_Start() {return m_start;}
	int Get_End() {return m_end;}
	void Set_Start(const int &value) {m_start = value;}
	void Set_End(const int &value) {m_end = value;}
	//int Get_Size() { return m_timers.size();}

	
protected:
	std::vector <Timer *> m_timers;

	int m_start;
	int m_end;
	
};


class TimerDigital : public Timer {
public:
	TimerDigital (): Timer() {}

	TimerDigital (TimerDigital & timer){
		m_start = timer.m_start;
		m_end = timer.m_end;
		for (Timer * t : timer.m_timers) m_timers.push_back(t);
	}
};


class TimerServer : public Timer {
public:
	TimerServer() = default;

	void Synchronize() {for (Timer * el : m_timers) el->Set_Start(20);}
	void Reset() {for (Timer * el : m_timers) el->Set_Start(0);}
};

