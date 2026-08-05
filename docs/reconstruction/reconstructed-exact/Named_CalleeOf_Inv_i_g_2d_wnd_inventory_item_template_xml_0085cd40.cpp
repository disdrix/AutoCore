// =============================================================================
// Named_CalleeOf_Inv_i_g_2d_wnd_inventory_item_template_xml_0085cd40
// -----------------------------------------------------------------------------
// Stable ID: aa_0085cd40
// Callee of Inv_i_g_2d_wnd_inventory_item_template_xml
// Address:   0x0085cd40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Inv_i_g_2d_wnd_inventory_item_template_xml: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0085cd40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Inv_i_g_2d_wnd_inventory_item_template_xml
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Inv_i_g_2d_wnd_inventory_item_template_xml_0085cd40(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  float fVar1;

  

  *in_EAX = 0;

  in_EAX[1] = 0;

  in_EAX[2] = 0;

  in_EAX[4] = 0x14;

  in_EAX[3] = 10;

  in_EAX[5] = 0x20;

  in_EAX[7] = 10;

  in_EAX[9] = 0x20;

  in_EAX[6] = 0x15;

  in_EAX[8] = 0x29;

  in_EAX[0xb] = 10;

  in_EAX[0xd] = 0x20;

  in_EAX[10] = 0x2a;

  in_EAX[0xc] = 0x3e;

  fVar1 = (float)DAT_00d1e818 * _DAT_00aaa7d8;

  in_EAX[0xf] = (int)((float)DAT_00d1e81c * _DAT_00aaa7d4);

  in_EAX[0xe] = (int)fVar1;

  fVar1 = (float)DAT_00d1e818 * _DAT_00aaa7d0;

  in_EAX[0x11] = (int)((float)DAT_00d1e81c * _DAT_00aaa7cc);

  in_EAX[0x10] = (int)fVar1;

  fVar1 = (float)DAT_00d1e818 * _DAT_00a10e38;

  in_EAX[0x13] = (int)((float)DAT_00d1e81c * _DAT_00aaa7b0);

  in_EAX[0x12] = (int)fVar1;

  in_EAX[0x14] = 0;

  in_EAX[0x15] = 0;

  in_EAX[0x16] = 0;

  return;

}
