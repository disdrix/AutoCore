// =============================================================================
// FUN_0040a410
// -----------------------------------------------------------------------------
// Stable ID: aa_0040a410
// Address:   0x0040a410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040a410 @ 0x0040a410
// Stable ID: aa_0040a410
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×5, while×2, do×1, return×1.
//  - Notable callees: FUN_0040aa60×2, FUN_0040a410.
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

void FUN_0040a410(int param_1,int param_2,code *param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  char cVar4;

  int iVar5;

  

  iVar1 = param_1;

  if (param_1 != param_2) {

    while (iVar2 = iVar1, iVar1 = iVar2 + 0x10, iVar1 != param_2) {

      cVar4 = (*param_3)(iVar1,param_1);

      if (cVar4 == '\0') {

        cVar4 = (*param_3)(iVar1,iVar2);

        iVar3 = iVar2;

        if (cVar4 != '\0') {

          do {

            iVar5 = iVar3;

            cVar4 = (*param_3)(iVar1,iVar5 + -0x10);

            iVar3 = iVar5 + -0x10;

          } while (cVar4 != '\0');

          if ((iVar5 != iVar1) && (iVar1 != iVar2 + 0x20)) {

            FUN_0040aa60(iVar5,iVar1,iVar2 + 0x20);

          }

        }

      }

      else if ((param_1 != iVar1) && (iVar1 != iVar2 + 0x20)) {

        FUN_0040aa60(param_1,iVar1,iVar2 + 0x20);

      }

    }

  }

  return;

}
