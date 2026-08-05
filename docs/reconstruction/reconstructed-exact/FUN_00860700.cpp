// =============================================================================
// FUN_00860700
// -----------------------------------------------------------------------------
// Stable ID: aa_00860700
// Address:   0x00860700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00860700 @ 0x00860700
// Stable ID: aa_00860700
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_00413be0×2, CVOGReaction_ResolveObjectTarget, DeleteCriticalSection, FUN_0040dc40, FUN_004294f0, FUN_00571260, FUN_0085fd80, FUN_008605b0.
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

void FUN_00860700(void)



{

  int iVar1;

  int *unaff_ESI;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  undefined **local_38;

  _RTL_CRITICAL_SECTION local_34;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  char local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b376c;

  local_c = ExceptionList;

  if (unaff_ESI[0x15b] != 0) {

    local_38 = &PTR_FUN_00a34140;

    local_18 = 0;

    local_1c = 0;

    local_14 = 0;

    local_10 = '\0';

    ExceptionList = &local_c;

    InitializeCriticalSection(&local_34);

    local_4 = 0;

    FUN_0085fd80();

    FUN_00571260(&local_38,(char)unaff_ESI[0x159]);

    local_44 = 0;

    FUN_004294f0();

    iVar1 = FUN_00413be0(&local_44,&local_40);

    while (iVar1 == 0) {

      iVar1 = CVOGReaction_ResolveObjectTarget(1,local_40,local_3c);

      if (iVar1 != 0) {

        FUN_008605b0();

      }

      iVar1 = FUN_00413be0(&local_44,&local_40);

    }

    if (local_10 != '\0') {

      local_10 = '\0';

      LeaveCriticalSection(&local_34);

    }

    FUN_00931d60();

    (**(code **)(*unaff_ESI + 0x34c))();

    local_4 = 0xffffffff;

    local_38 = &PTR_FUN_00a34140;

    FUN_0040dc40();

    DeleteCriticalSection(&local_34);

  }

  ExceptionList = local_c;

  return;

}
