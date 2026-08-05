# Function record: IdvFileError_Ctor_MsgBracketErrno

| Field | Value |
|---|---|
| **Stable ID** | `aa_006874b0` |
| **Canonical name** | `IdvFileError_Ctor_MsgBracketErrno` |
| **Prior scaffold** | `FUN_006874b0` |
| **Rejected misname** | `Named_CalleeOf_*_006874b0` |
| **Address** | `0x006874b0`–`0x00687624` (**372 B** / `0x174`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | SpeedTree / IDV file exception (`IdvFileError`) |
| **Completion status** | **Dual reviewed** — trio + A/B **accept** (2026-07-29 W34-B) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC **`IdvFileError`** constructor used by SpeedTree SPT parse throw sites. Builds message `msg + " [" + (include_errno ? strerror(*errno()) : "") + "]"`, constructs base exception+string via `FUN_00685b40`, installs IdvFileError vtbl `PTR_FUN_009ead64`. Callers then `_CxxThrowException(..., DAT_00ac9e00)`.

## Signature

```c
// __thiscall; RET 8; returns this
// RTTI: .?AVIdvFileError@@
IdvFileError* __thiscall IdvFileError_Ctor_MsgBracketErrno(
    IdvFileError* this,
    const std::string* msg,
    char include_errno);
```

| Item | Value |
|---|---|
| Final vtbl | `PTR_FUN_009ead64` (`FUN_00687630` scalar-dtor, `0x004018e0`) |
| Base ctor | `FUN_00685b40` → intermediate vtbl `PTR_FUN_009ea778` + string @ `this+0x0c` |
| ThrowInfo | `DAT_00ac9e00` |
| Catchables | IdvFileError → `std::runtime_error` → `exception` (size **0x28**) |
| Bracket literals | `DAT_009ead6c` = `" ["`; `DAT_00a62c94` = `"]"` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006874b0_FUN_006874b0.md`
- Annotated: `docs/reconstruction/raw/aa_006874b0_FUN_006874b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/IdvFileError_Ctor_MsgBracketErrno.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_006874b0.cpp`
- Function scaffold: `docs/reconstruction/functions/aa_006874b0_FUN_006874b0.md`
- Dual A: `docs/reconstruction/reviews/A_aa_006874b0_IdvFileError_Ctor_MsgBracketErrno.md`
- Dual B: `docs/reconstruction/reviews/B_aa_006874b0_IdvFileError_Ctor_MsgBracketErrno.md`
- Scratch: `docs/reconstruction/tmp/a_006874b0.md`
- Report: `docs/agents/task-dual-ab-006874b0-009698a0-w34b-report.md`

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Callees | `FUN_00685b40`, `FUN_00416490`, `FUN_00416410`, `_errno`, `strerror`, `basic_string` ctor/dtor | message assemble + base |
| Callers | 20+ SpeedTree parse workers (47 xrefs) e.g. `FUN_00687e40` | string → ctor(flag) → `_CxxThrowException` |
| Related | `FUN_00687630` | scalar-deleting dtor (vtbl[0]) |

## Confidence

| Claim | Level |
|---|---|
| Control flow / message build | **Confirmed** |
| `__thiscall` + `RET 8` | **Confirmed** |
| RTTI `IdvFileError` + ThrowInfo | **Confirmed** |
| Base via `FUN_00685b40` + string @ +0x0c | **Confirmed** |
| Product field English beyond message | **Tentative** |
| Runtime / bit-exact | **Open** |
