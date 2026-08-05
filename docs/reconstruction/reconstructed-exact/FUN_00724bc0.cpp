// =============================================================================
// FUN_00724bc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00724bc0
// Address:   0x00724bc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00724bc0 @ 0x00724bc0
// Stable ID: aa_00724bc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_0071f0f0, FUN_0071f760, FUN_0071f8a0, FUN_0071fc20, FUN_007227e0, FUN_00724bc0, ROUND.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_00724bc0(uint32_t /* width from decompiler */ param_1,int param_2,char param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  int unaff_EDI;

  float10 fVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  

  if (((*(char *)(unaff_EDI + 0x2ec) != '\0') && (*(int *)(unaff_EDI + 0x2a8 + param_2 * 4) != 0))

     && (0.0 < *(float *)(unaff_EDI + 0x2d8) * *(float *)(unaff_EDI + 0x2dc))) {

    iVar3 = *(int *)(unaff_EDI + 0x2a8 + param_2 * 4);

    *(float *)(iVar3 + 0x1b0) =

         *(float *)(iVar3 + 400) * *(float *)(unaff_EDI + 0x2d8) * *(float *)(unaff_EDI + 0x2dc);

    iVar3 = FUN_0071f760(1);

    if ((iVar3 == 0) || (param_3 != '\0')) {

      iVar3 = *(int *)(unaff_EDI + 0x2a8 + param_2 * 4);

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x218) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x228) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x23c) = 1;

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x230) = 0;

      iVar3 = *(int *)(unaff_EDI + 0x2a8 + param_2 * 4);

      puVar1 = *(uint32_t /* width from decompiler */ **)(iVar3 + 0x10);

      if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

        piVar4 = (int *)0x0;

      }

      else if (*(int *)(iVar3 + 0x1c) == 0) {

        piVar4 = (int *)0x0;

      }

      else {

        piVar4 = (int *)*puVar1;

      }

      (**(code **)(*piVar4 + 0x34))(piVar4,0);

      if (*(int *)(*(int *)(unaff_EDI + 0x2a8 + param_2 * 4) + 0x14) != 0) {

        FUN_0071f0f0();

      }

      uVar2 = _DAT_00d217c4 & 1;

      *(uint8_t *)(*(int *)(unaff_EDI + 0x2a8 + param_2 * 4) + 0x1c4) = 1;

      if (uVar2 == 0) {

        _DAT_00d217c4 = _DAT_00d217c4 | 1;

        DAT_00d217c0 = *(uint *)(unaff_EDI + 0x2f0) >> 1;

      }

      if (((param_2 == 0) || (param_2 == 1)) &&

         (piVar4 = (int *)(unaff_EDI + 0x304), *(int *)(unaff_EDI + 0x304) == 0)) {

        piVar5 = (int *)FUN_0071f8a0(0);

        (**(code **)(*piVar5 + 0x20))(piVar5,piVar4);

        *piVar4 = *piVar4 - DAT_00d217c0;

      }

      *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x2a8 + param_2 * 4) + 0x1a4) = 0;

      uVar8 = 0;

      uVar7 = 0xffffffff;

      fVar6 = (float10)FUN_007227e0(*(uint32_t /* width from decompiler */ *)

                                     (*(int *)(unaff_EDI + 0x2a8 + param_2 * 4) + 0x1a4));

      FUN_0071fc20(0,param_1,(int)ROUND(fVar6),uVar7,uVar8);

    }

  }

  return;

}
