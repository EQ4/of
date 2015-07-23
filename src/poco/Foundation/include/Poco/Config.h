//
// Config.h
//
// $Id: //poco/1.4/Foundation/include/Poco/Config.h#3 $
//
// Library: Foundation
// Package: Core
// Module:  Foundation
//
// Feature configuration for the POCO libraries.
//
// Copyright (c) 2006-2010, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_Config_INCLUDED
#define Foundation_Config_INCLUDED


// Define to enable Windows Unicode (UTF-8) support
// NOTE: As of POCO C++ Libraries release 1.6.0, compiling POCO
// without POCO_WIN32_UTF8 defined on Windows is deprecated.
#ifndef POCO_WIN32_UTF8
#define POCO_WIN32_UTF8
#endif


// Define to enable C++11 support
#ifndef POCO_ENABLE_CPP11
#define POCO_ENABLE_CPP11
#endif


// Define to disable implicit linking
// #define POCO_NO_AUTOMATIC_LIBS


// Define to disable automatic initialization
// Defining this will disable ALL automatic 
// initialization framework-wide (e.g. Net
// on Windows, all Data back-ends, etc).
// 
#define POCO_NO_AUTOMATIC_LIB_INIT


// Define to disable FPEnvironment support
// #define POCO_NO_FPENVIRONMENT


// Define if std::wstring is not available
// #define POCO_NO_WSTRING


// Define to disable shared memory
// #define POCO_NO_SHAREDMEMORY


// Define if no <locale> header is available (such as on WinCE)
// #define POCO_NO_LOCALE


// Define to desired default thread stack size
// Zero means OS default
#ifndef POCO_THREAD_STACK_SIZE
	#define POCO_THREAD_STACK_SIZE 0
#endif


// Define to override system-provided
// minimum thread priority value on POSIX
// platforms (returned by Poco::Thread::getMinOSPriority()).
// #define POCO_THREAD_PRIORITY_MIN 0


// Define to override system-provided
// maximum thread priority value on POSIX
// platforms (returned by Poco::Thread::getMaxOSPriority()).
// #define POCO_THREAD_PRIORITY_MAX 31


// Define to disable small object optimization. If not 
// defined, Any and Dynamic::Var (and similar optimization
// candidates) will be auto-allocated on the stack in 
// cases when value holder fits into POCO_SMALL_OBJECT_SIZE
// (see below).
// 
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!! NOTE: Any/Dynamic::Var SOO will NOT work reliably   !!!
// !!! without C++11 (std::aligned_storage in particular). !!!
// !!! Only comment this out if your compiler has support  !!!
// !!! for std::aligned_storage.                           !!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// #define POCO_NO_SOO


// Small object size in bytes. When assigned to Any or Var,
// objects larger than this value will be alocated on the heap,
// while those smaller will be placement new-ed into an
// internal buffer.
#if !defined(POCO_SMALL_OBJECT_SIZE) && !defined(POCO_NO_SOO)
	#define POCO_SMALL_OBJECT_SIZE 32
#endif


// Define to disable compilation of DirectoryWatcher
// on platforms with no inotify.
// #define POCO_NO_INOTIFY


// Following are options to remove certain features
// to reduce library/executable size for smaller
// embedded platforms. By enabling these options,
// the size of a statically executable can be
// reduced by a few 100 Kbytes.


// No automatic registration of FileChannel in
// LoggingFactory - avoids FileChannel and friends 
// being linked to executable.
// #define POCO_NO_FILECHANNEL


// No automatic registration of SplitterChannel in
// LoggingFactory - avoids SplitterChannel being
// linked to executable.
// #define POCO_NO_SPLITTERCHANNEL


// No automatic registration of SyslogChannel in
// LoggingFactory - avoids SyslogChannel being
// linked to executable on Unix/Linux systems.
// #define POCO_NO_SYSLOGCHANNEL


// Define to enable MSVC secure warnings
// #define POCO_MSVC_SECURE_WARNINGS


// No support for INI file configurations in
// Poco::Util::Application.
// #define POCO_UTIL_NO_INIFILECONFIGURATION


// No support for JSON configuration in 
// Poco::Util::Application. Avoids linking of JSON
// library and saves a few 100 Kbytes.
// #define POCO_UTIL_NO_JSONCONFIGURATION


// No support for XML configuration in 
// Poco::Util::Application. Avoids linking of XML
// library and saves a few 100 Kbytes.
// #define POCO_UTIL_NO_XMLCONFIGURATION


// No IPv6 support
// Define to disable IPv6
// #define POCO_NET_NO_IPv6


// Windows CE has no locale support
#if defined(_WIN32_WCE)
	#define POCO_NO_LOCALE
#endif

// Enable the poco_debug_* and poco_trace_* macros
// even if the _DEBUG variable is not set.
// This allows the use of these macros in a release version.
// #define POCO_LOG_DEBUG

// Uncomment to disable the use of bundled OpenSSL binaries
// #define POCO_EXTERNAL_OPENSSL

#endif // Foundation_Config_INCLUDED
