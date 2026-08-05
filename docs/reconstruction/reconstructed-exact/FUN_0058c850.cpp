// =============================================================================
// FUN_0058c850  (scaffold alias of Skill_ApplyMultiTargetHits_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0058c850
// Address:   0x0058c850–0x0058cc3f  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-29 W20-Q dual A/B seal
// Exactness: Scaffold keeps Ghidra name; CF = live decompile (see named clean).
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean: Skill_ApplyMultiTargetHits_Inferred.cpp
// Dual: reviews/A|B_aa_0058c850_Skill_ApplyMultiTargetHits_Inferred.md
// =============================================================================

#include <cstdint>

// PURPOSE: Multi-target TFID list skill damage apply (see named clean header).

int FUN_0058c850(
    int param_1,
    uint32_t *param_2,
    int param_3,
    uint32_t /*param_4 unused*/,
    int param_5,
    int param_6)
{
  unsigned char local_c5;
  int local_c4;
  int local_c0;
  int local_bc;
  uint32_t local_b8;
  int local_b4;
  uint32_t local_b0;
  uint32_t local_ac;
  float local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  uint32_t local_98;
  uint32_t local_94;
  unsigned char local_90;
  uint32_t local_8c;
  uint32_t local_88[4];
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  unsigned char local_60;
  unsigned char local_5e;
  uint32_t local_58;
  int local_44;
  uint32_t *puVar1;
  char cVar3;
  int iVar4;
  int *piVar5;
  uint32_t *puVar6;
  uint32_t uVar7;
  unsigned short *puVar8;
  long double fVar9;

  // SEH: ExceptionList / LAB_009a5758 (omitted)
  if (param_2 != 0) {
    // list object + dual CS (PTR_FUN_009cb368)
    local_44 = 0;
    // InitializeCriticalSection x2
    uVar7 = *param_2 & param_2[1];
    while (uVar7 != 0xffffffff) {
      iVar4 = CVOGReaction_ResolveObjectTarget((char)param_2[2], *param_2, param_2[1]);
      if (iVar4 != 0) {
        FUN_004024d0(iVar4);
        local_44 = 1;
      }
      puVar1 = param_2 + 4;
      param_2 = param_2 + 4;
      uVar7 = *puVar1 & puVar1[1];
    }
    if (local_44 != 0) {
      local_c4 = 0;
      local_bc = 0;
      piVar5 = (int *)FUN_0040b020();
      if (piVar5 != 0) {
        param_6 = param_6 * 6;
        local_c0 = param_6;
        do {
          local_c5 = 0;
          if ((local_c4 < 1) ||
              (cVar3 = (char)Skill_AccuracyHitCheck_Inferred(
                   (void *)(intptr_t)param_1, piVar5,
                   *(unsigned short *)(param_5 + (param_6 % 600) * 2), &local_c5),
               cVar3 != '\0')) {
            local_a4 = *(int *)(param_3 + 0x54);
            local_a0 = *(int *)(param_3 + 0x58);
            local_9c = *(int *)(param_3 + 0x5c);
            local_b8 = *(uint32_t *)(param_3 + 0x60);
            local_b4 = *(int *)(param_3 + 0x64);
            local_b0 = *(uint32_t *)(param_3 + 0x68);
            local_98 = 0;
            local_94 = 0;
            local_90 = 0;
            puVar8 = (unsigned short *)(param_5 + (param_6 % 600) * 2);
            if (*(char *)(param_3 + 0x140) == '\0') {
              local_8c = *(uint32_t *)(param_3 + 0x144);
              iVar4 = (*(int (**)())(*piVar5 + 0x4c))(); // retail thiscall damage method
            } else {
              iVar4 = (int)(short)local_a4 + (local_a4 >> 0x10) + (int)(short)local_a0 +
                      (local_a0 >> 0x10) + (int)(short)local_9c + (local_9c >> 0x10);
              iVar4 = (int)((unsigned long long)*puVar8 %
                            (unsigned long long)(
                                ((int)(short)local_b8 + (int)(short)local_b4 +
                                 (local_b4 >> 0x10) + (int)(short)local_b0 +
                                 ((int)local_b0 >> 0x10) + (int)(short)(local_b8 >> 0x10)) -
                                iVar4 + 1)) +
                      iVar4;
            }
            fVar9 = FUN_004cf080((void *)(intptr_t)param_1, piVar5, *puVar8);
            local_a8 = (float)fVar9;
            local_ac = 0;
            if (g_flOne < local_a8) {
              iVar4 = (int)((float)iVar4 * local_a8);
              local_ac = 1;
            }
            if (((int)(short)(local_b8 >> 0x10) > 0) ||
                ((int)(short)(local_b0 >> 0x10) > 0)) {
              piVar5[0x33] = 4;
            }
            Client_Combat_ApplySingleHitMaybeDefer_Inferred(
                local_ac, iVar4, (void *)(intptr_t)param_1, piVar5, 1, 1, 0,
                DAT_009d4d28, DAT_009d4d2c, DAT_009d4d30, DAT_009d4d34, &local_98);
            local_bc = local_bc + iVar4;
          } else {
            puVar6 = local_88;
            for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar6 = 0;
              puVar6 = puVar6 + 1;
            }
            puVar6 = (uint32_t *)(param_1 + 0x160);
            if (param_1 == 0) {
              puVar6 = &DAT_009d4d28;
            }
            local_88[0] = *puVar6;
            local_88[1] = puVar6[1];
            local_88[2] = puVar6[2];
            local_88[3] = puVar6[3];
            local_78 = piVar5[0x58];
            local_74 = piVar5[0x59];
            local_70 = piVar5[0x5a];
            local_6c = piVar5[0x5b];
            local_5e = 1;
            local_60 = 0;
            local_58 = 0;
            Client_EnqueueCombatFloater_INFERRED(local_88);
            local_c0 = param_6;
          }
          local_c4 = local_c4 + 1;
          param_6 = local_c0 + 6;
          local_c0 = param_6;
          piVar5 = (int *)FUN_0040b020();
        } while (piVar5 != 0);
      }
      FUN_004bcbf0();
      return local_bc;
    }
    FUN_004bcbf0();
  }
  return 0;
}
