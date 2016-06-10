
#pragma once
class CHummerModel 
{
	public:
		CHummerModel();
		virtual ~CHummerModel();
		void Run();
	protected:
		virtual void Start() = 0;
		virtual void Stop() = 0;
		virtual void Alarm() = 0;
		virtual void EngineBoom() = 0;
		virtual bool IsAlarm();
};
