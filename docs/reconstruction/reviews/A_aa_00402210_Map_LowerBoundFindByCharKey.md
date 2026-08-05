# Review A (reconstruction fidelity): `aa_00402210` Map_LowerBoundFindByCharKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402210` |
| **VA** | `0x00402210` |
| **Canonical name** | `Map_LowerBoundFindByCharKey` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00402210_Map_LowerBoundFindByCharKey.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leaf MSVC-style **ordered-tree exact find** for a **char** key. `__thiscall(this=mapHeader, pOutIt, pKey)` with **`ret 8`**.

Walks from root `*( *(this+4) + 4 )` (head→parent), using nil flag **`node+0x21`**, key as **signed char** at **`node+0x0C`** (`*(char*)(node+3)` / `[node+0xC]`), left `*node`, right `node+0x08`. After the lower-bound-shaped walk, **accepts only exact match**: candidate ≠ end **and** `node.key <= *pKey` (combined with walk invariant `key >= *pKey` ⇒ equality). On miss, writes **end** `*(this+4)` into `*pOutIt`.

**Read-only** — no insert/erase/allocation. Shared helper used by skill/cast-adjacent paths (map often at `object+0x51c` in callers). Body returns **node pointer** (or end) only; value payload is **caller-owned**.

Distinct layout from sibling helpers:

| Helper | Nil / isnil | Key slot | Key type | Op |
|---|---|---|---|---|
| `Map_LowerBoundFindByIntKey` (`0x0050f940`) | `+0x15` | `node[3]` | int | lower_bound-walk + ≤ gate |
| `StdMap_LowerBoundByIntKey_INFERRED` (`0x004054f0`) | `+0x1d` | `node[3]` | int | lower_bound-walk + ≤ gate |
| `Map_ExactFindByIntKey` (`0x0051c150`) | `+0x29` | `node+0x10` | int | exact find |
| **`Map_LowerBoundFindByCharKey` (`0x00402210`)** | **`+0x21`** | **`node+0x0C`** | **char** | **exact find** |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00402210_Map_LowerBoundFindByCharKey.md` |
| Annotated | `docs/reconstruction/raw/aa_00402210_Map_LowerBoundFindByCharKey.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_LowerBoundFindByCharKey.cpp` |
| Function record | `docs/reconstruction/functions/aa_00402210_Map_LowerBoundFindByCharKey.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x00402210` (2026-07-29) |
| Complete analysis | Ghidra `analyze_function_complete` — leaf, 11 xrefs, 7 named callers |
| Bytes | `read_memory` 96 B @ `0x00402210` — nil `cmp byte [reg+0x21]`, key `cmp [reg+0x0C]`, exit `ret 8` |
| Xrefs / callers | `get_function_xrefs` / `get_function_callers` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature `__thiscall(map*, Node** out, char* key)` void; **ret 8** | **Confirmed** | `C2 08 00`; body uses two stack slots |
| Decompiler third formal / name swap is phantom | **Confirmed** | `pKey` unused in body; key loaded from stack arg used as `pOutIt` in Ghidra names |
| `this+4` = end / `_Myhead` | **Confirmed** | body both arms |
| Root = `head[1]` (`head+4`) | **Confirmed** | decompile + asm |
| Nil flag byte `node+0x21 == 0` means real node | **Confirmed** | decompile + `80 78 21 00` |
| Key **signed char** at `node+0x0C` | **Confirmed** | `38 48 0C` / `3A 4A 0C` |
| Left child `*node` (+0); right `node+8` | **Confirmed** | body |
| Walk is lower_bound-shaped (`node.key < search` → right else left+cand) | **Confirmed** | body |
| Post-check enforces **exact** match (`cand≠end && cand.key <= search`) | **Confirmed** | body; with walk ⇒ equality |
| Miss / empty → `*out = end` | **Confirmed** | body |
| No callees (leaf helper) | **Confirmed** | analyze complete; no CALL in body |
| Not insert / not erase / not pure lower_bound API | **Confirmed** / those roles **Falsified** | equality gate + read-only |
| Callers include skill/cast paths (`+0x51c` maps) | **High** | multiple reconstructed call sites |
| Product STL / RTTI name | **Open** | structural name kept |
| Full node schema beyond key / links / nil | **Open** | value fields are caller evidence |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load end/head `*(this+4)` | Yes |
| Empty/nil-root skip walk | Yes |
| Tree walk by signed char key | Yes |
| Exact-match gate | Yes |
| Write hit node or end | Yes |
| No invent insert/mutate | Yes |
| ABI-corrected clean (2 stack args) vs raw 3-name decompiler print | Yes CF; formal list cleaned in clean/annotated |

### Recovered CF

```c
// void __thiscall Map_LowerBoundFindByCharKey(MapHeader *this, Node **pOut, char *pKey)
Node *end  = this->_Myhead;          // *(this+4)
Node *cand = end;
Node *cur  = end->_Parent;           // end[1]
if (cur->_Isnil == 0) {              // +0x21
  do {
    if (cur->_Key < *pKey)           // +0x0C signed char
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

| Caller | Site(s) | Role (caller duals own domain) |
|---|---|---|
| `FUN_0059a940` | `0x0059aa7e` | skill-adjacent map @ `+0x51c` |
| `NPC_TryCastSkillFromSet` | `0x005d13ad` | cast path |
| `FUN_00616d10` | `0x00616ff9` | map @ `+0x51c`, char key |
| `FUN_00620ff0` | `0x00621293` | map @ `+0x51c`, char key |
| `FUN_007eaf20` | `0x007eb997`, `0x007ec62b` | two sites |
| `FUN_00845030` | `0x0084526b` | reaction/skill resolve path |
| `FUN_00955eb0` | `0x00956152` | skill debug/time-left path |
| xref extras | `0x006165b0`, `0x00616bb0`, `0x00620e90` | listed by xrefs |

Callees: **none**.

---

## 6. Gaps / open

1. Product / RTTI name (keep `Map_LowerBoundFindByCharKey`).
2. Full node field map after char key (color, padding, mapped value) — **not this VA**.
3. Map owner type at `+0x51c` / other bases — caller duals.
4. Runtime / bit-exact image diff.

**Verdict:** **accept-with-gaps**
