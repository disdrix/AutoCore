# Review A (reconstruction fidelity): `aa_00403d60` StdTree_UpperBound_StringKey_Isnil131_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403d60` |
| **VA** | `0x00403d60`–`0x00403da6` inclusive (**71 B** / `0x47`) |
| **Canonical name** | `StdTree_UpperBound_StringKey_Isnil131_Inferred` |
| **Ghidra name** | `FUN_00403d60` |
| **Review date** | `2026-08-05` (R10-020 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00403d60_StdTree_UpperBound_StringKey_Isnil131_Inferred.md` |
| **System** | shared `client::stdtree` / skills-abilities residual (isnil131 string-key map) |
| **Parent dual** | `0x00403c60` StdTree_LowerBound_StringKey_Isnil131_Inferred (MEGA-041) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf MSVC **`_Tree::upper_bound`** specialization for large tree nodes with **`std::string` key @ +0x0C** and **isnil @ +0x131**. Returns the first node with `key < node.key` (or head/`end()`).

```text
// EAX = map; stack = const string* key; RET 4 → node*
cand = head (= end)
cur  = head->parent (= root)
while !cur->isnil(+0x131):
  if operator<(key, cur->key(+0xC)):  cand = cur; cur = cur->left(+0)
  else:                               cur = cur->right(+8)
return cand
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ 2026-07-23 raw CF (upper_bound walk) |
| Full body | `disassemble_function` + `read_memory` **71 B** |
| IAT compare | `[0x009c62e8]` → `0x006eadd0` string `operator<` |
| Call sites | `0x0095797a` / `0x00957c6b` (`FUN_00957820` region) |
| Twin lower_bound | dualed `StdTree_LowerBound_StringKey_Isnil131_Inferred` `0x00403c60` |
| Family | dualed `StdTree_IteratorIncrement_Isnil131` `0x00404000`; erase/free isnil131 peers |
| Clean | `reconstructed-exact/StdTree_UpperBound_StringKey_Isnil131_Inferred.cpp` |

### Full body hex (sealed)

```
8b4004558b6c2408568b700480be3101000000578bf87529538b1de8629c00908d4e0c
5155ffd383c40884c074068bfe8b36eb038b760880be310100000074e05b8bc75f5e5d
c20400
```

Every isnil guard is displacement **`0x131`** (`80 BE 31 01 00 00`). Single exit **`RET 4`** (`C2 04 00` @ `0x00403da6`). Pad `CC` before next function.

---

## 3. Signature (sealed)

```c
// EAX = map* (_Myhead at +4); stack key*; EAX out = node*; RET 4
StdTreeNode* StdTree_UpperBound_StringKey_Isnil131_Inferred(
    /*EAX*/ void *map,
    /*stack*/ const std::string *key);
```

| Formal | Source | Conf |
|---|---|---|
| map | **EAX** → `[EAX+4]` head | **Confirmed** (entry `MOV EAX,[EAX+4]`; call sites `LEA EDI/ESI,[EBP+4]` then `MOV EAX,EDI/ESI`) |
| key | stack `[ESP+4]` after entry → EBP | **Confirmed** (`MOV EBP,[ESP+8]` after one push) |
| return | EAX = candidate node* | **Confirmed** (`MOV EAX,EDI`) |
| cleanup | **`RET 4`** | **Confirmed** |
| compare | IAT cdecl `operator<(key, node.key)` | **Confirmed** (`PUSH ECX; PUSH EBP; CALL EBX; ADD ESP,8`) |

**Not** ECX-thiscall. Decompiler `in_EAX` is the map register.

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| head / root / cand=end init | bytes | **Confirmed** |
| isnil@+0x131 loop predicate | `80 BE 31 01 00 00` | **Confirmed** |
| `operator<(key, node.key)` | LEA +0xC + push order + IAT CALL | **Confirmed** |
| true → cand=cur, left; false → right | branches | **Confirmed** |
| return cand; RET 4 | epilog | **Confirmed** |
| Classic upper_bound (not lower, not exact-find) | twin `00403c60` inverted; no equality write-out | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (STL upper_bound) |
| External call sites | **2** UNCONDITIONAL_CALL |
| Caller functions | `FUN_00957820` only (slash help list) |
| Site role | string-key map range end for `[lb, ub)` |
| Callees | string `operator<` only |
| Residual seed | skills-abilities parent `0x00403c60` — **body is pure STL** |

Caller ABI sample (`FUN_00957820` @ `0x0095797a`):

```text
LEA EDI, [EBP+4]     ; map at client+4
PUSH ECX             ; string key
MOV EAX, EDI
CALL 0x00403d60      ; upper_bound → [ESP+0x14]
LEA EDX, [ESP+0x18]
PUSH EDX
MOV EAX, EDI
CALL 0x00403c60      ; lower_bound → EDI
; walk [lb, ub) with iterator++ until lb==ub
```

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Classic upper_bound CF + assembly seal | **Yes** |
| isnil @ +0x131 family match (iterator++/lower_bound peers) | **Yes** |
| string key @ +0x0C via LEA + operator< | **Yes** |
| EAX-map + RET 4 ABI | **Yes** |
| Twin lower_bound inverted compare sealed | **Yes** |
| Product/PDB host type English | **No** (slash-cmd usage only) |

**Decision:** promote **`StdTree_UpperBound_StringKey_Isnil131_Inferred`**. Keep `_Inferred` — product map type open.

---

## 7. Gaps

- Product English for host map (slash-command registry inferred from callers only).
- Full isnil131 node payload field map (handler/level from callers — not owned by this unit).
- Runtime / bit-exact / differential.
- No third call site outside `FUN_00957820` (lower_bound has slash-dispatch site; this unit does not).

---

## 8. Verdict

Fidelity path accepts CF/ABI/isnil/string-key/caller roles with product-type residual → **accept-with-gaps**.
