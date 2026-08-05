// =============================================================================
// FUN_00783e00
// -----------------------------------------------------------------------------
// Stable ID: aa_00783e00
// Address:   0x00783e00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00783e00 @ 0x00783e00
// Stable ID: aa_00783e00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00783e00.
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

uint32_t /* width from decompiler */ FUN_00783e00(ushort param_1)



{

  uint uVar1;

  uint uVar2;

  uint *in_EAX;

  uint uVar3;

  uint uVar4;

  int iVar5;

  

  uVar1 = *in_EAX;

  uVar2 = in_EAX[1];

  iVar5 = 0;

  if (uVar2 < uVar1) {

    uVar3 = uVar1 - uVar2;

  }

  else if (((uVar1 < uVar2) || (uVar3 = 0, (char)in_EAX[4] == '\0')) &&

          (uVar3 = uVar1, *(char *)((int)in_EAX + 0x11) != '\0')) {

    iVar5 = in_EAX[3] - uVar2;

  }

  uVar4 = (uint)param_1;

  if ((int)(iVar5 + uVar3) < (int)uVar4) {

    return 0;

  }

  if (uVar1 < uVar4) {

    *in_EAX = in_EAX[3] - (uint)(ushort)(param_1 - (short)*in_EAX);

  }

  else {

    *in_EAX = uVar1 - uVar4;

  }

  if (*in_EAX == uVar2) {

    *(uint8_t *)(in_EAX + 4) = 1;

  }

  return 1;

}
