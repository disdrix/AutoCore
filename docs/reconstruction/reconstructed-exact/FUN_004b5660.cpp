// =============================================================================
// FUN_004b5660
// -----------------------------------------------------------------------------
// Stable ID: aa_004b5660
// Address:   0x004b5660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b5660 @ 0x004b5660
// Stable ID: aa_004b5660
// Embedded strings (evidence for future rename):
//   - "Instancing not supported, Disabling PhysX"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, goto×1.
//  - Notable callees: FUN_00401000, FUN_00401030, FUN_004b5660, FUN_007a4480, FUN_00968c00, NxCreatePhysicsSDK, NxReleasePhysicsSDK, _atexit.
//  - Strings: "Instancing not supported, Disabling PhysX".
//  - Return sites: 3.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_004b5660(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  FUN_00968c00();

  if (DAT_00afa360 != 1) {

    FUN_007a4480(0,"Instancing not supported, Disabling PhysX");

    return;

  }

  if ((_DAT_00b036e0 & 1) == 0) {

    _DAT_00b036e0 = _DAT_00b036e0 | 1;

    _DAT_00b036dc = &PTR_LAB_009cb174;

    _atexit((_func_4879 *)&LAB_009c37f0);

  }

  local_10 = 0x10000;

  local_8 = 0x800;

  local_c = 0x100;

  local_4 = 0;

  piVar1 = (int *)NxCreatePhysicsSDK(0x2060100,0,&DAT_00b036dc,&local_10);

  *param_1 = piVar1;

  if (piVar1 != (int *)0x0) {

    iVar2 = (**(code **)(*piVar1 + 0x5c))();

    if (iVar2 == 0) {

      uVar3 = *param_1;

    }

    else {

      if (DAT_00b036d8 == '\0') {

        DAT_00b036d8 = '\x01';

        if (DAT_00b036d9 == '\0') {

          DAT_00b036d9 = '\x01';

          DAT_00af06e8 = 0;

          DAT_00af06e9 = 1;

          DAT_00af06ea = 1;

          FUN_00401000(0x3f000000);

          FUN_00401030(0x3e800000);

        }

LAB_004b575b:

        (**(code **)(*(int *)*param_1 + 8))(1,0x3d4ccccd);

        (**(code **)(*(int *)*param_1 + 8))(0,0x3ba3d70a);

        return;

      }

      if (DAT_00b036d9 != '\0') goto LAB_004b575b;

      uVar3 = *param_1;

    }

    NxReleasePhysicsSDK(uVar3);

    *param_1 = 0;

  }

  DAT_00b036d8 = 0;

  return;

}
