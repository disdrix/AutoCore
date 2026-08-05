# Function record: Client_RecvSkillStatusEffect

| Field | Value |
|---|---|
| **Stable ID** | `aa_00811170` |
| **Canonical name** | `Client_RecvSkillStatusEffect` |
| **Address** | `0x00811170` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Opcode** | S2C **0x2031** SkillStatusEffect — **sealed** via sole PacketDispatch case/xref (`0x0081589c`) |
| **Completion status** | **Human-refined** — annotated + clean full body; dual A/B; opcode/framing sealed; **ApplyEffects thiscall arg map sealed wave2 2026-07-29** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

S2C skill status-effect / cast result. Validates `eSkillResponses`, aborts cast-again heartbeat on hard failures, applies mana shorts, then either:

- **null source + status `'c'`** → direct `Skill_ApplyEffectsOnTarget_Inferred`, or
- **resolved source** → `Skill_ApplyStatusEffectLocal` (which may call ApplyEffects when `lDelayTime < 1`).

## Signature (refined — framing sealed 2026-07-29)

```c
void __fastcall Client_RecvSkillStatusEffect(void *pClientCtx);  /* ECX = client */
/* packet buffer in EAX (call site: MOV EAX,ESI; MOV ECX,EBP; CALL) */
```

### Dispatch (sealed)

```
Client_PacketDispatch case 0x2031 @ 0x00815898:
  8b c6          MOV EAX, ESI    ; packet
  8b cd          MOV ECX, EBP    ; client
  e8 cf b8 ff ff CALL 0x00811170
  … b0 01 …      return 1
```

Sole xref: `From 0081589c in Client_PacketDispatch [UNCONDITIONAL_CALL]`.

## ApplyEffects path (sealed wave2)

**Gate:** `status@+0x14 == 'c'(0x63)` **and** `ResolveTFID(source@+0x28) == null`.

**Call site** `0x00811638` → `Skill_ApplyEffectsOnTarget_Inferred` (`0x005538a0`):

```c
/* __thiscall */
Skill_ApplyEffectsOnTarget_Inferred(
    skill,                 /* ECX — CVOGReaction_ResolveSkillTargets(skillId, level) */
    /*caster*/ NULL,       /* PUSH 0 */
    /*world*/  *(void**)(pClientCtx + 0xe04),
    /*targets*/ compactTfidHeap,   /* 16B × n; n = (uiSize-0x40)/0x18 */
    /*pos*/    &posFromPkt_0x18,
    /*seed*/   *(uint*)(pkt + 0x3c));
```

| Contrast | caster | world |
|---|---|---|
| This path | null | `client+0xe04` |
| Via `Skill_ApplyStatusEffectLocal` (delay&lt;1) | `pCasterObj` | `caster+0xa4` |

## Packet fields (body uses)

| Offset | Role |
|---|---|
| `+0x04` | `uiSize` → target count `(size - 0x40) / 0x18` |
| `+0x08` | skillId |
| `+0x0C` | level |
| `+0x10` | `lDelayTime` (charge remainder — not CD) |
| `+0x14` | status / `eSkillResponses` gate `{0, 'c'=0x63, 0x11}` |
| `+0x18` | world position |
| `+0x28` | source TFID |
| `+0x38` | `bIsItemSkill` |
| `+0x3c` | dice seed |
| `+0x40+` | targets stride **0x18** `{TFID, mana, maxMana}` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00811170_Client_RecvSkillStatusEffect.md`
- Annotated: `docs/reconstruction/raw/aa_00811170_Client_RecvSkillStatusEffect.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_RecvSkillStatusEffect.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00811170_Client_RecvSkillStatusEffect.md`
- Review B: `docs/reconstruction/reviews/B_aa_00811170_Client_RecvSkillStatusEffect.md`
- Seal chain: `docs/reconstruction/reviews/CHAIN_2026-07-29_s2c_2031_skillstatuseffect.md`
- Scratch: `tmp/a_00811170.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Packet / UI offsets in notes | High (schema + body) |
| Status gate `{0, 'c', 0x11}` | High |
| Opcode **0x2031** dispatch | **High / Confirmed** (sole xref + case; reconfirm wave2) |
| Packet EAX / client ECX framing | **High / Confirmed** (call-site image; reconfirm wave2) |
| ApplyEffects thiscall arg map (Recv null+`'c'`) | **High / Confirmed** (asm wave2) |
| Dual apply fan-out (direct vs ApplyStatusEffectLocal) | High |
| Types / residual FUN product names | Open — roles documented; do not invent |
| Sector `'c'` emit matrix | Open (local packer domain sealed) |
| World `+0xe04` vs `caster+0xa4` alias | Open |

## Open residual

- Product names for residual FUN_* (priority `FUN_00514e00`, list-lock/map family, `FUN_0054b480`) — roles in dual A/B + chain
- Sector-server emit conditions for `'c'(0x63)` beyond local reaction packer `param_10`
- World pointer alias `client+0xe04` vs `caster+0xa4`
- `nInferred` noise on ApplyStatusEffectLocal formals
- Runtime cast capture; binary diff
