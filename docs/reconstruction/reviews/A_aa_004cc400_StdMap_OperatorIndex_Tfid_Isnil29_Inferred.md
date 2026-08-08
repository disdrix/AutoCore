# Review A (reconstruction fidelity): `aa_004cc400` StdMap_OperatorIndex_Tfid_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cc400` |
| **VA** | `0x004cc400` |
| **Body** | `0x004cc400`–`0x004cc469` exclusive (**105** B) |
| **Canonical name** | `StdMap_OperatorIndex_Tfid_Isnil29_Inferred` (inferred) |
| **Ghidra symbol** | `FUN_004cc400` |
| **Review date** | `2026-08-04` (WQ9G-C OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004cc400_StdMap_OperatorIndex_Tfid_Isnil29_Inferred.md` |
| **System** | std map operator[] (isnil29 / TFID pair) |
| **Live tools** | Ghidra `batch_decompile`, `disassemble_function`, `read_memory`, `analyze_function_complete`, callers/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Get-or-insert mapped for TFID-shaped pair-key maps: dualed lower_bound + equality gate; miss → dualed insert-hint with mapped 0; return `node+0x20`. **Sole** caller of `StdTree_InsertHint_Isnil29_Inferred`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9G-C re-verify) | `docs/reconstruction/raw/aa_004cc400_FUN_004cc400.md` |
| Annotated | `docs/reconstruction/raw/aa_004cc400_FUN_004cc400.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_OperatorIndex_Tfid_Isnil29_Inferred.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_004cc400.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cc400_StdMap_OperatorIndex_Tfid_Isnil29_Inferred.md` |
| Live decompile | ≡ CF |
| Live body / RET | `read_memory` seals `ADD EAX,0x20` + `C2 04 00` |
| Callees | dualed `004cb4b0` (W31-N), dualed `004cc220` (WQ9F-E) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `83 EC 18` / `56` / load key ESI / `8B F9` map |
| lower_bound | `E8` → `004cb4b0` |
| Head compare | `3B 47 04` vs `map+4` |
| Hi signed | `8B 4E 04` / `3B 48 14` / `JG` hit / `JL` insert |
| Lo unsigned | `3B 50 10` / `JNC` hit |
| Stage mapped0 | `C7 44 24 24 00 00 00 00` |
| insert-hint | `E8` → `004cc220` |
| Mapped return | `83 C0 20` |
| Epilogue | `C2 04 00` **RET 4** |
| Body end | exclusive `0x004cc469` (pad `CC`) |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size exclusive end | **pass** (105 B) |
| `ret 4` / thiscall | **pass** |
| Sole insert-hint caller | **pass** (1 xref to `004cc220` from this) |
| TFID pair order hi/lo | **pass** (matches lower_bound / pair peers) |
| Default mapped 0 on insert | **pass** |
| Clean meaningful names | **pass** |
| Product English / demangle | **gap** |
| Full TFID 16 B vs 8 B compare English | **gap** (structural only) |
| Runtime / differential | **open** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI RET4 | **High** | live ≡ raw; bytes |
| operator[] role | **High** | LB + eq + insert default + mapped* |
| Sole hint caller | **High** | WQ9F-E + this xref |
| Product method name | **Low** | `_Inferred` |

---

## 6. Gaps

- Product / MSVC demangle for map value_type / class method.
- Whether product names this `operator[]` vs `insert` wrapper.
- Runtime / bit-exact / differential.

---

## 7. Verdict

**accept-with-gaps** — CF/ABI/RET4/TFID-pair equality/insert-hint sole-caller/mapped@+0x20 sealed; product English open.
