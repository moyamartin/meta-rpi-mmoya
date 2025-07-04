HOMEPAGE = "http://www.denx.de/wiki/U-Boot/WebHome"
DESCRIPTION = "U-Boot, a boot loader for Embedded boards based on PowerPC, \
ARM, MIPS and several other processors, which can be installed in a boot \
ROM and used to initialize and test the hardware or to download and run \
application code."
SECTION = "bootloaders"
DEPENDS += "flex-native bison-native python3-setuptools-native"

LICENSE = "GPL-2.0-or-later"
LIC_FILES_CHKSUM = "file://Licenses/README;md5=2ca5f2c35c8cc335f0a19756634782f1"
PE = "1"

# We use the revision in order to avoid having to fetch it from the
# repo during parse
SRCREV = "3f772959501c99fbe5aa0b22a36efe3478d1ae1c"

SRC_URI = "git://source.denx.de/u-boot/u-boot.git;protocol=https;branch=master \
           file://CVE-2024-57254.patch \
           file://CVE-2024-57255.patch \
           file://CVE-2024-57256.patch \
           file://CVE-2024-57257.patch \
           file://CVE-2024-57258-1.patch \
           file://CVE-2024-57258-2.patch \
           file://CVE-2024-57258-3.patch \
           file://CVE-2024-57259.patch \
           file://0001-add-boot-counter-to-rpi-5.patch \
           file://0002-set-custom-env-variables-to-rpi.env.patch \
           file://0003-enable-bootcount-write-to-any-fs-type.patch \
"

S = "${WORKDIR}/git"
B = "${WORKDIR}/build"

inherit pkgconfig

do_configure[cleandirs] = "${B}"
