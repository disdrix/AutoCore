// =============================================================================
// FUN_004338a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004338a0
// Address:   0x004338a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004338a0 @ 0x004338a0
// Stable ID: aa_004338a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, while×1.
//  - Notable callees: FUN_004338a0.
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

uint FUN_004338a0(int param_1,uint param_2)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  byte *pbVar6;

  int local_10;

  uint local_c;

  

  if ((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 0x28) == 0)) {

    return 0;

  }

  if ((*(char *)(param_1 + 0x1a1) != '\0') && (*(uint *)(param_1 + 0x19c) == param_2)) {

    return (uint)*(byte *)(param_1 + 0x1a0);

  }

  uVar1 = 0;

  *(uint *)(param_1 + 0x19c) = param_2;

  *(uint8_t *)(param_1 + 0x1a1) = 1;

  local_10 = 200000;

  local_c = 0;

  iVar3 = *(int *)(param_1 + 0x2c);

  if (*(int *)(param_1 + 0x2c) == 0) {

    iVar3 = *(int *)(param_1 + 0x28);

  }

  if (0 < iVar3) {

    pbVar6 = (byte *)(*(int *)(param_1 + 4) + 0x29);

    uVar1 = 0;

    while (iVar5 = (uint)pbVar6[-1] - (param_2 & 0xff),

          iVar2 = (uint)*pbVar6 - (param_2 >> 8 & 0xff),

          iVar4 = (uint)pbVar6[1] - (param_2 >> 0x10 & 0xff),

          iVar2 = iVar2 * iVar2 + iVar5 * iVar5 + iVar4 * iVar4, iVar2 != 0) {

      if (iVar2 < local_10) {

        local_c = uVar1;

        local_10 = iVar2;

      }

      uVar1 = uVar1 + 1;

      pbVar6 = pbVar6 + 4;

      if (iVar3 <= (int)uVar1) {

        *(char *)(param_1 + 0x1a0) = (char)local_c;

        return local_c;

      }

    }

  }

  *(char *)(param_1 + 0x1a0) = (char)uVar1;

  return uVar1;

}
