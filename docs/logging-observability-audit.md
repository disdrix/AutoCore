# Logging / Observability Audit (LG register)

**Status (2026-08-08):** Phases 0–6 of the logging overhaul are implemented. Companion to
[`exception-safety-audit.md`](exception-safety-audit.md) (SS-nn) and the event catalog
[`logging-event-catalog.md`](logging-event-catalog.md). Resume handoff history:
[`migrateGoals.md`](migrateGoals.md).

## Goal

Before the first live playtest: **Player → Session → Request → Subsystem → Operation → Result →
State Change → Error** traceability from NDJSON (`log-*.ndjson`). Reconstruct a session with
`jq 'select(.SessionId=="…")'` and economy stories with `jq 'select(.Audit)'`.

## Design decisions (D1–D8)

| ID | Decision |
|---|---|
| D1 | No Serilog/M.E.Logging. Structured layer is hand-rolled under `src/AutoCore.Utils/Logging/`, never-throws (SS-06). Reserved property names stay CLEF-mappable. |
| D2 | Static `GameLog` facade + string event names; dual-write at `Logger` mirrors every legacy line into NDJSON with ambient context. |
| D3 | `AsyncLocal<LogContext>` scopes. SessionId is a **server-generated** GUID (never client-writable PlayerCoid). CorrelationId per inbound packet. TransactionId `TX-xxxxxxxx` for economy. `Capture()`/`Restore()` across queues/threads. |
| D4 | Audit trail = same NDJSON stream with `Audit:true` (exempt from level filter + rate limiting). Item events pair `ItemCoid` with container/map context where available (COIDs are per-map counters). |
| D5 | `PlayerDiagnostics` enroll SessionId/CharacterId with auto-expiry; enrolled sessions pass Debug/Trace. Console: `log player <id\|session> [minutes]`. `PlaytestDiagnostics` config forces min level Debug. |
| D6 | Rate limiter: token bucket per (EventName, Level), ~20/10s for WARN+; Audit/Fatal/lifecycle exempt; summary `*RateLimited` with `Suppressed=N` on window reopen. |
| D7 | Health: `HealthSummary` every 60s from Sector main loop; `TickOverrun` when tick > 50ms budget; DB slow-op wrapper >250ms. |
| D8 | Fix-vs-log: **FIXED** Launcher LoggerConfig, auth dispatch SS-26, kill-loot SS-27, GM gate SS-28. **LOG-ONLY** transfer key SS-29 (`SecurityKeyMismatch`). |

Never log: VehicleMoved/CreatureMoved handling, ghost pack paths, heartbeats, passwords/keys/tokens
(AuthKey, OneTimeKey included). Do not fabricate events for unimplemented systems (trading, crafting,
mail/auction).

## Infrastructure

| Piece | Location |
|---|---|
| `GameLog`, `LogContext`, `StructuredLogRecord`, `NdjsonFileSink`, `RateLimiter`, `PlayerDiagnostics`, `DbOperationTiming`, `HealthSummaryReporter` | `src/AutoCore.Utils/Logging/` |
| Dual-write | `Logger.WriteLog` / `WriteException` → `GameLog.WriteLegacy` |
| Config | `StructuredLogPath`, `StructuredMinimumLevel`, `PlaytestDiagnostics` in auth/global/sector appsettings; `LauncherLoggerSetup.Apply` |
| Catalog drift guard | `LogEventCatalogSyncTests` scans production `GameLog.*("Name")` vs catalog |

## LG findings / known limitations

| ID | Area | Notes | Status |
|---|---|---|---|
| LG-01 | Item COID provenance | Cargo/locker audits carry `ItemCoid` + `Container` but not always `MapId` (wrappers only see character coid). Prefer joining SessionId + CharacterId + time. | Accepted |
| LG-02 | Transfer key | SS-29: key mismatch is WARN-only; not enforced. | Accepted risk |
| LG-03 | Inventory persist failure | In-memory mutation can succeed while DB write fails; player not notified. `InventoryPersistFailed` (DB-001) + TODO(LG) in `InventoryManager`. | Open (notify player later) |
| LG-04 | Auth session violation | MsgLogout / MsgServerListExt / MsgAboutToPlay still largely legacy-only when session state is wrong. Candidate: `AuthSessionViolation`. | Candidate |
| LG-05 | Character select failure | `HandleLoginPacket` disconnect paths lack a dedicated structured failure event. Candidate: `CharacterSelectFailed`. | Candidate |
| LG-06 | Sector login rejection | LoginToSector TODO path has no structured rejection event. | Candidate |
| LG-07 | Packet dispatch failure | Per-packet catch is still mostly legacy `Logger`; structured `PacketDispatchFailed` not universal. | Candidate |
| LG-08 | Vendor atomicity | Buy path = multiple non-atomic DB writes. Reconstruct via `TransactionId`; atomicity deliberately not fixed. | Accepted |
| LG-09 | Rate-limit summary names | Suppression summaries use `{EventName}RateLimited` (dynamic). Catalog lists the pattern; sync test allows `*RateLimited` suffix. | By design |
| LG-10 | Legacy dual-write | Untouched call sites emit `EventName=Legacy` with `LegacyType`. Not catalogued as first-class product events. | By design |

## Subsystem before / after (summary)

| Subsystem | Before | After |
|---|---|---|
| Session / TNL | Scattered console lines | SessionId + ConnectionId + CorrelationId on every packet; lifecycle events |
| Auth | Unguarded dispatch; password risk | SS-26 Guard; AuthLogin* events; no secrets |
| Economy | Silent credit/item loss paths | CurrencyChanged, Item*, Vendor* + TX- id, SS-27 kill-loot persist |
| Missions | Sparse logs | MissionGranted/Completed/Failed audit; MissionPersistDeadLettered |
| Admin | Open GM commands | SS-28 GMLevel≥1; AdminCommand* |
| Ops | No health signal | HealthSummary, TickOverrun, DbOperationSlow/Failed, RateLimiter |

## Playtest reconstruction recipes

```bash
# One player session
jq 'select(.SessionId=="abc123")' log-sector.ndjson

# Money / items only
jq 'select(.Audit==true)' log-sector.ndjson

# One vendor TX
jq 'select(.TransactionId=="TX-deadbeef")' log-sector.ndjson

# Errors with codes
jq 'select(.ErrorCode!=null)' log-*.ndjson
```

## Related docs

- [`logging-event-catalog.md`](logging-event-catalog.md) — every first-class event
- [`exception-safety-audit.md`](exception-safety-audit.md) — SS-26…SS-29 and boundaries
- [`migrateGoals.md`](migrateGoals.md) — original phased plan / handoff
