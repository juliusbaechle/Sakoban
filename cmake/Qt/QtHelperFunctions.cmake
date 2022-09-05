# Description: Parse a list of Qt Module names {QTMODULES} to a list of Qt Lib names m{RESULT} for linking to a target
# Param ${QTMODULES}: List of Qt Modules e.g. Widgets Core ...
# Return ${RESULT_LIBS}: List of Qt Libs e.g. Qt5::Widgets Qt5::Core ...
# Example usage:
# set(Qt_Libs)
# createQtLibNames(QTMODULES ${Qt_Modules} RESULTLIBS Qt_Libs)
# target_link_libraries(${TARGET_NAME_5600} PUBLIC ${Qt_Libs})
function(createQtLibNames)
  set(options)
  set(args RESULTLIBS)
  set(list_args QTMODULES)
  cmake_parse_arguments(
    PARSE_ARGV 0
    createQtLibNames
    "${options}"
    "${args}"
    "${list_args}"
  )

  # create List of Qt lib names
  set(__QT_LIB_NAMES__)
  foreach(module IN LISTS createQtLibNames_QTMODULES)
    set(__lib__ ${module})
    # prepend "Qt5::"
    string(PREPEND __lib__ Qt5::)
    # append result to lib names array
    list(APPEND __QT_LIB_NAMES__ ${__lib__})
  endforeach()

  # set result (lib names) in reference {RESULT} in parent scope
  set(${createQtLibNames_RESULTLIBS} ${__QT_LIB_NAMES__} PARENT_SCOPE)
endfunction()
