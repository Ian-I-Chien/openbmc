# Copyright 2015-present Facebook. All Rights Reserved.
#
# This program file is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; version 2 of the License.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
# for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program in a file named COPYING; if not, write to the
# Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor,
# Boston, MA 02110-1301 USA

SUMMARY = "GPIO Sensor Monitoring Daemon"
DESCRIPTION = "Daemon for monitoring the gpio sensors"
SECTION = "base"
PR = "r1"
LICENSE = "GPL-2.0-or-later"
LIC_FILES_CHKSUM = "file://gpiod.c;beginline=4;endline=16;md5=b395943ba8a0717a83e62ca123a8d238"

S="${WORKDIR}/sources"
UNPACKDIR="${S}"

LOCAL_URI = " \
    file://meson.build \
    file://gpiod.c \
    file://setup-gpiod.sh \
    file://run-gpiod.sh \
    "

inherit meson pkgconfig
inherit legacy-packages

pkgdir = "gpiod"

DEPENDS += "update-rc.d-native libbic libfby35-gpio libpal libfby35-common libkv libfruid"

do_install:append() {
  install -d ${D}${sysconfdir}/init.d
  install -d ${D}${sysconfdir}/rcS.d
  install -d ${D}${sysconfdir}/sv
  install -d ${D}${sysconfdir}/sv/gpiod
  install -d ${D}${sysconfdir}/gpiod
  install -m 755 ${UNPACKDIR}/setup-gpiod.sh ${D}${sysconfdir}/init.d/setup-gpiod.sh
  install -m 755 ${UNPACKDIR}/run-gpiod.sh ${D}${sysconfdir}/sv/gpiod/run
  update-rc.d -r ${D} setup-gpiod.sh start 91 5 .
}
