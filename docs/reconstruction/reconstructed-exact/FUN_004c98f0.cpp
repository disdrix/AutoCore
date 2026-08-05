// =============================================================================
// FUN_004c98f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c98f0
// Address:   0x004c98f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c98f0 @ 0x004c98f0
// Stable ID: aa_004c98f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00493ef0, FUN_004c98f0, FUN_00581330, FUN_0096dc80.
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

uint32_t /* width from decompiler */ __thiscall FUN_004c98f0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  void *pvVar1;

  int iVar2;

  int iVar3;

  void *unaff_EDI;

  uint8_t unaff_retaddr;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1c86;

  local_c = ExceptionList;

  iVar3 = 0;

  if (*(int *)(param_1 + 0x48) != 0) {

    ExceptionList = &local_c;

    pvVar1 = operator_new(0x220);

    local_4 = 0;

    if (pvVar1 != (void *)0x0) {

      iVar3 = FUN_00581330();

    }

    local_4 = 0xffffffff;

    iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 8))

                      (param_2,*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1)

                      );

    if (iVar2 == 0) {

      iVar2 = FUN_0096dc80(local_4 & 0xff,*(uint32_t /* width from decompiler */ *)(iVar3 + 8),unaff_retaddr);

      if (-1 < iVar2) {

        FUN_00493ef0(&stack0xffffffe4);

        ExceptionList = unaff_EDI;

        return 0;

      }

    }

    (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3))(1);

  }

  ExceptionList = local_c;

  return 0xffffffff;

}
