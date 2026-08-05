// =============================================================================
// FUN_005b4ed0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b4ed0
// Address:   0x005b4ed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b4ed0 @ 0x005b4ed0
// Stable ID: aa_005b4ed0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005b4a30, FUN_005b4ed0, FUN_0068a4d0, ROUND.
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

void __fastcall FUN_005b4ed0(int param_1)



{

  int iVar1;

  int iVar2;

  

  FUN_0068a4d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x50),2,0xffffffff,0xffffffff,0xffffffff);

  if (g_flZero < *(float *)(*(int *)(param_1 + 0x50) + 0x74)) {

    FUN_005b4a30();

    (**(code **)(*DAT_00d1f610 + 0x1c))

              (DAT_00d1f610,0x18,(int)ROUND(*(float *)(*(int *)(param_1 + 0x50) + 0x74)));

    iVar1 = *(int *)(param_1 + 0x70);

    if (((iVar1 != 0) && (iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 0x3c), -1 < iVar2)) &&

       (*(short *)(iVar1 + iVar2 * 2) != 0)) {

      (**(code **)(*DAT_00b05340 + 0x148))

                (DAT_00b05340,5,0,0,*(uint16_t *)(*(int *)(param_1 + 0x50) + 0x4c),0,

                 *(ushort *)(iVar1 + *(int *)(*(int *)(param_1 + 0x50) + 0x3c) * 2) - 2);

    }

  }

  return;

}
