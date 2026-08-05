// =============================================================================
// FUN_00436030
// -----------------------------------------------------------------------------
// Stable ID: aa_00436030
// Address:   0x00436030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00436030 @ 0x00436030
// Stable ID: aa_00436030
// Embedded strings (evidence for future rename):
//   - "%+#.8g"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00436030, FUN_00767160.
//  - Strings: "%+#.8g".
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

uint32_t /* width from decompiler */ __fastcall FUN_00436030(float *param_1)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  if (unaff_ESI[7] != 0) {

    if (-1 < in_EAX + -1) {

      do {

        uVar2 = FUN_00767160("%+#.8g",(double)*param_1);

        unaff_ESI[1] = unaff_ESI[1] | uVar2;

        param_1 = param_1 + 1;

        in_EAX = in_EAX + -1;

      } while (in_EAX != 0);

    }

    unaff_ESI[8] = 0;

    uVar2 = (**(code **)(*(int *)*unaff_ESI + 0x18))();

    unaff_ESI[1] = unaff_ESI[1] | uVar2;

    return 0;

  }

  uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))();

  return uVar1;

}
