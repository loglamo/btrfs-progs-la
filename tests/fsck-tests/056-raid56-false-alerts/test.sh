#!/bin/bash
#
# Make sure "btrfs check --check-data-csum" won't report false alerts on RAID56
# data.
#

source "$TEST_TOP/common" || exit

check_prereq btrfs
check_prereq mkfs.btrfs
check_global_prereq losetup

setup_root_helper

setup_loopdevs 3
prepare_loopdevs
dev1=${loopdevs[1]}
TEST_DEV=$dev1

run_check $SUDO_HELPER "$TOP/mkfs.btrfs" -f -m raid1 -d raid5 "${loopdevs[@]}"
run_check_mount_test_dev

run_check $SUDO_HELPER dd if=/dev/urandom of="$TEST_MNT/file" bs=16K count=1 \
	status=noxfer > /dev/null 2>&1

run_check_umount_test_dev

# Check data csum should not report false alerts
run_check $SUDO_HELPER "$TOP/btrfs" check --check-data-csum "$dev1"

cleanup_loopdevs
