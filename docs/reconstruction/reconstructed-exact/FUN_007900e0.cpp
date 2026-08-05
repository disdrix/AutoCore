// =============================================================================
// FUN_007900e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007900e0
// Address:   0x007900e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007900e0 @ 0x007900e0
// Stable ID: aa_007900e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×5, return×4.
//  - Notable callees: FUN_007900e0, GetKeyState.
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

uint32_t /* width from decompiler */ __thiscall FUN_007900e0(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  SHORT SVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    if ((param_1[0x12f] != 0) &&

       (cVar1 = (**(code **)(*(int *)param_1[0x12f] + 0x354))(param_2,param_3), cVar1 != '\0')) {

      return 1;

    }

    if (param_2 == 9) {

      SVar2 = GetKeyState(0x10);

      iVar4 = (**(code **)(*param_1 + 0x3d4))(~(byte)((ushort)SVar2 >> 0xf) & 1);

      if ((iVar4 != 0) && (iVar4 != param_1[0x12f])) {

        (**(code **)(*param_1 + 0x3bc))(iVar4);

      }

      return 1;

    }

    if ((param_2 == 0xd) && (-1 < param_1[0x126])) {

      uVar3 = (**(code **)(*param_1 + 0x338))(8,param_1[0x126]);

      return uVar3;

    }

  }

  return 0;

}
