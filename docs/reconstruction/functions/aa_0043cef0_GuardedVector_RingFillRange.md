# Function record: GuardedVector_RingFillRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043cef0` |
| **Canonical name** | `GuardedVector_RingFillRange` (**Inferred**) |
| **Ghidra name** | `FUN_0043cef0` |
| **Address** | `0x0043cef0`–`0x0043cf38` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-vector container |
| **Status** | Dual A/B sealed W28-D 2026-07-29 — **accept** |

## Purpose

Assign a single dword fill value across a half-open ring index range. Used by the grow/insert worker `FUN_0043cb00` after element construct moves.

## Signature

```c
// Retail: EBX=&fill; 4 stack formals; plain RET
void GuardedVector_RingFillRange(
    GuardedVectorHeader* container_from, uint32_t idx_from,
    GuardedVectorHeader* container_to,   uint32_t idx_to,
    const uint32_t* fill /*EBX*/);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043cef0_FUN_0043cef0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043cef0_FUN_0043cef0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingFillRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043cef0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043cef0_FUN_0043cef0.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043cef0_GuardedVector_RingFillRange.md`, `B_…` |
