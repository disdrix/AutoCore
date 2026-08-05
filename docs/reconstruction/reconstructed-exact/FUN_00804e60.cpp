// =============================================================================
// FUN_00804e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00804e60
// Address:   0x00804e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00804e60 @ 0x00804e60
// Stable ID: aa_00804e60
// Embedded strings (evidence for future rename):
//   - "lgLcdReadSoftButtons failed: unplug?\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00804e00×4, FUN_0048a236, FUN_007a4480, FUN_00804d90, FUN_00804e60.
//  - Strings: "lgLcdReadSoftButtons failed: unplug?\n".
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

void FUN_00804e60(void)



{

  int in_EAX;

  int iVar1;

  int local_4;

  

  if (*(int *)(in_EAX + 0x88) != -1) {

    local_4 = 0;

    iVar1 = FUN_0048a236(*(int *)(in_EAX + 0x88),&local_4);

    if (iVar1 != 0) {

      FUN_007a4480(0xffffffff,&DAT_00a2c2a4,"lgLcdReadSoftButtons failed: unplug?\n");

      FUN_00804d90();

    }

    if (*(int *)(in_EAX + 0x98) != local_4) {

      FUN_00804e00();

      FUN_00804e00();

      FUN_00804e00();

      FUN_00804e00();

      *(int *)(in_EAX + 0x98) = local_4;

    }

  }

  return;

}
