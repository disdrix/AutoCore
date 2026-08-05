// =============================================================================
// Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_00722790
// -----------------------------------------------------------------------------
// Stable ID: aa_00722790
// Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
// Address:   0x00722790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Uses_Client_GetMissionCompleteAudioTable: mission/objective helper. Evidence string: "_lxx.ogg". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "_lxx.ogg"
//   - ".ogg"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, for×2, if×1, return×1.
//  - Notable callees: FUN_00722790.
//  - Strings: "_lxx.ogg"; ".ogg".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
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

void __thiscall Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_00722790(int param_1,int param_2)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  uint uVar4;

  char *pcVar5;

  char *pcVar6;

  

  pcVar2 = "_lxx.ogg";

  pcVar3 = pcVar2;

  if (*(char *)(param_1 + 0x308) == '\0') {

    pcVar2 = ".ogg";

    pcVar3 = pcVar2;

  }

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  pcVar6 = (char *)(param_2 + -1);

  do {

    pcVar5 = pcVar6 + 1;

    pcVar6 = pcVar6 + 1;

  } while (*pcVar5 != '\0');

  pcVar5 = pcVar3;

  for (uVar4 = (uint)((int)pcVar2 - (int)pcVar3) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar5;

    pcVar5 = pcVar5 + 4;

    pcVar6 = pcVar6 + 4;

  }

  for (uVar4 = (int)pcVar2 - (int)pcVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

    *pcVar6 = *pcVar5;

    pcVar5 = pcVar5 + 1;

    pcVar6 = pcVar6 + 1;

  }

  return;

}
