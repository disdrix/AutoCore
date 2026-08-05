// =============================================================================
// FUN_00979650
// -----------------------------------------------------------------------------
// Stable ID: aa_00979650
// Address:   0x00979650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00979650 @ 0x00979650
// Stable ID: aa_00979650
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00979310, entity.
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

/* ClientSpecialEvent_Respawn_ctor

   

   fastcall: ECX=dest vec*, EDX=entity+0x250 child, stack=this, flag, quat*

   Copies TFID from controlled entity (offset table +0x164), dest position/rotation,

   flag at this+0x38 (from packet+0x40), initializes phase state to 0.

   Called from Client_RecvSpecialEvent when type==0 and flag!=0. */



uint32_t /* width from decompiler */ * __fastcall

ClientSpecialEvent_Respawn_ctor

          (uint32_t /* width from decompiler */ *param_1,int param_2,uint32_t /* width from decompiler */ *param_3,uint8_t param_4,

          uint32_t /* width from decompiler */ *param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b02a3;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_3 = &PTR_LAB_00a766f8;

  *(uint8_t *)(param_3 + 1) = 0;

  local_4 = 0;

  *param_3 = &PTR_ClientSpecialEvent_Respawn_Update_00a76720;

  *(uint8_t *)(param_3 + 2) = 0;

  param_3[4] = 0;

  param_3[5] = 0;

  puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0x164 + param_2);

  param_3[10] = *puVar1;

  param_3[0xb] = puVar1[1];

  param_3[0xc] = puVar1[2];

  param_3[0xd] = puVar1[3];

  *(uint8_t *)(param_3 + 0xe) = param_4;

  param_3[0x10] = *param_1;

  param_3[0x11] = param_1[1];

  param_3[0x12] = param_1[2];

  param_3[0x13] = param_1[3];

  param_3[0x14] = *param_5;

  param_3[0x15] = param_5[1];

  param_3[0x16] = param_5[2];

  param_3[0x17] = param_5[3];

  param_3[0x18] = 0;

  param_3[0x19] = 0;

  *(uint8_t *)(param_3 + 0x1b) = 0;

  *(uint8_t *)((int)param_3 + 0x6d) = 0;

  FUN_00979310();

  ExceptionList = local_c;

  return param_3;

}
