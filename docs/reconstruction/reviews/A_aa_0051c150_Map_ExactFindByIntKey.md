# Review A (reconstruction fidelity): `aa_0051c150` Map_ExactFindByIntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051c150` |
| **VA** | `0x0051c150` |
| **Canonical name** | `Map_ExactFindByIntKey` (structural; Ghidra plate still `FUN_0051c150`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0051c150_Map_ExactFindByIntKey.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **ordered tree exact find** for an **int** key. `__thiscall(this=mapHeader, pOutNode, pKey)`.

Walks from root `*( *(this+4) + 4 )` (head→parent), using nil flag **`node+0x29`**, key at **`node+0x10`** (`node[4]` as dword), left `*node`, right `node+0x08`. After the lower-bound-style walk, **accepts only exact match**: candidate ≠ end **and** `node.key <= *pKey` (combined with walk invariant `key >= *pKey` ⇒ equality). On miss, writes **end** `*(this+4)` into `*pOutNode`.

**Read-only** — no insert/erase/allocation. Used by active-cast binding lookup and clear as the map find for skill-id keys (node value TFID is **caller-owned**; this body only returns the node pointer).

Distinct layout from sibling helpers:

| Helper | Nil / color-ish | Key slot | Op |
|---|---|---|---|
| `Map_LowerBoundFindByIntKey` (`0x0050f940`) | `+0x15` | `node[3]` | lower_bound |
| `StdMap_LowerBoundByIntKey_INFERRED` (`0x004054f0`) | `+0x1d` | `node[3]` | lower_bound |
| **`Map_ExactFindByIntKey` (`0x0051c150`)** | **`+0x29`** | **`node+0x10` / `[4]`** | **exact find** |

Node factory for this tree (`FUN_0058d9c0`, sibling leave-FUN `FUN_00518c20`) allocates **`0x30`** blocks and sets head nil at **`+0x29`** — consistent with this walk.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051c150_FUN_0051c150.md` |
| Annotated | `docs/reconstruction/raw/aa_0051c150_FUN_0051c150.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0051c150.cpp` |
| Named alias clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Skill_LookupActiveCastBinding_0051c150.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051c150_FUN_0051c150.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x0051c150` (2026-07-29) |
| Force redecompile | Ghidra `force_decompile` @ `0x0051c150` — **identical CF** |
| Bytes | `read_memory` 80 B @ `0x0051c150` — nil `cmp byte [reg+0x29]`, key `cmp [reg+0x10]`, exit `ret 8` |
| Xrefs | `get_function_xrefs` / `get_function_callers` |
| Parent duals | `A\|B_aa_00518cf0_Skill_LookupActiveCastBinding`, `A\|B_aa_00518c20_FUN_00518c20` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature `__thiscall(map*, Node** out, int* key)` void | **Confirmed** | decompile + `ret 8` (two stack args) |
| `this+4` = end / `_Myhead` | **Confirmed** | body both arms |
| Root = `head[1]` (`head+4` parent) | **Confirmed** | decompile + asm |
| Nil flag byte `node+0x29 == 0` means real node | **Confirmed** | decompile + `read_memory` `80 78 29 00` |
| Key int at `node+0x10` | **Confirmed** | decompile `puVar[4]` + asm `39 70 10` / `3b 4a 10` |
| Left child `*node` (+0); right `node+8` | **Confirmed** | body |
| Walk is lower_bound-shaped (`key < search` → right else left+candidate) | **Confirmed** | body |
| Post-check enforces **exact** match (`cand≠end && cand.key <= search`) | **Confirmed** | body; with walk ⇒ equality |
| Miss / empty → `*out = end` | **Confirmed** | body |
| No callees (leaf helper) | **Confirmed** | decompile; no CALL in body bytes |
| Not insert / not erase / not lower_bound-only API | **Confirmed** / **Falsified** those roles | equality gate |
| Callers: Lookup @ `0x00518d07`, Clear @ `0x0051a717` only | **Confirmed** | xrefs (2 sites / 2 fns) |
| Cast-binding domain association | **High** | both callers on active-cast map; not exclusive product seal |
| Product STL / RTTI name | **Open** | no strings; structural name only |
| Full node schema beyond key / links / nil | **Open** | value TFID @ +0x18…+0x24 is **caller** evidence |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ force

| Stage | Match |
|---|---|
| Load end/head `*(this+4)` | Yes |
| Empty/nil-root skip walk | Yes |
| Tree walk by int key | Yes |
| Exact-match gate | Yes |
| Write hit node or end | Yes |
| No invent insert/mutate | Yes |

### Recovered CF

```c
// void __thiscall Map_ExactFindByIntKey(MapHeader *this, Node **pOut, int *pKey)
Node *end  = this->_Myhead;          // *(this+4)
Node *cand = end;
Node *cur  = end->_Parent;           // end[1]
if (cur->_Isnil == 0) {              // +0x29
  do {
    if (cur->_Key < *pKey)           // +0x10
      cur = cur->_Right;             // +0x08
    else {
      cand = cur;
      cur  = cur->_Left;             // +0x00
    }
  } while (cur->_Isnil == 0);
}
if (cand != end && cand->_Key <= *pKey)
  *pOut = cand;                      // exact hit
else
  *pOut = end;                       // miss
```

---

## 5. Callers (inventory)

| Caller | Site | Role |
|---|---|---|
| `Skill_LookupActiveCastBinding` | `0x00518d07` | find skillId → copy value TFID or invalid |
| `Skill_ClearCastBindingAndMaybeRestartCd` | `0x0051a717` | find before erase / clear path |

No other xrefs in image (this dual pass).

---

## 6. Gaps / open

1. Product / RTTI name (leave Ghidra `FUN_0051c150` unless string evidence appears).
2. Full `0x30` node field map (color, padding, value layout) — partially owned by Lookup/Clear duals.
3. Whether any other map with **same** layout reuses this VA only (xrefs say yes exclusive to these two skill paths today).
4. Runtime / bit-exact image diff.

**Verdict:** **accept-with-gaps**
