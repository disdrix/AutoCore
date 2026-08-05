// =============================================================================
// FUN_005dcb60
// -----------------------------------------------------------------------------
// Stable ID: aa_005dcb60
// Address:   0x005dcb60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005dcb60 @ 0x005dcb60
// Stable ID: aa_005dcb60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_005dc5f0, FUN_005dcb60, FUN_00642a90.
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

void __fastcall FUN_005dcb60(int param_1)



{

  int iVar1;

  void *pvVar2;

  CVOGHBBase *this;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a730f;

  local_c = ExceptionList;

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

  if (((iVar1 != 0) && (*(int *)(param_1 + 0x15c) != 0)) && (*(char *)(iVar1 + 0x7e) != '\0')) {

    if (*(float *)(param_1 + 0x154) == g_flZero) {

      ExceptionList = &local_c;

      FUN_005dc5f0(1);

      ExceptionList = local_c;

      return;

    }

    ExceptionList = &local_c;

    pvVar2 = operator_new(0x28);

    local_4 = 0;

    if (pvVar2 == (void *)0x0) {

      this = (CVOGHBBase *)0x0;

    }

    else {

      this = (CVOGHBBase *)FUN_00642a90(param_1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x154));

    }

    local_4 = 0xffffffff;

    CVOGHBBase_Start(this);

    CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) +

                                 0xe4ec),this);

  }

  ExceptionList = local_c;

  return;

}
