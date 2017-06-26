#include "TimeManager.hpp"

namespace utils {
	milliseconds TimeManager::GetTime() {
		return duration_cast<milliseconds>(frameTime_);
	}

	milliseconds TimeManager::GetDeltaTime() {
		return duration_cast<milliseconds>(deltaTime_);
	}

	milliseconds TimeManager::GetRealTime() {
		return duration_cast<milliseconds>(realTime_ - startTime_);
	}

	milliseconds TimeManager::GetInFrameDeltaTime() {
		auto duration = clock.now().time_since_epoch();
		nanoseconds now = duration_cast<nanoseconds>(duration);
		return duration_cast<milliseconds>(now - realTime_);
	}

	void TimeManager::Setup() {
		auto duration = clock.now().time_since_epoch();
		realTime_ = duration_cast<nanoseconds>(duration);
		startTime_ = realTime_;
		frameTime_ = nanoseconds::zero();
	}

	bool TimeManager::Update() {
		deltaTime_ = -realTime_;

		auto duration = clock.now().time_since_epoch();
		realTime_ = duration_cast<nanoseconds>(duration);

		deltaTime_ += realTime_;

		if (!paused_)
			frameTime_ += deltaTime_;

		return true;
	}

	void TimeManager::Render() {

	}

	void TimeManager::Destroy() {

	}

#ifdef TEST_TIME_MANAGER
#include <iostream>

	int main() {
		TimeManager tm;
		tm.Setup();
		std::cout << "Start: " << tm.GetTime().count() << std::endl;

		long j = 0;
		for (long i = 0; i < 1000000000; i++)
			j++;
		tm.Update();

		std::cout << "Duration: " << tm.GetDeltaTime().count() << std::endl;

		j = 0;
		for (long i = 0; i < 3000000000; i++)
			j++;
		tm.Update();

		std::cout << "Duration: " << tm.GetDeltaTime().count() << std::endl;

		std::cout << "End: " << tm.GetTime().count() << std::endl;
		std::cin.get();
	}
#endif // _DEBUG
}