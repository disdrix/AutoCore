// =============================================================================
// FUN_00770280
// -----------------------------------------------------------------------------
// Stable ID: aa_00770280
// Address:   0x00770280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00770280 @ 0x00770280
// Stable ID: aa_00770280
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×2, while×2.
//  - Notable callees: FUN_007701d0, FUN_00770280.
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

void __fastcall FUN_00770280(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar4;

  

  if (0 < unaff_EBX) {

    iVar1 = *param_2;

    if (iVar1 <= unaff_EBX) {

      FUN_007701d0();

      return;

    }

    puVar2 = (uint32_t /* width from decompiler */ *)param_2[3];

    iVar3 = 0;

    puVar4 = puVar2 + unaff_EBX;

    if (iVar1 != unaff_EBX && -1 < iVar1 - unaff_EBX) {

      do {

        *puVar2 = *puVar4;

        iVar3 = iVar3 + 1;

        puVar2 = puVar2 + 1;

        puVar4 = puVar4 + 1;

      } while (iVar3 < *param_2 - unaff_EBX);

    }

    if (iVar3 < *param_2) {

      do {

        *puVar2 = 0;

        iVar3 = iVar3 + 1;

        puVar2 = puVar2 + 1;

      } while (iVar3 < *param_2);

    }

    *param_2 = *param_2 - unaff_EBX;

  }

  return;

}
