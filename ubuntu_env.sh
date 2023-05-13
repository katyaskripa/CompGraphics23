#!/bin/bash

apt-get update
apt-get install -y sudo
sudo apt-get install -y git
sudo apt-get install -y cmake
sudo apt-get install -y ccache
sudo apt-get install -y lld
sudo apt-get install -y ninja-build
pip3 install --force-reinstall -v "conan==1.59.0"
