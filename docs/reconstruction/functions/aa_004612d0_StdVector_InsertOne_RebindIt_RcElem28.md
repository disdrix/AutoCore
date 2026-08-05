# Function record: StdVector_InsertOne_RebindIt_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_004612d0` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_RcElem28` (**Inferred** structural) |
| **Ghidra name** | `FUN_004612d0` |
| **Address** | `0x004612d0`–`0x00461342` exclusive (**114 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector` insert-one + rebind, T refcounted **0x1c** |
| **Completion status** | **Dual sealed** W35-Q — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Insert one RC-elem28; rebind out-iterator as `begin' + saved_index * 0x1c` after possible realloc. Thin wrapper over sealed `StdVector_InsertN_RcElem28` with `count=1`.

## Signature

```c
RcElem28** StdVector_InsertOne_RebindIt_RcElem28(
    StdVectorRc28* vec,        /* EDI */
    RcElem28** outIt,          /* stack0 */
    RcElem28* where,           /* stack1 */
    const RcElem28* value);    /* stack2; RET 0xC */
```

## Related

| VA | Role |
|---|---|
| `0x004617a0` | `StdVector_InsertN_RcElem28` (W34-P) |
| `0x00460f90` | push_back parent (unowned) |
| `0x004611e0` | resize sibling (same T family) |
| `0x0040dbf0` | dword insert-one rebind twin (different ABI/stride) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004612d0_FUN_004612d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004612d0_FUN_004612d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_RcElem28.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_004612d0_StdVector_InsertOne_RebindIt_RcElem28.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-004611e0-004612d0-w35q-report.md` |
