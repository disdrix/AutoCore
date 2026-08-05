# Review A (reconstruction fidelity): `aa_00539e90` Vec12_UninitializedFillN_ReturnEnd_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00539e90` |
| **VA** | `0x00539e90` |
| **Canonical name** | `Vec12_UninitializedFillN_ReturnEnd_Inferred` (was `FUN_00539e90`) |
| **Ghidra symbol** | `FUN_00539e90` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — nested residual of PackUpdate skills vector grow) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00539e90_Vec12_UninitializedFillN_ReturnEnd_Inferred.md` |
| **System** | util / 12-byte POD vector helpers |
| **Parent (VehicleNet)** | in-place branch of `FUN_005b2df0` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Thin wrapper** over `FUN_00538710`: fill `N` copies of a 12-byte value starting at `dst`, then **return** `dst + N*0xC` (new end pointer).

```c
// decomp thiscall noise; body is free-func shaped
void *Vec12_UninitializedFillN_ReturnEnd(void *dst, int count, const void *src) {
  FUN_00538710(dst, count, src);
  return (char *)dst + count * 0xC;
}
```

Live:

```
FUN_00538710(param_2, param_3, param_4, ...);
return param_2 + param_3 * 0xc;
```

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x00539e90` |
| Callee dual | `A_aa_00538710_*` (this batch) |
| Parent | live `005b2df0` |

---

## 3. Confidence

| Claim | Confidence |
|---|---|
| Sole logic = fill-N + end arithmetic | **High** |
| Multiplier **0xC** | **High** |
| No independent domain behavior | **High** |

**Verdict:** **accept-with-gaps**
