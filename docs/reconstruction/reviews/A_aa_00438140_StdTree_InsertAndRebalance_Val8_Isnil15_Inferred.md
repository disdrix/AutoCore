# Review A (reconstruction fidelity): `aa_00438140` StdTree_InsertAndRebalance_Val8_Isnil15_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00438140` |
| **VA** | `0x00438140` |
| **Body** | `0x00438140`–`0x004382be` inclusive (**383 B**) |
| **Canonical name** | `StdTree_InsertAndRebalance_Val8_Isnil15_Inferred` (inferred) |
| **Ghidra symbol** | `FUN_00438140` |
| **Prior / alias** | `Named_CalleeOf_*Mission_bActiveObj_00438140` (**reject** product) |
| **Review date** | `2026-08-04` (W38-L OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00438140_StdTree_InsertAndRebalance_Val8_Isnil15_Inferred.md` |
| **System** | std map/set tree Val8 isnil15 |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, callers/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Always-insert + red-black rebalance for Val8 (`0x18`) tree nodes (color@+0x14, isnil@+0x15). Shared multi-caller helper; parents perform lower-bound / unique key policy.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00438140_FUN_00438140.md` (+ W38-L append) |
| Annotated | `docs/reconstruction/raw/aa_00438140_FUN_00438140.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val8_Isnil15_Inferred.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_00438140.cpp` |
| Function record | `docs/reconstruction/functions/aa_00438140_StdTree_InsertAndRebalance_Val8_Isnil15_Inferred.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | full 383 B hex in raw append |
| Parent dual | W37-K `aa_00458510` (calls this helper) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| SEH | `64 A1 … 6A FF 68 19 C9 9B 00` — `LAB_009bc919` |
| Max size | `81 7F 08 FE FF FF 1F` — **`[EDI+8] ? 0x1ffffffd`** |
| Buynode | call `FUN_00439110` with color push `6A 00`; ESI←stack value |
| Color test | `80 79 14 00` / `80 7A 14 00` — byte **@+0x14** |
| Rotates | calls `FUN_004219b0`, `FUN_0046f030` |
| Epilogue | `83 C4 50 C2 10 00` — **RET 0x10** |
| Body end | inclusive `0x004382be` then `CC` |

Full hex: see raw W38-L append.

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body 383 B / RET 0x10 | **pass** |
| EDI=map register ABI | **pass** (bytes + unaff_EDI) |
| Always-insert (no key cmp) | **pass** |
| Val8 color@+0x14 isnil@+0x15 | **pass** (buynode + RB) |
| Max `0x1ffffffd` (not Val12 `0x15555553`) | **pass** |
| Clean avoids bare `undefined4` | **pass** |
| Buynode / rotate duals | **gap** (unOWN) |
| Product English | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + always-insert + RB | **High** | live ≡ raw |
| ABI EDI / ret 0x10 / 4 stack args | **High** | epilogue + call sites |
| Multi-caller shared helper | **High** | 6 fn / 24 sites |
| Name structural `_Inferred` | **Inferred** | no product plate |
| Runtime / differential | Open | |

---

## 6. Gaps (acceptable)

1. Full dual of buynode `FUN_00439110` and rotate clones `004219b0`/`0046f030`.  
2. Product/demangle names for the six caller map types.  
3. Buynode null OOM path.  
4. Runtime / bit-exact / differential.
