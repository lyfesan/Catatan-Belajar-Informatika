#!/bin/bash

read -p "Enter username : " username
read -p "Enter password : " password

MESSAGE_SUCCESS="LOGIN: SUCCESS $username is logged in"
MESSAGE_FAIL="LOGIN: ERROR Failed login attempt on $username"

awk -F "," -v username="$username" -v password="$password" -v current_date="$(date +"%y/%m/%d %H:%M:%S")" -v msg_success="$MESSAGE_SUCCESS" -v msg_fail="$MESSAGE_FAIL" '
BEGIN { 
    FPAT="([^,]*)|(\"[^\"]+\")" 
    flag_login=0 
}

{
    split($2, name, "_")
    match($6, /\(([^)]+)\)/, arr)
    pass = $4 arr[1]
    if(name[1] == username && password == pass) {
        flag_log=1
        exit
    }
} 

END {
    if(flag_log==0) {
        print current_date " " msg_fail
    }
    else {
        print current_date " " msg_success
    }
}' resources/data-pkm.csv >> "log.txt"