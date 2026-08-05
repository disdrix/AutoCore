# Function record: FUN_0043cef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043cef0` |
| **Canonical name** | `GuardedVector_RingFillRange` (prefer named plate) |
| **Ghidra name** | `FUN_0043cef0` |
| **Address** | `0x0043cef0`–`0x0043cf38` (**73 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / guarded ring-vector container |
| **Completion status** | Dual A/B sealed W28-D 2026-07-29 — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Leaf ring fill: write `*EBX` to every element in half-open absolute index range using page map at `+0x04` and page capacity at `+0x08` (4 dwords per page).

## Signature (retail)

```c
// EBX=&fill; stack 4 args; plain RET (caller cleans 0x10)
void GuardedVector_RingFillRange(
    GuardedVectorHeader* container_from, uint32_t idx_from,
    GuardedVectorHeader* container_to,   uint32_t idx_to,
    const uint32_t* fill /*EBX*/);
```

## Artifacts

- Named: `GuardedVector_RingFillRange`
- Raw: `docs/reconstruction/raw/aa_0043cef0_FUN_0043cef0.md`
- Annotated: `docs/reconstruction/raw/aa_0043cef0_FUN_0043cef0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GuardedVector_RingFillRange.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0043cef0.cpp`
- Named record: `docs/reconstruction/functions/aa_0043cef0_GuardedVector_RingFillRange.md`

## Callers / callees

| Direction | Target |
|---|---|
| Caller (1) | `FUN_0043cb00` — xrefs `0x0043cbdd`, `0x0043cd1c`, `0x0043cde6` |
| Callees | **none** (leaf) |

## Confidence

| Claim | Level |
|---|---|
| Leaf CF + page wrap math | **High** |
| `+0x04/+0x08` map layout | **High** |
| EBX fill pointer ABI | **High** |
| Product English | **Inferred** |
