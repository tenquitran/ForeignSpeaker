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
	if (text.empty())
	{
		assert(false); return;
	}

	// For simple two-person dialogs, we can "flip" the speaker role for the next sentence 
	// instead of passing the speaker role as an argument.

	static ESpeakerRole lastRole = ESpeakerRole::A;

	m_sentences.emplace_back(Sentence(text, lastRole));

	lastRole = (ESpeakerRole::A == lastRole ? ESpeakerRole::B : ESpeakerRole::A);
}

bool Dialog::isEmpty() const
{
	return m_sentences.empty();
}

void Dialog::clear()
{
	m_sentences.clear();
}

size_t Dialog::getSentenceCount() const
{
	return m_sentences.size();
}

Sentence Dialog::operator[](size_t index) const
{
	if (index >= m_sentences.size())
	{
		assert(false); return Sentence();
	}

	return m_sentences[index];
}
