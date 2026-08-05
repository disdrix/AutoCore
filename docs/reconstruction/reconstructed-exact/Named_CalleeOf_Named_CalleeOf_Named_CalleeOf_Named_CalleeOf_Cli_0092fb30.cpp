// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_0092fb30
// -----------------------------------------------------------------------------
// Stable ID: aa_0092fb30
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen
// Address:   0x0092fb30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: return×8, if×5, switch×1.
//  - Notable callees: FUN_00513de0×2, CONCAT31, FUN_004fabc0, FUN_00514390, FUN_0092fb30.
//  - Return sites: 8.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_0092fb30(void)



{

  byte bVar1;

  char cVar2;

  int in_EAX;

  int iVar3;

  int *unaff_ESI;

  uint32_t /* width from decompiler */ local_8;

  uint local_4;

  

  if (((unaff_ESI == (int *)0x0) || (iVar3 = *(int *)(in_EAX + 0xe98), iVar3 == 0)) ||

     (*(int *)(iVar3 + 0x250) == 0)) {

    return 0;

  }

  local_4 = CONCAT31(local_4._1_3_,(char)((uint)unaff_ESI[0x5f] >> 0x13)) & 0xffffff01;

  cVar2 = FUN_00514390(iVar3,0);

  local_8 = 0;

  FUN_00513de0(0);

  iVar3 = FUN_004fabc0(unaff_ESI,&local_8);

  FUN_00513de0(local_4);

  if ((iVar3 != 7) && ((iVar3 != 6 || (cVar2 != '\0')))) {

    iVar3 = unaff_ESI[0x2a];

    switch(*(uint32_t /* width from decompiler */ *)(iVar3 + 0x38)) {

    case 6:

      if (*(short *)(*(int *)(iVar3 + 0x3c) + 0x3f4) == 0) {

        return 9;

      }

      break;

    case 8:

    case 0x32:

      return 7;

    case 0x1a:

      if ((*(int *)(iVar3 + 0x3c) != 0) &&

         (bVar1 = *(byte *)(*(int *)(iVar3 + 0x3c) + 0x4c9),

         iVar3 = (**(code **)(*unaff_ESI + 0x25c))(), (int)(uint)bVar1 <= iVar3)) {

        return 6;

      }

      return 5;

    }

    if ((cVar2 != '\0') && ((*(byte *)(*(int *)(iVar3 + 0x3c) + 0x3f2) & 0x80) != 0)) {

      return 8;

    }

    return 1;

  }

  return 2;

}
