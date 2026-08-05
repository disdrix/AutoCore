// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: Skill_CopyRuntimeFieldsFromTemplate×2, Skill_ReevaluateForCurrentRank.
//  - Return sites: 1.

// =============================================================================
// Skill_CopyRuntimeFieldsFromTemplate
// -----------------------------------------------------------------------------
// Stable ID: aa_00553480
// Address:   0x00553480  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* Skill_CopyRuntimeFieldsFromTemplate(pDst, pSrc)

   

   Copies rank/flags/category/name fields; clears casting flag and cast start tick;

   calls Skill_ReevaluateForCurrentRank. */



void __thiscall Skill_CopyRuntimeFieldsFromTemplate(void *param_1,int param_2)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  

  *(uint16_t *)((int)param_1 + 0x5f6) = *(uint16_t *)(param_2 + 0x5f6);

  *(uint8_t *)((int)param_1 + 0x5f8) = *(uint8_t *)(param_2 + 0x5f8);

  *(uint8_t *)((int)param_1 + 0x5f9) = *(uint8_t *)(param_2 + 0x5f9);

  *(uint8_t *)((int)param_1 + 0x5fa) = *(uint8_t *)(param_2 + 0x5fa);

  *(uint8_t *)((int)param_1 + 0x5fb) = *(uint8_t *)(param_2 + 0x5fb);

  *(uint8_t *)((int)param_1 + 0x5f4) = *(uint8_t *)(param_2 + 0x5f4);

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x614) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x614);

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x618) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x618);

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x60c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x60c);

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x610) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x610);

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x620) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x620);

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x180) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x180);

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x17c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x17c);

  *(uint8_t *)((int)param_1 + 0x628) = 0;

  *(short *)((int)param_1 + 0x174) = (short)(int)*(float *)(param_2 + 0xf4);

  *(uint8_t *)((int)param_1 + 0x5e7) = *(uint8_t *)(param_2 + 0x5e7);

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x5e8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x5e8);

  pcVar3 = (char *)(param_2 + 0x1a5);

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x5ec) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x5ec);

  iVar2 = 0x1a5 - (int)pcVar3;

  do {

    cVar1 = *pcVar3;

    pcVar3[(int)param_1 + iVar2] = cVar1;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x170) = 0;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x178) = 0;

  Skill_ReevaluateForCurrentRank(param_1);

  return;

}
