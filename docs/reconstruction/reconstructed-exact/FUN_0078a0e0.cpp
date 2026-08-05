// =============================================================================
// FUN_0078a0e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0078a0e0
// Address:   0x0078a0e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078a0e0 @ 0x0078a0e0
// Stable ID: aa_0078a0e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×5, while×3, do×2, return×1.
//  - Notable callees: FUN_00423f40×2, FUN_0041c7e0, FUN_004294f0, FUN_007894a0, FUN_0078a0e0, LeaveCriticalSection.
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

void __thiscall FUN_0078a0e0(int param_1,uint *param_2,uint param_3,uint param_4)



{

  uint uVar1;

  uint *puVar2;

  uint *puVar3;

  char *pcVar4;

  int iVar5;

  uint *puVar6;

  

  puVar6 = param_2;

  if (param_2 != (uint *)0x0) {

    *(uint8_t *)(param_1 + 0x566) = 0;

    puVar2 = operator_new(0x30);

    if (puVar2 == (uint *)0x0) {

      puVar2 = (uint *)0x0;

    }

    else {

      *(uint8_t *)((int)puVar2 + 0x12) = 0xff;

      *(uint8_t *)((int)puVar2 + 0x11) = 0xff;

      *(uint8_t *)(puVar2 + 4) = 0xff;

      *(uint8_t *)((int)puVar2 + 0x13) = 0xff;

      *(uint8_t *)((int)puVar2 + 0x16) = 0xff;

      *(uint8_t *)((int)puVar2 + 0x15) = 0xff;

      *(uint8_t *)(puVar2 + 5) = 0xff;

      *(uint8_t *)((int)puVar2 + 0x17) = 0xff;

      *(uint8_t *)((int)puVar2 + 0x1a) = 0xff;

      *(uint8_t *)((int)puVar2 + 0x19) = 0xff;

      *(uint8_t *)(puVar2 + 6) = 0xff;

      *(uint8_t *)((int)puVar2 + 0x1b) = 0xff;

    }

    *puVar2 = param_3;

    puVar2[1] = param_4;

    puVar2[7] = 0;

    puVar2[3] = *(uint *)(param_1 + 0x4fc);

    puVar2[8] = 0;

    puVar2[9] = 0;

    puVar2[10] = 0;

    puVar2[4] = *(uint *)(param_1 + 0x500);

    puVar2[5] = *(uint *)(param_1 + 0x504);

    puVar2[6] = *(uint *)(param_1 + 0x508);

    puVar3 = puVar6;

    do {

      uVar1 = *puVar3;

      puVar3 = (uint *)((int)puVar3 + 1);

    } while ((char)uVar1 != '\0');

    pcVar4 = operator_new__((uint)((int)puVar3 + (1 - (int)((int)puVar6 + 1))));

    puVar2[2] = (uint)pcVar4;

    do {

      uVar1 = *puVar6;

      *pcVar4 = (char)uVar1;

      puVar6 = (uint *)((int)puVar6 + 1);

      pcVar4 = pcVar4 + 1;

    } while ((char)uVar1 != '\0');

    FUN_004294f0();

    iVar5 = FUN_00423f40(&param_2);

    puVar6 = param_2;

    while (param_2 = puVar6, iVar5 == 0) {

      if ((puVar6 != (uint *)0x0) && ((*puVar6 & puVar6[1]) == 0xffffffff)) {

        *puVar6 = param_3;

        puVar6[1] = param_4;

        if (puVar6[2] != 0) {

          FUN_007894a0();

        }

        puVar2[7] = (uint)puVar6;

        break;

      }

      iVar5 = FUN_00423f40(&param_2);

      puVar6 = param_2;

    }

    if (*(char *)(param_1 + 0x560) != '\0') {

      *(uint8_t *)(param_1 + 0x560) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x53c));

    }

    FUN_0041c7e0(param_1 + 0x50c,puVar2);

  }

  return;

}
