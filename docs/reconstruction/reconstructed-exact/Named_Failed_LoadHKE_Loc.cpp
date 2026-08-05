// =============================================================================
// Named_Failed_LoadHKE_Loc
// -----------------------------------------------------------------------------
// Stable ID: aa_0053d810
// Address:   0x0053d810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Failed_LoadHKE_Loc @ 0x0053d810
// Stable ID: aa_0053d810
// Embedded strings (evidence for future rename):
//   - "Failed in LoadHKE for %d:%s\nLoc: %0.2f, %0.2f, %0.2f"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, for×1.
//  - Notable callees: FUN_004eb230, FUN_004ebc00, FUN_004f2930, Named_Failed_LoadHKE_Loc, FUN_00560ec0, FUN_005f5700, FUN_007a4480, wcslen.
//  - Strings: "Failed in LoadHKE for %d:%s\nLoc: %0.2f, %0.2f, %0.2f".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Failed in LoadHKE for %d:%s
Loc: %0.2f, %0.2f, %0.2f"
 * Domain alias of FUN_0053d810 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_Failed_LoadHKE_Loc(int *param_1,float *param_2,uint32_t /* width from decompiler */ param_3)



{

  wchar_t *_Str;

  size_t sVar1;

  int iVar2;

  

  if (*(int *)(*(int *)(param_1[1] + 4) + 0xa8 + (int)param_1) != 0) {

    if (param_1[2] != 0) {

      (**(code **)(*param_1 + 4))();

    }

    _Str = (wchar_t *)FUN_004eb230();

    sVar1 = wcslen(_Str);

    if (1 < sVar1) {

      (**(code **)(*param_1 + 0x18))();

      iVar2 = FUN_004f2930();

      param_1[2] = iVar2;

      if (iVar2 != 0) {

        FUN_005f5700(1,*(int *)(param_1[1] + 4) + 4 + (int)param_1);

        FUN_00560ec0();

        iVar2 = FUN_004ebc00(param_2,param_3,

                             *(uint32_t /* width from decompiler */ *)((int)param_1 + *(int *)(param_1[1] + 4) + 0xbc),

                             *(uint32_t /* width from decompiler */ *)((int)param_1 + *(int *)(param_1[1] + 4) + 0xa8));

        param_1[3] = iVar2;

        return 1;

      }

      iVar2 = *(int *)(*(int *)(param_1[1] + 4) + 0xac + (int)param_1);

      FUN_007a4480(1,"Failed in LoadHKE for %d:%s\nLoc: %0.2f, %0.2f, %0.2f",

                   *(uint32_t /* width from decompiler */ *)(iVar2 + 0x34),iVar2 + 0x40,(double)*param_2,(double)param_2[1],

                   (double)param_2[2]);

      return 1;

    }

  }

  return 0;

}
