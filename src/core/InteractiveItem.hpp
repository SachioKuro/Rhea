#pragma once
#include <iostream>

namespace core {
	class InteractiveItem
	{
	public:
		static __int32 gID;
		const __int32 ID;

		explicit InteractiveItem();
		virtual ~InteractiveItem();

		virtual void Setup() = 0;
		virtual bool Update() = 0;
		virtual void Render() = 0;
		virtual void Destroy() = 0;
	};
}