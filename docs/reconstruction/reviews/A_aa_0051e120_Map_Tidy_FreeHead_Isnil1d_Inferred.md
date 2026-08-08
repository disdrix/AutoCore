# Review A (reconstruction fidelity): `aa_0051e120` Map_Tidy_FreeHead_Isnil1d_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e120` |
| **VA** | `0x0051e120`–`0x0051e14d` inclusive (**46 B** / exclusive end `0x0051e14e`) |
| **Canonical name** | `Map_Tidy_FreeHead_Isnil1d_Inferred` |
| **Ghidra name** | `FUN_0051e120` |
| **Review date** | `2026-08-04` (WQ9F-G OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0051e120_Map_Tidy_FreeHead_Isnil1d_Inferred.md` |
| **System** | MSVC map tidy / free header (host of dualed `Map_EraseRange_Isnil1d_Inferred`) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` (full body) + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Bare map tidy (no SEH): full-range erase via dualed **`Map_EraseRange_Isnil1d_Inferred`**, free header sentinel, null `head` and `size`. Same 46 B template as dualed `Map_Tidy_FreeHead` @ `0x0051da30` (isnil@+0x29 / `Map_EraseRange`) and `StdTree_Tidy_FreeHead_Bare_Val12` @ `0x0040d6d0`. Sole static consumer is atexit thunk for global host `0x00b04240`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `0x0051e120` (2026-08-04) — truncated after delete |
| Bytes | `read_memory` full 46 B; tails `C3`; nulls head+size |
| Erase range | dualed `Map_EraseRange_Isnil1d_Inferred` `0x0051d700` |
| Caller | `FUN_009c3940`: `MOV ECX,0xb04240; JMP 0x0051e120` |
| Peer tidy | dualed `Map_Tidy_FreeHead` `0x0051da30` |
| Raw / clean | `raw/aa_0051e120_*`, `reconstructed-exact/Map_Tidy_FreeHead_Isnil1d_Inferred.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 46 B; bare `ret` | **Confirmed** | full-body hex |
| `__fastcall`/`thiscall` ECX=map | **Confirmed** | `56 8B F1` |
| Full clear: first=`*head`, last=`head` | **Confirmed** | decomp ≡ bytes |
| Erase via `Map_EraseRange_Isnil1d_Inferred` | **Confirmed** | rel call target `0x0051d700` |
| Free head only; null head+size | **Confirmed** | bytes (decomp drops nulls) |
| Does not free map facade | **Confirmed** | no `this` delete |
| Twin of `Map_Tidy_FreeHead` (isnil1d) | **High** | same template; different erase |
| K/V / global host English | Open | |
| Product/PDB symbol | Open → `_Inferred` | |
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
| Discriminator via dualed isnil1d erase-range | **Yes** |
| Product/RTTI host English | **No** |
| Collapse into `Map_Tidy_FreeHead` same VA | **No** |

**Decision:** promote **`Map_Tidy_FreeHead_Isnil1d_Inferred`**.  
**Reject:** free-of-facade; product class name without RTTI; merge identity with isnil29 `Map_Tidy_FreeHead`.

---

## 6. Gaps

1. Product English for global `0x00b04240` and exact `map<K,V>`.
2. Nested free/erase-node duals of erase-range (not OWN).
3. Neighbor tidies `0051e150` / `0051e180` (WQ9F-H OWN; not dualled here).
4. Runtime / image diff / bit-exact.

**Verdict:** **accept-with-gaps**
