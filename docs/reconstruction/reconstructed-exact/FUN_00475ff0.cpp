// =============================================================================
// FUN_00475ff0
// -----------------------------------------------------------------------------
// Stable ID: aa_00475ff0
// Address:   0x00475ff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00475ff0 @ 0x00475ff0
// Stable ID: aa_00475ff0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: free×3, FUN_004766e0×2, FUN_00475ff0, FUN_00476120.
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

void FUN_00475ff0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  code *pcVar2;

  void *_Memory;

  void *_Memory_00;

  void *_Memory_01;

  uint8_t local_26c [580];

  uint32_t /* width from decompiler */ local_28;

  

  _Memory = (void *)0x0;

  _Memory_01 = (void *)0x0;

  _Memory_00 = (void *)0x0;

  if (param_1 != (uint32_t /* width from decompiler */ *)0x0) {

    _Memory = (void *)*param_1;

  }

  if (param_2 != (uint32_t /* width from decompiler */ *)0x0) {

    _Memory_01 = (void *)*param_2;

  }

  if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

    _Memory_00 = (void *)*param_3;

  }

  uVar1 = *(uint32_t /* width from decompiler */ *)((int)_Memory + 0x244);

  pcVar2 = *(code **)((int)_Memory + 0x24c);

  FUN_00476120();

  if (_Memory_01 != (void *)0x0) {

    FUN_004766e0(_Memory,_Memory_01,0x4000,0xffffffff);

    if (pcVar2 == (code *)0x0) {

      free(_Memory_01);

    }

    else {

      local_28 = uVar1;

      (*pcVar2)(local_26c);

    }

    *param_2 = 0;

  }

  if (_Memory_00 != (void *)0x0) {

    FUN_004766e0(_Memory,_Memory_00,0x4000,0xffffffff);

    if (pcVar2 == (code *)0x0) {

      free(_Memory_00);

    }

    else {

      local_28 = uVar1;

      (*pcVar2)(local_26c);

    }

    *param_3 = 0;

  }

  if (pcVar2 != (code *)0x0) {

    local_28 = uVar1;

    (*pcVar2)(local_26c);

    *param_1 = 0;

    return;

  }

  free(_Memory);

  *param_1 = 0;

  return;

}
