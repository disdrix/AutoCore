// =============================================================================
// FUN_004818d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004818d0
// Address:   0x004818d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004818d0 @ 0x004818d0
// Stable ID: aa_004818d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_004818d0, _stricmp.
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

uint32_t /* width from decompiler */ * FUN_004818d0(void)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int in_EAX;

  char *_Str2;

  int iVar3;

  char *_Str1;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  puVar5 = (uint32_t /* width from decompiler */ *)(*(uint32_t /* width from decompiler */ **)(in_EAX + 4))[1];

  cVar1 = *(char *)((int)puVar5 + 0x25);

  puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 4);

  while (cVar1 == '\0') {

    _Str2 = (char *)*unaff_EBX;

    if ((char *)*unaff_EBX == (char *)0x0) {

      _Str2 = PTR_DAT_00afa2bc;

    }

    _Str1 = (char *)puVar5[3];

    if ((char *)puVar5[3] == (char *)0x0) {

      _Str1 = PTR_DAT_00afa2bc;

    }

    iVar3 = _stricmp(_Str1,_Str2);

    if (iVar3 < 0) {

      puVar4 = (uint32_t /* width from decompiler */ *)puVar5[2];

      puVar5 = puVar2;

    }

    else {

      puVar4 = (uint32_t /* width from decompiler */ *)*puVar5;

    }

    puVar2 = puVar5;

    puVar5 = puVar4;

    cVar1 = *(char *)((int)puVar4 + 0x25);

  }

  return puVar2;

}
