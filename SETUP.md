# AutoCore Server Setup Guide

This guide will help you set up and run the AutoCore game server.

## Prerequisites

1. **MySQL/MariaDB Database Server**
   - Install MySQL 8.0+ or MariaDB 10.5+
   - Ensure the MySQL service is running
   - Note your MySQL root password (or create a dedicated user)

2. **Auto Assault Game Files**
   - You need a copy of the Auto Assault game installation
   - The game directory must contain:
     - `exe/autoassault.exe`
     - `clonebase.wad`
     - GLM files (game data archives)

3. **.NET 8.0 Runtime**
   - Ensure .NET 8.0 runtime is installed (should already be installed if you compiled)

## Setup Steps

### 1. Database Setup

You need three MySQL databases: `autocore_auth`, `autocore_char`, and `autocore_world`.

#### Option A: Import the starter dump (Recommended for new operators)

The repo ships a shareable dump under [`sql/`](sql/) with **world static data** and **empty** auth/char schemas (no accounts, no characters). Import it:

```powershell
.\scripts\import-starter-db.ps1 -MySQLPassword YOUR_PASSWORD
```

If MySQL is not in PATH:
```powershell
.\scripts\import-starter-db.ps1 -MySQLPassword YOUR_PASSWORD -MySQLPath "C:\Program Files\MariaDB 12.1\bin\mysql.exe"
```

Or manually:
```powershell
mysql -u root -p < sql\autocore_starter.sql
```

This creates the three databases, loads world tables (`config_new_character`, continents, XP curves, factions, …), and leaves account/character tables empty. After the server starts, create your own admin (see [First account](#first-account) below).

To refresh the dump from a live world DB (maintainers):
```powershell
.\scripts\export-starter-db.ps1 -Force
```

#### Option B: Empty databases only

Run the initialization script (tables are created on first server boot; **world static rows are not** — prefer Option A unless you have another world data source):

```powershell
cd scripts
.\init-databases.ps1 -MySQLUser root -MySQLPassword YOUR_PASSWORD
```

If your MySQL root user has no password:
```powershell
.\init-databases.ps1 -MySQLUser root
```

If MySQL is not in your PATH, specify the path:
```powershell
.\init-databases.ps1 -MySQLUser root -MySQLPath "C:\Program Files\MariaDB 12.1\bin\mysql.exe"
```

#### Option C: Manual SQL Creation

Connect to MySQL and run:

```sql
CREATE DATABASE autocore_auth CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
CREATE DATABASE autocore_char CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
CREATE DATABASE autocore_world CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
```

**Note:** Empty databases get tables from Entity Framework Core on first access, but a working game needs the world data from the starter dump (Option A).

### 2. Configure Database Connection Strings

Edit the `appsettings.*.json` files in the output directory (typically `src/AutoCore.Launcher/bin/Debug/net8.0/`):

#### Update `appsettings.auth.json`:
```json
{
    "AuthDatabaseConnectionString": "Server=localhost;Port=3306;Database=autocore_auth;User=root;Password=YOUR_PASSWORD;Persist Security Info=False;Character Set=utf8;Connection Timeout=300"
}
```

#### Update `appsettings.global.json`:
```json
{
    "CharDatabaseConnectionString": "Server=localhost;Port=3306;Database=autocore_char;User=root;Password=YOUR_PASSWORD;Persist Security Info=False;Character Set=utf8;Connection Timeout=300",
    "WorldDatabaseConnectionString": "Server=localhost;Port=3306;Database=autocore_world;User=root;Password=YOUR_PASSWORD;Persist Security Info=False;Character Set=utf8;Connection Timeout=300"
}
```

#### Update `appsettings.sector.json`:
```json
{
    "CharDatabaseConnectionString": "Server=localhost;Port=3306;Database=autocore_char;User=root;Password=YOUR_PASSWORD;Persist Security Info=False;Character Set=utf8;Connection Timeout=300",
    "WorldDatabaseConnectionString": "Server=localhost;Port=3306;Database=autocore_world;User=root;Password=YOUR_PASSWORD;Persist Security Info=False;Character Set=utf8;Connection Timeout=300"
}
```

Replace `YOUR_PASSWORD` with your actual MySQL root password (or leave empty if no password is set).

### 3. Configure Game Path

Update the `GamePath` in both `appsettings.global.json` and `appsettings.sector.json`:

```json
{
    "GamePath": "C:\\Path\\To\\Auto Assault\\game\\Auto Assault new"
}
```

**Important:** The path must:
- Point to your Auto Assault game installation directory
- Contain `exe/autoassault.exe`
- Contain `clonebase.wad`
- Use double backslashes (`\\`) or forward slashes (`/`) in JSON

### 4. Configure Server Addresses (Optional)

If running on a different machine or need external access, update the `PublicAddress` fields:

- `appsettings.global.json`: `GameConfig.PublicAddress`
- `appsettings.sector.json`: `GameConfig.PublicAddress`

Default is `127.0.0.1` (localhost only).

## Running the Server

### Option 1: Run All Servers Together (Recommended)

Navigate to the output directory:
```powershell
cd src\AutoCore.Launcher\bin\Debug\net8.0
```

Run the launcher:
```powershell
.\AutoCore.Launcher.exe
```

This will start all three servers:
- **Auth Server** on port 2106
- **Global Server** on port 26880
- **Sector Server** on port 27001

### Option 2: Run Servers Individually

#### Auth Server:
```powershell
cd src\AutoCore.Auth\bin\Debug\net8.0
.\AutoCore.Auth.exe
```

#### Global Server:
```powershell
cd src\AutoCore.Global\bin\Debug\net8.0
.\AutoCore.Global.exe
```

#### Sector Server:
```powershell
cd src\AutoCore.Sector\bin\Debug\net8.0
.\AutoCore.Sector.exe
```

**Note:** If running individually, make sure to:
1. Start Auth Server first
2. Then start Global Server
3. Finally start Sector Server

## Port Configuration

Default ports used by the servers:
- **Auth Server**: 2106 (AuthSocketPort), 2107 (CommunicatorPort)
- **Global Server**: 26880 (GameConfig.Port), 2107 (CommunicatorPort)
- **Sector Server**: 27001 (GameConfig.Port)

Make sure these ports are not blocked by your firewall.

## Troubleshooting

### Database Connection Errors

- Verify MySQL is running: `mysql -u root -p`
- Check connection strings match your MySQL setup
- Ensure databases exist (or let EF create them on first run)
- Verify user permissions

### Game Path Errors

- Verify the path exists and contains `exe/autoassault.exe`
- Check that `clonebase.wad` exists in the game directory
- Ensure path uses correct format (double backslashes or forward slashes)

### Port Already in Use

- Check if ports 2106, 2107, 26880, or 27001 are already in use
- Change ports in the appsettings files if needed
- Ensure no other instance of the server is running

### Asset Loading Errors

- Verify game files are complete
- Check that `clonebase.wad` is not corrupted
- Ensure GLM files are present in the game directory

## Log Files

Log files are created in the same directory as the executables:
- `log-auth.txt` - Auth server logs
- `log-global.txt` - Global server logs  
- `log-sector.txt` - Sector server logs

Check these files for detailed error messages if something goes wrong.

## First account

The starter SQL dump ships **with no accounts**. Create an admin one of two ways:

1. **Bootstrap on first empty auth DB** — set `DefaultAdminPassword` in `appsettings.auth.json` before the first Auth start. That creates username `admin` / email `admin@autocore.local` at level 255 using your password. Leave it empty (default) to skip seeding.
2. **Console** — after Auth is running:
   ```
   auth.create <email> <username> <password>
   ```

There is no built-in default password.

## Optional: Discord bot

AutoCore can host an optional Discord bot (presence + DM account commands). It is **off by default**.

1. Create a bot in the [Discord Developer Portal](https://discord.com/developers/applications) and invite it with scopes `bot` + `applications.commands`.
2. Copy `appsettings.discord.example.json` to `appsettings.discord.json` next to the Launcher (gitignored), then edit:

```json
{
  "Enabled": true,
  "BotToken": "YOUR_BOT_TOKEN",
  "GuildId": 123456789012345678,
  "MaxAccountsPerDiscordUser": 1
}
```

3. Restart Launcher. Players use slash commands in any channel (or DM):
   - `/newaccount` — email, username, password
   - `/changepassword` — username, new_password (linked accounts only)

Full details: [`docs/discord.md`](docs/discord.md).

## Next Steps

Once all servers are running:
1. Verify all three servers started successfully
2. Check log files for any warnings or errors
3. Configure your Auto Assault client to connect to the server (see `CLIENT_SETUP.md`)
4. Create an admin account if you have not already (see [First account](#first-account))
5. Test client connection with that account

## Client Configuration

To connect the Auto Assault game client to your server, see the **[Client Setup Guide](CLIENT_SETUP.md)** for detailed instructions on configuring the client.

