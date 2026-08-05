// =============================================================================
// Named_TthkShapeCollection_getMaximumProjection
// -----------------------------------------------------------------------------
// Stable ID: aa_006d1850
// Address:   0x006d1850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_TthkShapeCollection_getMaximumProjection @ 0x006d1850
// Stable ID: aa_006d1850
// Embedded strings (evidence for future rename):
//   - "TthkShapeCollection::getMaximumProjection"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: rdtsc×2, Named_TthkShapeCollection_getMaximumProjection.
//  - Strings: "TthkShapeCollection::getMaximumProjection".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "TthkShapeCollection::getMaximumProjection"
 * Domain alias of FUN_006d1850 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

float10 __thiscall Named_TthkShapeCollection_getMaximumProjection(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint64_t uVar1;

  int iVar2;

  int *piVar3;

  float10 fVar4;

  float fStack_124;

  uint8_t auStack_110 [268];

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TthkShapeCollection::getMaximumProjection";

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  for (iVar2 = (**(code **)(*param_1 + 0x2c))(); iVar2 != -1;

      iVar2 = (**(code **)(*param_1 + 0x30))(iVar2)) {

    piVar3 = (int *)(**(code **)(*param_1 + 0x34))(iVar2,auStack_110);

    fVar4 = (float10)(**(code **)(*piVar3 + 0x1c))(param_2);

    if ((float10)fStack_124 <= fVar4) {

      fStack_124 = (float)fVar4;

    }

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return (float10)-3.4028235e+38;

}
