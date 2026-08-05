// =============================================================================
// FUN_00710880
// -----------------------------------------------------------------------------
// Stable ID: aa_00710880
// Address:   0x00710880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00710880 @ 0x00710880
// Stable ID: aa_00710880
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: return×10, if×9.
//  - Notable callees: FUN_00710880, FUN_007112e0, FUN_00711350, FUN_007113d0.
//  - Return sites: 10.

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

uint32_t /* width from decompiler */ FUN_00710880(int *param_1,int *param_2)



{

  uint8_t local_88 [68];

  uint8_t local_44 [68];

  

  if (param_2 == (int *)0x0) {

    return 0x181a;

  }

  if (param_2[2] == 0) {

    return 0x17f2;

  }

  if (*param_2 == 0) {

    return 0x17ed;

  }

  if (*(ushort *)(param_2 + 3) <= *(ushort *)((int)param_2 + 0xe)) {

    return 0x1801;

  }

  if (*(ushort *)(param_2 + 3) <= *(ushort *)((int)param_2 + 0x12)) {

    return 0x1806;

  }

  if (7 < *(byte *)(param_2 + 4)) {

    return 0x17f7;

  }

  if (7 < *(byte *)(param_2 + 5)) {

    return 0x17fc;

  }

  if ((param_1 != (int *)0x0) && (*param_1 == 0xface)) {

    if ((char)param_1[3] != '\n') {

      return 0x17de;

    }

    FUN_007113d0(*param_2,param_1[4],local_88);

    FUN_00711350(local_44,param_1[4],local_88);

    FUN_007112e0(local_44,param_2[2],(int)param_2 + 0x12,param_2 + 5,(short)param_2[3],0);

    return 0;

  }

  return 0x17d4;

}
