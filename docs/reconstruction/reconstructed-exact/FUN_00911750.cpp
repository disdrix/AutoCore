// =============================================================================
// FUN_00911750
// -----------------------------------------------------------------------------
// Stable ID: aa_00911750
// Address:   0x00911750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00911750 @ 0x00911750
// Stable ID: aa_00911750
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_00791f30, FUN_0090f250, FUN_009114f0, FUN_00911750, fcos, fsin.
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

void __thiscall FUN_00911750(int *param_1,float param_2)



{

  char cVar1;

  float10 fVar2;

  float fVar3;

  

  *(uint8_t *)(param_1 + 0x143) = 0;

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    cVar1 = (**(code **)(*param_1 + 0xd0))();

    if (cVar1 != '\0') {

      if (DAT_00d17950 != '\0') {

        (**(code **)(*param_1 + 100))();

        DAT_00d17950 = '\0';

      }

      if (g_flZero <= (float)param_1[0x155]) {

        param_1[0x155] = (int)(param_2 + (float)param_1[0x155]);

      }

      FUN_009114f0();

      FUN_00791f30(param_2);

      FUN_0090f250(&param_2);

      if (((*(char *)(DAT_00d1b644 + 0x80) == '\0') && (*(char *)(DAT_00d1b644 + 0xf5) != '\0')) &&

         ((float)param_1[0x150] != g_flZero)) {

        fVar3 = (float)param_1[0x150] * param_2 + (float)param_1[0x14e];

        fVar2 = (float10)fsin((float10)fVar3);

        param_1[0x14e] = (int)fVar3;

        param_1[0x16b] = (int)(float)fVar2;

        fVar2 = (float10)fcos((float10)fVar3);

        param_1[0x16d] = (int)(float)-fVar2;

      }

    }

  }

  return;

}
