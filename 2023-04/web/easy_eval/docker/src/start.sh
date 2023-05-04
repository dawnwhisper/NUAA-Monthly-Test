#!/bin/bash
echo $FLAG > /flag && export FLAG=not && FLAG=not && \
service apache2 restart && \
tail -f /dev/null
