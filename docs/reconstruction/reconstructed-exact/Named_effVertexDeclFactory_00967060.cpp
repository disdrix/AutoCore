// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004406e0, FUN_004451c0, FUN_00967060, vog_LogMessage.
//  - Strings: ",

                 0xc3,3,".
//  - Return sites: 2.

// =============================================================================
// Named_effVertexDeclFactory_00967060
// -----------------------------------------------------------------------------
// Stable ID: aa_00967060
// Address:   0x00967060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effVertexDeclFactory"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_effVertexDeclFactory_00967060(int param_1)



{

  int iVar1;

  void *pvVar2;

  int iVar3;

  void *unaff_ESI;

  uint8_t local_14 [4];

  uint32_t /* width from decompiler */ uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009afa0c;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  iVar1 = (**(code **)(*(int *)*DAT_00d1f044 + 0x158))

                    ((int *)*DAT_00d1f044,*(uint32_t /* width from decompiler */ *)(param_1 + 4));

  if ((-1 < iVar1) && (local_14 != (uint8_t *)0x0)) {

    pvVar2 = operator_new(0x18);

    uStack_10 = 0;

    if (pvVar2 == (void *)0x0) {

      iVar1 = 0;

    }

    else {

      iVar1 = FUN_004451c0(pvVar2,param_1);

    }

    uStack_10 = 0xffffffff;

    if (*(int *)(puStack_8 + 0x14) == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(puStack_8 + 0x18) - *(int *)(puStack_8 + 0x14) >> 2;

    }

    *(uint8_t **)(iVar1 + 0x10) = local_14;

    *(int *)(iVar1 + 0x14) = iVar3;

    FUN_004406e0();

    ExceptionList = unaff_ESI;

    return 0;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effVertexDeclFactory.cpp",

                 0xc3,3,"Unable to build device vertex declaration object");

  ExceptionList = unaff_ESI;

  return 0xffffffff;

}
