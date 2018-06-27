#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace ForeignSpeakerApp;

//////////////////////////////////////////////////////////////////////////


Dialog::Dialog()
{
}

Dialog::~Dialog()
{
}

void Dialog::addSentence(const std::wstring& text)
{
	// For simple two-person dialogs, we can "flip" the speaker role for the next sentence 
	// instead of passing the speaker role as an argument.

	static ESpeakerRole lastRole = ESpeakerRole::A;

	m_sentences.emplace_back(Sentence(text, lastRole));

	lastRole = (ESpeakerRole::A == lastRole ? ESpeakerRole::B : ESpeakerRole::A);
}

bool Dialog::empty() const
{
	return m_sentences.empty();
}

void Dialog::clear()
{
	m_sentences.clear();
}

Dialog::SentenceItr Dialog::cbegin() const
{
	return m_sentences.cbegin();
}

Dialog::SentenceItr Dialog::cend() const
{
	return m_sentences.cend();
}
