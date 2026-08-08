# Review A (reconstruction fidelity): `aa_00409220` Map_EraseNode_B

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409220` |
| **VA** | `0x00409220`–`0x004094b4` exclusive (**660 B** by bytes) |
| **Canonical name** | `Map_EraseNode_B` |
| **Ghidra name** | `FUN_00409220` |
| **Review date** | `2026-08-04` (WQ9E-G OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00409220_Map_EraseNode_B.md` |
| **System** | STL / map-set |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` entry/tail + string + callees/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style red-black **single-node erase** for the large payload map/set family (isnil@+0x29). Twin of dualed `Map_EraseNode` (`0x0051cb40`). Callers include range-erase loop `FUN_00407d70` and several host erase sites.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | `0x00409220` |
| Bytes | `read_memory` entry + mid + post-delete through **`ret 8`** |
| String | `"invalid map/set<T> iterator"` @ `0x00a152f0` |
| Twin | `Map_EraseNode` `aa_0051cb40` (W19-I) — same CF/callees |
| Rotates / Min / Max | dualed isnil29 units |
| Raw / clean | `raw/aa_00409220_*`, `reconstructed-exact/Map_EraseNode_B.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x00409220`–`0x004094b4` (660 B) | **Confirmed** | bytes; Ghidra end `0x00409484` superseded |
| `__thiscall` ECX=map; stack `(outIt, pNode)`; **`ret 8`** | **Confirmed** | `C2 08 00` @ epilogue |
| isnil gate `@node+0x29` → throw string | **Confirmed** | decomp + string VA |
| Unlink + RB rebalance (color `@+0x28`) | **Confirmed** | decomp + rot/Min/Max callees |
| `operator_delete` falls through | **Confirmed** | size-- + `*outIt` after call |
| `map+0x08` size-- if >0 | **Confirmed** | post-delete bytes |
| `*outIt = successor` | **Confirmed** | tail store |
| Successor via `FUN_004cb270` | **High** | callee; same as twin |
| Twin of `Map_EraseNode` | **High** | CF/callees/family match; throw path differs |
| Product/PDB symbol | **Inferred structural** | `_B` twin naming like `Map_EraseRange_B` |
| Chain-of-caller name | **Falsified** as canonical | reject Named_CalleeOf_* |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| isnil → throw | **Yes** |
| successor + unlink + rebalance | **Yes** (raw/live; plate incomplete on post-delete) |
| delete → size-- → out it → ret 8 | **Yes** (bytes seal post-delete) |
| Two-child transplant “unreachable” | **Present in image** (decomp warning false) |
| No invent key compare in body | **Yes** (erase-by-node only) |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| STL throw string | **Yes** |
| RB erase structure | **Yes** |
| Twin `Map_EraseNode` dualed | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`Map_EraseNode_B`** (structural twin; no product English required — same bar as `Map_EraseNode` / `Map_EraseRange_B`).

---

## 6. Gaps

1. Product/PDB symbol for this MSVC instantiation vs `0x0051cb40`.
2. Per-caller value payload English.
3. Full algebra residual on every rotation case (CF sealed).
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
