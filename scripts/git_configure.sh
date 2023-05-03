#!/bin/zsh
# Assume User Configured Github

branch=`git branch | grep -E '\*' - | cut -d ' ' -f 2`
user=`git config --get user.name`
stage_status=`git ls-remote origin $user-stage`

# I like space between sections
echo

# Check if stage branch exists
if [ -z "$stage_status" ];
then
	# if not, create it
	git branch $user-stage
	git push -u origin $user-stage
else
	# if does, fetch it
	git fetch
fi

git checkout $user-stage

# DEBUG
if [ ! -z "$debug" ];
then
	echo
	echo DEBUG
	echo "====="
	echo "User:\t$user"
	echo "Branch:\t$branch"
	echo "Stage_Staus: $stage_status"
fi

