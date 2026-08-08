# Function record: StdTree_Buynode_CharKey_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041d860` |
| **Canonical name** | `StdTree_Buynode_CharKey_Isnil21_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_0041d860` |
| **Address** | `0x0041d860`–`0x0041d8e5` inclusive (**134 B** / `0x86`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x0041d860`–`0x0041d8e5` |
| **System** | skills-abilities / MSVC `std::_Tree` node allocation |
| **Agent** | R13-023 OWN-ONLY dual 2026-08-05 |
| **Parent dual** | `0x0041ba30` StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred (R12-011) |
| **Dual start** | 2686 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

MSVC-style `_Tree` buynode for the **isnil@+0x21** family with **char key** at `+0x0C` and residual value body at `+0x10`. Allocates **0x24**, stores links + key + color + isnil=0, constructs residual payload via thiscall `FUN_0041c140` on `node+0x10`. Returns null on OOM. Used exclusively by dualed always-insert `FUN_0041ba30`.

## Signature

```c
NodeCharKeyIsnil21* __stdcall StdTree_Buynode_CharKey_Isnil21_Inferred(
    NodeCharKeyIsnil21* left,
    NodeCharKeyIsnil21* parent,
    NodeCharKeyIsnil21* right,
    const CharKeyValueInferred* value,  // key@+0; residual payload@+4
    uint8_t color);
// RET 0x14; EAX = node* | null
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x0C | char key |
| +0x10 | residual value body (vector-like; elem stride 0x18 via residual ctor) |
| +0x20 | color (0 red / 1 black) |
| +0x21 | isnil (forced 0) |
| size | **0x24** |

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | `FUN_0041ba30` / `StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred` @ `0x0041ba9d` — args `(head, where, head, value*, color=0)` |
| Alloc | `operator_new(0x24)` |
| Construct | residual `FUN_0041c140` (thiscall @ node+0x10) |
| Contrast | Val16/isnil21 buynode `0x00408990` (node 0x28); Val24/isnil29 buynodes `0x00407e30` / `0x005a2de0` |

## Evidence summary

- Live decompile ≡ raw CF; epilogue `RET 0x14` via `read_memory` / disasm (`C2 14 00` @ `0x0041d8e3`).
- Insert parent dual R12-011 passes `(head, where, head, value, 0)` → red node; rebalance reads color @+0x20 / isnil @+0x21.
- Char key store @+0x0C sealed in bytes; parent placement compare also uses node+0x0C (evidence only).
- Prior generic scaffold / chain-of-caller names **narrow** to structural `_Inferred` name.
- **Never Runtime Confirmed** this dual.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Buynode_CharKey_Isnil21_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_0041d860.cpp`
- Raw: `docs/reconstruction/raw/aa_0041d860_FUN_0041d860.md`
- Annotated: `docs/reconstruction/raw/aa_0041d860_FUN_0041d860.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_0041d860_StdTree_Buynode_CharKey_Isnil21_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0041d860_StdTree_Buynode_CharKey_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-0041d860-r13-report.md`
