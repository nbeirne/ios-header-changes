XCODE_PATH=$1
CONTENTS_PATH=$XCODE_PATH/Contents/Developer/Platforms/iPhoneOS.platform

rsync -vaP --include '*.h' --include="*/" --exclude="*" "$CONTENTS_PATH" .

