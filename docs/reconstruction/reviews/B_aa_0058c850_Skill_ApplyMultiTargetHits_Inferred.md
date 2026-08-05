# Review B (skeptical / adversarial): `aa_0058c850` Skill_ApplyMultiTargetHits_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058c850` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-Q) |
| **Counterpart** | `reviews/A_aa_0058c850_Skill_ApplyMultiTargetHits_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is only a debug helper for `VOG_DEBUG_STOP` | **Falsified** — 3 callers; `0061c090` multi-hit skill arm is production path |
| 2 | Accuracy runs on every target including first | **Falsified** — `local_c4 < 1` short-circuits AccuracyHitCheck |
| 3 | Function gathers targets from world | **Falsified** — consumes prebuilt TFID list; no `Skill_GatherTargetsInArea` |
| 4 | Returns bool success only | **Falsified** — returns accumulated `local_bc` damage sum |
| 5 | param_4 is a required damage scale | **Falsified** — unused in body (still stack-passed) |
| 6 | Parent-seed name `Named_CalleeOf_VOG_DEBUG_STOP` is complete | **Falsified as sole role** — wrapper + multi-hit callers |
| 7 | Clean invents gather modes / UI | **Falsified** — clean stays on list→hit→floater CF |
| 8 | Always applies hit without scale | **Falsified** — `FUN_004cf080` + `g_flOne` gate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Multi-target apply (not gather) | **High** | Wrong combat pipeline stage |
| Skip-first accuracy | **High** | Wrong multi-target balance |
| Damage sum return | **High** | Callers (`0061c090` nonzero test) mis-ported |
| param_4 dead | **High** | Fake ABI dependency |
| Product name | Low | Cosmetic only |
| List helper class | Medium | Port uses wrong concurrent list |

---

## 3. Cross-check against raw + bytes

```
SEH → null list? → CS list → TFID walk resolve/push
  → foreach object:
       (idx0 | AccuracyHitCheck(rollTable[(i%600)])) ?
         damage(min/max / vtbl+0x4c) → scale → ApplySingleHit → sum
       : floater miss
       i_roll += 6
  → teardown → return sum
```

Entry SEH + `sub esp,0xbc` and exit `add esp,0xc8; ret` match large stack frame; no `ret N`.

Sibling Accuracy dual cites this VA at `0x0058c9ac` — consistent.

---

## 4. Surviving contract for AutoCore

```csharp
// Port sketch — Skill_ApplyMultiTargetHits_Inferred
int ApplyMultiTargetHits(
    SkillHost skill,
    IReadOnlyList<Tfid> targets,
    DamageSource dmg,
    ushort[] rollTable,
    int rollSeed)
{
    // 1) resolve targets to objects
    // 2) for i, target in enumerate(objects):
    //      if i > 0 && !AccuracyHitCheck(skill, attacker, target, rollTable[(rollSeed*6 + i*6) % 600]):
    //          EnqueueMissFloater(...); continue;
    //      damage = RollOrMethod(dmg, roll);
    //      damage = ApplyScale(skill, target, roll, damage);
    //      ApplySingleHitMaybeDefer(...);
    //      total += damage;
    // 3) return total;
}
```

Do **not** re-implement world gather here; parents supply the list. Do **not** accuracy-check target index 0.

---

## 5. Open questions

1. Why first target skips accuracy (design vs bug) — CF sealed; product reason open.
2. Whether `param_1` is always skill object for Accuracy thiscall in all three callers.
3. Exact modular damage packing of min/max shorts.

**Verdict:** **accept-with-gaps**
