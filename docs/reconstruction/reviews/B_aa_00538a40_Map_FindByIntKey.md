# Review B (skeptical / adversarial): `aa_00538a40` Tree find (int key)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538a40` |
| **VA** | `0x00538a40` |
| **Canonical name** | `FUN_00538a40` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial dual (attack over-claims) |
| **Counterpart** | `reviews/A_aa_00538a40_Map_FindByIntKey.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** on CF/ABI/geometry; **reject** pure “lower_bound returns greater key” and product-name claims |

---

## 1. What this is *not*

| Attack | Result |
|---|---|
| “Generic reward-region *logic*” | **Falsified** — no field reads past key; only tree walk + out node* |
| “Insert / erase” | **Falsified** — leaf; no callees; no stores into tree |
| “Returns node* in EAX” | **Falsified** — result only via `*ppOut`; both paths `ret 8` after writing out |
| “`void` is decompiler lying (like 0052c700)” | **Reject attack** — here void is **correct** (unlike staging store) |
| “Pure `lower_bound` (may return first greater)” | **Falsified as public contract** — final `JL` rejects `key < node.key`, so miss→head; **effective find** |
| “Only used for reward UI” | **Falsified** — also staging upsert, clear, GiveMission prior-state |
| “Key is unsigned” | **Falsified** — signed `JGE`/`JL` on compares |
| “isnil at +0x1d like XP map” | **Falsified** — this map uses **`+0x49`** (larger node / different value type) |
| Product export name | **Unproven** — no string |

---

## 2. Decompiler hazards

| Decomp artifact | Reality |
|---|---|
| Callers show `FUN_00538a40(local,&key)` missing map `this` | Asm: `LEA ECX,[char+0x508]` before `CALL` |
| Signature `void` with junk EAX | Out-param only; ignore residual EAX |
| `param_2` typed `undefined4*` | Really `node**` / iterator out |
| Naming “lower_bound” in prior sibling reviews | **Walk** is lower_bound; **contract** is find (exact). Prefer “find” or “lower_bound+eq” |

---

## 3. Equality gate proof (why not pure lower_bound)

Walk invariants (standard MSVC lower_bound):

- On left branch: candidate updated; property preserved that any remaining hit has `node.key ≥ key`.
- On right branch: discard nodes with `node.key < key`.

After walk, candidate is either head or first node with `node.key ≥ key`.

Final asm:

```
CMP *pKey, candidate.key
JL  → write head   // key < node.key  ⇒ not equal
// else write candidate               // key ≥ node.key ∧ node.key ≥ key ⇒ equal
```

Therefore **out == head XOR exact key match**. Callers that only test `out != *(char+0x50c)` are safe **because** greater-key lower_bound results are forced to end.

If this were pure lower_bound without the gate, `FUN_0052dac0` would false-hit the next larger mission id’s region — **not observed** in CF of that unit (returns `node+0x18` on any non-sentinel). Gate is load-bearing.

---

## 4. Layout challenges

| Challenge | Response | CF |
|---|---|---|
| Is `+0x49` color or isnil? | Treated as **isnil/end-child** (loop while clear); MSVC tree nil flag. Color bit may coexist elsewhere — **not read here**. | High role |
| Is head always at `this+4`? | Only field of `this` read | High |
| Does value start at `+0x18`? | **Not proven by this function** — sibling `FUN_0052dac0` adds `+0x18`. Out of OWN except cross-ref. | Sibling High |
| Same template as `0x004054f0`? | Same algorithm; **different** isnil offset (`+0x1d` vs `+0x49`) and key dword index | High “family”, distinct instance |

---

## 5. Surviving contract (minimal)

```
// thiscall Map*
void Map_FindByIntKey(Map* map, Node** out, const int* key);
// map+4 = head (end)
// node: left@0 parent@4 right@8 key@0x10 isnil@0x49
// *out = matching node OR head
// exact int key only; no payload access
// ret 8
```

Do **not** treat as:

- reward content interpreter
- insert hint without re-find
- unsigned key compare
- EAX-returned node*

---

## 6. Cross-check vs dual A

| A claim | B stance |
|---|---|
| Leaf, ret 8, thiscall | **Agree** |
| isnil `+0x49`, key `+0x10` | **Agree** |
| Exact-find contract | **Agree** — insist naming reflects find not pure lower_bound |
| Domain via `+0x508` callers | **Agree** as **caller role**, not self-describing |
| Product English open | **Agree** — keep open |
| STL `std::map` typedef sealed | **Reject** — shape High only |

---

## 7. Residual (honest)

1. Product / export name.
2. Color bit / full `std::_Tree_node` layout beyond fields this unit touches.
3. Proof of maps **other than** `+0x508` family (none in current xref set).
4. Runtime observation of multi-key tree.
5. Formal rename in Ghidra (still `FUN_00538a40`).

---

## 8. Verdict

### **accept-with-gaps**

Shape, ABI, exact-find gate, and offsets this body reads are **sealed**. Reject pure-lower_bound public contract and product naming. Dual A’s evidence table is acceptable if “find / lower_bound+eq” language is used and domain English stays caller-qualified.
