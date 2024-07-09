awk -F "," '
BEGIN { FPAT="([^,]*)|(\"[^\"]+\")" }
{
    if(NR>1) {
        split($2, name, "_")
        match($6, /\(([^)]+)\)/, arr)
        username = name[1]
        password = $4 arr[1]
        print username " " password
    }
}' resources/data-pkm.csv > users.txt