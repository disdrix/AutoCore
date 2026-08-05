// =============================================================================
// FUN_00988630
// -----------------------------------------------------------------------------
// Stable ID: aa_00988630
// Address:   0x00988630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00988630 @ 0x00988630
// Stable ID: aa_00988630
// Embedded strings (evidence for future rename):
//   - "UIMap%d"
//   - "UIMapExtents%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00752310×2, sprintf×2, FUN_00988630.
//  - Strings: "UIMap%d"; "UIMapExtents%d".
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

void FUN_00988630(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint32_t /* width from decompiler */ unaff_EDI;

  uint32_t /* width from decompiler */ local_9c;

  uint32_t /* width from decompiler */ local_98 [4];

  uint32_t /* width from decompiler */ local_88;

  uint32_t /* width from decompiler */ local_84;

  char local_80 [128];

  

  sprintf(local_80,"UIMap%d");

  if (*(int *)(unaff_EBX + 0xc) == 0) {

    local_9c = 0xffffffff;

    puVar1 = &local_9c;

  }

  else {

    puVar1 = (uint32_t /* width from decompiler */ *)FUN_00752310(local_98,local_80);

  }

  local_98[0] = *puVar1;

  sprintf(local_80,"UIMapExtents%d");

  puVar1 = &local_9c;

  if (*(int *)(unaff_EBX + 0xc) == 0) {

    local_9c = 0xffffffff;

  }

  else {

    puVar1 = (uint32_t /* width from decompiler */ *)FUN_00752310(&local_9c,local_80);

  }

  unaff_ESI[2] = *puVar1;

  *unaff_ESI = unaff_EDI;

  unaff_ESI[1] = local_98[0];

  unaff_ESI[4] = local_84;

  unaff_ESI[3] = local_88;

  return;

}
