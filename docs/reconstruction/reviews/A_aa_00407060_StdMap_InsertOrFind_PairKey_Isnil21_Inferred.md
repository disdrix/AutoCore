# Review A (reconstruction fidelity): `aa_00407060` StdMap_InsertOrFind_PairKey_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407060` |
| **VA** | `0x00407060` |
| **Body** | `0x00407060`–`0x00407133` exclusive (**211** B / `0xD3`) |
| **Canonical name** | `StdMap_InsertOrFind_PairKey_Isnil21_Inferred` (inferred) |
| **Ghidra symbol** | `FUN_00407060` |
| **Review date** | `2026-08-05` (WQ9I-C OWN-ONLY dual) |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_00407060_StdMap_InsertOrFind_PairKey_Isnil21_Inferred.md` |
| **System** | std map insert-or-find (isnil21 pair key) |
| **Live tools** | decompile + read_memory + analyze + callers/xrefs + disassemble_function (**no** disassemble_bytes) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Unique insert-or-find for **isnil@+0x21** maps keyed by a **two-dword pair** (signed hi @ node+0x14 primary, unsigned lo @ node+0x10 secondary). Insert worker `FUN_00407200`; predecessor `FUN_005adff0`. Sole image caller: dualed hint-insert parent `FUN_00406560` fallthrough.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9I-C append) | `docs/reconstruction/raw/aa_00407060_FUN_00407060.md` |
| Annotated | `docs/reconstruction/raw/aa_00407060_FUN_00407060.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_PairKey_Isnil21_Inferred.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_00407060.cpp` |
| Function record | `docs/reconstruction/functions/aa_00407060_StdMap_InsertOrFind_PairKey_Isnil21_Inferred.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | 211 B hex in raw append |
| Parent context | dualed InsertHint `0x00406560`; peer isnil29 pair `0x004cbee0` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `51 55 8B 6C 24 10 56 57 8B F9` |
| isnil | `80 78 21 00` (CMP byte [EAX+0x21],0) |
| Hi compare | `3B 50 14` / `7F` / `7C` — signed vs node+0x14 |
| Lo compare | `3B 58 10` / `73` — **unsigned JAE** vs node+0x10 |
| Insert | `E8`→`00407200` ×2 |
| Pred | `E8`→`005adff0` |
| Out inserted | `C6 40 04 01` / `C6 40 04 00` |
| RET 8 | `C2 08 00` ×3 |
| Body end | exclusive `0x00407133`; pad `CC` |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** (cursor aliasing noted) |
| Body size | **pass** (211 B) |
| RET 8 thiscall | **pass** |
| Pair order hi signed / lo unsigned | **pass** |
| Equal no rewrite | **pass** |
| isnil@+0x21 family | **pass** |
| Insert worker dualed | **gap** (WQ9I-B) |
| Product pair English | **gap** |
| Runtime | **open** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | bytes + disasm |
| Pair key compare | **High** | opcodes match isnil29 peer |
| Role insert-or-find shell | **High** | caller InsertHint fallthrough |
| Name `_Inferred` | **Inferred** | product open |
| Runtime | Open | |

---

## 6. Gaps (acceptable)

1. Product demangle / English for pair type.  
2. Dual of insert `FUN_00407200` (WQ9I-B) and pred `FUN_005adff0`.  
3. Runtime / bit-exact / differential.
