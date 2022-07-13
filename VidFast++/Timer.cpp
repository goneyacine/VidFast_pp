#include "Timer.h"


using namespace VidFast::Debug;


Timer::Timer(std::string p_taskName)
{
	m_start = std::chrono::high_resolution_clock::now();
	m_taskName = p_taskName;
}

void Timer::Stop()
{

	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

	std::cout <<
	    m_taskName << " takes " << std::chrono::duration_cast<std::chrono::microseconds>(end - m_start).count()
		<< " us to procces ( " << std::chrono::duration_cast<std::chrono::microseconds>(end - m_start).count() / 1000 << "ms)"
		<< "\n";

}