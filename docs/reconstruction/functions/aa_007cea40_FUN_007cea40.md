# Function record: FUN_007cea40

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cea40` |
| **Canonical name** | `FUN_007cea40` |
| **Address** | `0x007cea40` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Dual A/B present** (2026-07-29) — structural; see named record |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

Human name: **`DbReader_LoadTAchievementRows_Inferred`**. Prior: `Named_tAchievement` (`//tAchievement/row`).

Named record: `functions/aa_007cea40_DbReader_LoadTAchievementRows_Inferred.md`  
Dual: `reviews/A_aa_007cea40_DbReader_LoadTAchievementRows_Inferred.md` / `B_aa_*`

## Alias_prev

Human name: `Named_CalleeOf_Named_VOG_DEBUG_STOP_007cea40` (callee of `Named_VOG_DEBUG_STOP`)

## Purpose

Load tAchievement rows (elem 0x3d4) via DbReader ctx `*[DAT_00b0469c]` for medal table ensure.

## Signature (decompiler-derived)

```c
/* WARNING: Removing unreachable block (ram,0x007cefed) */
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007cea40_FUN_007cea40.md`
- Annotated: `docs/reconstruction/raw/aa_007cea40_FUN_007cea40.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_007cea40.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
