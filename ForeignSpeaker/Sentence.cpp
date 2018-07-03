#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace ForeignSpeakerApp;

//////////////////////////////////////////////////////////////////////////


Sentence::Sentence()
	: m_role(ESpeakerRole::Undefined)
{
}

Sentence::Sentence(const std::wstring& text, ESpeakerRole role)
	: m_text(text), m_role(role)
{
	assert(!m_text.empty());

	assert(ESpeakerRole::Undefined != role);
}

Sentence::~Sentence()
{
}

std::wstring Sentence::getText() const
{
	return m_text;
}

ESpeakerRole Sentence::getRole() const
{
	return m_role;
}

bool Sentence::isValid() const
{
	return (    ESpeakerRole::Undefined != m_role
			&& !m_text.empty());
}
