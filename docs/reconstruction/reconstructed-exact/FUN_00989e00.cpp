// =============================================================================
// FUN_00989e00
// -----------------------------------------------------------------------------
// Stable ID: aa_00989e00
// Address:   0x00989e00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00989e00 @ 0x00989e00
// Stable ID: aa_00989e00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: EnterCriticalSection, FUN_00466da0, FUN_00989b60, FUN_00989e00, FUN_00996c80, LeaveCriticalSection.
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

void __thiscall FUN_00989e00(int param_1,uint32_t /* width from decompiler */ *param_2,char *param_3)



{

  LPCRITICAL_SECTION lpCriticalSection;

  char *pcVar1;

  char cVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ local_18;

  LPCRITICAL_SECTION local_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  pcVar1 = param_3;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009adce1;

  local_c = ExceptionList;

  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {

    *param_2 = DAT_00d1eac0;

    return;

  }

  param_3 = (char *)0x0;

  ExceptionList = &local_c;

  cVar2 = FUN_00989b60(pcVar1,&param_3);

  puVar3 = (uint32_t /* width from decompiler */ *)param_3;

  if (cVar2 == '\0') {

    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x68);

    local_14 = lpCriticalSection;

    if (*(char *)(param_1 + 0x80) != '\0') {

      EnterCriticalSection(lpCriticalSection);

    }

    local_4 = 0;

    local_18 = FUN_00996c80(pcVar1);

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_00466da0(param_3,&local_18);

    puVar3 = (uint32_t /* width from decompiler */ *)*puVar3;

    if (*(char *)(param_1 + 0x80) != '\0') {

      LeaveCriticalSection(lpCriticalSection);

      *param_2 = *puVar3;

      ExceptionList = local_c;

      return;

    }

  }

  *param_2 = *puVar3;

  ExceptionList = local_c;

  return;

}
