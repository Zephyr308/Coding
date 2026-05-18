#!/bin/bash

sudo apt update

sudo apt install -y \
gpsd \
gpsd-clients \
python3-pip \
sqlite3

pip3 install -r requirements.txt

sudo systemctl enable gpsd
sudo systemctl restart gpsd
