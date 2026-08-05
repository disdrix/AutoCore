# Function record: StdVector_Resize_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_004611e0` |
| **Canonical name** | `StdVector_Resize_RcElem28` (**Inferred** structural) |
| **Ghidra name** | `FUN_004611e0` |
| **Address** | `0x004611e0`–`0x004612c5` exclusive (**229 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<T>::resize`, T refcounted **0x1c** |
| **Completion status** | **Dual sealed** W35-Q — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Resize RC-elem28 vector to `n` elements filled with by-value `value`: grow via `StdVector_InsertN_RcElem28` at end; shrink via `FUN_00461720` erase-range; Release stack value resource `@+0x10`.

## Signature

```c
void StdVector_Resize_RcElem28(
    StdVectorRc28* vec,   /* EDI */
    uint32_t new_size,    /* ECX */
    RcElem28 value);      /* stack by-value; RET 0x1C */
```

## Related

| VA | Role |
|---|---|
| `0x004617a0` | `StdVector_InsertN_RcElem28` (W34-P) — grow engine |
| `0x00461720` | erase-range shrink helper |
| `0x004612d0` | insert-one sibling (same T family) |
| `0x00406840` | `LogicUiEventQueue_Resize` — POD stride-0x138 twin pattern |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004611e0_FUN_004611e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004611e0_FUN_004611e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Resize_RcElem28.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_004611e0_StdVector_Resize_RcElem28.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-004611e0-004612d0-w35q-report.md` |
