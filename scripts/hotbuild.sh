#!/usr/bin/env bash

set -uo pipefail

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
pushd $SCRIPT_DIR/.. > /dev/null

while inotifywait -r -e modify,create,delete,move src; do
  pkill -f './build/TimeLight'  # Kills the running program
  ./scripts/build.sh && ./build/TimeLight &  # Rebuild and restart in the background
done
