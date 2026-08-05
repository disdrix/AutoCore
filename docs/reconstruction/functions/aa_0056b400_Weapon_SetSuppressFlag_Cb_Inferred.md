# Function record: Weapon_SetSuppressFlag_Cb_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056b400` |
| **Canonical name** | `Weapon_SetSuppressFlag_Cb_Inferred` |
| **Address** | `0x0056b400` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | combat / weapon flags |
| **Ghidra symbol** | `FUN_0056b400` |
| **Completion status** | **Dual A/B present** (2026-07-29 OWN-ONLY nested residual) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Set `weapon+0xCB`; non-zero zeros f32 `+0xD8`; zero optionally `CVOGTacArc_UpdateMesh` via `+0xC0`. Distinct from fire pair `+0xC7/+0xC8`. Cleared on ActivateEnterWorld hardpoint loop.

## Signature

```c
void __thiscall Weapon_SetSuppressFlag_Cb_Inferred(Weapon* w, unsigned char value); // RET 4
```

## Artifacts

- Raw / annotated / clean: `raw/aa_0056b400_*`, `reconstructed-exact/FUN_0056b400.cpp`
- Dual A/B: `reviews/A_aa_0056b400_Weapon_SetSuppressFlag_Cb_Inferred.md`, `B_aa_0056b400_*`
- Legacy: `functions/aa_0056b400_FUN_0056b400.md`

## Callers / callees

| Direction | Target |
|---|---|
| Caller | `Vehicle_ActivateEnterWorld`, `FUN_004f4eb0`, `FUN_005fe6a0` |
| Callee | `CVOGTacArc_UpdateMesh` (clear path only) |

## Confidence

| Claim | Level |
|---|---|
| +0xCB / branch CF | High |
| Product “suppress” English | Probable |
