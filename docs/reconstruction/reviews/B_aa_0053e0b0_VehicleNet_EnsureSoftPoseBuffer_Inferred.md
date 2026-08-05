# Review B (skeptical / adversarial): `aa_0053e0b0` VehicleNet_EnsureSoftPoseBuffer_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053e0b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053e0b0_VehicleNet_EnsureSoftPoseBuffer_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Always returns linVel @ +0x20 | Returns **base** of 0x40 buffer | **Falsified offset** |
| 2 | Fills from physics body | No body read | **Falsified** |
| 3 | Entity-only | Any object with +0x28 soft slot | **Broad this** |
| 4 | Complex cache invalidation | Null-check only | **Falsified** |

---

## 2. Surviving contract

```
buf = EnsureSoftPoseBuffer(obj):
  if obj.softBuf(+0x28) == null: softBuf = Alloc0x40()
  return softBuf
```

**Verdict:** **accept**
