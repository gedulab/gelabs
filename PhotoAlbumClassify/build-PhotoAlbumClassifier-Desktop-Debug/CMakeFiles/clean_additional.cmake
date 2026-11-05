# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/PhotoAlbumClassifier_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/PhotoAlbumClassifier_autogen.dir/ParseCache.txt"
  "PhotoAlbumClassifier_autogen"
  )
endif()
