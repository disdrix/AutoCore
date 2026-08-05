// =============================================================================
// FUN_00855000
// -----------------------------------------------------------------------------
// Stable ID: aa_00855000
// Address:   0x00855000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00855000 @ 0x00855000
// Stable ID: aa_00855000
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~133 non-empty decompiler lines.
//  - Control keywords: if×20, return×14, goto×3.
//  - Notable callees: FUN_004101e0×10, FUN_00855000.
//  - Return sites: 14.

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



void FUN_00855000(int param_1)



{

  char cVar1;

  char cVar2;

  int in_EAX;

  int iVar3;

  

  if ((*(int *)(in_EAX + 0x298) != 0) && (param_1 != 0)) {

    iVar3 = (**(code **)(**(int **)(in_EAX + 0x298) + 0x10))(3);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xbc) = 0xffffffff;

    *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + 1;

    *(float *)(iVar3 + 0x90) = *(float *)(iVar3 + 0x90) + _DAT_00aaa900;

    iVar3 = (**(code **)(**(int **)(in_EAX + 0x298) + 0x10))(3);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xbc) = 0xffffffff;

    *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + 1;

    *(float *)(iVar3 + 0x94) = *(float *)(iVar3 + 0x94) + DAT_00aaa8fc;

    iVar3 = (**(code **)(**(int **)(in_EAX + 0x298) + 0x10))(3);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xbc) = 0xffffffff;

    *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + 1;

    *(float *)(iVar3 + 0x98) = *(float *)(iVar3 + 0x98) - _DAT_00aaa8f8;

    iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);

    cVar2 = *(char *)(iVar3 + 0x532);

    if (cVar2 == '\0') {

      cVar2 = *(char *)(iVar3 + 0x531);

      if ((cVar2 == '\0') && (*(int *)(iVar3 + 0x528) == 0)) {

        iVar3 = (**(code **)(**(int **)(in_EAX + 0x298) + 0x10))(3);

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0xbc) = 0xffffffff;

        *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + 1;

        *(float *)(iVar3 + 0x90) = *(float *)(iVar3 + 0x90) - DAT_00aaa8f4;

        return;

      }

      if ((cVar2 != '\x01') || (*(int *)(iVar3 + 0x528) != 0)) {

        if ((cVar2 == '\x03') && (cVar1 = FUN_004101e0(), cVar1 == '\0')) {

          iVar3 = (**(code **)(**(int **)(in_EAX + 0x298) + 0x10))(3);

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0xbc) = 0xffffffff;

          *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + 1;

          *(float *)(iVar3 + 0x90) = *(float *)(iVar3 + 0x90) - DAT_00aaa7b8;

          return;

        }

        if ((cVar2 != '\x02') || (cVar1 = FUN_004101e0(), cVar1 != '\0')) {

          if (cVar2 != '\x03') {

            return;

          }

          cVar2 = FUN_004101e0();

          if (cVar2 != '\x01') {

            return;

          }

          iVar3 = (**(code **)(**(int **)(in_EAX + 0x298) + 0x10))(3);

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0xbc) = 0xffffffff;

          *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + 1;

          *(float *)(iVar3 + 0x90) = *(float *)(iVar3 + 0x90) + DAT_00aaa8f4;

          iVar3 = (**(code **)(**(int **)(in_EAX + 0x298) + 0x10))(3);

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0xbc) = 0xffffffff;

          *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + 1;

          *(float *)(iVar3 + 0x98) = *(float *)(iVar3 + 0x98) + DAT_00aaa8f0;

          return;

        }

      }

LAB_008552f8:

      iVar3 = (**(code **)(**(int **)(in_EAX + 0x298) + 0x10))(3);

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xbc) = 0xffffffff;

      *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + 1;

      *(float *)(iVar3 + 0x98) = *(float *)(iVar3 + 0x98) - g_flMultiKillCountBlend;

      return;

    }

    if (cVar2 != '\x02') {

      if (cVar2 != '\x01') {

        return;

      }

      if (*(char *)(iVar3 + 0x531) != '\x01') {

        return;

      }

      cVar2 = FUN_004101e0();

      if (cVar2 != '\0') {

        return;

      }

      iVar3 = (**(code **)(**(int **)(in_EAX + 0x298) + 0x10))(3);

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xbc) = 0xffffffff;

      *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + 1;

      *(float *)(iVar3 + 0x98) = *(float *)(iVar3 + 0x98) - DAT_00a0f70c;

      return;

    }

    cVar2 = *(char *)(iVar3 + 0x531);

    if ((cVar2 == '\0') && (cVar1 = FUN_004101e0(), cVar1 == '\0')) {

      iVar3 = (**(code **)(**(int **)(in_EAX + 0x298) + 0x10))(3);

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xbc) = 0xffffffff;

      *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + 1;

      *(float *)(iVar3 + 0x90) = *(float *)(iVar3 + 0x90) - DAT_00aaa8f4;

      iVar3 = (**(code **)(**(int **)(in_EAX + 0x298) + 0x10))(3);

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xbc) = 0xffffffff;

      *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + 1;

      *(float *)(iVar3 + 0x98) = *(float *)(iVar3 + 0x98) - DAT_00aaa8ec;

      return;

    }

    if (cVar2 == '\x02') {

      cVar1 = FUN_004101e0();

      if (cVar1 == '\0') {

        iVar3 = (**(code **)(**(int **)(in_EAX + 0x298) + 0x10))(3);

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0xbc) = 0xffffffff;

        *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + 1;

        *(float *)(iVar3 + 0x90) = *(float *)(iVar3 + 0x90) - DAT_00aaa7b8;

        goto LAB_008552f8;

      }

      cVar1 = FUN_004101e0();

      if (cVar1 == '\x01') {

        iVar3 = (**(code **)(**(int **)(in_EAX + 0x298) + 0x10))(3);

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0xbc) = 0xffffffff;

        *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + 1;

        *(float *)(iVar3 + 0x94) = *(float *)(iVar3 + 0x94) + DAT_00aaa8f0;

        iVar3 = (**(code **)(**(int **)(in_EAX + 0x298) + 0x10))(3);

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0xbc) = 0xffffffff;

        *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + 1;

        *(float *)(iVar3 + 0x98) = *(float *)(iVar3 + 0x98) + g_flMultiKillCountBlend;

        return;

      }

    }

    if (cVar2 == '\x01') {

      cVar1 = FUN_004101e0();

      if (cVar1 == '\x01') goto LAB_008553f5;

      cVar1 = FUN_004101e0();

      if (cVar1 == '\0') goto LAB_008552f8;

    }

    if ((cVar2 == '\x03') && (cVar2 = FUN_004101e0(), cVar2 == '\x01')) {

LAB_008553f5:

      iVar3 = (**(code **)(**(int **)(in_EAX + 0x298) + 0x10))(3);

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xbc) = 0xffffffff;

      *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + 1;

      *(float *)(iVar3 + 0x98) = *(float *)(iVar3 + 0x98) + DAT_00aaa8ec;

      return;

    }

  }

  return;

}
