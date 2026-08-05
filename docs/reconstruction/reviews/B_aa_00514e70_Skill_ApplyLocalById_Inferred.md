# Review B (skeptical / adversarial): `aa_00514e70` Skill_ApplyLocalById_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00514e70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00514e70_Skill_ApplyLocalById_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as `Skill_ApplyStatusEffectLocal` | No status buffer / opcode 0x2031; single id + host re-apply | **Falsified** merge |
| 2 | Always queues HB | Immediate `005538a0` when type short ≤0 or no world HB list | **Survives** dual path |
| 3 | `param_1` is the skill object | vtbl lookup *on* param_1; TFID/world from param_1 → **host** | **Falsified** (host this) |
| 4 | Refresh dual’s `FUN_00514e70(id)` is freestanding | thiscall host in ECX; decomp drops ECX on same-this callers | **Survives** as thiscall |
| 5 | Sibling clear uses flag 1 | Live push 0; only `0052db50` uses flag 1 | **Falsified** |
| 6 | Applies to arbitrary target TFID | Companion pack is **invalid** TFID; self identity only | **Survives** self/local |

---

## 2. Live ≡ raw

Live matches raw CF: lookup → `+0x615&1` → SiblingCastClear → identity/invalid packs → HB (`006061e0`+enqueue+start) vs `Skill_ApplyEffectsOnTarget_Inferred`. Callers: refresh `00516a00`, hash re-apply `00523e60`, rank path `0052dc20`, bag path `005304a0`.

---

## 3. Surviving contract

```
// thiscall host, skillId:
// skill = host.vtbl[+0x234](skillId)
// if skill && (skill[+0x615] & 1):
//   SiblingCastClear(host, skillId, host.tfid@+0x160, flag=0)
//   if skill[+0x14] > 0 && world.hbList:
//     Start(Enqueue(new SkillHB(...)))
//   else if world:
//     ApplyEffectsOnTarget(skill, host, world, host.tfid, invalid, 0)
```

**Gaps kept:** product names for lookup/`+0x14`; full `006061e0` dual; runtime.

**Verdict:** **accept-with-gaps**.
