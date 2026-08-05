# Review B (skeptical / adversarial): `aa_004d09a0` CVOGReaction_CastSkillOnTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d09a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` (residual dual strengthen `2026-07-29`) |
| **Counterpart** | `reviews/A_aa_004d09a0_CVOGReaction_CastSkillOnTarget.md` |
| **Verdict** | **accept-with-gaps** on packer; **no-wire-in-unit Confirmed**; remote delivery still **outside scope** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Function always sends S2C/C2S 0x2031 on wire | **Falsified in-unit** — callees are resolve/apply/heap only; pack → optional Apply → free |
| 2 | Name “CastSkillOnTarget” = full cast SM | **Overstated** — packer + optional local apply; no LocalCastValidate here |
| 3 | `+0x7e` means English “server” | **Family polarity only** — non-zero enables packing; same offset class as other managers; not sealed English |
| 4 | Status always `'c'` | **Falsified** — only when param_10 nonzero (`-(x!=0)&99`) |
| 5 | Target list ownership always free | **Overstated** — free only if allocated (`bVar2` / owned list) |
| 6 | Size formula wrong if terminator counted | **Resolved** — `nTargets` is pre-term walk count; base `0x58` = `0x40` + one term slot; Apply `(size-0x40)/0x18` counts n+1 |
| 7 | Resolve error codes 0xd/0xe become packet status | **Falsified** — map stays in `local_8`; packet+0x14 never written from map; return is always 0 |
| 8 | Targets start at +0x50 | **Falsified as TFID base** — TFID @ +0x40; +0x50 is mana shorts of first entry (cursor math) |
| 9 | This is the same as RequestCastSkill / 0x2030 UI path | **Falsified** — no 0x2030; sibling wire consumer is Recv 0x2031 |
| 10 | Finished exact / bit-for-bit | **Overstated** — runtime/diff open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Field map / opcode | **High** | Wrong SkillStatusEffect consumer |
| Gate conditions | **High** | Spurious casts / never cast |
| **No network emission in unit** | **High / Confirmed** | Was Tentative; callee set seals |
| Size / terminator accounting | **High / Confirmed** | Off-by-one target copy in Apply |
| resolveFlags → packet status | **Confirmed no** | Fake error status on wire/local |
| Targets @ +0x40 | **High** | Wrong AutoCore layout |
| Named caller graph (NPC/Outpost/Summon) | **High** | Miss reaction entry points |
| Error codes 0xd/0xe product English | **Probable** | Client UX mismatch if someone ports map as return |
| `+0x7e` product name | **Tentative** | Wrong sim/client split |
| Remote 0x2031 emit (other unit) | **Open** | Multiplayer parity |

---

## 3. Cross-check against raw

Raw packer path matches clean human-refined rewrite and prior reconstruction review. Topic extraction skill-cast.md agrees on size and offsets. S2C consumer is separate unit `Client_RecvSkillStatusEffect` `0x00811170` — do not conflate.

**2026-07-29 callee seal:**

```
Object_ResolveFromTFID
Skill_ResolveTargetList
Skill_ApplyStatusEffectLocal
operator_new / operator_new[] / operator_delete / operator_delete[]
```

**2026-07-29 caller samples:**

```
NPC_TryCastSkillFromSet          @ 0x005d1280  → CastSkillOnTarget after validate/resolve
Outpost_CastSkillsForFaction     @ 0x00606d70
Outpost_CastSkillsForBeaconShare @ 0x006070e0
Skill_CVOGHBSkill_Summon         @ 0x00521650
FUN_004d1b80 (Skill_Uses alias)  @ 0x004d1b80
+ bulk FUN_* xrefs
```

Apply consumer (`0x0051aa00`) independently confirms target base `+0x40` and size-derived count.

---

## 4. Surviving contract for AutoCore

```
CastSkillOnTarget(world, skill, source, targetObj?, notItem, list?, aim, extra?, statusC, chargeUsed)
  if !world.flag(+0x7e) or !skill or !source: return 0
  maybe remap targetObj for world types 0xe/0x12/0x14/3 via vtbl+0x19c
  pack 0x2031 (size = n*0x18+0x58; targets @ +0x40; status 0 or 'c' from statusC only)
  if !list: ResolveTargetList; map flags to LOCAL codes only (do not treat as return/status)
  fill targets + terminator; optional ApplyStatusEffectLocal when (!extra && (targets|skill flags))
  free packet; return 0
Do NOT assume this emits sector SkillStatusEffect.
Do NOT assume this is RequestCastSkill (0x2030-family client UI path).
Do NOT assume resolve 0xd/0xe appear in packet+0x14 from this unit.
```

---

## 5. Open questions

1. Which unit (if any) serializes the packed buffer as S2C 0x2031 after reaction/NPC cast?
2. Interaction symmetry with `Client_RecvSkillStatusEffect` for multi-target mana shorts.
3. Runtime multi-target mana packing observation.
4. Whether any caller inspects the (always-0) return or the discarded resolve codes.

**Verdict:** Packer sealed; **no wire in unit Confirmed**; transport role remains open outside this ownership.
