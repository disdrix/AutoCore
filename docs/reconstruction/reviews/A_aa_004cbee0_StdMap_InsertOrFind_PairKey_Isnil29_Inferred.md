# Review A (reconstruction fidelity): `aa_004cbee0` StdMap_InsertOrFind_PairKey_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbee0` |
| **VA** | `0x004cbee0` |
| **Body** | `0x004cbee0`–`0x004cbfb2` exclusive (**210** B) |
| **Canonical name** | `StdMap_InsertOrFind_PairKey_Isnil29_Inferred` (inferred) |
| **Ghidra symbol** | `FUN_004cbee0` |
| **Prior / alias** | `Named_CalleeOf_…_VOG_DEBUG_ST_004cbee0` (**reject** product) |
| **Review date** | `2026-08-04` (WQ9F-D OWN-ONLY dual) |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_004cbee0_StdMap_InsertOrFind_PairKey_Isnil29_Inferred.md` |
| **System** | std map insert-or-find (isnil29 pair key) |
| **Live tools** | decompile + read_memory + analyze + callers/xrefs (**no** disassemble_bytes) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Unique insert-or-find for **isnil@+0x29** maps keyed by a **two-dword pair** (signed hi @ +0x14 primary, unsigned lo @ +0x10 secondary). Same insert worker `0x004cbb60` as int-key peer. Sole image caller: hint-insert parent `FUN_004cc220` fallthrough.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9F-D append) | `docs/reconstruction/raw/aa_004cbee0_FUN_004cbee0.md` |
| Annotated | `docs/reconstruction/raw/aa_004cbee0_FUN_004cbee0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_PairKey_Isnil29_Inferred.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_004cbee0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cbee0_StdMap_InsertOrFind_PairKey_Isnil29_Inferred.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | 210 B hex in raw append |
| Parent context | `FUN_004cc220` uses same pair compare + `FUN_00401480` elsewhere |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `51 55 8B 6C 24 10 56 57 8B F9` — same shell as int-key peer |
| Pair load | `8B 55 04` / `53` / `8B 5D 00` — hi in EDX, lo in EBX |
| Hi compare | `3B 50 14` / `7F` / `7C` — signed vs node+0x14 |
| Lo compare | `3B 58 10` / `73` — **unsigned JAE** vs node+0x10 |
| isnil | `80 78 29 00` |
| Insert / pred / RET8 | `E8`→`004cbb60`; `E8`→`004cb4f0`; `C2 08 00` ×3 |
| Body end | exclusive `0x004cbfb2` |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size | **pass** (210 B) |
| RET 8 thiscall | **pass** |
| Pair order hi signed / lo unsigned | **pass** |
| Equal no rewrite | **pass** |
| Insert worker dualed | **pass** |
| Product pair English (TFID vs custom) | **gap** |
| Predecessor dual | **gap** |
| Runtime | **open** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | |
| Pair key compare | **High** | opcodes |
| Role insert-or-find shell | **High** | |
| Name `_Inferred` | **Inferred** | |
| Runtime | Open | |

---

## 6. Gaps (acceptable)

1. Product demangle / English for pair type.  
2. Dual of `FUN_004cb4f0` and hint parent `FUN_004cc220` (other partition).  
3. Runtime / bit-exact / differential.
