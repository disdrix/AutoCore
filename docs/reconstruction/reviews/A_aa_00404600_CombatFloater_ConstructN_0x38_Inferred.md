# Review A (reconstruction fidelity): `aa_00404600` CombatFloater_ConstructN_0x38_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404600` |
| **VA** | `0x00404600` |
| **Canonical name** | `CombatFloater_ConstructN_0x38_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00404600_CombatFloater_ConstructN_0x38_Inferred.md` |
| **System** | `missions-progression` / combat floater UI |
| **Verdict** | **accept** |

---

## 1. Purpose

Fast-path bulk construct for combat-floater POD elements: loop `count` times, `CombatFloater_PodCopyElement_0x38(dst, src)`, advance `dst` by **0x38** each iteration. Parent enqueue calls with `count=1` when capacity remains.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Ghidra decompile | `0x00404600` |
| Raw | `docs/reconstruction/raw/aa_00404600_FUN_00404600.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00404600.cpp` |
| Parent | `Client_EnqueueCombatFloater_INFERRED` dual |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Loop count times | **High** | `for (; count; count--)` |
| Stride **0x38** after each pod copy | **High** | `dst += 0x38` |
| Body = only `FUN_004046f0` | **High** | Single callee |
| SEH frame present | **High** | ExceptionList setup |
| No award / no network | **High** | Pure construct |

---

## 4. Control flow

```
ConstructN(dst, count, srcPayload):
  while count--:
    PodCopy0x38(dst, srcPayload)
    dst += 0x38
```

---

## 5. Gaps

1. Whether `src` is full 0x38 blob or thinner payload widened by pod copy (copy always 14 dwords).

**Verdict:** **accept**
