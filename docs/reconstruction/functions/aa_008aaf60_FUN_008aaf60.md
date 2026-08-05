# Function record: FUN_008aaf60

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aaf60` |
| **Canonical name** | `FUN_008aaf60` |
| **Inferred name** | `Client_MissionDialog_SetHeaderCaption_Inferred` |
| **Address** | `0x008aaf60`–`0x008ab098` (312 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Completion status** | **Dual sealed 2026-08-04 (WQ7R-A)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (`terminal_coverage=false`) |

## Purpose

Set/clear mission dialog header caption widget at `dialog+0x6e0`. EDI=0 clears; else resolve string, optional format, apply chrome, layout, conditional show. Common tail `vtbl+0x214(0)` + `FUN_008aa610`.

## Signature

```c
// ECX = dialog context; EDI = caption key (0 clear)
void FUN_008aaf60(void); // Ghidra; true register contract above
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008aaf60_FUN_008aaf60.md`
- Annotated: `docs/reconstruction/raw/aa_008aaf60_FUN_008aaf60.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_MissionDialog_SetHeaderCaption_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_008aaf60.cpp`
- Named record: `docs/reconstruction/functions/aa_008aaf60_Client_MissionDialog_SetHeaderCaption_Inferred.md`
- Dual A/B: `reviews/A_aa_008aaf60_Client_MissionDialog_SetHeaderCaption_Inferred.md`, `reviews/B_aa_008aaf60_Client_MissionDialog_SetHeaderCaption_Inferred.md`

## Callers / callees

| Direction | Target |
|-----------|--------|
| Callers | `Client_ShowNpcMissionDialogUI` (×3), `Client_UpdateMissionJournal` (×2), `FUN_0093e450` (×1) |
| Callees | `FUN_007a69d0`, `FUN_007a6de0`, `std::string` ctor/dtor, `FUN_005465c0`, `FUN_008aab00`, `FUN_008aa610`, widget vcalls |

## Confidence

| Claim | Level |
|---|---|
| ECX dialog + EDI caption key + widget `+0x6e0` CF | High (Confirmed) |
| vtbl `+0x1d8` args (0,1,1) | High (Confirmed via bytes) |
| Nested callee semantics | Open (other OWN) |
| Product widget/vtable English | Open → `_Inferred` |
