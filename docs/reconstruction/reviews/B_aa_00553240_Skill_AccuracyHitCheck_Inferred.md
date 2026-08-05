# Review B (skeptical / adversarial): `aa_00553240` Skill_AccuracyHitCheck_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553240` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00553240_Skill_AccuracyHitCheck_Inferred.md` |
| **Verdict** | **accept** on role/ABI/CF; **accept-with-gaps** on product name + score-helper internals |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | `this` is caster entity (entity+0x24) | **Falsified** — assembly both sites `MOV ECX, skill` (`ESI` ApplyEffects / `EDI` 0058c850); stack carries attacker separately |
| 2 | Name is product-original | **Holds as false** — no string/RTTI; `_Inferred` required |
| 3 | Server damage / hit authority | **Falsified** — pure local bool; parents enqueue floater / skip apply |
| 4 | Hit when `score <= threshold` | **Falsified** — that path returns **0** (miss); hit is `score > threshold` or sentinel |
| 5 | `roll / 100` participates in hit chance | **Falsified** — only `roll % 100`; `/100` unused for compare |
| 6 | Always requires non-null out-flag | **Falsified** — ApplyEffects pushes **0**; null-checked |
| 7 | Always rolls even when accuracy is -1 | **Falsified** — early return 1 without `FUN_005531d0` |
| 8 | Same object as `FUN_00553dd0` (+0x24 time math) | **Falsified for identity** — 00553dd0 is a different unit; shared sentinel only is coincidental until proven |
| 9 | Sole caller is ApplyEffects | **Falsified** — second xref `FUN_0058c850` multi-target path |
| 10 | Scaffold name `Named_CalleeOf_…RecvSkillStatusEffect` is role | **Falsified as role** — accuracy hit-check, not Recv helper |
| 11 | Threshold uses full ushort as percent 0–655.35 | **Falsified** — `% 100` then `* 0.01` → 0.00–0.99 |
| 12 | Decompiler `param_3` is roll | **Partial hazard** — sealed by assembly: stack is attacker, target, roll, out; decompiler param index can confuse 531d0 args but 53240 decision uses `param_4` as roll correctly vs body |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Skill thiscall ABI | **Confirmed** (asm) | Mis-bind accuracy to entity |
| Sentinel -1.0 auto-hit | **Confirmed** | Wrong always-hit skills |
| Threshold formula | **Confirmed** | Wrong miss rate ports |
| Return polarity hit=1 miss=0 | **Confirmed** | Invert combat outcomes |
| Score math (cebao) | Partial (callee) | Port uses stub score |
| Product name | Inferred | Cosmetic |
| 0058c850 first-target skip | **High** (parent CF) | Over-apply accuracy on shot 1 |

---

## 3. Surviving contract

```
Skill_AccuracyHitCheck(skill, attacker, target, roll, outMiss?) -> 0|1
  acc = skill.f32[+0x24]
  clear debugBuf[0x400]
  if acc == -1.0f: return 1
  score = ScoreVia_005531d0(skill, attacker, target, &debugBuf)
  thr = (roll % 100) * 0.01f
  if score <= thr:
    if outMiss: *outMiss = 1
    return 0
  return 1
```

Parents:

- ApplyEffects: gate `skill+0x624&1`; seed slice → roll; out=null; miss → combat floater + fail path.
- FUN_0058c850: per-target after first; out local; miss → floater, skip damage for that target.

---

## 4. Residual uncertainty

| # | Item | Blocks rename seal? |
|---|---|---|
| R1 | Product name | No (`_Inferred`) |
| R2 | Full `FUN_004ceba0` / `FUN_005531d0` score formula | No for this unit’s gate |
| R3 | `FUN_0058c850` product name / table | No |
| R4 | Whether score is always clamped to [0,1] | No (compare still holds) |
| R5 | Runtime / bit-exact | No |

---

## 5. Concrete checks (2026-07-29)

1. Re-decompile `0x00553240` — CF: sentinel, score, `<=` miss, returns 0/1.
2. `get_function_xrefs` → `00553982`, `0058c9ac` only.
3. `get_assembly_context` both sites — ECX=skill; four stack args attacker/target/roll/out.
4. `read_memory` `0x00aaa668` → `-1.0f`; `0x00a0f718` → `0.01f`.
5. ApplyEffects parent: accuracy gated by `skill+0x624&1`; out=0.
6. Callee-only `FUN_005531d0` → `FUN_004ceba0` with AutoHit strings.
7. No product string on this VA.

---

## 6. Verdict

**accept** — role sealed as skill accuracy hit/miss check; name **`Skill_AccuracyHitCheck_Inferred`**.

Do **not** over-claim score-stat composition, server authority, or product spelling.
