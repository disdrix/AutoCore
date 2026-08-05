// =============================================================================
// FUN_0051f7b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f7b0
// Address:   0x0051f7b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0051f7b0 @ 0x0051f7b0
// Stable ID: aa_0051f7b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0051f7b0, GetTickCount.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 __fastcall FUN_0051f7b0(int param_1)



{

  int iVar1;

  float fVar2;

  DWORD DVar3;

  uint uVar4;

  float10 fVar5;

  float fVar6;

  

  iVar1 = *(int *)(param_1 + 0x504);

  DVar3 = GetTickCount();

  uVar4 = DVar3 - iVar1;

  if ((uVar4 < 0x493e1) && (iVar1 != 0)) {

    fVar2 = (float)(int)uVar4;

    if ((int)uVar4 < 0) {

      fVar2 = fVar2 + _DAT_00aaa5dc;

    }

    fVar6 = fVar2 * _DAT_009cef00;

    if (g_flOne <= fVar2 * _DAT_009cef00) {

      fVar6 = g_flOne;

    }

    return (float10)fVar6;

  }

  fVar5 = (float10)g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x504) = 0;

  return fVar5;

}
