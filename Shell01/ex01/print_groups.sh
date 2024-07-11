#!/bin/bash
id -G -n | tr " "  "," | tr -d "\n"
