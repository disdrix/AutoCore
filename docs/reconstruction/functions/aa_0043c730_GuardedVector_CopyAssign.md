# Function record: GuardedVector_CopyAssign

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c730` |
| **Canonical name** | `GuardedVector_CopyAssign` (**Inferred**) |
| **Ghidra name** | `FUN_0043c730` |
| **Address** | `0x0043c730`–`0x0043c7d6` (**167 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / guarded container |
| **Convention** | custom: **EAX**=source, **EDI**=dest; plain `RET` |
| **Completion status** | **partial** — dual A/B 2026-07-29 W26-G |
| **Dual verdict** | **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Copy-assign ring/vector contents from source to dest without taking the parent critical section (lock is the wrapper `GuardedVector_AssignTo`).

## Signature

```c
void GuardedVector_CopyAssign(void* source /*EAX*/, void* dest /*EDI*/);
```

## Layout (header)

| Offset | Field |
|---|---|
| `+0x04` | slots map |
| `+0x08` | capacity |
| `+0x0c` | begin index |
| `+0x10` | size |

## Artifacts

- Scaffold record: `docs/reconstruction/functions/aa_0043c730_FUN_0043c730.md`
- Raw / annotated / clean / dual A/B — see scaffold record.

## Confidence

| Claim | Level |
|---|---|
| CF + ABI sealed | **High** |
| Name product English | **Inferred** only |
| Nested grow/fit free | residual |
