#!/bin/bash
   
     echo -n "Modala sankeyannu tilisi : "
    read num1
    echo -n "Eradane sankeyannu tilisi : "
    read num2
    sum=`expr $num1 / $num2`
    echo "Uttara : $sum"
   
