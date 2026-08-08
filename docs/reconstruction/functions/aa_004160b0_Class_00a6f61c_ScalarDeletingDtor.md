# Function record: Class_00a6f61c_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004160b0` |
| **Canonical name** | `Class_00a6f61c_ScalarDeletingDtor` (**Inferred** structural) |
| **Ghidra name** | `FUN_004160b0` |
| **Address** | `0x004160b0` |
| **Body** | `0x004160b0`–`0x004160cd` inclusive (**30 B** / `0x1E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC scalar-deleting destructor |
| **Completion status** | **Dual-reviewed** WQ9I-E — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Partition** | `WAVE_2026-08-04_wq009_depth6_partition_map.md` → **WQ9I-E** |

## Purpose

MSVC scalar-deleting destructor for the class whose primary vtbl is `PTR_FUN_00a6f61c`. Always runs the complete dtor (`FUN_0097a8a0`), then frees the heap host when `(flags & 1)`. Returns `this` in EAX.

## Signature

```c
// ECX = this; stack flags; RET 4; returns this*
void* __thiscall Class_00a6f61c_ScalarDeletingDtor(void* self, uint8_t flags);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | DATA only — `PTR_FUN_00a6f61c[0]` @ `0x00a6f61c` (= `0x004160b0`) |
| Callees | `FUN_0097a8a0` (complete), `operator_delete` |

## Related (not OWN)

- Complete dtor `FUN_0097a8a0` → base chain `FUN_00792c20`
- Ctor `FUN_0097a8e0` (same vtbl; UI `i_w_tut_2d_wnd_highlight.dds`)
- Neighbor scalar `FUN_004160d0` (WQ9I-F)

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004160b0_FUN_004160b0.md`
- Annotated: `docs/reconstruction/raw/aa_004160b0_FUN_004160b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Class_00a6f61c_ScalarDeletingDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004160b0.cpp`
- Review A: `reviews/A_aa_004160b0_Class_00a6f61c_ScalarDeletingDtor.md`
- Review B: `reviews/B_aa_004160b0_Class_00a6f61c_ScalarDeletingDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_004160b0_FUN_004160b0.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ABI ECX + RET 4 + return this | **High** |
| flags bit0 → operator_delete | **High** |
| vtbl[0] slot `00a6f61c` | **High** |
| Product MSVC demangle | **Open** (vtbl stamp naming) |
| Runtime | **Open** |
