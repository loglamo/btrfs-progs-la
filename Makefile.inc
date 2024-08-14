# Variables set during configure phase:
# * build environment, paths
# * features (eg. convert, documentation)
export

CC = gcc
LN_S = ln -s
AR = ar
RM = /usr/bin/rm
RMDIR = /usr/bin/rmdir
INSTALL = /usr/bin/install -c
DISABLE_DOCUMENTATION = 0
DISABLE_BTRFSCONVERT = 0
BUILD_PROGRAMS = 1
BUILD_SHARED_LIBRARIES = 1
BUILD_STATIC_LIBRARIES = 1
BTRFSCONVERT_EXT2 = 1
BTRFSCONVERT_REISERFS = 0
COMPRESSION_LZO = 1
COMPRESSION_ZSTD = 1
PYTHON_BINDINGS = 1
PYTHON = /usr/bin/python3
PYTHON_CFLAGS = -I/usr/include/python3.10 -I/usr/include/x86_64-linux-gnu/python3.10
CRYPTOPROVIDER_BUILTIN = 1
CRYPTO_CFLAGS =     

HAVE_CFLAG_msse2 = 1
HAVE_CFLAG_msse41 = 1
HAVE_CFLAG_mavx2 = 1
HAVE_CFLAG_msha = 1
TARGET_CPU = x86_64
HAVE_GLIBC = 1

SUBST_CFLAGS = -g -O2 -Wall -D_FORTIFY_SOURCE=2
SUBST_LDFLAGS = 

LIBBTRFS_MAJOR=0
LIBBTRFS_MINOR=1
LIBBTRFS_PATCHLEVEL=3
LIBS_BASE = -luuid -lblkid -ludev -L. -pthread
LIBS_COMP = -L/usr/local/lib -lz -llzo2 -lzstd
LIBS_PYTHON = 
LIBS_CRYPTO =     
STATIC_LIBS_BASE = -luuid -lblkid -L. -pthread
STATIC_LIBS_COMP = -L/usr/local/lib -lz -llzo2 -lzstd

prefix ?= /usr/local
exec_prefix = ${prefix}
bindir = ${exec_prefix}/bin
libdir ?= ${exec_prefix}/lib
incdir = ${prefix}/include
udevdir = /lib/udev
udevruledir = ${udevdir}/rules.d
pkgconfigdir = ${libdir}/pkgconfig

# external libs required by various binaries; for btrfs-foo,
# specify btrfs_foo_libs = <list of libs>; see $($(subst...)) rules in Makefile
btrfs_convert_libs = -lext2fs -lcom_err 

MAKEFILE_INC_INCLUDED = yes
