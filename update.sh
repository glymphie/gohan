#!/bin/sh
rm -rf dmenu dwm dwmblocks st libxft-bgra slock

SUCKLESS="$GIT/suckless"

rsync -a --delete --exclude=".git" "$SUCKLESS/st" .
rsync -a --delete --exclude=".git" "$SUCKLESS/dmenu" .
rsync -a --delete --exclude=".git" "$SUCKLESS/dwm" .
rsync -a --delete --exclude=".git" "$SUCKLESS/libxft-bgra" .
rsync -a --delete --exclude=".git" "$SUCKLESS/slock" .
rsync -a --delete --exclude=".git" "$SUCKLESS/dwmblocks" .
