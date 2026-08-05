// =============================================================================
// FUN_0084b770
// -----------------------------------------------------------------------------
// Stable ID: aa_0084b770
// Address:   0x0084b770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0084b770 @ 0x0084b770
// Stable ID: aa_0084b770
// Embedded strings (evidence for future rename):
//   - "(No Value)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_005142a0, FUN_00571b60, FUN_007a69d0, FUN_007a6de0, FUN_0084b770, FUN_00977a30, sprintf.
//  - Strings: "(No Value)".
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_0084b770(int *param_1,char param_2)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  char *_Format;

  int iVar4;

  int *unaff_EBX;

  uint8_t *puVar5;

  uint8_t auStack_180 [128];

  char acStack_100 [256];

  

  FUN_007a69d0();

  piVar1 = DAT_00d1b89c;

  if ((param_2 == '\0') || (*(int *)(unaff_EBX[0x2a] + 0x38) == 4)) {

    return 0;

  }

  iVar3 = FUN_005142a0();

  iVar4 = iVar3 >> 0x1f;

  if (piVar1 != (int *)0x0) {

    cVar2 = (**(code **)(*piVar1 + 0xd0))();

    if (cVar2 != '\0') {

      cVar2 = (**(code **)(*piVar1 + 0x3d8))();

      if ((cVar2 != '\0') && (piVar1[0x16c] != 0)) {

        cVar2 = FUN_00571b60(unaff_EBX);

        if (cVar2 != '\0') {

          iVar3 = (**(code **)(*unaff_EBX + 0x168))();

          iVar4 = iVar3 >> 0x1f;

        }

      }

    }

  }

  if (iVar3 != 0 || iVar4 != 0) {

    FUN_00977a30(DAT_00d1ad30,iVar3,iVar4);

    return 1;

  }

  puVar5 = auStack_180;

  _Format = (char *)FUN_007a6de0("(No Value)",0xffffffff);

  sprintf(acStack_100,_Format,puVar5);

  (**(code **)(*param_1 + 0x224))(acStack_100,0xffbbbbbb);

  return 1;

}
