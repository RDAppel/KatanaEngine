
#pragma once

using namespace KatanaEngine;

namespace Test
{
	class BezierComp : public KatanaEngine::Bezier
	{
	public:

		virtual float GetWeightFor(const int index, const float value) const
		{
			const float t = value;
			const float t2 = t * t;
			const float t3 = t2 * t;

			if (index == 0) return -t3 + 3 * t2 - 3 * t + 1;
			if (index == 1) return 3 * t3 - 6 * t2 + 3 * t;
			if (index == 2) return -3 * t3 + 3 * t2;
			if (index == 3) return t3;

			return 0;
		}
	};
}