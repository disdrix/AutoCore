# Function record: BasicString_CopyBackward_Thunk_0x1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431480` |
| **Canonical name** | `BasicString_CopyBackward_Thunk_0x1c` (**Inferred** structural) |
| **Ghidra name** | `FUN_00431480` |
| **Address** | `0x00431480` |
| **Body** | `0x00431480`–`0x0043149d` exclusive (**29 B** / `0x1D`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `basic_string<char>` copy-backward trampoline |
| **Completion status** | **Dual-reviewed** W33-I — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Thin trampoline used by `StdVector_InsertN_BasicString` mid-insert path to open an insert hole: forwards three range pointers into free `FUN_00431790` (`copy_backward` of live `basic_string` slots, stride **0x1c**).

## Signature

```c
// Call-site sealed: cdecl; 3 stack args; plain RET; void
void BasicString_CopyBackward_Thunk_0x1c(
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest_end);
// Forwards to FUN_00431790(first, last, dest_end)
```

| Formal | Source | Conf |
|---|---|---|
| first / last / dest_end | 3 stack args at sole call site | **High** |
| body `PUSH ECX` + reorder | `read_memory` body hex | **High** |
| ECX semantic this | sole caller does not set | **Med** (dead) |
| cleanup | plain `C3`; body `ADD ESP,14` before ret | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `StdVector_InsertN_BasicString` (`FUN_004306b0`) @ `0x00430984` |
| Callees | `FUN_00431790` @ `0x00431790` (copy_backward free helper; **not dual-owned**) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00431480_FUN_00431480.md` (W33-I append)
- Annotated: `docs/reconstruction/raw/aa_00431480_FUN_00431480.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/BasicString_CopyBackward_Thunk_0x1c.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00431480.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00431480_BasicString_CopyBackward_Thunk_0x1c.md`
- Review B: `docs/reconstruction/reviews/B_aa_00431480_BasicString_CopyBackward_Thunk_0x1c.md`
- Scaffold record: `docs/reconstruction/functions/aa_00431480_FUN_00431480.md`

## Confidence

| Claim | Level |
|---|---|
| Thunk → `00431790` CF | **High** |
| Call-site 3-arg cdecl | **High** |
| Role = copy_backward for insert hole | **High** (parent + callee decompile) |
| Product demangle / nested plate | **Low** |
| Ghidra 4-param thiscall as real public ABI | **Rejected** for call-site contract |
