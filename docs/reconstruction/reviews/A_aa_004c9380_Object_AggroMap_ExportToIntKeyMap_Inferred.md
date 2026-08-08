# Review A (reconstruction fidelity): `aa_004c9380` Object_AggroMap_ExportToIntKeyMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c9380` |
| **VA** | `0x004c9380` |
| **Body** | `0x004c9380`–`0x004c9428` exclusive (**168** B) |
| **Canonical name** | `Object_AggroMap_ExportToIntKeyMap_Inferred` (inferred) |
| **Ghidra symbol** | `FUN_004c9380` |
| **Review date** | `2026-08-04` (WQ9G-C OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004c9380_Object_AggroMap_ExportToIntKeyMap_Inferred.md` |
| **System** | Object aggro export / AI target prep |
| **Live tools** | Ghidra `batch_decompile`, `disassemble_function`, `read_memory`, `analyze_function_complete`, callers/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Export object aggro map (head @ +0x158) inorder into destination int-key map via dualed insert-or-find, keying each entry by **score @ +0x20**. Caller: `CVOGHBAIBase_GetTargetFromAggro`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9G-C re-verify) | `docs/reconstruction/raw/aa_004c9380_FUN_004c9380.md` |
| Annotated | `docs/reconstruction/raw/aa_004c9380_FUN_004c9380.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_AggroMap_ExportToIntKeyMap_Inferred.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_004c9380.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c9380_Object_AggroMap_ExportToIntKeyMap_Inferred.md` |
| Live decompile | walk CF ok; **ABI incomplete** (fixed by disasm) |
| Live RET | `read_memory` → `C2 04 00` |
| Insert-or-find | dualed WQ9F-D `004cbe20` |
| Caller context | live decompile `CVOGHBAIBase_GetTargetFromAggro` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `83 EC 20` / `53` / `8B D9` this |
| Source head | `8B 83 58 01 00 00` — **+0x158** |
| Dest map | `8B 7C 24 30` after pushes |
| Score key | `8B 46 20` → `[ESP+0x14]` value[0] |
| TFID pack | loads `[ESI+0x10..0x1C]` → value+8 region |
| insert-or-find | `8B CF` (ECX=dest) / `E8` → `004cbe20` |
| isnil successor | `80 7E 29 00` and child/parent walks |
| Epilogue | `83 C4 20` / `C2 04 00` **RET 4** |
| Body end | exclusive `0x004c9428` (pad `CC`) |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Inorder walk + insert call CF | **pass** |
| Body size exclusive end | **pass** (168 B) |
| `ret 4` / thiscall + dest arg | **pass** (disasm; decomp wrong) |
| Source head +0x158 / isnil+0x29 | **pass** |
| Score as int key | **pass** |
| Insert callee dualed int-key | **pass** (`004cbe20`) |
| Clean meaningful names | **pass** |
| Unwritten value dword1 | **preserved** (odd) |
| Equal-score collapse | **preserved** (insert-or-find contract) |
| Product method English | **gap** |
| Runtime / differential | **open** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF export loop | **High** | disasm ≡ annotated |
| ABI RET4 + dest | **High** | bytes supersede decomp |
| Aggro head +0x158 | **High** | matches dualed aggro peers |
| Product English | **Low** | `_Inferred` |

---

## 6. Gaps

- Product / PDB method name on Object / AI host.
- Dest map value_type English (score key + TFID payload layout).
- Intent of unwritten value[+4].
- Runtime / bit-exact / differential.

---

## 7. Verdict

**accept-with-gaps** — export CF/ABI/RET4/score-key/insert-or-find callee/successor sealed; decomp ABI gap closed by bytes; product English open.
