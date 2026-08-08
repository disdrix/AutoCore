# Review A (reconstruction fidelity): `aa_0051d7c0` Map_EraseRange_Isnil15

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d7c0` |
| **VA** | `0x0051d7c0`–`0x0051d873` inclusive (**180 B**) |
| **Canonical name** | `Map_EraseRange_Isnil15` |
| **Ghidra name** | `FUN_0051d7c0` |
| **Review date** | `2026-08-04` (WQ9E-J OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0051d7c0_Map_EraseRange_Isnil15.md` |
| **System** | STL / map-set (WQ-009 depth-2 residual; isnil@+0x15) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full body + pad) + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style red-black **map/set range erase** for the **isnil@+0x15** node family. Full-range fast path frees the tree via `FUN_0051be50`; partial path walks successors and calls `FUN_0051ce00` (STL single-node erase with `"invalid map/set<T> iterator"`). Skill-neighborhood residual next to dualed `Map_EraseRange` / `Map_EraseRange_B` (those use **isnil@+0x29**).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `0x0051d7c0` (2026-08-04) |
| Bytes | `read_memory` 180 B; tails `C2 0C 00`; isnil `+0x15` immediates |
| Free subtree | live `FUN_0051be50` (isnil@+0x15 recurse/delete) |
| Single erase | live `FUN_0051ce00` (throw string seals STL) |
| Callers | `FUN_0051e150`, `FUN_0052f260` |
| Peer isnil29 | dualed `Map_EraseRange` / `Map_EraseRange_B` |
| Peer isnil15 | `StdMap_EraseRange_Inferred` @ `0x004bacf0` (different free/erase) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 180 B; `ret 0x0c` both exits | **Confirmed** | bytes |
| `__thiscall` ECX=map; stack `(out, first, last)` | **Confirmed** | entry + `ret 12` |
| Full clear: `first==*head && last==head` | **Confirmed** | decomp ≡ bytes |
| Free via `FUN_0051be50(head->parent)` then head reset + size 0 | **Confirmed** | rel call target |
| Partial: successor + `FUN_0051ce00` with ECX=map | **Confirmed** | `mov ecx,edi` + call |
| isnil @ `+0x15` (not +0x29) | **Confirmed** | immediates `0x15` |
| Structural name `Map_EraseRange_Isnil15` | **High** | STL role; discriminator vs Map_EraseRange |
| K/V payload English | **Inferred** / open | not recovered |
| Product/PDB symbol | **Inferred** | open |
| Runtime / bit-exact | Open | no Launcher |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Full-range detection | **Yes** |
| Free + head reset + size 0 + out | **Yes** |
| Successor walk isnil@+0x15 | **Yes** |
| Erase node with ECX=map | **Yes** (bytes; decomp omits ECX formal) |
| `*out_it` + `ret 0x0c` | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| STL range-erase structure | **Yes** |
| Erase-node throw string (callee) | **Yes** |
| isnil offset discriminator | **Yes** (`+0x15`) |
| Product/PDB English | **No** |

**Decision:** promote **`Map_EraseRange_Isnil15`** (structural; family of `Map_EraseRange` with isnil discriminator).  
**Reject:** merge with `Map_EraseRange` / `Map_EraseRange_B` (wrong isnil); identity with `StdMap_EraseRange_Inferred` (same isnil, different free/erase VA).

---

## 6. Gaps

1. Exact `map<K,V>` / `set<K>` instantiation and value size.
2. Full free-subtree algebra inside `FUN_0051be50` (not OWN; decomp may drop left recurse).
3. Full dual of `FUN_0051ce00` (not OWN).
4. Per-caller payload English (`0052f260` map @ −300 vs tidy peer).
5. Runtime / image diff / bit-exact.

**Verdict:** **accept-with-gaps**
