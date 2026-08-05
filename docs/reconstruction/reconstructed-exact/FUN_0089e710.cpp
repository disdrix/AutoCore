// =============================================================================
// FUN_0089e710
// -----------------------------------------------------------------------------
// Stable ID: aa_0089e710
// Address:   0x0089e710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0089e710 @ 0x0089e710
// Stable ID: aa_0089e710
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×14, return×1.
//  - Notable callees: sprintf×5, FUN_008423c0, FUN_0089e710.
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

void FUN_0089e710(void)



{

  char cVar1;

  int *in_EAX;

  char acStack_100 [256];

  

  if (DAT_00d1b6d8 != 0) {

    cVar1 = (**(code **)(*in_EAX + 0x3d8))();

    if (cVar1 != '\0') {

      if (in_EAX[0x161] != 0) {

        sprintf(acStack_100,"%i",(uint)*(byte *)(DAT_00d1b6d8 + 0x598));

        (**(code **)(*(int *)in_EAX[0x161] + 0x1d8))(acStack_100,1,1);

        (**(code **)(*(int *)in_EAX[0x161] + 0x34c))();

      }

      if (in_EAX[0x162] != 0) {

        sprintf(acStack_100,"%i",(uint)*(byte *)(DAT_00d1b6d8 + 0x599));

        (**(code **)(*(int *)in_EAX[0x162] + 0x1d8))(acStack_100,1,1);

        (**(code **)(*(int *)in_EAX[0x162] + 0x34c))();

      }

      if (in_EAX[0x163] != 0) {

        sprintf(acStack_100,"%i",(uint)*(byte *)(DAT_00d1b6d8 + 0x59a));

        (**(code **)(*(int *)in_EAX[0x163] + 0x1d8))(acStack_100,1,1);

        (**(code **)(*(int *)in_EAX[0x163] + 0x34c))();

      }

      if (in_EAX[0x164] != 0) {

        sprintf(acStack_100,"%i",(uint)*(byte *)(DAT_00d1b6d8 + 0x59b));

        (**(code **)(*(int *)in_EAX[0x164] + 0x1d8))(acStack_100,1,1);

        (**(code **)(*(int *)in_EAX[0x164] + 0x34c))();

      }

      if (in_EAX[0x15a] != 0) {

        sprintf(acStack_100,"%i",(int)*(short *)(DAT_00d1b6d8 + 0x580));

        (**(code **)(*(int *)in_EAX[0x15a] + 0x1d8))(acStack_100,1,1);

        (**(code **)(*(int *)in_EAX[0x15a] + 0x34c))();

      }

      if (in_EAX[0x14e] != 0) {

        (**(code **)(*(int *)in_EAX[0x14e] + 0x444))();

      }

      if (in_EAX[0x14f] != 0) {

        (**(code **)(*(int *)in_EAX[0x14f] + 0x444))();

      }

      if (in_EAX[0x150] != 0) {

        (**(code **)(*(int *)in_EAX[0x150] + 0x444))();

      }

      if (in_EAX[0x151] != 0) {

        (**(code **)(*(int *)in_EAX[0x151] + 0x444))();

      }

      if (DAT_00d1d8ec != (int *)0x0) {

        cVar1 = (**(code **)(*DAT_00d1d8ec + 0x3d8))();

        if (cVar1 != '\0') {

          cVar1 = (**(code **)(*DAT_00d1d8ec + 0xd0))();

          if (cVar1 != '\0') {

            FUN_008423c0();

          }

        }

      }

    }

  }

  return;

}
