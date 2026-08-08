# Function record: StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e3e70` |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil21_Inferred` |
| **Ghidra name** | `FUN_004e3e70` |
| **Address** | `0x004e3e70`–`0x004e4126` exclusive (**694 B** / `0x2B6`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL map-set helpers (isnil@+0x21 family) |
| **Wave** | R12-013 OWN-ONLY dual 2026-08-05 (dual start 2646) |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |
| **Parent dual** | `0x005a27f0` (Rrotate isnil21) |

## Alias history

- Ghidra: `FUN_004e3e70`
- Scaffold: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_004e3e70` (**reject** product id)
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
4. If erased color black (`+0x20 == 1`) → RB with Lrotate `FUN_0050e9f0` / Rrotate `FUN_005a27f0`.
5. `operator_delete(node)`; if size>0 then `--size`; `*outIt = successor`; `ret 8`.

**Note:** Decompiler marks delete as noreturn and omits size-- / outIt / ret 8 — **bytes seal**.

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x00407200` | `StdTree_InsertAndRebalance_Isnil21_Inferred` | insert twin (same layout/rotates) |
| `0x004e4130` | `StdTree_EraseAndRebalance_Val12` | adjacent Val12 erase (isnil@+0x19) |
| `0x0050e9f0` | Lrotate isnil21 | rotate leaf |
| `0x005a27f0` | Rrotate isnil21 | rotate leaf (partition parent) |
| `0x004e12c0` | nextnode isnil21 | successor prep |
| `0x004e4e10` / `0x004e52a0` | EraseRange shells | sole callers (2) |

## Artifacts

- Raw (+ R12-013 append): `docs/reconstruction/raw/aa_004e3e70_FUN_004e3e70.md`
- Annotated: `docs/reconstruction/raw/aa_004e3e70_FUN_004e3e70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil21_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004e3e70.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004e3e70_StdTree_EraseAndRebalance_Isnil21_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004e3e70_StdTree_EraseAndRebalance_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-004e3e70-r12-report.md`
- Scaffold function: `docs/reconstruction/functions/aa_004e3e70_FUN_004e3e70.md`

## Callers / callees

| **Callers (2)** | `FUN_004e4e10` @ `0x004e4eaf`; `FUN_004e52a0` @ `0x004e533f` |
| **Callees** | `FUN_004e12c0`, `FUN_004cb2c0`, `FUN_00421a60`, `FUN_0050e9f0`, `FUN_005a27f0`, `operator_delete`, STL throw chain (`basic_string` / `exception` / `_CxxThrowException`) |

## Confidence

| Claim | Level |
|---|---|
| Role single-node erase + rebalance | **High** |
| ABI / RET 8 / size-- / outIt | **Confirmed** |
| Layout color@+0x20 isnil@+0x21 | **Confirmed** |
| Two EraseRange callers | **Confirmed** |
| Product English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
