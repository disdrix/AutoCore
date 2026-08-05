// =============================================================================
// FUN_004265f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004265f0
// Address:   0x004265f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004265f0 @ 0x004265f0
// Stable ID: aa_004265f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×11, return×4.
//  - Notable callees: FUN_00424d10, FUN_00424f70, FUN_00425550, FUN_00426290, FUN_004265f0, FUN_00426760, FUN_004267c0.
//  - Return sites: 4.

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



void __thiscall FUN_004265f0(int *param_1,char param_2,int param_3)



{

  int iVar1;

  float fVar2;

  float fVar3;

  double dVar4;

  char cVar5;

  uint uVar6;

  int iVar7;

  

  if ((param_2 == '\0') && ((*(byte *)(param_1 + 0x2d) & 0xc) == 0)) {

    if ((uint)((param_1[0x30] - param_1[0x2e]) + param_3) < (uint)param_1[0x3d]) {

      return;

    }

    uVar6 = ((param_1[0x30] - param_1[0x2e]) - param_1[0x3d]) + param_3;

    param_1[0x30] = uVar6;

    if (1000 < uVar6) {

      param_1[0x30] = 1000;

    }

  }

  (**(code **)(*param_1 + 0x34))();

  cVar5 = FUN_00426760(2);

  if ((cVar5 == '\0') && (cVar5 = (**(code **)(*param_1 + 0x54))(), cVar5 != '\0')) {

    FUN_00424f70(param_1[0x3c]);

    param_1[0x2e] = param_3;

    FUN_00425550(param_1,0);

    FUN_004267c0();

    FUN_00424d10();

    return;

  }

  if ((*(byte *)(param_1 + 0x2d) & 0xc) != 0) {

    iVar1 = param_1[0x23];

    iVar7 = iVar1 - param_1[0x71];

    fVar2 = (float)iVar7;

    if (iVar7 < 0) {

      fVar2 = fVar2 + _DAT_00aaa5dc;

    }

    fVar3 = (float)(param_3 - param_1[0x72]);

    if (param_3 - param_1[0x72] < 0) {

      fVar3 = fVar3 + _DAT_00aaa5dc;

    }

    if (fVar3 * fVar2 * DAT_00a0f704 * g_flHardKillInterpolate <= g_flOne) {

      dVar4 = (double)iVar7;

      if (iVar7 < 0) {

        dVar4 = dVar4 + _DAT_00aaa728;

      }

      if (dVar4 <= _DAT_00aaa5c0) {

        return;

      }

    }

    if (param_1[0x71] != iVar1) {

      param_1[0x71] = iVar1;

      param_1[0x72] = param_3;

      FUN_00426290();

    }

  }

  return;

}
