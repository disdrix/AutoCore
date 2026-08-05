# Function record: StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469e20` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_00469e20` |
| **Address** | `0x00469e20`–`0x00469e92` exclusive (**114 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector` insert-one + rebind, T POD **0x1c** |
| **Completion status** | **Dual sealed** W36-Q — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `reviews/A_aa_00469e20_StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred.md`, `B_…` |

## Purpose

Insert one POD-elem28; rebind out-iterator as `begin' + saved_index * 0x1c` after possible realloc. Thin wrapper over sealed `StdVector_InsertN_Elem28_ValueEdx_Inferred` with `count=1`.

## Signature

```c
Elem28** StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred(
    StdVectorElem28* vec,      /* EDI */
    Elem28** outIt,            /* stack0 */
    Elem28* where,             /* stack1 */
    const Elem28* value);      /* stack2; RET 0xC */
```

## Related

| VA | Role |
|---|---|
| `0x00469f50` | `StdVector_InsertN_Elem28_ValueEdx_Inferred` (W34-Q) — sole engine |
| `0x00469c80` | push_back parent (unowned): spare-cap → `FUN_0046a260`; else this |
| `0x004612d0` | `StdVector_InsertOne_RebindIt_RcElem28` — RC twin (same CF/ABI shell) |
| `0x0040dbf0` | dword insert-one rebind twin (different ABI/stride) |
| `0x00469c50` | `StdVector_Elem28_Size` (W33-J) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00469e20_FUN_00469e20.md` |
| Annotated | `docs/reconstruction/raw/aa_00469e20_FUN_00469e20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00469e20.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_00469e20_FUN_00469e20.md` |
| Dual report | `docs/agents/task-dual-ab-00469e20-004a6820-w36q-report.md` |
