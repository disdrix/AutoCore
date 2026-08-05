// =============================================================================
// FUN_004dbef0
// -----------------------------------------------------------------------------
// Stable ID: aa_004dbef0
// Address:   0x004dbef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004dbef0 @ 0x004dbef0
// Stable ID: aa_004dbef0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_00493e90, FUN_004bb1c0, FUN_004dbef0, FUN_004e23d0, FUN_004e3170, FUN_004e7d30.
//  - Return sites: 2.

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

void FUN_004dbef0(int *param_1,uint32_t /* width from decompiler */ param_2,int param_3,int param_4,int param_5)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  

  piVar1 = param_1;

  iVar5 = param_1[0x58];

  iVar2 = FUN_004e23d0(iVar5,param_1[0x59],&param_1);

  iVar3 = 0;

  if (iVar2 != 0) {

    iVar3 = *(int *)(iVar2 + 0xc);

  }

  if (iVar3 != 0) {

    FUN_004e3170(iVar5,piVar1[0x59],&param_1);

  }

  piVar4 = operator_new(0x28);

  if (piVar4 == (int *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    *piVar4 = 0;

    piVar4[1] = 0;

    piVar4[2] = 0;

    piVar4[3] = 0;

    piVar4[4] = 0;

    piVar4[5] = 0;

    piVar4[6] = 0;

    piVar4[7] = 0;

    piVar4[8] = 0;

    piVar4[9] = 0;

  }

  *piVar4 = piVar1[0x58];

  piVar4[1] = piVar1[0x59];

  piVar4[2] = piVar1[0x5a];

  piVar4[3] = piVar1[0x5b];

  piVar4[4] = 0;

  piVar4[6] = param_3;

  piVar4[7] = param_4;

  piVar4[8] = param_5;

  iVar5 = FUN_004bb1c0(0,param_3,param_4);

  piVar4[5] = iVar5;

  piVar1[0x47] = (int)piVar4;

  if (piVar1[0x29] != 0) {

    iVar5 = (**(code **)(*piVar1 + 0x1cc))();

    if (iVar5 != 0) {

      iVar5 = (**(code **)(*piVar1 + 0x1cc))();

      FUN_00493e90(*(uint32_t /* width from decompiler */ *)(iVar5 + 8));

    }

  }

  iVar5 = FUN_004e7d30(*piVar4,piVar4[1],piVar4,0);

  if (iVar5 != 0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(piVar4);

  }

  return;

}
