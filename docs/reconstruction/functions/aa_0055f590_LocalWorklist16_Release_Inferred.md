# Function record: LocalWorklist16_Release_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055f590` |
| **Canonical name** | `LocalWorklist16_Release_Inferred` |
| **Ghidra name** | `FUN_0055f590` |
| **Address** | `0x0055f590`–`0x0055f5e7` (**88 B** / `0x58`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | allocator / local worklist teardown (stride 0x10) |
| **Completion status** | **Dual sealed** (W28-R 2026-07-29) — A/B accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_0055f590`
- Prior scaffold alias: `Named_CalleeOf_..._CVO_0055f590` (auto path name; superseded for dual)

## Purpose

Release a **local worklist / stack alloc descriptor** (element stride **0x10**) via global allocator `DAT_00b05060`: return or free the slab (`vtbl+0x28` vs arena bump), then optional tagged free (`vtbl+0x14`, tag `0x12`) when `desc[+8] >= 0`. Teardown twin of `LocalWorklist16_Init_Inferred`; always paired on `Phys_CommitPairListStorage` path. Sibling of stride-8 `LocalWorklist_Release_Inferred` (`0x0055f4c0`).

## Signature (machine)

```c
// __fastcall/thiscall; ECX = desc; ret 0; void
void LocalWorklist16_Release_Inferred(uint32_t *desc);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0055f590_FUN_0055f590.md` (+ W28-R append)
- Annotated: `docs/reconstruction/raw/aa_0055f590_FUN_0055f590.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/LocalWorklist16_Release_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0055f590.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0055f590_LocalWorklist16_Release_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0055f590_LocalWorklist16_Release_Inferred.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (1) | `FUN_006297e0` |
| Callees | `DAT_00b05060` vtable +0x28, +0x14 only |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ live | **High** |
| ABI ECX-only / `ret` | **High** |
| Aligned size formula | **High** |
| Tag free mask `0x7fffffff` | **High** (machine) |
| Role as pair-list teardown | **High** (caller dual) |
| Allocator product English | **Tentative** |
| Runtime / bit-exact | **Open** |
