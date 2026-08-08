# Review A (reconstruction fidelity): `aa_004cbe20` StdMap_InsertOrFind_IntKey_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbe20` |
| **VA** | `0x004cbe20` |
| **Body** | `0x004cbe20`–`0x004cbed8` exclusive (**184** B) |
| **Canonical name** | `StdMap_InsertOrFind_IntKey_Isnil29_Inferred` (inferred) |
| **Ghidra symbol** | `FUN_004cbe20` |
| **Prior / alias** | `Named_CalleeOf_…_GetTargetFromAggro_004cbe20` (**reject** product) |
| **Review date** | `2026-08-04` (WQ9F-D OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004cbe20_StdMap_InsertOrFind_IntKey_Isnil29_Inferred.md` |
| **System** | std map insert-or-find (isnil29) |
| **Live tools** | Ghidra `batch_decompile`, `read_memory`, `analyze_function_complete`, callers/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Unique insert-or-find for maps with **isnil@+0x29** nodes and a **signed int32** key at node+0x10. Writes `{iterator, inserted}`; equal key does not rewrite mapped payload. Insert worker is dualed `StdTree_InsertAndRebalance_Isnil29_Inferred` @ `0x004cbb60`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9F-D append) | `docs/reconstruction/raw/aa_004cbe20_FUN_004cbe20.md` |
| Annotated | `docs/reconstruction/raw/aa_004cbe20_FUN_004cbe20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_IntKey_Isnil29_Inferred.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_004cbe20.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cbe20_StdMap_InsertOrFind_IntKey_Isnil29_Inferred.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | 184 B hex in raw append |
| Insert worker | dual sealed WQ9E-E `aa_004cbb60` |
| Skill caller | `Skill_InsertActiveCastBinding_Inferred` @ `0x00518ca0` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `51 55 8B 6C 24 10 56 57 8B F9` — out pair on stack; EBP=value*; EDI=map |
| isnil | `80 78 29 00` — **@+0x29** |
| Signed key | `3B 50 10` / `0F 9C C1` — cmp vs node+0x10; **SETL** |
| Insert | `E8` → `004cbb60` with addLeft 1 or goLeft |
| Predecessor | `E8` → `004cb4f0` |
| Equal | `C6 40 04 00` inserted=0 |
| Epilogue | `C2 08 00` **RET 8** ×3 |
| Body end | exclusive `0x004cbed8` (pad `CC` then `004cbee0`) |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size exclusive end | **pass** (184 B) |
| `ret 8` / thiscall | **pass** |
| isnil@+0x29 / key@+0x10 signed | **pass** |
| Equal → inserted=0 no rewrite | **pass** |
| Insert callee dualed isnil29 | **pass** (`004cbb60`) |
| Clean meaningful names | **pass** |
| Predecessor dual | **gap** (`FUN_004cb4f0`) |
| Product English / demangle | **gap** |
| Runtime / differential | **open** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI RET8 | **High** | live ≡ raw; bytes |
| Signed int key | **High** | SETL |
| Insert-or-find not always-insert | **High** | equal path |
| Shared helper (2 callers) | **High** | xrefs |
| Name structural `_Inferred` | **Inferred** | no product plate |
| Runtime | Open | |

---

## 6. Gaps (acceptable)

1. Product/demangle map value_type (6-dword Val24 insert payload).  
2. Dual of predecessor `FUN_004cb4f0`.  
3. Per-caller mapped field English beyond skill active-cast packing.  
4. Runtime / bit-exact / differential.
