// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag_00478d60
// -----------------------------------------------------------------------------
// Stable ID: aa_00478d60
// Callee of Named_CalleeOf_Named_CalleeOf_Named_assPackManager
// Address:   0x00478d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_assPackManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×8, return×4.
//  - Notable callees: FUN_00478d10, FUN_00478d60.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_assPackManager
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag_00478d60(uint param_1,int param_2)



{

  char *in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_ESI;

  

  if (((in_EAX == (char *)0x0) || (*in_EAX != '1')) || (param_2 != 0x38)) {

    return 0xfffffffa;

  }

  if (unaff_ESI != 0) {

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18) = 0;

    if (*(int *)(unaff_ESI + 0x20) == 0) {

      *(code **)(unaff_ESI + 0x20) = FUN_0047f700;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x28) = 0;

    }

    if (*(int *)(unaff_ESI + 0x24) == 0) {

      *(code **)(unaff_ESI + 0x24) = FUN_0047f720;

    }

    iVar1 = (**(code **)(unaff_ESI + 0x20))(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x28),1,0x1ba8);

    if (iVar1 == 0) {

      return 0xfffffffc;

    }

    *(int *)(unaff_ESI + 0x1c) = iVar1;

    if ((int)param_1 < 0) {

      *(uint32_t /* width from decompiler */ *)(iVar1 + 8) = 0;

      param_1 = -param_1;

    }

    else {

      *(int *)(iVar1 + 8) = ((int)param_1 >> 4) + 1;

      if ((int)param_1 < 0x30) {

        param_1 = param_1 & 0xf;

      }

    }

    if ((7 < (int)param_1) && ((int)param_1 < 0x10)) {

      *(uint *)(iVar1 + 0x1c) = param_1;

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0x2c) = 0;

      uVar2 = FUN_00478d10();

      return uVar2;

    }

    (**(code **)(unaff_ESI + 0x24))(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x28),iVar1);

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = 0;

  }

  return 0xfffffffe;

}
