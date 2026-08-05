// =============================================================================
// FUN_0096ff50
// -----------------------------------------------------------------------------
// Stable ID: aa_0096ff50
// Address:   0x0096ff50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096ff50 @ 0x0096ff50
// Stable ID: aa_0096ff50
// Embedded strings (evidence for future rename):
//   - "Opaque"
//   - "Alpha_Test"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_00448fc0, FUN_00746270, FUN_00752a80, FUN_0096fdf0, FUN_0096ff50, _stricmp.
//  - Strings: "Opaque"; "Alpha_Test".
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

int __thiscall FUN_0096ff50(int *param_1,char *param_2)



{

  int iVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  char *_Str1;

  

  cVar2 = (char)param_1[1];

  _Str1 = param_2;

  while ((cVar2 != '\0' && (iVar3 = _stricmp(_Str1,"Opaque"), iVar3 == 0))) {

    cVar2 = (char)param_1[1];

    _Str1 = "Alpha_Test";

  }

  cVar2 = FUN_0096fdf0();

  iVar3 = *param_1;

  puVar4 = (uint32_t /* width from decompiler */ *)FUN_00746270(&param_2,_Str1);

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x1c) = *puVar4;

  FUN_00752a80();

  iVar3 = (-1 < *(short *)(iVar3 + 0x1c)) - 1;

  if (((iVar3 == -1) && (cVar2 != '\0')) && (iVar1 = *param_1, iVar1 != 0)) {

    iVar5 = *(int *)(iVar1 + 0x18);

    if (*(int *)(iVar1 + 0x18) == 0) {

      iVar5 = iVar1;

    }

    if (iVar5 != iVar1) {

      FUN_00448fc0(iVar5);

    }

  }

  return iVar3;

}
