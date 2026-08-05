// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Auth_Setup_of_CNDAuthClient_faile_007293f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007293f0
// Callee of Named_CalleeOf_Auth_Setup_of_CNDAuthClient_failed
// Address:   0x007293f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Auth_Setup_of_CNDAuthClient_failed: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, DES_InitializeCipher, FUN_0046e310, FUN_0046f150, FUN_0046f1c0, FUN_0046f230, FUN_0046f2a0, FUN_0046f310.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Auth_Setup_of_CNDAuthClient_failed
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

int Named_CalleeOf_Named_CalleeOf_Auth_Setup_of_CNDAuthClient_faile_007293f0(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b06f1;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0046e310(param_1);

  local_4 = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  FUN_0067b070();

  local_4._0_1_ = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

  *(uint8_t *)(param_1 + 0x40) = 0;

  uVar1 = FUN_004933f0();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = uVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 0;

  local_4 = CONCAT31(local_4._1_3_,2);

  DES_InitializeCipher();

  FUN_0046f150(&LAB_0046e9c0,param_1);

  FUN_0046f1c0(&LAB_0046e9e0,param_1);

  FUN_0046f230(&LAB_0046ea00,param_1);

  FUN_0046f2a0(&LAB_0046ea20,param_1);

  FUN_0046f310(&LAB_0046ea40,param_1);

  FUN_0046f380(&LAB_0046ea50,param_1);

  FUN_0046f3f0(&LAB_0046ea70,param_1);

  FUN_0046f460(&LAB_0046ea90,param_1);

  FUN_0046f4d0(&LAB_0046eaa0,param_1);

  FUN_0046f540(&LAB_0046eac0,param_1);

  FUN_0046f5b0(&LAB_0046eae0,param_1);

  ExceptionList = local_c;

  return param_1;

}
