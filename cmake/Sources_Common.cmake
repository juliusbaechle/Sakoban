set(SOURCES_LEVELS  
  ${PROJECT_SOURCE_DIR}/src/levels/Level1.h
  ${PROJECT_SOURCE_DIR}/src/levels/Level2.h
  ${PROJECT_SOURCE_DIR}/src/levels/Level3.h
  ${PROJECT_SOURCE_DIR}/src/levels/Level4.h
  ${PROJECT_SOURCE_DIR}/src/levels/Level5.h
  ${PROJECT_SOURCE_DIR}/src/levels/Level6.h
  ${PROJECT_SOURCE_DIR}/src/levels/Level7.h
  ${PROJECT_SOURCE_DIR}/src/levels/Level8.h
  ${PROJECT_SOURCE_DIR}/src/levels/Level9.h
  ${PROJECT_SOURCE_DIR}/src/levels/Level10.h
  ${PROJECT_SOURCE_DIR}/src/levels/Level11.h
  ${PROJECT_SOURCE_DIR}/src/levels/Level12.h
  ${PROJECT_SOURCE_DIR}/src/levels/Level13.h
  ${PROJECT_SOURCE_DIR}/src/levels/Level14.h
  ${PROJECT_SOURCE_DIR}/src/levels/Level15.h
  ${PROJECT_SOURCE_DIR}/src/levels/HardCodedLevelRepository.cpp
  ${PROJECT_SOURCE_DIR}/src/levels/HardCodedLevelRepository.h
)
source_group("Levels" FILES ${SOURCES_LEVELS})

set(SOURCES_SAKOBAN
  ${PROJECT_SOURCE_DIR}/src/main.cpp
  ${PROJECT_SOURCE_DIR}/src/Playground.h
  ${PROJECT_SOURCE_DIR}/src/Sakoban.h
  ${PROJECT_SOURCE_DIR}/src/Sakoban.cpp
  ${PROJECT_SOURCE_DIR}/src/SakobanUI.h
  ${PROJECT_SOURCE_DIR}/src/SakobanUI.cpp
  ${PROJECT_SOURCE_DIR}/src/SakobanUI.ui
  ${PROJECT_SOURCE_DIR}/src/ILevelRepository.h
)
source_group("Sakoban" FILES ${SOURCES_SAKOBAN})

set(SOURCES_COMMON
  ${SOURCES_SAKOBAN}
  ${SOURCES_LEVELS}
)
