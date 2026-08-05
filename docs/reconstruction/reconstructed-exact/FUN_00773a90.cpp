// =============================================================================
// FUN_00773a90
// -----------------------------------------------------------------------------
// Stable ID: aa_00773a90
// Address:   0x00773a90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00773a90 @ 0x00773a90
// Stable ID: aa_00773a90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, do×1, while×1.
//  - Notable callees: FUN_007707d0×2, FUN_007701a0, FUN_00770440, FUN_00770650, FUN_00773470, FUN_00773a90.
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

int __thiscall FUN_00773a90(int *param_1,uint8_t *param_2,int param_3)



{

  int in_EAX;

  int iVar1;

  uint8_t *puVar2;

  int local_14;

  int local_10 [2];

  int local_8;

  

  if (((in_EAX < 3) || (param_3 < 2)) || (0x40 < param_3)) {

    return -3;

  }

  if (*param_1 == 0) {

    *param_2 = 0x30;

    param_2[1] = 0;

    return 0;

  }

  iVar1 = FUN_00770440();

  if (iVar1 == 0) {

    iVar1 = FUN_00770650();

  }

  if (iVar1 == 0) {

    puVar2 = param_2;

    if (local_8 == 1) {

      puVar2 = param_2 + 1;

      *param_2 = 0x2d;

      local_8 = 0;

      in_EAX = in_EAX + -1;

    }

    do {

      if (local_10[0] == 0) break;

      iVar1 = FUN_00773470(local_10,param_3,local_10,&local_14);

      if (iVar1 != 0) {

        FUN_007707d0();

        return iVar1;

      }

      *puVar2 = PTR_s_0123456789ABCDEFGHIJKLMNOPQRSTUV_00afa2a8[local_14];

      in_EAX = in_EAX + -1;

      puVar2 = puVar2 + 1;

    } while (in_EAX != 1);

    FUN_007701a0();

    *puVar2 = 0;

    FUN_007707d0();

    iVar1 = 0;

  }

  return iVar1;

}
