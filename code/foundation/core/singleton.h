#pragma once
//------------------------------------------------------------------------------
/**
    @class Core::Singleton
  
    Implements a system specific Singleton
    
    @copyright
    (C) 2007 Radon Labs GmbH
    (C) 2013-2020 Individual contributors, see AUTHORS file
*/
#if __WIN32__
#include "core/win32/win32singleton.h"
#elif __OSX__
#include "core/osx/osxsingleton.h"
#elif __linux__
#include "core/posix/posixsingleton.h"
#else
#error "IMPLEMENT ME!"
#endif
