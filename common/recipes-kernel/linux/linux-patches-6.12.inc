FILESEXTRAPATHS:prepend := "${THISDIR}/6.12:"

#
# Patches to be upstreamed soon.
#
SRC_URI:append = " \
    file://0001-ARM-dts-aspeed-Remove-eMMC-from-ast2600-facebook-net.patch \
    file://0002-ARM-dts-aspeed-elbert-Enable-eMMC-device.patch \
    file://0003-ARM-dts-aspeed-fuji-Enable-eMMC-device.patch \
    file://0004-ARM-dts-aspeed-Add-Facebook-FBDarwin-AST2600-BMC.patch \
    file://0005-ARM-dts-aspeed-elbert-Enable-mdio0-devices.patch \
    file://0006-ARM-dts-aspeed-Add-Facebook-fblite-r1-BMC.patch \
    file://0007-ARM-dts-aspeed-Expand-data0-partition-in-facebook-bm.patch \
"

#
# JTAG patches.
# Used by multiple OpenBMC platforms for firmware upgrade.
#
SRC_URI:append = " \
    file://0100-drivers-jtag-Add-JTAG-core-driver.patch \
    file://0101-dt-binding-jtag-Aspeed-2400-and-2500-series.patch \
    file://0102-Add-Aspeed-SoC-24xx-and-25xx-families-JTAG-master-dr.patch \
    file://0103-jtag-aspeed-support-sysfs-interface.patch \
    file://0104-jtag-support-driver-specific-ioctl-commands.patch \
    file://0105-jtag-aspeed-support-JTAG_RUN_CYCLE-ioctl-command.patch \
    file://0106-jtag-aspeed-add-AST2600-support.patch \
    file://0107-Documentation-jtag-Add-ABI-documentation.patch \
    file://0108-Documentation-jtag-Add-JTAG-core-driver-ioctl-number.patch \
    file://0109-drivers-jtag-Add-JTAG-core-driver-Maintainers.patch \
    file://0110-fixup-jtag-patch-series.patch \
    file://0111-ARM-dts-aspeed-g6-add-jtag-controllers.patch \
    file://0112-ARM-dts-aspeed-g5-add-jtag-controller.patch \
"

#
# SPI patches.
# "0150-spi-aspeed-add-shutdown-path..." is required for all the AST25XX
# platforms.
# "0151-spi-add-user-mode..." is used by several FBOSS platforms to access
# flashes using spidev/flashrom.
#
SRC_URI:append = " \
    file://0130-spi-aspeed-add-shutdown-path-for-AST25XX-SPI-control.patch \
    file://0131-spi-add-user-mode-aspeed-spi-driver.patch \
"

#
# I2C patches used by multiple OpenBMC platforms.
#
SRC_URI:append = " \
    file://0150-aspeed-i2c-add-clock-duty-cycle-property.patch \
    file://0151-dt-bindings-aspeed-i2c-add-properties-for-setting-i2.patch \
    file://0152-i2c-aspeed-update-ast2400-timing-settings.patch \
    file://0153-i2c-add-a-slave-backend-to-receive-and-queue-message.patch \
    file://0154-i2c-aspeed-add-i2c-slave-inactive-timeout-support.patch \
    file://0155-Add-ASPEED-AST2600-I2Cv2-controller-driver.patch \
"

#
# I3C patches used by OpenBMC platforms.
#
SRC_URI:append = " \
    file://0180-ARM-dts-aspeed-g6-Add-AST2600-I3Cs.patch \
    file://0181-dt-bindings-i3c-hub-Add-Renesas-RG3MxxB12A1-I3C-HUB.patch \
    file://0182-i3c-i3c-hub-Add-Renesas-RG3MxxB12A1-I3C-HUB-driver.patch \
    file://0183-mctp-i3c-fix-MCTP-I3C-driver-multi-thread-issue.patch \
"

#
# Misc ASPEED controller drivers.
#
SRC_URI:append = " \
    file://0300-aspeed-g6.dtsi-update-for-PWM-and-TACH-driver.patch \
    file://0301-ARM-dts-aspeed-g6-add-pcc-config-in-aspeed-g6.dtsi.patch \
    file://0302-drivers-watchdog-ast2600-support-bootstatus.patch \
    file://0303-dmaengine-aspeed-Add-AST2600-UART-DMA-driver.patch \
    file://0304-serial-8250-Add-AST2600-UART-driver.patch \
    file://0305-drivers-misc-Add-Aspeed-OTP-control-register.patch \
    file://0306-soc-aspeed-Add-Post-Code-Control.patch \
"

#
# NCSI patches used by multiple OpenBMC platforms.
#
SRC_URI:append = " \
    file://0500-NCSI-Add-propety-no-channel-monitor-and-start-redo-p.patch \
    file://0501-net-ncsi-specify-maximum-package-to-probe.patch \
    file://0502-Revert-net-ncsi-change-from-ndo_set_mac_address-to-d.patch \
"

#
# hwmon/sensor drivers
#
SRC_URI:append = " \
    file://0600-hwmon-max31790-support-to-config-PWM-as-TACH.patch \
    file://0601-hwmon-max31790-add-fanN_enable-for-all-fans.patch \
    file://0602-hwmon-pmbus-Add-xdpe132g5c-driver.patch \
    file://0603-hwmon-ina233-Add-ina233-driver.patch \
    file://0604-hwmon-Driver-for-Nuvoton-NCT7363Y.patch \
    file://0605-hwmon-new-driver-for-ISL28022-power-monitor.patch \
    file://0606-hwmon-pmbus-Add-SQ52205-driver.patch \
    file://0607-hwmon-Add-net_brcm-driver.patch \
    file://0608-Kernel6v5-Support-apml-driver.patch \
"

#
# FBOSS-specific patches
#
SRC_URI:append = " \
    file://0800-ARM-dts-aspeed-Enable-jtag1-in-fblite-r1-dts.patch \
"

#
# Hacks and workarounds
#
SRC_URI:append = " \
    file://0900-Revert-usb-gadget-f_ecm-Add-suspend-resume-and-remot.patch \
    file://0901-jffs2-kill-garbage-collect-thread-when-filesystem-is.patch \
    file://0902-jffs2-suppress-jffs2-messages-when-reading-inode.patch \
    file://0903-mmc-sdhci-of-aspeed-add-skip_probe-module-parameter.patch \
"
