FILESEXTRAPATHS:prepend := "${THISDIR}/flashrom:"

SRC_URI:append = " \
    file://0001-flashrom-GD25LQ256D.patch \
    file://0002-flashrom-remove-duplicate-N25Q256__1E.patch \
    file://0003-flashrom-W25Q256JW.patch \
"
