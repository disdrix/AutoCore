# Function record: QuickBar_RebindPageColumns_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a0e10` |
| **Canonical name** | `QuickBar_RebindPageColumns_Inferred` |
| **Address** | `0x008a0e10` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **Human-refined plate** — Purpose/CF/offsets; dual reviews present; runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

For the QuickBar dialog host, if the host virtual at vtbl+0x3d8 succeeds and `DAT_00d1b6d8 != 0`, prepare UI context (`FUN_007fce10(&DAT_00d1a840)`) then rebind each of 10 column widgets from `DAT_00d1da60[page*10+col]` (stride 0x18): type 1 skill / 2 item / 5 macro / else clear. Page is `host+0x50c`. Does not select page or activate slots.

## Signature (behavior)

```c
void __stdcall QuickBar_RebindPageColumns_Inferred(int *host);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008a0e10_FUN_008a0e10.md`
- Annotated: `docs/reconstruction/raw/aa_008a0e10_FUN_008a0e10.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/QuickBar_RebindPageColumns_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_008a0e10.cpp`
- Dual reviews:
  - `docs/reconstruction/reviews/A_aa_008a0e10_QuickBar_RebindPageColumns_Inferred.md`
  - `docs/reconstruction/reviews/B_aa_008a0e10_QuickBar_RebindPageColumns_Inferred.md`

## Callers / callees

- Callees: type binders + clear + `FUN_007fce10`
- Callers: SelectPage, CreateChildWidgets, create-character refresh, `FUN_008a1280`

## Confidence

| Claim | Level |
|---|---|
| Rebind (not SelectPage / Activate) | High |
| Type table stride 0x18 | High |
| Page/widget offsets | High |
| Product English name | Inferred |
