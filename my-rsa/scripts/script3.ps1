$myArgs = $args.Clone()
$myhex = $myArgs[0]
#$bytes = [byte[]] -split ($myhex -replace '..', '0x$& ')
$myhex = [System.Convert]::FromBase64String($test)

