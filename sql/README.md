# Starter SQL dumps

Shareable MySQL/MariaDB dumps so other operators can start a server **without** any existing player accounts.

| File | Contents |
|------|----------|
| [`autocore_starter.sql`](autocore_starter.sql) | All-in-one import (preferred) |
| [`autocore_world.sql`](autocore_world.sql) | World schema **+** static game data |
| [`autocore_auth.sql`](autocore_auth.sql) | Auth schema only (no accounts) |
| [`autocore_char.sql`](autocore_char.sql) | Char schema only (no characters) |

## Import

```powershell
.\scripts\import-starter-db.ps1 -MySQLPassword YOUR_PASSWORD
```

Or: `mysql -u root -p < sql/autocore_starter.sql`

Then create an admin (`DefaultAdminPassword` or `auth.create`). See [SETUP.md](../SETUP.md).

## Refresh (maintainers)

```powershell
.\scripts\export-starter-db.ps1 -Force
```
