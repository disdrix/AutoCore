// =============================================================================
// FUN_00974c00
// -----------------------------------------------------------------------------
// Stable ID: aa_00974c00
// Address:   0x00974c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00974c00 @ 0x00974c00
// Stable ID: aa_00974c00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00974160, FUN_00974c00, malloc, realloc.
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

void FUN_00974c00(size_t param_1)



{

  uint _NewSize;

  size_t sVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ *unaff_EBX;

  

  iVar2 = param_1;

  sVar1 = (*(uint *)(param_1 + 0x10) / 3) * 4 + 9;

  param_1 = sVar1;

  puVar3 = operator_new(0x18);

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar3[1] = 0;

    puVar3[2] = 0;

    *puVar3 = &PTR_LAB_009d7b00;

    puVar3[4] = sVar1;

    pvVar4 = malloc(sVar1);

    puVar3[3] = pvVar4;

    *(uint8_t *)(puVar3 + 5) = 1;

  }

  FUN_00974160(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x10),puVar3[3],&param_1);

  sVar1 = param_1;

  _NewSize = param_1 + 1;

  if ((uint)puVar3[4] < _NewSize) {

    if (*(char *)(puVar3 + 5) != '\0') {

      puVar3[4] = _NewSize;

      pvVar4 = realloc((void *)puVar3[3],_NewSize);

      puVar3[3] = pvVar4;

    }

  }

  else {

    puVar3[4] = _NewSize;

  }

  *(uint8_t *)(sVar1 + puVar3[3]) = 0;

  *unaff_EBX = puVar3;

  puVar3[2] = puVar3[2] + 1;

  return;

}
