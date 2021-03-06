#!/bin/sh
rm -rf dmenu dwm dwmblocks st libxft-bgra slock

SUCKLESS="$GIT/suckless"

rsync -a --delete --exclude=".git" --exclude="README*" "$SUCKLESS/st" .
rsync -a --delete --exclude=".git" --exclude="README*" "$SUCKLESS/dmenu" .
rsync -a --delete --exclude=".git" --exclude="README*" "$SUCKLESS/dwm" .
rsync -a --delete --exclude=".git" --exclude="README*" "$SUCKLESS/libxft-bgra" .
rsync -a --delete --exclude=".git" --exclude="README*" "$SUCKLESS/slock" .
rsync -a --delete --exclude=".git" --exclude="README*" "$SUCKLESS/dwmblocks" .
