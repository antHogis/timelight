#!/usr/bin/env bash

set -euo pipefail

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
BUILD_DIR="${SCRIPT_DIR}/../build"

mkdir -p $BUILD_DIR
pushd $BUILD_DIR > /dev/null

cmake ../src
cmake --build .

