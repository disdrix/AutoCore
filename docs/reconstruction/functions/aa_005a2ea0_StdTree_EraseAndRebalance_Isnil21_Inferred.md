# Function record: StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2ea0` |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil21_Inferred` |
| **Ghidra name** | `FUN_005a2ea0` |
| **Address** | `0x005a2ea0`–`0x005a3155` inclusive (**694 B** / `0x2B6`) |
| **Exclusive end / pad** | `0x005a3156` (`CC`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL map-set helpers (isnil@+0x21 family) |
| **Wave** | R12-030 OWN-ONLY dual 2026-08-05 (dual start 2646) |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |
| **Parent dual** | `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred (R11-007) |
| **Partition** | `WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-030** |

## Alias history

- Ghidra: `FUN_005a2ea0`
- Scaffold: auto plate (unknown system) — retired for product id
- Structural: `StdTree_EraseAndRebalance_Isnil21_Inferred` (product demangle open)

## Purpose

Single-node MSVC `_Tree::erase(const_iterator)` for **isnil@+0x21** nodes (node **0x28**, color@**+0x20**, Val16 @+0x10): nil-iterator throw, successor prep, unlink + extremity fix, RB rebalance if erased black, `operator_delete`, size--, write `*outIt`.

## Signature

```c
void __thiscall StdTree_EraseAndRebalance_Isnil21_Inferred(
    /*ECX*/ MapShell_Isnil21 *map,   // +0x04 head, +0x08 size
    MapNode_Isnil21 **outIt,         // *outIt = successor
    MapNode_Isnil21 *node);          // node to erase
// RET 8
```

## Algorithm

1. If `node->isnil (+0x21)` → throw `"invalid map/set<T> iterator"` (`0x00a152f0`, ThrowInfo `DAT_00acc34c`).
2. `FUN_004e12c0` — isnil21 successor / out-it prep.
3. Splice replacement; fix root / leftmost (`FUN_004cb2c0`) / rightmost (`FUN_00421a60`).
4. Two-child successor-swap plate lives in asm (decomp "unreachable" warnings).
5. If erased color black (`+0x20 == 1`) → RB with Lrotate `FUN_0050e9f0` / Rrotate `FUN_005a27f0`.
6. `operator_delete(node)`; if size>0 then `--size`; `*outIt = successor`; `ret 8`.

**Note:** Decompiler marks delete as noreturn and omits size-- / outIt / ret 8 — **bytes seal**.

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x10 | value (Val16 / trivial in this body) |
| +0x20 | color (0 red / 1 black) |
| +0x21 | isnil |
| size | **0x28** |

Shell: `head@+4`, `size@+8`.

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x00407200` | `StdTree_InsertAndRebalance_Isnil21_Inferred` | insert twin (same layout/rotates) |
| `0x00405650` | same structural erase (R12-009, 660 B) | clone |
| `0x004e3e70` | same structural erase (R12-013, 694 B) | reloc-near-identical clone |
| `0x0050e9f0` | Lrotate isnil21 | rotate leaf |
| `0x005a27f0` | Rrotate isnil21 | rotate leaf (partition parent) |
| `0x004e12c0` | nextnode isnil21 | successor prep |
| `0x005a3860` | EraseRange shell | primary recovered caller |
| residual | `0059d300`, `005a3500`, … | other isnil21 erase clones (not OWN) |

## Artifacts

- Raw (+ R12-030 append): `docs/reconstruction/raw/aa_005a2ea0_FUN_005a2ea0.md`
- Annotated: `docs/reconstruction/raw/aa_005a2ea0_FUN_005a2ea0.annotated.md`
- Clean (VA): `docs/reconstruction/reconstructed-exact/FUN_005a2ea0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_005a2ea0_StdTree_EraseAndRebalance_Isnil21_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005a2ea0_StdTree_EraseAndRebalance_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-005a2ea0-r12-report.md`
- Scaffold function: `docs/reconstruction/functions/aa_005a2ea0_FUN_005a2ea0.md`

## Callers / callees

| **Callers (2 xrefs)** | `FUN_005a3860` @ `0x005a38ff`; orphan @ `0x005a052b` |
| **Callees** | `FUN_004e12c0`, `FUN_004cb2c0`, `FUN_00421a60`, `FUN_0050e9f0`, `FUN_005a27f0`, `operator_delete`, STL throw chain |

## Confidence

| Claim | Level |
|---|---|
| Role single-node erase + rebalance | **High** |
| ABI / RET 8 / size-- / outIt | **High** (byte-sealed; not Runtime Confirmed) |
| Layout color@+0x20 isnil@+0x21 | **High** |
| Two xrefs / one recovered EraseRange caller | **High** |
| Product English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
