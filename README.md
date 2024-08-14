### ``btrfs-progs-la'' creates multiple partitions with their super blocks and filesystem trees at mkfs.btrfs on a single disk.

#### Required tools/libraries to build:

1. e2fslibs-dev
2. libblkid-dev
3. liblzo2-dev
4. libzstd-dev
5. zlib 

#### Steps to build and install from src:

1. Make the configuration: $./configure
2. Disable btrfs-convert and documentation if there is any error caused by them: $./configure --disable-convert
3. Start making: $make -j#
4. Install: $sudo make install 
5. Make a fs on a device: $sudo mkfs.btrfs /dev/nvme#   
