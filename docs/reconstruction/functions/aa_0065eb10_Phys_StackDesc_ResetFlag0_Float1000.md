# Function record: `Phys_StackDesc_ResetFlag0_Float1000`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0065eb10` |
| **Canonical name** | `Phys_StackDesc_ResetFlag0_Float1000` (**Inferred**) |
| **Ghidra name** | `FUN_0065eb10` |
| **Address** | `0x0065eb10` |
| **Body** | `0065eb10`–`0065eb22` (19 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `physics` / Havok stack or CCS descriptor |
| **Completion status** | **Dual A/B sealed 2026-07-29 (W25-O)** — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Ghidra / scaffold: `FUN_0065eb10`
- Prior partial scaffold only (no dual)

## Purpose

Leaf: `*desc = 0`; `*(float*)(desc+4) = 1000.0f` from `DAT_00a0f520`. Post-ctor stack-descriptor teardown and chassis optional CCS reset.

## Signature

```c
void __fastcall Phys_StackDesc_ResetFlag0_Float1000(uint8_t *desc);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0065eb10_FUN_0065eb10.md` |
| Annotated | `docs/reconstruction/raw/aa_0065eb10_FUN_0065eb10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phys_StackDesc_ResetFlag0_Float1000.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0065eb10.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0065eb10_FUN_0065eb10.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0065eb10_Phys_StackDesc_ResetFlag0_Float1000.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0065eb10_Phys_StackDesc_ResetFlag0_Float1000.md` |

## Callers / callees

**Callees:** none

**Callers:** `FUN_0064fe40` @ `0x0064fe40`; `hkDefaultChassis_vtbl_0x18` @ `0x0064feb0`

## Confidence

| Claim | Level |
|---|---|
| CF + constant | **Confirmed** |
| Inferred English name | **Probable** |
| Product symbol | **Open** |
