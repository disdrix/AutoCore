# Review A (reconstruction fidelity): `aa_00811170` Client_RecvSkillStatusEffect

| Field | Value |
|---|---|
| **Stable ID** | `aa_00811170` |
| **VA** | `0x00811170` |
| **Canonical name** | `Client_RecvSkillStatusEffect` |
| **Review date** | `2026-07-28` (opcode/FUN residual strengthen `2026-07-29`; ApplyEffects arg-map wave2) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00811170_Client_RecvSkillStatusEffect.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

S2C **0x2031** SkillStatusEffect / cast-result handler. Gates on `eSkillResponses@+0x14` ∈ {0, `'c'`=0x63, 0x11}; hard failures abort optimistic cast-again heartbeat (type **8** / `CVOGHBOKToCastAgain`) matching `skillId@+8`, touch category CD map, and show `"Server says"` system chat via `Skill_FormatFailureMessage`. Success-like path resolves source TFID@+0x28, applies target mana shorts, cancel-active remove (0x11), cast side-path (`'c'`), or `Skill_ApplyStatusEffectLocal`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00811170_Client_RecvSkillStatusEffect.md` |
| Annotated | `docs/reconstruction/raw/aa_00811170_Client_RecvSkillStatusEffect.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvSkillStatusEffect.cpp` |
| Function record | `docs/reconstruction/functions/aa_00811170_Client_RecvSkillStatusEffect.md` |
| Packet schema | `Documentation/PACKET STRUCTURES.md` (`SMSG_Sector_SkillStatusEffect`, `eSkillResponses`) |
| Topic | `docs/topic-extractions/skill-cast.md` |
| System map | `docs/reconstruction/systems/skills-abilities.md` |
| Packer sibling | `CVOGReaction_CastSkillOnTarget` `0x004d09a0` |
| Dispatch | `Client_PacketDispatch` `0x00815710` / call site `0x0081589c` |
| Seal chain | `reviews/CHAIN_2026-07-29_s2c_2031_skillstatuseffect.md` |
| Ghidra | `get_function_xrefs`, `get_assembly_context`, `read_memory`, `batch_decompile` of residual FUN_* (2026-07-29) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Status gate allows only `{0, 0x63('c'), 0x11}` | **High** | Triple compare at entry; else error arm |
| `0` = OK; `0x11` = `SKILL_RESPONSE_CANCELLED_ACTIVE` (17) | **High** | Enum plate + remove branch uses 0x11 |
| `'c'(0x63)` is a distinct cast side-path (not public enum name) | **Probable** | Body only; not in `eSkillResponses` plate list; server emit open |
| Packet layout: skillId@+8, level@+0xC, delay@+0x10, status@+0x14, pos@+0x18, source TFID@+0x28, itemSkill@+0x38, dice@+0x3c, targets@+0x40 (0x18 stride) | **High** | Body + PACKET STRUCTURES + packer cross-check |
| `lDelayTime@+0x10` is remaining charge delay, **not** cooldown | **High** | Topic extraction + ApplyStatusEffectLocal dual |
| Error: walk HB list type==8, RTTI cast to `CVOGHBOKToCastAgain`, match skillId at HB skill+0x5fc | **High** | Body |
| Error: abort HB via vcall +0x18(1,1); category map find/erase helpers | **High** | CF; map helper FUN_* roles sealed, product names open |
| Failure chat: `Skill_FormatFailureMessage` + `"Server says"` + `CDlgChatLog` + `FUN_008f8200` | **High** | Strings + RTTI |
| BUSY(0x06) early return when `char+0x6b9 != 0` (skips HB abort) | **High** | Nested error arm |
| Source TFID local-caster match vs `character+0x164` (not vehicle) | **High** | Body + topic |
| Remove 0x11: `Skill_LookupActiveCastBinding` → resolve → vtbl +0x220(skillId,0) | **High** | Body |
| Target loop: resolve TFID, vtbl +0x214, mana short vtbl +0xac, OR bit7 @ +0x180, store maxMana @ +0x12e | **High** | Body + REACTION_SYSTEM flags note |
| Source null + status `'c'`: `CVOGReaction_ResolveSkillTargets` + copy targets + `Skill_ApplyEffectsOnTarget_Inferred` (`0x005538a0`) | **High / Confirmed** | Call site asm `0x00811638` (wave2) |
| **ApplyEffects thiscall arg map** (skill, null caster, world=`client+0xe04`, TFID heap, pos, dice) | **High / Confirmed** | Pushes + `MOV ECX,ESI` before CALL (wave2) |
| Source resolved: vtbl +0x218(+0xe04) then `Skill_ApplyStatusEffectLocal` | **High** | Named callee; ApplyEffects only if delay&lt;1 **inside** ApplyStatusEffectLocal |
| Dual apply fan-out: null+`'c'` → direct ApplyEffects; resolved → ApplyStatusEffectLocal | **High** | Mutually exclusive CF arms |
| Item-skill (`+0x38`) category CD map update via `FUN_0054b480` / `FUN_00418890` / `Skill_GetCategoryCooldownMap` | **High** CF | `FUN_0054b480` = global map singleton (≠ GetCategoryCooldownMap) |
| **Opcode is S2C 0x2031** | **High / Confirmed** | Sole xref PacketDispatch case `0x2031` @ call `0x0081589c` (reconfirm wave2) |
| **Packet in EAX / client in ECX (`__fastcall`)** | **High / Confirmed** | Call site `MOV EAX,ESI; MOV ECX,EBP; CALL` (image reconfirm wave2) |
| Empty stub previously non-authoritative | **High** | Clean now single full body |
| Residual FUN_* product names | **Open** | Roles documented; `0x005538a0` already `_Inferred`; leave remaining FUN_* without string/RTTI |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Entry helper + status gate | **Yes** |
| Error HB abort type8 + chat return | **Yes** |
| BUSY silent return under +0x6b9 | **Yes** |
| Source resolve + local-caster flag | **Yes** |
| 0x11 remove path | **Yes** |
| Target mana-short loop | **Yes** |
| Unresolved-source `'c'` side-path | **Yes** |
| Resolved-source ApplyStatusEffectLocal + item CD | **Yes** |
| No invented modernization branches | **Yes** |
| Prior empty stub removed; single CF body | **Yes** |

---

## 5. Opcode / dispatch residual seal (2026-07-29; reconfirm wave2)

| Evidence | Result |
|---|---|
| `get_function_xrefs(0x00811170)` | **Only** `From 0081589c in Client_PacketDispatch` |
| PacketDispatch decompile | `case 0x2031: Client_RecvSkillStatusEffect(...)` then `return 1` |
| Call site asm @ `0x00815898` | `mov eax,esi; mov ecx,ebp; call 0x00811170` |
| Image bytes (`read_memory` wave2) | `8b c6 8b cd e8 cf b8 ff ff 5f 5e 5d b0 01 …` (`return 1` via `MOV AL,1`) |
| AutoCore | `GameOpcode.SkillStatusEffect = 0x2031` |

Body never hardcodes the opcode (correct for dispatched handlers). Opcode binding is **body-external** and **sealed**.

Chain: `reviews/CHAIN_2026-07-29_s2c_2031_skillstatuseffect.md`.

---

## 5b. ApplyEffects path residual seal (wave2 2026-07-29)

**Gate into path:** `status@+0x14 == 'c'(0x63)` **and** `Object_ResolveFromTFID(source@+0x28) == null`.  
If source resolves → this path is **not** taken; `Skill_ApplyStatusEffectLocal` runs instead (and may call ApplyEffects when `lDelayTime < 1`).

**Pre-call (body):**

1. `skill = CVOGReaction_ResolveSkillTargets(skillId@+8, level@+0xC)`
2. Copy `pos` from `pkt+0x18..+0x20` into stack TFID/pos shell
3. `nTargets = (uiSize@+4 - 0x40) / 0x18`; `operator_new__(n << 4)` compact TFID heap
4. Copy each target entry: first **16 bytes** of each 0x18-stride wire slot (`+0x40` step 6 dwords)

**Call site asm @ `0x00811638` → `0x005538a0` (`get_assembly_context` wave2):**

| Step | Asm | Meaning |
|---|---|---|
| | `MOV ECX, [EBX+0x3c]` / `PUSH ECX` | dice seed (last formal) |
| | `LEA EDX, [ESP+…]` / `PUSH EDX` | `&pos` |
| | `PUSH EAX` | compact TFID heap |
| | `MOV EAX, [ESI+0xe04]` / `PUSH EAX` | world = **client+0xe04** |
| | `PUSH 0` | **caster = null** |
| | `MOV ESI, [stack skill]` / `MOV ECX, ESI` | **this = skill** (thiscall) |
| | `CALL 0x005538a0` | ApplyEffects |

**Sealed prototype at this site:**

```c
/* __thiscall */ Skill_ApplyEffectsOnTarget_Inferred(
    skill,                 /* ECX — from ResolveSkillTargets */
    /*caster*/ NULL,       /* PUSH 0 */
    /*world*/  *(void**)(pClientCtx + 0xe04),
    /*targets*/ tfidHeap,  /* compact 16B × n */
    /*pos*/    &posFromPkt18,
    /*seed*/   *(uint*)(pkt + 0x3c));
```

**Contrast — ApplyStatusEffectLocal immediate-apply site (`0x0051ae58`):**

```c
Skill_ApplyEffectsOnTarget_Inferred(
    skill, pCasterObj, *(void**)(pCasterObj + 0xa4), tfidHeap, &pos, seed);
```

| Site | caster | world expression |
|---|---|---|
| Recv null+`'c'` | **null** | `client+0xe04` |
| ApplyStatusEffectLocal delay&lt;1 | **pCasterObj** | `caster+0xa4` |

**Xrefs to ApplyEffects (`0x005538a0`):** Recv `0x00811638`, ApplyStatusEffectLocal `0x0051ae58`, `FUN_00514e70`, `FUN_00606180`, `FUN_00620480` — Recv is a **first-class** caller, not only via ApplyStatusEffectLocal.

**Clean-plate fix (wave2):** prior clean call dropped skill `this` and started with `0` as first shown arg (legacy non-thiscall decomp shape). Corrected to six-arg thiscall matching asm.

**`'c'` emit note:** local packer `CVOGReaction_CastSkillOnTarget` writes status `0` or `'c'(99)` from `param_10` only — so `'c'` is a **real packer domain value**, not folklore. Full sector server emit matrix still open.

---

## 6. FUN residual surface (roles; product names open)

Decompiles of residual callees (2026-07-29). **Do not invent product names** without strings/RTTI.

| Address | Role (evidence-only) | Conf |
|---|---|---|
| `FUN_007a69d0` | Singleton getter `&DAT_00d1f660` (one-shot init) | High CF |
| `FUN_007a4480` | Filtered debug log → `vog_LogMessage` / `NDError.cpp` (level==1) | High string |
| `FUN_00514e00` | Dec refcount at nested `*(+0x64)+0x10`; clear `+0xc` at zero | High CF |
| `FUN_004294f0` | List traversal **lock enter** (`EnterCriticalSection`, flag `+0x28`) | High string `"TraversalLock"` |
| `FUN_004022a0` | List **next** under `TryEnterCriticalSection` | High CF |
| `FUN_0040c700` | List **unlock** `LeaveCriticalSection` | High CF |
| `FUN_00418b80` | `std::map` lower_bound/find by int key | High CF |
| `FUN_00418890` | map find sibling | High CF |
| `FUN_004188e0` | map erase | High string `"invalid map/set<T> iterator"` |
| `FUN_0054b480` | Global map singleton `&DAT_00b04734` (**≠** `Skill_GetCategoryCooldownMap` @ `0x00518d70`) | High CF |
| `0x005538a0` | **`Skill_ApplyEffectsOnTarget_Inferred`** — shared cast/combat apply (floaters, vtbl `+0x238`); also from ApplyStatusEffectLocal | High (named `_Inferred`) |
| `FUN_007a6de0` | Localized string table lookup (`"Server says"`) | High usage |
| `FUN_008f8200` | Chat-log channel append into `CDlgChatLog` | High CF |
| `FUN_007fb640` | UI dismiss helper (`client+0x1120` gate) | Probable |

HB walk trio (`FUN_004294f0` / `FUN_004022a0` / `FUN_0040c700`) is a locked-list scaffold around type-8 cast-again abort — roles High; product type name open.

---

## 7. Gaps / open questions

1. ~~Opcode seal~~ **Closed 2026-07-29** — PacketDispatch case `0x2031` + sole xref + call site (reconfirm wave2).
2. ~~Register framing~~ **Closed 2026-07-29** — EAX=packet (ESI), ECX=client (EBP) (reconfirm wave2).
3. ~~ApplyEffects call-site arg map~~ **Closed wave2** — thiscall skill + null caster + world/`targets`/pos/seed sealed via asm.
4. **`'c'(0x63)` sector-server emit matrix** — packer can write it (`param_10`); full live/server table open; not in public `eSkillResponses` plate.
5. **Product names for residual FUN_*** — roles sealed; `0x005538a0` already `Skill_ApplyEffectsOnTarget_Inferred`. Priority remaining: `FUN_00514e00`, list-lock/map family, `FUN_0054b480`.
6. **`nInferred` / `extraout_*` residuals** — decompiler register noise into `Skill_ApplyStatusEffectLocal` args.
7. **World pointer identity** — Recv uses `client+0xe04`; ApplyStatusEffectLocal uses `caster+0xa4`; same conceptual world? open.
8. Runtime cast success/fail capture still open.

**Verdict:** Clean plate is full-body CF-faithful (ApplyEffects thiscall **fixed wave2**). Opcode + framing + ApplyEffects path sealed. FUN residual **roles** documented without inventing names. **accept-with-gaps.**
