// =============================================================================
// FUN_006808a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006808a0
// Address:   0x006808a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006808a0 @ 0x006808a0
// Stable ID: aa_006808a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: LeaveCriticalSection×2, EnterCriticalSection, FUN_006808a0.
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

uint32_t /* width from decompiler */ __thiscall FUN_006808a0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  LPCRITICAL_SECTION lpCriticalSection;

  int iVar1;

  uint uVar2;

  int iVar3;

  

  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x14);

  if (*(char *)(param_1 + 0x2c) != '\0') {

    EnterCriticalSection(lpCriticalSection);

  }

  if (*(int *)(param_1 + 0x10) != 0) {

    uVar2 = *(uint *)(param_1 + 0xc) >> 1;

    iVar3 = *(uint *)(param_1 + 0xc) + uVar2 * -2;

    if (*(uint *)(param_1 + 8) <= uVar2) {

      uVar2 = uVar2 - *(uint *)(param_1 + 8);

    }

    iVar1 = *(int *)(*(int *)(param_1 + 4) + uVar2 * 4);

    *param_2 = *(uint32_t /* width from decompiler */ *)(iVar1 + iVar3 * 8);

    param_2[1] = *(uint32_t /* width from decompiler */ *)(iVar1 + 4 + iVar3 * 8);

    if (*(int *)(param_1 + 0x10) != 0) {

      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;

      if ((uint)(*(int *)(param_1 + 8) * 2) <= *(uint *)(param_1 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

      }

      iVar3 = *(int *)(param_1 + 0x10) + -1;

      *(int *)(param_1 + 0x10) = iVar3;

      if (iVar3 == 0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

      }

    }

    if (*(char *)(param_1 + 0x2c) != '\0') {

      LeaveCriticalSection(lpCriticalSection);

    }

    return 1;

  }

  if (*(char *)(param_1 + 0x2c) != '\0') {

    LeaveCriticalSection(lpCriticalSection);

  }

  return 0;

}
