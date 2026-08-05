# Review B (skeptical / adversarial): `aa_00537770` Map predecessor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537770` |
| **VA** | `0x00537770` |
| **Canonical name** | `FUN_00537770` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial dual (attack over-claims) |
| **Counterpart** | `reviews/A_aa_00537770_Map_Predecessor.md` |
| **System** | shared map/tree helper |
| **Verdict** | **accept-with-gaps** on shape; **reject** insert/rebalance/key-domain claims |

---

## 1. What this is *not*

| Attack | Result |
|---|---|
| “Tree insert / rebalance / `operator_new`” | **Falsified** — leaf body; no CALL; no size/color writes |
| “Mission-staging-only helper” | **Falsified** — static callers also `FUN_00569320`, `FUN_00569560` |
| “Key compare / lower_bound” | **Falsified** — never reads key; only links + isnil |
| “Successor / `operator++`” | **Falsified** — isnil→**right** (max), then **left**-max or parent climb while **left**-child = classic **predecessor** |
| “Generic for all maps in the binary” | **Falsified as universal** — hard-coded isnil **`+0x49`**; other trees use `+0x29`, `+0x15`, `+0x1d`, `+0x641`, etc. |
| “Fixes / owns node payload” | **Falsified** — only `*pIt` store |
| “`__thiscall` map shell” | **Falsified** — ECX is **iterator\***, not map; no `this+4` head |
| Product export name `std::map::…` | **Unproven** — structural MSVC tree decrement only |

---

## 2. Decompiler hazards corrected by dual

| Decomp artifact | Reality |
|---|---|
| Callers show `FUN_00537770()` with **no args** | Asm/ABI: **`ECX = Node**`** (`__fastcall`); stack empty; `C3` |
| Scaffold clean “Notable callees: FUN_00537770” (self) | **False** — **zero** callees |
| Scaffold system `unknown` / dialog-callee alias chain | Role is **map iterator**, not mission-dialog logic; dialog is a distant caller chain only |
| “Human name: Named_CalleeOf_…RecvNpcMiss_…” | **Naming noise** — do not treat as product semantics |

---

## 3. Layout / CF challenges

| Challenge | Response | CF |
|---|---|---|
| Is isnil really `+0x49` not color? | Body only tests `+0x49`; staging dual seals color at `+0x48` separately | **High** isnil |
| Is “isnil → right” really end→max? | Matches MSVC head: head.right = rightmost; also matches insert dual use | **High** structural |
| Parent climb equality test `*pIt == *parent` | `*parent` is left*; equality ⇒ current is left child | **High** |
| Could this be successor with mirrored fields? | Successor would take right-min / climb while right-child; body uses left-max / left-child climb | **High** predecessor |
| Shared key offset? | **No** — `00539cb0` uses `+0x10`; `00569320` uses `+0x0C`; predecessor independent | **High** |

---

## 4. Surviving contract (minimal)

```
// __fastcall  ECX = Node** pIt
void Map_Tree_Predecessor_Isnil49(Node** pIt);
// RET (C3) — no stack cleanup
//
// Requires nodes with:
//   left@0, parent@4, right@8, isnil@0x49
// Mutates *pIt to in-order predecessor (or rightmost if *pIt was end/head).
// Does NOT: allocate, rebalance, compare keys, read color, touch map shell.
//
// Do NOT port as map insert. Do NOT assume key@+0x10 for all callers.
```

---

## 5. Cross-check vs dual A

| A claim | B stance |
|---|---|
| `__fastcall` ECX iterator*, `C3` | **Agree** |
| isnil `+0x49`; links 0/4/8 | **Agree** |
| Leaf predecessor algorithm | **Agree** |
| Not insert/rebalance | **Agree** — critical |
| Three static callers | **Agree** (static xrefs) |
| Key layout caller-specific | **Agree** |
| Product English open | **Agree** — keep open |
| Role High / English Tentative | **Agree** |

---

## 6. Residual (honest)

1. Product / MSVC template English name.
2. Full node schemas for `00569320` / `00569560` maps (only isnil/link contract sealed here).
3. Runtime edge cases (`--begin`, empty tree, single element).
4. Bit-exact image diff.
5. Indirect calls (none static).

---

## 7. Verdict

### **accept-with-gaps**

ABI, CF, link/isnil geometry, leaf predecessor role, and multi-caller sharing are **sealed**. Reject insert/rebalance, successor, mission-only, and fixed-key-offset claims. Dual A layout partial is acceptable with product name and non-staging full node schemas open.
