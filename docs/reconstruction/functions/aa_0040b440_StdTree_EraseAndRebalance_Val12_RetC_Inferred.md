# Function record: StdTree_EraseAndRebalance_Val12_RetC_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b440` |
| **Canonical name** | `StdTree_EraseAndRebalance_Val12_RetC_Inferred` |
| **Ghidra name** | `FUN_0040b440` |
| **Address** | `0x0040b440` |
| **Body range** | `0x0040b440`–`0x0040b6d0` exclusive (**656** B / `0x290`) |
| **Ghidra listed end** | `0x0040b6a0` (false noreturn on `operator_delete`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer (partition R13-018; structural role = MSVC `_Tree` erase) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + throw + epilogue size-- sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) — **Terminal false** |
| **Dual A/B** | `reviews/A_aa_0040b440_StdTree_EraseAndRebalance_Val12_RetC_Inferred.md`, `reviews/B_aa_0040b440_StdTree_EraseAndRebalance_Val12_RetC_Inferred.md` |
| **Last reviewed** | `2026-08-05` (R13-018 OWN dual) |
| **Parent dual** | `0x0092b2a0` MissionTracker_FillTrackedTargetSlots_Inferred |
| **Dual start** | 2686 |

## Alias

- `FUN_0040b440`
- Scaffold: `aa_0040b440_FUN_0040b440`

## Purpose

MSVC-style `_Tree::erase(const_iterator)` for **Val12** nodes with **stack 3-arg / ret 0xC** ABI: nil-iterator throw, unlink, RB rebalance if erased black, `operator_delete`, size--, write out iterator.

## Signature

```c
void StdTree_EraseAndRebalance_Val12_RetC_Inferred(
    MapShell_Val12* map,     // stack0; +0x04 head, +0x08 size
    MapNode_Val12** outIt,   // stack1; *outIt = successor
    MapNode_Val12* node);    // stack2; node to erase
// RET 0xC  — NOT thiscall / NOT ret 8
```

## Layout (Val12)

| Field | Offset |
|---|---|
| left / parent / right | +0 / +4 / +8 |
| value (3 dwords) | +0x0C..+0x14 |
| color | **+0x18** |
| isnil | **+0x19** |
| node size | **0x1C** |

## Algorithm

1. If `node->isnil` → throw `"invalid map/set<T> iterator"`.
2. `FUN_00457cc0()` successor prep (Isnil19 iterator++).
3. Splice replacement; fix root / leftmost (`FUN_0043bf90`) / rightmost (`FUN_0040b8f0`).
4. Two-child successor-swap @ `0x0040b539` when both children non-nil.
5. If erased black → RB fixup with `FUN_00446b10` / `FUN_0040b910`.
6. `operator_delete(node)`; if size>0 then `--size`; `*outIt = successor`; `ret 0xC`.

## Artifacts

- Raw (+ R13-018 re-verify): `docs/reconstruction/raw/aa_0040b440_FUN_0040b440.md`
- Annotated: `docs/reconstruction/raw/aa_0040b440_FUN_0040b440.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Val12_RetC_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_0040b440.cpp`
- Function scaffold: `docs/reconstruction/functions/aa_0040b440_FUN_0040b440.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0040b440-r13-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00457cc0` (Isnil19 ++), `FUN_0043bf90` (min), `FUN_0040b8f0` (max), `FUN_00446b10` (Lrot), `FUN_0040b910` (Rrot), `FUN_00401bc0`, `operator_delete`, throw chain |
| **Callers** | `FUN_0040bc10` @ `0x0040bcae` (erase-range); `FUN_0092b2a0` @ `0x0092b741` (parent) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| `ret 0xC` + 3 stack args + size-- | **High** (bytes) |
| Val12 color@+0x18 / isnil@+0x19 | **High** |
| Throw string + ThrowInfo | **High** |
| 2 callers (range + MissionTracker parent) | **High** |
| Name `…_Val12_RetC_Inferred` | **_Inferred** (structural; ABI-distinguished from thiscall peer) |
| Product English / demangle | **Open** |
| Runtime / differential | **Open** |

## Related (do not merge)

| Unit | Why distinct |
|---|---|
| `0x004e4130` `StdTree_EraseAndRebalance_Val12` | **thiscall RET 8**; different rotates/min/iter pair |
| `0x005399f0` `Map_EraseNode_Val12` | peer clone; different helpers |
| `0x005ae990` `StdTree_EraseNode_Val12` | peer clone |
| `0x005e15a0` `StdTree_EraseAndRebalance_Val12_005e15a0` | VA-suffixed twin |
| `0x00405650` isnil21 erase | isnil@+0x21 / thiscall RET 8 |
| `0x00402850` isnil29 RetC erase | isnil@+0x29 |
| `0x00408ed0` isnil31 erase | isnil@+0x31 |

## Family helpers (this clone)

| Role | VA | Status |
|---|---|---|
| Iterator++ | `0x00457cc0` | dualed W38-B `StdTree_IteratorIncrement_Isnil19` |
| Min | `0x0043bf90` | residual |
| Max | `0x0040b8f0` | residual (R13-019 neighborhood) |
| Lrotate | `0x00446b10` | residual (also used by insert `0043c2e0`) |
| Rrotate | `0x0040b910` | residual |
| Erase-range parent | `0x0040bc10` | residual R13-020 |
