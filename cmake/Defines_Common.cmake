##### Common Defines #####

# Windows Defines
if(WIN32)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) # only needed if building a DLL somewhere
  add_compile_definitions(
    _WINDOWS
    UNICODE
    _UNICODE
  )
endif()

# Linux Defines
if(UNIX)
  add_compile_definitions(
    UNICODE
    _UNICODE
  )
endif()

# Debug Defines
if(CMAKE_BUILD_TYPE MATCHES Debug)
  add_compile_definitions(
    _DEBUG
  )
endif()
