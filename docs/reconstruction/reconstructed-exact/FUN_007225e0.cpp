// =============================================================================
// FUN_007225e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007225e0
// Address:   0x007225e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007225e0 @ 0x007225e0
// Stable ID: aa_007225e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×7, for×2, return×2.
//  - Notable callees: CONCAT22, FUN_007224d0, FUN_007225e0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* WARNING: Restarted to delay deadcode elimination for space: stack */



int FUN_007225e0(int *param_1)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  uint16_t unaff_DI;

  int *piVar4;

  uint32_t /* width from decompiler */ uStack_84;

  int local_24;

  int local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ *local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if ((int *)*param_1 != (int *)0x0) {

    local_18 = 0;

    local_10 = 0;

    local_c = (uint32_t /* width from decompiler */ *)0x0;

    local_20 = (uint)(*(char *)((int)param_1 + 0x25a) != '\0') * 4 + 0x15;

    local_8 = 0;

    local_4 = 0;

    local_24 = 0x24;

    local_1c = 0;

    local_14 = 0;

    iVar3 = (**(code **)(*(int *)*param_1 + 0xc))();

    if (-1 < iVar3) {

      piVar1 = param_1 + 1;

      iVar3 = (**(code **)*local_c)();

      if (-1 < iVar3) {

        (**(code **)(*(int *)*piVar1 + 0x3c))();

        (**(code **)(*(int *)*piVar1 + 0x2c))();

        uStack_84 = DAT_00d1f658;

        (**(code **)(*(int *)*piVar1 + 0x30))((int *)*piVar1);

        (**(code **)(*(int *)*piVar1 + 0x44))((int *)*piVar1);

        piVar1 = param_1 + 3;

        piVar4 = piVar1;

        for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {

          *piVar4 = 0;

          piVar4 = piVar4 + 1;

        }

        *piVar1 = 0x60;

        iVar3 = (**(code **)(*(int *)*param_1 + 0x10))((int *)*param_1,piVar1);

        if (-1 < iVar3) {

          if (((0x1e < (uint)param_1[0x11]) && (*(char *)((int)param_1 + 0x25a) == '\0')) ||

             (*(uint8_t *)((int)param_1 + 0x25a) = 1, *(char *)((int)param_1 + 0x25a) == '\0')) {

            cVar2 = FUN_007224d0(param_1);

            *(bool *)((int)param_1 + 0x25a) = cVar2 == '\0';

          }

          uStack_84 = CONCAT22(unaff_DI,1);

          iVar3 = (**(code **)(_DAT_00000000 + 0x38))(0,&uStack_84);

          if (-1 < iVar3) {

            if (&local_24 != (int *)0x0) {

              (**(code **)(local_24 + 8))(&local_24);

            }

            iVar3 = 0;

          }

        }

      }

    }

    return iVar3;

  }

  return -0x7ffbfe10;

}
