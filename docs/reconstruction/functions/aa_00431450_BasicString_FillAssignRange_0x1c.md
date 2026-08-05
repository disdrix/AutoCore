# Function record: BasicString_FillAssignRange_0x1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431450` |
| **Canonical name** | `BasicString_FillAssignRange_0x1c` (**Inferred** structural) |
| **Ghidra name** | `FUN_00431450` |
| **Address** | `0x00431450` |
| **Body** | `0x00431450`–`0x00431477` exclusive (**39 B** / `0x27`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `basic_string<char>` range assign-fill |
| **Completion status** | **Dual-reviewed** W33-I — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Assign one source `basic_string` into every existing element of half-open range `[first, last)` with element stride **0x1c**. Implements the in-place hole-fill step of `vector<string>::insert(where, count, value)` (`StdVector_InsertN_BasicString`).

## Signature

```c
// cdecl; 3 stack args; plain RET; void
void BasicString_FillAssignRange_0x1c(
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    const BasicString_0x1c* value);
```

| Formal | Source | Conf |
|---|---|---|
| first | stack `[esp+4]` → ESI | **High** |
| last | stack `[esp+8]` → EDI | **High** |
| value | stack `[esp+0xC]` → EBX | **High** |
| stride | `ADD ESI, 0x1C` | **High** |
| cleanup | plain `C3` | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `StdVector_InsertN_BasicString` (`FUN_004306b0`) @ `0x0043092d`, `0x00430994` |
| Callees | IAT `basic_string::operator=` via `[0x009c63c4]` → `0x006ec244` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00431450_FUN_00431450.md` (W33-I append)
- Annotated: `docs/reconstruction/raw/aa_00431450_FUN_00431450.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/BasicString_FillAssignRange_0x1c.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00431450.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00431450_BasicString_FillAssignRange_0x1c.md`
- Review B: `docs/reconstruction/reviews/B_aa_00431450_BasicString_FillAssignRange_0x1c.md`
- Scaffold record: `docs/reconstruction/functions/aa_00431450_FUN_00431450.md`

## Confidence

| Claim | Level |
|---|---|
| Fill-by-assign CF | **High** |
| ABI cdecl 3-arg + plain RET | **High** |
| Stride 0x1c + string operator= | **High** |
| Product demangle plate | **Low** |
