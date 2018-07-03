#pragma once


namespace ForeignSpeakerApp
{
	class Speaker
	{
	public:
		Speaker();

		virtual ~Speaker();

		void speak(const std::wstring& phrase) const;

	private:
		;
	};
}
