// =============================================================================
// FUN_0055b270
// -----------------------------------------------------------------------------
// Stable ID: aa_0055b270
// Address:   0x0055b270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055b270 @ 0x0055b270
// Stable ID: aa_0055b270
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, goto×1.
//  - Notable callees: FUN_0055a5f0×2, FUN_0055a400, FUN_0055a4a0, FUN_0055b0e0, FUN_0055b270, FUN_0055b530, FUN_00787280.
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

void FUN_0055b270(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4)



{

  bool bVar1;

  char cVar2;

  void **ppvVar3;

  void *pvVar4;

  void *local_14;

  void *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a4905;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  local_14 = (void *)FUN_0055b530(param_1);

  if (local_14 != DAT_00b04774) {

    bVar1 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (param_1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                                *)((int)local_14 + 0xc));

    if (!bVar1) {

      ppvVar3 = &local_14;

      goto LAB_0055b2ca;

    }

  }

  local_10 = DAT_00b04774;

  ppvVar3 = &local_10;

LAB_0055b2ca:

  if ((*ppvVar3 != DAT_00b04774) && (*(int *)((int)*ppvVar3 + 0x28) != 0)) {

    FUN_0055a5f0();

    ExceptionList = local_c;

    return;

  }

  local_10 = operator_new(0x24);

  local_4 = 0;

  if (local_10 == (void *)0x0) {

    pvVar4 = (void *)0x0;

  }

  else {

    pvVar4 = (void *)FUN_0055a4a0();

  }

  local_4 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x10) = *param_4;

  cVar2 = FUN_0055b0e0(param_2,param_3);

  if (cVar2 == '\0') {

    if (*(void **)((int)pvVar4 + 0x18) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)((int)pvVar4 + 0x18));

    }

    *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x18) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x1c) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x20) = 0;

    FUN_00787280();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar4);

  }

  FUN_0055a400(param_1,pvVar4);

  FUN_0055a5f0();

  ExceptionList = local_c;

  return;

}
