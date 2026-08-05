// =============================================================================
// FUN_0083a950
// -----------------------------------------------------------------------------
// Stable ID: aa_0083a950
// Address:   0x0083a950  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083a950 @ 0x0083a950
// Stable ID: aa_0083a950
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_0076df50, FUN_0076e3c0, FUN_00791f30, FUN_00833390, FUN_0083a950.
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

void __thiscall FUN_0083a950(int *param_1,float param_2)



{

  int iVar1;

  int *piVar2;

  float fVar3;

  int iVar4;

  float fVar5;

  uint8_t auStack_10 [16];

  

  fVar3 = DAT_00a0f298;

  fVar5 = (float)param_1[0x141];

  param_1[0x141] = (int)(param_2 + fVar5);

  if (fVar3 < param_2 + fVar5) {

    (**(code **)(*param_1 + 0x444))();

    param_1[0x141] = 0;

  }

  iVar4 = 0;

  do {

    iVar1 = param_1[iVar4 + 0x143];

    if (((iVar1 != 0) && (iVar4 == 2)) && (piVar2 = *(int **)(iVar1 + 0x508), piVar2 != (int *)0x0))

    {

      fVar5 = param_2 * DAT_00a0f298;

      *(uint8_t *)(iVar1 + 0x5dc) = 0;

      FUN_0076e3c0(auStack_10,fVar5,0,0);

      FUN_0076df50(iVar1 + 0x590,iVar1 + 0x590,auStack_10);

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0x5cc) = 0xffffffff;

      *(int *)(iVar1 + 0x5c4) = *(int *)(iVar1 + 0x5c4) + 1;

      if ((int *)piVar2[0x12] != (int *)0x0) {

        (**(code **)(*(int *)piVar2[0x12] + 0x14))(iVar1 + 0x590);

        (**(code **)(*piVar2 + 0x44))();

        FUN_00833390();

      }

    }

    iVar4 = iVar4 + 1;

  } while (iVar4 < 5);

  FUN_00791f30(param_2);

  return;

}
