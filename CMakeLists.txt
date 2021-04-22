
set(CMAKE_BUILD_TYPE Debug)

project (testing)

file(GLOB_RECURSE testing_SRC

	"*.h"
	"*.cpp"
)

add_executable(testing ${testing_SRC})