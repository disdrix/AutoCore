# Function record: Map_EraseNode_Isnil1d_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051c880` |
| **Canonical name** | `Map_EraseNode_Isnil1d_Inferred` |
| **Ghidra name** | `FUN_0051c880` |
| **Address** | `0x0051c880`–`0x0051cb36` exclusive (**694 B** / `0x2B6`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / map-set (WQ-009 skill residual; isnil@+0x1d) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_0051c880_Map_EraseNode_Isnil1d_Inferred.md`, `B_aa_0051c880_Map_EraseNode_Isnil1d_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9F-F OWN-ONLY) |

## Alias

- `FUN_0051c880`
- Scaffold chain-of-caller names: **reject** as canonical

## Purpose

Erase one non-nil node from an MSVC-style map/set tree (**isnil@+0x1d**, **color@+0x1c**). Throws `"invalid map/set<T> iterator"` on nil. Writes successor into `*pOutIt`; decrements `map->size@+0x08` after free. Structural peer of dualed `Map_EraseNode` (isnil@+0x29) with different layout immediates and callees. Sole caller: `Map_EraseRange_Isnil1d_Inferred` partial path.

## Signature (byte-sealed)

```c
void __thiscall Map_EraseNode_Isnil1d_Inferred(
    void *map,        // ECX — head @ +4, size @ +8
    void **pOutIt,    // stack0 — successor out
    void *pNode);     // stack1 — node to erase
// RET 8
```

## Algorithm (sealed)

1. If `pNode->isnil@+0x1d` → throw `"invalid map/set<T> iterator"`.
2. `FUN_0051b690(&local)` — in-order successor (isnil@+0x1d).
3. Unlink node; update head begin/root/end; RB rebalance (color@+0x1c; rotates `FUN_00420130` / `FUN_00420180`; min `FUN_0051b670`; max `FUN_00421b90`).
4. `operator_delete(pNode)` — **falls through** (decomp false-noreturn).
5. If `map->size > 0`: `size--`.
6. `*pOutIt = successor`; `ret 8`.

## Related

| VA | Role |
|---|---|
| `0x0051d700` | `Map_EraseRange_Isnil1d_Inferred` — sole caller |
| `0x0051be10` | free-subtree isnil@+0x1d (range full-clear; not OWN) |
| `0x0051cb40` | `Map_EraseNode` isnil@+0x29 twin role |
| `0x00409220` | `Map_EraseNode_B` isnil@+0x29 twin |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_0051c880_FUN_0051c880.md`
- Annotated: `docs/reconstruction/raw/aa_0051c880_FUN_0051c880.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Map_EraseNode_Isnil1d_Inferred.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_0051c880.cpp`
- Review A/B: `docs/reconstruction/reviews/A|B_aa_0051c880_Map_EraseNode_Isnil1d_Inferred.md`
- Scaffold alias: `docs/reconstruction/functions/aa_0051c880_FUN_0051c880.md`

## Confidence

| Claim | Level |
|---|---|
| STL erase role + throw string | **Confirmed** |
| ABI `thiscall` + `ret 8` + size-- | **Confirmed** (bytes) |
| Node isnil@+0x1d / color@+0x1c | **Confirmed** |
| Product/PDB symbol | Open (`_Inferred`) |
| Runtime / image diff | Open |
