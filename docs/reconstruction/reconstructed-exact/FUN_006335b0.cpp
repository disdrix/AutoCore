// =============================================================================
// FUN_006335b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006335b0
// Address:   0x006335b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006335b0 @ 0x006335b0
// Stable ID: aa_006335b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CVOGHBBase_AttachOwnerObject, CVOGHBBase_ctor, FUN_006335b0.
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

uint32_t /* width from decompiler */ * __thiscall

FUN_006335b0(uint32_t /* width from decompiler */ *param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint8_t param_5,uint32_t /* width from decompiler */ param_6,int param_7,int param_8)



{

  void *pOwnerObject;

  

  CVOGHBBase_ctor(param_1);

  param_1[4] = param_4;

  param_1[3] = param_4;

  *param_1 = &PTR_FUN_009e35b4;

  param_1[2] = param_3;

  if (param_2 == 0) {

    pOwnerObject = (void *)0x0;

  }

  else {

    pOwnerObject = (void *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2);

  }

  CVOGHBBase_AttachOwnerObject(param_1,pOwnerObject);

  *(uint8_t *)(param_1 + 10) = param_5;

  param_1[0xb] = param_6;

  param_1[9] = param_2;

  param_1[0xc] = *(uint32_t /* width from decompiler */ *)(param_7 + 0x160);

  param_1[0xd] = *(uint32_t /* width from decompiler */ *)(param_7 + 0x164);

  param_1[0xe] = *(uint32_t /* width from decompiler */ *)(param_7 + 0x168);

  param_1[0xf] = *(uint32_t /* width from decompiler */ *)(param_7 + 0x16c);

  param_1[0x10] = *(uint32_t /* width from decompiler */ *)(param_8 + 0x160);

  param_1[0x11] = *(uint32_t /* width from decompiler */ *)(param_8 + 0x164);

  param_1[0x12] = *(uint32_t /* width from decompiler */ *)(param_8 + 0x168);

  param_1[0x13] = *(uint32_t /* width from decompiler */ *)(param_8 + 0x16c);

  return param_1;

}
