// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_UpdateMissi_007f9160
// -----------------------------------------------------------------------------
// Stable ID: aa_007f9160
// Callee of Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal
// Address:   0x007f9160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×5, do×4, while×4, return×3, for×2, goto×1.
//  - Notable callees: FUN_007f5120×2, CONCAT22, CONCAT31, FUN_007f7240, FUN_007f9160.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_UpdateMissi_007f9160(char *param_1,uint32_t /* width from decompiler */ param_2,char param_3)



{

  char cVar1;

  short sVar2;

  uint32_t /* width from decompiler */ in_EAX;

  short *psVar3;

  char *pcVar4;

  uint uVar5;

  uint uVar6;

  char *pcVar7;

  short sVar8;

  

  psVar3 = (short *)FUN_007f7240(in_EAX);

  if ((psVar3 == (short *)0x0) || (param_1 == (char *)0x0)) {

    return (uint)psVar3 & 0xffffff00;

  }

  *param_1 = '\0';

  if (param_3 == '\0') {

    sVar8 = *psVar3;

    sVar2 = psVar3[0x15];

  }

  else {

    sVar8 = psVar3[1];

    sVar2 = psVar3[0x16];

  }

  if (sVar8 == 0) {

    if (sVar2 == 0) {

      return CONCAT22((short)((uint)psVar3 >> 0x10),sVar2) & 0xffffff00;

    }

  }

  else if (sVar2 == 0) goto LAB_007f91e7;

  pcVar4 = (char *)FUN_007f5120();

  pcVar7 = param_1;

  do {

    cVar1 = *pcVar4;

    *pcVar7 = cVar1;

    pcVar4 = pcVar4 + 1;

    pcVar7 = pcVar7 + 1;

  } while (cVar1 != '\0');

  pcVar7 = param_1 + -1;

  do {

    pcVar4 = pcVar7 + 1;

    pcVar7 = pcVar7 + 1;

  } while (*pcVar4 != '\0');

  *(uint16_t *)pcVar7 = DAT_00a2e620;

LAB_007f91e7:

  pcVar4 = (char *)FUN_007f5120();

  pcVar7 = pcVar4;

  do {

    cVar1 = *pcVar7;

    pcVar7 = pcVar7 + 1;

  } while (cVar1 != '\0');

  uVar5 = (int)pcVar7 - (int)pcVar4;

  param_1 = param_1 + -1;

  do {

    pcVar7 = param_1 + 1;

    param_1 = param_1 + 1;

  } while (*pcVar7 != '\0');

  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

    *(uint32_t /* width from decompiler */ *)param_1 = *(uint32_t /* width from decompiler */ *)pcVar4;

    pcVar4 = pcVar4 + 4;

    param_1 = param_1 + 4;

  }

  for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

    *param_1 = *pcVar4;

    pcVar4 = pcVar4 + 1;

    param_1 = param_1 + 1;

  }

  return CONCAT31((int3)(uVar5 >> 8),1);

}
