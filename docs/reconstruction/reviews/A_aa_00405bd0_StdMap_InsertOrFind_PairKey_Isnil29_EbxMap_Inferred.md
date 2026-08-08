# Review A (reconstruction fidelity): `aa_00405bd0` StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00405bd0` |
| **VA** | `0x00405bd0` |
| **Body** | `0x00405bd0`–`0x00405c7e` inclusive (**175** B / `0xAF`) |
| **Canonical name** | `StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred` (inferred) |
| **Ghidra symbol** | `FUN_00405bd0` |
| **Prior / alias** | `Named_CalleeOf_…_Error_Received_a_packet_of_00405bd0` (**reject** product) |
| **Review date** | `2026-08-05` (WQ9K-D OWN-ONLY dual) |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_00405bd0_StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred.md` |
| **System** | std map insert-or-find (isnil29 pair key, register ABI) |
| **Live tools** | decompile + disassemble_function + read_memory + callers/xrefs (**no** disassemble_bytes) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Unique insert-or-find for **isnil@+0x29** maps keyed by a **two-dword pair** (signed hi @ +0x14 primary, unsigned lo @ +0x10 secondary). Register ABI: **EBX**=map, **EAX**=value, **ESI**=out. Insert worker undualed `0x004069f0`. Pred dualed `0x00409820`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9K-D append) | `docs/reconstruction/raw/aa_00405bd0_FUN_00405bd0.md` |
| Annotated | `docs/reconstruction/raw/aa_00405bd0_FUN_00405bd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_00405bd0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00405bd0_StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred.md` |
| Live decompile | ≡ raw CF (unaff formals = register ABI) |
| Live body bytes | 175 B hex in raw append |
| Parent context | `FUN_0092ff00` TFID resolve path (2 call sites) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `83 EC 08` / `8B 4B 04` / `8B F8` — EBX map, EAX→EDI value |
| Pair load | `[EDI+4]` hi / `[EDI]` lo vs node+0x14 / +0x10 |
| Hi compare | `3B 50 14` / `7F` / `7C` — signed |
| Lo compare | `3B 48 10` / `73` / `JNC` — **unsigned** |
| isnil | `80 78 29 00` |
| Pred / insert | `E8`→`00409820`; `E8`→`004069f0` |
| Exit | bare `C3` ×2 (found / inserted); EAX=ESI |
| Body end | inclusive `0x00405c7e` |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size 175 B | **pass** |
| bare RET register ABI | **pass** |
| Pair order hi signed / lo unsigned | **pass** |
| Equal no rewrite (inserted=0) | **pass** |
| Pred dualed | **pass** |
| Insert worker dual | **gap** (`004069f0`) |
| Product pair English (TFID vs custom) | **gap** |
| Runtime | **open** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | disasm sealed |
| Pair key compare | **High** | opcodes |
| Role insert-or-find shell | **High** | MSVC pattern |
| Name `_Inferred` + EbxMap | **Inferred** | ABI suffix |
| Runtime | Open | |

---

## 6. Gaps (acceptable)

1. Product demangle / English for pair type (TFID host only).  
2. Dual of insert worker `FUN_004069f0`.  
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
