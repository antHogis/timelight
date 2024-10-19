#!/usr/bin/env bash

set -uo pipefail

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
pushd $SCRIPT_DIR/.. > /dev/null

run_build() {
  pkill -f './build/TimeLight'  # Kills the running program
  ./scripts/build.sh && ./build/TimeLight &  # Rebuild and restart in the background
}

run_build
while inotifywait -r -e modify,create,delete,move src; do
	run_build
done
