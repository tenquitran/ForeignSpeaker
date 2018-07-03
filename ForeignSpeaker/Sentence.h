#pragma once


namespace ForeignSpeakerApp
{
	// Sentence of a dialog.
	class Sentence
	{
	public:
		Sentence();

		Sentence(const std::wstring& text, ESpeakerRole role);

		virtual ~Sentence();

		std::wstring getText() const;

		ESpeakerRole getRole() const;

		bool isValid() const;

	private:
		std::wstring m_text;

		ESpeakerRole m_role;
	};
}
