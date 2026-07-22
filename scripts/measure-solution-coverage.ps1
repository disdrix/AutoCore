# Measure first-party AutoCore.* line coverage from Cobertura reports.
# Collects (or reuses) coverage, de-dupes lines by assembly+file+line, prints summary.
# Fails if any present first-party package is below -MinimumRate (default 80%).
# Hosts without coverage packages report MISSING_TESTS; hard-fail only when their
# test project exists (-FailMissingTests:$true, or auto-detect under src/).
# TNL.NET is reported separately and never fails the first-party gate.
param(
    [string]$ResultsDirectory = "",
    [double]$MinimumRate = 80.0,
    [switch]$SkipCollect,
    [Nullable[bool]]$FailMissingTests = $null,
    [switch]$SkipGate
)

$ErrorActionPreference = "Stop"
$repoRoot = Split-Path $PSScriptRoot -Parent
if ([string]::IsNullOrWhiteSpace($ResultsDirectory)) {
    $ResultsDirectory = Join-Path $repoRoot "TestResults\solution-coverage"
}

$firstParty = @(
    "AutoCore.Game",
    "AutoCore.Utils",
    "AutoCore.Database",
    "AutoCore.Sector",
    "AutoCore.Communicator",
    "AutoCore.Auth",
    "AutoCore.Global",
    "AutoCore.Launcher"
)

$testProjects = @(
    @{ Name = "AutoCore.Game.Tests"; Path = "src\AutoCore.Game.Tests\AutoCore.Game.Tests.csproj" },
    @{ Name = "AutoCore.Utils.Tests"; Path = "src\AutoCore.Utils.Tests\AutoCore.Utils.Tests.csproj" },
    @{ Name = "AutoCore.Sector.Tests"; Path = "src\AutoCore.Sector.Tests\AutoCore.Sector.Tests.csproj" },
    @{ Name = "AutoCore.Auth.Tests"; Path = "src\AutoCore.Auth.Tests\AutoCore.Auth.Tests.csproj" },
    @{ Name = "AutoCore.Global.Tests"; Path = "src\AutoCore.Global.Tests\AutoCore.Global.Tests.csproj" },
    @{ Name = "AutoCore.Launcher.Tests"; Path = "src\AutoCore.Launcher.Tests\AutoCore.Launcher.Tests.csproj" },
    @{ Name = "AutoCore.Communicator.Tests"; Path = "src\AutoCore.Communicator.Tests\AutoCore.Communicator.Tests.csproj" },
    @{ Name = "AutoCore.Database.Tests"; Path = "src\AutoCore.Database.Tests\AutoCore.Database.Tests.csproj" }
)

function Test-ProjectExists([string]$relativePath) {
    return Test-Path (Join-Path $repoRoot $relativePath)
}

if ($null -eq $FailMissingTests) {
    # Auto: hard-fail missing hosts once any of Auth/Global/Launcher test projects exist.
    $hostTestExists = @(
        "src\AutoCore.Auth.Tests\AutoCore.Auth.Tests.csproj",
        "src\AutoCore.Global.Tests\AutoCore.Global.Tests.csproj",
        "src\AutoCore.Launcher.Tests\AutoCore.Launcher.Tests.csproj"
    ) | Where-Object { Test-ProjectExists $_ }
    $FailMissingTests = ($hostTestExists.Count -gt 0)
}

if (-not $SkipCollect) {
    if (Test-Path $ResultsDirectory) {
        Remove-Item -Recurse -Force $ResultsDirectory
    }
    New-Item -ItemType Directory -Path $ResultsDirectory -Force | Out-Null

    $anyRan = $false
    foreach ($tp in $testProjects) {
        $projPath = Join-Path $repoRoot $tp.Path
        if (-not (Test-Path $projPath)) {
            Write-Output "SKIP collect (no project): $($tp.Name)"
            continue
        }
        $anyRan = $true
        $outDir = Join-Path $ResultsDirectory $tp.Name
        Write-Output "Collecting coverage: $($tp.Name) -> $outDir"
        & dotnet test $projPath `
            --collect:"XPlat Code Coverage" `
            --results-directory $outDir `
            --verbosity minimal
        if ($LASTEXITCODE -ne 0) {
            Write-Error "dotnet test failed for $($tp.Name) (exit $LASTEXITCODE)."
            exit $LASTEXITCODE
        }
    }
    if (-not $anyRan) {
        Write-Error "No test projects found to collect coverage."
        exit 1
    }
}

$coverageFiles = @(Get-ChildItem -Path $ResultsDirectory -Recurse -Filter "coverage.cobertura.xml" -ErrorAction SilentlyContinue)
if ($coverageFiles.Count -eq 0) {
    # Fallback: newest solution-wide or audit artifacts
    $coverageFiles = @(Get-ChildItem -Path (Join-Path $repoRoot "TestResults") -Recurse -Filter "coverage.cobertura.xml" -ErrorAction SilentlyContinue |
        Sort-Object LastWriteTime -Descending |
        Select-Object -First 20)
}

if ($coverageFiles.Count -eq 0) {
    Write-Error "No coverage.cobertura.xml found under $ResultsDirectory or TestResults/. Run without -SkipCollect."
    exit 1
}

Write-Output ""
Write-Output "Coverage files ($($coverageFiles.Count)):"
$coverageFiles | ForEach-Object { Write-Output "  $($_.FullName)" }

# De-dupe: assembly -> file -> lineNumber -> max hits
# Also track branch hits when present (diagnostics only).
$lineHits = @{}   # key: "pkg|file|line" -> hits
$branchHits = @{} # key: "pkg|file|line" -> @{ covered; total } aggregated

foreach ($cf in $coverageFiles) {
    [xml]$xml = Get-Content -LiteralPath $cf.FullName
    $packages = @($xml.coverage.packages.package)
    foreach ($pkg in $packages) {
        $pkgName = $pkg.name
        if (-not $pkgName) { continue }
        $classes = @($pkg.classes.class)
        foreach ($cls in $classes) {
            if ($cls.name -match '[<>]') { continue }
            $file = $cls.filename
            if (-not $file) { continue }
            # Normalize paths across coverlet runs:
            #   src\AutoCore.X\Foo.cs | AutoCore.X\Foo.cs | Foo.cs  →  autocore.x\foo.cs
            $fileNorm = ($file -replace '/', '\')
            if ($fileNorm -match '(?i)(?:^|\\)src\\(AutoCore\.[^\\]+\\.+)$') {
                $fileNorm = $Matches[1]
            } elseif ($fileNorm -match '(?i)(?:^|\\)(AutoCore\.[^\\]+\\.+)$') {
                $fileNorm = $Matches[1]
            } elseif ($fileNorm -match '(?i)(?:^|\\)lib\\(.+)$') {
                $fileNorm = "lib\$($Matches[1])"
            } else {
                # Project-relative bare path (e.g. Timer\Timer.cs) — prefix package
                $fileNorm = "$pkgName\$($fileNorm.TrimStart('\'))"
            }
            $fileNorm = $fileNorm.ToLowerInvariant()
            $lines = @($cls.lines.line)
            foreach ($ln in $lines) {
                $num = [string]$ln.number
                if ([string]::IsNullOrWhiteSpace($num)) { continue }
                $key = "$pkgName|$fileNorm|$num"
                $hits = 0
                [int]::TryParse([string]$ln.hits, [ref]$hits) | Out-Null
                if (-not $lineHits.ContainsKey($key) -or $hits -gt $lineHits[$key]) {
                    $lineHits[$key] = $hits
                }
                # branch-rate on line is optional in cobertura
                if ($null -ne $ln.branch -and $ln.branch -eq "true" -and $null -ne $ln."condition-coverage") {
                    # condition-coverage format: "50% (1/2)"
                    $m = [regex]::Match([string]$ln."condition-coverage", '\((\d+)/(\d+)\)')
                    if ($m.Success) {
                        $c = [int]$m.Groups[1].Value
                        $t = [int]$m.Groups[2].Value
                        if (-not $branchHits.ContainsKey($key)) {
                            $branchHits[$key] = @{ Covered = $c; Total = $t }
                        } else {
                            # take max covered / max total loosely
                            if ($t -gt $branchHits[$key].Total) {
                                $branchHits[$key] = @{ Covered = $c; Total = $t }
                            } elseif ($c -gt $branchHits[$key].Covered) {
                                $branchHits[$key].Covered = $c
                            }
                        }
                    }
                }
            }
        }
    }
}

function Get-PackageStats([string]$packageName) {
    $keys = @($lineHits.Keys | Where-Object { $_.StartsWith("$packageName|") })
    $total = $keys.Count
    $covered = @($keys | Where-Object { $lineHits[$_] -gt 0 }).Count
    $rate = if ($total -gt 0) { [math]::Round(100.0 * $covered / $total, 2) } else { $null }

    $bKeys = @($branchHits.Keys | Where-Object { $_.StartsWith("$packageName|") })
    $bTotal = 0
    $bCovered = 0
    foreach ($bk in $bKeys) {
        $bTotal += $branchHits[$bk].Total
        $bCovered += $branchHits[$bk].Covered
    }
    $bRate = if ($bTotal -gt 0) { [math]::Round(100.0 * $bCovered / $bTotal, 2) } else { $null }

    return [PSCustomObject]@{
        Package = $packageName
        Lines = $total
        Covered = $covered
        LineRate = $rate
        BranchRate = $bRate
        Present = ($total -gt 0)
    }
}

Write-Output ""
Write-Output "=== First-party assembly line coverage (de-duplicated) ==="
Write-Output ("{0,-28} {1,10} {2,10} {3,10} {4,10}" -f "Assembly", "Lines", "Covered", "Line%", "Branch%")

$failures = @()
$missing = @()
$results = @()

foreach ($name in $firstParty) {
    $stats = Get-PackageStats $name
    $results += $stats
    if (-not $stats.Present) {
        $prodExists = Test-Path (Join-Path $repoRoot "src\$name\$name.csproj")
        if ($prodExists) {
            $missing += $name
            Write-Output ("{0,-28} {1,10} {2,10} {3,10} {4,10}" -f $name, "-", "-", "MISSING_TESTS", "-")
        } else {
            Write-Output ("{0,-28} {1,10} {2,10} {3,10} {4,10}" -f $name, "-", "-", "N/A", "-")
        }
        continue
    }
    $linePct = "{0:N2}" -f $stats.LineRate
    $branchPct = if ($null -ne $stats.BranchRate) { "{0:N2}" -f $stats.BranchRate } else { "-" }
    Write-Output ("{0,-28} {1,10} {2,10} {3,10} {4,10}" -f $name, $stats.Lines, $stats.Covered, $linePct, $branchPct)
    if ($stats.LineRate -lt $MinimumRate) {
        $failures += "$name ($($stats.LineRate)% < $MinimumRate%)"
    }
}

# TNL.NET dependency risk (never gate)
$tnl = Get-PackageStats "TNL.NET"
Write-Output ""
Write-Output "=== Dependency (not first-party gate) ==="
if ($tnl.Present) {
    Write-Output ("{0,-28} {1,10} {2,10} {3,10}" -f "TNL.NET", $tnl.Lines, $tnl.Covered, ("{0:N2}" -f $tnl.LineRate))
} else {
    Write-Output "TNL.NET: no package in reports"
}

# Markdown summary
$mdPath = Join-Path $ResultsDirectory "coverage-summary.md"
$mdDir = Split-Path $mdPath -Parent
if (-not (Test-Path $mdDir)) { New-Item -ItemType Directory -Path $mdDir -Force | Out-Null }
$md = @()
$md += "# Solution coverage summary"
$md += ""
$md += "Generated: $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')"
$md += "Minimum line rate: $MinimumRate%"
$md += ""
$md += "| Assembly | Lines | Covered | Line % | Branch % |"
$md += "|----------|------:|--------:|-------:|---------:|"
foreach ($r in $results) {
    if (-not $r.Present) {
        $md += "| $($r.Package) | - | - | MISSING_TESTS | - |"
    } else {
        $br = if ($null -ne $r.BranchRate) { "$($r.BranchRate)" } else { "-" }
        $md += "| $($r.Package) | $($r.Lines) | $($r.Covered) | $($r.LineRate) | $br |"
    }
}
if ($tnl.Present) {
    $md += ""
    $md += "## TNL.NET (dependency, not gated)"
    $md += ""
    $md += "| Lines | Covered | Line % |"
    $md += "|------:|--------:|-------:|"
    $md += "| $($tnl.Lines) | $($tnl.Covered) | $($tnl.LineRate) |"
}
$md -join "`n" | Set-Content -Path $mdPath -Encoding UTF8
Write-Output ""
Write-Output "Markdown summary: $mdPath"

if ($SkipGate) {
    Write-Output "Gate skipped (-SkipGate)."
    exit 0
}

$exitCode = 0
if ($failures.Count -gt 0) {
    Write-Output ""
    Write-Error ("First-party coverage gate failed (minimum {0}%):`n  {1}" -f $MinimumRate, ($failures -join "`n  "))
    $exitCode = 1
}

if ($missing.Count -gt 0) {
    if ($FailMissingTests) {
        Write-Output ""
        Write-Error ("Missing coverage packages for first-party assemblies with production projects:`n  {0}" -f ($missing -join "`n  "))
        $exitCode = 1
    } else {
        Write-Output ""
        Write-Warning ("MISSING_TESTS (soft): {0}. Will hard-fail once host test projects exist." -f ($missing -join ", "))
    }
}

if ($exitCode -eq 0) {
    Write-Output ""
    Write-Output "Solution coverage gate passed (all present first-party packages >= $MinimumRate%)."
}

exit $exitCode
