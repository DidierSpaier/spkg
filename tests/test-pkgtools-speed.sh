#!/bin/sh
PKG=kdebase-3.3.2-i486-1.tgz

clean() { rm -rf ',,root' ; }
bench() { time sh -c "$1" ; }
targzrun() { echo "tar xzf:" ; bench "tar xzf $PKG" ; }
ptrun() { echo "installpkg:" ; bench "ROOT=./,,root installpkg $PKG > /dev/null" ; }
fprun() { echo "installpkg:" ; bench "ROOT=./,,root installpkg $PKG > /dev/null" ; }
gziprun() { echo "gzip:" ; bench "gzip -d < $PKG > /dev/null" ; }

#zlibrun
#gziprun
clean
ptrun
#clean
#targzrun
