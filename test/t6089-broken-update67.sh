#! /bin/sh -e
# tup - A file-based build system
#
# Copyright (C) 2022-2023  Mike Shal <marfey@gmail.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

# Try writing to a file in a file that is both internally ignored (eg: in .git
# from pel_ignored()) and explicitly ignored with an exclusion. Tup was
# checking the explicit ignores first, and getting an internal error about not
# finding the final pel pointer because the .git directory is also internally
# ignored.

. ./tup.sh

mkdir .git
cat > Tupfile << HERE
: |> touch %o && touch .git/index-lock |> out ^\.git
HERE
update

eotup
