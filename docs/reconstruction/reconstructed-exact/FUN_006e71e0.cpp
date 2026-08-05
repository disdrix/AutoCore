// =============================================================================
// FUN_006e71e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006e71e0
// Address:   0x006e71e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e71e0 @ 0x006e71e0
// Stable ID: aa_006e71e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×4, for×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_006e71e0.
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

uint32_t /* width from decompiler */ * __thiscall

FUN_006e71e0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            int param_5)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int unaff_EBP;

  uint8_t local_c [12];

  

  piVar1 = param_1 + 3;

  param_1[2] = param_5;

  *param_1 = &PTR_FUN_00a0e7d4;

  *piVar1 = 0;

  param_1[4] = 0;

  param_1[5] = 0x80000000;

  if (param_5 != 0) {

    (**(code **)(*(int *)*param_2 + 0x28))(local_c);

    iVar4 = param_1[4];

    if (iVar4 < unaff_EBP) {

      if ((int)(param_1[5] & 0x7fffffff) < unaff_EBP) {

        iVar2 = (param_1[5] & 0x7fffffff) * 2;

        iVar3 = unaff_EBP;

        if (unaff_EBP < iVar2) {

          iVar3 = iVar2;

        }

        FUN_005b3300(piVar1,iVar3,2);

      }

      for (; iVar4 < unaff_EBP; iVar4 = iVar4 + 1) {

        *(uint16_t *)(*piVar1 + iVar4 * 2) = 0xffff;

      }

    }

    param_1[4] = unaff_EBP;

  }

  return param_1;

}
