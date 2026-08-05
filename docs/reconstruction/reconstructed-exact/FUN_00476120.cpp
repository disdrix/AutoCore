// =============================================================================
// FUN_00476120
// -----------------------------------------------------------------------------
// Stable ID: aa_00476120
// Address:   0x00476120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00476120 @ 0x00476120
// Stable ID: aa_00476120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~253 non-empty decompiler lines.
//  - Control keywords: if×50, do×3, while×3, for×3, return×1.
//  - Notable callees: free×20, FUN_00476c00×2, FUN_00476120.
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

void __fastcall FUN_00476120(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  int in_EAX;

  uint32_t /* width from decompiler */ *unaff_EBX;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ auStack_40 [16];

  

  if (in_EAX != 0) {

    FUN_00476c00();

  }

  if (param_1 != 0) {

    FUN_00476c00();

  }

  if ((void *)unaff_EBX[0x2b] != (void *)0x0) {

    if ((code *)unaff_EBX[0x93] == (code *)0x0) {

      free((void *)unaff_EBX[0x2b]);

    }

    else {

      (*(code *)unaff_EBX[0x93])();

    }

  }

  if ((void *)unaff_EBX[0x94] != (void *)0x0) {

    if ((code *)unaff_EBX[0x93] == (code *)0x0) {

      free((void *)unaff_EBX[0x94]);

    }

    else {

      (*(code *)unaff_EBX[0x93])();

    }

  }

  if ((void *)unaff_EBX[0x3a] != (void *)0x0) {

    if ((code *)unaff_EBX[0x93] == (code *)0x0) {

      free((void *)unaff_EBX[0x3a]);

    }

    else {

      (*(code *)unaff_EBX[0x93])();

    }

  }

  if ((void *)unaff_EBX[0x7b] != (void *)0x0) {

    if ((code *)unaff_EBX[0x93] == (code *)0x0) {

      free((void *)unaff_EBX[0x7b]);

    }

    else {

      (*(code *)unaff_EBX[0x93])();

    }

  }

  if ((void *)unaff_EBX[0x7c] != (void *)0x0) {

    if ((code *)unaff_EBX[0x93] == (code *)0x0) {

      free((void *)unaff_EBX[0x7c]);

    }

    else {

      (*(code *)unaff_EBX[0x93])();

    }

  }

  if ((void *)unaff_EBX[0x59] != (void *)0x0) {

    if ((code *)unaff_EBX[0x93] == (code *)0x0) {

      free((void *)unaff_EBX[0x59]);

    }

    else {

      (*(code *)unaff_EBX[0x93])();

    }

  }

  if ((void *)unaff_EBX[0x5a] != (void *)0x0) {

    if ((code *)unaff_EBX[0x93] == (code *)0x0) {

      free((void *)unaff_EBX[0x5a]);

    }

    else {

      (*(code *)unaff_EBX[0x93])();

    }

  }

  if ((void *)unaff_EBX[0x5b] != (void *)0x0) {

    if ((code *)unaff_EBX[0x93] == (code *)0x0) {

      free((void *)unaff_EBX[0x5b]);

    }

    else {

      (*(code *)unaff_EBX[0x93])();

    }

  }

  if (((*(byte *)((int)unaff_EBX + 0x215) & 0x10) != 0) && ((void *)unaff_EBX[0x45] != (void *)0x0))

  {

    if ((code *)unaff_EBX[0x93] == (code *)0x0) {

      free((void *)unaff_EBX[0x45]);

    }

    else {

      (*(code *)unaff_EBX[0x93])();

    }

  }

  *(byte *)((int)unaff_EBX + 0x215) = *(byte *)((int)unaff_EBX + 0x215) & 0xef;

  if (((*(byte *)((int)unaff_EBX + 0x215) & 0x20) != 0) && ((void *)unaff_EBX[0x62] != (void *)0x0))

  {

    if ((code *)unaff_EBX[0x93] == (code *)0x0) {

      free((void *)unaff_EBX[0x62]);

    }

    else {

      (*(code *)unaff_EBX[0x93])();

    }

  }

  *(byte *)((int)unaff_EBX + 0x215) = *(byte *)((int)unaff_EBX + 0x215) & 0xdf;

  if (((unaff_EBX[0x85] & 8) != 0) && ((void *)unaff_EBX[0x7d] != (void *)0x0)) {

    if ((code *)unaff_EBX[0x93] == (code *)0x0) {

      free((void *)unaff_EBX[0x7d]);

    }

    else {

      (*(code *)unaff_EBX[0x93])();

    }

  }

  unaff_EBX[0x85] = unaff_EBX[0x85] & 0xfffffff7;

  if (unaff_EBX[0x5c] != 0) {

    iVar8 = 1 << (8U - (char)unaff_EBX[0x56] & 0x1f);

    iVar6 = 0;

    if (0 < iVar8) {

      do {

        pvVar1 = *(void **)(unaff_EBX[0x5c] + iVar6 * 4);

        if (pvVar1 != (void *)0x0) {

          if ((code *)unaff_EBX[0x93] == (code *)0x0) {

            free(pvVar1);

          }

          else {

            (*(code *)unaff_EBX[0x93])();

          }

        }

        iVar6 = iVar6 + 1;

      } while (iVar6 < iVar8);

    }

    if ((void *)unaff_EBX[0x5c] != (void *)0x0) {

      if ((code *)unaff_EBX[0x93] == (code *)0x0) {

        free((void *)unaff_EBX[0x5c]);

      }

      else {

        (*(code *)unaff_EBX[0x93])();

      }

    }

  }

  if (unaff_EBX[0x5d] != 0) {

    iVar8 = 1 << (8U - (char)unaff_EBX[0x56] & 0x1f);

    iVar6 = 0;

    if (0 < iVar8) {

      do {

        pvVar1 = *(void **)(unaff_EBX[0x5d] + iVar6 * 4);

        if (pvVar1 != (void *)0x0) {

          if ((code *)unaff_EBX[0x93] == (code *)0x0) {

            free(pvVar1);

          }

          else {

            (*(code *)unaff_EBX[0x93])();

          }

        }

        iVar6 = iVar6 + 1;

      } while (iVar6 < iVar8);

    }

    if ((void *)unaff_EBX[0x5d] != (void *)0x0) {

      if ((code *)unaff_EBX[0x93] == (code *)0x0) {

        free((void *)unaff_EBX[0x5d]);

      }

      else {

        (*(code *)unaff_EBX[0x93])();

      }

    }

  }

  if (unaff_EBX[0x5e] != 0) {

    iVar8 = 1 << (8U - (char)unaff_EBX[0x56] & 0x1f);

    iVar6 = 0;

    if (0 < iVar8) {

      do {

        pvVar1 = *(void **)(unaff_EBX[0x5e] + iVar6 * 4);

        if (pvVar1 != (void *)0x0) {

          if ((code *)unaff_EBX[0x93] == (code *)0x0) {

            free(pvVar1);

          }

          else {

            (*(code *)unaff_EBX[0x93])();

          }

        }

        iVar6 = iVar6 + 1;

      } while (iVar6 < iVar8);

    }

    if ((void *)unaff_EBX[0x5e] != (void *)0x0) {

      if ((code *)unaff_EBX[0x93] == (code *)0x0) {

        free((void *)unaff_EBX[0x5e]);

      }

      else {

        (*(code *)unaff_EBX[0x93])();

      }

    }

  }

  if ((void *)unaff_EBX[0x84] != (void *)0x0) {

    if ((code *)unaff_EBX[0x93] == (code *)0x0) {

      free((void *)unaff_EBX[0x84]);

    }

    else {

      (*(code *)unaff_EBX[0x93])();

    }

  }

  if (((unaff_EBX != (uint32_t /* width from decompiler */ *)0xffffff8c) && (unaff_EBX[0x24] != 0)) &&

     ((code *)unaff_EBX[0x26] != (code *)0x0)) {

    iVar6 = *(int *)(unaff_EBX[0x24] + 0x2c);

    if (iVar6 != 0) {

      (*(code *)unaff_EBX[0x26])(unaff_EBX[0x27],iVar6);

    }

    (*(code *)unaff_EBX[0x26])(unaff_EBX[0x27],unaff_EBX[0x24]);

    unaff_EBX[0x24] = 0;

  }

  if ((void *)unaff_EBX[0x6c] != (void *)0x0) {

    if ((code *)unaff_EBX[0x93] == (code *)0x0) {

      free((void *)unaff_EBX[0x6c]);

    }

    else {

      (*(code *)unaff_EBX[0x93])();

    }

  }

  if ((void *)unaff_EBX[0x79] != (void *)0x0) {

    if ((code *)unaff_EBX[0x93] == (code *)0x0) {

      free((void *)unaff_EBX[0x79]);

    }

    else {

      (*(code *)unaff_EBX[0x93])();

    }

  }

  uVar2 = unaff_EBX[0x93];

  uVar3 = unaff_EBX[0x12];

  uVar4 = unaff_EBX[0x10];

  puVar7 = unaff_EBX;

  puVar9 = auStack_40;

  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar9 = *puVar7;

    puVar7 = puVar7 + 1;

    puVar9 = puVar9 + 1;

  }

  uVar5 = unaff_EBX[0x11];

  puVar7 = unaff_EBX;

  for (iVar6 = 0x9b; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar7 = 0;

    puVar7 = puVar7 + 1;

  }

  unaff_EBX[0x11] = uVar5;

  unaff_EBX[0x93] = uVar2;

  puVar7 = auStack_40;

  puVar9 = unaff_EBX;

  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar9 = *puVar7;

    puVar7 = puVar7 + 1;

    puVar9 = puVar9 + 1;

  }

  unaff_EBX[0x12] = uVar3;

  unaff_EBX[0x10] = uVar4;

  return;

}
