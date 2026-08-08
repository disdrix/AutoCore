# Function record: EnsureFactionsLookupLoaded

| Field | Value |
|---|---|
| **Stable ID** | `aa_005197b0` |
| **Canonical name** | `EnsureFactionsLookupLoaded` |
| **Address** | `0x005197b0` |
| **Body** | `0x005197b0`–`0x00519a22` (626 bytes → `ret`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | factions / client table bring-up |
| **Calling convention** | cdecl / void — no stack args |
| **Completion status** | **Dual A/B complete** — accept-with-gaps (2026-08-04 WQ9R-F) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_005197b0` (Ghidra)
- **Rejected:** `Named_VOG_DEBUG_STOP_005197b0` (scaffold)

## Purpose

Ensure-load **`tFactions`** (`//tFactions/row` via `FUN_007ce550`) into global CNDHash at **`0x00b04314`**. Converts each row’s id + two wide strings into a **0x64** MBCS heap record and inserts by id. Boot + lazy consumers.

## Signature

```c
void EnsureFactionsLookupLoaded(void);
```

## Behavioral summary (asm-sealed)

1. SEH; `FUN_0051d290(4)` ECX=`0x00b04314`.
2. DB enter `FUN_007e1d80` / load `FUN_007ce550` / leave `FUN_007b7df0` with ECX=`*[0x00b0469c]`.
3. Status `<0` → `VOG_DEBUG_STOP`.
4. Walk temp vector stride **`0xc4`**: new **100**-byte record; WCMAP two strings; `FUN_0051e5d0(id, rec, 0)` ECX=hash.
5. Free temp; restore SEH; return.

## Globals

| VA | Role |
|---|---|
| `0x00b04314` | Faction CNDHash host |
| `0x00b0431c` | hash mask (lookup) |
| `0x00b04320` | count/ready (lazy gate in `FUN_0051a120`) |
| `0x00b04324` | bucket table |
| `0x00b0469c` | DB reader ctx pointer |
| `0x00a15844` | `"VOG_DEBUG_STOP"` |

## Callers / callees

**Callers:** `FUN_0094a6a0` InitInstance (`0094afc2`), `FUN_0051a120` (`0051a132`).  
**Callees:** see dual report / review A.

## Artifacts

- Raw / annotated / clean / A/B reviews — see dual report  
- Dual report: `docs/agents/task-dual-ab-005194f0-005197b0-wq9rf-report.md`

## Confidence

| Claim | Level |
|---|---|
| Ensure-load control flow | **High** |
| Table = tFactions via loader xpath | **High** |
| Column English for two strings | Medium / open |
