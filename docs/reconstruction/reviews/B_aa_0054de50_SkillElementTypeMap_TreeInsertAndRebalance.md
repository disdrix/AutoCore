# Review B (skeptical / adversarial): `aa_0054de50` SkillElementTypeMap_TreeInsertAndRebalance

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054de50` |
| **VA** | `0x0054de50` |
| **Canonical name** | `SkillElementTypeMap_TreeInsertAndRebalance` |
| **Review date** | `2026-07-29` (W20-B OWN-ONLY dual) |
| **Reviewer role** | Adversarial dual (attack over-claims) |
| **Counterpart** | `reviews/A_aa_0054de50_SkillElementTypeMap_TreeInsertAndRebalance.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** on shape; **reject** find/upsert/skill-logic roles |

---

## 1. What this is *not*

| Attack | Result |
|---|---|
| “Insert-or-find / may not allocate” | **Falsified** — always `FUN_006173a0` + `size++`; no key walk |
| “Equal-key payload update” | **Falsified** — no key compare; parent owns equal path |
| “Skill cast / damage / cooldown logic” | **Falsified** — pure tree mutator; only string is STL length text |
| “Same insert helper as every map” | **Partial** — algorithm is STL `_Tree` insert; **this VA** is specialized to **0x18** nodes (color `+0x14`, isnil `+0x15`, size cap `0x1ffffffd`). Staging uses `0x00538ea0` (0x50 / cap `0x4924922`); AI timer map uses `0x005d20b0` |
| “`RET 8` like parent insert-or-find” | **Falsified** — epilogue **`C2 10 00`** (four stack args); parent is `C2 08 00` |
| “Self-recursive” | **Falsified** — scaffold listed self-callee; body does not call self |
| “color 0 = black” | **Falsified** — new color **0**, loop while parent **0**, root set **1** → **0=red, 1=black** |
| Product export `std::map::_Insert` | **Unproven** — structure matches; no PDB name |

---

## 2. Decompiler hazards corrected by dual

| Decomp artifact | Reality |
|---|---|
| `void` return | Contract is `*outIt = newNode`; not a register return of node |
| `undefined4 *` params | Fixed-width pointers / value pair; avoid bare `undefined4` in clean |
| `param_1` as plain `int` | ECX **MapShell*** |
| Rotate calls show partial args | Map thiscall ECX + node* — roles sealed; exact this-passing recovered from parent dual pattern |
| Scaffold name chain via VOG_DEBUG | **Misleading** — sole static caller is skill-element type map insert-or-find |
| Size cap confusable with staging `0x4924922` | **Distinct** — this unit uses **`0x1ffffffd`** (byte `fe ff ff 1f`) |

---

## 3. Layout challenges

| Challenge | Response | CF |
|---|---|---|
| Node size shared with staging map? | Staging ctor `new(0x50)`; this `new(0x18)` | **High** distinct |
| Is `+0x14` isnil not color? | ctor stores color arg at dword5 low byte (`+0x14`); isnil forced at `+0x15`; rebalance reads parent `+0x14` | **High** |
| Size limit magic wrong? | Bytes `cmp [edi+8], 0x1ffffffd` + `jb` past throw | **High** |
| Head layout not leftmost/root/rightmost? | Empty insert writes all three; left/right update head extrema | **High** |
| Multiple callers beyond catalog? | `get_xrefs_to` / callers: **only** `FUN_0054eb20` (2 sites) | **High** |

---

## 4. Surviving contract (minimal)

```
// thiscall on MapShell
// ALWAYS inserts a new node (caller must ensure miss / correct where+addLeft)

void SkillElementTypeMap_TreeInsertAndRebalance(
    MapShell* map,          // ECX
    Node** outIt,           // *outIt = newly allocated node
    char addLeft,           // 1 → left child of where; 0 → right
    Node* where,            // parent, or head if tree empty
    const IntPtrPair* value // {key, factory*} → node+0x0C
);
// RET 0x10
//
// Throws if map->size > 0x1ffffffd ("map/set<T> too long")
// Node: new(0x18), color red (0), isnil 0, RB rebalance, root black
//
// Do NOT call for equal-key refresh — parent FUN_0054eb20 handles find-only.
```

---

## 5. Cross-check vs dual A

| A claim | B stance |
|---|---|
| `RET 0x10` + 4 stack args | **Agree** |
| Always alloc + rebalance | **Agree** — critical vs parent insert-or-find |
| color `+0x14` / isnil `+0x15` / node `0x18` / 2 dwords | **Agree** |
| 0=red, 1=black | **Agree** |
| Size cap `0x1ffffffd` + throw string | **Agree** |
| Sole static caller `0x0054eb20` | **Agree** |
| Product English open | **Agree** |
| Rotate helper English names | Roles **High**, names **Tentative** |

---

## 6. Residual risk

1. Rotate VAs not dual-owned this wave — role High, product name open.
2. Node ctor dual residual.
3. No runtime / CE proof of insert under live catalog register.
4. Dynamic calls not observed.

**Verdict:** **accept-with-gaps** — reject any skill-domain business logic claim; accept structural always-insert RB helper sealed by string, size cap, node ctor, and sole parent.
