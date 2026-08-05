# Annotated low-level: Client_RecvSkillStatusEffect

| Field | Value |
|---|---|
| **Stable ID** | `aa_00811170` |
| **VA** | `0x00811170` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | skills-abilities |
| **Source raw** | `aa_00811170_Client_RecvSkillStatusEffect.md` |
| **Refine** | Human pass 2026-07-23 (named_hl keyword wave); opcode/FUN residual 2026-07-29; ApplyEffects thiscall wave2 |

This file is the **annotated** layer: packet/UI offsets, branch order, and decompiler corrections.

---

## 1. Purpose

S2C skill status-effect / cast result. Validates eSkillResponses, aborts cast-again heartbeat on hard failures, applies mana shorts and Skill_ApplyStatusEffectLocal.

## 2. Corrected signature (framing sealed 2026-07-29)

```c
void __fastcall Client_RecvSkillStatusEffect(void *pClientCtx);  /* ECX = client */
/* packet buffer in EAX — call site 0x00815898: MOV EAX,ESI; MOV ECX,EBP; CALL */
```

## 3. Key offsets / packet fields

| Offset / symbol | Role |
|---|---|
| `pkt+0x08` | skillId |
| `pkt+0x0C` | level |
| `pkt+0x10` | lDelayTime |
| `pkt+0x14` | eSkillResponses / status |
| `pkt+0x18` | world position |
| `pkt+0x28` | source TFID |
| `pkt+0x38` | bIsItemSkill |
| `pkt+0x40` | targets array |

## 4. Machine-level notes

- Packet: +0x08 skillId, +0x0C level, +0x10 lDelayTime (charge remainder, not CD), +0x14 eSkillResponses, +0x18 pos, +0x28 source TFID (character for local-caster match), +0x38 bIsItemSkill, +0x3c dice seed, +0x40 targets[] (0x18 stride: TFID + mana/maxMana shorts).
- Allowed status set includes 0, 'c'(0x63), 0x11 (CANCELLED_ACTIVE); others abort cast-again HB type8 + category CD map and show chat error.
- Cross-checked vs CVOGReaction_CastSkillOnTarget packer + SMSG_Sector_SkillStatusEffect (size 0x9a0).
- **Opcode S2C 0x2031 sealed 2026-07-29:** sole function xref is `Client_PacketDispatch` case `0x2031` @ call `0x0081589c` (body does not compare opcode — correct).
- **Register framing sealed:** EAX=packet (ESI), ECX=client (EBP); image `8b c6 8b cd e8 cf b8 ff ff`.
- Residual FUN_* **roles** documented in dual A/B + `CHAIN_2026-07-29_s2c_2031_skillstatuseffect.md` (product names open).
- Large function — full target loop retained in raw; clean is full body (empty stub removed 2026-07-28).

## 5. Pseudocode (authoritative raw, retained)

```c
/* Client_RecvSkillStatusEffect(pClientCtx)

   

   Parameters:

     pClientCtx - client/game context (thiscall/fastcall ECX)

     Packet in EAX-relative buffer (in_EAX in decomp):

       +0x08 skillId  +0x0C level  +0x10 lDelayTime  +0x14 eSkillResponses

       +0x18 pos  +0x28 source TFID  +0x38 bIsItemSkill  +0x40 targets[]

   

   Algorithm:

     if status not in {0,'c',0x11}: abort cast-again HB type8 + category map; chat error

     else resolve source, apply target mana shorts, Skill_ApplyStatusEffectLocal

   

   Returns: void

   

   VERIFIED packet offsets vs CVOGReaction_CastSkillOnTarget packer. */



void __fastcall Client_RecvSkillStatusEffect(void *pClientCtx)



{

  byte *pbVar1;

  undefined2 uVar2;

  undefined4 *puVar3;

  char cVar4;

  void *in_EAX;

  int *piVar5;

  void *pvVar6;

  char *pcVar7;

  undefined4 uVar8;

  int iVar9;

  int iVar10;

  uint extraout_ECX;

  uint uVar11;

  uint extraout_ECX_00;

  uint extraout_ECX_01;

  undefined2 extraout_var;

  uint *puVar12;

  undefined2 extraout_var_00;

  int nInferred;

  TFID_16 *pTVar13;

  undefined4 uVar14;

  char *pcVar15;

  TFID_16 **ppTVar16;

  int **ppiVar17;

  undefined4 uVar18;

  undefined4 local_234;

  undefined4 uStack_230;

  int *local_22c;

  TFID_16 *local_228;

  undefined4 *local_224;

  TFID_16 local_220;

  char local_210 [256];

  char local_110 [268];

  

                    /* // Get effect type from packet+0x14 */

                    /* // Validate effect type (0=normal, 'c'=cast, '\x11'=remove) */

  local_224 = (undefined4 *)FUN_007a69d0();

  cVar4 = *(char *)((int)in_EAX + 0x14);

  if (((cVar4 != '\0') && (cVar4 != 'c')) && (cVar4 != '\x11')) {

                    /* // Check if target matches current skill target */

    if (*(char *)(*(int *)((int)pClientCtx + 0xe98) + 0x6b9) == '\0') {

                    /* ERROR path: status not ok/'c'/cancel → abort cast-again HB + category map

                       for this skillId */

      FUN_007a4480(0,"Skill %d had error: %d. Aborting cooldown.\n",*(undefined4 *)((int)in_EAX + 8)

                   ,cVar4);

                    /* // Effect type '\x11' (remove): call vtable +0x220 on target */

      FUN_00514e00();

      local_22c = (int *)0x0;

      FUN_004294f0();

      FUN_004022a0(&local_22c,&local_234);

      while (local_234 != (void *)0x0) {

        if ((*(int *)((int)local_234 + 0x1c) == 8) &&

           (piVar5 = (int *)__RTDynamicCast(local_234,0,&CVOGHBBase::RTTI_Type_Descriptor,

                                            &CVOGHBOKToCastAgain::RTTI_Type_Descriptor,0),

           *(int *)(piVar5[9] + 0x5fc) == *(int *)((int)in_EAX + 8))) {

          local_234 = Skill_GetCategoryCooldownMap

                                ((void *)(*(int *)(*(int *)(*(int *)((int)pClientCtx + 0xe98) + 4) +

                                                  4) + 4 + *(int *)((int)pClientCtx + 0xe98)));

          local_228 = *(TFID_16 **)(piVar5[9] + 0x5e8);

          FUN_00418b80(&local_22c,&local_228);

          if (local_22c != *(int **)((int)local_234 + 4)) {

            FUN_004188e0(&local_228,local_22c);

          }

          FUN_0040c700();

          (**(code **)(*piVar5 + 0x18))(1,1);

          goto LAB_008112c3;

        }

        FUN_004022a0(&local_22c,&local_234);

      }

      FUN_0040c700();

LAB_008112c3:

      local_228 = (TFID_16 *)

                  (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)pClientCtx + 0xe98) + 4) + 4

                                                ) + 4 + *(int *)((int)pClientCtx + 0xe98)) + 0x234))

                            (*(undefined4 *)((int)in_EAX + 8));

      if (local_228 != (TFID_16 *)0x0) {

        piVar5 = *(int **)((int)pClientCtx + 0x10b0);

        if ((piVar5 != (int *)0x0) && (cVar4 = (**(code **)(*piVar5 + 0x3d8))(), cVar4 != '\0')) {

          (**(code **)(*piVar5 + 0x450))(local_228);

        }

        FUN_007fb640();

      }

    }

    else {

      FUN_00514e00();

      if (*(char *)((int)in_EAX + 0x14) == '\x06') {

        return;

      }

    }

    if (*(int *)((int)pClientCtx + 0xe98) == 0) {

      pvVar6 = (void *)0x0;

    }

    else {

      pvVar6 = (void *)(*(int *)(*(int *)(*(int *)((int)pClientCtx + 0xe98) + 4) + 4) + 4 +

                       *(int *)((int)pClientCtx + 0xe98));

    }

    pcVar7 = Skill_FormatFailureMessage((uint)*(byte *)((int)in_EAX + 0x14),local_110,pvVar6);

    uVar8 = FUN_007a6de0("Server says",0xffffffff);

    sprintf(local_210,"%s: %s",uVar8,pcVar7);

    uVar18 = 0;

    pcVar7 = local_210;

    pcVar15 = "[System]";

    uVar14 = 6;

    uVar8 = __RTDynamicCast(*(undefined4 *)((int)pClientCtx + 0x109c),0,

                            &CVOGDialog::RTTI_Type_Descriptor,&CDlgChatLog::RTTI_Type_Descriptor,0,6

                            ,"[System]",pcVar7,0);

    FUN_008f8200(uVar8,uVar14,pcVar15,pcVar7,uVar18);

    return;

  }

  local_22c = Object_ResolveFromTFID((TFID_16 *)((int)in_EAX + 0x28));

  uVar11 = extraout_ECX;

  if (*(int *)((int)pClientCtx + 0xe98) != 0) {

    puVar12 = (uint *)(*(int *)(*(int *)(*(int *)((int)pClientCtx + 0xe98) + 4) + 4) + 0x164 +

                      *(int *)((int)pClientCtx + 0xe98));

    uVar11 = ((TFID_16 *)((int)in_EAX + 0x28))->dwCoidLo;

    if ((uVar11 == *puVar12) && (uVar11 = *(uint *)((int)in_EAX + 0x2c), uVar11 == puVar12[1])) {

      uVar11 = CONCAT31((int3)(uVar11 >> 8),*(char *)((int)in_EAX + 0x30));

      uStack_230 = (void *)CONCAT13(1,(undefined3)uStack_230);

      if (*(char *)((int)in_EAX + 0x30) == (char)puVar12[2]) goto LAB_0081146c;

    }

  }

  uStack_230 = (void *)((uint)uStack_230 & 0xffffff);

LAB_0081146c:

  if (*(char *)((int)in_EAX + 0x14) == '\x11') {

    FUN_00514e00();

    piVar5 = local_22c;

    Skill_LookupActiveCastBinding(&local_220,*(int *)((int)in_EAX + 8));

    if (((piVar5 != (int *)0x0) &&

        (iVar9 = TFID_NotEquals(&local_220,&DAT_00a1e840), (char)iVar9 != '\0')) &&

       (piVar5 = Object_ResolveFromTFID(&local_220), piVar5 != (int *)0x0)) {

      (**(code **)(*piVar5 + 0x220))(*(undefined4 *)((int)in_EAX + 8),0);

      return;

    }

  }

  else {

    for (pTVar13 = (TFID_16 *)((int)in_EAX + 0x40);

        (local_234 = pTVar13, (pTVar13->dwCoidLo & pTVar13->dwCoidHi) != 0xffffffff ||

        (pTVar13->bGlobal != 0)); pTVar13 = (TFID_16 *)&pTVar13[1].bGlobal) {

      piVar5 = Object_ResolveFromTFID(pTVar13);

      uVar11 = extraout_ECX_00;

      if ((piVar5 != (int *)0x0) &&

         (piVar5 = (int *)(**(code **)(*piVar5 + 0x214))(), uVar11 = extraout_ECX_01,

         pTVar13 = local_234, piVar5 != (int *)0x0)) {

        (**(code **)(*piVar5 + 0xac))(CONCAT22(extraout_var_00,(short)local_234[1].dwCoidLo));

        uVar2 = *(undefined2 *)((int)&local_234[1].dwCoidLo + 2);

        uVar11 = CONCAT22(extraout_var,uVar2);

        pbVar1 = (byte *)(*(int *)(piVar5[1] + 4) + 0x180 + (int)piVar5);

        *pbVar1 = *pbVar1 | 0x80;

        *(undefined2 *)((int)piVar5 + 0x12e) = uVar2;

        pTVar13 = local_234;

      }

    }

    if (local_22c == (int *)0x0) {

      if (*(char *)((int)in_EAX + 0x14) == 'c') {

        local_224 = CVOGReaction_ResolveSkillTargets

                              (*(void **)((int)in_EAX + 8),

                               CONCAT22((short)(uVar11 >> 0x10),*(undefined2 *)((int)in_EAX + 0xc)))

        ;

        local_220.dwCoidLo = *(uint *)((int)in_EAX + 0x18);

        local_220.dwCoidHi = *(uint *)((int)in_EAX + 0x1c);

        piVar5 = (int *)((*(ushort *)((int)in_EAX + 4) - 0x40) / 0x18);

        local_220._8_4_ = *(undefined4 *)((int)in_EAX + 0x20);

        local_220.bPad3 = 0;

        local_220.bPad4 = 0;

        local_220.bPad5 = 0;

        local_220.bPad6 = 0;

        local_228 = operator_new__((int)piVar5 << 4);

        puVar3 = local_224;

        if (piVar5 != (int *)0x0) {

          puVar12 = (uint *)((int)in_EAX + 0x40);

          local_234 = local_228;

          local_22c = piVar5;

          do {

            pTVar13 = local_234 + 1;

            local_234->dwCoidLo = *puVar12;

            local_234->dwCoidHi = puVar12[1];

            uVar11 = puVar12[2];

            local_234->bGlobal = (char)uVar11;

            local_234->bPad0 = (char)(uVar11 >> 8);

            local_234->bPad1 = (char)(uVar11 >> 0x10);

            local_234->bPad2 = (char)(uVar11 >> 0x18);

            uVar11 = puVar12[3];

            puVar12 = puVar12 + 6;

            local_22c = (int *)((int)local_22c - 1);

            local_234->bPad3 = (char)uVar11;

            local_234->bPad4 = (char)(uVar11 >> 8);

            local_234->bPad5 = (char)(uVar11 >> 0x10);

            local_234->bPad6 = (char)(uVar11 >> 0x18);

            local_234 = pTVar13;

          } while (local_22c != (int *)0x0);

          local_22c = (int *)0x0;

        }

        FUN_005538a0(0,*(undefined4 *)((int)pClientCtx + 0xe04),local_228,&local_220,

                     *(undefined4 *)((int)in_EAX + 0x3c));

        if (local_228 != (TFID_16 *)0x0) {

          operator_delete__(local_228);

        }

        if (puVar3 != (undefined4 *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(puVar3);

        }

      }

    }

    else {

      (**(code **)(*local_22c + 0x218))(*(undefined4 *)((int)pClientCtx + 0xe04));

      if ((local_234._3_1_ == '\0') || (*(char *)((int)in_EAX + 0x38) != '\0')) {

        cVar4 = '\0';

      }

      else {

        cVar4 = '\x01';

      }

      Skill_ApplyStatusEffectLocal(uStack_230,nInferred,in_EAX,cVar4);

      if ((*(char *)((int)in_EAX + 0x38) != '\0') && (*(int *)((int)pClientCtx + 0xe98) != 0)) {

        iVar9 = (int)in_EAX + 8;

        ppTVar16 = &local_228;

        FUN_0054b480(ppTVar16,iVar9);

        piVar5 = (int *)FUN_00418890(ppTVar16,iVar9);

        iVar9 = *piVar5;

        iVar10 = FUN_0054b480();

        if (iVar9 != *(int *)(iVar10 + 4)) {

          local_228 = *(TFID_16 **)(iVar9 + 0x5f8);

          ppTVar16 = &local_228;

          ppiVar17 = &local_22c;

          Skill_GetCategoryCooldownMap

                    ((void *)(*(int *)(*(int *)(*(int *)((int)pClientCtx + 0xe98) + 4) + 4) + 4 +

                             *(int *)((int)pClientCtx + 0xe98)));

          FUN_00418b80(ppiVar17,ppTVar16);

          pvVar6 = Skill_GetCategoryCooldownMap

                             ((void *)(*(int *)(*(int *)(*(int *)((int)pClientCtx + 0xe98) + 4) + 4)

                                       + 4 + *(int *)((int)pClientCtx + 0xe98)));

          if (local_22c == *(int **)((int)pvVar6 + 4)) {

            return;

          }

        }

      }

      if (((local_234._3_1_ != '\0') &&

          (piVar5 = *(int **)((int)pClientCtx + 0x10b0), piVar5 != (int *)0x0)) &&

         (cVar4 = (**(code **)(*piVar5 + 0x3d8))(), cVar4 != '\0')) {

        (**(code **)(*piVar5 + 0x450))(0);

      }

    }

  }

  return;

}
```

## 6. Open questions

- Enumerate live **sector-server** emitted `eSkillResponses` beyond gate set; when is `'c'(0x63)` used on the wire? (`0x11` = CANCELLED_ACTIVE=17; local packer `CastSkillOnTarget` can write 0/`'c'` from `param_10`.)
- ~~Seal PacketDispatch register framing~~ **Closed 2026-07-29** — EAX=packet, ECX=client @ `0x00815898`.
- ~~ApplyEffects call-site thiscall map~~ **Closed wave2** — see §7.
- Unresolved callees (do **not** invent names without strings/xrefs):
  - `FUN_007a69d0` entry helper
  - `FUN_007a4480` debug log (has format string)
  - `FUN_00514e00` repeated pre-branch helper
  - `FUN_004294f0` / `FUN_004022a0` / `FUN_0040c700` HB list walk scaffolding
  - `FUN_00418b80` / `FUN_004188e0` / `FUN_00418890` / `FUN_0054b480` map family
  - `FUN_007fb640` post-error UI
  - `FUN_007a6de0` string table ("Server says")
  - `FUN_008f8200` chat append
  - ~~`FUN_005538a0`~~ → **`Skill_ApplyEffectsOnTarget_Inferred`** (role sealed; product string open)
- World alias `client+0xe04` vs `caster+0xa4`
- Runtime success / reject / cancel capture.

---

## 7. Wave2 correction — ApplyEffects thiscall (2026-07-29)

**Problem:** historical decomp/clean showed:

```c
FUN_005538a0(0, *(client+0xe04), local_228, &local_220, dice);
```

That is the **stack-only** shape after rename to `__thiscall`. Live asm @ `0x00811638`:

```
PUSH dice; PUSH &pos; PUSH heap; PUSH world(client+0xe04); PUSH 0 /*caster*/;
MOV ECX, skill; CALL 0x005538a0
```

**Correct call:**

```c
Skill_ApplyEffectsOnTarget_Inferred(
    skill,              /* ECX this — ResolveSkillTargets */
    /*caster*/ NULL,
    /*world*/  *(void**)(pClientCtx + 0xe04),
    /*targets*/ heap,
    /*pos*/    &pos,
    /*seed*/   *(uint*)(pkt + 0x3c));
```

Gate: source TFID unresolved **and** status `'c'`. Resolved source uses `Skill_ApplyStatusEffectLocal` instead (ApplyEffects only if delay&lt;1 **inside** that callee, with non-null caster + world `caster+0xa4`).

Authoritative dual: `reviews/A|B_aa_00811170_*` §5b; chain `CHAIN_2026-07-29_s2c_2031_skillstatuseffect.md`; clean plate fixed.
