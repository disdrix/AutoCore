// =============================================================================
// FUN_00999650
// -----------------------------------------------------------------------------
// Stable ID: aa_00999650
// Address:   0x00999650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00999650 @ 0x00999650
// Stable ID: aa_00999650
// Embedded strings (evidence for future rename):
//   - "Unable to open file to write VertexBuffer contents: %s"
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxVertexBufferImpl.cpp"
//   - "Failed to Serialize VertexBuffer: %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, goto×1.
//  - Notable callees: FUN_00766750×3, FUN_00414b60×2, FUN_005b2ba0×2, FUN_0076cec0×2, vog_LogMessage×2, CONCAT31, CloseHandle, FUN_004451c0.
//  - Strings: "Unable to open file to write VertexBuffer contents: %s"; "Failed to Serialize VertexBuffer: %s".
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __thiscall FUN_00999650(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  BOOL BVar4;

  undefined **local_5c;

  uint32_t /* width from decompiler */ local_58;

  HANDLE local_54;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint8_t local_48 [16];

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  undefined ***local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  uVar3 = param_2;

  puStack_8 = &LAB_009afbac;

  local_c = ExceptionList;

  local_5c = &PTR_FUN_00a9d84c;

  local_58 = 0;

  local_54 = (HANDLE)0xffffffff;

  local_50 = 0;

  local_4c = 0;

  local_4 = 0;

  ExceptionList = &local_c;

  iVar2 = FUN_007669d0(param_2,6,0);

  if (iVar2 < 0) {

    uVar3 = FUN_0076cec0(&param_2,"Unable to open file to write VertexBuffer contents: %s",uVar3);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxVertexBufferImpl.cpp",0x2e0,3,

                   uVar3);

    local_4 = 0xffffffff;

    FUN_00766750();

    ExceptionList = local_c;

    return 0xffffffff;

  }

  FUN_004451c0(local_48,param_1 + 0x24);

  local_30 = &local_5c;

  local_2c = 0;

  local_24 = 0;

  local_20 = 0;

  local_1c = 0;

  local_18 = 0;

  local_4._0_1_ = 2;

  local_14 = 1;

  local_10 = 0;

  FUN_007670a0();

  local_4 = CONCAT31(local_4._1_3_,3);

  iVar2 = gfxVertexBufferImpl_Serialize(&local_30);

  if (iVar2 < 0) {

    uVar3 = FUN_0076cec0(&param_2,"Failed to Serialize VertexBuffer: %s",param_2);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxVertexBufferImpl.cpp",0x2e7,3,

                   uVar3);

    FUN_005b2ba0();

    FUN_00414b60();

    local_4 = 0xffffffff;

    FUN_00766750();

    ExceptionList = local_c;

    return 0xffffffff;

  }

  FUN_00447ea0();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = local_34;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = local_38;

  cVar1 = (*(code *)local_5c[8])();

  if (cVar1 != '\0') {

    BVar4 = CloseHandle(local_54);

    if (BVar4 == 0) goto LAB_009997e7;

  }

  local_54 = (HANDLE)0xffffffff;

LAB_009997e7:

  FUN_005b2ba0();

  FUN_00414b60();

  local_4 = 0xffffffff;

  FUN_00766750();

  ExceptionList = local_c;

  return 0;

}
