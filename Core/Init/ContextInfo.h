namespace Core
{
	struct ContextInfo
	{
		int majorVersion, minorVersion;
		bool core;//either core or compaibilty. Should typically use core

		ContextInfo()
		{
			majorVersion = 3;
			minorVersion = 3;
			core = true;
		}

		ContextInfo(int majorV, int minorV, bool isCore)
		{
			majorVersion = majorV;
			minorVersion = minorV;
			core = isCore;
		}

		ContextInfo(const ContextInfo &otherContext)
		{
			majorVersion = otherContext.majorVersion;
			minorVersion = otherContext.minorVersion;
			core = otherContext.core;
		}

		void operator=(const ContextInfo &otherContext)
		{
			majorVersion = otherContext.majorVersion;
			minorVersion = otherContext.minorVersion;
			core = otherContext.core;
		}
	};
}