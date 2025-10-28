param(
	[Parameter(Mandatory = $true)]
	[string]$CFile
)

# Derive the base name (e.g., "taskEight" from "taskEight.c")
$BaseName = [System.IO.Path]::GetFileNameWithoutExtension($CFile)
# Define the output executable name (e.g., "taskEight.exe")
$ExeName = "$BaseName.exe"

# The compilation command (replacing program with the derived executable name)
$CompileCommand = "clang -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes -Wwrite-strings -Waggregate-return -Wmissing-prototypes -Wmissing-declarations -Wswitch-enum -Wuninitialized -Wfloat-equal -Wundef -lm -o $ExeName $CFile"

Write-Host "Compiling $CFile to $ExeName..."

# Execute the compile command
Invoke-Expression $CompileCommand

# Check if compilation was successful (i.e., if the executable was created)
if (Test-Path $ExeName) {
	Write-Host "Compilation successful. Running $ExeName..."
	# Execute the compiled program
	& ".\$ExeName"
}
else {
	Write-Error "Compilation failed. Check the output above."
}