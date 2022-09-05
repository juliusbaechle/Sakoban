set(LIBS_ALL)
# Common Libs
set(LIBS_COMMON
)

# Windows specific Libs
if (WIN32)
  set(LIBS_WIN
    #insert here
  )
endif()

# Linux specific Libs
if (UNIX)
  set(LIBS_LINUX
    #insert here
  )
endif()

##### Qt #####
include(Qt/QtHelperFunctions)
set(LIBS_QT)
createQtLibNames(QTMODULES ${Qt_Modules} RESULTLIBS LIBS_QT)

list(APPEND LIBS_ALL
  ${LIBS_COMMON}
  ${LIBS_WIN}
  ${LIBS_LINUX}
  ${LIBS_QT}
)

