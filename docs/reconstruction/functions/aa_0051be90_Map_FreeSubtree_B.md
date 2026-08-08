# Function record: Map_FreeSubtree_B

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051be90` |
| **Canonical name** | `Map_FreeSubtree_B` |
| **Ghidra name** | `FUN_0051be90` |
| **Address** | `0x0051be90`–`0x0051bec5` (**53 bytes**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / map-set (WQ-009 residual skill-bank helper) |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-08-04 (WQ9E-I OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC red-black **subtree free** for large-node maps (`isnil@+0x29`). Sole external caller is `Map_EraseRange_B` full-clear path. Byte-correct algebra: free right, delete node, walk left (decomp plate omits left walk).

## Signature (byte-sealed)

```c
void Map_FreeSubtree_B(void *node); // stack arg; RET 4
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051be90_FUN_0051be90.md`
- Annotated: `docs/reconstruction/raw/aa_0051be90_FUN_0051be90.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Map_FreeSubtree_B.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_0051be90.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0051be90_Map_FreeSubtree_B.md`
- Review B: `docs/reconstruction/reviews/B_aa_0051be90_Map_FreeSubtree_B.md`
- Alias record: `docs/reconstruction/functions/aa_0051be90_FUN_0051be90.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `Map_EraseRange_B` `0x0051d880` | full clear only @ `0x0051d89c` |
| Caller | self | right-child recurse |
| Callee | `operator_delete` | after left snapshot |

## Confidence

| Claim | Level |
|---|---|
| Free-subtree role + isnil@+0x29 | **Confirmed** |
| ABI stack node* + ret 4 | **Confirmed** |
| Byte left-walk algebra | **Confirmed** |
| Name pairs with Map_EraseRange_B | **High** |
| Product/PDB / map type English | Open |
| Runtime / image diff | Open |
