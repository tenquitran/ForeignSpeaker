#pragma once

#include <sapi.h>


namespace ForeignSpeakerApp
{
	class Speaker
	{
	public:
		Speaker();

		virtual ~Speaker();

		void speak(const std::wstring& phrase) const;

	private:
		CComPtr<ISpVoice> m_spVoice;
	};
}
