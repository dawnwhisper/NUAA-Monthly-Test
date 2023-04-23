#!/bin/bash
echo $FLAG > /dev/null && export FLAG=not && FLAG=not && \
service apache2 restart && \
tail -f /dev/null
