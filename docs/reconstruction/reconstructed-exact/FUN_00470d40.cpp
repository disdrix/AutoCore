// =============================================================================
// FUN_00470d40
// -----------------------------------------------------------------------------
// Stable ID: aa_00470d40
// Address:   0x00470d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00470d40 @ 0x00470d40
// Stable ID: aa_00470d40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×5, return×5.
//  - Notable callees: FUN_00470d40, FUN_00476d60.
//  - Return sites: 5.

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

void __thiscall FUN_00470d40(int param_1,int param_2,double param_3)



{

  uint16_t uVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ *unaff_EDI;

  

  if (param_2 == 0) {

    FUN_00476d60();

    return;

  }

  *(byte *)(in_EAX + 0x70) = *(byte *)(in_EAX + 0x70) | 0x80;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x138) = *unaff_EDI;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x13c) = unaff_EDI[1];

  uVar1 = *(uint16_t *)(unaff_EDI + 2);

  *(float *)(in_EAX + 0x134) = (float)param_3;

  *(uint16_t *)(in_EAX + 0x140) = uVar1;

  *(uint8_t *)(in_EAX + 0x130) = (uint8_t)param_2;

  *(uint *)(in_EAX + 0x70) = -(uint)(param_1 != 0) & 0x100 | *(uint *)(in_EAX + 0x70);

  if (param_1 == 0) {

    if (*(short *)((int)unaff_EDI + 2) != *(short *)(unaff_EDI + 1)) {

      return;

    }

    if (*(short *)((int)unaff_EDI + 2) != *(short *)((int)unaff_EDI + 6)) {

      return;

    }

  }

  else if ((*(byte *)(in_EAX + 0x126) & 2) != 0) {

    return;

  }

  *(byte *)(in_EAX + 0x69) = *(byte *)(in_EAX + 0x69) | 8;

  return;

}
