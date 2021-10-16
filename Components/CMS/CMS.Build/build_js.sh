#!/bin/bash

echo "Building CMS.Grpc.JS ..."
python3 $WORKSPACE_ROOT/scripts/build_js.py \
      --inDir $WORKSPACE_ROOT'/Components/CMS/CMS.Grpc/src' \
      --outDir $WORKSPACE_ROOT'/Components/CMS/CMS.Grpc/gen/js' \
      -path $WORKSPACE_ROOT'/Components/DOM/DOM.Grpc/src'
echo "Done"
