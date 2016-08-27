#!/bin/bash
for var in *.avi; do
	echo 'cp "'$var'" "'${var:14:2}${var:17}'"' >> todo.sh
done
chmod u+x todo.sh