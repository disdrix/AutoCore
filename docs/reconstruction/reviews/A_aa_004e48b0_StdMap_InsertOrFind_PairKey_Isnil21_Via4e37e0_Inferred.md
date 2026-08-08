# Review A (reconstruction fidelity): `aa_004e48b0` StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e48b0` |
| **VA** | `0x004e48b0` |
| **Body** | `0x004e48b0`–`0x004e4982` inclusive (**211 B** / `0xD3`); exclusive `0x004e4983` |
| **Canonical name** | `StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred` |
| **Ghidra symbol** | `FUN_004e48b0` |
| **Prior / alias** | `Named_CalleeOf_CVOGReaction_UpdateRepairStationPosition_004e48b0` (narrow) |
| **Review date** | `2026-08-05` (R13-005 OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004e48b0_StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred.md` |
| **System** | skills-abilities / STL map insert-or-find |
| **Parent dual** | `0x004e37e0` `StdTree_InsertAndRebalance_Val16_Isnil21_Inferred` |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `get_function_callers` / `get_function_xrefs` / `get_xrefs_to`, `read_memory` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Unique insert-or-find for **isnil@+0x21** maps keyed by a **two-dword pair** (signed hi @ node+0x14 primary, unsigned lo @ node+0x10 secondary). Insert worker dualed `FUN_004e37e0`; predecessor residual `FUN_005adff0`. Equal hit returns `{it,0}` without rewriting mapped payload.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R13-005 append) | `docs/reconstruction/raw/aa_004e48b0_FUN_004e48b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004e48b0_FUN_004e48b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_004e48b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e48b0_StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | full 211 B + epilogue pad via `read_memory` |
| Insert worker | dualed `004e37e0` `StdTree_InsertAndRebalance_Val16_Isnil21_Inferred` |
| Peer shell clone | dualed `00407060` `StdMap_InsertOrFind_PairKey_Isnil21_Inferred` (insert `00407200`) |
| Callers | `CVOGReaction_UpdateRepairStationPosition`; residual `FUN_004da160` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `51 55 8B 6C 24 10 56 57 8B F9` |
| isnil | `80 78 21 00` (CMP byte [EAX+0x21],0) |
| Hi compare | `3B 50 14` / `7F` / `7C` — signed vs node+0x14 |
| Lo compare | `3B 58 10` / `73` — **unsigned JAE** vs node+0x10 |
| Insert | `E8`→`004e37e0` ×2 (`004e4919`, `004e495a`) |
| Pred | `E8`→`005adff0` |
| Out inserted | `C6 40 04 01` / `C6 40 04 00` |
| RET 8 | `C2 08 00` ×3 |
| Body end | exclusive `0x004e4983`; pad `CC` |

Entry hex (64 B):

```
51558b6c241056578bf98b4f048b4104807821008bf1b101884c240c752f8b5504538b5d003b50148bf07f117c053b5810730a8b00b101884c2410eb098b4008
```

Epilogue tail (@ `0x004e4970`):

```
08008b4424145f5ec640040089105d59c20800cccccccccccccccccccccccccc
; ... ret 0x8; int3 pad
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** (cursor aliasing of `param_3` as where noted) |
| Body size exclusive end | **pass** (`004e4983`, 211 B) |
| `ret 0x8` / 2 stack args | **pass** |
| thiscall ECX=map | **pass** (`mov edi,ecx`) |
| Pair order hi signed / lo unsigned | **pass** (bytes) |
| Equal no rewrite | **pass** (`inserted=0` only) |
| isnil@+0x21 family | **pass** |
| Insert worker = dualed `004e37e0` | **pass** |
| Distinct from peer clone `00407060` | **pass** (different insert VA) |
| Product English | **gap** |
| Pred dual `005adff0` | **gap** (residual) |
| Runtime / differential | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 0x8; full body bytes |
| Pair key compare order | **High** | opcodes match peer shells |
| Role insert-or-find shell | **High** | lower_bound + insert-or-equal + out pair |
| Name `…_Via4e37e0_Inferred` | **Inferred** | structural; distinguishes `00407060` |
| Runtime / differential | Open | never Runtime Confirmed |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| isnil@+0x21 + Val16 insert worker dualed | **Yes** |
| Pair hi signed / lo unsigned compare | **Yes** |
| Equal path no rewrite | **Yes** |
| Peer shell same CF different insert clone | **Yes** (`00407060`) |
| Product/PDB English for pair type | **No** |

**Decision:** promote **`StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred`** (structural High; English unproven → `_Inferred`). Reject merge with `00407060` / isnil29 pair `004cbee0` / int-key shells / always-insert-only / Runtime Confirmed.

---

## 7. Gaps

1. Product/PDB demangle for the pair key (TFID-shaped under repair-station path is plausible, not sealed).  
2. Full dual of residual predecessor `005adff0` and second caller `004da160` (not OWN).  
3. Bit-exact / differential / runtime — open.

**Verdict:** **accept-with-gaps**
