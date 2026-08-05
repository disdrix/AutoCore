# Function record: QuickBar_SelectPage_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a0ed0` |
| **Canonical name** | `QuickBar_SelectPage_Inferred` (Ghidra still `FUN_008a0ed0` until registry rename) |
| **Address** | `0x008a0ed0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **Dual A/B complete** (2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Notes |
|---|---|
| `FUN_008a0ed0` | Ghidra default |
| `Named_CalleeOf_Client_QuickBar_ActivateSlot_008a0ed0` | Prior scaffold alias (mode-1 parent) |
| `QuickBar_SelectPage_Inferred` | Dual residual name (no product string) |

## Purpose

Select QuickBar page 0..9 on the QB dialog host: store page at `+0x50c`, stamp/deactivate 10 column widgets, rebind page contents, restore or auto-pick remembered column, clear hover residual, refresh chrome. Client UI only — no network.

## Signature (decompiler-derived + dual)

```c
// ECX = host (CDlgQuickBar* Probable); EAX = page index
void __fastcall QuickBar_SelectPage_Inferred(int *host);
// page accepted only if 0 <= EAX <= 9
```

## Layout (host / column widget)

| Location | Field |
|---|---|
| host `+0x50c` (`[0x143]`) | Current page (i32) |
| host `+0x63c` (`[399]` × 10) | Column widget pointers |
| `DAT_00d1da38[page]` | Last selected column on page (i32; -1 = none) |
| `DAT_00d1a9fc` | Residual hover column index (−1 clear) |
| widget `+0x4fc` | Selected/active flag (u8) |
| widget `+0x500` | Column index (written into `DAT_00d1da38` on activate) |
| widget `+0x504` | Page stamp |
| widget `+0x550` / `+0x554` | Dual-dword empty mask (`& == -1` → empty) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008a0ed0_FUN_008a0ed0.md`
- Annotated: `docs/reconstruction/raw/aa_008a0ed0_FUN_008a0ed0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/QuickBar_SelectPage_Inferred.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_008a0ed0_QuickBar_SelectPage_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_008a0ed0_QuickBar_SelectPage_Inferred.md`
- Scratch: `tmp/a_008a0ed0.md`

## Callers / callees

**Callers:** `Client_QuickBar_ActivateSlot` (mode 1), `FUN_008a0fb0`, `FUN_008a0fe0`, `FUN_009114f0`, `Client_SkillTrainUiRequest_INFERRED`.

**Callees:** `FUN_008a0e10` (rebind page widgets), `FUN_00826780` (column activate/deactivate), `FUN_008a0210` (auto-pick column), host vtbl `+0x448` / `+0x34c`, optional column vtbl `+0x44c`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| Role = page select | **High** |
| Page @ `+0x50c`; 10 cols @ `+0x63c` | **High** |
| Product symbol | **Inferred** |
| Bit-for-bit / runtime | Open |
