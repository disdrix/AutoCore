// =============================================================================
// FUN_008793d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008793d0
// Address:   0x008793d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008793d0 @ 0x008793d0
// Stable ID: aa_008793d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00878d50, FUN_008793d0.
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

void FUN_008793d0(void)



{

  int *piVar1;

  char cVar2;

  int *in_EAX;

  int *piVar3;

  

  cVar2 = (**(code **)(*in_EAX + 0x3d8))();

  if (cVar2 != '\0') {

    FUN_00878d50(1);

    if ((in_EAX[0x162] != 0) &&

       (cVar2 = (**(code **)(*(int *)in_EAX[0x162] + 0xd8))(), cVar2 == '\0')) {

      (**(code **)(*(int *)in_EAX[0x162] + 0xd4))(1);

      (**(code **)(*(int *)in_EAX[0x162] + 0x34c))();

    }

    if ((in_EAX[0x161] != 0) &&

       (cVar2 = (**(code **)(*(int *)in_EAX[0x161] + 0xd8))(), cVar2 == '\0')) {

      (**(code **)(*(int *)in_EAX[0x161] + 0xd4))(1);

      (**(code **)(*(int *)in_EAX[0x161] + 0x34c))();

    }

    piVar1 = (int *)in_EAX[0x169];

    if ((piVar1 != (int *)0x0) && (*(char *)((int)piVar1 + 0x489) == '\x01')) {

      (**(code **)(*piVar1 + 0x3ac))(&DAT_00a1419b);

      piVar1 = (int *)in_EAX[0x169];

      *(uint8_t *)((int)piVar1 + 0x489) = 0;

      piVar3 = (int *)(**(code **)(*piVar1 + 0x170))(3);

      piVar1[0x8b] = *piVar3;

      (**(code **)(*(int *)in_EAX[0x169] + 0x34c))();

    }

    piVar1 = (int *)in_EAX[0x16a];

    if ((piVar1 != (int *)0x0) && (*(char *)((int)piVar1 + 0x489) == '\x01')) {

      (**(code **)(*piVar1 + 0x3ac))(&DAT_00a1419b);

      piVar1 = (int *)in_EAX[0x16a];

      *(uint8_t *)((int)piVar1 + 0x489) = 0;

      piVar3 = (int *)(**(code **)(*piVar1 + 0x170))(3);

      piVar1[0x8b] = *piVar3;

                    /* WARNING: Could not recover jumptable at 0x008794fd. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*(int *)in_EAX[0x16a] + 0x34c))();

      return;

    }

  }

  return;

}
