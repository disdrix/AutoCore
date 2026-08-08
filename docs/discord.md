# AutoCore.Discord (optional module)

Optional Launcher-hosted Discord bot for **online player presence** and **DM account management**.

Disabled by default. When `Enabled` is false, Launcher behavior is unchanged.

## Features

| Feature | Details |
|---|---|
| Rich presence | Bot activity text shows online player count (sum of Auth game-server `CurrentPlayers`, filled by Global from live TNL connections) |
| `/newaccount` | Create email + username + password; links account to the Discord user (any channel or DM) |
| `/changepassword` | Change password for an account **linked to that Discord user** only (any channel or DM) |
| Quota | Default **1** game account per Discord user (`MaxAccountsPerDiscordUser`) |

## Setup

### 1. Create a Discord application

1. Open the [Discord Developer Portal](https://discord.com/developers/applications) → **New Application**.
2. **Bot** → **Add Bot** → copy the **token** (never commit it).
3. **OAuth2 → URL Generator**:
   - Scopes: `bot`, `applications.commands`
   - Bot permissions: **Send Messages**, **Use Application Commands**
4. Open the generated invite URL and add the bot to your guild.
5. Enable **Developer Mode** in Discord (User Settings → Advanced), right-click the server → **Copy Server ID** for `GuildId`.

No privileged intents are required for slash commands + presence.

### 2. Configure Launcher

Copy `appsettings.discord.example.json` to `appsettings.discord.json` next to `AutoCore.Launcher.exe` (or under `src/AutoCore.Launcher/`), then edit. The real file is gitignored:

```json
{
  "Enabled": true,
  "BotToken": "YOUR_BOT_TOKEN",
  "GuildId": 123456789012345678,
  "MaxAccountsPerDiscordUser": 1,
  "PresenceUpdateIntervalSeconds": 60,
  "StatusTemplate": "{players} online",
  "AllowAccountCreation": true,
  "MinPasswordLength": 6,
  "MinUsernameLength": 3,
  "MaxUsernameLength": 32
}
```

Optional overlay: `appsettings.discord.env.json` (same pattern as auth/global/sector env files).

### 3. Database

New table: `discord_account_link` (Auth DB).

- Fresh installs: created with `AuthContext.EnsureCreated`.
- Existing MySQL deployments: Launcher also runs `CREATE TABLE IF NOT EXISTS` for `discord_account_link` when Discord starts.

### 4. Start

Run `AutoCore.Launcher` as usual. Discord starts **after Auth** and **before Global** when enabled.

## Player commands

```
/newaccount email:<email> username:<name> password:<password>
/changepassword username:<name> new_password:<password>
```

- Usable in **any channel** the bot can see, or in a DM.
- Bot replies are **ephemeral** (only the invoker sees the response). Password options still appear in the slash UI for the invoker — they are never logged server-side.
- Password changes require a prior Discord link (accounts created via `/newaccount`). Console `auth.create` accounts are not changeable via Discord unless linked.

## In-game `/reportbug`

Players can run (any GM level):

```
/reportbug something broke when I turned in the mission
```

Aliases: `/bug`, `/bugreport`.

The server builds a zip containing:

- player free-text description
- full mission journal (active objectives + completed ids)
- session snapshot (character, map, position, vehicle pools, build identity)
- last **500** high-fidelity action events for that player (`player-events.ndjson`): NPC interact,
  mission dialog, damage dealt/taken, heals, skill casts, economy audits, chat commands, etc.
  (ring is independent of NDJSON min-level so Debug dual-writes under session still appear)

and posts it to the Discord channel configured as `BugReportChannelId` (bot needs **Send Messages** + **Attach Files**).

```json
"BugReportChannelId": 1535729132019650671
```

Cooldown: 60 seconds per character. If Discord is disabled or the channel id is `0`, the command tells the player reports are unavailable.

## Security notes

- Keep `Enabled: false` and empty `BotToken` in `appsettings.discord.example.json`. Never commit `appsettings.discord.json`.
- Never log the bot token or user passwords.
- Linked-only password change prevents takeover of unrelated accounts.
- Interaction and gateway handlers are isolated (SS-25) so a single bad command cannot take down Launcher.

## Architecture (short)

- `AutoCore.Discord` — library (Discord.Net), domain services, fakes for tests.
- `AutoCore.Launcher` — optional `DiscordLauncherServerHost`, player-count source from `AuthServer.Servers`.
- Shared create/hash logic: `AutoCore.Database.Auth.AccountService` (also used by `auth.create`).
