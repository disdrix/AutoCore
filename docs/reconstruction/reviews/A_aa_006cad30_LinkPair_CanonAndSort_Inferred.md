# Review A (reconstruction fidelity): `aa_006cad30` LinkPair_CanonAndSort_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cad30` |
| **VA** | `0x006cad30` |
| **Body** | `0x006cad30`–`0x006cad7f` exclusive (**79** B) |
| **Canonical name** | `LinkPair_CanonAndSort_Inferred` |
| **Ghidra symbol** | `FUN_006cad30` |
| **Prior / alias** | `Named_CalleeOf_…_VOG_DEBUG_STOP_006cad30` (narrow) |
| **Review date** | `2026-07-29` (W28-Q OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_006cad30_LinkPair_CanonAndSort_Inferred.md` |
| **System** | phys / bind link-pair list prep |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, function metadata (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

For an array of 8-byte object pairs: order each pair so `a->(+4) ≤ b->(+4)` (unsigned), then quicksort the array with dual-key compare via `FUN_006cac60`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006cad30_FUN_006cad30.md` (+ W28-Q append) |
| Annotated | `docs/reconstruction/raw/aa_006cad30_FUN_006cad30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LinkPair_CanonAndSort_Inferred.cpp` |
| Twin | `reconstructed-exact/FUN_006cad30.cpp` |
| Function record | `docs/reconstruction/functions/aa_006cad30_LinkPair_CanonAndSort_Inferred.md` |
| Live decompile | ≡ raw |
| Live body bytes | full 79 B via `read_memory` |
| Caller dual | `aa_006297e0` Phys_CommitPairListStorage (W27-M); merge `aa_006caaa0` (W27-N) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Entry | `push edi; mov edi,[esp+0xc]` (count) |
| Early out | `test edi,edi; jz` |
| Stride | scaled index `*8` (`iVar4 * 8`) |
| Key | `[reg+4]` unsigned compare |
| Low-byte clear | `mov byte ptr [esp+0xc], 0` |
| Qsort call | `push unused; push count-1; push 0; push array; call FUN_006cac60; add esp,0x10` |
| Epilogue | `pop edi; ret` |

Full body hex (79 B):

```
578b7c240c85ff74458b4c240833c085ff7e1f53568b54c1048b34c18b5e043b5a0476078914c18974c104403bc77ce55e5b83ff01c644240c007e128b44240c504f576a0051e8e5feffff83c4105fc3
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** |
| Body size 79 B exclusive end | **pass** (`006cad7f`) |
| cdecl plain ret | **pass** |
| Per-pair canon on key@+4 | **pass** |
| count>1 → FUN_006cac60 | **pass** |
| count==0 / count==1 no sort | **pass** |
| Dual-list callers (×2 sites in commit) | **pass** (xrefs) |
| Product object type | **gap** |
| Nested qsort dual | **gap** (not OWN) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | full body hex sealed |
| Pair stride 8 + key@+4 | **High** | |
| Role in bind/unbind pipeline | **High** | W27-M/N context |
| Name `LinkPair_CanonAndSort_Inferred` | **Inferred** | LinkPair_* family |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product type behind pair pointers.  
2. Nested `FUN_006cac60` full dual (not OWN).  
3. Bit-exact / differential — open.

**Verdict:** **accept** (gaps residual / non-blocking for CF-ABI seal)
