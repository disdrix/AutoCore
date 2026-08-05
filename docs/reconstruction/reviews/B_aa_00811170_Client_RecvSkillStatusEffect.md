# Review B (skeptical / adversarial): `aa_00811170` Client_RecvSkillStatusEffect

| Field | Value |
|---|---|
| **Stable ID** | `aa_00811170` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-28` (opcode/FUN residual strengthen `2026-07-29`; ApplyEffects arg-map wave2) |
| **Counterpart** | `reviews/A_aa_00811170_Client_RecvSkillStatusEffect.md` |
| **Verdict** | **accept-with-gaps** on CF (full body); **reject-stub-as-impl** (stub removed); opcode + framing + ApplyEffects thiscall **sealed**; FUN product names still **needs-more-evidence** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Any non-zero status is success | **Falsified** — only `{0, 'c', 0x11}` pass the gate |
| 2 | Always applies `Skill_ApplyStatusEffectLocal` | **Falsified** — error path returns after chat; 0x11 may remove via +0x220; `'c'` + null source uses `Skill_ApplyEffectsOnTarget_Inferred` (`0x005538a0`) |
| 3 | Empty stub is the implementation | **Falsified** — stub was no-op; full body is CF (stub now removed from clean) |
| 4 | Portable `__fastcall(client)` alone is enough | **Was Weak** → **Sealed 2026-07-29** — call site loads EAX=ESI packet, ECX=EBP client |
| 5 | `+0x10` is cooldown duration | **Falsified by sibling evidence** — `lDelayTime` is remaining charge; cooldown lives in type-8 HB / category map |
| 6 | Source TFID may be vehicle for player cast | **Falsified for local-caster match** — compares `character+0x164`; vehicle fails match bit |
| 7 | Target slots are damage deltas | **Falsified** — 0x18 entries with mana/maxMana shorts applied via vtbl +0xac |
| 8 | `0x11` is a mystery raw byte | **Weakened** — aligns with `SKILL_RESPONSE_CANCELLED_ACTIVE=17`; still confirm live cancel path |
| 9 | All FUN_* are already named in registry | **Falsified** — residual surface remains; **roles** now documented, product names open |
| 10 | Finished exact / bit-for-bit | **Overstated** — runtime/diff open |
| 11 | Opcode 0x2031 is plate folklore only | **Falsified 2026-07-29** — sole PacketDispatch xref + `case 0x2031` + call site `0x0081589c` |
| 12 | `FUN_0054b480` == `Skill_GetCategoryCooldownMap` | **Falsified** — `FUN_0054b480` returns global `&DAT_00b04734`; GetCategoryCooldownMap is `0x00518d70` (owner+0x6c map) |
| 13 | Null-source `'c'` path passes caster as first formal `0` and has no skill this | **Falsified wave2** — asm `MOV ECX,skill` + `PUSH 0` caster; skill is thiscall ECX |
| 14 | Recv always goes through `Skill_ApplyStatusEffectLocal` before ApplyEffects | **Falsified** — null+`'c'` calls ApplyEffects **directly** at `0x00811638`; resolved source uses ApplyStatusEffectLocal |
| 15 | Recv and ApplyStatusEffectLocal pass the same world expression into ApplyEffects | **Falsified as identity of expression** — Recv uses `client+0xe04`; ApplyStatusEffectLocal uses `caster+0xa4` (alias open) |
| 16 | `'c'` is never written by any packer | **Falsified** — `CVOGReaction_CastSkillOnTarget` writes `0` or `99` from `param_10` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Allowed status set `{0,c,0x11}` | **High** | Wrong CD abort / apply / silent fail |
| HB type8 skill-id match abort | **High** | Leave optimistic CD running or cancel wrong skill |
| Failure chat path | **High** | Missing player feedback on reject |
| `Skill_ApplyStatusEffectLocal` on resolved source | **High** | Silent no FX / no delay HB |
| Packet field offsets | **High** | Wire schema mismatch with AutoCore |
| Opcode **0x2031** | **High / Confirmed** | Was Probable; sealed via dispatch sole xref (reconfirm wave2) |
| Packet-in-EAX framing | **High / Confirmed** | Was Tentative; sealed via call-site image (reconfirm wave2) |
| ApplyEffects thiscall args at Recv | **High / Confirmed** | Asm @ `0x00811638` (wave2) |
| `'c'(0x63)` meaning | **Probable** (packer domain) / sector emit open | Packer writes 0/99; full server table open |
| `'c'` path calls `Skill_ApplyEffectsOnTarget_Inferred` | **High / Confirmed** | Direct CALL xref + thiscall arg map |
| Map FUN_* / list-lock FUN_* roles | **High** CF | Product names open; erase/find/lock behavior clear |
| Clean scaffold quality | **High** after stub removal + ApplyEffects thiscall fix | Was Low when stub-only; mid when this omitted |

---

## 3. Cross-check against raw

```
status = pkt+0x14
if status not in {0, 'c', 0x11}:
  if char+0x6b9 == 0:
    log "Aborting cooldown"; walk HB type8 CVOGHBOKToCastAgain match skillId@+8; abort
  else if status == 0x06: return   # BUSY silent
  FormatFailureMessage → "[System] Server says: …"; return

source = ResolveTFID(pkt+0x28)
localCasterMatch = source TFID equals character+0x164 (full TFID incl variant)

if status == 0x11:
  LookupActiveCastBinding(skillId); resolve; vcall +0x220(skillId, 0); return?

else:
  for each target@+0x40 until sentinel:
    resolve; entity = vcall +0x214; mana short +0xac; OR +0x180 bit7; store +0x12e
  if source == null:
    if status == 'c':
      skill = ResolveSkillTargets(skillId, level)
      copy pos; compact-copy targets (16B × n from 0x18 wire stride)
      Skill_ApplyEffectsOnTarget_Inferred(skill, NULL, client+0xe04, heap, &pos, dice@+0x3c)
      free heap; free skill
  else:
    source vcall +0x218(ctx+0xe04)
    ApplyStatusEffectLocal(…, pkt, localMatch && !itemSkill)
      # inside: delay<1 → ApplyEffects(skill, caster, caster+0xa4, …)
    if itemSkill: map path via FUN_0054b480 + FUN_00418890 + GetCategoryCooldownMap
    optional UI vcall +0x450(0)
```

Clean single body matches this shape (ApplyEffects thiscall fixed wave2). Do **not** use any historical empty stub or pre-thiscall 5-arg call shape.

---

## 4. Surviving contract for AutoCore

```
On S2C SkillStatusEffect (0x2031)  [dispatch sealed]:
  Client_PacketDispatch case 0x2031 → only Client_RecvSkillStatusEffect
  Call framing: EAX = packet, ECX = client context

  status@+0x14:
    0 / 0x11 / 0x63('c') → apply / remove / cast-side paths
    else → abort optimistic cast-again HB type8 for skillId@+8;
           show system chat via Skill_FormatFailureMessage
           (BUSY 0x06 may silent-return under char+0x6b9)
  source TFID@+0x28 must be character for local-caster match (not vehicle)
  targets@+0x40 are {TFID, mana, maxMana} 0x18-stride; not damage
  lDelayTime@+0x10 is charge remainder → ApplyStatusEffectLocal (not CD start)
  bIsItemSkill@+0x38 alters ApplyStatusEffectLocal flag + category CD map path
  Keep wire aligned with CVOGReaction_CastSkillOnTarget packer (size 0x9a0)
```

---

## 5. Opcode / framing attack surface (2026-07-29; reconfirm wave2)

| Attack | Result |
|---|---|
| Handler bound under a different opcode | **Fail** — sole xref is PacketDispatch `0x0081589c`; decompile case is `0x2031` |
| Packet formal is ECX | **Fail** — `MOV EAX,ESI` before call; ECX is client (EBP) |
| Multiple dispatch sites | **Fail** — one unconditional call |
| Body must hardcode 0x2031 | **N/A** — dispatch ownership is correct pattern |

Image confirmation (`read_memory` @ `0x00815898` wave2): `8b c6 8b cd e8 cf b8 ff ff 5f 5e 5d b0 01 …`.

---

## 5b. ApplyEffects path attack surface (wave2)

| Attack | Result |
|---|---|
| First stack arg `0` is skill this | **Fail** — `PUSH 0` is caster; `MOV ECX,ESI` loads skill thiscall |
| Legacy clean 5-arg call is authoritative | **Fail** — omits this; contradicts asm and post-rename decomp |
| ApplyEffects only reachable via ApplyStatusEffectLocal | **Fail** — direct Recv xref `0x00811638` |
| Null+`'c'` and resolved-source share one apply arm | **Fail** — exclusive if/else on source resolve |
| World always `caster+0xa4` | **Fail at Recv site** — uses `client+0xe04` when caster null |

---

## 6. FUN residual surface — adversarial

| Claim | Adversarial finding |
|---|---|
| Promote `0x005538a0` beyond `_Inferred` | **Reject product name** — already `Skill_ApplyEffectsOnTarget_Inferred`; no retail string |
| `FUN_0054b480` is category cooldown map | **Reject identity** — different address/global than `Skill_GetCategoryCooldownMap`; is a **related** map singleton used on item-skill path |
| List helpers are skill-specific | **Reject** — generic locked-list + std::map family; skill only provides type-8 filter + skillId match |
| `FUN_007a4480` always logs | **Falsified** — only when first arg == 1; error format string uses arg 0 → no log side effect on that path |
| Roles are unknown | **Weakened** — decompiles pin lock/map/log/chat roles to High; only product labels open |
| ApplyEffects arg order unknown | **Closed wave2** — thiscall map sealed; only product English open |

Priority residual for naming (evidence still insufficient): `FUN_00514e00`, list-lock trio, `FUN_0054b480`.

---

## 7. Open questions

1. ~~Seal opcode 0x2031~~ **Closed** — see §5 / chain note.
2. ~~Confirm EAX/ECX framing~~ **Closed** — call site image.
3. ~~ApplyEffects thiscall arg map at Recv~~ **Closed wave2** — asm §5b.
4. Full live/sector table of server-emitted `eSkillResponses` including when `'c'(0x63)` appears (packer domain sealed for local reaction).
5. Product-name residual FUN_* only with strings/xrefs — priority `FUN_00514e00` (not `0x005538a0`).
6. Does success path ever cancel type-8 HB, or only confirm (optimistic HB left to expire)?
7. World `client+0xe04` vs `caster+0xa4` alias.
8. Runtime success/fail/cancel capture still open.

**Verdict:** **accept-with-gaps** on CF (full body); **reject-stub-as-impl**; opcode + register framing + ApplyEffects path **sealed (High)**; FUN **roles High**, product names **open**; sector `'c'` emit + runtime still **needs-more-evidence**.
