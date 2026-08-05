// =============================================================================
// FUN_00789550
// -----------------------------------------------------------------------------
// Stable ID: aa_00789550
// Address:   0x00789550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00789550 @ 0x00789550
// Stable ID: aa_00789550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×10, do×1, return×1, goto×1, while×1.
//  - Notable callees: FUN_00423f40×2, FUN_004294f0, FUN_00789550, LeaveCriticalSection.
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

void __fastcall FUN_00789550(int param_1)



{

  uint *puVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  FUN_004294f0();

  local_4 = 0;

  iVar3 = FUN_00423f40(&local_8);

  puVar1 = local_8;

  do {

    if (iVar3 != 0) {

      if (*(char *)(param_1 + 0x560) != '\0') {

        *(uint8_t *)(param_1 + 0x560) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x53c));

      }

      return;

    }

    local_8 = puVar1;

    if (((puVar1 != (uint *)0x0) && (puVar1[3] != 0)) &&

       (cVar2 = (**(code **)(*(int *)puVar1[3] + 0x3b8))(), cVar2 != '\0')) {

      if ((*(char *)(param_1 + 0x565) == '\0') || ((*puVar1 & puVar1[1]) != 0xffffffff)) {

        cVar2 = (**(code **)(*(int *)puVar1[3] + 0xd8))();

        if (cVar2 == '\0') {

          (**(code **)(*(int *)puVar1[3] + 0xd4))(1);

          (**(code **)(*(int *)puVar1[3] + 0x34c))();

        }

      }

      else {

        cVar2 = (**(code **)(*(int *)puVar1[3] + 0xd8))();

        if (cVar2 == '\x01') {

          (**(code **)(*(int *)puVar1[3] + 0xd4))(0);

          (**(code **)(*(int *)puVar1[3] + 0x34c))();

        }

      }

      if ((*(uint *)(param_1 + 0x998) & *(uint *)(param_1 + 0x99c)) == 0xffffffff) {

        cVar2 = (**(code **)(*(int *)puVar1[3] + 0x3bc))();

        if (cVar2 != '\0') {

          (**(code **)(*(int *)puVar1[3] + 0x3c8))(0,1);

          (**(code **)(*(int *)puVar1[3] + 0x34c))();

        }

      }

      else {

        if (((*puVar1 == *(uint *)(param_1 + 0x998)) && (puVar1[1] == *(uint *)(param_1 + 0x99c)))

           && (cVar2 = (**(code **)(*(int *)puVar1[3] + 0x3bc))(), cVar2 == '\0')) {

          uVar4 = 1;

        }

        else {

          if (((*puVar1 == *(uint *)(param_1 + 0x998)) && (puVar1[1] == *(uint *)(param_1 + 0x99c)))

             || (cVar2 = (**(code **)(*(int *)puVar1[3] + 0x3bc))(), cVar2 == '\0'))

          goto LAB_007896af;

          uVar4 = 0;

        }

        (**(code **)(*(int *)puVar1[3] + 0x3c8))(uVar4,1);

        (**(code **)(*(int *)puVar1[3] + 0x34c))();

      }

    }

LAB_007896af:

    iVar3 = FUN_00423f40(&local_8);

    puVar1 = local_8;

  } while( true );

}
