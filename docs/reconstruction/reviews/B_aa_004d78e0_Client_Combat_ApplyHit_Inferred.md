# Review B (skeptical / adversarial): `aa_004d78e0` Client_Combat_ApplyHit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d78e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004d78e0_Client_Combat_ApplyHit_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Pure floater UI with no pool writes | Non-zero path calls `vtbl+0x44` / shield | **Falsified** as UI-only |
| 2 | Always applies damage | `param_3==0` skips pool mutate | **Survives** zero branch |
| 3 | Always enqueues floater | Mask/`param_10`/`param_6`/host gates | **Survives** as gated |
| 4 | Same as multi-target `004da2e0` | That loops + optional `004e1600`; this is one hit | **Falsified** merge |
| 5 | Always impulses target | Type `==3` + flags + phys component required | **Survives** as gated |
| 6 | `param_7` means "critical" | When set, **skips** shield sync path | **Falsified** as crit — closer to skip-shield |

---

## 2. Live ≡ raw

Live full body matches raw `aa_004d78e0`: zero branch, pool vtbls, `Vehicle_SetCurrentShield`, `Client_EnqueueCombatFloater_INFERRED`, reaction notify, type-3 impulse via `FUN_0058c3b0`.

---

## 3. Surviving contract

```
// this = combat host (flag @ +0x7E)
// if damage==0:
//   gated floater-only (transforms + optional meta) → return
// else:
//   read pool; apply or clamp by host flag; optional shield sync
//   gated floater with damage/delta
//   optional reaction notify
//   optional type-3 phys impulse
// return status byte
```

**Gaps kept:** vtbl product names; return-byte semantics; hit-meta schema.

**Verdict:** **accept-with-gaps**.
