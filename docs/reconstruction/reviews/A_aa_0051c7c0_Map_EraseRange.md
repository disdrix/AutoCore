# Review A (reconstruction fidelity): `aa_0051c7c0` Map_EraseRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051c7c0` |
| **VA** | `0x0051c7c0`–`0x0051c873` (**180 B**) |
| **Canonical name** | `Map_EraseRange` |
| **Ghidra name** | `FUN_0051c7c0` |
| **Review date** | `2026-08-04` (WQ9D-H OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0051c7c0_Map_EraseRange.md` |
| **System** | STL / map-set (WQ-009 skill residual helper) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `read_memory` (full body + pad) + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style red-black **map/set range erase** for the large-node family (`isnil@+0x29`). Full-range fast path frees the tree via `FUN_0051bbc0`; partial path walks successors and calls sealed `Map_EraseNode` (`0x0051cb40`). Used by aggro map prune and map host dtor — skill-bank depth residual, not cast SM itself.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `0x0051c7c0` (2026-08-04) |
| Bytes | `read_memory` 180 B; tails `C2 0C 00`; isnil `+0x29` immediates |
| Single erase | dualed `Map_EraseNode` / `A_aa_0051cb40_*` |
| Free subtree | live `FUN_0051bbc0` (isnil@+0x29) |
| Callers | `CVOGHBAIBase_GetTargetFromAggro`, `FUN_0051da30` |
| Peer twin | `Map_EraseRange_B` / `0x0051d880` |
| Distinct families | `StdMap_EraseRange_Inferred` isnil@+0x15; `FUN_0051d700` isnil@+0x1d |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 180 B; `ret 0x0c` both exits | **Confirmed** | bytes |
| `__thiscall` ECX=map; stack `(out, first, last)` | **Confirmed** | entry + `ret 12` |
| Full clear: `first==*head && last==head` | **Confirmed** | decomp ≡ bytes |
| Free via `FUN_0051bbc0(head->parent)` then head reset + size 0 | **Confirmed** | rel call target |
| Partial: successor + `Map_EraseNode` | **Confirmed** | `mov ecx,edi` + call `0x0051cb40` |
| isnil @ `+0x29` (same as Map_EraseNode) | **Confirmed** | immediates `0x29` |
| Structural name `Map_EraseRange` | **High** | STL role; no product English required (peer Map_EraseNode) |
| K/V payload English | **Inferred** / open | not recovered |
| Product/PDB symbol | **Inferred** | open |
| Runtime / bit-exact | Open | no Launcher |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Full-range detection | **Yes** |
| Free + head reset + size 0 + out | **Yes** |
| Successor walk isnil@+0x29 | **Yes** |
| Map_EraseNode with ECX=map | **Yes** (bytes; decomp omits ECX formal) |
| `*out_it` + `ret 0x0c` | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| STL range-erase structure | **Yes** |
| Shared erase-node with throw string | **Yes** (callee dual) |
| Reject chain `Named_CalleeOf_CVOGHBAIBase_*` | **Yes** — multi-caller generic |
| Product/PDB English | **No** |

**Decision:** promote **`Map_EraseRange`** (structural; family of `Map_EraseNode`).

---

## 6. Gaps

1. Exact `map<K,V>` / `set<K>` instantiation and value size.
2. Full free-subtree algebra inside `FUN_0051bbc0` (not OWN; decomp may drop left recurse).
3. Per-caller key English (aggro TFID vs other map host).
4. Runtime / image diff / bit-exact.

**Verdict:** **accept-with-gaps**
