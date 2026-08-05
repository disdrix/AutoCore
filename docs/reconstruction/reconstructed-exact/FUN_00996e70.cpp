// =============================================================================
// FUN_00996e70
// -----------------------------------------------------------------------------
// Stable ID: aa_00996e70
// Address:   0x00996e70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00996e70 @ 0x00996e70
// Stable ID: aa_00996e70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: BitStream_readBits×2, FUN_00996e70, malloc.
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

void FUN_00996e70(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *pvVar4;

  uint _Size;

  uint local_4;

  

  local_4 = 0;

  BitStream_readBits(10,&local_4);

  _Size = local_4 & 0x3ff;

  puVar3 = operator_new(0x18);

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar3[1] = 0;

    puVar3[2] = 0;

    *puVar3 = &PTR_LAB_009d7b00;

    puVar3[4] = _Size;

    pvVar4 = malloc(_Size);

    puVar3[3] = pvVar4;

    *(uint8_t *)(puVar3 + 5) = 1;

  }

  piVar2 = (int *)*param_2;

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *param_2 = (int)puVar3;

  if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar3[2] = puVar3[2] + 1;

  }

  BitStream_readBits(_Size * 8,*(uint32_t /* width from decompiler */ *)(*param_2 + 0xc));

  return;

}
