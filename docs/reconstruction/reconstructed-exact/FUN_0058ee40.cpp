// =============================================================================
// FUN_0058ee40
// -----------------------------------------------------------------------------
// Stable ID: aa_0058ee40
// Address:   0x0058ee40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058ee40 @ 0x0058ee40
// Stable ID: aa_0058ee40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_0040cf90, FUN_0058ee40.
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

void FUN_0058ee40(int param_1,float param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uStack_c;

  float fStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  if (DAT_00b04e44 != DAT_00b04e48) {

    puVar3 = DAT_00b04e44;

    do {

      iVar1 = (**(code **)(*(int *)*puVar3 + 0xc))();

      iVar2 = (**(code **)(*(int *)*puVar3 + 0x48))();

      uStack_c = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x90);

      fStack_8 = *(float *)(iVar1 + 0x94) -

                 *(float *)(iVar2 + 0xc) * DAT_00a0f298 * (float)puVar3[1] * param_2;

      uStack_4 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x98);

      uVar4 = 3;

      (**(code **)(*(int *)*puVar3 + 0x10))(3,&uStack_c);

      FUN_0040cf90(uVar4);

      (**(code **)(*(int *)*puVar3 + 0x3c))(param_1 + 0x10);

      puVar3 = puVar3 + 8;

    } while (puVar3 != DAT_00b04e48);

  }

  return;

}
