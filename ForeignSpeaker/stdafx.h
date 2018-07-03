// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// Additional headers our program requires.

#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <atlbase.h>

#include "Exception.h"
#include "FileFindWrapper.h"

#include "SpeakerRole.h"
#include "Sentence.h"
#include "Dialog.h"
#include "ContentLibrary.h"

#include "Speaker.h"

#include "ConversationManager.h"
