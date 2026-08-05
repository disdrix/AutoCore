// =============================================================================
// FUN_0067cde0
// -----------------------------------------------------------------------------
// Stable ID: aa_0067cde0
// Address:   0x0067cde0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067cde0 @ 0x0067cde0
// Stable ID: aa_0067cde0
// Embedded strings (evidence for future rename):
//   - "Session %lu: Received a fragment of size zero"
//   - "C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_0067cd80, FUN_0067cde0, FUN_00680c30, FUN_006810a0, FUN_0076cec0, thunk_FUN_0076c4d0, vog_LogMessage.
//  - Strings: "Session %lu: Received a fragment of size zero".
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

uint32_t /* width from decompiler */ __thiscall FUN_0067cde0(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  int *piVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a96ed;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (*(int *)(param_1 + 0x2a3c) != 0) {

    piVar1 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x40);

    ExceptionList = &local_c;

    *piVar1 = *piVar1 + 1;

  }

  if (*(char *)(param_1 + 0x2a12) == '\0') {

    *(uint8_t *)(param_1 + 0x2a12) = 1;

    pvVar2 = operator_new(0x1c);

    local_4 = 0;

    if (pvVar2 == (void *)0x0) {

      uVar3 = 0;

    }

    else {

      uVar3 = FUN_00680c30();

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a14) = uVar3;

  }

  local_4 = 0xffffffff;

  if (param_4 == 0) {

    uVar3 = FUN_0076cec0(&param_4,"Session %lu: Received a fragment of size zero",

                         *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a20));

    vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp",

                   0x569,2,uVar3);

  }

  else {

    FUN_006810a0(param_3,param_4);

  }

  if ((*(byte *)(param_2 + 0xd) & 0x20) != 0) {

    FUN_0067cd80(0,*(uint32_t /* width from decompiler */ *)(param_1 + 0x2a14));

    *(uint8_t *)(param_1 + 0x2a12) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a14) = 0;

    if (*(int *)(param_1 + 0x2a3c) != 0) {

      piVar1 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x48);

      *piVar1 = *piVar1 + 1;

    }

  }

  thunk_FUN_0076c4d0();

  ExceptionList = local_c;

  return 1;

}
