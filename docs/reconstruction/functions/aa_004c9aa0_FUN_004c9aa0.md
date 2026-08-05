# Function record: FUN_004c9aa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c9aa0` |
| **Canonical name** | `CVOGCreature_ctor` (Ghidra `FUN_004c9aa0`) |
| **Address** | `0x004c9aa0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | creature runtime / world object factory |
| **Completion status** | **Dual-sealed 2026-07-29 W21-F** — see named record |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `CVOGCreature_ctor` (**preferred**)
- `Named_CalleeOf_CVOGReaction_GiveItemByCbid_004c9aa0` (prior xref seed; incomplete — multi-caller)

## Purpose

CVOGCreature constructor (most-derived flag, parent base, vtbls, field defaults, map head, 0x60 subobject). Heap size **0x690** when most-derived.

## Signature

```c
uint32_t* __thiscall FUN_004c9aa0(uint32_t* self, int mostDerivedFlag);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c9aa0_FUN_004c9aa0.md`
- Annotated: `docs/reconstruction/raw/aa_004c9aa0_FUN_004c9aa0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGCreature_ctor.cpp`
- Named record: `docs/reconstruction/functions/aa_004c9aa0_CVOGCreature_ctor.md`
- Reviews: `A|B_aa_004c9aa0_CVOGCreature_ctor.md`

## Callers / callees

See named record (8 call sites; callees `00518940`, `005c82a0`, `0058d9c0`, `0096e0e0`, `005d55f0`).

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + image | **High** |
| Parameter semantic names | **High** (this + mostDerivedFlag) |
| Types / field English | **Tentative** / **Open** |
