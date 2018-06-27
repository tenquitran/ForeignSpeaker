#pragma once


namespace ForeignSpeakerApp
{
	// Role assumed by the speaker. Currently, our program supports only two roles.
	enum class ESpeakerRole
	{
		Undefined,
		A,    /* first peer */
		B,    /* second peer */
	};
}
