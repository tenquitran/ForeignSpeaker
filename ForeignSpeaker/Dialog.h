#pragma once


namespace ForeignSpeakerApp
{
	// Sentences making a dialog.
	class Dialog
	{
		typedef std::vector<Sentence> SentenceColl;

	public:
		typedef std::vector<Sentence>::const_iterator SentenceItr;

	public:
		Dialog();

		virtual ~Dialog();

		void addSentence(const std::wstring& text);

		bool isEmpty() const;

		void clear();

		size_t getSentenceCount() const;

		Sentence operator[](size_t index) const;

	private:
		SentenceColl m_sentences;
	};
}
