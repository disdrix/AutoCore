# Function record: StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404360` |
| **Canonical name** | `StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_00404360` |
| **Address** | `0x00404360`–`0x0040438C` exclusive (**44 B** / `0x2C`) |
| **Body epilogue** | `RET 0xC` (`C2 0C 00` @ end of body) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `std::_Tree` node construct |
| **Calling convention** | `__usercall`: node@&lt;eax&gt;, left@&lt;ecx&gt;, parent@&lt;edx&gt;, right/value*/color stack; **`ret 0xc`** |
| **Partition** | R10-021 — residual dual under parent `0x00403f30` (missions-progression) |
| **Agent** | R10-021 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00404360_StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred.md` |
| **Dual B** | `reviews/B_aa_00404360_StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred.md` |
| **Last reviewed** | `2026-08-05` (R10-021) |

## Alias

- Ghidra: `FUN_00404360`
- Reject: `Named_CalleeOf_*Client_*` / multi-hop NotifyActiveMission scaffold plate
- Reject: freelist / placement-new / CNDHash init
- Reject: naming as **buynode** (no `operator_new`; parent `00403f30` owns alloc)
- Reject: merge with Val24 isnil29 NodeCtor `00409880` / `004098d0` or Val16 isnil21 `004099b0`

## Purpose

MSVC-style **tree node construct** (no allocation) for the **isnil@+0x31 / Val32** family using **EAX-this** usercall ABI:

1. left/parent/right → +0/+4/+8
2. eight dwords from value* → +0x10 (**Val32**)
3. color → +0x30; isnil → +0x31 = 0

Sole caller buynode `StdTree_Buynode_Val32_Isnil31_Inferred` (`FUN_00403f30`) supplies node from `operator_new(0x38)`. That buy is used exclusively by residual insert/rebalance `FUN_00403250` (same isnil31 family as dualed Lrotate `00403e90` / Rrotate `00403ee0` / erase `00408ed0` / BuyHead `00409180`).

## Signature

```c
/* __usercall node@<eax>(left@<ecx>, parent@<edx>, right, value*, color); ret 0xc */
void StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred(
    NodeIsnil31_Val32* node,
    NodeIsnil31_Val32* left,
    NodeIsnil31_Val32* parent,
    NodeIsnil31_Val32* right,
    const uint32_t value8[8],
    uint8_t color);
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x0C | untouched by this ctor |
| +0x10 | value (8× uint32 / Val32) |
| +0x30 | color (0 red / 1 black) |
| +0x31 | isnil (forced 0) |
| size (parent alloc) | **0x38** |

## Behavioral summary

```
node.left/parent/right = left/parent/right
node.val[0..7] = value8[0..7]     ; REP MOVSD ×8
node.color = color                ; +0x30
node.isnil = 0                    ; +0x31
return  ; RET 0xC
```

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | `StdTree_Buynode_Val32_Isnil31_Inferred` (`FUN_00403f30`) @ `0x00403f86` |
| **Grandparent insert** | `FUN_00403250` insert/rebalance isnil31 (MEGA-047 residual; not OWN) |
| **Callees** | none (leaf) |
| **Family** | Lrot `00403e90`, Rrot `00403ee0`, erase `00408ed0`, BuyHead `00409180` |
| **Contrast** | isnil29 Val24 NodeCtor `00409880`/`004098d0` — **do not merge** |

## Evidence summary

- Live decompile ≡ raw CF; epilogue `RET 0xC` via `read_memory` hex `C2 0C 00`.
- `REP MOVSD` ECX=**8** seals Val32; hard `MOV byte [EAX+0x31],0` seals isnil.
- Sole xref/caller buynode @ `00403f86` (parent dual MEGA-048).
- Prior chain-of-caller `Named_CalleeOf_*` scaffold **retired**.

## Gaps

- Product / PDB demangle for value_type.
- Runtime / bit-exact / differential.
- Insert parent dual not OWN.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00404360.cpp`
- Retired scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00404360.cpp`
- Raw: `docs/reconstruction/raw/aa_00404360_FUN_00404360.md`
- Annotated: `docs/reconstruction/raw/aa_00404360_FUN_00404360.annotated.md`
- FUN record: `docs/reconstruction/functions/aa_00404360_FUN_00404360.md`
- Review A: `docs/reconstruction/reviews/A_aa_00404360_StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00404360_StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred.md`
- Report: `docs/agents/task-dual-ab-00404360-r10-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF + store map + RET 0xC | **High** |
| EAX/ECX/EDX ABI | **High** |
| Val32 / isnil31 family | **High** |
| Product demangle | **Inferred** |
| Runtime / bit-exact | **Open** |
