# wipeplayers.ps1
# Truncates all character / player data in autocore_char while keeping accounts.
# Does NOT touch autocore_auth (login accounts) or the char-DB `account` table
# (GM level / first-login flags keyed by account id).
#
# Usage:
#   .\scripts\wipeplayers.ps1
#   .\scripts\wipeplayers.ps1 -Force
#   .\scripts\wipeplayers.ps1 -MySQLPassword 'admin123!' -Force
#
# Prefer appsettings passwords first, then common local defaults.

param(
    [string]$MySQLHost = "localhost",
    [int]$MySQLPort = 3306,
    [string]$MySQLUser = "root",
    [string]$MySQLPassword = "",
    [string]$MySQLPath = "",
    [string]$Database = "autocore_char",
    [switch]$Force
)

$ErrorActionPreference = "Stop"

Write-Host "AutoCore wipeplayers" -ForegroundColor Cyan
Write-Host "====================" -ForegroundColor Cyan
Write-Host "Database : $Database"
Write-Host "Keeps    : account (char DB) + all of autocore_auth"
Write-Host "Wipes    : characters, vehicles, inventory, missions, skills, clans, ..."
Write-Host ""

function Find-MySqlClient {
    param([string]$ExplicitPath)

    if ($ExplicitPath) {
        if (-not (Test-Path $ExplicitPath)) {
            throw "MySQL path not found: $ExplicitPath"
        }
        return $ExplicitPath
    }

    try {
        $null = Get-Command "mysql" -ErrorAction Stop
        return "mysql"
    } catch {
        # fall through
    }

    $commonPaths = @(
        "C:\Program Files\MariaDB 12.1\bin\mysql.exe",
        "C:\Program Files\MariaDB 12.0\bin\mysql.exe",
        "C:\Program Files\MariaDB 11.5\bin\mysql.exe",
        "C:\Program Files\MariaDB 11.4\bin\mysql.exe",
        "C:\Program Files\MariaDB 11.3\bin\mysql.exe",
        "C:\Program Files\MySQL\MySQL Server 8.0\bin\mysql.exe",
        "C:\Program Files\MySQL\MySQL Server 8.1\bin\mysql.exe",
        "C:\Program Files\MySQL\MySQL Server 8.2\bin\mysql.exe",
        "C:\Program Files\MySQL\MySQL Server 8.3\bin\mysql.exe",
        "C:\Program Files (x86)\MariaDB 12.1\bin\mysql.exe",
        "C:\Program Files (x86)\MariaDB 12.0\bin\mysql.exe",
        "C:\Program Files (x86)\MySQL\MySQL Server 8.0\bin\mysql.exe"
    )

    foreach ($path in $commonPaths) {
        if (Test-Path $path) {
            return $path
        }
    }

    throw "MySQL client not found. Pass -MySQLPath or add mysql to PATH."
}

function Get-PasswordCandidates {
    param([string]$ExplicitPassword)

    $candidates = [System.Collections.Generic.List[string]]::new()

    if (-not [string]::IsNullOrEmpty($ExplicitPassword)) {
        $candidates.Add($ExplicitPassword)
        return $candidates
    }

    # Env override (never log the value)
    if (-not [string]::IsNullOrEmpty($env:AUTOCORE_MYSQL_PASSWORD)) {
        $candidates.Add($env:AUTOCORE_MYSQL_PASSWORD)
    }

    # Appsettings used by Launcher / Sector / Global
    $repoRoot = Split-Path $PSScriptRoot -Parent
    $settingsFiles = @(
        (Join-Path $repoRoot "src\AutoCore.Launcher\appsettings.sector.json"),
        (Join-Path $repoRoot "src\AutoCore.Launcher\appsettings.global.json"),
        (Join-Path $repoRoot "src\AutoCore.Sector\appsettings.sector.json"),
        (Join-Path $repoRoot "src\AutoCore.Global\appsettings.global.json")
    )

    foreach ($file in $settingsFiles) {
        if (-not (Test-Path $file)) { continue }
        try {
            $json = Get-Content -Raw -Path $file | ConvertFrom-Json
            $cs = $json.Config.CharDatabaseConnectionString
            if (-not $cs) { $cs = $json.CharDatabaseConnectionString }
            if ($cs -match '(?i)Password=([^;]*)') {
                $pw = $Matches[1]
                if (-not [string]::IsNullOrEmpty($pw) -and -not $candidates.Contains($pw)) {
                    $candidates.Add($pw)
                }
            }
        } catch {
            # ignore unreadable settings
        }
    }

    # Local defaults seen in this repo / scripts
    foreach ($pw in @("admin123!", "Jcr321321!", "")) {
        if (-not $candidates.Contains($pw)) {
            $candidates.Add($pw)
        }
    }

    return $candidates
}

function Test-MySqlConnection {
    param(
        [string]$MysqlCmd,
        [string]$HostName,
        [int]$Port,
        [string]$User,
        [string]$Password
    )

    $args = @("-h", $HostName, "-P", $Port.ToString(), "-u", $User, "-N", "-B", "-e", "SELECT 1;")
    if ($null -ne $Password) {
        $args = @("-h", $HostName, "-P", $Port.ToString(), "-u", $User, "-p$Password", "-N", "-B", "-e", "SELECT 1;")
    }

    $prev = $ErrorActionPreference
    $ErrorActionPreference = "Continue"
    $output = & $MysqlCmd @args 2>&1
    $code = $LASTEXITCODE
    $ErrorActionPreference = $prev

    return ($code -eq 0)
}

function Invoke-MySql {
    param(
        [string]$MysqlCmd,
        [string]$HostName,
        [int]$Port,
        [string]$User,
        [string]$Password,
        [string]$Sql
    )

    $args = @("-h", $HostName, "-P", $Port.ToString(), "-u", $User, "-p$Password")
    $prev = $ErrorActionPreference
    $ErrorActionPreference = "Continue"
    $output = $Sql | & $MysqlCmd @args 2>&1
    $code = $LASTEXITCODE
    $ErrorActionPreference = $prev

    return [pscustomobject]@{
        ExitCode = $code
        Output   = ($output | Out-String)
    }
}

$mysqlCmd = Find-MySqlClient -ExplicitPath $MySQLPath
Write-Host "Using MySQL client: $mysqlCmd" -ForegroundColor Gray

$password = $null
foreach ($candidate in (Get-PasswordCandidates -ExplicitPassword $MySQLPassword)) {
    if (Test-MySqlConnection -MysqlCmd $mysqlCmd -HostName $MySQLHost -Port $MySQLPort -User $MySQLUser -Password $candidate) {
        $password = $candidate
        break
    }
}

if ($null -eq $password) {
    Write-Host "Error: could not connect to MySQL as $MySQLUser@$MySQLHost`:$MySQLPort" -ForegroundColor Red
    Write-Host "Pass -MySQLPassword or set AUTOCORE_MYSQL_PASSWORD." -ForegroundColor Yellow
    exit 1
}

Write-Host "Connected to MySQL." -ForegroundColor Green

if (-not $Force) {
    Write-Host ""
    Write-Host "WARNING: This deletes ALL characters and related data in '$Database'." -ForegroundColor Red
    Write-Host "Accounts are kept. Auth DB is not touched." -ForegroundColor Yellow
    Write-Host "Press Ctrl+C to cancel, or any key to continue..." -ForegroundColor Yellow
    $null = $Host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown")
    Write-Host ""
}

# Tables that hold player/character state. `account` is intentionally omitted.
# Unknown tables are skipped (older/newer schemas).
$playerTables = @(
    "character_inventory",
    "character_mission",
    "character_mission_completed",
    "character_quest",
    "character_completed_mission",
    "character_learned_skill",
    "character_quickbar",
    "character_exploration",
    "character_social",
    "character_stats",
    "clan_member",
    "clan",
    "vehicle",
    "simple_object",
    "character"
)

$truncateStmts = foreach ($t in $playerTables) {
    @"
SET @sql = IF(
  (SELECT COUNT(*) FROM information_schema.tables
   WHERE table_schema = '$Database' AND table_name = '$t') > 0,
  'TRUNCATE TABLE ``$t``',
  'SELECT 1'
);
PREPARE stmt FROM @sql; EXECUTE stmt; DEALLOCATE PREPARE stmt;
"@
}

$countExprs = ($playerTables | ForEach-Object {
    "UNION ALL SELECT '$_', IFNULL((SELECT COUNT(*) FROM information_schema.tables t WHERE t.table_schema='$Database' AND t.table_name='$_'),0), IFNULL((SELECT TABLE_ROWS FROM information_schema.tables WHERE table_schema='$Database' AND table_name='$_'),0)"
}) -join "`n"

# Use exact COUNTs after wipe; approximate TABLE_ROWS only for the before snapshot.
$sql = @"
USE ``$Database``;

SELECT 'BEFORE' AS phase;
SELECT 'account' AS tbl, COUNT(*) AS cnt FROM account
UNION ALL SELECT 'character', COUNT(*) FROM ``character``
UNION ALL SELECT 'vehicle', COUNT(*) FROM vehicle
UNION ALL SELECT 'simple_object', COUNT(*) FROM simple_object
UNION ALL SELECT 'character_inventory', COUNT(*) FROM character_inventory
UNION ALL SELECT 'character_mission', COUNT(*) FROM character_mission
UNION ALL SELECT 'character_mission_completed', COUNT(*) FROM character_mission_completed;

SET FOREIGN_KEY_CHECKS = 0;
$($truncateStmts -join "`n")
SET FOREIGN_KEY_CHECKS = 1;

SELECT 'AFTER' AS phase;
SELECT 'account' AS tbl, COUNT(*) AS cnt FROM account
UNION ALL SELECT 'character', COUNT(*) FROM ``character``
UNION ALL SELECT 'vehicle', COUNT(*) FROM vehicle
UNION ALL SELECT 'simple_object', COUNT(*) FROM simple_object
UNION ALL SELECT 'character_inventory', COUNT(*) FROM character_inventory
UNION ALL SELECT 'character_mission', COUNT(*) FROM character_mission
UNION ALL SELECT 'character_mission_completed', COUNT(*) FROM character_mission_completed;

SELECT
  (SELECT COUNT(*) FROM account) AS accounts_kept,
  (SELECT COUNT(*) FROM ``character``) AS characters_left,
  (SELECT COUNT(*) FROM vehicle) AS vehicles_left,
  (SELECT COUNT(*) FROM simple_object) AS simple_objects_left;
"@

Write-Host "Wiping player tables in $Database ..." -ForegroundColor Yellow
$result = Invoke-MySql -MysqlCmd $mysqlCmd -HostName $MySQLHost -Port $MySQLPort -User $MySQLUser -Password $password -Sql $sql

if ($result.ExitCode -ne 0) {
    Write-Host "Error: wipe failed (exit $($result.ExitCode))." -ForegroundColor Red
    Write-Host $result.Output
    exit $result.ExitCode
}

Write-Host $result.Output

# Hard-fail if any character rows remain
$verifySql = "USE ``$Database``; SELECT COUNT(*) FROM ``character``;"
$verify = Invoke-MySql -MysqlCmd $mysqlCmd -HostName $MySQLHost -Port $MySQLPort -User $MySQLUser -Password $password -Sql $verifySql
$left = ($verify.Output -split "`r?`n" | Where-Object { $_ -match '^\d+$' } | Select-Object -Last 1)

if ($verify.ExitCode -ne 0) {
    Write-Host "Error: post-wipe verify failed." -ForegroundColor Red
    Write-Host $verify.Output
    exit 1
}

if ($left -ne "0") {
    Write-Host "Error: expected 0 characters after wipe, found $left." -ForegroundColor Red
    exit 1
}

Write-Host "[SUCCESS] Player data wiped. Accounts kept." -ForegroundColor Green
exit 0
