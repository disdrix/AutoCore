// =============================================================================
// Named_CalleeOf_Named_gfxDeviceIB_0046c1b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0046c1b0
// Callee of Named_gfxDeviceIB (+1 other named callers)
// Address:   0x0046c1b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDeviceIB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxDeviceIB (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, while×1.
//  - Notable callees: FUN_0046c1b0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_gfxDeviceIB (+1 other named callers)
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

void __fastcall Named_CalleeOf_Named_gfxDeviceIB_0046c1b0(uint *param_1)



{

  int *piVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *in_EAX;

  uint uVar3;

  int *piVar4;

  int unaff_ESI;

  

  uVar2 = *param_1;

  uVar3 = uVar2 & *(uint *)(unaff_ESI + 0x20);

  if (*(uint *)(unaff_ESI + 0x24) <= uVar3) {

    uVar3 = uVar3 + (-1 - (*(uint *)(unaff_ESI + 0x20) >> 1));

  }

  piVar1 = (int *)(*(int *)(unaff_ESI + 0x14) + uVar3 * 4);

  piVar4 = (int *)*piVar1;

  if (piVar4 != (int *)piVar1[1]) {

    do {

      if (uVar2 <= (uint)piVar4[2]) {

        if ((uint)piVar4[2] <= uVar2) {

          *in_EAX = piVar4;

          return;

        }

        *in_EAX = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8);

        return;

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != (int *)piVar1[1]);

  }

  *in_EAX = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8);

  return;

}
