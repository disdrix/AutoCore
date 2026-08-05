// =============================================================================
// FUN_00978b80
// -----------------------------------------------------------------------------
// Stable ID: aa_00978b80
// Address:   0x00978b80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00978b80 @ 0x00978b80
// Stable ID: aa_00978b80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×7, return×7.
//  - Notable callees: CVOGReaction_TeleportTarget, FUN_004e9530, FUN_005816a0, FUN_00978990, FUN_00978b80.
//  - Return sites: 7.

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

uint32_t /* width from decompiler */ __thiscall FUN_00978b80(int param_1,float param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *pTeleportData;

  void *this;

  float fVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint8_t auStack_24 [32];

  

  if (*(char *)(param_1 + 8) != '\0') {

    FUN_00978990();

    return 0;

  }

  param_2 = param_2 + *(float *)(param_1 + 0x3c);

  fVar3 = *(float *)(param_1 + 0x44) + DAT_00aaa690;

  *(float *)(param_1 + 0x3c) = param_2;

  if (fVar3 <= param_2) {

    *(char *)(param_1 + 0x49) = *(char *)(param_1 + 0x49) + '\x01';

    *(float *)(param_1 + 0x44) = fVar3;

    return 1;

  }

  (**(code **)(**(int **)(param_1 + 0x24) + 0x28))(*(uint32_t /* width from decompiler */ *)(DAT_00d09874 + 0x238));

  (**(code **)(**(int **)(*(int *)(param_1 + 0x24) + 8) + 0x34))();

  if (*(char *)(param_1 + 0x48) != '\0') {

    (**(code **)(**(int **)(param_1 + 0x28) + 0xc))();

    iVar1 = *(int *)(param_1 + 0x38);

    iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

    pTeleportData = (uint32_t /* width from decompiler */ *)FUN_004e9530(auStack_24,&stack0xffffffd0);

    this = (void *)(**(code **)(*(int *)(iVar2 + 4 + iVar1) + 0x19c))();

    CVOGReaction_TeleportTarget(this,pTeleportData);

    return 0;

  }

  fVar3 = *(float *)(param_1 + 0x44) + g_flLevelUpUiBase_Inferred;

  if ((*(float *)(param_1 + 0x3c) < fVar3) || (*(char *)(param_1 + 0x49) != '\x02')) {

    fVar3 = *(float *)(param_1 + 0x44) + g_flOne;

    if ((fVar3 <= *(float *)(param_1 + 0x3c)) && (*(char *)(param_1 + 0x49) == '\x01')) {

      *(float *)(param_1 + 0x44) = fVar3;

      *(uint8_t *)(param_1 + 0x49) = 2;

      *(uint8_t *)(param_1 + 0x48) = 0;

      return 0;

    }

    fVar3 = *(float *)(param_1 + 0x44) + DAT_00aaa8b0;

    if (*(float *)(param_1 + 0x3c) < fVar3) {

      return 0;

    }

    if (*(char *)(param_1 + 0x49) != '\0') {

      return 0;

    }

    *(uint8_t *)(param_1 + 0x49) = 1;

    uVar4 = 0;

  }

  else {

    *(uint8_t *)(param_1 + 0x49) = 3;

    uVar4 = 2;

  }

  *(float *)(param_1 + 0x44) = fVar3;

  FUN_005816a0(uVar4,0x3dcccccd);

  return 0;

}
