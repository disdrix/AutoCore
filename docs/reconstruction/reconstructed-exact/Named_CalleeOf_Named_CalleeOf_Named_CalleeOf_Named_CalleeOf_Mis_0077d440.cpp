// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_0077d440
// -----------------------------------------------------------------------------
// Stable ID: aa_0077d440
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Sending_Co
// Address:   0x0077d440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Sending_Co: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, goto×2.
//  - Notable callees: FUN_0077d440×3, FUN_0042b450×2.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Sending_Co
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_0077d440(int param_1,int param_2,int param_3)



{

  int iVar1;

  char cVar2;

  int iVar3;

  byte *pbVar4;

  

  if (param_2 < 0) {

    iVar3 = DAT_00d1eabc + (param_2 * 3 + 3) * -4;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 8) = **(uint32_t /* width from decompiler */ **)(param_1 + 0xc);

    *(uint8_t *)(iVar3 + 4) = (uint8_t)param_3;

    return;

  }

  iVar1 = *(int *)(param_1 + 0x18);

  iVar3 = DAT_00d1eab0 + param_2 * 8;

  if (*(uint *)(param_1 + 0x30) < iVar1 + 1U) {

    cVar2 = FUN_0042b450();

    if (cVar2 != '\0') goto LAB_0077d499;

  }

  else {

LAB_0077d499:

    pbVar4 = (byte *)(*(int *)(param_1 + 0xc) + (*(uint *)(param_1 + 0x18) >> 3));

    *pbVar4 = *pbVar4 & ~('\x01' << ((byte)*(uint *)(param_1 + 0x18) & 7));

    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;

  }

  Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_0077d440(param_1,(int)*(short *)(iVar3 + 4),param_3 + 1);

  *(int *)(param_1 + 0x18) = iVar1;

  if (*(uint *)(param_1 + 0x30) < iVar1 + 1U) {

    cVar2 = FUN_0042b450();

    if (cVar2 == '\0') goto LAB_0077d4fe;

  }

  pbVar4 = (byte *)(*(int *)(param_1 + 0xc) + (*(uint *)(param_1 + 0x18) >> 3));

  *pbVar4 = *pbVar4 | '\x01' << ((byte)*(uint *)(param_1 + 0x18) & 7);

  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;

LAB_0077d4fe:

  Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_0077d440(param_1,(int)*(short *)(iVar3 + 6),param_3 + 1);

  *(int *)(param_1 + 0x18) = iVar1;

  return;

}
