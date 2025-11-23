#!/bin/sh

# android-platform-manager.sh android-28

DIR="$(cd "$(dirname "$0")" && pwd)"

NDK_VERSION=26.2.11394342
NDK_VERSION=android-ndk-r21e
NDK_VERSION=21.4.7075529
export ANDROID_HOME=${HOME}/Android/Sdk
export ANDROID_SDK_ROOT=${HOME}/Android/Sdk
export ANDROID_NDK_HOME=${ANDROID_SDK_ROOT}/ndk/${NDK_VERSION}
export PATH=/opt/cmake/cmake-3.19/bin:$PATH
export PATH=$PATH:${ANDROID_HOME}/tools/bin:${ANDROID_HOME}/platform-tools

python3 $DIR/boden.py $@
