# Review A (reconstruction fidelity): `aa_006cac60` LinkPair_QuickSort_DualKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cac60` |
| **VA** | `0x006cac60` |
| **Body** | `0x006cac60`–`0x006cad2f` exclusive (**207** B) |
| **Canonical name** | `LinkPair_QuickSort_DualKey_Inferred` |
| **Ghidra symbol** | `FUN_006cac60` |
| **Prior / alias** | `Named_CalleeOf_…_VOG_DEBUG_ST_006cac60` (narrow) |
| **Review date** | `2026-07-29` (W29-Q OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_006cac60_LinkPair_QuickSort_DualKey_Inferred.md` |
| **System** | phys / bind link-pair list prep (qsort) |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, function metadata (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Quicksort array of 8-byte object pairs on dual unsigned keys `(a+4, b+4)` over inclusive `[lo, hi]`. Nested engine of `LinkPair_CanonAndSort_Inferred`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006cac60_FUN_006cac60.md` (+ W29-Q append) |
| Annotated | `docs/reconstruction/raw/aa_006cac60_FUN_006cac60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LinkPair_QuickSort_DualKey_Inferred.cpp` |
| Twin | `reconstructed-exact/FUN_006cac60.cpp` |
| Function record | `docs/reconstruction/functions/aa_006cac60_LinkPair_QuickSort_DualKey_Inferred.md` |
| Live decompile | ≡ raw 2026-07-23 |
| Live body bytes | full 207 B via `read_memory` |
| Parent dual | `aa_006cad30` LinkPair_CanonAndSort_Inferred (W28-Q) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `push ebp; mov ebp,esp; and esp,0xfffffff0; sub esp,0x14` |
| Mid pivot | `lea ecx,[edi+eax]; sar ecx,1` then load pair at `array+mid*8` |
| Key loads | `[reg+4]` unsigned compares (`jb` / setb patterns in decomp) |
| Pair swap | 8-byte exchange of both dwords at `i*8` and `j*8` |
| Left recurse | `push unused; push j; push lo; push array; call self; add esp,0x10` |
| Right tail | `mov [ebp+lo], i; jmp outer` when `i < hi` |
| Epilogue | `pop edi/esi/ebx; mov esp,ebp; pop ebp; ret` |

Full body hex (207 B):

```
558bec83e4f083ec148b451053568b7508578b7d0c8d0c07d1f98b14ce8b5cce0489542410895c2414eb058b5c2414908b4c24108b51048b0cfe8b49043bca721375148b4cfe048b49043b4b040f92c184c9740347ebe08b0cc68b49043bd1721375188b4cc6048b5b043b59040f92c184c974078b5c241448ebdc3bc77c24741c8b1cfe8b0cc68b54c604891cc68b5cfe04895cc604890cfe8954fe0448473bf87e888b4d0c3bc87d0f8b551452505156e84affffff83c4108b45103bf87d08897d0ce94affffff5f5e5b8be55dc3
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** |
| Body size 207 B exclusive end | **pass** (`006cad2f`) |
| cdecl plain ret | **pass** |
| Dual-key primary then secondary @+4 | **pass** |
| Stride 8 full-pair swap | **pass** |
| Left recurse + right tail loop | **pass** |
| param_4 unused in body | **pass** |
| Parent call site (lo=0, hi=count-1) | **pass** (W28-Q CanonAndSort) |
| Product object type | **gap** (non-blocking) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | full body hex sealed |
| Dual-key unsigned @+4 | **High** | |
| Role under CanonAndSort | **High** | sole external caller |
| Name `LinkPair_QuickSort_DualKey_Inferred` | **Inferred** | LinkPair_* family |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product type behind pair pointers / meaning of field +4.  
2. Bit-exact / differential — open.  
3. Sort stability for equal dual-keys — not claimed (standard qsort not stable).

**Verdict:** **accept** (gaps residual / non-blocking for CF-ABI seal)
