#!/bin/bash

echo "Building DOM.Grpc.JS ..."
python3 $WORKSPACE_ROOT/scripts/build_js.py \
      --inDir $WORKSPACE_ROOT'/Components/DOM/DOM.Grpc/src' \
      --outDir $WORKSPACE_ROOT'/Components/DOM/DOM.Grpc/gen/js'
echo "Done"
