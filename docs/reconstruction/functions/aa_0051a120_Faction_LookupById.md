# Function record: Faction_LookupById

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a120` |
| **Canonical name** | `Faction_LookupById` |
| **Ghidra name** | `FUN_0051a120` |
| **Address** | `0x0051a120` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | game-data / faction table |
| **Completion status** | **Dual A/B sealed** (WQ9R-G 2026-08-04) — **accept-with-gaps** |
| **Naming basis** | Caller miss path `"UNDEFINED FACTION: %i"`; display name @ record+4 |

## Purpose

See `aa_0051a120_FUN_0051a120.md` and dual reviews A/B.

## Signature

```c
void* Faction_LookupById(uint32_t factionId);
```

## Artifacts

Same set as `aa_0051a120_FUN_0051a120.md` (raw / annotated / clean / duals / report).
