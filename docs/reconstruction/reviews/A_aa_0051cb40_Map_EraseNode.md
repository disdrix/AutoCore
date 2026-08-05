# Review A (reconstruction fidelity): `aa_0051cb40` Map_EraseNode

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051cb40` |
| **VA** | `0x0051cb40`–`0x0051cdf5` |
| **Canonical name** | `Map_EraseNode` |
| **Ghidra name** | `FUN_0051cb40` |
| **Review date** | `2026-07-29` (W19-I OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0051cb40_Map_EraseNode.md` |
| **System** | STL / map-set |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` entry/tail + string. No `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style red-black **single-node erase** for the large payload map/set family used by active-cast binding clear, range-erase wrappers, and aggro prune. Nil-iterator throw string seals STL identity.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | `0x0051cb40` |
| Bytes | `read_memory` entry + post-delete tail through `ret 8` |
| String | `"invalid map/set<T> iterator"` @ `0x00a152f0` |
| Sibling | `Map_ExactFindByIntKey` (`0x0051c150`); range erase `FUN_0051c7c0` / `FUN_0051d880` |
| Distinct family | `Map_EraseNode_IntKey` (`0x005d1df0`, isnil@+0x15) |
| Raw / clean | `raw/aa_0051cb40_*`, `reconstructed-exact/Map_EraseNode.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x0051cb40`–`0x0051cdf5` (694 B) | **Confirmed** | bytes; Ghidra end `0x0051cdc6` superseded |
| `__thiscall` ECX=map; stack `(pOutIt, pNode)`; **`ret 8`** | **Confirmed** | `C2 08 00` @ `0x0051cdf3` |
| isnil gate `@node+0x29` → throw string | **Confirmed** | decomp + string VA |
| Unlink + RB rebalance (color `@+0x28`) | **Confirmed** | decomp + rot callees |
| `operator_delete` falls through | **Confirmed** | size-- + `*pOutIt` after call |
| `map+0x08` size-- if >0 | **Confirmed** | post-delete bytes |
| `*pOutIt = successor` | **Confirmed** | tail store |
| Successor via `FUN_004cb270` | **High** | callee dual; plate loses ECX formal |
| Family with ExactFind (key@+0x10) | **High** | shared isnil/color; callers |
| Product/PDB symbol | **Inferred** | structural `Map_EraseNode` |
| Chain-of-caller name | **Falsified** as canonical | reject Named_CalleeOf_* |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| isnil → throw | **Yes** |
| successor + unlink + rebalance | **Yes** (raw/live; plate incomplete on post-delete) |
| delete → size-- → out it → ret 8 | **Yes** (bytes seal post-delete) |
| No invent key compare in body | **Yes** (erase-by-node only) |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| STL throw string | **Yes** |
| RB erase structure | **Yes** |
| Sibling `Map_ExactFindByIntKey` | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`Map_EraseNode`** (structural Confirmed/High; no product English required for STL helper pattern used elsewhere without `_Inferred`).

---

## 6. Gaps

1. Product/PDB symbol for this MSVC instantiation.
2. Per-caller value payload English (cast TFID vs aggro).
3. Full algebra residual on every rotation case (CF sealed).
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
