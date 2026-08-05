# Function record: StdVector_BuyN_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431b30` |
| **Canonical name** | `StdVector_BuyN_BasicString` (**Inferred** structural) |
| **Ghidra name** | `FUN_00431b30` |
| **Address** | `0x00431b30` |
| **Body** | `0x00431b30`–`0x00431b82` exclusive (**82 B** / `0x52`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<basic_string<char>>` blank capacity buy (elem **0x1c**) |
| **Completion status** | **Dual-reviewed** W37-E — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Blank-buy buffer for **n** `basic_string` slots: zero triad (no free), allocate `n*0x1c` when n≠0, leave **size 0** (begin==end), set capEnd. Return 0/1. Max n `0x9249249` else throw `"vector<T> too long"`. Used by `StdVector_AssignFrom_BasicString` (`0x00469d10`, W34-S) as the dest prep step.

## Signature

```c
// ECX = dest vector*; stack n; RET 4; AL = 0 (n==0) or 1 (bought)
uint8_t __thiscall StdVector_BuyN_BasicString(VectorBasicString* dest, uint32_t n);
```

| Formal | Source | Conf |
|---|---|---|
| dest | ECX (`8B F1`) | **High** |
| n | stack `[esp+4]` (`8B 44 24 04`) | **High** |
| return 0/1 | `32 C0` / `B0 01` | **High** |
| cleanup | `C2 04 00` | **High** |
| stride | `n*0x1c` lea chain | **High** |
| no free | triad stores only | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `StdVector_AssignFrom_BasicString` (`FUN_00469d10`) @ `0x00469d56` |
| Callees | `FUN_004540b0` (noreturn); `operator_new` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00431b30_FUN_00431b30.md` (W37-E append)
- Annotated: `docs/reconstruction/raw/aa_00431b30_FUN_00431b30.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_BuyN_BasicString.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00431b30.cpp`
- Scaffold: `docs/reconstruction/functions/aa_00431b30_FUN_00431b30.md`
- Review A: `docs/reconstruction/reviews/A_aa_00431b30_StdVector_BuyN_BasicString.md`
- Review B: `docs/reconstruction/reviews/B_aa_00431b30_StdVector_BuyN_BasicString.md`
- Scratch: `docs/reconstruction/tmp/a_00431b30.md`

## Confidence

| Claim | Level |
|---|---|
| Buy CF / no-free | **High** |
| ABI + return codes | **High** |
| Elem 0x1c + max | **High** |
| basic_string product T | **High** (caller W34-S + throw string) |
| MSVC demangle English | **Low** |
