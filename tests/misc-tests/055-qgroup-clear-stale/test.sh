#!/bin/bash
#
# Clear stale qgroups

source "$TEST_TOP/common" || exit

check_prereq mkfs.btrfs
check_prereq btrfs

setup_root_helper
prepare_test_dev

run_check_mkfs_test_dev
run_check_mount_test_dev
run_check $SUDO_HELPER "$TOP/btrfs" quota enable "$TEST_MNT"
run_check $SUDO_HELPER "$TOP/btrfs" subvolume create "$TEST_MNT/subv1"
run_check $SUDO_HELPER "$TOP/btrfs" qgroup show "$TEST_MNT"
rootid=$(run_check_stdout "$TOP/btrfs" inspect-internal rootid "$TEST_MNT/subv1")
run_check $SUDO_HELPER "$TOP/btrfs" subvolume delete "$TEST_MNT/subv1"
run_check $SUDO_HELPER "$TOP/btrfs" qgroup show "$TEST_MNT"
# Subvolume deletion could be slow and won't let the qgroup to be cleaned,
# shown as '<under deletion>'.
if ! run_mayfail $SUDO_HELPER "$TOP/btrfs" qgroup clear-stale "$TEST_MNT"; then
	run_check $SUDO_HELPER "$TOP/btrfs" subvolume sync "$TEST_MNT" "$rootid"
	run_check $SUDO_HELPER "$TOP/btrfs" qgroup show "$TEST_MNT"
	# After cleaning the subvolume it must pass
	run_check $SUDO_HELPER "$TOP/btrfs" qgroup clear-stale "$TEST_MNT"
fi
list=$(run_check_stdout $SUDO_HELPER "$TOP/btrfs" qgroup show "$TEST_MNT")
if echo "$list" | grep -q "0/$rootid"; then
	_fail "stale qgroups not deleted"
fi
if echo "$list" | grep -q "<stale>"; then
	_fail "stale qgroups not deleted"
fi
run_check_umount_test_dev
