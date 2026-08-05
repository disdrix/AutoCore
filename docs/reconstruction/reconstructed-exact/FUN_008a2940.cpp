// =============================================================================
// FUN_008a2940
// -----------------------------------------------------------------------------
// Stable ID: aa_008a2940
// Address:   0x008a2940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a2940 @ 0x008a2940
// Stable ID: aa_008a2940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×4, for×1, return×1.
//  - Notable callees: FUN_008a2940, memmove.
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

void FUN_008a2940(void)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *_Src;

  char cVar4;

  void *pvVar5;

  uint uVar6;

  int *unaff_ESI;

  

  for (uVar6 = 0;

      (iVar2 = unaff_ESI[0x16d], iVar2 != 0 && (uVar6 < (uint)(unaff_ESI[0x16e] - iVar2 >> 2)));

      uVar6 = uVar6 + 1) {

    iVar1 = uVar6 * 4;

    cVar4 = (**(code **)(**(int **)(iVar2 + iVar1) + 0x3d8))();

    if (cVar4 != '\0') {

      (**(code **)(**(int **)(unaff_ESI[0x16d] + iVar1) + 0x440))();

    }

    (**(code **)(*unaff_ESI + 0xb0))(*(uint32_t /* width from decompiler */ *)(unaff_ESI[0x16d] + iVar1));

    if ((*(int *)(unaff_ESI[0x16d] + iVar1) != 0) &&

       (puVar3 = *(uint32_t /* width from decompiler */ **)(unaff_ESI[0x16d] + iVar1), puVar3 != (uint32_t /* width from decompiler */ *)0x0)) {

      (**(code **)*puVar3)(1);

    }

    *(uint32_t /* width from decompiler */ *)(unaff_ESI[0x16d] + iVar1) = 0;

  }

  pvVar5 = (void *)unaff_ESI[0x16d];

  if (pvVar5 != (void *)0x0) {

    _Src = (void *)unaff_ESI[0x16e];

    if (((int)_Src - (int)pvVar5 >> 2 != 0) && (pvVar5 != _Src)) {

      pvVar5 = memmove(pvVar5,_Src,0);

      unaff_ESI[0x16e] = (int)pvVar5;

    }

  }

  return;

}
