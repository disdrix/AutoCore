// =============================================================================
// FUN_00821af0
// -----------------------------------------------------------------------------
// Stable ID: aa_00821af0
// Address:   0x00821af0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00821af0 @ 0x00821af0
// Stable ID: aa_00821af0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, return×1.
//  - Notable callees: FUN_004033e0×2, block×2, FUN_00821af0.
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

/* WARNING: Removing unreachable block (ram,0x00821b69) */

/* WARNING: Removing unreachable block (ram,0x00821bba) */



void FUN_00821af0(void)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  uint32_t /* width from decompiler */ *unaff_ESI;

  int unaff_EDI;

  char local_8c [128];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009abbd9;

  local_c = ExceptionList;

  pcVar3 = local_8c;

  ExceptionList = &local_c;

  *unaff_ESI = 0x1000;

  FUN_004033e0();

  iVar2 = 4 - (int)pcVar3;

  do {

    cVar1 = *pcVar3;

    pcVar3[(int)unaff_ESI + iVar2] = cVar1;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  local_4 = 0xffffffff;

  pcVar3 = local_8c;

  FUN_004033e0();

  iVar2 = 0x25 - (int)pcVar3;

  do {

    cVar1 = *pcVar3;

    pcVar3[(int)unaff_ESI + iVar2] = cVar1;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  unaff_ESI[0x13] = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x6c);

  unaff_ESI[0x12] = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x70);

  ExceptionList = local_c;

  return;

}
