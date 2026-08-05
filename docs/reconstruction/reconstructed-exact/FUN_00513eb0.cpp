// =============================================================================
// FUN_00513eb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00513eb0
// Address:   0x00513eb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00513eb0 @ 0x00513eb0
// Stable ID: aa_00513eb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_00512670×2, FUN_00513eb0.
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

uint32_t /* width from decompiler */ __thiscall FUN_00513eb0(int *param_1,int *param_2)



{

  ushort uVar1;

  int iVar2;

  ulonglong uVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  ushort uVar7;

  

  if ((param_2 != (int *)0x0) && (*(int *)(param_2[0x2a] + 0x34) == *(int *)(param_1[0x2a] + 0x34)))

  {

    uVar1 = *(ushort *)(*(int *)(param_1[0x2a] + 0x3c) + 0x4bc);

    if ((uVar1 != 0) && (uVar1 != 0xffff)) {

      uVar4 = (uint)*(ushort *)(param_2 + 0x60) + (uint)*(ushort *)(param_1 + 0x60);

      if (uVar4 <= uVar1) {

        *(short *)(param_1 + 0x60) = (short)uVar4;

        FUN_00512670();

        return 1;

      }

      uVar3 = (ulonglong)uVar4 % (ulonglong)(longlong)(int)(uint)uVar1;

      uVar7 = (ushort)uVar3;

      if ((int)uVar3 == 0) {

        uVar7 = uVar1;

      }

      *(ushort *)(param_1 + 0x60) = uVar7;

    }

    iVar2 = *param_1;

    iVar5 = (**(code **)(*param_2 + 0x25c))();

    iVar6 = (**(code **)(*param_1 + 0x25c))();

    (**(code **)(iVar2 + 0x260))(iVar5 + iVar6);

    FUN_00512670();

    return 1;

  }

  return 0;

}
