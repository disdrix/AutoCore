# Function record: StdVector_UninitializedCopy_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431430` |
| **Canonical name** | `StdVector_UninitializedCopy_BasicString` (**Inferred** structural) |
| **Ghidra name** | `FUN_00431430` |
| **Address** | `0x00431430` |
| **Body** | `0x00431430`–`0x00431450` exclusive (**32 B** / `0x20`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<basic_string<char>>` uninitialized copy (thin thiscall rebind) |
| **Completion status** | **Dual-reviewed** W33-H — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Thin **thiscall** wrapper: forward vector + `[first,last)` + `dest` into `FUN_0046a2c0` (string placement copy-ctor range / MSVC-style `_Ucopy`). Returns end of constructed dest range. Used by in-place arms of `StdVector_InsertN_BasicString`.

## Signature

```c
// ECX = vector*; stack first*, last*, dest*; RET 0x0C
// returns dest_end (EAX)
BasicString_0x1c* __thiscall StdVector_UninitializedCopy_BasicString(
    VectorBasicString* vec,
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest);
```

| Formal | Source | Conf |
|---|---|---|
| vec | ECX (this) | **High** |
| first / last / dest | stack; `RET 0x0C` | **High** |
| forward to `FUN_0046a2c0` | relative call + `ADD ESP,0x14` | **High** |
| EAX return | use-site in insert; no EAX clobber | **High** |
| string stride 0x1c | callee + parent insert | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `StdVector_InsertN_BasicString` / `FUN_004306b0` @ `0x004308e2`, `0x00430976` |
| Callees | `FUN_0046a2c0` (core Ucopy; not dual-owned here) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00431430_FUN_00431430.md` (W33-H append)
- Annotated: `docs/reconstruction/raw/aa_00431430_FUN_00431430.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_UninitializedCopy_BasicString.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00431430.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00431430_StdVector_UninitializedCopy_BasicString.md`
- Review B: `docs/reconstruction/reviews/B_aa_00431430_StdVector_UninitializedCopy_BasicString.md`
- Scaffold record: `docs/reconstruction/functions/aa_00431430_FUN_00431430.md`

## Confidence

| Claim | Level |
|---|---|
| Thin rebind CF | **High** (bytes) |
| ABI thiscall + RET 0x0C | **High** |
| Role = vector string Ucopy | **High** (caller + callee) |
| EAX return (not void) | **High** (use-site) |
| Product demangle | **Low** |
| Why 5th push = dest | **Med** (residual) |
| Nested `FUN_0046a2c0` plate | **Med** (not owned) |
