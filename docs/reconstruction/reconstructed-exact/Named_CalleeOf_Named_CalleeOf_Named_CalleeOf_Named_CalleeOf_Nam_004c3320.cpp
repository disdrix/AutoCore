// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004c3320
// -----------------------------------------------------------------------------
// Stable ID: aa_004c3320
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x004c3320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~177 non-empty decompiler lines.
//  - Control keywords: do×19, while×19, switch×1, return×1.
//  - Notable callees: FUN_004c3320.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004c3320(uint32_t /* width from decompiler */ param_1,char *param_2,char *param_3)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  char *pcVar4;

  

  iVar2 = (int)param_3 - (int)param_2;

  do {

    cVar1 = *param_2;

    param_2[iVar2] = cVar1;

    param_2 = param_2 + 1;

  } while (cVar1 != '\0');

  switch(param_1) {

  case 0:

    pcVar3 = param_3 + -1;

    do {

      pcVar4 = pcVar3 + 1;

      pcVar3 = pcVar3 + 1;

    } while (*pcVar4 != '\0');

    *(uint32_t /* width from decompiler */ *)pcVar3 = DAT_009cb960;

    break;

  case 1:

    pcVar3 = param_3 + -1;

    do {

      pcVar4 = pcVar3 + 1;

      pcVar3 = pcVar3 + 1;

    } while (*pcVar4 != '\0');

    *(uint32_t /* width from decompiler */ *)pcVar3 = DAT_009cb95c;

    break;

  case 2:

    pcVar3 = param_3 + -1;

    do {

      pcVar4 = pcVar3 + 1;

      pcVar3 = pcVar3 + 1;

    } while (*pcVar4 != '\0');

    *(uint32_t /* width from decompiler */ *)pcVar3 = DAT_009cb958;

    break;

  case 3:

    pcVar3 = param_3 + -1;

    do {

      pcVar4 = pcVar3;

      pcVar3 = pcVar4 + 1;

    } while (pcVar4[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = DAT_009cb950;

    pcVar4[5] = DAT_009cb954;

    break;

  case 4:

    pcVar3 = param_3 + -1;

    do {

      pcVar4 = pcVar3;

      pcVar3 = pcVar4 + 1;

    } while (pcVar4[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = DAT_009cb948;

    pcVar4[5] = DAT_009cb94c;

    break;

  case 5:

    pcVar3 = param_3 + -1;

    do {

      pcVar4 = pcVar3 + 1;

      pcVar3 = pcVar3 + 1;

    } while (*pcVar4 != '\0');

    *(uint32_t /* width from decompiler */ *)pcVar3 = DAT_009cb934;

    break;

  case 6:

    pcVar3 = param_3 + -1;

    do {

      pcVar4 = pcVar3 + 1;

      pcVar3 = pcVar3 + 1;

    } while (*pcVar4 != '\0');

    *(uint32_t /* width from decompiler */ *)pcVar3 = DAT_009cb930;

    break;

  case 7:

    pcVar3 = param_3 + -1;

    do {

      pcVar4 = pcVar3;

      pcVar3 = pcVar4 + 1;

    } while (pcVar4[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = DAT_009cb928;

    pcVar4[5] = DAT_009cb92c;

    break;

  case 9:

    pcVar3 = param_3 + -1;

    do {

      pcVar4 = pcVar3;

      pcVar3 = pcVar4 + 1;

    } while (pcVar4[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = DAT_009cb920;

    pcVar4[5] = DAT_009cb924;

    break;

  case 10:

    pcVar3 = param_3 + -1;

    do {

      pcVar4 = pcVar3;

      pcVar3 = pcVar4 + 1;

    } while (pcVar4[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = DAT_009cb918;

    pcVar4[5] = DAT_009cb91c;

    break;

  case 0xb:

    pcVar3 = param_3 + -1;

    do {

      pcVar4 = pcVar3;

      pcVar3 = pcVar4 + 1;

    } while (pcVar4[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = DAT_009cb910;

    pcVar4[5] = DAT_009cb914;

    break;

  case 0xc:

    pcVar3 = param_3 + -1;

    do {

      pcVar4 = pcVar3;

      pcVar3 = pcVar4 + 1;

    } while (pcVar4[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = DAT_009cb908;

    pcVar4[5] = DAT_009cb90c;

    break;

  case 0xd:

    pcVar3 = param_3 + -1;

    do {

      pcVar4 = pcVar3;

      pcVar3 = pcVar4 + 1;

    } while (pcVar4[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = DAT_009cb900;

    pcVar4[5] = DAT_009cb904;

    break;

  case 0xe:

    pcVar3 = param_3 + -1;

    do {

      pcVar4 = pcVar3;

      pcVar3 = pcVar4 + 1;

    } while (pcVar4[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = DAT_009cb8f8;

    pcVar4[5] = DAT_009cb8fc;

    break;

  case 0xf:

    pcVar3 = param_3 + -1;

    do {

      pcVar4 = pcVar3;

      pcVar3 = pcVar4 + 1;

    } while (pcVar4[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = DAT_009cb8f0;

    pcVar4[5] = DAT_009cb8f4;

    break;

  case 0x10:

    pcVar3 = param_3 + -1;

    do {

      pcVar4 = pcVar3;

      pcVar3 = pcVar4 + 1;

    } while (pcVar4[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = DAT_009cb940;

    pcVar4[5] = DAT_009cb944;

    break;

  case 0x11:

    pcVar3 = param_3 + -1;

    do {

      pcVar4 = pcVar3;

      pcVar3 = pcVar4 + 1;

    } while (pcVar4[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = DAT_009cb938;

    pcVar4[5] = DAT_009cb93c;

    break;

  case 0x12:

    *(uint32_t /* width from decompiler */ *)param_3 = s__Achar_g_m_ae059_009cb8de._2_4_;

    *(uint32_t /* width from decompiler */ *)(param_3 + 4) = s__Achar_g_m_ae059_009cb8de._6_4_;

    *(uint32_t /* width from decompiler */ *)(param_3 + 8) = s__Achar_g_m_ae059_009cb8de._10_4_;

    *(uint16_t *)(param_3 + 0xc) = s__Achar_g_m_ae059_009cb8de._14_2_;

    param_3[0xe] = s__Achar_g_m_ae059_009cb8de[0x10];

  }

  pcVar3 = param_3 + -1;

  do {

    pcVar4 = pcVar3;

    pcVar3 = pcVar4 + 1;

  } while (pcVar4[1] != '\0');

  *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = DAT_00a308b8;

  pcVar4[5] = DAT_00a308bc;

  return;

}
