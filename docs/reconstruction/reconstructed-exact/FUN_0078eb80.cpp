// =============================================================================
// FUN_0078eb80
// -----------------------------------------------------------------------------
// Stable ID: aa_0078eb80
// Address:   0x0078eb80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078eb80 @ 0x0078eb80
// Stable ID: aa_0078eb80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×12, return×8, switch×1.
//  - Notable callees: FUN_0078eb80.
//  - Return sites: 8.

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

uint32_t /* width from decompiler */ __thiscall FUN_0078eb80(int *param_1,int param_2,int param_3)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  switch(param_3 + -0x65) {

  case 0:

    if (param_2 == 5) {

      if (param_1[0x252] != 0) {

        (**(code **)(*(int *)param_1[0x252] + 0x3cc))(1);

        (**(code **)(*(int *)param_1[0x252] + 0x34c))();

      }

      if (param_1[0xac] != 0) {

        iVar1 = *(int *)param_1[0xac];

        uVar3 = (**(code **)(*param_1 + 0x78))();

        (**(code **)(iVar1 + 0x338))(0x66,uVar3);

      }

      return 1;

    }

    if (param_2 == 6) {

      if (param_1[0xac] != 0) {

        iVar1 = *(int *)param_1[0xac];

        uVar3 = (**(code **)(*param_1 + 0x78))();

        (**(code **)(iVar1 + 0x338))(0x67,uVar3);

      }

      return 1;

    }

    if (param_2 == 7) {

      if (param_1[0x252] != 0) {

        if ((param_1[0xac] != 0) &&

           (cVar2 = (**(code **)(*(int *)param_1[0x252] + 0x3c4))(), cVar2 == '\0')) {

          iVar1 = *(int *)param_1[0xac];

          uVar3 = (**(code **)(*param_1 + 0x78))();

          (**(code **)(iVar1 + 0x338))(0x65,uVar3);

        }

        (**(code **)(*(int *)param_1[0x252] + 0x3d0))(1);

        (**(code **)(*(int *)param_1[0x252] + 0x34c))();

      }

      (**(code **)(*param_1 + 0x450))();

      return 1;

    }

    break;

  case 1:

    if (param_2 == 8) {

      (**(code **)(*param_1 + 0x45c))(0xbf800000);

      return 1;

    }

    break;

  case 2:

    if (param_2 == 8) {

      (**(code **)(*param_1 + 0x45c))(0x3f800000);

      return 1;

    }

    break;

  case 3:

    if (param_2 == 8) {

      return 1;

    }

  }

  cVar2 = (**(code **)(*param_1 + 0xd8))();

  if ((cVar2 != '\0') && (param_1[0xac] != 0)) {

    uVar3 = (**(code **)(*(int *)param_1[0xac] + 0x338))(param_2,param_3);

    return uVar3;

  }

  return 0;

}
