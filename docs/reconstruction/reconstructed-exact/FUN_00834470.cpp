// =============================================================================
// FUN_00834470
// -----------------------------------------------------------------------------
// Stable ID: aa_00834470
// Address:   0x00834470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00834470 @ 0x00834470
// Stable ID: aa_00834470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0040d1a0, FUN_004f8ce0, FUN_00756060, FUN_007560a0, FUN_007afe80, FUN_00834470.
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

void FUN_00834470(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  uint unaff_EBX;

  uint32_t /* width from decompiler */ uVar5;

  

  iVar2 = *(int *)(param_1 + 0x508);

  if (iVar2 != 0) {

    iVar1 = (unaff_EBX & 0xff) * 4 + 0x28c;

    iVar3 = *(int *)(iVar1 + iVar2);

    if (iVar3 != param_2) {

      if ((-1 < iVar3) && (*(int *)(iVar2 + 0x34c + (char)unaff_EBX * 4) != 0)) {

        FUN_00756060();

      }

      FUN_004f8ce0(unaff_EBX,param_2);

      if ((-1 < *(int *)(iVar1 + *(int *)(param_1 + 0x508))) &&

         (piVar4 = *(int **)(*(int *)(param_1 + 0x508) + 0x34c + (char)unaff_EBX * 4),

         piVar4 != (int *)0x0)) {

        uVar5 = 3;

        (**(code **)(*piVar4 + 0x10))(3,param_1 + 0x590);

        FUN_0040d1a0(uVar5);

        FUN_007560a0();

        FUN_007afe80(piVar4,1);

      }

    }

  }

  return;

}
