// =============================================================================
// FUN_006228f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006228f0
// Address:   0x006228f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006228f0 @ 0x006228f0
// Stable ID: aa_006228f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0058a5d0×2, FUN_00578270, FUN_006228f0.
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

void __fastcall FUN_006228f0(int param_1)



{

  float fVar1;

  short sVar2;

  short sVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  bool bVar6;

  uint32_t /* width from decompiler */ uVar7;

  float fVar8;

  

  fVar8 = (float)*(int *)(param_1 + 0x6c0) * *(float *)(param_1 + 0x18c);

  fVar1 = *(float *)(param_1 + 0x6c4);

  if (fVar1 != fVar8) {

    if ((fVar1 != g_flZero) && ((*(byte *)(param_1 + 0x648) & 0x40) != 0)) {

      FUN_0058a5d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,fVar1 * DAT_00aaa668,0x3f800000);

    }

    bVar6 = fVar8 != g_flZero;

    *(float *)(param_1 + 0x6c4) = fVar8;

    if (bVar6) {

      uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x620);

      iVar5 = **(int **)(param_1 + 0x18);

      sVar2 = *(short *)(param_1 + 0x61a);

      sVar3 = *(short *)(param_1 + 0x198);

      uVar7 = FUN_00578270(0,0,0);

      (**(code **)(iVar5 + 0x238))(0xf,uVar4,(int)(short)(sVar2 + sVar3),0,uVar7);

      if ((*(byte *)(param_1 + 0x648) & 0x40) != 0) {

        FUN_0058a5d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,*(uint32_t /* width from decompiler */ *)(param_1 + 0x6c4)

                     ,0x3f800000);

      }

    }

  }

  return;

}
