# Review B (skeptical / adversarial): `aa_0056bab0` WeaponFx_OnHitApplyOrStage_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056bab0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0056bab0_WeaponFx_OnHitApplyOrStage_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always multi-hit applies | Flag `+0xc` stages instead; also early FX-only arms | **Survives** as dual path |
| 2 | Same as `004da2e0` | FX catalog + optional stage wrapper | **Falsified** merge |
| 3 | Applies when `param_2 == param_3` | Explicit skip of stage/apply when equal | **Survives** gate |
| 4 | Kill XP / death path | No OnDeath callees | **Falsified** |
| 5 | Catalog ids fully named | Only numeric `004ec010` args | **Survives** as gap |

---

## 2. Live ≡ raw

Live matches catalog branches and terminal stage vs `004da2e0`. Sole caller `00812a60`. Multi-hit dual lists this as a primary caller.

---

## 3. Surviving contract

```
// play optional FX catalog entries by mode
// if obj_a != obj_b:
//   root = obj_a.master || obj_a
//   if fxNode[+0xc]: StageTargets(hit_pack, 1, root+0x160)
//   else: ApplyMultiTargetHits(hit_pack, 1, root, ...)
```

**Gaps kept:** product catalog names; caller packet; siblings `0056c860`/`0056e000`.

**Verdict:** **accept-with-gaps**.
