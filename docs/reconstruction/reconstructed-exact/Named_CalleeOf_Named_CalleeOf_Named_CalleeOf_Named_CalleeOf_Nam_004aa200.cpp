// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004aa200
// -----------------------------------------------------------------------------
// Stable ID: aa_004aa200
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x004aa200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: strrchr×3, FUN_00404b30, FUN_004aa200, _wcslwr, block, wcscpy.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

/* WARNING: Removing unreachable block (ram,0x004aa2d4) */



void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004aa200(int param_1,char *param_2)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  uint32_t /* width from decompiler */ uVar4;

  char *_Str;

  char *pcVar5;

  wchar_t local_204 [128];

  char local_104 [260];

  

  iVar2 = -(int)param_2;

  do {

    cVar1 = *param_2;

    param_2[(int)(local_104 + iVar2)] = cVar1;

    param_2 = param_2 + 1;

  } while (cVar1 != '\0');

  _Str = local_104;

  pcVar3 = strrchr(_Str,0x2f);

  if (pcVar3 != (char *)0x0) {

    *pcVar3 = '\0';

    _Str = pcVar3 + 1;

  }

  pcVar3 = strrchr(local_104,0x5c);

  if (pcVar3 != (char *)0x0) {

    *pcVar3 = '\0';

    _Str = pcVar3 + 1;

  }

  pcVar3 = strrchr(local_104,0x2e);

  if (pcVar3 != (char *)0x0) {

    *pcVar3 = '\0';

    pcVar3 = _Str + -1;

    do {

      pcVar5 = pcVar3;

      pcVar3 = pcVar5 + 1;

    } while (pcVar5[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar5 + 1) = DAT_00a395dc;

    pcVar5[5] = DAT_00a395e0;

  }

  uVar4 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00404b30(_Str,uVar4);

  wcscpy((wchar_t *)(param_1 + 0x124),local_204);

  _wcslwr((wchar_t *)(param_1 + 0x124));

  return;

}
