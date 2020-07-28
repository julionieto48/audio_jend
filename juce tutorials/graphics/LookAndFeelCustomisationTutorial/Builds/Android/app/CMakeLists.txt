# Automatically generated makefile, created by the Projucer
# Don't edit this file! Your changes will be overwritten when you re-save the Projucer project!

cmake_minimum_required(VERSION 3.4.1)

SET(BINARY_NAME "juce_jni")

add_library("cpufeatures" STATIC "${ANDROID_NDK}/sources/android/cpufeatures/cpu-features.c")
set_source_files_properties("${ANDROID_NDK}/sources/android/cpufeatures/cpu-features.c" PROPERTIES COMPILE_FLAGS "-Wno-sign-conversion -Wno-gnu-statement-expression")

add_definitions("-DJUCE_ANDROID=1" "-DJUCE_ANDROID_API_VERSION=16" "-DJUCE_PUSH_NOTIFICATIONS=1" "-DJUCE_PUSH_NOTIFICATIONS_ACTIVITY=\"com/roli/juce/JuceActivity\"" "-DJUCER_ANDROIDSTUDIO_7F0E4A25=1" "-DJUCE_APP_VERSION=1.0.0" "-DJUCE_APP_VERSION_HEX=0x10000")

include_directories( AFTER
    "../../../JuceLibraryCode"
    "/Users/tom/Development/JUCE-utils/CI/macOS/../../../JUCE-dev/modules"
    "${ANDROID_NDK}/sources/android/cpufeatures"
)

enable_language(ASM)

IF(JUCE_BUILD_CONFIGURATION MATCHES "DEBUG")
    add_definitions("-DDEBUG=1" "-D_DEBUG=1")
ELSEIF(JUCE_BUILD_CONFIGURATION MATCHES "RELEASE")
    add_definitions("-DNDEBUG=1")
ELSE(JUCE_BUILD_CONFIGURATION MATCHES "DEBUG")
    MESSAGE( FATAL_ERROR "No matching build-configuration found." )
ENDIF(JUCE_BUILD_CONFIGURATION MATCHES "DEBUG")

add_library( ${BINARY_NAME}

    SHARED

    "../../../Source/Main.cpp"
    "../../../Source/LookAndFeelCustomisationTutorial_01.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_AbstractFifo.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_AbstractFifo.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_Array.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_ArrayAllocationBase.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_ArrayBase.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_ArrayBase.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_DynamicObject.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_DynamicObject.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_ElementComparator.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_HashMap.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_HashMap_test.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_LinkedListPointer.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_ListenerList.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_NamedValueSet.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_NamedValueSet.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_OwnedArray.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_OwnedArray.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_PropertySet.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_PropertySet.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_ReferenceCountedArray.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_ReferenceCountedArray.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_ScopedValueSetter.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_SortedSet.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_SparseSet.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_SparseSet.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_Variant.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_Variant.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_DirectoryIterator.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_DirectoryIterator.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_File.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_File.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_FileFilter.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_FileFilter.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_FileInputStream.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_FileInputStream.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_FileOutputStream.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_FileOutputStream.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_FileSearchPath.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_FileSearchPath.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_MemoryMappedFile.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_TemporaryFile.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_TemporaryFile.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_WildcardFileFilter.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_WildcardFileFilter.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/javascript/juce_Javascript.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/javascript/juce_Javascript.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/javascript/juce_JSON.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/javascript/juce_JSON.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/logging/juce_FileLogger.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/logging/juce_FileLogger.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/logging/juce_Logger.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/logging/juce_Logger.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_BigInteger.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_BigInteger.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_Expression.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_Expression.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_MathsFunctions.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_NormalisableRange.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_Random.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_Random.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_Range.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_StatisticsAccumulator.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_Atomic.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_ByteOrder.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_ContainerDeletePolicy.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_HeapBlock.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_HeavyweightLeakedObjectDetector.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_LeakedObjectDetector.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_Memory.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_MemoryBlock.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_MemoryBlock.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_OptionalScopedPointer.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_ReferenceCountedObject.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_ScopedPointer.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_SharedResourcePointer.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_Singleton.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_WeakReference.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_ConsoleApplication.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_ConsoleApplication.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_Result.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_Result.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_RuntimePermissions.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_RuntimePermissions.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_StdFunctionCompat.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_StdFunctionCompat.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_Uuid.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_Uuid.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_WindowsRegistry.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/java/README.txt"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_android_Files.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_android_JNIHelpers.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_android_JNIHelpers.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_android_Misc.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_android_Network.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_android_RuntimePermissions.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_android_SystemStats.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_android_Threads.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_BasicNativeHeaders.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_curl_Network.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_linux_CommonFile.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_linux_Files.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_linux_Network.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_linux_SystemStats.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_linux_Threads.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_mac_ClangBugWorkaround.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_mac_Files.mm"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_mac_Network.mm"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_mac_Strings.mm"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_mac_SystemStats.mm"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_mac_Threads.mm"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_osx_ObjCHelpers.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_posix_IPAddress.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_posix_NamedPipe.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_posix_SharedCode.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_win32_ComSmartPtr.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_win32_Files.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_win32_Network.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_win32_Registry.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_win32_SystemStats.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_win32_Threads.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_IPAddress.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_IPAddress.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_MACAddress.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_MACAddress.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_NamedPipe.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_NamedPipe.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_Socket.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_Socket.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_URL.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_URL.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_WebInputStream.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_WebInputStream.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_BufferedInputStream.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_BufferedInputStream.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_FileInputSource.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_FileInputSource.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_InputSource.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_InputStream.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_InputStream.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_MemoryInputStream.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_MemoryInputStream.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_MemoryOutputStream.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_MemoryOutputStream.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_OutputStream.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_OutputStream.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_SubregionStream.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_SubregionStream.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_URLInputSource.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_URLInputSource.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/system/juce_CompilerSupport.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/system/juce_PlatformDefs.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/system/juce_StandardHeader.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/system/juce_SystemStats.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/system/juce_SystemStats.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/system/juce_TargetPlatform.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_Base64.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_Base64.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_CharacterFunctions.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_CharacterFunctions.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_CharPointer_ASCII.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_CharPointer_UTF8.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_CharPointer_UTF16.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_CharPointer_UTF32.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_Identifier.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_Identifier.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_LocalisedStrings.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_LocalisedStrings.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_NewLine.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_String.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_String.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_StringArray.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_StringArray.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_StringPairArray.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_StringPairArray.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_StringPool.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_StringPool.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_StringRef.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_TextDiff.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_TextDiff.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ChildProcess.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ChildProcess.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_CriticalSection.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_DynamicLibrary.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_HighResolutionTimer.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_HighResolutionTimer.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_InterProcessLock.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_Process.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ReadWriteLock.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ReadWriteLock.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ScopedLock.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ScopedReadLock.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ScopedWriteLock.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_SpinLock.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_Thread.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_Thread.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ThreadLocalValue.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ThreadPool.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ThreadPool.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_TimeSliceThread.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_TimeSliceThread.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_WaitableEvent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/time/juce_PerformanceCounter.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/time/juce_PerformanceCounter.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/time/juce_RelativeTime.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/time/juce_RelativeTime.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/time/juce_Time.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/time/juce_Time.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/unit_tests/juce_UnitTest.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/unit_tests/juce_UnitTest.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/unit_tests/juce_UnitTestCategories.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/xml/juce_XmlDocument.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/xml/juce_XmlDocument.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/xml/juce_XmlElement.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/xml/juce_XmlElement.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/adler32.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/compress.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/crc32.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/crc32.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/deflate.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/deflate.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/infback.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/inffast.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/inffast.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/inffixed.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/inflate.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/inflate.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/inftrees.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/inftrees.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/trees.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/trees.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/uncompr.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/zconf.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/zconf.in.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/zlib.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/zutil.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/zutil.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/juce_GZIPCompressorOutputStream.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/juce_GZIPCompressorOutputStream.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/juce_GZIPDecompressorInputStream.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/juce_GZIPDecompressorInputStream.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/juce_ZipFile.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/juce_ZipFile.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/juce_core.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/juce_core.mm"
    "../../../../../../../../JUCE-dev/modules/juce_core/juce_core.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/app_properties/juce_ApplicationProperties.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/app_properties/juce_ApplicationProperties.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/app_properties/juce_PropertiesFile.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/app_properties/juce_PropertiesFile.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/undomanager/juce_UndoableAction.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/undomanager/juce_UndoManager.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/undomanager/juce_UndoManager.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_CachedValue.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_CachedValue.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_Value.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_Value.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_ValueTree.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_ValueTree.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_ValueWithDefault.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_ValueWithDefault.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/juce_data_structures.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/juce_data_structures.mm"
    "../../../../../../../../JUCE-dev/modules/juce_data_structures/juce_data_structures.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/broadcasters/juce_ActionBroadcaster.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/broadcasters/juce_ActionBroadcaster.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/broadcasters/juce_ActionListener.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/broadcasters/juce_AsyncUpdater.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/broadcasters/juce_AsyncUpdater.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/broadcasters/juce_ChangeBroadcaster.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/broadcasters/juce_ChangeBroadcaster.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/broadcasters/juce_ChangeListener.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/interprocess/juce_ConnectedChildProcess.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/interprocess/juce_ConnectedChildProcess.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/interprocess/juce_InterprocessConnection.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/interprocess/juce_InterprocessConnection.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/interprocess/juce_InterprocessConnectionServer.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/interprocess/juce_InterprocessConnectionServer.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/interprocess/juce_NetworkServiceDiscovery.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/interprocess/juce_NetworkServiceDiscovery.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_ApplicationBase.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_ApplicationBase.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_CallbackMessage.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_DeletedAtShutdown.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_DeletedAtShutdown.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_Initialisation.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_Message.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_MessageListener.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_MessageListener.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_MessageManager.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_MessageManager.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_MountedVolumeListChangeDetector.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_NotificationType.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_android_Messaging.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_ios_MessageManager.mm"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_linux_EventLoop.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_linux_Messaging.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_mac_MessageManager.mm"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_osx_MessageQueue.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_win32_HiddenMessageWindow.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_win32_Messaging.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_win32_WinRTWrapper.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_win32_WinRTWrapper.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/timers/juce_MultiTimer.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/timers/juce_MultiTimer.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/timers/juce_Timer.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/timers/juce_Timer.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/juce_events.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/juce_events.mm"
    "../../../../../../../../JUCE-dev/modules/juce_events/juce_events.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/colour/juce_Colour.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/colour/juce_Colour.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/colour/juce_ColourGradient.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/colour/juce_ColourGradient.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/colour/juce_Colours.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/colour/juce_Colours.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/colour/juce_FillType.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/colour/juce_FillType.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/colour/juce_PixelFormats.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/contexts/juce_GraphicsContext.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/contexts/juce_GraphicsContext.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/contexts/juce_LowLevelGraphicsContext.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/effects/juce_DropShadowEffect.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/effects/juce_DropShadowEffect.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/effects/juce_GlowEffect.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/effects/juce_GlowEffect.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/effects/juce_ImageEffectFilter.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_AttributedString.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_AttributedString.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_CustomTypeface.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_CustomTypeface.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_Font.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_Font.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_GlyphArrangement.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_GlyphArrangement.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_TextLayout.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_TextLayout.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_Typeface.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_Typeface.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_AffineTransform.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_AffineTransform.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_BorderSize.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_EdgeTable.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_EdgeTable.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_Line.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_Parallelogram.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_Path.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_Path.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_PathIterator.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_PathIterator.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_PathStrokeType.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_PathStrokeType.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_Point.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_Rectangle.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_RectangleList.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/cderror.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/changes to libjpeg for JUCE.txt"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcapimin.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcapistd.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jccoefct.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jccolor.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcdctmgr.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jchuff.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jchuff.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcinit.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcmainct.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcmarker.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcmaster.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcomapi.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jconfig.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcparam.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcphuff.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcprepct.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcsample.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jctrans.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdapimin.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdapistd.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdatasrc.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdcoefct.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdcolor.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdct.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jddctmgr.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdhuff.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdhuff.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdinput.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdmainct.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdmarker.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdmaster.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdmerge.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdphuff.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdpostct.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdsample.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdtrans.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jerror.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jerror.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jfdctflt.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jfdctfst.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jfdctint.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jidctflt.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jidctfst.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jidctint.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jidctred.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jinclude.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jmemmgr.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jmemnobs.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jmemsys.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jmorecfg.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jpegint.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jpeglib.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jquant1.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jquant2.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jutils.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jversion.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/transupp.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/transupp.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/libpng_readme.txt"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/png.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/png.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngconf.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngerror.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngget.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pnginfo.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngmem.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngpread.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngpriv.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngread.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngrio.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngrtran.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngrutil.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngset.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngstruct.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngtrans.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngwio.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngwrite.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngwtran.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngwutil.c"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/juce_GIFLoader.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/juce_JPEGLoader.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/juce_PNGLoader.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/images/juce_Image.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/images/juce_Image.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/images/juce_ImageCache.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/images/juce_ImageCache.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/images/juce_ImageConvolutionKernel.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/images/juce_ImageConvolutionKernel.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/images/juce_ImageFileFormat.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/images/juce_ImageFileFormat.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_android_Fonts.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_android_GraphicsContext.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_android_IconHelpers.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_freetype_Fonts.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_linux_Fonts.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_linux_IconHelpers.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.mm"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_mac_CoreGraphicsHelpers.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_mac_Fonts.mm"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_mac_IconHelpers.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_RenderingHelpers.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_win32_DirectWriteTypeface.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_win32_DirectWriteTypeLayout.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_win32_Fonts.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_win32_IconHelpers.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/placement/juce_Justification.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/placement/juce_RectanglePlacement.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/placement/juce_RectanglePlacement.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/juce_graphics.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/juce_graphics.mm"
    "../../../../../../../../JUCE-dev/modules/juce_graphics/juce_graphics.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/application/juce_Application.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/application/juce_Application.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ArrowButton.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ArrowButton.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_Button.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_Button.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_DrawableButton.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_DrawableButton.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_HyperlinkButton.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_HyperlinkButton.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ImageButton.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ImageButton.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ShapeButton.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ShapeButton.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_TextButton.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_TextButton.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ToggleButton.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ToggleButton.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ToolbarButton.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ToolbarButton.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/commands/juce_ApplicationCommandID.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/components/juce_CachedComponentImage.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/components/juce_Component.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/components/juce_Component.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/components/juce_ComponentListener.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/components/juce_ComponentListener.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/components/juce_ModalComponentManager.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/components/juce_ModalComponentManager.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/desktop/juce_Desktop.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/desktop/juce_Desktop.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/desktop/juce_Displays.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/desktop/juce_Displays.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_Drawable.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_Drawable.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableComposite.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableComposite.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableImage.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableImage.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawablePath.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawablePath.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableRectangle.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableRectangle.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableShape.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableShape.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableText.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableText.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_SVGParser.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_ContentSharer.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_ContentSharer.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileBrowserListener.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileChooser.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileChooser.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileListComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileListComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FilePreviewComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_CaretComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_CaretComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_KeyListener.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_KeyListener.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_KeyPress.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_KeyPress.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_ModifierKeys.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_ModifierKeys.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_SystemClipboard.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_TextEditorKeyMapper.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_TextInputTarget.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_AnimatedPosition.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_AnimatedPositionBehaviours.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ComponentAnimator.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ComponentAnimator.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ComponentBuilder.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ComponentBuilder.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ConcertinaPanel.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ConcertinaPanel.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_FlexBox.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_FlexBox.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_FlexItem.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_Grid.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_Grid.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_GridItem.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_GridItem.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_GroupComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_GroupComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ScrollBar.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ScrollBar.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_SidePanel.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_SidePanel.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_TabbedButtonBar.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_TabbedButtonBar.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_TabbedComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_TabbedComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_Viewport.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_Viewport.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/menus/juce_MenuBarComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/menus/juce_MenuBarComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/menus/juce_MenuBarModel.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/menus/juce_MenuBarModel.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/menus/juce_PopupMenu.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/menus/juce_PopupMenu.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/misc/juce_BubbleComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/misc/juce_BubbleComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/misc/juce_DropShadower.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/misc/juce_DropShadower.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/misc/juce_JUCESplashScreen.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/misc/juce_JUCESplashScreen.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_ComponentDragger.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_ComponentDragger.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_DragAndDropTarget.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_FileDragAndDropTarget.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_LassoComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseCursor.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseCursor.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseEvent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseEvent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseInputSource.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseInputSource.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseListener.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseListener.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_SelectedItemSet.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_TextDragAndDropTarget.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_TooltipClient.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_android_ContentSharer.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_android_FileChooser.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_android_Windowing.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_common_MimeTypes.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_ios_ContentSharer.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_ios_FileChooser.mm"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_ios_UIViewComponentPeer.mm"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_ios_Windowing.mm"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_linux_FileChooser.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_linux_X11.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_linux_X11.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_linux_X11_Clipboard.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_linux_X11_Windowing.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_mac_FileChooser.mm"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_mac_MainMenu.mm"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_mac_MouseCursor.mm"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_mac_NSViewComponentPeer.mm"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_mac_Windowing.mm"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_MultiTouchMapper.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_win32_DragAndDrop.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_win32_FileChooser.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_win32_Windowing.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_MarkerList.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_MarkerList.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativePoint.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativePoint.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativePointPath.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativePointPath.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativeRectangle.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativeRectangle.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_PropertyComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_PropertyComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_PropertyPanel.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_PropertyPanel.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_TextPropertyComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_TextPropertyComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ComboBox.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ComboBox.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ImageComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ImageComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_Label.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_Label.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ListBox.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ListBox.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ProgressBar.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ProgressBar.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_Slider.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_Slider.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_TableListBox.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_TableListBox.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_TextEditor.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_TextEditor.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_Toolbar.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_Toolbar.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ToolbarItemFactory.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_TreeView.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_TreeView.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_AlertWindow.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_AlertWindow.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_CallOutBox.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_CallOutBox.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_ComponentPeer.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_ComponentPeer.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_DialogWindow.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_DialogWindow.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_DocumentWindow.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_DocumentWindow.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_NativeMessageBox.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_ResizableWindow.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_ResizableWindow.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_TooltipWindow.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_TooltipWindow.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_TopLevelWindow.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_TopLevelWindow.h"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/juce_gui_basics.cpp"
    "../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/juce_gui_basics.mm"
    "../../../../../../../../JUCE-dev/modules/juce_gui_basics/juce_gui_basics.h"
    "../../../JuceLibraryCode/AppConfig.h"
    "../../../JuceLibraryCode/include_juce_core.cpp"
    "../../../JuceLibraryCode/include_juce_data_structures.cpp"
    "../../../JuceLibraryCode/include_juce_events.cpp"
    "../../../JuceLibraryCode/include_juce_graphics.cpp"
    "../../../JuceLibraryCode/include_juce_gui_basics.cpp"
    "../../../JuceLibraryCode/JuceHeader.h"
)

set_source_files_properties("../../../Source/LookAndFeelCustomisationTutorial_01.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_AbstractFifo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_AbstractFifo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_Array.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_ArrayAllocationBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_ArrayBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_ArrayBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_DynamicObject.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_DynamicObject.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_ElementComparator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_HashMap.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_HashMap_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_LinkedListPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_ListenerList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_NamedValueSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_NamedValueSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_OwnedArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_OwnedArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_PropertySet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_PropertySet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_ReferenceCountedArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_ReferenceCountedArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_ScopedValueSetter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_SortedSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_SparseSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_SparseSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_Variant.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/containers/juce_Variant.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_DirectoryIterator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_DirectoryIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_File.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_File.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_FileFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_FileFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_FileInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_FileInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_FileOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_FileOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_FileSearchPath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_FileSearchPath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_MemoryMappedFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_TemporaryFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_TemporaryFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_WildcardFileFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/files/juce_WildcardFileFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/javascript/juce_Javascript.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/javascript/juce_Javascript.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/javascript/juce_JSON.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/javascript/juce_JSON.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/logging/juce_FileLogger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/logging/juce_FileLogger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/logging/juce_Logger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/logging/juce_Logger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_BigInteger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_BigInteger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_Expression.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_Expression.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_MathsFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_NormalisableRange.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_Random.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_Random.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_Range.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/maths/juce_StatisticsAccumulator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_Atomic.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_ByteOrder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_ContainerDeletePolicy.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_HeapBlock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_HeavyweightLeakedObjectDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_LeakedObjectDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_Memory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_MemoryBlock.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_MemoryBlock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_OptionalScopedPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_ReferenceCountedObject.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_ScopedPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_SharedResourcePointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_Singleton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/memory/juce_WeakReference.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_ConsoleApplication.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_ConsoleApplication.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_Result.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_Result.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_RuntimePermissions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_RuntimePermissions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_StdFunctionCompat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_StdFunctionCompat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_Uuid.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_Uuid.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/misc/juce_WindowsRegistry.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/java/README.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_android_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_android_JNIHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_android_JNIHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_android_Misc.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_android_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_android_RuntimePermissions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_android_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_android_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_BasicNativeHeaders.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_curl_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_linux_CommonFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_linux_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_linux_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_linux_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_linux_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_mac_ClangBugWorkaround.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_mac_Files.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_mac_Network.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_mac_Strings.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_mac_SystemStats.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_mac_Threads.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_osx_ObjCHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_posix_IPAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_posix_NamedPipe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_posix_SharedCode.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_win32_ComSmartPtr.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_win32_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_win32_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_win32_Registry.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_win32_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/native/juce_win32_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_IPAddress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_IPAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_MACAddress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_MACAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_NamedPipe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_NamedPipe.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_Socket.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_Socket.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_URL.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_URL.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_WebInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/network/juce_WebInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_BufferedInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_BufferedInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_FileInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_FileInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_InputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_InputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_InputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_MemoryInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_MemoryInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_MemoryOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_MemoryOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_OutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_OutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_SubregionStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_SubregionStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_URLInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/streams/juce_URLInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/system/juce_CompilerSupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/system/juce_PlatformDefs.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/system/juce_StandardHeader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/system/juce_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/system/juce_SystemStats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/system/juce_TargetPlatform.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_Base64.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_Base64.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_CharacterFunctions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_CharacterFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_CharPointer_ASCII.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_CharPointer_UTF8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_CharPointer_UTF16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_CharPointer_UTF32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_Identifier.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_Identifier.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_LocalisedStrings.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_LocalisedStrings.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_NewLine.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_String.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_String.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_StringArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_StringArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_StringPairArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_StringPairArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_StringPool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_StringPool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_StringRef.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_TextDiff.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/text/juce_TextDiff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ChildProcess.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ChildProcess.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_CriticalSection.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_DynamicLibrary.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_HighResolutionTimer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_HighResolutionTimer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_InterProcessLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_Process.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ReadWriteLock.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ReadWriteLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ScopedLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ScopedReadLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ScopedWriteLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_SpinLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_Thread.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_Thread.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ThreadLocalValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ThreadPool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_ThreadPool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_TimeSliceThread.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_TimeSliceThread.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/threads/juce_WaitableEvent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/time/juce_PerformanceCounter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/time/juce_PerformanceCounter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/time/juce_RelativeTime.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/time/juce_RelativeTime.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/time/juce_Time.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/time/juce_Time.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/unit_tests/juce_UnitTest.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/unit_tests/juce_UnitTest.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/unit_tests/juce_UnitTestCategories.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/xml/juce_XmlDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/xml/juce_XmlDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/xml/juce_XmlElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/xml/juce_XmlElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/adler32.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/compress.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/crc32.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/crc32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/deflate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/deflate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/infback.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/inffast.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/inffast.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/inffixed.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/inflate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/inflate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/inftrees.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/inftrees.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/trees.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/trees.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/uncompr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/zconf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/zconf.in.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/zlib.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/zutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/zlib/zutil.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/juce_GZIPCompressorOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/juce_GZIPCompressorOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/juce_GZIPDecompressorInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/juce_GZIPDecompressorInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/juce_ZipFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/zip/juce_ZipFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/juce_core.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_core/juce_core.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../../JUCE-dev/modules/juce_core/juce_core.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/app_properties/juce_ApplicationProperties.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/app_properties/juce_ApplicationProperties.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/app_properties/juce_PropertiesFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/app_properties/juce_PropertiesFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/undomanager/juce_UndoableAction.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/undomanager/juce_UndoManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/undomanager/juce_UndoManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_CachedValue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_CachedValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_Value.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_Value.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_ValueTree.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_ValueTree.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_ValueWithDefault.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/values/juce_ValueWithDefault.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/juce_data_structures.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_data_structures/juce_data_structures.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../../JUCE-dev/modules/juce_data_structures/juce_data_structures.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/broadcasters/juce_ActionBroadcaster.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/broadcasters/juce_ActionBroadcaster.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/broadcasters/juce_ActionListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/broadcasters/juce_AsyncUpdater.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/broadcasters/juce_AsyncUpdater.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/broadcasters/juce_ChangeBroadcaster.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/broadcasters/juce_ChangeBroadcaster.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/broadcasters/juce_ChangeListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/interprocess/juce_ConnectedChildProcess.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/interprocess/juce_ConnectedChildProcess.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/interprocess/juce_InterprocessConnection.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/interprocess/juce_InterprocessConnection.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/interprocess/juce_InterprocessConnectionServer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/interprocess/juce_InterprocessConnectionServer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/interprocess/juce_NetworkServiceDiscovery.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/interprocess/juce_NetworkServiceDiscovery.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_ApplicationBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_ApplicationBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_CallbackMessage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_DeletedAtShutdown.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_DeletedAtShutdown.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_Initialisation.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_Message.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_MessageListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_MessageListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_MessageManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_MessageManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_MountedVolumeListChangeDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/messages/juce_NotificationType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_android_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_ios_MessageManager.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_linux_EventLoop.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_linux_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_mac_MessageManager.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_osx_MessageQueue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_win32_HiddenMessageWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_win32_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_win32_WinRTWrapper.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/native/juce_win32_WinRTWrapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/timers/juce_MultiTimer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/timers/juce_MultiTimer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/timers/juce_Timer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/timers/juce_Timer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/juce_events.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_events/juce_events.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../../JUCE-dev/modules/juce_events/juce_events.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/colour/juce_Colour.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/colour/juce_Colour.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/colour/juce_ColourGradient.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/colour/juce_ColourGradient.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/colour/juce_Colours.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/colour/juce_Colours.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/colour/juce_FillType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/colour/juce_FillType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/colour/juce_PixelFormats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/contexts/juce_GraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/contexts/juce_GraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/contexts/juce_LowLevelGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/effects/juce_DropShadowEffect.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/effects/juce_DropShadowEffect.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/effects/juce_GlowEffect.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/effects/juce_GlowEffect.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/effects/juce_ImageEffectFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_AttributedString.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_AttributedString.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_CustomTypeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_CustomTypeface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_Font.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_Font.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_GlyphArrangement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_GlyphArrangement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_TextLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_TextLayout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_Typeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/fonts/juce_Typeface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_AffineTransform.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_AffineTransform.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_BorderSize.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_EdgeTable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_EdgeTable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_Line.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_Parallelogram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_Path.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_Path.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_PathIterator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_PathIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_PathStrokeType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_PathStrokeType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_Point.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_Rectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/geometry/juce_RectangleList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/cderror.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/changes to libjpeg for JUCE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcapimin.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcapistd.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jccoefct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jccolor.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcdctmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jchuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jchuff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcinit.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcmainct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcmarker.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcmaster.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcomapi.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jconfig.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcparam.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcphuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcprepct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jcsample.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jctrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdapimin.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdapistd.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdatasrc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdcoefct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdcolor.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jddctmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdhuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdhuff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdinput.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdmainct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdmarker.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdmaster.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdmerge.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdphuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdpostct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdsample.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jdtrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jerror.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jerror.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jfdctflt.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jfdctfst.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jfdctint.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jidctflt.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jidctfst.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jidctint.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jidctred.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jinclude.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jmemmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jmemnobs.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jmemsys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jmorecfg.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jpegint.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jpeglib.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jquant1.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jquant2.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jutils.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/jversion.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/transupp.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/jpglib/transupp.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/libpng_readme.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/png.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/png.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngconf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngerror.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngget.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pnginfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngmem.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngpread.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngpriv.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngread.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngrio.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngrtran.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngrutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngset.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngstruct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngtrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngwio.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngwrite.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngwtran.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/pnglib/pngwutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/juce_GIFLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/juce_JPEGLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/image_formats/juce_PNGLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/images/juce_Image.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/images/juce_Image.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/images/juce_ImageCache.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/images/juce_ImageCache.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/images/juce_ImageConvolutionKernel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/images/juce_ImageConvolutionKernel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/images/juce_ImageFileFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/images/juce_ImageFileFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_android_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_android_GraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_android_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_freetype_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_linux_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_linux_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_mac_CoreGraphicsHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_mac_Fonts.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_mac_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_RenderingHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_win32_DirectWriteTypeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_win32_DirectWriteTypeLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_win32_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/native/juce_win32_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/placement/juce_Justification.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/placement/juce_RectanglePlacement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/placement/juce_RectanglePlacement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/juce_graphics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_graphics/juce_graphics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../../JUCE-dev/modules/juce_graphics/juce_graphics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/application/juce_Application.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/application/juce_Application.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ArrowButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ArrowButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_Button.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_Button.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_DrawableButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_DrawableButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_HyperlinkButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_HyperlinkButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ImageButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ImageButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ShapeButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ShapeButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_TextButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_TextButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ToggleButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ToggleButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ToolbarButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/buttons/juce_ToolbarButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/commands/juce_ApplicationCommandID.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/components/juce_CachedComponentImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/components/juce_Component.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/components/juce_Component.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/components/juce_ComponentListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/components/juce_ComponentListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/components/juce_ModalComponentManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/components/juce_ModalComponentManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/desktop/juce_Desktop.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/desktop/juce_Desktop.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/desktop/juce_Displays.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/desktop/juce_Displays.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_Drawable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_Drawable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableComposite.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableComposite.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableImage.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawablePath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawablePath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableRectangle.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableRectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableShape.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableShape.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableText.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_DrawableText.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/drawables/juce_SVGParser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_ContentSharer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileBrowserListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileChooser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FilePreviewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_CaretComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_CaretComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_KeyListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_KeyListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_KeyPress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_KeyPress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_ModifierKeys.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_ModifierKeys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_SystemClipboard.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_TextEditorKeyMapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/keyboard/juce_TextInputTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_AnimatedPosition.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_AnimatedPositionBehaviours.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ComponentAnimator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ComponentAnimator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ComponentBuilder.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ComponentBuilder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ConcertinaPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ConcertinaPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_FlexBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_FlexBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_FlexItem.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_Grid.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_Grid.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_GridItem.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_GridItem.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_GroupComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_GroupComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ScrollBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_ScrollBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_SidePanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_SidePanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_TabbedButtonBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_TabbedButtonBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_TabbedComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_TabbedComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_Viewport.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/layout/juce_Viewport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/menus/juce_MenuBarComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/menus/juce_MenuBarComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/menus/juce_MenuBarModel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/menus/juce_MenuBarModel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/menus/juce_PopupMenu.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/menus/juce_PopupMenu.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/misc/juce_BubbleComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/misc/juce_BubbleComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/misc/juce_DropShadower.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/misc/juce_DropShadower.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/misc/juce_JUCESplashScreen.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/misc/juce_JUCESplashScreen.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_ComponentDragger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_ComponentDragger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_DragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_FileDragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_LassoComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseCursor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseCursor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseEvent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseEvent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_MouseListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_SelectedItemSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_TextDragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/mouse/juce_TooltipClient.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_android_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_android_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_android_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_common_MimeTypes.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_ios_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_ios_FileChooser.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_ios_UIViewComponentPeer.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_ios_Windowing.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_linux_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_linux_X11.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_linux_X11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_linux_X11_Clipboard.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_linux_X11_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_mac_FileChooser.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_mac_MainMenu.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_mac_MouseCursor.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_mac_NSViewComponentPeer.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_mac_Windowing.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_MultiTouchMapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_win32_DragAndDrop.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_win32_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/native/juce_win32_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_MarkerList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_MarkerList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativePoint.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativePoint.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativePointPath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativePointPath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativeRectangle.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/positioning/juce_RelativeRectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_PropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_PropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_PropertyPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_PropertyPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_TextPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/properties/juce_TextPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ComboBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ComboBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ImageComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ImageComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_Label.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_Label.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ListBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ListBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ProgressBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ProgressBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_Slider.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_Slider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_TableListBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_TableListBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_TextEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_TextEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_Toolbar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_Toolbar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ToolbarItemFactory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_TreeView.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/widgets/juce_TreeView.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_AlertWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_AlertWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_CallOutBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_CallOutBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_ComponentPeer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_ComponentPeer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_DialogWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_DialogWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_DocumentWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_DocumentWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_NativeMessageBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_ResizableWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_ResizableWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_TooltipWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_TooltipWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_TopLevelWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/windows/juce_TopLevelWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/juce_gui_basics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../CI/macOS/../../../JUCE-dev/modules/juce_gui_basics/juce_gui_basics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../../../../JUCE-dev/modules/juce_gui_basics/juce_gui_basics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../JuceLibraryCode/AppConfig.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../JuceLibraryCode/JuceHeader.h" PROPERTIES HEADER_FILE_ONLY TRUE)

find_library(log "log")
find_library(android "android")
find_library(glesv2 "GLESv2")
find_library(egl "EGL")

target_link_libraries( ${BINARY_NAME}

    ${log}
    ${android}
    ${glesv2}
    ${egl}
    "cpufeatures"
)
