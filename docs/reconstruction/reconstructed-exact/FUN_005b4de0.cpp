// =============================================================================
// FUN_005b4de0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b4de0
// Address:   0x005b4de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b4de0 @ 0x005b4de0
// Stable ID: aa_005b4de0
// Embedded strings (evidence for future rename):
//   - "SetupFrondForTreeType"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0076cef0×2, FUN_005b4de0, FUN_0068a4d0, FUN_00752a00, FUN_0076cf00, FUN_0096f5d0, FUN_0096fdf0.
//  - Strings: "SetupFrondForTreeType".
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __fastcall FUN_005b4de0(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  char cVar2;

  int iVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a68bf;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("SetupFrondForTreeType");

  local_4 = 0;

  FUN_0068a4d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x50),2,0xffffffff,0xffffffff,0xffffffff);

  if (*(short *)(*(int *)(param_1 + 0x50) + 0x40) != 0) {

    *(uint *)(*(int *)(param_1 + 0x10) + 0xc4) =

         *(ushort *)(*(int *)(param_1 + 0x70) + *(int *)(*(int *)(param_1 + 0x50) + 0x3c) * 2) - 2;

    uVar1 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + 0xd0);

    cVar2 = FUN_0096fdf0();

    iVar3 = FUN_00752a00(uVar1,&DAT_00b05240);

    if ((iVar3 == -1) && (cVar2 != '\0')) {

      FUN_0096f5d0();

    }

    local_4 = 0xffffffff;

    FUN_0076cef0();

    ExceptionList = local_c;

    return 1;

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return 0;

}
