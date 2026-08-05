// =============================================================================
// FUN_00419f60
// -----------------------------------------------------------------------------
// Stable ID: aa_00419f60
// Address:   0x00419f60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00419f60 @ 0x00419f60
// Stable ID: aa_00419f60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00419e20, FUN_00419f60, _com_issue_errorex.
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

uint32_t /* width from decompiler */ * FUN_00419f60(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  ULONG UVar4;

  void *unaff_ESI;

  IUnknown *unaff_EDI;

  uint32_t /* width from decompiler */ *puVar5;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puVar2 = param_2;

  puVar1 = param_1;

  puStack_8 = &LAB_009bceb8;

  pvStack_c = ExceptionList;

  local_4 = 0;

  param_1 = (uint32_t /* width from decompiler */ *)0x0;

  if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = *param_2;

  }

  puVar5 = &param_1;

  ExceptionList = &pvStack_c;

  UVar4 = (*unaff_EDI->lpVtbl[0xc].AddRef)(unaff_EDI);

  if ((int)UVar4 < 0) {

    _com_issue_errorex(UVar4,unaff_EDI,(_GUID *)&DAT_00a86128);

  }

  *puVar1 = local_4;

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00419e20(uVar3,puVar5);

  }

  ExceptionList = unaff_ESI;

  return puVar1;

}
