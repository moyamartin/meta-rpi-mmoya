SUMMARY = "Simple script that runs after startup that disables upgrade_available variable in u-boot"
DESCRIPTION = "Simple script that runs after startup that disables upgrade_available variable in u-boot"
SECTION = "swupdate"
LICENSE="CLOSED"

inherit systemd

DEPENDS += "swupdate"

SRC_URI = " \
    file://finishupgrade \
    file://finishupgrade.service \
"
PV = "1.0+git${SRCPV}"

FILES:${PN} = " \
    ${libdir}/finishupgrade/* \
    ${systemd_system_unitdir}/finishupgrade.service \
"

do_install () {
    install -d ${D}${systemd_unitdir}/system
    install -d ${D}${libdir}/finishupgrade
    install -m 644 ${WORKDIR}/finishupgrade.service ${D}${systemd_system_unitdir}
    sed -i 's#@LIBDIR@#${libdir}#' ${D}${systemd_system_unitdir}/finishupgrade.service
    install -m 755 ${WORKDIR}/finishupgrade ${D}${libdir}/finishupgrade
}

SYSTEMD_PACKAGES = "${PN}"
SYSTEMD_SERVICE:${PN} = "finishupgrade.service"
