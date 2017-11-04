#!/bin/bash

add-apt-repository ppa:team-gcc-arm-embedded/ppa
apt-get update
apt-get upgrade

# Ubuntu Desktop Environment
apt-get install -y ubuntu-desktop

# Libs for pyenv
apt-get install -y make build-essential libssl-dev zlib1g-dev libbz2-dev libreadline-dev libsqlite3-dev wget curl llvm libncurses5-dev libncursesw5-dev libpng-dev

# Libs for yotta
apt-get install -y cmake ninja-build
apt-get install -y gcc-arm-embedded
apt-get install -y srecord
