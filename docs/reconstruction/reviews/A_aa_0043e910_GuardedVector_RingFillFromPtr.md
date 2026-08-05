# Review A (reconstruction fidelity): `aa_0043e910` GuardedVector_RingFillFromPtr

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e910` |
| **VA** | `0x0043e910`–`0x0043e963` (**84 B**) |
| **Canonical name** | `GuardedVector_RingFillFromPtr` (**Inferred**) |
| **Ghidra name** | `FUN_0043e910` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-K) |
| **Counterpart** | `reviews/B_aa_0043e910_GuardedVector_RingFillFromPtr.md` |
| **System** | STL / guarded ring-vector container |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 84 B) + `analyze_function_complete`; sole caller `0043e080` (3 xrefs); leaf |
| **Verdict** | **accept** |

---

## 1. Purpose

Forward half-open ring fill from a stack fill pointer:

1. While `(start_c, start_i) != (end_c, end_i)`.
2. Map `start_i` through capacity-wrapped block table on **start** container.
3. If dest element address ≠ fill pointer, `*dest = *fill`.
4. `start_i++`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043e910_FUN_0043e910.md` (+ 2026-07-29 W33-K append) |
| Annotated | `docs/reconstruction/raw/aa_0043e910_FUN_0043e910.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingFillFromPtr.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e910.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043e910_FUN_0043e910.md` |
| Named record | `docs/reconstruction/functions/aa_0043e910_GuardedVector_RingFillFromPtr.md` |
| Live | decompile ≡ raw; body end `C3` before pad/`FUN_0043e970`; 3 call xrefs from InsertN_Thiscall |

---

## 3. Signature (sealed)

```c
// 5 stack args; plain RET; void
void GuardedVector_RingFillFromPtr(
    GuardedVectorHeader* start_c, uint32_t start_i,
    GuardedVectorHeader* end_c,   uint32_t end_i,
    const uint32_t* fill);
```

| Slot | Source | Conf |
|---|---|---|
| start_c / start_i | Stack[+4]/[+8] | **High** |
| end_c / end_i | Stack[+0xc]/[+0x10] | **High** |
| fill* | Stack[+0x14] → EBX | **High** |
| cleanup | plain `RET` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
while start_c != end_c || start_i != end_i:
  map page from start_i on start_c; if dest != fill: *dest = *fill; start_i++
RET
```

| Stage | Match | Conf |
|---|---|---|
| Forward half-open walk | **Yes** | **High** |
| capacity wrap on block index | **Yes** | **High** |
| stack fill* + self-alias skip | **Yes** | **High** |
| Leaf (no calls) | **Yes** | **High** |
| Not EBX-fill twin (`0043cef0`) | **Yes** (bytes) | **High** |

---

## 5. Machine bytes (`read_memory`)

Full **84 B** hex sealed in raw. Entry `53 8B 5C 24 18` (fill*→EBX). Epilogue `5F 5E 5D 5B C3`.

---

## 6. Gaps

- Product/PDB class English (`GuardedVector_*` structural).  
- Runtime / bit-exact.

---

## 7. Verdict

Fidelity seals ABI, forward fill CF, map math, and self-alias skip. Closes W32-F InsertN_Thiscall nested fill residual → **accept**.
