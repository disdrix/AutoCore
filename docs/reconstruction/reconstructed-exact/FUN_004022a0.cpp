// =============================================================================
// FUN_004022a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004022a0
// Address:   0x004022a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004022a0 @ 0x004022a0
// Stable ID: aa_004022a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×5, return×4.
//  - Notable callees: LeaveCriticalSection×3, FUN_004022a0, TryEnterCriticalSection.
//  - Return sites: 4.

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

uint __thiscall FUN_004022a0(int param_1,int *param_2,uint32_t /* width from decompiler */ *param_3)



{

  LPCRITICAL_SECTION lpCriticalSection;

  int iVar1;

  int iVar2;

  BOOL BVar3;

  uint32_t /* width from decompiler */ uVar4;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bc110;

  local_10 = ExceptionList;

  iVar1 = *param_2;

  if (*(char *)(param_1 + 0x28) != '\0') {

    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);

    ExceptionList = &local_10;

    BVar3 = TryEnterCriticalSection(lpCriticalSection);

    if (BVar3 != 0) {

      local_8 = 0;

      if (*param_2 == 0) {

        if (*(int *)(param_1 + 0x1c) == 0) {

          uVar4 = 0;

        }

        else {

          uVar4 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1c) + 4);

        }

        *param_3 = uVar4;

        *param_2 = *(int *)(param_1 + 0x1c);

        LeaveCriticalSection(lpCriticalSection);

        ExceptionList = local_10;

        return (uint)(*(int *)(param_1 + 0x1c) == 0);

      }

      iVar2 = *(int *)(iVar1 + 8);

      if (iVar2 != 0) {

        *param_2 = iVar2;

        *param_3 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 8) + 4);

        LeaveCriticalSection(lpCriticalSection);

        ExceptionList = local_10;

        return 0;

      }

      *param_2 = 0;

      *param_3 = 0;

      LeaveCriticalSection(lpCriticalSection);

      ExceptionList = local_10;

      return 1;

    }

  }

  ExceptionList = local_10;

  return 0x80070005;

}
