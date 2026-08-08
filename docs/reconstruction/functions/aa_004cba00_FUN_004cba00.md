# Function record: FUN_004cba00

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cba00` |
| **Canonical name** | `FUN_004cba00` |
| **Address** | `0x004cba00`–`0x004cba51` (**82 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL map find residual |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** (WQ9G-G) |
| **Bit-for-bit / runtime / diff** | Open |
| **Last reviewed** | `2026-08-04` |

## Alias

- Primary named: `StdMap_Find_Tfid_Isnil29_Inferred`
- Scaffold (reject product): `Named_CalleeOf_Named_VOG_DEBUG_STOP_004cba00`

## Purpose

MSVC map::find over TFID-shaped keys: lower_bound (`004cb4b0`) + equality gate; write node or head to `*outIt`.

## Signature (sealed)

```c
void __thiscall FUN_004cba00(Map* self, Node** outIt, const KeyU32I32* pKey);
// RET 8
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cba00_FUN_004cba00.md`
- Annotated: `docs/reconstruction/raw/aa_004cba00_FUN_004cba00.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004cba00.cpp`
- Named clean: `docs/reconstruction/reconstructed-exact/StdMap_Find_Tfid_Isnil29_Inferred.cpp`
- Dual A/B: `A_aa_004cba00_StdMap_Find_Tfid_Isnil29_Inferred.md`, `B_aa_004cba00_StdMap_Find_Tfid_Isnil29_Inferred.md`
- Named record: `aa_004cba00_StdMap_Find_Tfid_Isnil29_Inferred.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_004ea350` (×3), `FUN_00807550`, site `0x005dd84d` |
| Callees | `StdMap_LowerBound_Tfid_Isnil29` (`0x004cb4b0`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow | High |
| ABI RET 8 thiscall | High |
| Parameter semantic names | High (map/out/key); product type Tentative |
| Types | Tentative (payload @+0x20 open) |
