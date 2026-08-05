// =============================================================================
// FUN_004c6ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c6ac0
// Address:   0x004c6ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c6ac0 @ 0x004c6ac0
// Stable ID: aa_004c6ac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~158 non-empty decompiler lines.
//  - Control keywords: if×36, return×2.
//  - Notable callees: FUN_004c4e80×2, FUN_004c6ac0.
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

void __thiscall FUN_004c6ac0(int param_1,uint param_2)



{

  int *piVar1;

  uint *puVar2;

  byte *pbVar3;

  

  if ((param_2 & 0x125e) != 0) {

    if ((param_2 & 2) != 0) {

      if ((param_2 & 0x100000) == 0) {

        piVar1 = (int *)(param_1 + -0x1c4);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + -0x1c4) = 0;

        }

      }

      else {

        piVar1 = (int *)(param_1 + -0x1a4);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + -0x1a4) = 0;

        }

      }

      if (*(int *)(param_1 + -0x1c4) + *(int *)(param_1 + -0x1a4) == 0) {

        puVar2 = (uint *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x448 + param_1);

        *puVar2 = *puVar2 & 0xfffffffd;

      }

    }

    if ((param_2 & 4) != 0) {

      if ((param_2 & 0x100000) == 0) {

        piVar1 = (int *)(param_1 + -0x1c0);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + -0x1c0) = 0;

        }

      }

      else {

        piVar1 = (int *)(param_1 + -0x1a0);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + -0x1a0) = 0;

        }

      }

      if (*(int *)(param_1 + -0x1c0) + *(int *)(param_1 + -0x1a0) == 0) {

        puVar2 = (uint *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x448 + param_1);

        *puVar2 = *puVar2 & 0xfffffffb;

      }

    }

    if ((param_2 & 8) != 0) {

      if ((param_2 & 0x100000) == 0) {

        piVar1 = (int *)(param_1 + -0x1bc);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + -0x1bc) = 0;

        }

      }

      else {

        piVar1 = (int *)(param_1 + -0x19c);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + -0x19c) = 0;

        }

      }

      if (*(int *)(param_1 + -0x1bc) + *(int *)(param_1 + -0x19c) == 0) {

        puVar2 = (uint *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x448 + param_1);

        *puVar2 = *puVar2 & 0xfffffff7;

      }

    }

    if ((param_2 & 0x10) != 0) {

      if ((param_2 & 0x100000) == 0) {

        piVar1 = (int *)(param_1 + -0x1b8);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + -0x1b8) = 0;

        }

      }

      else {

        piVar1 = (int *)(param_1 + -0x198);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + -0x198) = 0;

        }

      }

      if (*(int *)(param_1 + -0x1b8) + *(int *)(param_1 + -0x198) == 0) {

        puVar2 = (uint *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x448 + param_1);

        *puVar2 = *puVar2 & 0xffffffef;

      }

    }

    if ((param_2 & 0x40) != 0) {

      if ((param_2 & 0x100000) == 0) {

        piVar1 = (int *)(param_1 + -0x1b4);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + -0x1b4) = 0;

        }

      }

      else {

        piVar1 = (int *)(param_1 + -0x194);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + -0x194) = 0;

        }

      }

      if (*(int *)(param_1 + -0x1b4) + *(int *)(param_1 + -0x194) == 0) {

        puVar2 = (uint *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x448 + param_1);

        *puVar2 = *puVar2 & 0xffffffbf;

      }

    }

    if ((param_2 & 0x200) != 0) {

      if ((param_2 & 0x100000) == 0) {

        piVar1 = (int *)(param_1 + -0x1b0);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + -0x1b0) = 0;

        }

      }

      else {

        piVar1 = (int *)(param_1 + -400);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + -400) = 0;

        }

      }

      if (*(int *)(param_1 + -0x1b0) + *(int *)(param_1 + -400) == 0) {

        pbVar3 = (byte *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x447 + param_1);

        *pbVar3 = *pbVar3 & 0xfd;

      }

    }

    if ((param_2 & 0x1000) != 0) {

      if ((param_2 & 0x100000) == 0) {

        piVar1 = (int *)(param_1 + -0x1ac);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + -0x1ac) = 0;

        }

      }

      else {

        piVar1 = (int *)(param_1 + -0x18c);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + -0x18c) = 0;

        }

      }

      if (*(int *)(param_1 + -0x1ac) + *(int *)(param_1 + -0x18c) == 0) {

        pbVar3 = (byte *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x447 + param_1);

        *pbVar3 = *pbVar3 & 0xef;

      }

    }

    *(bool *)(param_1 + -0x1eb) =

         0 < *(int *)(param_1 + -0x1c4) + *(int *)(param_1 + -0x1c0) + *(int *)(param_1 + -0x1bc) +

             *(int *)(param_1 + -0x1b8) + *(int *)(param_1 + -0x1b4) + *(int *)(param_1 + -0x1b0) +

             *(int *)(param_1 + -0x1ac);

    FUN_004c4e80();

    return;

  }

  puVar2 = (uint *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + param_1 + -0x448);

  *puVar2 = *puVar2 & ~param_2;

  FUN_004c4e80();

  return;

}
