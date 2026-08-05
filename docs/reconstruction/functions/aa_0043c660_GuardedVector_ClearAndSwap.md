# Function record: GuardedVector_ClearAndSwap

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c660` |
| **Canonical name** | `GuardedVector_ClearAndSwap` (**Inferred**) |
| **Ghidra name** | `FUN_0043c660` |
| **Address** | `0x0043c660`–`0x0043c6e8` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-deque container |
| **Status** | Dual A/B sealed W29-A 2026-07-29 — **accept** |

## Purpose

Under optional critical section on EDI (`+0x2c` flag / `+0x14` CS), resize ESI to empty then swap ring header fields (`+0x04` slots, `+0x08` capacity, `+0x0c` begin, `+0x10` size) with EDI. Primary consumer of sealed `GuardedVector_Resize` clear arm.

## Signature

```c
// ESI=A, EDI=B (optional CS); plain RET
void GuardedVector_ClearAndSwap(void /*ESI, EDI*/);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043c660_FUN_0043c660.md` |
| Annotated | `docs/reconstruction/raw/aa_0043c660_FUN_0043c660.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_ClearAndSwap.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c660.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043c660_FUN_0043c660.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043c660_GuardedVector_ClearAndSwap.md`, `B_…` |
