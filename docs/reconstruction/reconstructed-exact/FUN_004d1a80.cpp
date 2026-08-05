// =============================================================================
// FUN_004d1a80
// -----------------------------------------------------------------------------
// Stable ID: aa_004d1a80
// Address:   0x004d1a80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d1a80 @ 0x004d1a80
// Stable ID: aa_004d1a80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_0071f5e0×2, ftell×2, fwrite×2, FUN_004bc180, FUN_004d1a80.
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

void __thiscall FUN_004d1a80(int param_1,FILE *param_2,FILE *param_3,char param_4)



{

  long lVar1;

  long lVar2;

  int iVar3;

  int local_8;

  int local_4;

  

  if (*(int *)(param_1 + 0xe908) == 0) {

    local_8 = 0;

  }

  else {

    local_8 = (*(int *)(param_1 + 0xe90c) - *(int *)(param_1 + 0xe908)) / 200;

  }

  fwrite(&local_8,4,1,param_2);

  iVar3 = *(int *)(param_1 + 0xe908);

  if (iVar3 != *(int *)(param_1 + 0xe90c)) {

    do {

      if (param_3 != (FILE *)0x0) {

        lVar1 = ftell(param_3);

        FUN_0071f5e0(param_3);

        lVar2 = ftell(param_3);

        local_4 = lVar2 - lVar1;

        fwrite(&local_4,4,1,param_2);

      }

      FUN_0071f5e0(param_2);

      iVar3 = iVar3 + 200;

    } while (iVar3 != *(int *)(param_1 + 0xe90c));

  }

  if ((param_4 != '\0') && (iVar3 = *(int *)(param_1 + 0xe908), iVar3 != *(int *)(param_1 + 0xe90c))

     ) {

    do {

      FUN_004bc180(*(uint32_t /* width from decompiler */ *)(iVar3 + 0xc0));

      iVar3 = iVar3 + 200;

    } while (iVar3 != *(int *)(param_1 + 0xe90c));

  }

  return;

}
