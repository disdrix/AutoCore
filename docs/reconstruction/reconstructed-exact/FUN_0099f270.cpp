// =============================================================================
// FUN_0099f270
// -----------------------------------------------------------------------------
// Stable ID: aa_0099f270
// Address:   0x0099f270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0099f270 @ 0x0099f270
// Stable ID: aa_0099f270
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~93 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_00414a50, FUN_00414b60, FUN_00414bc0, FUN_00414c20, FUN_0099f270.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_0099f270(float param_1,float param_2)



{

  int *piVar1;

  int *piVar2;

  float fVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  float *pfVar6;

  int unaff_EDI;

  float fVar7;

  float *local_28 [7];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1f5e;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *(uint *)(unaff_EDI + 0xbc) = *(uint *)(unaff_EDI + 0xbc) | 1;

  uVar4 = FUN_00414bc0(0x112);

  local_4 = 0;

  iVar5 = FUN_00414c20(4,uVar4,0x20,0);

  local_4 = 0xffffffff;

  FUN_00414b60();

  if (iVar5 < 0) {

    ExceptionList = local_c;

    return 0xffffffff;

  }

  iVar5 = *(int *)(unaff_EDI + 0x14);

  piVar1 = *(int **)(iVar5 + 0x10);

  if (piVar1 != (int *)0x0) {

    local_28[0] = *(float **)(iVar5 + 0x14);

    piVar2 = (int *)*piVar1;

    if (piVar2 == (int *)0x0) {

      pfVar6 = (float *)0x0;

    }

    else {

      iVar5 = (**(code **)(*piVar2 + 0x2c))

                        (piVar2,piVar1[2] * (int)local_28[0],piVar1[2] * *(int *)(iVar5 + 0x18),

                         local_28,0x800);

      if (iVar5 < 0) {

        pfVar6 = (float *)0x0;

      }

      else {

        piVar1[4] = piVar1[4] + 1;

        pfVar6 = local_28[0];

      }

    }

    fVar3 = g_flOne;

    if (pfVar6 != (float *)0x0) {

      pfVar6[1] = 0.0;

      pfVar6[2] = param_1;

      fVar7 = 0.0 - param_1;

      *pfVar6 = fVar7;

      pfVar6[3] = 0.0;

      pfVar6[4] = fVar3;

      pfVar6[5] = 0.0;

      pfVar6[6] = 0.0;

      pfVar6[7] = 0.0;

      pfVar6[8] = param_1;

      pfVar6[9] = 0.0;

      pfVar6[10] = param_1;

      pfVar6[0xb] = 0.0;

      pfVar6[0xc] = fVar3;

      pfVar6[0xd] = 0.0;

      pfVar6[0xe] = param_2;

      pfVar6[0xf] = 0.0;

      pfVar6[0x10] = fVar7;

      pfVar6[0x11] = 0.0;

      pfVar6[0x12] = fVar7;

      pfVar6[0x13] = 0.0;

      pfVar6[0x14] = fVar3;

      pfVar6[0x15] = 0.0;

      pfVar6[0x16] = 0.0;

      pfVar6[0x17] = param_2;

      pfVar6[0x18] = param_1;

      pfVar6[0x19] = 0.0;

      pfVar6[0x1a] = fVar7;

      pfVar6[0x1b] = 0.0;

      pfVar6[0x1c] = fVar3;

      pfVar6[0x1d] = 0.0;

      pfVar6[0x1e] = param_2;

      pfVar6[0x1f] = param_2;

      FUN_00414a50();

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xa8) = 2;

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xac) = 5;

      ExceptionList = local_c;

      return 0;

    }

  }

  ExceptionList = local_c;

  return 0xffffffff;

}
