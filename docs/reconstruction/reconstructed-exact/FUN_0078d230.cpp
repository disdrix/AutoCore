// =============================================================================
// FUN_0078d230
// -----------------------------------------------------------------------------
// Stable ID: aa_0078d230
// Address:   0x0078d230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078d230 @ 0x0078d230
// Stable ID: aa_0078d230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_0078d230.
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

uint32_t /* width from decompiler */ __thiscall FUN_0078d230(int *param_1,int *param_2)



{

  int iVar1;

  char cVar2;

  int iVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  int unaff_EBX;

  float fVar6;

  int iStack_44;

  int iStack_40;

  int iStack_20;

  uint8_t auStack_1c [28];

  

  if (param_2 != (int *)0x0) {

    cVar2 = (**(code **)(*param_1 + 0x3d8))();

    if (cVar2 != '\0') {

      iVar3 = (**(code **)(*param_1 + 0x484))();

      (**(code **)(*param_1 + 0xa8))();

      DAT_00afa274 = DAT_00afa274 + 1;

      (**(code **)(*param_2 + 0x74))();

      cVar2 = (**(code **)(*param_1 + 0x490))();

      if (cVar2 == '\0') {

        (**(code **)(*param_2 + 4))();

      }

      else {

        (**(code **)(*param_2 + 4))();

      }

      fVar6 = (float)DAT_00d1e818 * (float)(param_1[0x248] * iVar3 + param_1[0x246]) * DAT_00aaa67c;

      iStack_40 = 0;

      iStack_20 = (int)((float)DAT_00d1e81c * (float)(param_1[0x249] * iVar3 + param_1[0x247]) *

                       DAT_00aaa678);

      iStack_44 = 1;

      iVar3 = (**(code **)(*param_2 + 0x120))(auStack_1c);

      iVar3 = *(int *)(iVar3 + 4);

      iVar1 = param_1[0x245];

      piVar4 = (int *)(**(code **)(*param_2 + 0x120))(&iStack_20,1,0);

      iStack_44 = param_1[0x244] + *piVar4 + (int)fVar6;

      iStack_40 = iVar3 + iVar1 + unaff_EBX;

      (**(code **)(*param_2 + 0x118))(&iStack_44);

      if (*(char *)((int)param_1 + 0x4fe) != '\0') {

        iVar3 = (**(code **)(*param_1 + 0x464))();

        if (iVar3 == -1) {

          iVar3 = *param_1;

          uVar5 = (**(code **)(*param_2 + 0x78))();

          (**(code **)(iVar3 + 0x45c))(uVar5);

        }

      }

      uVar5 = (**(code **)(*param_2 + 0x78))();

      return uVar5;

    }

  }

  return 0xffffffff;

}
