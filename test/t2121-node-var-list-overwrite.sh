#! /bin/sh -e
# tup - A file-based build system
#
# Copyright (C) 2009-2023  Mike Shal <marfey@gmail.com>
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

# Test that a list of node variables can be overwritten.

. ./tup.sh

cat > Tupfile << HERE
&libs = foo.a
&libs += bar.a
: |> echo &(libs) > %o |> out.txt

&libs = quux.a
: |> echo &(libs) > %o |> out2.txt
HERE

touch foo.a bar.a quux.a
update

tup_object_exist . 'echo foo.a bar.a > out.txt'
tup_object_exist . 'echo quux.a > out2.txt'

eotup
