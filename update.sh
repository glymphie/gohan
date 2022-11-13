#!/bin/sh
SUCKLESS="$GIT/suckless"

rsync -a --delete --exclude=".git" --exclude="README*" "$SUCKLESS/st" .
rsync -a --delete --exclude=".git" --exclude="README*" "$SUCKLESS/dmenu" .
rsync -a --delete --exclude=".git" --exclude="README*" "$SUCKLESS/dwm" .
rsync -a --delete --exclude=".git" --exclude="README*" "$SUCKLESS/slock" .
rsync -a --delete --exclude=".git" --exclude="README*" "$SUCKLESS/dwmblocks" .
