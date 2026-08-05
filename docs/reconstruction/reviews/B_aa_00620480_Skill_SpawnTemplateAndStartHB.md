# Review B (skeptical / adversarial): `aa_00620480` Skill_SpawnTemplateAndStartHB

| Field | Value |
|---|---|
| **Stable ID** | `aa_00620480` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W19-E) |
| **Counterpart** | `reviews/A_aa_00620480_Skill_SpawnTemplateAndStartHB.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs for role). No `disassemble_bytes`. Own VA `0x00620480` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function **is** only the invalid-template logger | Full spawn+HB+effects pipeline | **Falsified** — string is one error path |
| 2 | thiscall / ret 4 | epilogue `C2 18 00` | **Falsified** — **6 stack args**, `ret 0x18` |
| 3 | Always returns 0 on any failure | gate miss returns **1**; only invalid template returns 0 | **Falsified** |
| 4 | Single spawn path | `+0x22` branches direct vs template | **Falsified multiplicity** |
| 5 | Direct CALL graph callers | only DATA `@0x009d1598` | **Falsified** — table install |
| 6 | No terrain interaction | `CVOGMap_CastTerrainHeight` + 100.f bias | **Falsified** |
| 7 | HB always started | owner-null path dtor without Enqueue | **Falsified** conditional |
| 8 | Live decomp diverges CF from raw | cosmetic types/names only | **Falsified** as CF break |
| 9 | PDB name proven from string | no PDB | **Open English** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 0x18 / six args / 0\|1 returns | **High** | stack corruption / wrong HR |
| Dual spawn arms + invalid template | **High** | missing entities / silent fail |
| HB new/enqueue/start | **High** | skills never fire |
| Floats 5.0 / 100.0 | **High** | wrong spawn height |
| DATA install site | **High** | wrong dispatch wiring |
| arg3/arg5 product English | **Open** | doc-only |
| Runtime / bit-exact | **Open** | shipping image |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  gate ctx+0x7e && source && related=vtbl+0x214
  if skillDef+0x22==0: new 0x690 path
  else: FUN_0058bf50 or log+return 0
  terrain Z+100; EnsureLoaded; HB 0x6c0; Enqueue+Start
  optional ApplyEffects; return 1

bytes:
  prolog 55 8B EC 83 E4 F0 6A FF 68 FC 88 9A 00
  gate 8A 40 7E / 8B 4D 08
  vcall FF 92 14 02 00 00
  size 68 90 06 00 00 (0x690)
  string push → 009e1c6c
  early ret: 33 C0 … C2 18 00
  success: B8 01 00 00 00 … C2 18 00
  DAT_00aaa7ac = 00 00 C8 42 (100.f)
  DAT_00aaa688 = 00 00 A0 40 (5.0f)
  DATA 009d1598 = 80 04 62 00
```

**No conflict** on owned CF. String-seed name **rejected** as primary.

---

## 4. Surviving contract for AutoCore

```csharp
// Skill_SpawnTemplateAndStartHB @ 0x00620480
// retail: 6 stack args, ret 0x18; table entry @ 0x009d1598
// return 0 only on invalid template; 1 on success or gated no-op

uint SpawnTemplateAndStartHB(Object source, SkillDef def, WorldCtx ctx, ...)
{
  // if !gate: return 1
  // spawn direct or via template lookup
  // terrain snap z+100; ensure skills; start HB action
  // optional apply effects
}
```

---

## 5. Residual risks

1. MI-adjusted object arithmetic is dense — clean port must preserve adj formulas or use typed layouts recovered elsewhere.
2. `FUN_00404c90` dual-arm identity may hide a decompiler merge of two pose getters.
3. No live skill-cast capture in this dual.
