// =============================================================================
// FUN_0096d9d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096d9d0
// Address:   0x0096d9d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096d9d0 @ 0x0096d9d0
// Stable ID: aa_0096d9d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×4, while×1, for×1, return×1.
//  - Notable callees: FUN_0044ac40, FUN_0096d9d0.
//  - Return sites: 1.

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

void FUN_0096d9d0(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  iVar4 = 0xc;

  puVar5 = param_1;

  puVar6 = unaff_EBX;

  while( true ) {

    puVar6 = puVar6 + 1;

    puVar5 = puVar5 + 1;

    if (iVar4 == 0) break;

    iVar4 = iVar4 + -1;

    *puVar6 = *puVar5;

  }

  puVar5 = param_1 + 0xd;

  puVar6 = unaff_EBX + 0xd;

  for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar6 = *puVar5;

    puVar5 = puVar5 + 1;

    puVar6 = puVar6 + 1;

  }

  piVar2 = (int *)param_1[0x19];

  if ((piVar2 != (int *)0x0) && (piVar2[1] = piVar2[1] + 1, piVar2[1] == 1)) {

    (**(code **)(*piVar2 + 4))();

  }

  piVar3 = (int *)unaff_EBX[0x19];

  if (piVar3 != (int *)0x0) {

    piVar1 = piVar3 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar3 + 8))();

    }

  }

  unaff_EBX[0x19] = piVar2;

  FUN_0044ac40();

  return;

}
