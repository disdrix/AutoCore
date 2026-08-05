# Review B (skeptical / adversarial): `aa_0053e020` VehicleNet_SoftPoseBufferAlloc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053e020` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053e020_VehicleNet_SoftPoseBufferAlloc_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Applies network pose | Body is only `operator_new` + zero/init | **Falsified** |
| 2 | Heap size unknown | Immediate `0x40` | **Falsified** |
| 3 | Identity at rot.xyz | Only **w** set to 1; xyz zero | **Correct as A** |
| 4 | Returns void | Callers assign return (decomp type weak) | **Accept with type residual** |
| 5 | Physics body alloc | No Havok / entity linkage here | **Falsified** |

---

## 2. Surviving contract

```
softBuf = SoftPoseBufferAlloc():
  0x40 zeroed; rot.w = 1
  layout: pos|rot|linVel|angVel (4×float each)
```

**Verdict:** **accept**
