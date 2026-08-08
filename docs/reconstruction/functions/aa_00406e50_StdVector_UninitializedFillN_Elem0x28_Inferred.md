# Function record: StdVector_UninitializedFillN_Elem0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406e50` |
| **Canonical name** | `StdVector_UninitializedFillN_Elem0x28_Inferred` |
| **Ghidra name** | `FUN_00406e50` |
| **Address** | `0x00406e50` |
| **Body range** | `0x00406e50` – `0x00406e6c` (**28 B** / `0x1c`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (generic; elem stride **0x28**) |
| **Calling convention** | **EDI**=dst, **ESI**=count, stack `value*`; **`ret 4`**; EAX=end |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ9G-H 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00406e50_StdVector_UninitializedFillN_Elem0x28_Inferred.md` |
| **Dual B** | `reviews/B_aa_00406e50_StdVector_UninitializedFillN_Elem0x28_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9G-H) |

## Alias

- Ghidra: `FUN_00406e50`
- Prior scaffold: partial raw/annotated/clean only
- Structural: fill-n wrapper — ConstructN then `return dst + n*0x28`
- Twin pattern: `UiToast_UninitializedFillN_0x98` @ `0x00404130`

## Purpose

**Uninitialized fill-N** for **0x28-byte** POD elements:

1. Call `FUN_00409d40` (ConstructN) to stamp `count` copies of template `value` at `dst`.
2. Return **end** pointer `dst + count * 0x28`.

Sole known parent: insert-N `FUN_00408050` — two sites (realloc hole fill + in-place fill).

## Signature

```c
void *StdVector_UninitializedFillN_Elem0x28_Inferred(
    /*EDI*/ void *dst,
    /*ESI*/ int count,
    /*stack*/ const void *value);
// ret 4; EAX = dst + count*0x28
```

## Algorithm

```
FUN_00409d40(value /*ECX*/, dst, count);  // loop PodCopy 10 dwords / +0x28
return dst + count * 0x28;
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00406e50_FUN_00406e50.md` (+ WQ9G-H append)
- Annotated: `docs/reconstruction/raw/aa_00406e50_FUN_00406e50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_UninitializedFillN_Elem0x28_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00406e50.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00406e50_FUN_00406e50.md`
- Report: `docs/agents/task-dual-ab-00406de0-00406e50-wq9gh-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Callee | `0x00409d40` | ConstructN (loop `FUN_00409f30` PodCopy 0x28) |
| Callee leaf | `0x00409f30` | PodCopy 10 dwords → 0x28 |
| Caller | `0x00408050` | InsertN (2 UNCONDITIONAL_CALL sites) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| Stride **0x28** end arithmetic | **High** |
| `ret 4` / EDI/ESI + value stack | **High** |
| Role = fill-n (not grow) | **High** |
| Product English symbol | **Inferred / Open** |
| Runtime / differential | Open |
