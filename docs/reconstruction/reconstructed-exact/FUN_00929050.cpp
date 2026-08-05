// =============================================================================
// FUN_00929050
// -----------------------------------------------------------------------------
// Stable ID: aa_00929050
// Address:   0x00929050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00929050 @ 0x00929050
// Stable ID: aa_00929050
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×5, for×1, return×1.
//  - Notable callees: FUN_00928d60, FUN_00929050, free, malloc.
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

uint32_t /* width from decompiler */ * FUN_00929050(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  uint32_t /* width from decompiler */ *_Memory;

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int unaff_EBX;

  

  _Memory = malloc(0x50);

  puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  if (_Memory != (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = _Memory;

    for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar1 = 0;

      puVar1 = puVar1 + 1;

    }

    if (param_3 == 0) {

      uVar4 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x18);

    }

    else {

      uVar4 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x14);

    }

    *_Memory = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 4);

    _Memory[5] = param_1;

    _Memory[6] = param_2;

    _Memory[3] = param_3;

    _Memory[4] = uVar4;

    if (param_3 == 0) {

      uVar2 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x20);

    }

    else {

      uVar2 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x1c);

    }

    _Memory[2] = uVar2;

    if (param_3 == 0) {

      uVar2 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x10);

    }

    else {

      uVar2 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xc);

    }

    _Memory[1] = uVar2;

    _Memory[7] = 0;

    iVar3 = FUN_00928d60(uVar2,uVar4);

    _Memory[0x13] = iVar3;

    puVar1 = _Memory;

    if (iVar3 == 0) {

      free(_Memory);

      puVar1 = (uint32_t /* width from decompiler */ *)0x0;

    }

    puVar1[8] = 1;

  }

  return puVar1;

}
