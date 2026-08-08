# Function record: Std_OutOfRange_CtorFromString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401bc0` |
| **Canonical name** | `Std_OutOfRange_CtorFromString` |
| **Prior scaffold** | `FUN_00401bc0` |
| **Rejected misname** | `Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect_00401bc0` (xref-seed false) |
| **Address** | `0x00401bc0`–`0x00401c10` inclusive (**81 B** / `0x51`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC STL / `std::out_of_range` |
| **Agent** | WQ9L-B OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept** — RTTI/ABI/CF sealed) |
| **Terminal** | **false** (runtime open) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC **`std::out_of_range`** constructor from `std::string const&`. Installs EH frame, constructs base **`std::logic_error`** via `FUN_00401aa0` (embeds message string at `this+0x0c`), then sets out_of_range vftable `PTR_FUN_009c7640`. Used by map/set erase and peer tree helpers that throw on nil iterator (`"invalid map/set<T> iterator"`) with ThrowInfo `DAT_00acc34c`.

```text
Std_OutOfRange_CtorFromString(this, msg) -> this
  SEH install (LAB_009bc828)
  logic_error(msg)            // FUN_00401aa0
  this->vtbl = out_of_range   // PTR_FUN_009c7640
  return this
```

## Signature (decompiler + bytes + RTTI)

```c
// __thiscall; RET 4
// RTTI: .?AVout_of_range@std@@
std::out_of_range* __thiscall Std_OutOfRange_CtorFromString(
    std::out_of_range* this,
    const std::string* msg);
```

| Item | Value |
|---|---|
| Vtbl | `PTR_FUN_009c7640` |
| Base ctor | `FUN_00401aa0` → logic_error / vtbl `009c7628` |
| ThrowInfo | `DAT_00acc34c` (catchables: out_of_range, logic_error, exception) |
| Object size (CatchableType) | `0x28` |
| Shared message | `"invalid map/set<T> iterator"` @ `0x00a152f0` |

## Artifacts

- Raw scaffold + re-verify: `docs/reconstruction/raw/aa_00401bc0_FUN_00401bc0.md`
- Annotated: `docs/reconstruction/raw/aa_00401bc0_FUN_00401bc0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Std_OutOfRange_CtorFromString.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00401bc0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00401bc0_Std_OutOfRange_CtorFromString.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00401bc0_Std_OutOfRange_CtorFromString.md`
- Report: `docs/agents/task-dual-ab-00401bc0-00403e90-wq9lb-report.md`

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Callee | `FUN_00401aa0` | `logic_error(string)` |
| Callers | **25** UNCONDITIONAL_CALL | map/set erase/insert nil-iterator path |
| Sample | dualed `StdTree_EraseAndRebalance_Isnil31_Inferred` `0x00408ed0` @ `0x00408f17` | string → this → `_CxxThrowException(..., DAT_00acc34c)` |
| Twin | `Std_LengthError_CtorFromString` `0x00401a40` | same base; vtbl `009c7634`; ThrowInfo `acc388` |

## Confidence

| Claim | Level |
|---|---|
| Control flow | **Confirmed** |
| `__thiscall` + `RET 4` | **Confirmed** |
| RTTI `std::out_of_range` | **Confirmed** |
| Base = logic_error via `FUN_00401aa0` | **Confirmed** |
| Role vs skill-seed misname | **Confirmed reject misname** |
| Full vtable method English | **Tentative** |
