// =============================================================================
// FUN_009a0180
// -----------------------------------------------------------------------------
// Stable ID: aa_009a0180
// Address:   0x009a0180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009a0180 @ 0x009a0180
// Stable ID: aa_009a0180
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00720d40, FUN_00722300, FUN_0076c3c0, FUN_0076c4d0, FUN_0076c500, FUN_009a0180, FUN_009a0294, Sleep.
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_009a0180(int param_1)



{

  float fVar1;

  uint uVar2;

  void *pvStack_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009b3bd9;

  pvStack_10 = ExceptionList;

  ExceptionList = &pvStack_10;

  FUN_0076c500(1000);

  local_8 = 0;

  *(uint8_t *)(param_1 + 0xc) = 1;

  do {

    Sleep(0x32);

    uVar2 = FUN_0076c3c0();

    if (199 < uVar2) {

      FUN_00720d40();

      fVar1 = (float)(int)uVar2;

      if ((int)uVar2 < 0) {

        fVar1 = fVar1 + _DAT_00aaa5dc;

      }

      FUN_00722300(fVar1 * g_flMsToSeconds_Inferred);

      FUN_0076c4d0();

    }

  } while (*(char *)(param_1 + 0xc) != '\0');

  FUN_009a0294();

  return;

}
