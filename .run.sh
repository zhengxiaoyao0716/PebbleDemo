#!/bin/bash
# usage: pebble install [-h] [-v] [--phone phone_ip] [--qemu [host]]
#                       [--cloudpebble] [--emulator {aplite,basalt,chalk}]
#                       [--sdk SDK] [--serial SERIAL] [--logs]
#                       [pbw]
pebble build && pebble install --emulator chalk
