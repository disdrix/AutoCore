# Review B (skeptical / adversarial): `aa_004b6980` NDSpecialFX_FlushStagedMultiHits_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b6980` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004b6980_NDSpecialFX_FlushStagedMultiHits_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Stages targets into buffer | Only reads + frees `+0x3C`; stage is `004b67d0` | **Falsified** as stage |
| 2 | Always calls multi-hit | Null `+0x3C` skips entirely | **Survives** as gated |
| 3 | Same as `004da2e0` | Thin wrapper; no walk | **Falsified** merge |
| 4 | Leaves staged buffer allocated | Free + zero | **Falsified** leak claim |
| 5 | `operator_delete` kills process | Known noreturn artifact | **Survives** as noise |

---

## 2. Live ≡ raw

Live matches raw. Confirmed sole multi-hit consumer pattern from parent dual notes; callers are FX paths.

---

## 3. Surviving contract

```
// if fx[+0x3C]==0: return
// ApplyMultiTargetHits(entries, count, ResolveTFID(fx+0x48), flags/masks...)
// delete entries; fx[+0x3C]=0
```

**Gaps kept:** product FX class name.

**Verdict:** **accept-with-gaps**.
