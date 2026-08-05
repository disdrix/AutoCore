// READABILITY (auto CF):
//  - Body size: ~256 non-empty decompiler lines.
//  - Control keywords: if×26, return×6, for×2, while×2, goto×2, do×1.
//  - Notable named callees: Object_ResolveFromTFID, Skill_ApplyStatusEffectLocal,
//    Skill_GetCategoryCooldownMap, Skill_FormatFailureMessage, Skill_LookupActiveCastBinding,
//    CVOGReaction_ResolveSkillTargets, TFID_NotEquals, CVOGHBOKToCastAgain RTTI.
//  - Residual FUN_* (roles sealed 2026-07-29; product names open — do not invent):
//      FUN_007a69d0 singleton DAT_00d1f660; FUN_007a4480 vog_LogMessage/NDError;
//      FUN_00514e00 nested refcount dec; FUN_004294f0/004022a0/0040c700 list lock/next/unlock;
//      FUN_00418b80/00418890/004188e0 map find/find/erase;
//      FUN_0054b480 global map &DAT_00b04734 (≠ GetCategoryCooldownMap);
//      Skill_ApplyEffectsOnTarget_Inferred (was FUN_005538a0) on 'c' path;
//      FUN_007a6de0 string table; FUN_008f8200 chat append; FUN_007fb640 UI dismiss.
//  - Strings: "Skill %d had error: %d. Aborting cooldown.\n"; "Server says"; "%s: %s"; "[System]".
//  - Return sites: 6.

// =============================================================================
// Client_RecvSkillStatusEffect
// -----------------------------------------------------------------------------
// Stable ID: aa_00811170
// Address:   0x00811170  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Opcode:    S2C 0x2031 SkillStatusEffect — SEALED 2026-07-29
//            Sole xref: Client_PacketDispatch case 0x2031 @ call 0x0081589c
//            Body does not hardcode opcode (dispatch external — correct)
// Generated: 2026-07-28 human-refined; 2026-07-29 opcode/FUN residual plate;
//            2026-07-29 wave2 ApplyEffects thiscall fix (skill ECX + null caster)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Chain:     reviews/CHAIN_2026-07-29_s2c_2031_skillstatuseffect.md
// =============================================================================

/*
 * S2C skill status-effect / cast result handler.
 *
 * Signature (framing sealed 2026-07-29 via call-site image):
 *   void __fastcall Client_RecvSkillStatusEffect(void *pClientCtx);  // ECX
 *   Packet buffer arrives in EAX (in_EAX).
 *   Call site 0x00815898: MOV EAX,ESI; MOV ECX,EBP; CALL 0x00811170
 *   (bytes: 8b c6  8b cd  e8 cf b8 ff ff)
 *
 * Packet (SMSG_Sector_SkillStatusEffect, size 0x9a0) — verified vs
 * CVOGReaction_CastSkillOnTarget packer + PACKET STRUCTURES:
 *   +0x04  uiSize (ushort used for target-count derivation)
 *   +0x08  lSkillID
 *   +0x0C  iSkillLevel (ushort)
 *   +0x10  lDelayTime (remaining charge/cast delay — NOT cooldown)
 *   +0x14  eSkillResponses / status (u8)
 *   +0x18  world position (float3)
 *   +0x28  source TFID (fidSource) — character coid for learned casts, not vehicle
 *   +0x38  bIsItemSkill
 *   +0x3c  lDiceSeed
 *   +0x40  arrTargets[] — 0x18-byte entries {TFID, int16 mana, int16 maxMana, pad}
 *
 * Status gate (entry): only {0, 'c'(0x63), 0x11} continue to apply path.
 *   0    = SKILL_RESPONSE_OK
 *   0x11 = SKILL_RESPONSE_CANCELLED_ACTIVE (17) — remove / cancel-active branch
 *   'c'  = 0x63 — cast side-path when source TFID fails resolve (not in public enum plate)
 * Everything else → error path (abort cast-again HB type 8 matching skillId + system chat).
 * Special early return inside error arm when char+0x6b9 != 0 and status == 0x06 (BUSY).
 *
 * Client ctx offsets used:
 *   +0xe04  active-effects / apply context arg
 *   +0xe98  local character *
 *   +0x109c dialog root (CDlgChatLog cast for failure chat)
 *   +0x10b0 UI component (vtbl +0x3d8 gate, +0x450 update)
 *
 * IMPORTANT: Empty stub was previously present above the body — non-authoritative.
 * This single function body is the CF source of truth (matches raw).
 */

/* Client_RecvSkillStatusEffect(pClientCtx)

   Parameters:
     pClientCtx - client/game context (thiscall/fastcall ECX)
     Packet in EAX-relative buffer (in_EAX in decomp)

   Algorithm:
     if status not in {0,'c',0x11}: abort cast-again HB type8 + category map; chat error
     else resolve source, apply target mana shorts;
          if source null && status 'c': Skill_ApplyEffectsOnTarget_Inferred (thiscall sealed)
          else if source resolved: Skill_ApplyStatusEffectLocal
          else if status 0x11: remove via LookupActiveCastBinding / vtbl+0x220

   Returns: void

   VERIFIED packet offsets vs CVOGReaction_CastSkillOnTarget packer.
   ApplyEffects thiscall arg map sealed 2026-07-29 wave2 via call-site asm. */

void __fastcall Client_RecvSkillStatusEffect(void *pClientCtx)
{
  byte *pbVar1;
  uint16_t uVar2;
  uint32_t /* decomp width */ *puVar3;
  char cVar4;
  void *in_EAX;
  int *piVar5;
  void *pvVar6;
  char *pcVar7;
  uint32_t /* decomp width */ uVar8;
  int iVar9;
  int iVar10;
  uint extraout_ECX;
  uint uVar11;
  uint extraout_ECX_00;
  uint extraout_ECX_01;
  uint16_t extraout_var;
  uint *puVar12;
  uint16_t extraout_var_00;
  int nInferred;
  TFID_16 *pTVar13;
  uint32_t /* decomp width */ uVar14;
  char *pcVar15;
  TFID_16 **ppTVar16;
  int **ppiVar17;
  uint32_t /* decomp width */ uVar18;
  uint32_t /* decomp width */ local_234;
  uint32_t /* decomp width */ uStack_230;
  int *local_22c;
  TFID_16 *local_228;
  uint32_t /* decomp width */ *local_224;
  TFID_16 local_220;
  char local_210 [256];
  char local_110 [268];

                    /* entry helper (FUN_007a69d0 — unresolved) */
                    /* status = packet+0x14; allow only 0 / 'c' / 0x11 */
  local_224 = (uint32_t /* decomp width */ *)FUN_007a69d0();
  cVar4 = *(char *)((int)in_EAX + 0x14);
  if (((cVar4 != '\0') && (cVar4 != 'c')) && (cVar4 != '\x11')) {
                    /* ---- ERROR path: status not ok / 'c' / cancel-active ---- */
    if (*(char *)(*(int *)((int)pClientCtx + 0xe98) + 0x6b9) == '\0') {
                    /* abort cast-again HB type8 matching skillId@+8 + category CD map */
      FUN_007a4480(0,"Skill %d had error: %d. Aborting cooldown.\n",*(uint32_t /* decomp width */ *)((int)in_EAX + 8)
                   ,cVar4);
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
                    /* skill-def vcall +0x234(skillId); optional UI refresh */
      local_228 = (TFID_16 *)
                  (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)pClientCtx + 0xe98) + 4) + 4
                                                ) + 4 + *(int *)((int)pClientCtx + 0xe98)) + 0x234))
                            (*(uint32_t /* decomp width */ *)((int)in_EAX + 8));
      if (local_228 != (TFID_16 *)0x0) {
        piVar5 = *(int **)((int)pClientCtx + 0x10b0);
        if ((piVar5 != (int *)0x0) && (cVar4 = (**(code **)(*piVar5 + 0x3d8))(), cVar4 != '\0')) {
          (**(code **)(*piVar5 + 0x450))(local_228);
        }
        FUN_007fb640();
      }
    }
    else {
                    /* char+0x6b9 set: skip HB abort; BUSY(0x06) silent return */
      FUN_00514e00();
      if (*(char *)((int)in_EAX + 0x14) == '\x06') {
        return;
      }
    }
                    /* format failure + "[System] Server says: …" chat */
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
    uVar8 = __RTDynamicCast(*(uint32_t /* decomp width */ *)((int)pClientCtx + 0x109c),0,
                            &CVOGDialog::RTTI_Type_Descriptor,&CDlgChatLog::RTTI_Type_Descriptor,0,6
                            ,"[System]",pcVar7,0);
    FUN_008f8200(uVar8,uVar14,pcVar15,pcVar7,uVar18);
    return;
  }

                    /* ---- SUCCESS-like path: status in {0, 'c', 0x11} ---- */
  local_22c = Object_ResolveFromTFID((TFID_16 *)((int)in_EAX + 0x28));
  uVar11 = extraout_ECX;
                    /* local-caster match: source TFID vs character+0x164 (not vehicle) */
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
                    /* cancel-active / remove: vtbl +0x220 on active-cast binding target */
    FUN_00514e00();
    piVar5 = local_22c;
    Skill_LookupActiveCastBinding(&local_220,*(int *)((int)in_EAX + 8));
    if (((piVar5 != (int *)0x0) &&
        (iVar9 = TFID_NotEquals(&local_220,&DAT_00a1e840), (char)iVar9 != '\0')) &&
       (piVar5 = Object_ResolveFromTFID(&local_220), piVar5 != (int *)0x0)) {
      (**(code **)(*piVar5 + 0x220))(*(uint32_t /* decomp width */ *)((int)in_EAX + 8),0);
      return;
    }
  }
  else {
                    /* target loop @+0x40: mana shorts + flag bit7 @ entity+0x180 / +0x12e */
    for (pTVar13 = (TFID_16 *)((int)in_EAX + 0x40);
        (local_234 = pTVar13, (pTVar13->dwCoidLo & pTVar13->dwCoidHi) != 0xffffffff ||
        (pTVar13->bGlobal != 0)); pTVar13 = (TFID_16 *)&pTVar13[1].bGlobal) {
      piVar5 = Object_ResolveFromTFID(pTVar13);
      uVar11 = extraout_ECX_00;
      if ((piVar5 != (int *)0x0) &&
         (piVar5 = (int *)(**(code **)(*piVar5 + 0x214))(), uVar11 = extraout_ECX_01,
         pTVar13 = local_234, piVar5 != (int *)0x0)) {
        (**(code **)(*piVar5 + 0xac))(CONCAT22(extraout_var_00,(short)local_234[1].dwCoidLo));
        uVar2 = *(uint16_t *)((int)&local_234[1].dwCoidLo + 2);
        uVar11 = CONCAT22(extraout_var,uVar2);
        pbVar1 = (byte *)(*(int *)(piVar5[1] + 4) + 0x180 + (int)piVar5);
        *pbVar1 = *pbVar1 | 0x80;
        *(uint16_t *)((int)piVar5 + 0x12e) = uVar2;
        pTVar13 = local_234;
      }
    }
    if (local_22c == (int *)0x0) {
                    /* source TFID unresolved: 'c' cast side-path via ResolveSkillTargets */
      if (*(char *)((int)in_EAX + 0x14) == 'c') {
        local_224 = CVOGReaction_ResolveSkillTargets
                              (*(void **)((int)in_EAX + 8),
                               CONCAT22((short)(uVar11 >> 0x10),*(uint16_t *)((int)in_EAX + 0xc)))
        ;
        local_220.dwCoidLo = *(uint *)((int)in_EAX + 0x18);
        local_220.dwCoidHi = *(uint *)((int)in_EAX + 0x1c);
        piVar5 = (int *)((*(ushort *)((int)in_EAX + 4) - 0x40) / 0x18);
        local_220._8_4_ = *(uint32_t /* decomp width */ *)((int)in_EAX + 0x20);
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
                    /* Skill_ApplyEffectsOnTarget_Inferred (0x005538a0) — null-source + 'c' side-path.
                     * Thiscall sealed 2026-07-29 via call-site asm @ 0x00811638:
                     *   ECX = skill (ResolveSkillTargets); stack: caster=0, world=client+0xe04,
                     *   targets heap, &pos, dice@+0x3c.  (Prior clean omitted skill this — FIXED.) */
        Skill_ApplyEffectsOnTarget_Inferred(
            local_224,                                              /* this = skill runtime */
            (void *)0x0,                                            /* caster null */
            *(void **)((int)pClientCtx + 0xe04),                    /* world */
            local_228,                                              /* compact TFID list */
            &local_220,                                             /* pos from pkt+0x18 */
            *(uint32_t /* decomp width */ *)((int)in_EAX + 0x3c));  /* dice seed */
        if (local_228 != (TFID_16 *)0x0) {
          operator_delete__(local_228);
        }
        if (puVar3 != (uint32_t /* decomp width */ *)0x0) {
                    /* WARNING: Subroutine does not return */
          operator_delete(puVar3);
        }
      }
    }
    else {
                    /* source resolved: vtbl +0x218 then Skill_ApplyStatusEffectLocal */
      (**(code **)(*local_22c + 0x218))(*(uint32_t /* decomp width */ *)((int)pClientCtx + 0xe04));
      if ((local_234._3_1_ == '\0') || (*(char *)((int)in_EAX + 0x38) != '\0')) {
        cVar4 = '\0';
      }
      else {
        cVar4 = '\x01';
      }
      Skill_ApplyStatusEffectLocal(uStack_230,nInferred,in_EAX,cVar4);
                    /* item-skill path: category CD map update via unresolved map helpers */
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
