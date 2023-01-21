# Remove everything except word characters from the string.
# In effect, this removes any punctuation ('-', ':', '.')
$sanitizedHexStr = 'AA:BB:CC:DD:E2:00' -replace '\W'

# Convert all hex-digit pairs in the string to an array of bytes.
$bytes = [byte[]] -split ($sanitizedHexStr -replace '..', '0x$& ')

# Get the Base64 encoding of the byte array.
[System.Convert]::ToBase64String($bytes)
