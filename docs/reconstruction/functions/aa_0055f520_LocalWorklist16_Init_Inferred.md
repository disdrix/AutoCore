# Function record: LocalWorklist16_Init_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055f520` |
| **Canonical name** | `LocalWorklist16_Init_Inferred` |
| **Ghidra name** | `FUN_0055f520` |
| **Address** | `0x0055f520`–`0x0055f588` (**105 B** / `0x69`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | allocator / local worklist init (stride 0x10) |
| **Completion status** | **Dual sealed** (W28-R 2026-07-29) — A/B accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_0055f520`
- Prior scaffold alias: `Named_CalleeOf_..._CVO_0055f520` (auto path name; superseded for dual)

## Purpose

Initialize a **local worklist descriptor** for **stride-16** elements against `DAT_00b05060`: arena bump or `vtbl+0x24` slab alloc, stamp count with high bit set so release skips tag free. Prep twin always paired with `LocalWorklist16_Release_Inferred` on `Phys_CommitPairListStorage` path.

## Signature (machine)

```c
// thiscall; ECX = desc; stack = count; ret 4; returns desc
int * LocalWorklist16_Init_Inferred(int *desc, unsigned count);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0055f520_FUN_0055f520.md` (+ W28-R append)
- Annotated: `docs/reconstruction/raw/aa_0055f520_FUN_0055f520.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/LocalWorklist16_Init_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0055f520.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0055f520_LocalWorklist16_Init_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0055f520_LocalWorklist16_Init_Inferred.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (2) | `FUN_006297e0`, `FUN_00560750` |
| Callees | `DAT_00b05060` vtable `+0x24` only |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ live | **High** |
| ABI thiscall / `ret 4` | **High** |
| Stride / high-bit contract | **High** |
| Align16 size | **High** (machine) |
| Allocator product English | **Tentative** |
| Runtime / bit-exact | **Open** |
