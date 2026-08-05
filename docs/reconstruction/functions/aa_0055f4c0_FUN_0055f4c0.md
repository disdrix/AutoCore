# Function record: LocalWorklist_Release_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055f4c0` |
| **Canonical name** | `LocalWorklist_Release_Inferred` |
| **Ghidra name** | `FUN_0055f4c0` |
| **Address** | `0x0055f4c0`–`0x0055f51b` (**92 B** / `0x5C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | allocator / local worklist teardown |
| **Completion status** | **Dual sealed** (W27-N 2026-07-29) — A/B accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_0055f4c0`
- Prior scaffold alias: `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0055f4c0` (auto path name; superseded for dual)

## Purpose

Release a **local worklist / stack alloc descriptor** via global allocator `DAT_00b05060`: return or free the slab (`vtbl+0x28` vs arena bump), then optional tagged free (`vtbl+0x14`, tag `0x12`) when `desc[+8] >= 0`. Teardown twin always paired with bind/unbind manager helpers.

## Signature (machine)

```c
// __fastcall/thiscall; ECX = desc; ret 0; void
void LocalWorklist_Release_Inferred(std::uint32_t *desc);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0055f4c0_FUN_0055f4c0.md` (+ W27-N append)
- Annotated: `docs/reconstruction/raw/aa_0055f4c0_FUN_0055f4c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/LocalWorklist_Release_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0055f4c0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0055f4c0_LocalWorklist_Release_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0055f4c0_LocalWorklist_Release_Inferred.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (5 / 8 xrefs) | `FUN_0055fa40`×2, `FUN_0055fbf0`×2, `FUN_0055ff20`, `FUN_00560020`, `FUN_00634450`×2 |
| Callees | `DAT_00b05060` vtable +0x28, +0x14 only |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ live | **High** |
| ABI ECX-only / `ret` | **High** |
| Aligned size formula | **High** |
| Tag free mask `0x7fffffff` | **High** (machine) |
| Role as bind/unbind teardown | **High** (caller duals) |
| Allocator product English | **Tentative** |
| Runtime / bit-exact | **Open** |
