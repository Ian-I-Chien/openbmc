# Copyright 2020-present Facebook. All Rights Reserved.
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

FILESEXTRAPATHS:prepend := "${THISDIR}/patches_6.0:"

SRC_URI += "file://1001-ARM-dts-aspeed-Add-Facebook-FBDarwin-AST2600-BMC.patch \
            file://1002-misc-eeprom_93xx46-Add-93C76-93C86-support.patch \
            file://1003-ARM-dts-aspeed-fbdarwin-Enable-spi1-devices.patch \
            file://1004-gpiolib-of-Respect-High-CS-in-spi-gpio.patch \
           "
