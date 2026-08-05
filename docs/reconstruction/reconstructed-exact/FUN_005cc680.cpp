// =============================================================================
// FUN_005cc680
// -----------------------------------------------------------------------------
// Stable ID: aa_005cc680
// Address:   0x005cc680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005cc680 @ 0x005cc680
// Stable ID: aa_005cc680
// Embedded strings (evidence for future rename):
//   - "%n(%d) is attacking itself on %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: return×5, if×4.
//  - Notable callees: FUN_005134e0, FUN_0053e510, FUN_005cc680, FUN_007a4480, n.
//  - Strings: "%n(%d) is attacking itself on %s".
//  - Return sites: 5.

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

void __fastcall FUN_005cc680(int *param_1)



{

  int *piVar1;

  float fVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  float10 fVar7;

  

  if (*(int **)(param_1[6] + 0xa0) == (int *)0x0) {

    return;

  }

  iVar4 = (**(code **)(**(int **)(param_1[6] + 0xa0) + 0x1c8))();

  if ((((iVar4 == 0) || (*(int *)(iVar4 + 8) == 0)) || (cVar3 = FUN_005134e0(), cVar3 != '\0')) ||

     (((*(uint *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0x180 + iVar4) >> 3 & 1) != 0 ||

      (cVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x198))(),

      cVar3 != '\0')))) {

                    /* WARNING: Could not recover jumptable at 0x005cc7b9. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*param_1 + 0x20))();

    return;

  }

  piVar1 = (int *)param_1[6];

  iVar4 = (**(code **)(*(int *)piVar1[0x28] + 0x1c8))();

  iVar5 = (**(code **)(*piVar1 + 0x19c))();

  if (iVar5 == iVar4) {

    piVar1 = (int *)param_1[6];

    uVar6 = (**(code **)(*piVar1 + 0x160))(*(uint32_t /* width from decompiler */ *)(piVar1[0x2a] + 0x34),piVar1[0x29] + 0xb4)

    ;

    FUN_007a4480(0,"%n(%d) is attacking itself on %s",uVar6);

                    /* WARNING: Could not recover jumptable at 0x005cc75c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*param_1 + 0x20))();

    return;

  }

  iVar4 = param_1[0x19];

  fVar2 = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xac + iVar4) + 0x3c) +

                    0x4c8);

  uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x19c))();

  fVar7 = (float10)FUN_0053e510(uVar6);

  if (fVar7 <= (float10)fVar2) {

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x005cc7ad. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*param_1 + 0x20))();

  return;

}
