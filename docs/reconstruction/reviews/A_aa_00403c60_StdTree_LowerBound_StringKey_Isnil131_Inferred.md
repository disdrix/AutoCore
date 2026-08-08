# Review A (reconstruction fidelity): `aa_00403c60` StdTree_LowerBound_StringKey_Isnil131_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403c60` |
| **VA** | `0x00403c60`–`0x00403ca6` inclusive (**71 B** / `0x47`) |
| **Canonical name** | `StdTree_LowerBound_StringKey_Isnil131_Inferred` |
| **Ghidra name** | `FUN_00403c60` |
| **Prior scaffold** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_QuickBar_Ac_00403c60` |
| **Rejected misname** | QuickBar_ActivateSlot product leaf; thiscall-ECX map method; exact-find (equality write-out) |
| **Review date** | `2026-08-05` (MEGA-041 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00403c60_StdTree_LowerBound_StringKey_Isnil131_Inferred.md` |
| **System** | shared `client::stdtree` / skills-abilities residual (isnil131 string-key map) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf MSVC **`_Tree::lower_bound`** specialization for large tree nodes with **`std::string` key @ +0x0C** and **isnil @ +0x131**. Returns the first node with `!(node.key < key)` (or head/`end()`).

```text
// EAX = map; stack = const string* key; RET 4 → node*
cand = head (= end)
cur  = head->parent (= root)
while !cur->isnil(+0x131):
  if operator<(cur->key(+0xC), key):  cur = cur->right(+8)
  else:                               cand = cur; cur = cur->left(+0)
return cand
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ 2026-07-23 raw CF (lower_bound walk) |
| Full body | `disassemble_function` + `read_memory` **71 B** |
| IAT compare | `[0x009c62e8]` → `0x006eadd0` string `operator<` |
| Call sites | `0x0093bdfa` (`FUN_0093bd10`); `0x0095798a` / `0x00957c7b` (`FUN_00957820` region) |
| Twin upper_bound | `FUN_00403d60` (inverted `operator<(key, node.key)`) |
| Family | dualed `StdTree_IteratorIncrement_Isnil131` `0x00404000`; erase/free isnil131 peers |
| Clean | `reconstructed-exact/StdTree_LowerBound_StringKey_Isnil131_Inferred.cpp` |

### Full body hex (sealed)

```
8b4004558b6c2408568b700480be3101000000578bf87529538b1de8629c00908d4e0c
5551ffd383c40884c074058b7608eb048bfe8b3680be310100000074e05b8bc75f5e5d
c20400
```

Every isnil guard is displacement **`0x131`** (`80 BE 31 01 00 00`). Single exit **`RET 4`** (`C2 04 00` @ `0x00403ca6`).

---

## 3. Signature (sealed)

```c
// EAX = map* (_Myhead at +4); stack key*; EAX out = node*; RET 4
StdTreeNode* StdTree_LowerBound_StringKey_Isnil131_Inferred(
    /*EAX*/ void *map,
    /*stack*/ const std::string *key);
```

| Formal | Source | Conf |
|---|---|---|
| map | **EAX** → `[EAX+4]` head | **Confirmed** (entry `MOV EAX,[EAX+4]`; call sites `LEA EAX,[reg+4]` / `MOV EAX,reg`) |
| key | stack `[ESP+4]` after entry → EBP | **Confirmed** (`MOV EBP,[ESP+8]` after one push) |
| return | EAX = candidate node* | **Confirmed** (`MOV EAX,EDI`) |
| cleanup | **`RET 4`** | **Confirmed** |
| compare | IAT cdecl `operator<` | **Confirmed** (`CALL EBX`; `ADD ESP,8`) |

**Not** ECX-thiscall. Decompiler `in_EAX` is the map register.

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| head / root / cand=end init | bytes | **Confirmed** |
| isnil@+0x131 loop predicate | `80 BE 31 01 00 00` | **Confirmed** |
| `operator<(node.key, key)` | LEA +0xC + IAT CALL | **Confirmed** |
| true → right; false → cand=cur, left | branches | **Confirmed** |
| return cand; RET 4 | epilog | **Confirmed** |
| Classic lower_bound (not upper, not exact-find) | twin `00403d60` inverted; no equality write-out | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (STL lower_bound) |
| External call sites | **3** UNCONDITIONAL_CALL |
| Caller functions | `FUN_0093bd10` (slash dispatch), `FUN_00957820` (slash help) |
| Site role | string-key map lookup / `[lb,ub)` range start |
| Callees | string `operator<` only |
| Residual seed | QuickBar_ActivateSlot nested — **body is pure STL**, not QB product |

Caller ABI sample (`0x0093bdfa`):

```text
LEA EAX, [EBX+4]     ; map at client+4
PUSH EDX             ; string key
CALL 0x00403c60
MOV EDI, EAX
CMP EDI, [EBX+8]     ; end() == head at client+8
```

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Classic lower_bound CF + assembly seal | **Yes** |
| isnil @ +0x131 family match (iterator++/erase peers) | **Yes** |
| string key @ +0x0C via LEA + operator< | **Yes** |
| EAX-map + RET 4 ABI | **Yes** |
| Product/PDB host type English | **No** (slash-cmd usage only) |

**Decision:** promote **`StdTree_LowerBound_StringKey_Isnil131_Inferred`**. Retire `Named_CalleeOf_*QuickBar*` scaffold. Keep `_Inferred` — product map type open.

---

## 7. Gaps

- Product English for host map (slash-command registry inferred from callers only).
- Full isnil131 node payload field map (handler@+0x12C / level@+0x28 from callers — not owned by this unit).
- Runtime / bit-exact / differential.
- Twin upper_bound `00403d60` residual (not this OWN).

---

## 8. Verdict

Fidelity path accepts CF/ABI/isnil/string-key/caller roles with product-type residual → **accept-with-gaps**.
