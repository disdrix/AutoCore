# Review B (skeptical / adversarial): `aa_005538a0` Skill_ApplyEffectsOnTarget_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005538a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual **strengthen**) |
| **Counterpart** | `reviews/A_aa_005538a0_Skill_ApplyEffectsOnTarget_Inferred.md` |
| **Verdict** | **accept** on role/rename/CF; **accept-with-gaps** on event-code English + residual FUN product names |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Full server combat / damage authority | **Falsified** — client combat events + skill handler; no net send in callee set |
| 2 | Name is product-original | **Holds as false** — `_Inferred` required; no string/RTTI; UF-013 dual/map closed |
| 3 | Always requires non-null caster | **Falsified** — Recv null-source `'c'`; body null-checks every caster use |
| 4 | Walks entire multi-TFID list here | **Falsified for this body** — one `ResolveObjectTarget`; list walk if any is handler/caller |
| 5 | Same unit as `Skill_ApplyStatusEffectLocal` | **Falsified** — ApplyStatusEffectLocal *calls* this when delay&lt;1 |
| 6 | Return 0 only on miss | **Falsified** — world gate, handler fail, miss, all yield 0 |
| 7 | Power drain always after apply attempt | **Falsified** — **no accuracy + handler returns 0** skips LAB power drain |
| 8 | Power drain always runs on miss | **Holds** — miss still `goto LAB_00553a7e` |
| 9 | Event 4 carries ROUND(skill+0x28) | **Falsified** — event 4 uses trailing zeros; ROUND only on 0xc/0xe/5/6 |
| 10 | Null target always returns 0 | **Falsified** — can return 1 after power path if fail flags clear and target null (fall-through) |
| 11 | `FUN_00620480` passes original skill as this | **Falsified** — uses `CVOGReaction_ResolveSkillTargets` result (`puVar2`) as skill this |
| 12 | Clean always matched retail power CF | **Prior gap** — first clean always drained; **fixed** in strengthen pass |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Skill thiscall identity | **High** | Mis-attribute offsets to caster |
| 5 callers / 5 xrefs | **Confirmed** | Miss alternate entry |
| Codes 4/0xc/0xe/5/6 present | **Confirmed** | Wrong FX wiring |
| Code English labels | Tentative | Misnamed start/hit/miss UX |
| Accuracy path + floater | **High** | Wrong miss gate |
| Power-drain CF matrix | **Confirmed** | Port drains on handler fail incorrectly |
| Multi-target completeness | Partial | Under-count targets in ports |
| `DAT_009d1ca8` invalid TFID | **Confirmed** | Wrong floater source when caster null |

---

## 3. Surviving contract

```
Skill_ApplyEffectsOnTarget(skill, caster?, world, targetTfid*, posOrArg, seed) -> 0|1
  require world && *(world+0xe4e8)
  target = ResolveObjectTarget(*targetTfid)   // single primary
  if caster:
    caster.vtbl+0x238(4, skillId, rank, skill+0x14, target, 0,0,0)
    if caster.vtbl+0x214(): FUN_004c2f20(skillId)
  miss=false; fail=false
  if handler && target:
    if skill+0x624 bit0:
      slice = FUN_0058ab60(seed)
      if !Skill_AccuracyHitCheck_Inferred(skill, caster, target, *slice, 0):
        floater(from=caster+0x160|DAT_009d1ca8, to=target+0x160, flag+0x2a=1); miss=true
      else:
        fail = (handler.vtbl+0x2c(...) == 0)
      delete[] slice
      → power_lab
    else:
      fail = (handler.vtbl+0x2c(...) == 0)
      if !fail → power_lab
      // if fail: skip power_lab
  else:
    → power_lab
power_lab (caster only):
  if vtbl+0x210(0) && *(obj+0x6b4)>0: skip drain
  else if vtbl+0x214(): plant.vtbl+0xb0(skill+8)
  if fail || miss:
    caster.vtbl+0x238(0xc, ..., ROUND(skill+0x28)); return 0
  if target:
    caster?.vtbl+0x238(0xe, ..., ROUND(...))
    if type(target)==0xe && target.vtbl+0x238(6,...) nonzero: return 1
    target.vtbl+0x238(5, ..., ROUND(...))
  return 1
```

---

## 4. Residual uncertainty

| # | Item | Blocks rename seal? |
|---|---|---|
| R1 | Product name | No (`_Inferred`; UF-013 closed dual/map) |
| R2 | Event-code English | No |
| R3 | Multi-TFID handler walk | No for this unit |
| R4 | `FUN_0058ab60` / `FUN_004c2f20` names (`00553240` dual-sealed) | No |
| R5 | `FUN_00606180` / `FUN_00514e70` / `FUN_00620480` product names | No (roles sealed at call sites) |
| R6 | Runtime / bit-exact | No |

---

## 5. Concrete checks (re-run 2026-07-29 strengthen)

1. Re-decompile `0x005538a0`; confirm event immediates **4, 0xc, 0xe, 5, 6**.
2. `get_function_callers` → five sites; xrefs: `00514fd2`, `0051ae58`, `00811638`, `006061d2`, `006209f3`.
3. Callees: ResolveObjectTarget `004bae70`, floater `00402620`, accuracy `00553240`, seed slice `0058ab60`, `004c2f20`, `operator_delete[]`.
4. Recv path: status `'c'` + null source still calls after `ResolveSkillTargets`.
5. ApplyStatusEffectLocal: only when delay &lt; 1.
6. Power-drain: no-accuracy handler-fail does **not** enter LAB_00553a7e.
7. `read_memory` `DAT_009d1ca8` → `ff ff ff ff ff ff ff ff 00 00 00 00 00 00 00 00`.
8. No string xrefs on function body for product name.

---

## 6. Verdict

**accept** — role sealed as skill apply-effects-on-target core; name remains `_Inferred`. Dual residual strengthen seals **power-drain CF asymmetry**, caller arg contracts (esp. HB layout + `FUN_00620480` resolved-skill this), floater/global, and callee VAs.

Do **not** over-claim multi-target walk, server damage authority, or English labels for event codes.
