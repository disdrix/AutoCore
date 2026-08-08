# Review A (reconstruction fidelity): `aa_0051d940` Map_EraseRange_Isnil15_B

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d940` |
| **VA** | `0x0051d940`–`0x0051d9f3` inclusive (**180 B**) |
| **Canonical name** | `Map_EraseRange_Isnil15_B` |
| **Ghidra name** | `FUN_0051d940` |
| **Review date** | `2026-08-04` (WQ9F-J OWN dual A) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0051d940_Map_EraseRange_Isnil15_B.md` |
| **System** | STL / map-set (WQ-009 depth-3 residual; isnil@+0x15) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full 180 B + pad) + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Twin** of dualed `Map_EraseRange_Isnil15` (`0x0051d7c0`): MSVC red-black **map/set range erase** for the **isnil@+0x15** node family.

- Full-range fast path when `first == *head && last == head`: free tree via **`FUN_0051bed0(head->parent)`**, reset head links, `size = 0`, `*out_it = *head`.  
- Partial path: while `first != last`, compute tree successor (isnil@+0x15), call **`FUN_0051ce00(map, &first, node)`**, advance to successor; write `*out_it`.

**Discriminator vs `Map_EraseRange_Isnil15`:** full-clear free-subtree **`FUN_0051bed0`** (not `FUN_0051be50`). Partial erase callee is the **same** `FUN_0051ce00` (STL throw string `"invalid map/set<T> iterator"`).

Only static caller recovered: map host complete dtor `FUN_0051e1b0` (full erase then `operator_delete` head).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `0x0051d940` (2026-08-04) ≡ raw scaffold CF |
| Bytes | 180 B; both exits **`ret 0x0c`** (`C2 0C 00`); isnil immediates **`0x15`** (`80 7e 15 00` / `80 78 15 00`) |
| Free call | rel32 @ `0x0051d95c` → **`FUN_0051bed0`** |
| Erase call | rel32 @ `0x0051d9df` → **`FUN_0051ce00`** (`mov ecx,edi` restores map this) |
| Twin | `Map_EraseRange_Isnil15` / free `FUN_0051be50` |
| Peer isnil29 | dualed `Map_EraseRange` / `Map_EraseRange_B` |
| Caller | `FUN_0051e1b0` @ `0x0051e1c2` only (`xref_count=1`) |
| Pad / next | `CC` pad; next `FUN_0051da00` @ `0x0051da00` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 180 B; `ret 0x0c` both exits | **Confirmed** | bytes |
| `__thiscall` ECX=map; stack `(out, first, last)` | **Confirmed** | entry + ret 12 |
| Full clear: free `FUN_0051bed0` + head reset + size 0 | **Confirmed** | rel call + decomp |
| Partial: successor isnil@+0x15 + `FUN_0051ce00` | **Confirmed** | bytes + decomp |
| Twin of `Map_EraseRange_Isnil15` (free differs) | **Confirmed** | CF match; free VA |
| Structural name `Map_EraseRange_Isnil15_B` | **High** | same bar as `Map_EraseRange_B` |
| K/V / product English | Open | |
| Runtime / bit-exact | Open | |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Full-range detection | **Yes** |
| Free + head reset + size 0 + out | **Yes** |
| Successor walk isnil@+0x15 | **Yes** |
| Erase node with ECX=map | **Yes** (bytes; decomp plate omits formal) |
| `*out_it` + `ret 0x0c` | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Twin of sealed `Map_EraseRange_Isnil15` | **Yes** |
| Distinct free-subtree VA | **Yes** (`0051bed0` vs `0051be50`) |
| Same partial erase as twin | **Yes** (`FUN_0051ce00`) |
| Product/PDB English | **No** |

**Decision:** promote **`Map_EraseRange_Isnil15_B`** — keep separate from `Map_EraseRange_Isnil15`.  
**Reject:** merge with twin; merge with isnil@+0x29 `Map_EraseRange` / `_B`; identity with `StdMap_EraseRange_Inferred` (`0x004bacf0`).

---

## 6. Gaps

1. Why MSVC emitted a second isnil@+0x15 instantiation (value type / size) when erase node is shared.  
2. Free-subtree `FUN_0051bed0` dual (not OWN; decomp may drop left recurse).  
3. Full dual of `FUN_0051ce00` (not OWN; already referenced by twin).  
4. Map host class English for `FUN_0051e1b0`.  
5. Runtime / image diff / bit-exact.

**Verdict:** **accept-with-gaps**
