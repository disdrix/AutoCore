# Review B (skeptical / adversarial): `aa_00516a00` Object_RefreshActiveSkillEffects_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00516a00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00516a00_Object_RefreshActiveSkillEffects_Inferred.md` |
| **Verdict** | **accept-with-gaps** on dual-collection refresh CF; **reject** product names for type ids / +0x5f6 / 00514e70, and claims this casts new skills from loadout |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Casts brand-new skills from catalog | Only iterates existing skill instances + calls `00514e70` with id@+0x5fc | **Overclaim** — refresh of actives, not loadout equip cast |
| 2 | Single skill list only | Two passes: hash `this[0x1c]` + vfunc `+0x1DC` array | **Falsified narrow** |
| 3 | Always processes all actives | `param_2==0` requires `+0x5f6 > 0` | **Falsified** |
| 4 | Early-out type list is complete product taxonomy | Only machine case set sealed | **Hold** product mapping open |
| 5 | Vehicle-only | Many creature/activate callers | **Falsified** |
| 6 | Traversal lock optional debug | Errors log + continue path still sets lock | **Seal: lock is real**; log is defensive |
| 7 | Retail name sealed | `_Inferred` only | **Hold** |

---

## 2. Surviving contract

```
On enter-world / post-create refresh:
  skip excluded clonebase types;
  walk locked skill hash + secondary skill array;
  for each active bit skill (optionally rank>0): re-apply FUN_00514e70(skillId).

Do NOT treat as full skill-cast pipeline or inventory equip.
```

**Verdict:** **accept-with-gaps**
