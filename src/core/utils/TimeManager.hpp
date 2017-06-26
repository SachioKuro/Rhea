#pragma once

#include "../InteractiveItem.hpp"
#include <chrono>

namespace utils {
	using namespace std::chrono;

	using clock_type = typename std::conditional<high_resolution_clock::is_steady,
		high_resolution_clock,
		steady_clock>::type;

	class TimeManager : public core::InteractiveItem
	{
	public:
		explicit TimeManager() {};

		milliseconds GetTime();
		milliseconds GetDeltaTime();
		milliseconds GetRealTime();
		milliseconds GetInFrameDeltaTime();

		virtual void Setup();
		virtual bool Update();
		virtual void Render();
		virtual void Destroy();

	private:
		static const clock_type clock;

		nanoseconds deltaTime_;
		nanoseconds frameTime_;
		nanoseconds realTime_;
		nanoseconds startTime_;
		bool paused_ = false;
	};
}