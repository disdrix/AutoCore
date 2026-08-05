# Function record: FUN_0096efd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096efd0` |
| **Canonical name** | `RefCountedPtr_Dtor_Inferred` (was `FUN_0096efd0`) |
| **Address** | `0x0096efd0`–`0x0096f03a` (**107 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared util — refcounted handle destructor |
| **Completion status** | **Dual A/B sealed** (W38-P, 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Canonical: `RefCountedPtr_Dtor_Inferred`
- **Rejected:** `Named_CalleeOf_CVOGTacArc_dtor_helper_0096efd0`

## Purpose

SEH-wrapped refcounted handle destructor. Peer of `RefCountedPtr_DefaultCtor_Inferred` (`0x0096ef70`).

## Signature

```c
void __fastcall FUN_0096efd0(void** self /*ECX*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0096efd0_FUN_0096efd0.md`
- Annotated: `docs/reconstruction/raw/aa_0096efd0_FUN_0096efd0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/RefCountedPtr_Dtor_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0096efd0.cpp`
- Named record: `docs/reconstruction/functions/aa_0096efd0_RefCountedPtr_Dtor_Inferred.md`
- Reviews: `A_` / `B_aa_0096efd0_RefCountedPtr_Dtor_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow + ABI from bytes | Confirmed |
| Product payload type name | Open |
