#pragma once


namespace ForeignSpeakerApp
{
	class Dialog
	{
		typedef std::vector<Sentence> SentenceColl;

	public:
		typedef std::vector<Sentence>::const_iterator SentenceItr;

	public:
		Dialog();

		virtual ~Dialog();

		void addSentence(const std::wstring& text);

		bool empty() const;

		void clear();

		SentenceItr cbegin() const;
		SentenceItr cend() const;

	private:
		SentenceColl m_sentences;
	};
}
