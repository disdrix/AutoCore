// =============================================================================
// FUN_00980590
// -----------------------------------------------------------------------------
// Stable ID: aa_00980590
// Address:   0x00980590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00980590 @ 0x00980590
// Stable ID: aa_00980590
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, return×1.
//  - Notable callees: FUN_00980250, FUN_00980590.
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

void FUN_00980590(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5)



{

  char cVar1;

  int iVar2;

  char *in_EAX;

  char *unaff_ESI;

  char *unaff_EDI;

  uint32_t /* width from decompiler */ local_1e8;

  char local_1e4 [50];

  char local_1b2 [400];

  char local_22 [18];

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = param_5;

  local_c = param_3;

  local_8 = param_4;

  local_1e8 = 0;

  local_10 = param_2;

  iVar2 = -(int)in_EAX;

  do {

    cVar1 = *in_EAX;

    in_EAX[(int)(local_1b2 + iVar2)] = cVar1;

    in_EAX = in_EAX + 1;

  } while (cVar1 != '\0');

  iVar2 = -(int)unaff_ESI;

  do {

    cVar1 = *unaff_ESI;

    unaff_ESI[(int)(local_1e4 + iVar2)] = cVar1;

    unaff_ESI = unaff_ESI + 1;

  } while (cVar1 != '\0');

  iVar2 = -(int)unaff_EDI;

  do {

    cVar1 = *unaff_EDI;

    unaff_EDI[(int)(local_22 + iVar2)] = cVar1;

    unaff_EDI = unaff_EDI + 1;

  } while (cVar1 != '\0');

  FUN_00980250(&local_1e8,1);

  return;

}
