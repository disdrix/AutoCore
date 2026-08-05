# Review A (reconstruction fidelity): `aa_00537860` Vec12_AssignFillRange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537860` |
| **VA** | `0x00537860` |
| **Canonical name** | `Vec12_AssignFillRange_Inferred` (was `FUN_00537860`) |
| **Ghidra symbol** | `FUN_00537860` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — nested residual of PackUpdate skills vector grow) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00537860_Vec12_AssignFillRange_Inferred.md` |
| **System** | util / 12-byte POD vector helpers |
| **Parent (VehicleNet)** | in-place branch of `FUN_005b2df0` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Assign-fill** half-open range `[first, last)` with copies of one 12-byte source (overwrites existing slots; no null-dst guard).

```c
void Vec12_AssignFillRange(uint32_t *first, uint32_t *last, const uint32_t *src) {
  for (; first != last; first += 3) {
    first[0] = src[0];
    first[1] = src[1];
    first[2] = src[2];
  }
}
```

Used by `005b2df0` after shifting tail elements during in-place insert so the insert window holds the new value.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x00537860` |
| Parent | live `005b2df0` |

---

## 3. Confidence

| Claim | Confidence |
|---|---|
| Fill range from one triple | **High** |
| No null check (unlike `00538710` / `0057fb80`) | **High** |
| Stride 0xC | **High** |

**Verdict:** **accept-with-gaps**
