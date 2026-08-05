// =============================================================================
// FUN_008e9710
// -----------------------------------------------------------------------------
// Stable ID: aa_008e9710
// Address:   0x008e9710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e9710 @ 0x008e9710
// Stable ID: aa_008e9710
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×6, goto×2, return×1.
//  - Notable callees: FUN_00791f30, FUN_008e9320, FUN_008e9710.
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

void __thiscall FUN_008e9710(int *param_1,float param_2)



{

  float fVar1;

  int iVar2;

  char cVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  cVar3 = (**(code **)(*param_1 + 0xd0))();

  if (cVar3 != '\0') {

    if (((param_1[0x151] != 0) && (param_1[0x182] != 0)) &&

       (fVar1 = (float)param_1[0x155], param_1[0x155] = (int)(fVar1 + param_2),

       (float)param_1[0x156] <= fVar1 + param_2)) {

      param_1[0x155] = 0;

      FUN_008e9320(param_1);

    }

    if ((int *)param_1[0x16d] != (int *)0x0) {

      iVar2 = *(int *)param_1[0x16d];

      if (DAT_00d1775e == '\0') {

        cVar3 = (**(code **)(iVar2 + 0x3bc))();

        if (cVar3 != '\x01') goto LAB_008e97a6;

        uVar4 = 0;

      }

      else {

        cVar3 = (**(code **)(iVar2 + 0x3bc))();

        if (cVar3 != '\0') goto LAB_008e97a6;

        uVar4 = 1;

      }

      (**(code **)(*(int *)param_1[0x16d] + 0x3c8))(uVar4,1);

    }

  }

LAB_008e97a6:

  FUN_00791f30(param_2);

  return;

}
