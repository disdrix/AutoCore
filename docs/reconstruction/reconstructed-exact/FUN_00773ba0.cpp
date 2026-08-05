// =============================================================================
// FUN_00773ba0
// -----------------------------------------------------------------------------
// Stable ID: aa_00773ba0
// Address:   0x00773ba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00773ba0 @ 0x00773ba0
// Stable ID: aa_00773ba0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, while×1.
//  - Notable callees: FUN_007707d0×2, FUN_007701a0, FUN_00770440, FUN_00770650, FUN_00773470, FUN_00773ba0.
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

int FUN_00773ba0(uint8_t *param_1,int param_2)



{

  uint8_t *puVar1;

  uint8_t *puVar2;

  int *in_EAX;

  int iVar3;

  int local_10 [2];

  int local_8;

  

  puVar2 = param_1;

  if ((1 < param_2) && (param_2 < 0x41)) {

    if (*in_EAX == 0) {

      *param_1 = 0x30;

      param_1[1] = 0;

      return 0;

    }

    iVar3 = FUN_00770440();

    if ((iVar3 == 0) && (iVar3 = FUN_00770650(), iVar3 == 0)) {

      puVar1 = puVar2;

      if (local_8 == 1) {

        puVar1 = puVar2 + 1;

        *puVar2 = 0x2d;

        local_8 = 0;

      }

      while (local_10[0] != 0) {

        iVar3 = FUN_00773470(local_10,param_2,local_10,&param_1);

        if (iVar3 != 0) {

          FUN_007707d0();

          return iVar3;

        }

        *puVar1 = PTR_s_0123456789ABCDEFGHIJKLMNOPQRSTUV_00afa2a8[(int)param_1];

        puVar1 = puVar1 + 1;

      }

      FUN_007701a0();

      *puVar1 = 0;

      FUN_007707d0();

      iVar3 = 0;

    }

    return iVar3;

  }

  return -3;

}
