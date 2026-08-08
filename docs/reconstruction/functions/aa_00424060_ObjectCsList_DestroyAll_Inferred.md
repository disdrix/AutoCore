# Function record: ObjectCsList_DestroyAll_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00424060` |
| **Canonical name** | `ObjectCsList_DestroyAll_Inferred` |
| **Ghidra** | `FUN_00424060` |
| **Address** | `0x00424060`–`0x0042415a` (**251 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object core / CS-owned list DestroyAll |
| **Completion status** | **Dual sealed** WQ9L-E 2026-08-05 |
| **Verdict** | **accept** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

List-method **DestroyAll** (product SEH string): under CS, throw if traversal flag, drain head@`+0x1C` via next@`+8` and scalar-delete, zero head/counts, LeaveCS. Twin of W31-S `ObjectCsList_ClearDestroyNoNode4_Inferred` (`0x0051bc90`) without `node+4=0`. Opposite of W30-F `ObjectCsList_ClearDestroy_Inferred` (`0x0051b8a0`) which clears `node+4`.

## Signature

```c
void __fastcall ObjectCsList_DestroyAll_Inferred(void* list /* ECX */);
```

## UI nesting

CNDUIWindow `+0x1E8`: dual vtbl phase `00a964b8`/`00a964ac` (`CNDDoubleListPtr`/`CNDDoubleList` of `STextMarkup`) then this ×2 + `DeleteCriticalSection(+0x1EC)`.

## Artifacts

- Twin Ghidra record: `docs/reconstruction/functions/aa_00424060_FUN_00424060.md`
- Clean: `docs/reconstruction/reconstructed-exact/ObjectCsList_DestroyAll_Inferred.cpp`
- Dual A/B under `docs/reconstruction/reviews/`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / offsets / NoNode4 | **High** |
| Name DestroyAll | **High** (product string) |
| ObjectCsList family English | **Inferred** |
