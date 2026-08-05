// =============================================================================
// FUN_004cd9a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004cd9a0
// Address:   0x004cd9a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004cd9a0 @ 0x004cd9a0
// Stable ID: aa_004cd9a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_004cd9a0, FUN_005b3f60, FUN_005b42f0.
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

void __thiscall FUN_004cd9a0(int param_1,int *param_2)



{

  int *piVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  piVar1 = param_2;

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a1ecc;

  local_c = ExceptionList;

  if (0x22 < *(int *)(param_1 + 0x8c)) {

    ExceptionList = &local_c;

    (**(code **)(*param_2 + 0x14))(&param_2,1);

    if ((char)param_2 != '\0') {

      pvVar2 = operator_new(0x30);

      uStack_4 = 0;

      if (pvVar2 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_005b3f60();

      }

      uStack_4 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4fc) = uVar3;

      FUN_005b42f0(piVar1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x8c));

    }

  }

  ExceptionList = local_c;

  return;

}
