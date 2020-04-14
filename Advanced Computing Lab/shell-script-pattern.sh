#!/bin/bash


echo -n "Enter the number upto which you want to print the pattern: "

declare -i PATTERN_NUMBER

read PATTERN_NUMBER

echo ""

NUM=0
while [ $NUM -le $PATTERN_NUMBER ]
do
    TEMP=$NUM
    while [ $TEMP -ge 0 ]
    do
        echo -n "$TEMP"
        TEMP=`expr $TEMP - 1`
    done
    echo ""
    NUM=`expr $NUM + 1`
done
NUM=`expr $PATTERN_NUMBER - 1`
while [ $NUM -ge 0 ]
do
    TEMP=$NUM
    while [ $TEMP -ge 0 ]
    do
        echo -n "$TEMP"
        TEMP=`expr $TEMP - 1`
    done
    echo ""
    NUM=`expr $NUM - 1`
done

unset NUM
unset TEMP
unset PATTERN_NUMBER
