# Multi-agent partition map — wave 8 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **701** unique A |
| Rule | **One write owner per VA** |

## High-priority callees (from DriveControlTick / RequestCast / LocalCast / SearchAutoMissions / Grab)

| VA | Context |
|----|---------|
| `0x00404c90` | DriveControlTick callee |
| `0x00404cb0` | DriveControlTick callee |
| `0x0040d040` | DriveControlTick callee |
| `0x004c3a40` | DriveControlTick callee |
| `0x004c55e0` | DriveControlTick callee |
| `0x004cd220` | DriveControlTick callee |
| `0x004cff70` | DriveControlTick / terrain |
| `0x004f3700` | Vehicle drive path |
| `0x005081d0` | HB-related |
| `0x005172d0` | Skill path |
| `0x0056a260` | Drive/skill path |
| `0x0075c340` | DriveControlTick callee |
| `0x0091d460` | Client input path |
| `0x0091f6b0` | Client input path |
| `0x007fb690` | RequestCast path |
| `0x008f8200` | RequestCast path |
| `0x00786990` | Mission search path |
| `0x00786a00` | Mission search path |
| `0x007a4480` | VOG_DEBUG_STOP helper |
| `0x007fbbb0` | Grab path |
| `0x00550300` | Skill_ResolveTargetList (if no dual) |
| `0x004e2600` | ValidateTarget list predicate |

## Meta

| Role | Focus |
|------|-------|
| CRT/import trivial-batch | Remaining pure FF25 IAT |
| Parent | restamp after land |

## Honesty

Terminal **false**. Dual 701 / 25666. Stamp ≠ dual depth.
