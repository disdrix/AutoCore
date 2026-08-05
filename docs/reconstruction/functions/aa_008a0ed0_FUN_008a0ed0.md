# Function record: FUN_008a0ed0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a0ed0` |
| **Canonical name** | `FUN_008a0ed0` → dual: **`QuickBar_SelectPage_Inferred`** |
| **Address** | `0x008a0ed0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **Dual A/B complete 2026-07-29** — accept-with-gaps (supersedes partial scaffold) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Dual: `QuickBar_SelectPage_Inferred` — see `functions/aa_008a0ed0_QuickBar_SelectPage_Inferred.md`
- Prior scaffold: `Named_CalleeOf_Client_QuickBar_ActivateSlot_008a0ed0`

## Purpose

Select QuickBar page 0..9: store at host `+0x50c`, rebind 10 column widgets, restore/auto-pick column, refresh chrome. Client UI only.

## Signature (decompiler-derived)

```c
void __fastcall FUN_008a0ed0(int *param_1)  // page in EAX
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008a0ed0_FUN_008a0ed0.md`
- Annotated: `docs/reconstruction/raw/aa_008a0ed0_FUN_008a0ed0.annotated.md`
- Clean (dual): `docs/reconstruction/reconstructed-exact/QuickBar_SelectPage_Inferred.cpp`
- Clean (scaffold): `docs/reconstruction/reconstructed-exact/FUN_008a0ed0.cpp`
- Dual A/B: `reviews/A_aa_008a0ed0_QuickBar_SelectPage_Inferred.md`, `B_*`

## Callers / callees

**Callers:** `Client_QuickBar_ActivateSlot` (mode 1), `FUN_008a0fb0`, `FUN_008a0fe0`, `FUN_009114f0`, `Client_SkillTrainUiRequest_INFERRED`.

**Callees:** `FUN_008a0e10`, `FUN_00826780`, `FUN_008a0210`, host vtbls.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| Role = page select | **High** |
| Product name | **Inferred** |
