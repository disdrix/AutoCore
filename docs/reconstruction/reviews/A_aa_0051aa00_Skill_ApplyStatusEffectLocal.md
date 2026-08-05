# Review A (reconstruction fidelity): `aa_0051aa00` Skill_ApplyStatusEffectLocal

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051aa00` |
| **VA** | `0x0051aa00` |
| **Canonical name** | `Skill_ApplyStatusEffectLocal` |
| **Review date** | `2026-07-29` (dual residual refresh) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0051aa00_Skill_ApplyStatusEffectLocal.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Apply SkillStatusEffect (**0x2031**) buffer locally: load/create skill, resolve/cancel active cast binding, sim cast-again HB, then either `Skill_ApplyEffectsOnTarget_Inferred` (delay&lt;1) or `CVOGHBWakeupSkill` delayed HB. Returns local status (`2` / `0` / `0x11`). Client apply of S2C status — not caster LocalCastValidate. Wire cancel `0x11` is **Recv-only**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051aa00_Skill_ApplyStatusEffectLocal.md` |
| Annotated | `docs/reconstruction/raw/aa_0051aa00_Skill_ApplyStatusEffectLocal.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_ApplyStatusEffectLocal.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051aa00_Skill_ApplyStatusEffectLocal.md` |
| Residual scratch | `docs/reconstruction/reviews/a_0051aa00.md` |
| Packet | `Documentation/PACKET STRUCTURES.md` `SMSG_Sector_SkillStatusEffect` |
| Live Ghidra | re-decompile 2026-07-29 + RTTI on vtbl `009de7b4` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `0x2031` body field map | **High** | PACKET STRUCTURES + body |
| Load/create skill path | **High** | Body |
| Rank sum `+0x5f6 + +0x174` | **High** | sizeof HB + cross-unit |
| Skill id `+0x5fc`, flags `+0x614`, category `+0x5e8`, skip-CD `+0x61c`, CD `+0x10` | **High** | overlay math + InitRuntime dual |
| Binding cancel early-return predicates | **High** | Body CF |
| Wire `0x11` ≠ local return path | **High** | Recv branch |
| Recv discards return | **High** | Call site |
| `Skill_ApplyEffectsOnTarget_Inferred` | **High** | Prior residual unit |
| `CVOGHBWakeupSkill_ctor` | **Confirmed** | RTTI `".?AVCVOGHBWakeupSkill@@"` |
| Local S2C apply role | **High** | System |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Parse packet → ensure skill → apply effect / WakeupSkill HB | Yes |
| No invented cast request C2S | Yes |
| Sealed skill byte offsets (not `+0x130` placeholders) | Yes (residual update) |
| ApplyEffects skill-thiscall arg order | Yes (residual update) |

---

## 5. Gaps / open

1. Product English for `skill+0x614` bit0.
2. Product names `FUN_00514e00` / `FUN_00514e20` (roles only).
3. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps** — dual residual sealed body contract; matrix residual open items reduced.
