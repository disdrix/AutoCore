// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_0092d900
// -----------------------------------------------------------------------------
// Stable ID: aa_0092d900
// Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
// Address:   0x0092d900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~104 non-empty decompiler lines.
//  - Control keywords: do×10, while×10, for×6, return×1.
//  - Notable callees: _itoa×4, FUN_0092d900.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
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

void Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_0092d900(uint param_1,char *param_2)



{

  char cVar1;

  char *pcVar2;

  uint uVar3;

  char *pcVar4;

  char *pcVar5;

  char *pcVar6;

  char *pcVar7;

  

  pcVar5 = param_2;

  pcVar2 = _itoa(param_1 >> 0x18,(char *)&param_2,10);

  pcVar4 = pcVar5;

  do {

    cVar1 = *pcVar2;

    *pcVar4 = cVar1;

    pcVar2 = pcVar2 + 1;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  pcVar4 = pcVar5 + -1;

  do {

    pcVar2 = pcVar4 + 1;

    pcVar4 = pcVar4 + 1;

  } while (*pcVar2 != '\0');

  *(uint16_t *)pcVar4 = DAT_00a2e610;

  pcVar2 = _itoa(param_1 >> 0x10 & 0xff,(char *)&param_2,10);

  pcVar4 = pcVar2;

  do {

    cVar1 = *pcVar4;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  pcVar7 = pcVar5 + -1;

  do {

    pcVar6 = pcVar7 + 1;

    pcVar7 = pcVar7 + 1;

  } while (*pcVar6 != '\0');

  pcVar6 = pcVar2;

  for (uVar3 = (uint)((int)pcVar4 - (int)pcVar2) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar6;

    pcVar6 = pcVar6 + 4;

    pcVar7 = pcVar7 + 4;

  }

  for (uVar3 = (int)pcVar4 - (int)pcVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

    *pcVar7 = *pcVar6;

    pcVar6 = pcVar6 + 1;

    pcVar7 = pcVar7 + 1;

  }

  pcVar4 = pcVar5 + -1;

  do {

    pcVar2 = pcVar4 + 1;

    pcVar4 = pcVar4 + 1;

  } while (*pcVar2 != '\0');

  *(uint16_t *)pcVar4 = DAT_00a2e610;

  pcVar2 = _itoa(param_1 >> 8 & 0xff,(char *)&param_2,10);

  pcVar4 = pcVar2;

  do {

    cVar1 = *pcVar4;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  pcVar7 = pcVar5 + -1;

  do {

    pcVar6 = pcVar7 + 1;

    pcVar7 = pcVar7 + 1;

  } while (*pcVar6 != '\0');

  pcVar6 = pcVar2;

  for (uVar3 = (uint)((int)pcVar4 - (int)pcVar2) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar6;

    pcVar6 = pcVar6 + 4;

    pcVar7 = pcVar7 + 4;

  }

  for (uVar3 = (int)pcVar4 - (int)pcVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

    *pcVar7 = *pcVar6;

    pcVar6 = pcVar6 + 1;

    pcVar7 = pcVar7 + 1;

  }

  pcVar4 = pcVar5 + -1;

  do {

    pcVar2 = pcVar4 + 1;

    pcVar4 = pcVar4 + 1;

  } while (*pcVar2 != '\0');

  *(uint16_t *)pcVar4 = DAT_00a2e610;

  pcVar2 = _itoa(param_1 & 0xff,(char *)&param_2,10);

  pcVar4 = pcVar2;

  do {

    cVar1 = *pcVar4;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  pcVar5 = pcVar5 + -1;

  do {

    pcVar7 = pcVar5 + 1;

    pcVar5 = pcVar5 + 1;

  } while (*pcVar7 != '\0');

  pcVar7 = pcVar2;

  for (uVar3 = (uint)((int)pcVar4 - (int)pcVar2) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar5 = *(uint32_t /* width from decompiler */ *)pcVar7;

    pcVar7 = pcVar7 + 4;

    pcVar5 = pcVar5 + 4;

  }

  for (uVar3 = (int)pcVar4 - (int)pcVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

    *pcVar5 = *pcVar7;

    pcVar7 = pcVar7 + 1;

    pcVar5 = pcVar5 + 1;

  }

  return;

}
