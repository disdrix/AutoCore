# Chain note: S2C `0x2031` SkillStatusEffect dispatch + ApplyEffects path

| Field | Value |
|---|---|
| **Date** | `2026-07-29` (wave2: ApplyEffects thiscall arg map) |
| **Topic** | Static seal of S2C SkillStatusEffect opcode → handler + register framing + ApplyEffects dual path + FUN residual roles |
| **Opcode** | `0x2031` (`GameOpcode.SkillStatusEffect`) |
| **Handler** | `Client_RecvSkillStatusEffect` @ `0x00811170` (`aa_00811170`) |
| **System** | `skills-abilities` |
| **Audience** | Dual-review residual strengthen; cold resume |

---

## Seal chain (static)

```
1. Client_PacketDispatch                    @ 0x00815710
     └─ switch(param_2->dwOpcode)
     └─ case 0x2031:
           MOV EAX, ESI          ; packet buffer
           MOV ECX, EBP          ; client/game context
           CALL 0x00811170       ; @ 0x0081589c
           return 1              ; MOV AL,1

2. Client_RecvSkillStatusEffect             @ 0x00811170
     └─ formal ECX = pClientCtx
     └─ packet in EAX (decomp in_EAX)
     └─ status@+0x14 gate {0, 'c'=0x63, 0x11}
     └─ error → abort type-8 CVOGHBOKToCastAgain + chat
     └─ success-like:
          resolve source TFID@+0x28
          if status == 0x11 → remove path (no ApplyStatusEffectLocal)
          else mana-short loop on targets@+0x40
          if source == null && status == 'c':
               skill = ResolveSkillTargets(skillId, level)
               compact-copy targets
               Skill_ApplyEffectsOnTarget_Inferred(skill, NULL, client+0xe04, …)  @ 0x00811638
          else if source != null:
               vtbl+0x218(client+0xe04)
               Skill_ApplyStatusEffectLocal(…)
                 └─ delay<1 → Skill_ApplyEffectsOnTarget_Inferred(skill, caster, caster+0xa4, …) @ 0x0051ae58
```

### Opcode evidence

| Source | Detail | Confidence |
|---|---|---|
| Sole function xref | `From 0081589c in Client_PacketDispatch [UNCONDITIONAL_CALL]` | **High** |
| PacketDispatch decompile | `case 0x2031` → handler → `return 1` | **High** |
| Clean dispatch | `reconstructed-exact/Client_PacketDispatch.cpp` | **High** |
| AutoCore | `GameOpcode.SkillStatusEffect = 0x2031` | corroborating |
| Handler body | never compares opcode | N/A (body-external seal) |

### Register framing evidence

Call site image @ `0x00815898` (Ghidra `read_memory` wave2 reconfirm):

| Bytes | Asm | Role |
|---|---|---|
| `8b c6` | `MOV EAX, ESI` | packet buffer → EAX |
| `8b cd` | `MOV ECX, EBP` | client context → ECX |
| `e8 cf b8 ff ff` | `CALL 0x00811170` | handler |
| `… b0 01` | `MOV AL, 1` | dispatch returns success |

**Signature (sealed):**

```c
void __fastcall Client_RecvSkillStatusEffect(void *pClientCtx);  /* ECX */
/* packet buffer in EAX */
```

### ApplyEffects path evidence (wave2)

Call site @ `0x00811638` (`get_assembly_context` + live decompile):

| Step | Detail |
|---|---|
| Gate | `status == 'c'` **and** source TFID resolve **null** |
| Skill | `CVOGReaction_ResolveSkillTargets(skillId@+8, level@+0xC)` → thiscall ECX |
| Caster | `PUSH 0` (null) |
| World | `*(client + 0xe04)` |
| Targets | compact 16B×n heap from wire 0x18-stride @ `+0x40` |
| Pos | stack copy of `pkt+0x18` |
| Seed | `pkt+0x3c` |
| Callee | `Skill_ApplyEffectsOnTarget_Inferred` `0x005538a0` (dual/map `_Inferred`) |

**Xrefs to `0x005538a0`:** Recv `0x00811638`, ApplyStatusEffectLocal `0x0051ae58`, `FUN_00514e70`, `FUN_00606180`, `FUN_00620480`.

**Clean-plate correction:** pre-wave2 clean omitted skill `this` (legacy 5-arg shape). Fixed to six-arg thiscall.

**`'c'` packer domain:** `CVOGReaction_CastSkillOnTarget` writes status `0` or `99` from `param_10` only — domain sealed for local reaction; sector-server emit matrix still open.

---

## FUN residual surface (roles; most product names still open)

Roles documented from decompiles of callees; **do not invent product names** without strings/RTTI. Prefer dual/map names when already assigned.

| Address | Role (evidence-only) | Conf |
|---|---|---|
| `0x007a69d0` | Singleton getter `&DAT_00d1f660` | High CF |
| `0x007a4480` | `vog_LogMessage` via NDError.cpp (level gate) | High string |
| `0x00514e00` | Refcount dec on nested slot `+0x64`/`+0x10` | High CF |
| `0x004294f0` | List traversal lock enter | High string |
| `0x004022a0` | List next under lock | High CF |
| `0x0040c700` | List unlock | High CF |
| `0x00418b80` / `0x00418890` / `0x004188e0` | map find / find / erase | High CF + string on erase |
| `0x0054b480` | Global map singleton `&DAT_00b04734` (≠ `Skill_GetCategoryCooldownMap`) | High CF |
| `0x005538a0` | **`Skill_ApplyEffectsOnTarget_Inferred`** — Recv direct + ApplyStatusEffectLocal delay&lt;1 | High (`_Inferred`; retail string open) |
| `0x007a6de0` | Localized string table (`"Server says"`) | High usage |
| `0x008f8200` | Chat log append (`CDlgChatLog`) | High CF |
| `0x007fb640` | UI dismiss helper | Probable |

---

## Dual-review unit

| Stable ID | Name | Reviews | Verdict |
|---|---|---|---|
| `aa_00811170` | `Client_RecvSkillStatusEffect` | A/B residual strengthen + ApplyEffects wave2 2026-07-29 | **accept-with-gaps** |

Paths:

- `reviews/A_aa_00811170_Client_RecvSkillStatusEffect.md`
- `reviews/B_aa_00811170_Client_RecvSkillStatusEffect.md`
- Function record: `functions/aa_00811170_Client_RecvSkillStatusEffect.md`
- Scratch: `tmp/a_00811170.md`

---

## Sealed vs still open

### Sealed (static, high confidence)

- Opcode **0x2031** → sole handler `0x00811170` via PacketDispatch
- Call framing **EAX=packet, ECX=client**
- Status gate `{0, 0x63('c'), 0x11}` (body)
- ApplyEffects **thiscall arg map** at Recv null+`'c'` (skill / null caster / `client+0xe04` / heap / pos / dice)
- Dual apply fan-out: null+`'c'` direct vs resolved → ApplyStatusEffectLocal
- FUN residual **roles** (evidence-only); `0x005538a0` dual/map name **`Skill_ApplyEffectsOnTarget_Inferred`**
- Local packer can write `'c'(99)` from `param_10`

### Still open

- Product names for **remaining** residual FUN_* (priority: `FUN_00514e00`, list-lock/map family, `FUN_0054b480`)
- Retail/mangled product string for `Skill_ApplyEffectsOnTarget_Inferred`
- Full sector-server emit matrix for `'c'(0x63)` (beyond local packer)
- World alias `client+0xe04` vs `caster+0xa4`
- Runtime cast capture; binary diff
