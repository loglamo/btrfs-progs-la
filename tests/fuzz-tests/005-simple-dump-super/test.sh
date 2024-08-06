#!/bin/bash

source "$TEST_TOP/common" || exit

check_prereq btrfs

setup_root_helper

# redefine the one provided by common
check_image() {
	local image

	image=$1
	run_mayfail "$TOP/btrfs" inspect-internal dump-super "$image"
	run_mayfail "$TOP/btrfs" inspect-internal dump-super -Ffa "$image"
}

check_all_images "$TEST_TOP/fuzz-tests/images"

exit 0
