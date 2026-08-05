# Review B (skeptical / adversarial): `aa_0054fa20` Skill_FormatFailureMessage

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054fa20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (residual strengthen) |
| **Counterpart** | `reviews/A_aa_0054fa20_Skill_FormatFailureMessage.md` |
| **Residual scratch** | `reviews/a_0054fa20.md` |
| **Verdict** | **accept** on sealed table + enum crosswalk; 0x10 opaque helpers + 0x0F UX residual |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Server authority deny | Body only fills strings | **Falsified** — client formatter |
| 2 | Only 3 generic messages | Switch 1–14 + 0x10 + 0x12 | **Falsified** |
| 3 | Mutates cast flag | No skill/cast stores | **Falsified** — pure out-buf |
| 4 | Case 0x12 is summon-level cap | Raw case 0x12 = stunted; **0x10** is summon sprintf | **Falsified** (wave2 + prior dual A) |
| 5 | Case 9 = active-skill / 11 = range | Raw: 9=air, 10=active-skill, 0x0D=range | **Falsified** prior dual A |
| 6 | Code 0 formats success text | No case 0 → default unhandled | **Confirmed risk** if caller formats 0 |
| 7 | 0x0F accuracy miss has toast | Falls default unhandled | **Confirmed** — no dedicated key |
| 8 | Case 3 string = wrecked only | LocalCastValidate returns 3 for missing plant | **Survives** as shared code; string is wrecked wording |
| 9 | Enum name FACTION implies faction toast | Case 14 key = `Wrong target type.` | **Survives** — name≠UX; do not invent faction string |
| 10 | Enum TOO_SOON implies “too soon” toast | Case 0x12 key = `Target has just been stunted` | **Survives** — name≠UX |
| 11 | Annotated “current ≤ max” labels are sealed | Raw only has `uVar4 <= uVar3` without operand meaning | **Confirmed residual** — leave FUN_* |
| 12 | DEATHCAST=99 has special text | No case 99 | **Confirmed** — default unhandled |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Fixed keys 1–14, 0x12 | High | Wrong cast toasts |
| 0x10 vs 0x12 case split | High | Summon vs stunt UX swap |
| Default residual set (0, 0x0F, 0x11, 99, other) | High | Missing/extra toast |
| 0x10 sprintf templates | High | Bad summon text |
| 0x10 count/level math | Tentative | Wrong N / level number |
| pCharacterCtx object type | Tentative | Wrong vtbl assumption |
| Locale FUN names | Tentative | Naming only |
| PACKET STRUCTURES enum numeric values | High (docs) | Wrong AutoCore wire enum if docs wrong — independent of this unit’s strings |

---

## 3. Cross-check against raw + re-decompile

```
if (!pOutBuf) return "";
FUN_007a69d0();
switch (code) {
  1..14, 0x12: locale-key → strcpy-style → return pOutBuf;
  0x10: goto summon_cap; // sprintf or case-8 fallback
  default: "Unhandled reason for skill failure.";
}
```

Fresh decompile 2026-07-29 residual **≡** frozen raw body. Sealed table + enum crosswalk in residual scratch / function record. Prior A mid-table shift and wave2 “0x12 summon” **rejected**.

Callees confirmed: `FUN_007a69d0`, `FUN_007a6de0`, `sprintf`, and for 0x10 `FUN_004c3f10` / `FUN_004c2e60` / `FUN_004c2eb0`. Callers ×5 unchanged.

---

## 4. Surviving contract for AutoCore

```
FormatFailureMessage(code, out, charCtx?):
  1..14, 0x12 → fixed English keys (via locale)
  0x10 → "You can only have N summons at a time[ until Level L]." or case-8 fallback
  else (0, 0x0F, 0x11, 99, other) → "Unhandled reason for skill failure."
  local only; pair LocalCastValidate / RequestCast / RecvSkillStatusEffect fail UX
  Do not invent codes; do not map 0x12 to summon
  Do not replace UX keys with enum identifier spelling (CORPSE/FACTION/TOO_SOON)
```

---

## 5. Open questions

1. Live-capture each deny code once.
2. Seal summon helpers if AutoCore needs level-cap text parity.
3. Whether 0x0F should stay generic unhandled (retail does).
4. Optional: confirm PACKET STRUCTURES enum values against a second source (out of unit).

**Verdict:** **accept** on sealed eSkillResponses string table + CF + enum name crosswalk; residual 0x10 helper math, locale names, and runtime only.
