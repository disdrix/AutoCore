# Review B (skeptical / adversarial): `aa_0056b400` Weapon_SetSuppressFlag_Cb_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056b400` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0056b400_Weapon_SetSuppressFlag_Cb_Inferred.md` |
| **Verdict** | **accept-with-gaps** on +0xCB store + branch; **reject** equating this to fire-flag pair, inventing +0xD8 product name, or claiming TacArc always runs |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Same as `Weapon_SetFireFlagPair` (+0xC7) | Different offset +0xCB; different side effects | **Falsified** |
| 2 | Always updates TacArc mesh | Only when clearing (0) **and** +0xC0 non-null | **Falsified** |
| 3 | +0xD8 zeroed on clear too | Only non-zero path zeros +0xD8 | **Falsified** |
| 4 | Vehicle thiscall | Callers pass weapon ECX from hardpoint table | **Falsified vehicle this** |
| 5 | Retail “suppress” sealed | Name inferred from fire-block residual | **Hold `_Inferred`** |
| 6 | Bit-exact complete | +0xD8 meaning open | **Fail** complete |

---

## 2. Surviving contract

```
weapon+0xCB is a separate suppress/busy flag from +0xC7 fire pair.
Set (non-zero): clear float +0xD8.
Clear (0): optionally refresh TacArc mesh at +0xC0.
ActivateEnterWorld clears both +0xCB and +0xC7 on all hardpoints.
```

**Verdict:** **accept-with-gaps**
