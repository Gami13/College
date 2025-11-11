param(
	[Parameter(Mandatory = $true)]
	[string]$CFile
)

$BaseName = [System.IO.Path]::GetFileNameWithoutExtension($CFile)
$ExeName = "$BaseName.exe"
$OutDir = Join-Path -Path (Get-Location) -ChildPath "out"

if (-not (Test-Path $OutDir)) {
	New-Item -ItemType Directory -Path $OutDir | Out-Null
}

$ExePath = Join-Path -Path $OutDir -ChildPath $ExeName

$CompileCommand = "clang -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes -Wwrite-strings -Waggregate-return -Wmissing-prototypes -Wmissing-declarations -Wswitch-enum -Wuninitialized -Wfloat-equal -Wundef -std=c99 -lm -o `"$ExePath`" `"$CFile`""

Write-Host "Compiling $CFile to $ExePath..."

Invoke-Expression $CompileCommand

if (Test-Path $ExePath) {
	Write-Host "Compilation successful. Running $ExePath..."
	& $ExePath
}
else {
	Write-Error "Compilation failed. Check the output above."
}