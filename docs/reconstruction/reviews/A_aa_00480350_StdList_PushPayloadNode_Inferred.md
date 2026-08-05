# Review A (reconstruction fidelity): `aa_00480350` StdList_PushPayloadNode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00480350` |
| **VA** | `0x00480350` |
| **Canonical name** | `StdList_PushPayloadNode_Inferred` |
| **Ghidra symbol** | `FUN_00480350` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_00480350_StdList_PushPayloadNode_Inferred.md` |
| **System** | client audio / `CSoundManager` queue list (generic MSVC list helper) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Insert a payload pointer** (`EAX`) into an MSVC-style **`std::list`-shaped container** at `param_1`.

Authoritative stages (live ≡ raw):

1. `head = *(param_1 + 4)` — list head / `_Myhead` sentinel.
2. **`node = FUN_006759b0(head, *(head+4), &payload)`** — `operator_new(0xC)` list node:
   - `node[0] = head`
   - `node[1] = head->_Next` (`*(head+4)`)
   - `node[2] = *payload` (dword value; payload was `in_EAX` at call)
3. **`FUN_0043fe60`** — list size bump (`_Mysize += n`) with `"list<T> too long"` overflow throw path.
4. Link: `*(head+4) = node`; `**(node+4) = node` — splice node into ring after head (push-front / after-sentinel pattern).

**Caller context:** `CSoundManager` queue at **`manager+0x310`** after freelist pop + field fill (`FUN_007258a0`, siblings).

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw / annotated / clean | `aa_00480350_*` | CF ≡ live |
| Live decompile | Ghidra `0x00480350` | sealed |
| Callee decompiles | `FUN_006759b0` (`new 0xC` node), `FUN_0043fe60` (size++) | sealed roles |
| Complete analysis | leaf-of-list helper; 3 xrefs | |
| Parent dual | `A_aa_007258a0` | `FUN_00480350(this+0x310)` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `param_1` = list container; `+4` = head | **Confirmed** | body |
| Payload via **EAX** into node ctor | **Confirmed** | `in_EAX` → `FUN_006759b0` 3rd arg |
| Node size **0xC** (next/prev/value) | **Confirmed** | `006759b0` `operator_new(0xC)` |
| Size increment via `0043fe60` | **Confirmed** | `"list<T> too long"` string in callee |
| Link updates head→next and back-link | **Confirmed** | body |
| Used as CSoundManager queue insert | **High** | `this+0x310` at parents |
| Push-front vs push-back product naming | **Medium** | MSVC list insert-after-head = front |
| Exact list element type beyond dword ptr | **Medium** | value is pointer-sized |
| Product STL symbol | **Open** | structural |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load head `*(list+4)` | Yes |
| Alloc 0xC node with head / next / payload | Yes |
| Size++ | Yes |
| Relink head and node | Yes |

```c
// void StdList_PushPayloadNode(List *list, void *payload_in_EAX)
void FUN_00480350(int list)
{
  int head = *(int *)(list + 4);
  int node = FUN_006759b0(head, *(undefined4 *)(head + 4), &payload /* EAX */);
  FUN_0043fe60(/* size++, list */);
  *(int *)(head + 4) = node;
  **(int **)(node + 4) = node;
}
```

---

## 5. Callers / callees

**Callees:** `FUN_006759b0` (node alloc/init), `FUN_0043fe60` (list size++).

**Callers (3):** `FUN_007252d0`, `FUN_007258a0`, `FUN_00725a70` — all pass **`manager+0x310`**.

---

## 6. Gaps / open

1. Full MSVC list header layout beyond `+4` head and size at callee (`param_2+8` in `0043fe60`).
2. Whether queue drain walks same list elsewhere (tick dual residual).
3. Runtime not run.

**Verdict:** **accept-with-gaps** — insert CF and audio-queue role sealed.
