// =============================================================================
// Named_CalleeOf_Mission_Requesting_PlayBackgroundMusic_on_s_0071f760
// -----------------------------------------------------------------------------
// Stable ID: aa_0071f760
// Callee of Mission_Requesting_PlayBackgroundMusic_on_s (+2 other named callers)
// Address:   0x0071f760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Requesting_PlayBackgroundMusic_on_s: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Mission_Requesting_PlayBackgroundMusic_on_s (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, while×1.
//  - Notable callees: FUN_0071f760.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Mission_Requesting_PlayBackgroundMusic_on_s (+2 other named callers)
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

byte __thiscall Named_CalleeOf_Mission_Requesting_PlayBackgroundMusic_on_s_0071f760(int param_1,char param_2)



{

  int *piVar1;

  byte bVar2;

  uint uVar3;

  

  if (param_2 == '\0') {

    return *(byte *)(param_1 + 0x1c5);

  }

  bVar2 = 0;

  if (*(int *)(param_1 + 0x10) == 0) {

    return 0;

  }

  uVar3 = 0;

  if (*(int *)(param_1 + 0x1c) != 0) {

    do {

      if (*(int *)(*(int *)(param_1 + 0x10) + uVar3 * 4) != 0) {

        _param_2 = 0;

        piVar1 = *(int **)(*(int *)(param_1 + 0x10) + uVar3 * 4);

        (**(code **)(*piVar1 + 0x24))(piVar1,&param_2);

        bVar2 = bVar2 | (_param_2 & 1) != 0;

      }

      uVar3 = uVar3 + 1;

    } while (uVar3 < *(uint *)(param_1 + 0x1c));

  }

  *(byte *)(param_1 + 0x1c5) = bVar2;

  return bVar2;

}
