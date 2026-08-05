// =============================================================================
// Named_CalleeOf_Named_gfxDevice_0075e710
// -----------------------------------------------------------------------------
// Stable ID: aa_0075e710
// Callee of Named_gfxDevice (+1 other named callers)
// Address:   0x0075e710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDevice: callee helper. Evidence string: "\t BackBuffer [%ux%u], format=0x%08X, #%u\n". Supports parent flow (not a free-standing entry point). Named_gfxDevice (+1 other named callers).
// Embedded strings (evidence):
//   - "\t BackBuffer [%ux%u], format=0x%08X, #%u\n"
//   - "\t MultiSampleType = %d, Quality = %u\n"
//   - "FLIP"
//   - "COPY"
//   - "DISCARD"
//   - "\t SwapEffect = %s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0076c130×10, FUN_0075e710.
//  - Strings: "\t BackBuffer [%ux%u], format=0x%08X, #%u\n"; "\t MultiSampleType = %d, Quality = %u\n"; "FLIP"; "COPY".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxDevice (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_gfxDevice_0075e710(void)



{

  char *pcVar1;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  FUN_0076c130("\t BackBuffer [%ux%u], format=0x%08X, #%u\n",*unaff_ESI,unaff_ESI[1],unaff_ESI[2],

               unaff_ESI[3]);

  FUN_0076c130("\t MultiSampleType = %d, Quality = %u\n",unaff_ESI[4],unaff_ESI[5]);

  if (unaff_ESI[6] == 2) {

    pcVar1 = "FLIP";

  }

  else {

    pcVar1 = "COPY";

    if (unaff_ESI[6] != 3) {

      pcVar1 = "DISCARD";

    }

  }

  FUN_0076c130("\t SwapEffect = %s\n",pcVar1);

  FUN_0076c130("\t hDeviceWindow = 0x%08X\n",unaff_ESI[7]);

  FUN_0076c130("\t Fullscreen = %d\n",unaff_ESI[8] == 0);

  FUN_0076c130("\t EnableAutoDepthStencil = %d\n",unaff_ESI[9]);

  FUN_0076c130("\t AutoDepthStencilFormat = %d\n",unaff_ESI[10]);

  FUN_0076c130("\t Flags = 0x%08X\n",unaff_ESI[0xb]);

  FUN_0076c130("\t FullScreen_RefreshRateInHz = %u\n",unaff_ESI[0xc]);

  FUN_0076c130("\t PresentationInterval = 0x%X\n",unaff_ESI[0xd]);

  return;

}
