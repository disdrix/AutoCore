# Review B (skeptical / adversarial): `aa_005531d0` Skill_AccuracyScore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005531d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005531d0_Skill_AccuracyScore_Inferred.md` |
| **Verdict** | **accept** on role/ABI/CF/pack; **accept-with-gaps** on product name + cebao product + second-site identity |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function returns `void` (decompiler) | **Falsified** — no store of ST0 before `RET`; parent `FCOMIP` / second site `FMUL` on score; completeness tool warns on void |
| 2 | `this` is attacker entity | **Falsified** — `MOV EDI,ECX` then load `skill+0x24`; parent AccuracyHitCheck passes skill in ECX |
| 3 | This unit performs hit/miss roll | **Falsified** — no roll/%/threshold; pure score forward |
| 4 | Always reads attacker stats | **Falsified** — null attacker or null vtbl+0x214 → bonus stays 0.0 |
| 5 | Second float to cebao is skill accuracy | **Falsified** — asm `PUSH 0` then skill acc as **third** float |
| 6 | Only one caller (AccuracyHitCheck) | **Falsified for xrefs** — second `0082731b`; true for **named** function callers |
| 7 | Scaffold RecvSkillStatusEffect naming is role | **Falsified as role** — accuracy score wrapper |
| 8 | `004c4140` returns float already | **Falsified** — `MOVSX`/`CVTSI2SS` after call; callee returns short/int in AX |
| 9 | Name is product-original | **Holds as false** — no string/RTTI; `_Inferred` required |
| 10 | Wrapper invents AutoHit logic | **Falsified** — AutoHit strings live in `004ceba0` only |
| 11 | `skill+0x24` only used in parent, not here | **Falsified** — this unit always pushes `*(skill+0x24)` into cebao |
| 12 | cdecl / no stack cleanup | **Falsified** — `RET 0xC` thiscall; only cebao is cdecl (`ADD ESP,0x18`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Skill thiscall ABI | **Confirmed** (asm) | Mis-bind accuracy to entity |
| Float ST0 return | **Confirmed** | Port drops score |
| Bonus null gates | **Confirmed** | Wrong default accuracy contrib |
| cebao 6-arg pack order | **Confirmed** | Swap skillAcc / zeros |
| `004c4140` clamp formula | **High** (sibling body) | Wrong short→bonus map |
| cebao internal score | Partial (callee dual) | Port stubs wrong hit curve |
| Product name | Inferred | Cosmetic |
| `0082731b` product role | Partial (asm only) | Mis-attribute UI path |

---

## 3. Surviving contract

```
Skill_AccuracyScore(skill, attacker, target, debugOut) -> float
  bonus = 0.0f
  if attacker and attacker.vtbl[+0x214]():
      bonus = (float) clamp_short_stats(creature)   // 004c4140 → [1,250]
  return Skill_NonCreatureCastAutoHit(
      bonus, 0.0f, skill.f32[+0x24], attacker, target, debugOut)
```

Parents / consumers:

- `Skill_AccuracyHitCheck_Inferred`: miss if `score <= (roll%100)*0.01f` (after -1 auto-hit skip).
- `0x0082731b`: uses score × **100.0f** then integerize (tooltip/UI-style path; envelope unnamed).

---

## 4. Residual uncertainty

| # | Item | Blocks rename seal? |
|---|---|---|
| R1 | Product name | No (`_Inferred`) |
| R2 | Full `004ceba0` formula / entity+0x260 | No for **this** wrapper |
| R3 | Does cebao use third float? | No for pack seal; yes for **semantic** of skillAcc path |
| R4 | +0x140/+0x148 English | No |
| R5 | Function owning `0082731b` | No |
| R6 | Runtime / bit-exact | No |

---

## 5. Concrete checks (2026-07-29)

1. Re-decompile `0x005531d0` — CF matches raw bonus gate + cebao pack.
2. `get_function_xrefs` → `00553297`, `0082731b` only.
3. Body asm: `XORPS` zero; double `+0x214`; `004c4140`; six pushes; `ADD ESP,0x18`; `RET 0xC`.
4. `decompile 0x004c4140` — [1,250] clamp from +0x140/+0x148.
5. Parent dual: sole **named** score consumer for hit/miss.
6. `read_memory 0x00aaa7ac` → `00 00 c8 42` = 100.0f at second site.
7. No product string on this VA.

---

## 6. Verdict

**accept** — role sealed as skill accuracy **score** helper (`Skill_AccuracyScore_Inferred`).

Do **not** over-claim cebao stat composition, product spelling, or the unnamed second site’s full UI purpose.
