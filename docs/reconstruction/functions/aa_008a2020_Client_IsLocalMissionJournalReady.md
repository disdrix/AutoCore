# Function record: Client_IsLocalMissionJournalReady

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a2020` |
| **Canonical name** | `Client_IsLocalMissionJournalReady` |
| **Ghidra name** | `FUN_008a2020` |
| **Prior aliases** | `Named_CalleeOf_Mission_Client_BuildMissionDetailPanel_008a2020` |
| **Address** | `0x008a2020`–`0x008a2037` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / journal UI |
| **Completion status** | **Dual-sealed 2026-07-29 W21-F** — raw/annotated/clean + A/B reviews |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Null-safe client wrapper: load local character from `DAT_00d1b6d8`; if null return false; else `CVOGCharacter_IsMissionJournalReady(localChar, mission)`.

Sole static consumer `FUN_008a3510` uses the bool to append `"_done"` icon path and `"  [Complete]"` title chrome when detail panel mode `+0x50c == 0`.

## Signature

```c
// __cdecl; bool in AL; 1 stack arg
uint8_t Client_IsLocalMissionJournalReady(void* mission);
```

Inner call: `__thiscall CVOGCharacter_IsMissionJournalReady(void* this /*ECX=DAT_00d1b6d8*/, void* mission)`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008a2020_FUN_008a2020.md`
- Annotated: `docs/reconstruction/raw/aa_008a2020_FUN_008a2020.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_IsLocalMissionJournalReady.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_008a2020.cpp`
- Reviews: `reviews/A_aa_008a2020_Client_IsLocalMissionJournalReady.md`, `reviews/B_aa_008a2020_Client_IsLocalMissionJournalReady.md`
- Callee dual: `aa_0052b3b0` / `CVOGCharacter_IsMissionJournalReady`

## Callers / callees

| Direction | VA | Name |
|---|---|---|
| Caller | `0x008a3510` / site `0x008a384b` | `FUN_008a3510` (mission detail panel) |
| Callee | `0x0052b3b0` | `CVOGCharacter_IsMissionJournalReady` |
| Global | `0x00d1b6d8` | local character pointer |

## Confidence

| Claim | Level |
|---|---|
| Control flow + ABI (cdecl / null→0 / forward) | **High** |
| Callee identity journal-ready mode-0 | **High** (sibling dual) |
| UI Complete chrome contract via caller | **High** |
| Product name of this wrapper | **Probable** |
| Runtime multi-character meaning of global | **Open** |
