/*
* ir3595.c - The i2c driver for IR3595A
 *
 * Copyright 2018-present Facebook. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

// #define DEBUG

#include <linux/errno.h>
#include <linux/i2c.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>

#include "i2c_dev_sysfs.h"

#ifdef DEBUG
#define IR3595_DEBUG(fmt, ...) do {                   \
  printk(KERN_DEBUG "%s:%d " fmt "\n",            \
         __FUNCTION__, __LINE__, ##__VA_ARGS__);  \
} while (0)

#else /* !DEBUG */

#define IR3595_DEBUG(fmt, ...)
#endif

static ssize_t ir3595_vout_show(struct device *dev,
                                    struct device_attribute *attr,
                                    char *buf)
{
  int result = -1;

  result = i2c_dev_read_word_bigendian(dev, attr);

  if (result < 0) {
    /* error case */
    IR3595_DEBUG("I2C read error, result: %d\n", result);
    return -1;
  }

  return scnprintf(buf, PAGE_SIZE, "%d\n", (result * 1000) / 2048);
}

static ssize_t ir3595_iout_show(struct device *dev,
                                    struct device_attribute *attr,
                                    char *buf)
{
  int result = -1;

  result = i2c_dev_read_byte(dev, attr);

  if (result < 0) {
    /* error case */
    IR3595_DEBUG("I2C read error, result: %d\n", result);
    return -1;
  }

  return scnprintf(buf, PAGE_SIZE, "%d\n", result * 2 * 1000);
}

static ssize_t ir3595_temp_show(struct device *dev,
                                    struct device_attribute *attr,
                                    char *buf)
{
  int result = -1;

  result = i2c_dev_read_byte(dev, attr);

  if (result < 0) {
    /* error case */
    IR3595_DEBUG("I2C read error, result: %d\n", result);
    return -1;
  }

  return scnprintf(buf, PAGE_SIZE, "%d\n", result * 1000);
}


static const i2c_dev_attr_st ir3595_attr_table[] = {
  {
    "in0_input",
    NULL,
    ir3595_vout_show,
    NULL,
    0x9a, 0, 8,
  },
  {
    "curr1_input",
    NULL,
    ir3595_iout_show,
    NULL,
    0x94, 0, 8,
  },
  {
    "temp1_input",
    NULL,
    ir3595_temp_show,
    NULL,
    0x9d, 0, 8,
  },
  {
    "in0_label",
    "TH3 serdes Voltage",
    i2c_dev_show_label,
    NULL,
    0x0, 0, 0,
  },
  {
    "curr1_label",
    "TH3 serdes Current",
    i2c_dev_show_label,
    NULL,
    0x0, 0, 0,
  },
  {
    "temp1_label",
    "TH3 serdes Temp",
    i2c_dev_show_label,
    NULL,
    0x0, 0, 0,
  },
};

/*
 * ir3595 i2c addresses.
 */
static const unsigned short normal_i2c[] = {
  0x12, I2C_CLIENT_END
};


/* ir3595 id */
static const struct i2c_device_id ir3595_id[] = {
  {"ir3595", 0},
  { },
};
MODULE_DEVICE_TABLE(i2c, ir3595_id);

#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 5, 0)
static int ir3595_probe(struct i2c_client *client)
#else
static int ir3595_probe(struct i2c_client *client,
                         const struct i2c_device_id *id)
#endif
{
  i2c_dev_data_st *data;

  data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
  if (!data)
    return -ENOMEM;

  i2c_set_clientdata(client, data);

  return devm_i2c_dev_sysfs_init(client, data, ir3595_attr_table,
                                 ARRAY_SIZE(ir3595_attr_table));
}

static struct i2c_driver ir3595_driver = {
  .class    = I2C_CLASS_HWMON,
  .driver = {
    .name = "ir3595",
  },
  .probe    = ir3595_probe,
  .id_table = ir3595_id,
  .address_list = normal_i2c,
};
module_i2c_driver(ir3595_driver);

MODULE_AUTHOR("Mickey Zhan");
MODULE_DESCRIPTION("ir3595 Driver");
MODULE_LICENSE("GPL");
