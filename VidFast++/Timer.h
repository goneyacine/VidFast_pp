#pragma once

#include <iostream>
#include <chrono>


namespace VidFast
{
	namespace Debug
	{
		class Timer
		{
		public:
			Timer(std::string p_taskName);
			void Stop();
		private:
			std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
			std::string m_taskName;
		};

	}
}