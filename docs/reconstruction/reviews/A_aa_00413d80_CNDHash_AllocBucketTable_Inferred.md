# Review A (reconstruction fidelity): `aa_00413d80` CNDHash_AllocBucketTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00413d80` |
| **VA** | `0x00413d80` |
| **Canonical name** | `CNDHash_AllocBucketTable_Inferred` |
| **Ghidra** | `FUN_00413d80` |
| **Review date** | `2026-07-29` (OWN-ONLY dual — rebuild nested) |
| **Counterpart** | `reviews/B_aa_00413d80_CNDHash_AllocBucketTable_Inferred.md` |
| **System** | container / CNDHash |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Allocate a fresh bucket table for hash in **ESI**, using provisional count at `hash+8`:

```text
// ESI = hash*
// Requires: 0 < *(char*)(hash+0x1c) < 0x11   // log2 in 1..16

n = *(hash+8)                                 // bucket COUNT (power of two from Recreate)
table = operator_new[](n * 4)                 // pointer array
*(hash+0x10) = table
slab = malloc(n * 0xc)                        // contiguous bucket sentinels
for i in 0..n-1:
  table[i] = slab + i*0xc
  *bucket = &PTR_LAB_00a64760                 // sentinel vtbl
  bucket[1] = 0                               // head
  bucket[2] = 0
*(hash+8) = n - 1                             // COUNT → MASK for keyLo & mask
```

If log2 out of range: log `"VOG_DEBUG_STOP"` then throw **`0x80004003`** (`E_POINTER`).

**Callers:** `CNDHash_Recreate` (`004138d0`), `FUN_004137d0` (ctor path).

---

## 2. ABI

| Slot | Role |
|------|------|
| **ESI** | hash* |
| return | void (or noreturn throw) |

---

## 3. Confidence

| Claim | Conf |
|---|---|
| Dual allocation ptr-array + 0xc slab | **High** |
| Post-condition mask = count−1 | **High** (critical for Insert) |
| log2 gate 1..16 | **High** |
| Sentinel vtbl `00a64760` ≠ node `00a64758` | **High** |
| Product name | **Inferred** |

**Verdict:** **accept-with-gaps**
