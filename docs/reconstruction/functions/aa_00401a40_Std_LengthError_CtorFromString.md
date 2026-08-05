# Function record: Std_LengthError_CtorFromString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401a40` |
| **Canonical name** | `Std_LengthError_CtorFromString` |
| **Prior scaffold** | `FUN_00401a40` |
| **Rejected misname** | `Named_CalleeOf_Named_CalleeOf_Auth_AuthServer_00401a40` (xref-seed false) |
| **Address** | `0x00401a40`–`0x00401a90` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC STL / `std::length_error` |
| **Completion status** | **Dual reviewed** — three-rep present; A/B sealed **accept** (2026-07-29 W20-L) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC **`std::length_error`** constructor from `std::string const&`. Installs EH frame, constructs base **`std::logic_error`** via `FUN_00401aa0` (embeds message string at `this+0x0c`), then sets length_error vftable `PTR_FUN_009c7634`. Used by 50+ STL “too long” throw sites (`StdVector_ThrowTooLong`, map/set insert, …) with ThrowInfo `DAT_00acc388`.

## Signature (decompiler + bytes + RTTI)

```c
// __thiscall; RET 4
// RTTI: .?AVlength_error@std@@
std::length_error* __thiscall Std_LengthError_CtorFromString(
    std::length_error* this,
    const std::string* msg);
```

| Item | Value |
|---|---|
| Vtbl | `PTR_FUN_009c7634` |
| Base ctor | `FUN_00401aa0` → logic_error / vtbl `009c7628` |
| ThrowInfo | `DAT_00acc388` (catchables: length_error, logic_error, exception) |
| Object size (CatchableType) | `0x28` |

## Artifacts

- Raw scaffold + re-verify: `docs/reconstruction/raw/aa_00401a40_FUN_00401a40.md`
- Raw named: `docs/reconstruction/raw/aa_00401a40_Std_LengthError_CtorFromString.md`
- Annotated named: `docs/reconstruction/raw/aa_00401a40_Std_LengthError_CtorFromString.annotated.md`
- Annotated scaffold: `docs/reconstruction/raw/aa_00401a40_FUN_00401a40.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Std_LengthError_CtorFromString.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00401a40.cpp`
- False-name plate: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Auth_AuthServer_00401a40.cpp` (superseded)
- Dual A: `docs/reconstruction/reviews/A_aa_00401a40_Std_LengthError_CtorFromString.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00401a40_Std_LengthError_CtorFromString.md`

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Callee | `FUN_00401aa0` | `logic_error(string)` |
| Callers (sample) | `StdVector_ThrowTooLong` `0x004540b0`, `FUN_00401580` (map/set too long), `FUN_00401db0`, 50+ | all: string → this ctor → `_CxxThrowException(..., DAT_00acc388)` |
| Related | `FUN_00401880` | length_error dtor/unwind |
| Related | `FUN_00401970` | same vtbl install (copy-like) |

## Confidence

| Claim | Level |
|---|---|
| Control flow | **Confirmed** |
| `__thiscall` + `RET 4` | **Confirmed** |
| RTTI `std::length_error` | **Confirmed** |
| Base = logic_error via `FUN_00401aa0` | **Confirmed** |
| Role vs Auth-seed misname | **Confirmed reject misname** |
| Full vtable method English | **Tentative** |
