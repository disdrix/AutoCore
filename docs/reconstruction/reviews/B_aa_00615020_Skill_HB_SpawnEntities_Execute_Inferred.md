# Review B (skeptical / adversarial): `aa_00615020` Skill_HB_SpawnEntities_Execute_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00615020` |
| **Review type** | Skeptical / adversarial (Path B) |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00615020_Skill_HB_SpawnEntities_Execute_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF; reject overclaims from string plate name / void-this / template-local typing |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Name is literally `Skill_Skill_d_had_invalid_creature_d` | **Rejected as product name** — log format string only; keep as alias evidence |
| 2 | Free function / no `this` | **Falsified** — prologue saves ECX; `ret 0x18`; vtbl slot |
| 3 | Always returns success boolean | **Falsified** — returns count, or 0 error, or 1 gate-fail (1 is **not** success) |
| 4 | Gate-fail `return 1` means one spawn succeeded | **Falsified** — early path before loop; opposite of success count |
| 5 | Template path decompiler pointer math is bit-exact truth | **Untrusted** — `local_12c` float/pointer reuse; do not port polluted lines without re-type |
| 6 | `local_94` is an independent object | **Artifact** — almost certainly `this` / saved ECX; virtual at `+0x1c` |
| 7 | Cull path always runs | **Falsified** — gated on `skill+0x16c == 100.0f` and caster vtbl+0x210 |
| 8 | Isotropic disk uses degrees | **Falsified** — ushort × ~1/32768 − 1 × 10 → ~[-10,10] world units |
| 9 | Full clean cpp is line-complete port | **Overclaim risk** — stage plate + raw body; scaffold `FUN_00615020.cpp` is expanded but untyped |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Spawn pipeline order | **High** | Wrong server skill simulate |
| Return code meanings | **High** | Callers mis-handle gate vs count |
| Float constants | **High** | Wrong scatter radius / yaw |
| HB Enqueue list `map+0xe4ec` | **High** | HB never ticks |
| Template-branch field stores | **Medium** | Need re-decompile/retype |
| Product class name | **Low** | Docs only |

---

## 3. Cross-check: return codes

```
if !map.active(+0x7e) or !RTTI creature: return 1   // FAIL gate
...
if creature factory null: log; return 0
if template factory null: log; return 0
...
return spawnSuccessCount   // local_d8, may be 0 if all virtual gates skip
```

**Do not** treat return `1` as boolean true-success.

---

## 4. Surviving contract for AutoCore

```
Skill_HB_SpawnEntities_Execute(this, caster, skill, map, a4, a5, a6):
  require map flag +0x7e and caster is CVOGCreature else return 1
  sample pose from mount(+0x250) or self
  for i in 0 .. max(1, skill.spawnCount@+0xde)-1:
    if this.virtual(+0x1c)(caster, skill) != 0: continue
    compute world pos (disk or directed); terrain Y(+50 probe)
    orient by mode skill@+0x168
    spawn creature (skill@+0x22==0) or template
    arm HB 0x6d0 via FUN_00614dc0; Enqueue(map+0xe4ec); Start
    maybe cull if skill@+0x16c == 100
  return successCount
```

Port notes:

- Keep Enqueue **then** Start (same as other skill HBs).
- Do not invent product name without RTTI/string class evidence.
- Re-type template branch before trusting float→pointer stores in decompiler text.

---

## 5. Open questions (narrow)

1. English class behind `PTR_FUN_009d0ec4`.
2. Virtual `+0x1c` predicate semantics.
3. Whether server mirrors this client execute path.
4. Live multi-spawn count vs skill+0xde.

**Verdict:** **accept-with-gaps** — ABI/pipeline/constants sealed; naming + template typing residual.
