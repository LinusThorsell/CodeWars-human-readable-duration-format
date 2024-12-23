init:
	cmake -B build

watch_test:
	find . -type f | entr -r sh -c 'make build_test'

test:
	build/test_solution

run:
	build/main

build_test:
	cmake --build build && build/test_solution

build_run:
	cmake --build build && build/main

build_test_and_run: build_test run
