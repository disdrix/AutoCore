# Review B (skeptical / adversarial): `aa_005a2850` Map_Tree_Predecessor_Isnil15

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2850` |
| **VA** | `0x005a2850` |
| **Canonical name** | `Map_Tree_Predecessor_Isnil15` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial dual (attack over-claims) |
| **Counterpart** | `reviews/A_aa_005a2850_Map_Tree_Predecessor_Isnil15.md` |
| **System** | shared map/tree helper |
| **Wave** | W19-N OWN |
| **Verdict** | **accept-with-gaps** |

---

## 1. What this is *not*

| Attack | Result |
|---|---|
| “Tree insert / rebalance / `operator_new`” | **Falsified** — leaf; no CALL; no size/color writes |
| “Successor / `operator++`” | **Falsified** — isnil→**right** (max), left-max, climb while **left**-child = **predecessor** |
| “Universal for all maps in the binary” | **Falsified as universal** — hard-coded isnil **`+0x15`**; peers use `+0x49`, `+0x29`, `+0x1d`, `+0x21`, … |
| “Fixes / owns node payload / keys” | **Falsified** — only `*pIt` store |
| “`__thiscall` map shell” | **Falsified** — ECX is **iterator\***, not map; no `this+4` head |
| Scaffold `Named_CalleeOf_…VOG_DEBUG_STOP…` product meaning | **Reject** — assert string is distant caller noise |
| Product `std::map::…` export name | **Unproven** — structural name only |

---

## 2. Decompiler hazards corrected by dual

| Decomp artifact | Reality |
|---|---|
| Callers show `FUN_005a2850()` with **no args** | Asm/ABI: **`ECX = Node**`**; stack empty; `C3` |
| Scaffold “Notable callees: FUN_005a2850” (self) | **False** — **zero** callees |
| Scaffold system `unknown` / VOG_DEBUG alias | Role is **map iterator**, not debug-stop logic |
| Analyze `return_type undefined` | **void** (no EAX product) |

---

## 3. Layout / CF challenges

| Challenge | Response | CF |
|---|---|---|
| Is isnil really `+0x15` not color? | Body only tests `+0x15`; never reads color | **High** isnil |
| Is “isnil → right” end→max? | Matches MSVC head.right = rightmost; insert duals use as predecessor | **High** |
| Parent climb `*pIt == *parent` | `*parent` is left*; equality ⇒ left child | **High** |
| Could this be successor with mirrored fields? | Successor uses right-min / climb while right-child; body is left-max / left-child | **High** predecessor |
| Shared key offset? | **No** — predecessor never reads key | **High** |

---

## 4. Surviving contract (minimal)

```
// __fastcall  ECX = Node** pIt
void Map_Tree_Predecessor_Isnil15(Node** pIt);
// RET (C3) — no stack cleanup
//
// Requires nodes with:
//   left@0, parent@4, right@8, isnil@0x15
// Mutates *pIt to in-order predecessor (or rightmost if *pIt was end/head).
// Does NOT: allocate, rebalance, compare keys, read color, touch map shell.
//
// Do NOT port as map insert. Do NOT assume a fixed key offset for all callers.
```

---

## 5. Cross-check vs dual A

| A claim | B stance |
|---|---|
| `__fastcall` ECX iterator*, `C3` | **Agree** |
| isnil `+0x15`; links 0/4/8 | **Agree** |
| Leaf predecessor algorithm | **Agree** |
| Not insert/rebalance | **Agree** — critical |
| 21 static callers | **Agree** (analyze count) |
| Key layout caller-specific | **Agree** |
| Product English open | **Agree** |

---

## 6. Residual (honest)

1. Product / MSVC template English name.
2. Full node schemas for the 21 caller maps.
3. Runtime edge cases (`--begin`, empty tree, single element).
4. Bit-exact image diff.
5. Indirect calls (none static).

---

## 7. Verdict

### **accept-with-gaps**

ABI, CF, link/isnil geometry, leaf predecessor role, and multi-caller sharing are **sealed**. Reject insert/rebalance, successor, universal-isnil, and product-name certainty. Dual A accept-with-gaps is appropriate.
