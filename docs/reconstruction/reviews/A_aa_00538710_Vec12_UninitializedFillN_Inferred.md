# Review A (reconstruction fidelity): `aa_00538710` Vec12_UninitializedFillN_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538710` |
| **VA** | `0x00538710` |
| **Canonical name** | `Vec12_UninitializedFillN_Inferred` (was `FUN_00538710`) |
| **Ghidra symbol** | `FUN_00538710` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — nested residual of PackUpdate skills path) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00538710_Vec12_UninitializedFillN_Inferred.md` |
| **System** | util / 12-byte POD vector helpers (VehicleNet skills collector + peers) |
| **VehicleNet parent** | `FUN_005b3110` fast path; also `FUN_005b2df0` / `FUN_00539e90` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Place-construct `N` copies of a 12-byte (3×`uint32`) value** at an uninitialized destination range.

Live body:

```c
void Vec12_UninitializedFillN(uint32_t *dst, int count, const uint32_t *src) {
  for (; count != 0; --count) {
    if (dst != NULL) {
      dst[0] = src[0];
      dst[1] = src[1];
      dst[2] = src[2];
    }
    dst += 3;  // +0xC bytes
  }
}
```

**VehicleNet use:** PackOwnerSkillsHB collector push when vector has room — construct one 0xC record at `end` then advance (parent `end += 0xC`).

**Also called by:** multiple vector/list helpers (`005b2df0`, `00539e90`, `00539ef0`, phys helpers, …) — shared POD fill, not skills-exclusive.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x00538710` |
| Callers | `get_function_callers` includes `005b3110`, `005b2df0`, … |
| Parent dual | `A_aa_005b3110_VehicleNet_SkillsHBNodeVector_Push_Inferred.md` |

---

## 3. Confidence

| Claim | Confidence |
|---|---|
| Exactly 3 dword copy per element | **High** |
| Null `dst` skips store but still advances | **High CF** |
| No allocation / no stream | **High** |
| Skills-only | **Falsified** (shared) |

**Verdict:** **accept-with-gaps**
