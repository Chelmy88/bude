#! /bin/bash

docker run --rm -ti --user shiny -d -p 3838:3838 -v `pwd`/srv/shiny-server:/srv/shiny-server/ -v `pwd`/srv/data:/data rocker/shiny