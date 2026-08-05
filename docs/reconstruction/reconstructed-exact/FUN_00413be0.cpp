// =============================================================================
// FUN_00413be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00413be0
// Address:   0x00413be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00413be0 @ 0x00413be0
// Stable ID: aa_00413be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×5, return×4.
//  - Notable callees: LeaveCriticalSection×3, FUN_00413be0, TryEnterCriticalSection.
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

uint __thiscall FUN_00413be0(int param_1,int *param_2,uint32_t /* width from decompiler */ *param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  int iVar2;
  BOOL BVar3;
  uint32_t /* width from decompiler */ uVar4;
  uint32_t /* width from decompiler */ uVar5;
  void *local_10;
  uint8_t *puStack_c;
  uint32_t /* width from decompiler */ local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009bc3d0;
  local_10 = ExceptionList;
  iVar1 = *param_2;
  if (*(char *)(param_1 + 0x28) != '\0') {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);
    ExceptionList = &local_10;
    BVar3 = TryEnterCriticalSection(lpCriticalSection);
    if (BVar3 != 0) {
      uVar4 = 0;
      local_8 = 0;
      if (*param_2 == 0) {
        iVar1 = *(int *)(param_1 + 0x1c);
        if (iVar1 == 0) {
          uVar5 = 0;
        }
        else {
          uVar4 = *(uint32_t /* width from decompiler */ *)(iVar1 + 8);
          uVar5 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc);
        }
        *param_3 = uVar4;
        param_3[1] = uVar5;
        *param_2 = *(int *)(param_1 + 0x1c);
        LeaveCriticalSection(lpCriticalSection);
        ExceptionList = local_10;
        return (uint)(*(int *)(param_1 + 0x1c) == 0);
      }
      iVar2 = *(int *)(iVar1 + 0x10);
      if (iVar2 != 0) {
        *param_2 = iVar2;
        iVar1 = *(int *)(iVar1 + 0x10);
        uVar4 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc);
        *param_3 = *(uint32_t /* width from decompiler */ *)(iVar1 + 8);
        param_3[1] = uVar4;
        LeaveCriticalSection(lpCriticalSection);
        ExceptionList = local_10;
        return 0;
      }
      *param_2 = 0;
      *param_3 = 0;
      param_3[1] = 0;
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = local_10;
      return 1;
    }
  }
  ExceptionList = local_10;
  return 0x80070005;
}
