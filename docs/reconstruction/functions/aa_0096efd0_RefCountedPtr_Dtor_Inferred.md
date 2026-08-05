# Function record: RefCountedPtr_Dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096efd0` |
| **Canonical name** | `RefCountedPtr_Dtor_Inferred` |
| **Address** | `0x0096efd0`–`0x0096f03a` (**107 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared util — refcounted handle destructor |
| **Completion status** | **Dual A/B sealed** (W38-P, 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Ghidra name** | `FUN_0096efd0` |
| **Rejected alias** | `Named_CalleeOf_CVOGTacArc_dtor_helper_0096efd0` |

## Purpose

Release a 4-byte refcounted handle: decrement payload refcount at `+8`; on zero invoke release at iface `+4` vtbl+8 (this = payload+4); null the handle. MSVC SEH-wrapped; peer of `RefCountedPtr_DefaultCtor_Inferred` (`0x0096ef70`, W25-N).

## Signature

```c
// __thiscall / __fastcall; ECX = handle*; no stack formals; ret
void RefCountedPtr_Dtor_Inferred(void** self /*ECX*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0096efd0_FUN_0096efd0.md`
- Annotated: `docs/reconstruction/raw/aa_0096efd0_FUN_0096efd0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/RefCountedPtr_Dtor_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0096efd0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0096efd0_RefCountedPtr_Dtor_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0096efd0_RefCountedPtr_Dtor_Inferred.md`
- Function twin: `docs/reconstruction/functions/aa_0096efd0_FUN_0096efd0.md`

## Callers / callees

- **Callees:** virtual release only (no direct FUN_*).
- **Callers:** 100+ xrefs — CVOGTacArc_dtor_helper, GfxView teardown, stack temps after texture bind, many `Unwind@*` EH registrations. Thunk twin `thunk_FUN_0096efd0` @ `0x004434c0`.

## Confidence

| Claim | Level |
|---|---|
| Body 107 B / `ret` | Confirmed |
| ECX = handle* | Confirmed |
| rc@+8, iface@+4, vtbl+8 release | Confirmed |
| SEH dual-shape | Confirmed |
| Product payload English | Open |
