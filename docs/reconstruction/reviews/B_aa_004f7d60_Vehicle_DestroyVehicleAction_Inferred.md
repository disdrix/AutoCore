# Review B (skeptical / adversarial): `aa_004f7d60` Vehicle_DestroyVehicleAction_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f7d60` |
| **VA** | `0x004f7d60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004f7d60_Vehicle_DestroyVehicleAction_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Soft no-op always | **Falsified** | deletes holder when present |
| 2 | Only nulls pointer without releasing COMs | **Falsified** | refcount −1 / destroy on action, framework, mode helper |
| 3 | Releases all three holder slots | **Falsified** | body never touches holder+8 (driver input) |
| 4 | Mode helper lives on entity root | **Falsified** | clears `*(entity+8)+0x54` (physics object) |
| 5 | Allocates a new action | **Falsified** | teardown only; inverse of createVehicleAction |
| 6 | Only called from createVehicleAction | **Falsified** | also `FUN_004f8fe0`, `FUN_005004f0` |

---

## 2. Surviving contract

```
DestroyVehicleAction(entity):
  if !entity.actionHolder: return
  Release(phys.modeHelper@+0x54); phys.modeHelper = null
  if holder.action: Unregister(action); Release(action)
  Release(holder.framework)
  delete holder; entity.actionHolder = null
```

**Verdict:** **accept-with-gaps**
