// =============================================================================
// FUN_00860d90
// -----------------------------------------------------------------------------
// Stable ID: aa_00860d90
// Address:   0x00860d90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00860d90 @ 0x00860d90
// Stable ID: aa_00860d90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: Client_SendSectorPacket, FUN_00860d90.
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

uint32_t /* width from decompiler */ __fastcall FUN_00860d90(int *param_1)



{

  int iVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ auStack_20 [4];

  int iStack_10;

  int iStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  

  if (DAT_00d1b6d8 != 0) {

    iVar1 = param_1[0x15d];

    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x2b0) != 0)) {

      (**(code **)(*param_1 + 0xb0))(iVar1);

    }

    piVar2 = (int *)(**(code **)(*DAT_00d1b1f8 + 0x3ac))();

    if ((piVar2 != (int *)0x0) && (*(int *)(piVar2[0x2a] + 0x38) == 0x1a)) {

      iStack_10 = piVar2[0x58];

      iStack_c = piVar2[0x59];

      auStack_20[0] = 0x207e;

      uStack_8 = (**(code **)(*piVar2 + 0x25c))();

      Client_SendSectorPacket(&DAT_00d1a840,0x20,auStack_20);

      return 1;

    }

  }

  return 0;

}
