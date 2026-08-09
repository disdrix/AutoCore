# AutoCore

.NET Core multiplatform server application for Auto Assault.

## Quick Links

- **[Quick Start Guide](QUICKSTART.md)** - Get running in 5 minutes
- **[Setup Guide](SETUP.md)** - Detailed server setup instructions
- **[Client Setup Guide](CLIENT_SETUP.md)** - Configure the Auto Assault client to connect to your server
- **[Documentation index](docs/TOC.md)** - Networking, packet layout, and subsystem docs
- **[Inventory Catalog](tools/inventory-catalog/README.md)** - Browse exported inventory item definitions and stack sizes
- **[Mission Viewer](tools/mission-viewer/README.md)** - Offline browser for all missions (requirements, flow, gates)

## Overview

AutoCore is a complete server implementation for the Auto Assault MMO game, consisting of three main server components:

- **Auth Server** - Handles client authentication and account management
- **Global Server** - Manages character data and global game state
- **Sector Server** - Handles in-game sector/map operations

## Databases & first account

Import the shareable starter dump (world data, no accounts):

```powershell
.\scripts\import-starter-db.ps1 -MySQLPassword YOUR_PASSWORD
```

Then create an admin via `DefaultAdminPassword` in `appsettings.auth.json`, or `auth.create` on the Auth console. See [SETUP.md](SETUP.md).
