# Function record: StdVector_AssignFrom_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469d10` |
| **Canonical name** | `StdVector_AssignFrom_BasicString` (**Inferred** structural) |
| **Ghidra name** | `FUN_00469d10` |
| **Address** | `0x00469d10` |
| **Body** | `0x00469d10`–`0x00469d96` exclusive (**134 B** / `0x86`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<basic_string<char>>` assign-from-src (blank-buy + uninit_copy) |
| **Completion status** | **Dual-reviewed** W34-S — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Copy-assign **src** string-vector contents into **dest**: measure src size in 0x1c elems, call `FUN_00431b30(dest, n)` to zero dest triad and allocate capacity, then `StdUninitCopy_BasicString` (`FUN_0046a2c0`) to copy-construct strings into dest and set `dest.end`. Returns dest. Used by FS path-expand collectors (`FUN_009841d0`, `Fs_ExpandPathSpecToStringVec_Inferred`).

## Signature

```c
// ECX = src*; stack dest*; RET 4; returns dest*
VectorBasicString* __thiscall StdVector_AssignFrom_BasicString(
    VectorBasicString* src,
    VectorBasicString* dest);
```

| Formal | Source | Conf |
|---|---|---|
| src | ECX (`8B F1`) | **High** |
| dest | stack `[ebp+8]` (`8B 7D 08`) | **High** |
| buy this | ECX←EDI before `FUN_00431b30` | **High** |
| return | EAX = dest (`8B C7`) | **High** |
| cleanup | `C2 04 00` | **High** |
| stride | `/0x1c` magic | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_009841d0` @ `0x00984244`; `FUN_00984340` @ `0x009842ed`, `0x00984760` |
| Callees | `FUN_00431b30`; `FUN_0046a2c0` (`StdUninitCopy_BasicString`, W33-G) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00469d10_FUN_00469d10.md` (W34-S append)
- Annotated: `docs/reconstruction/raw/aa_00469d10_FUN_00469d10.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_AssignFrom_BasicString.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00469d10.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00469d10_StdVector_AssignFrom_BasicString.md`
- Review B: `docs/reconstruction/reviews/B_aa_00469d10_StdVector_AssignFrom_BasicString.md`
- Scaffold record: `docs/reconstruction/functions/aa_00469d10_FUN_00469d10.md`
- Scratch: `docs/reconstruction/tmp/a_00469d10.md`

## Confidence

| Claim | Level |
|---|---|
| Assign-from CF | **High** |
| ABI src-this + RET 4 | **High** |
| basic_string via W33-G | **High** |
| Buy no-free contract | **High** (nested decompile) |
| Product demangle | **Low** |
