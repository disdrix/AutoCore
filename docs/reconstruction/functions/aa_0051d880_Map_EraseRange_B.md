# Function record: Map_EraseRange_B

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d880` |
| **Canonical name** | `Map_EraseRange_B` |
| **Ghidra name** | `FUN_0051d880` |
| **Address** | `0x0051d880`–`0x0051d933` (**180 bytes**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / map-set (WQ-009 residual skill-bank helper) |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-08-04 (WQ9D-H OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Twin of `Map_EraseRange`: MSVC **range erase** for `isnil@+0x29` nodes via `Map_EraseNode`. Full-clear free-subtree is **`FUN_0051be90`** (discriminates from `Map_EraseRange` / `FUN_0051bbc0`).

## Signature (byte-sealed)

```c
void __thiscall Map_EraseRange_B(
    void *map,        // ECX — head @ +4, size @ +8
    void **out_it,
    void *first,
    void *last);
// RET 0x0C
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051d880_FUN_0051d880.md`
- Annotated: `docs/reconstruction/raw/aa_0051d880_FUN_0051d880.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Map_EraseRange_B.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_0051d880.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0051d880_Map_EraseRange_B.md`
- Review B: `docs/reconstruction/reviews/B_aa_0051d880_Map_EraseRange_B.md`
- Alias record: `docs/reconstruction/functions/aa_0051d880_FUN_0051d880.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `FUN_0051e180` | map host complete dtor only |
| Callee | `FUN_0051be90` | full-tree free |
| Callee | `Map_EraseNode` `0x0051cb40` | single-node erase |

## Confidence

| Claim | Level |
|---|---|
| Twin of Map_EraseRange CF | **Confirmed** |
| Free-subtree discriminator | **Confirmed** |
| ABI thiscall + ret 0x0c + isnil@+0x29 | **Confirmed** |
| Product/PDB / K-V English | Open |
| Runtime / image diff | Open |
