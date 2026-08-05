# Review B (skeptical / adversarial): `aa_00430b60` StdMap_StringKey_InsertNodeAndRebalance

| Field | Value |
|---|---|
| **Stable ID** | `aa_00430b60` |
| **VA** | `0x00430b60` |
| **Canonical name** | `StdMap_StringKey_InsertNodeAndRebalance` (**Inferred**) |
| **Review date** | `2026-07-29` (OWN-ONLY dual B — W22-E) |
| **Reviewer role** | Adversarial dual (attack over-claims) |
| **Counterpart** | `reviews/A_aa_00430b60_StdMap_StringKey_InsertNodeAndRebalance.md` |
| **System** | stl-map |
| **Verdict** | **accept-with-gaps** on shape; **reject** find/upsert/ECX-thiscall-map claims |

---

## 1. What this is *not*

| Attack | Result |
|---|---|
| “Insert-or-find / may not allocate” | **Falsified** — always `FUN_0042a890` + `size++`; no key walk |
| “Equal-key payload update” | **Falsified** — no key compare; parents own equal |
| “Standard ECX `__thiscall` on map” | **Falsified** — map is **EDI**; ECX is **where**; `ret 0x0C` |
| “Generic insert shared by every map” | **Partial** — algorithm is STL `_Tree` insert; **this VA** is **0x30** / color `+0x2C` specialized |
| “Color 0 = black” | **Falsified** — new node color **0**, loop while parent **0**, then paint **1** → **0=red, 1=black** |
| “Self-recursive rebalance” | **Falsified** — scaffold listed self-callee noise; body does not call self |
| Product export `std::map::_Insert` | **Unproven** — structure matches; no PDB for this instance |

---

## 2. Decompiler hazards corrected by dual

| Decomp artifact | Reality |
|---|---|
| `__thiscall` + `unaff_EDI` | Map **EDI** register ABI; ECX = where |
| Missing third stack formal (value) | Node ctor loads key from stack; **3** stack args → `ret 0x0C` |
| `FUN_0042a890(head, where, head, 0)` only | ECX = valuePair; color 0 pushed |
| `piVar6[0xb]` uncle color | `0xb*4 = 0x2C` — same color byte |
| Rotate “one arg” | Tree + node; isnil `+0x2D` on callees |
| Scaffold `Named_CalleeOf_…Client_InitI` | **False** product name — xref-seed rename |

---

## 3. Layout challenges

| Challenge | Response | CF |
|---|---|---|
| Same node as 0x4C / 0x50 maps? | ctor **`new(0x30)`**; color **+0x2C** not +0x48 | **High** distinct |
| `+0x2C` isnil not color? | ctor: color arg → +0x2C, isnil forced 0 @ +0x2D; rebalance reads +0x2C; rotates guard +0x2D | **High** |
| Size limit wrong? | Bytes `cmp [edi+8],0x07FFFFFE` / `jb` ≡ decomp `size > 0x7FFFFFD` | **High** |
| Head not leftmost/root/rightmost? | Empty insert writes all three; left/right update head[0]/head[2] | **High** |

---

## 4. Surviving contract (minimal)

```
// NOT ECX-thiscall for map
// EDI = MapShell* (head@+4, size@+8)
// ECX = Node* where
// stack: Node** outIt, char addLeft, const void* valuePair
// RET 0x0C
//
// ALWAYS inserts (caller ensures miss + correct where/addLeft)
// Throws if size > 0x7FFFFFD ("map/set<T> too long")
// Node: new(0x30), red, isnil 0, string@+0x0C, mapped@+0x28, color@+0x2C
// RB rebalance; root black; *outIt = new
//
// Do NOT call for equal-key refresh — parent FUN_004309c0 handles find.
```

---

## 5. Cross-check vs dual A

| A claim | B stance |
|---|---|
| `ret 0x0C` + EDI map + ECX where | **Agree** |
| Always alloc + rebalance | **Agree** |
| Node 0x30 / color +0x2C / isnil +0x2D | **Agree** |
| 0=red, 1=black | **Agree** |
| Rotates L=`0044e010` / R=`0042a840` | **Agree** roles |
| Callers 004309c0 / 004303c0 / 0044d9f0 | **Agree** (static xrefs) |
| Product English open | **Agree** |
| Helper English names | Roles **High**, names **Tentative** |

---

## 6. Residual (honest)

1. Product / export / typedef name.
2. Dynamic/indirect call sites beyond static xrefs (none found).
3. Runtime insert rebalance capture.
4. Bit-exact image diff vs clean rewrite.
5. Full mapped-value English beyond dword @ `+0x28`.

---

## 7. Verdict

### **accept-with-gaps**

ABI (EDI map / ECX where / `ret 0x0C`), always-insert CF, size cap, node geometry, color convention, rotation helpers, and static callers are **sealed**. Reject find/upsert and ECX-thiscall-on-map claims. Dual A layout table acceptable with product name open.
