# Logging / Observability / Exception-Safety Overhaul — Resume Handoff

**Status (2026-08-08): Phases 0–6 COMPLETE.** Full design is implemented: structured NDJSON dual-write,
session identity, economy/mission/gameplay audits, SS-26…SS-29, rate limiting, health, DB timing,
player diagnostics, docs + catalog sync. Nothing committed in the original workstream unless the
operator commits. Discord WIP remains unrelated and should stay untouched when splitting commits.

Master plan file (full design rationale): `C:\Users\josh\.claude\plans\generic-spinning-rossum.md`.
Read `AGENTS.md`, [`docs/exception-safety-audit.md`](exception-safety-audit.md), and
[`docs/logging-observability-audit.md`](logging-observability-audit.md).

## Goal (delivered)

**Player → Session → Request → Subsystem → Operation → Result → State Change → Error** traceability
from NDJSON. Reconstruct with `jq 'select(.SessionId=="…")'` and `jq 'select(.Audit)'`.

## Phase checklist

| Phase | Status | Notes |
|---|---|---|
| 0–1 Infrastructure | Done | GameLog, LogContext, NdjsonFileSink, Logger dual-write, LauncherLoggerSetup |
| 2 Session lifecycle | Done | TNL SessionId, Connection*/Character*/Login*/MapTransfer*, SS-26 Auth Guard |
| 3 Economy + gameplay audits | Done | Currency/Item/Vendor TX, missions, ObjectUsed/death/respawn/chat/loot, SS-27 |
| 4 Security | Done | SS-28 GM gate, NET-001/002, SS-29 log-only key, DevControlRequest |
| 5 Ops | Done | RateLimiter, HealthSummary, TickOverrun, DbOperationTiming, PlayerDiagnostics, Communicator Guard |
| 6 Docs | Done | logging-observability-audit.md, logging-event-catalog.md, LogEventCatalogSyncTests |

## Key entry points

- Utils: `src/AutoCore.Utils/Logging/`
- Catalog: `docs/logging-event-catalog.md`
- LG register: `docs/logging-observability-audit.md`
- SS register: `docs/exception-safety-audit.md` (SS-26…SS-29)

## Optional live smoke (needs user approval)

Do **not** start `AutoCore.Launcher` without explicit approval. When approved: buy/sell/kill/complete
mission/disconnect; confirm `log-sector.ndjson` session + audit reconstruction; confirm kill-loot
credits persist across restart (SS-27).

## Unrelated tree noise

Discord module and related Launcher/DB files may still be dirty in the same working tree — leave
them alone when committing logging work.
