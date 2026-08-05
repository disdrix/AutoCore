// =============================================================================
// FUN_0097dfe0
// -----------------------------------------------------------------------------
// Stable ID: aa_0097dfe0
// Address:   0x0097dfe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0097dfe0 @ 0x0097dfe0
// Stable ID: aa_0097dfe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: UI_CooldownGaugeWidget_ctor×2, FUN_00863f10, widget.
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

/* UI_CooldownGaugeWidget_ctor(this)

   

   Constructs quickbar cooldown gauge widget (0x4bc) used by

   i_d_qb_2d_btn_quickbar_cooldown.xml. */



void * UI_CooldownGaugeWidget_ctor(void *this)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b4a8a;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00863f10(this);

  *(uint32_t /* width from decompiler */ *)((int)this + 0x4a8) = DAT_00d1e504;

  *(undefined ***)this = &PTR_FUN_00a62454;

  *(uint32_t /* width from decompiler */ *)((int)this + 0x4b4) = 0xf;

  *(uint32_t /* width from decompiler */ *)((int)this + 0x4ac) = 0;

  *(uint8_t *)((int)this + 0x4b0) = 1;

  *(uint32_t /* width from decompiler */ *)((int)this + 0x4b8) = 4;

  ExceptionList = local_c;

  return this;

}
