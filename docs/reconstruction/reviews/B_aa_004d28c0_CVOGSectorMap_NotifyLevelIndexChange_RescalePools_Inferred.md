# Review B (skeptical / adversarial): `aa_004d28c0` CVOGSectorMap_NotifyLevelIndexChange_RescalePools_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d28c0` |
| **VA** | `0x004d28c0` |
| **Canonical name** | `CVOGSectorMap_NotifyLevelIndexChange_RescalePools_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004d28c0_CVOGSectorMap_NotifyLevelIndexChange_RescalePools_Inferred.md` |
| **System** | sector-map / combat-pool |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Rescales all sector objects always | Heavy gates; empty list no-ops | **Falsified** always |
| 2 | Levels unbounded | Clamp to 0xF; require one side `< 0x10` | **Falsified** unbounded |
| 3 | Directly mutates pool floats | Only calls `004cf3b0` | **Falsified** direct mutator |
| 4 | `this == -0xA0` is magic error code | Subobject null-outer idiom | **Agree** not magic pool id |
| 5 | Multiple unrelated callers | Only `004d32c0` / `004d3310` | **Agree** |
| 6 | Same as Vehicle_RecalcCombatPools | Recalc is `00501f60`; this is fan-out notify | **Falsified** identity |
| 7 | Changes `+0xe818` itself | Only reads old/new from caller | **Falsified** index writer |

---

## 2. Live ≡ raw

```
Live decompile ≡ raw:
  5 gates → clamp → lock → for each obj ScalePools(old,new) → unlock
```

Parent dual of `004cf3b0` already lists this as level-transition owner.

---

## 3. Surviving contract

```
// thiscall(SectorMap*, oldLevel, newLevel)
// If allowed: clamp levels to [0,15], rescale combat pools on +0xe4e8 vector.
```

**Verdict:** **accept-with-gaps.**
