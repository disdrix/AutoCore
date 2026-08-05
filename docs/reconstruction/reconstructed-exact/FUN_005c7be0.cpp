// =============================================================================
// FUN_005c7be0
// -----------------------------------------------------------------------------
// Stable ID: aa_005c7be0
// Address:   0x005c7be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c7be0 @ 0x005c7be0
// Stable ID: aa_005c7be0
// Embedded strings (evidence for future rename):
//   - "~CLoadNode"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×8, return×4, goto×1.
//  - Notable callees: FUN_004baf50, FUN_005b2ba0, FUN_005c7be0, FUN_0076cef0, FUN_0076cf00.
//  - Strings: "~CLoadNode".
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

void __fastcall FUN_005c7be0(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  int iVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6e71;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_009d9fe8;

  FUN_0076cf00("~CLoadNode");

  pvVar1 = (void *)param_1[0x16];

  local_4 = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_005b2ba0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  iVar2 = param_1[4];

  param_1[0x16] = 0;

  if (iVar2 == 0) {

    iVar2 = FUN_004baf50(param_1 + 6);

    if (iVar2 == 0) goto LAB_005c7c55;

  }

  *(uint8_t *)(iVar2 + 0xf) = 0;

LAB_005c7c55:

  if ((code *)param_1[0x1c] != (code *)0x0) {

    (*(code *)param_1[0x1c])(*(uint8_t *)((int)param_1 + 0x53));

  }

  if ((code *)param_1[0x1e] != (code *)0x0) {

    (*(code *)param_1[0x1e])(*(uint8_t *)((int)param_1 + 0x53),param_1[0x1d]);

  }

  if ((uint32_t /* width from decompiler */ *)param_1[0x1b] != (uint32_t /* width from decompiler */ *)0x0) {

    pvVar1 = *(void **)param_1[0x1b];

    if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *(uint32_t /* width from decompiler */ *)param_1[0x1b] = 0;

    if ((void *)param_1[0x1b] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)param_1[0x1b]);

    }

    param_1[0x1b] = 0;

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = pvStack_c;

  return;

}
