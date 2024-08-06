#!/bin/bash

source "$TEST_TOP/common" || exit

check_prereq btrfs

setup_root_helper

# redefine the one provided by common
check_image() {
	local image

	image=$1
	run_check cp "$image" "$image".scratch
	run_mayfail "$TOP/btrfs" rescue zero-log "$image".scratch
	rm -- "$image".scratch
}

check_all_images "$TEST_TOP/fuzz-tests/images"

exit 0
