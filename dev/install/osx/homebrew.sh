#!/bin/bash

# Workaround for issue #15
sudo cp /usr/include/assert.h /usr/local/include/

brew update

brew install boost --c++11
brew install Caskroom/cask/xquartz # Needed for Cairo
brew install libsndfile cairo pkgconfig cmake ninja openssl libusb assimp mpg123
brew install homebrew/science/opencv --c++11 --without-python --without-numpy --without-tests

# Cairo dependencies automatically installed:
# libpng, freetype, fontconfig, pixman, gettext, libffi, glib
