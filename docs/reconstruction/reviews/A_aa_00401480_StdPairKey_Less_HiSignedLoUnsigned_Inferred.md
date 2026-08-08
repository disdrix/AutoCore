# Review A (reconstruction fidelity): `aa_00401480` StdPairKey_Less_HiSignedLoUnsigned_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401480` |
| **VA** | `0x00401480` |
| **Body** | `0x00401480`–`0x004014a5` exclusive (**37** B / `0x25`) |
| **Canonical name** | `StdPairKey_Less_HiSignedLoUnsigned_Inferred` (inferred) |
| **Ghidra symbol** | `FUN_00401480` |
| **Prior / alias** | `Named_CalleeOf_…_VOG_DEBUG_ST_00401480` (**reject** product) |
| **Review date** | `2026-08-04` (WQ9G-B OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00401480_StdPairKey_Less_HiSignedLoUnsigned_Inferred.md` |
| **System** | std 2-dword pair-key less-than (insert-hint) |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete`, callers/xrefs, `get_assembly_context` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Leaf** strict **less-than** comparator for a **2-dword key**:

- **hi** @ key+4: **signed** primary order  
- **lo** @ key+0: **unsigned** secondary order  

```
less(a,b) := (a.hi < b.hi) || (a.hi == b.hi && a.lo < b.lo)
```

Returns **1** if less, else **0**. Used by dualed `StdTree_InsertHint_Isnil29_Inferred` (`0x004cc220`) and peer hint `FUN_00406560` against node keys at **+0x10/+0x14**.

**ABI:** two stack pointers; **`C2 08 00` RET 8**; EAX = 0|1. Leaf (no callees).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9G-B append) | `docs/reconstruction/raw/aa_00401480_FUN_00401480.md` |
| Annotated | `docs/reconstruction/raw/aa_00401480_FUN_00401480.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdPairKey_Less_HiSignedLoUnsigned_Inferred.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_00401480.cpp` |
| Function record | `docs/reconstruction/functions/aa_00401480_StdPairKey_Less_HiSignedLoUnsigned_Inferred.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | 37 B hex in raw append |
| Insert-hint parent | dualed `StdTree_InsertHint_Isnil29_Inferred` @ `0x004cc220` |
| Pair insert-or-find peer | dualed `StdMap_InsertOrFind_PairKey_Isnil29_Inferred` (same hi/lo order, inlined) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| arg1 / arg2 | `8B 44 24 04` / `8B 4C 24 08` |
| load a.hi | `8B 50 04` |
| signed hi cmp | `3B 51 04` + `7F 10` (JG → 0) + `7C 06` (JL → 1) |
| lo unsigned cmp | `8B 00` / `3B 01` + `73 08` (**JAE** → 0) |
| return 1 | `B8 01 00 00 00` |
| return 0 | `33 C0` |
| Epilogue | `C2 08 00` ×2 |
| Body end | exclusive `0x004014a5` (pad `CC`) |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size exclusive end | **pass** (37 B) |
| RET 8; two stack args | **pass** |
| hi signed / lo unsigned | **pass** (JG/JL vs JAE) |
| Strict less (not ≤ as sole result) | **pass** |
| Leaf | **pass** |
| Clean meaningful names | **pass** |
| Product pair English | **gap** |
| Runtime / differential | **open** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + RET 8 ABI | **High** | live ≡ raw; bytes |
| hi signed primary | **High** | JG/JL |
| lo unsigned secondary | **High** | JAE |
| Insert-hint key comparator | **High** | 10 xrefs / 2 callers |
| Name structural `_Inferred` | **Inferred** | no product plate |
| Runtime | Open | |

---

## 6. Gaps (acceptable)

1. Product / demangle English for the 2-dword pair (TFID vs custom).  
2. Full inventory of maps using this comparator beyond the two hint shells.  
3. Runtime / bit-exact / differential.
