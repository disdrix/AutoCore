# Function record: Class_00a733ec_ScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416f00` |
| **Canonical name** | `Class_00a733ec_ScalarDeletingDtor_Inferred` |
| **Ghidra name** | `FUN_00416f00` |
| **Address** | `0x00416f00` |
| **Body** | `0x00416f00`–`0x00416f2e` inclusive (**47 B** / `0x2F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC scalar-deleting destructor |
| **Completion status** | **Dual-reviewed** WQ9J-E — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Partition** | `WAVE_2026-08-04_wq009_depth7_partition_map.md` → **WQ9J-E** |

## Purpose

MSVC scalar-deleting destructor for the class whose primary vtbl is `PTR_FUN_00a733ec`. Always reinstalls that vtbl; if free-callback at `+0x10` is non-null, invokes it cdecl with context at `+0x04`; frees the heap host when `(flags & 1)`. Returns `this` in EAX. Complete teardown is **inline** (no separate complete-dtor call).

Object layout (size **0x14** from factories): `+0` vtbl, `+4` context, `+8`/`+0xc` zeros, `+0x10` free callback.

## Signature

```c
// ECX = this; stack flags; RET 4; returns this*
void *__thiscall Class_00a733ec_ScalarDeletingDtor_Inferred(void *self, uint8_t flags);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | DATA only — `PTR_FUN_00a733ec[0]` @ `0x00a733ec` (= `0x00416f00`) |
| Callees | indirect free @ `+0x10`, `operator_delete` |

## Related (not OWN)

- Factory with callback `LAB_00573240`: `FUN_00416830`
- Factory with null callback: `FUN_004168c0`
- Adjacent .rdata UTF-16 `"UNI_BUTTONS"` — circumstantial only (not sealed class name)

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00416f00_FUN_00416f00.md`
- Annotated: `docs/reconstruction/raw/aa_00416f00_FUN_00416f00.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Class_00a733ec_ScalarDeletingDtor_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00416f00.cpp`
- Review A: `reviews/A_aa_00416f00_Class_00a733ec_ScalarDeletingDtor_Inferred.md`
- Review B: `reviews/B_aa_00416f00_Class_00a733ec_ScalarDeletingDtor_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00416f00_FUN_00416f00.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ABI ECX + RET 4 + return this | **High** |
| flags bit0 → operator_delete | **High** |
| free callback cdecl +0x10 / arg +0x04 | **High** |
| vtbl[0] slot `00a733ec` | **High** |
| Product MSVC demangle | **Open** (vtbl stamp naming → `_Inferred`) |
| Runtime | **Open** |
