// =============================================================================
// Named_CalleeOf_Named_assPackManager_0071a9d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071a9d0
// Callee of Named_assPackManager
// Address:   0x0071a9d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assPackManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: FUN_007669d0×3, FUN_0071a4a0, FUN_0071a9d0, FUN_0076b190, _strdup, stat.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_assPackManager
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_assPackManager_0071a9d0(void)



{

  char *in_EAX;

  char *pcVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *unaff_EDI;

  uint8_t local_128 [6];

  uint local_122;

  uint8_t local_104 [248];

  uint32_t /* width from decompiler */ uStack_c;

  

  pcVar1 = _strdup(in_EAX);

  unaff_EDI[10] = (int)pcVar1;

  FUN_0076b190();

  uVar4 = 3;

  if ((char)unaff_EDI[0x10] != '\0') {

    uVar4 = 1;

  }

  iVar2 = stat(local_104,local_128);

  if ((iVar2 == 0) && ((local_122 >> 0xf & 1) != 0)) {

    iVar2 = FUN_007669d0(local_104,uVar4,0x10000000);

    if (iVar2 != 0) {

      return 0xffffffff;

    }

    iVar2 = FUN_007669d0(local_104,uVar4,0x10000000);

  }

  else {

    iVar2 = FUN_007669d0(local_104,6,0x10000000);

  }

  if (iVar2 == 0) {

    iVar2 = (**(code **)(*unaff_EDI + 0x1c))();

    if (iVar2 == 0) {

      return 0;

    }

    if (((iVar2 != -1) && (iVar3 = (**(code **)(*unaff_EDI + 4))(iVar2 + -4,0), iVar3 == 0)) &&

       (iVar3 = (**(code **)(*unaff_EDI + 0x14))(&stack0xfffffecc,4), iVar3 == 0)) {

      uVar4 = FUN_0071a4a0(unaff_EDI,uStack_c,iVar2);

      return uVar4;

    }

  }

  return 0xffffffff;

}
