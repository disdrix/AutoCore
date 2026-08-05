// =============================================================================
// FUN_004229e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004229e0
// Address:   0x004229e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004229e0 @ 0x004229e0
// Stable ID: aa_004229e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00422830, FUN_004229e0, RaiseException.
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

int FUN_004229e0(int *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *unaff_EBX;

  int iVar2;

  int unaff_EDI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puVar1 = param_1;

  puStack_8 = &LAB_009bcd88;

  local_c = ExceptionList;

  iVar2 = 0;

  if (*unaff_EBX == 0) {

    param_1 = (int *)0x0;

    local_4 = 0;

    ExceptionList = &local_c;

    iVar2 = (**(code **)*puVar1)(puVar1,&DAT_00a860ac,&param_1);

    if (-1 < iVar2) {

      *param_2 = *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0xc) + 0x10);

      if (*(int *)(*(int *)(unaff_EDI + 0xc) + 4) < 1) {

        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);

      }

      iVar2 = FUN_00422830();

    }

    local_4 = 0xffffffff;

    if (param_1 != (int *)0x0) {

      (**(code **)(*param_1 + 8))(param_1);

    }

  }

  ExceptionList = local_c;

  return iVar2;

}
