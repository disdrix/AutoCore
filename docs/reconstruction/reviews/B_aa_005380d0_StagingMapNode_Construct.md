# Review B (skeptical / adversarial): `aa_005380d0` Staging map node construct

| Field | Value |
|---|---|
| **Stable ID** | `aa_005380d0` |
| **VA** | `0x005380d0` |
| **Canonical name** | `FUN_005380d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial dual (attack over-claims) |
| **Counterpart** | `reviews/A_aa_005380d0_StagingMapNode_Construct.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** on shape; **reject** tree-insert/rebalance/mission-logic roles and decomp `void` |

---

## 1. What this is *not*

| Attack | Result |
|---|---|
| “Map insert / rebalance / size++” | **Falsified** — only `new` + field init; link/size/RB loop live in `FUN_00538ea0` |
| “Mission eligibility / GiveMission / dialog” | **Falsified** — pure memory construct; no def reads |
| “Generic shared node ctor for all maps” | **Partial** — **this** VA is specialized (0x50, value 14 dwords, isnil `+0x49`); static xrefs = only `FUN_00538ea0`. Sibling maps use other construct VAs (e.g. category-CD `new(0x1C)`) |
| “`void` / no return” | **Falsified** — EAX = node\*; caller `mov ecx,eax` |
| “`__thiscall` on map or node” | **Falsified** — freestanding; five stack args; `RET 0x14` |
| “Copies entire 0x50 including color from pair” | **Falsified** — only 0xE dwords @ `+0x10`; color is separate arg; isnil forced 0 |
| “Initializes `+0x0C` / pad tail” | **Falsified** — no stores to `+0x0C` or `+0x4A..` |
| “Always non-null” | **Falsified** — null `new` skips init and returns 0 (caller still increments size — **caller** hazard, not this unit’s invent) |
| Product name `std::_Tree_node` as export | **Unproven** — MSVC map-node shape; no PDB string for this instance |

---

## 2. Decompiler hazards corrected by dual

| Decomp artifact | Reality |
|---|---|
| `void FUN_005380d0(...)` | **Returns `StagingMapNode*` in EAX** — alloc pointer never reassigned; caller consumes EAX |
| Write order left, right, parent vs left, parent, right | Asm stores left, then right, then parent — **same final fields**; no observable difference |
| Copy loop `for (i=0xe; …)` | Image: **`REP MOVSD`** with `ECX=0xE` — bit-equivalent bulk copy |
| `param_5` as free-standing `undefined1` without stack slot size | Passed in **dword stack slot** (`RET 0x14` = 5×4); only low byte used |
| Scaffold clean “Notable callees: FUN_005380d0” | **False self-ref** — only callee is `operator_new` |

---

## 3. Layout challenges

| Challenge | Response | CF |
|---|---|---|
| Is size really 0x50 (not 0x4C / 0x54)? | `push 0x50` + stores only through `+0x49`; parent dual uses same | **High** |
| Is value 14 dwords or only 12 payload? | `ECX=0xE`; parent store builds key+pad+12 contiguous | **High** |
| Is color/isnil swapped? | `mov [eax+0x48],dl` then `mov byte [eax+0x49],0`; rebalance in `FUN_00538ea0` reads `+0x48` as color | **High** |
| Does caller pass black (1) sometimes? | This insert path always pushes **0**; other colors only via rebalance later | **High** for this call edge |
| Left=right=head always? | Only caller always passes `*(map+4)` for both; other hypothetical call sites: none static | **High** (static) |

---

## 4. Surviving contract (minimal)

```
// freestanding; RET 0x14; EAX = node* or 0
StagingMapNode* StagingMapNode_Construct(
    StagingMapNode* left,
    StagingMapNode* parent,
    StagingMapNode* right,
    const uint32_t valuePair[14],  // key, pad, payload[12]
    uint8_t color);

// On success:
//   node->{left,parent,right} = args
//   memcpy(node+0x10, valuePair, 0x38)
//   node->color = color; node->isnil = 0
//   +0x0C and +0x4A..+0x4F untouched
// On new failure: return 0 (no stores)

// Do NOT claim this unit:
//   - tree insertion, rotations, size++, head leftmost/rightmost updates
//   - equal-key upsert / payload rewrite
//   - mission rule evaluation
```

---

## 5. Cross-check vs dual A

| A claim | B stance |
|---|---|
| `RET 0x14` + 5 stack args | **Agree** |
| Return node\* in EAX (decomp void wrong) | **Agree** — critical |
| Size `0x50`, links `+0/+4/+8`, value 14 dwords @ `+0x10` | **Agree** |
| color `+0x48`, isnil `+0x49=0` | **Agree** |
| `+0x0C` / tail uninit | **Agree** |
| Sole caller `FUN_00538ea0`; color 0 on insert | **Agree** (static) |
| Product English open | **Agree** — keep open |
| Role “staging map node construct” High | **Agree** role; English name Tentative |

---

## 6. Residual (honest)

1. Product / export / typedef name.
2. Exact English for pad dword `+0x14`.
3. Whether any dynamic/indirect call reaches this VA (none found statically).
4. Caller behavior if `new` returns null (size++ still in `FUN_00538ea0`) — owned by insert helper dual, not re-sealed here beyond noting the edge.
5. Runtime multi-mission insert capture; bit-exact image diff.

---

## 7. Verdict

### **accept-with-gaps**

ABI, CF, node geometry, copy width, color/isnil, and return-in-EAX are **sealed**. Reject insert/rebalance/mission-logic claims and decompiler `void`. Dual A layout table is acceptable with product name open.
