# Function record: EnvSlot_SetActiveBumpGen

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074e200` |
| **Canonical name** | `EnvSlot_SetActiveBumpGen` (**Inferred** structural) |
| **Ghidra name** | `FUN_0074e200` |
| **Address** | `0x0074e200` |
| **Body** | `0x0074e200`–`0x0074e23c` (**61 B** / `0x3D`); pad `CC`; next `FUN_0074e240` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / env-slot active publish |
| **Completion status** | **Dual-reviewed** W31-Q — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Leaf thiscall helper on the env-slot object published as `DAT_00d1a54c`: if `*(slot+0x3c)` (related object) is non-null, always increment generation/dirty counter at `related+0xdc`, then set active flag at `related+0xd1` to 1 only when `enable != 0` **and** global gate `*(DAT_00d1f048+0x0f) != 0`; otherwise clear the flag to 0.

## Signature

```c
// ECX = slot; stack char enable; RET 4; void; leaf
void __thiscall EnvSlot_SetActiveBumpGen(void* slot, char enable);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | sole static `FUN_004cda90` (`Client_InitPalantirViewBundle_Inferred`) @ `0x004cdc0a` (enable=0 on old `DAT_00d1a54c`) and `0x004cdc17` (enable=1 on `*(env+4)`) |
| Callees | none (leaf) |
| Sibling | `FUN_00442b90` — combined disable/enable + global store (not owned) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0074e200_FUN_0074e200.md`
- Annotated: `docs/reconstruction/raw/aa_0074e200_FUN_0074e200.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/EnvSlot_SetActiveBumpGen.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0074e200.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0074e200_EnvSlot_SetActiveBumpGen.md`
- Review B: `docs/reconstruction/reviews/B_aa_0074e200_EnvSlot_SetActiveBumpGen.md`
- Scaffold record: `docs/reconstruction/functions/aa_0074e200_FUN_0074e200.md`
- Scratch: `docs/reconstruction/tmp/a_0074e200.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes ≡ decompile) | **High** |
| ABI ECX + stack enable + RET 4 | **High** (caller bytes) |
| Offsets +0x3c / +0xdc / +0xd1 / gate +0xf | **High** |
| Role = enable toggle during DAT_00d1a54c publish | **High** (caller) |
| Product class / gen-counter English | **Low** |
