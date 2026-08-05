# Function record: GuardedVector_InsertN

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043cb00` |
| **Canonical name** | `GuardedVector_InsertN` (**Inferred**) |
| **Ghidra name** | `FUN_0043cb00` |
| **Address** | `0x0043cb00`–`0x0043cdfe` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-deque container |
| **Status** | Dual A/B sealed W29-A 2026-07-29 — **accept-with-gaps** |

## Purpose

Insert `N` fill-dword copies at absolute `insert_at` in a GuardedVector ring header. Front-biased arms use push_front (`FUN_0043ce10`); back-biased arms use push_back (`FUN_0043c830`); window fill via sealed `GuardedVector_RingFillRange`. Resize grow is the sole known caller and only exercises the end-insert (`suffix=0`) arm.

## Signature

```c
// Retail: ECX=N; stack (container, seed, insert_at, fill*); RET 0x10
void GuardedVector_InsertN(uint32_t n /*ECX*/,
                           GuardedVectorHeader* container,
                           GuardedVectorHeader* seed,
                           int32_t insert_at,
                           uint32_t* fill);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043cb00_FUN_0043cb00.md` |
| Annotated | `docs/reconstruction/raw/aa_0043cb00_FUN_0043cb00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_InsertN.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043cb00.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043cb00_FUN_0043cb00.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043cb00_GuardedVector_InsertN.md`, `B_…` |
