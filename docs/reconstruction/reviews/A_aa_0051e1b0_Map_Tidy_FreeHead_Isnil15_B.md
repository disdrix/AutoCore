# Review A (reconstruction fidelity): `aa_0051e1b0` Map_Tidy_FreeHead_Isnil15_B

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e1b0` |
| **VA** | `0x0051e1b0`–`0x0051e1dd` inclusive (**46 B** / exclusive end `0x0051e1de`) |
| **Canonical name** | `Map_Tidy_FreeHead_Isnil15_B` |
| **Ghidra name** | `FUN_0051e1b0` |
| **Review date** | `2026-08-04` (WQ9G-D OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0051e1b0_Map_Tidy_FreeHead_Isnil15_B.md` |
| **System** | MSVC map tidy / free header (host of dualed `Map_EraseRange_Isnil15_B`) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full body) + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Bare map tidy (no SEH): full-range erase via dualed **`Map_EraseRange_Isnil15_B`**, free header sentinel, null `head` and `size`. Same 46 B template as dualed `Map_Tidy_FreeHead` @ `0x0051da30`, `Map_Tidy_FreeHead_B` @ `0x0051e180`, and `Map_Tidy_FreeHead_Isnil1d_Inferred` @ `0x0051e120`. Static consumer is atexit vector destructor for global map array `DAT_00b04288` (count 3, stride `0xc`).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `0x0051e1b0` (2026-08-04) — truncated after delete |
| Bytes | `read_memory` full 46 B; tails `C3`; nulls head+size |
| Erase range | dualed `Map_EraseRange_Isnil15_B` `0x0051d940` (call @ `0x0051e1c2`) |
| Free subtree (via erase) | dualed-open OWN `Map_FreeSubtree_Isnil15_B` `0x0051bed0` |
| Caller | `FUN_009c3980`: `_eh_vector_destructor_iterator_(&DAT_00b04288, 0xc, 3, FUN_0051e1b0)` |
| Peer tidies | dualed `Map_Tidy_FreeHead` / `_B` / `Isnil1d_Inferred` |
| Raw / clean | `raw/aa_0051e1b0_*`, `reconstructed-exact/Map_Tidy_FreeHead_Isnil15_B.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 46 B; bare `ret` | **Confirmed** | full-body hex; Ghidra end `0x0051e1cf` incomplete |
| `__fastcall`/`thiscall` ECX=map | **Confirmed** | `56 8B F1` |
| Full clear: first=`*head`, last=`head` | **Confirmed** | decomp ≡ bytes |
| Erase via `Map_EraseRange_Isnil15_B` | **Confirmed** | rel call target `0x0051d940` |
| Free head only; null head+size | **Confirmed** | bytes (decomp drops nulls) |
| Does not free map facade | **Confirmed** | no `this` delete |
| Twin of `Map_Tidy_FreeHead` (isnil15_B) | **High** | same template; different erase |
| K/V / global host English | Open | array `0xb04288` |
| Product/PDB symbol | Open | |
| Runtime / bit-exact | Open | |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Full-range erase args | **Yes** |
| Free header only | **Yes** |
| Null head+size after delete | **Yes** (bytes; decomp incomplete) |
| Bare RET / no SEH | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Tidy template (erase full + free head + null) | **Yes** |
| Discriminator via dualed isnil15_B erase-range | **Yes** |
| Product/RTTI host English | **No** |
| Collapse into `Map_Tidy_FreeHead` same VA | **No** |

**Decision:** promote **`Map_Tidy_FreeHead_Isnil15_B`**.  
**Reject:** free-of-facade; product class name without RTTI; merge identity with isnil29 `Map_Tidy_FreeHead` / `Map_Tidy_FreeHead_B` / isnil1d tidy.

---

## 6. Gaps

1. Product English for global array `0x00b04288` and exact `map<K,V>`.
2. Peer tidy `FUN_0051e150` (isnil15 without `_B`) not OWN.
3. Runtime / image diff / bit-exact.

**Verdict:** **accept-with-gaps**
