# Review A (reconstruction fidelity): `aa_004cc220` StdTree_InsertHint_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cc220` |
| **VA** | `0x004cc220`–`0x004cc3c4` inclusive (**421 B** / `0x1A5`) |
| **Canonical name** | `StdTree_InsertHint_Isnil29_Inferred` |
| **Ghidra name** | `FUN_004cc220` |
| **Review date** | `2026-08-04` (WQ9F-E OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004cc220_StdTree_InsertHint_Isnil29_Inferred.md` |
| **System** | MSVC `std::_Tree` unique insert-with-hint (isnil@+0x29; 2-dword key) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (entry/epilogue) + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style **map/set insert(const_iterator hint, const value_type&)** for the large-node family (**isnil @ +0x29**). Attempts local always-insert via dualed `StdTree_InsertAndRebalance_Isnil29_Inferred` (`0x004cbb60`) on empty / begin / end / neighbor-valid hints; otherwise falls back to insert-or-find `FUN_004cbee0` and returns the node only.

Peer shape of dualed `StdTree_InsertHint_Val12` (`0x0053a8e0`) with different isnil/key layout.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw CF (2026-08-04) |
| Bytes | `read_memory` entry empty-path + epilogue `RET 0x0c` |
| Insert rebalance dual | `aa_004cbb60` WQ9E-E |
| InsertHint Val12 peer | `aa_0053a8e0` W28-Q |
| Sole caller | `FUN_004cc400` @ `0x004cc457` |

---

## 3. Signature (sealed)

```c
// __thiscall; RET 0x0c
Node** __thiscall StdTree_InsertHint_Isnil29_Inferred(
    Map* map, Node** outIt, Node* hint, const void* value);
```

| Formal | Source | Conf |
|---|---|---|
| map | ECX (`MOV ESI,ECX`) | **High** |
| outIt | stack after frame | **High** |
| hint | stack | **High** |
| value | stack | **High** |
| cleanup | `ADD ESP,8; C2 0C 00` | **High** |
| return | outIt in EAX | **High** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Empty → Insert(1, head) | size@+8 == 0 | **High** |
| Hint == leftmost | `hint == *head` (left) | **High** |
| Hint == head (end) | rightmost key < value → Insert(0, rightmost) | **High** |
| value < hint → Prevnode | `FUN_004cb4f0` on local | **High** |
| pred < value < hint | open-side Insert via isnil@+0x29 on pred.right | **High** (bytes: where=pred/addLeft=0 or where=hint/addLeft=1) |
| hint < value → Nextnode | `FUN_004cb270` | **High** |
| Open-side Insert | bytes: where=hint/addLeft=0 or where=succ/addLeft=1 | **High** |
| Fallback InsertOrFind | `FUN_004cbee0`; `*outIt = pair.node` | **High** |
| Key less helper | `FUN_00401480` (2-dword hi/lo) | **High** |
| Decomp where-alias after prev/next | **slightly wrong** — bytes override where register | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | `FUN_004cc400` only (`xref_count=1`) |
| Callees | `004cbb60`×7, `004cbee0`, `00401480`, `004cb4f0`, `004cb270` |

---

## 6. Naming

| Name | Status |
|---|---|
| `StdTree_InsertHint_Isnil29_Inferred` | **Accept** — MSVC insert-hint + isnil29 family; product demangle open → `_Inferred` |
| `Named_CalleeOf_…_VOG_DEBUG_STOP_004cc220` | **Reject** scaffold |

---

## 7. Gaps

1. Product / MSVC demangle for map `value_type` / host of `FUN_004cc400`.  
2. Exact English for 2-dword key (TFID / pair / other) — structural only.  
3. Nested dual of `FUN_004cbee0` / `FUN_00401480` / prev-next (not OWN).  
4. Runtime / bit-exact / differential open.

**Verdict:** **accept-with-gaps**
