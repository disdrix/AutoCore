# Review A (reconstruction fidelity): `aa_0057fb80` Vec12_CopyRange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0057fb80` |
| **VA** | `0x0057fb80` |
| **Canonical name** | `Vec12_CopyRange_Inferred` (was `FUN_0057fb80`) |
| **Ghidra symbol** | `FUN_0057fb80` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — nested residual of PackUpdate skills vector grow) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0057fb80_Vec12_CopyRange_Inferred.md` |
| **System** | util / 12-byte POD vector helpers |
| **Parent (VehicleNet)** | `FUN_005b2df0` realloc path (prefix + suffix moves) |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Copy half-open range of 12-byte elements** `[first, last)` into destination, advancing both by 3 dwords per step.

```c
void Vec12_CopyRange(uint32_t *first, uint32_t *last, uint32_t *dst) {
  for (; first != last; first += 3) {
    if (dst != NULL) {
      dst[0] = first[0];
      dst[1] = first[1];
      dst[2] = first[2];
    }
    dst += 3;
  }
}
```

Contrast:

| Helper | Behavior |
|---|---|
| `00538710` | fill **N** copies of **one** source triple |
| `0057fb80` | copy **range** of distinct triples |
| `00537860` | assign-fill range from one source (overwrite initialized) |

Used twice on realloc path in `005b2df0` (before/after insert window).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x0057fb80` |
| Parent | live `005b2df0` |

---

## 3. Confidence

| Claim | Confidence |
|---|---|
| Range copy stride 0xC | **High** |
| Null dst skips stores | **High CF** |
| No size arithmetic (iterator compare) | **High** |

**Verdict:** **accept-with-gaps**
