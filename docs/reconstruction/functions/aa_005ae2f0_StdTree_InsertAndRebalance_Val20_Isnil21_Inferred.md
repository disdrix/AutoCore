# Function record: StdTree_InsertAndRebalance_Val20_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae2f0` |
| **Canonical name** | `StdTree_InsertAndRebalance_Val20_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_005ae2f0` |
| **Address** | `0x005ae2f0`–`0x005ae4da` inclusive (**491** B / `0x1EB`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL map-set helpers (Val20 / isnil@+0x21) |
| **Wave** | R12-034 OWN-ONLY dual 2026-08-05 |
| **Dual start** | 2646 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias history

- Ghidra: `FUN_005ae2f0`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_Mission_MissionStopLimit_005ae2f0` (**narrow/wrong** — shared STL helper; MissionStopLimit chain noise)
- Structural: `StdTree_InsertAndRebalance_Val20_Isnil21_Inferred` (product demangle open)

## Purpose

Always-allocate map/set node insert + RB rebalance for the **Val20 / isnil@+0x21** node family (node **0x24**, color@**+0x20**, Val20 5 dwords @+0x0C). Throws `"map/set<T> too long"` when `size ≥ 0xCCCCCCB`. Uses residual buynode `005ae1c0` and dualed L/R rotates `0050e9f0` / `005a27f0` (shared with Val16 isnil21 family). Sole parent shell `FUN_005aec50` (insert-or-find; composite int key) supplies placement.

## Signature (sealed)

```c
// __thiscall; ECX = map*; stack = (out**, addLeft, where*, value*); void; RET 0x10
void __thiscall StdTree_InsertAndRebalance_Val20_Isnil21_Inferred(
    /*ECX*/ MapShell* map,
    Node** out,
    char addLeft,
    Node* where,
    const Val20* value);
// *out = new node; root blackened
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x0C..+0x1C | Val20 (5×u32) |
| +0x20 | color (0=red, 1=black) |
| +0x21 | isnil |
| node size | **0x24** |
| tree+4 | head; head+4 = root; head+0 = leftmost; head+8 = rightmost |
| tree+8 | size |

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x005ae1c0` | buynode node 0x24 / Val20 | residual (not OWN) |
| `0x0050e9f0` | `StdTree_Lrotate_Isnil21_Inferred` | Lrotate leaf (R10-030 dualed) |
| `0x005a27f0` | `StdTree_Rrotate_Isnil21_Inferred` | Rrotate leaf (R11-007 dualed); partition parent |
| `0x005aec50` | insert-or-find Val20 | sole caller (not OWN) |
| `0x00407200` | `StdTree_InsertAndRebalance_Isnil21_Inferred` | peer Val16 / node 0x28 (same rotates; different max/buynode) |
| `0x005ae4e0` | `StdTree_InsertAndRebalance_Val12` | adjacent Val12 peer (different rotates/max) |

## Artifacts

- Raw (+ R12-034 re-verify): `docs/reconstruction/raw/aa_005ae2f0_FUN_005ae2f0.md`
- Annotated: `docs/reconstruction/raw/aa_005ae2f0_FUN_005ae2f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val20_Isnil21_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005ae2f0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_005ae2f0_StdTree_InsertAndRebalance_Val20_Isnil21_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005ae2f0_StdTree_InsertAndRebalance_Val20_Isnil21_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_005ae2f0_FUN_005ae2f0.md`
- Report: `docs/agents/task-dual-ab-005ae2f0-r12-report.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | `FUN_005ae1c0`, `FUN_0050e9f0`, `FUN_005a27f0` (×2), `_CxxThrowException`, `basic_string` / `exception` |
| **Callers (1)** | `FUN_005aec50` only |
| **Xrefs** | 1 UNCONDITIONAL_CALL @ `0x005aecaf` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| Always-insert + RB rebalance role | **High** |
| ABI thiscall + RET 0x10 | **High** |
| Val20 / node 0x24 / color@+0x20 / isnil@+0x21 | **High** |
| Size gate `0xCCCCCCB` | **High** |
| Sole caller `FUN_005aec50` | **High** |
| Name product English / demangle | **Inferred** |
| Runtime / differential | Open |
