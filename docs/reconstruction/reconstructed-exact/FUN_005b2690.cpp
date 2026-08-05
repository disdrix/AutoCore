// =============================================================================
// FUN_005b2690
// -----------------------------------------------------------------------------
// Stable ID: aa_005b2690
// Address:   0x005b2690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b2690 @ 0x005b2690
// Stable ID: aa_005b2690
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, while×1, return×1.
//  - Notable callees: BitStream_readBits×2, FUN_0042b250, FUN_005b1570, FUN_005b2690, FUN_005b2d70, free, malloc.
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

void FUN_005b2690(uint32_t /* width from decompiler */ param_1)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint _Size;

  byte local_21;

  ushort local_20 [4];

  uint local_18;

  uint32_t /* width from decompiler */ *local_14;

  uint32_t /* width from decompiler */ *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a677a;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  BitStream_readBits(8,&local_21);

  if (local_21 != 0) {

    local_18 = (uint)local_21;

    do {

      BitStream_readBits(0x10,local_20);

      _Size = (uint)local_20[0];

      pvVar4 = malloc(_Size);

      FUN_005b1570(param_1,pvVar4,_Size);

      puVar5 = operator_new(0x18);

      if (puVar5 == (uint32_t /* width from decompiler */ *)0x0) {

        puVar5 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        puVar5[2] = 0;

      }

      *puVar5 = 0xffffffff;

      puVar5[1] = 0;

      local_14 = puVar5;

      puVar6 = operator_new(0x18);

      local_4 = 0;

      local_10 = puVar6;

      if (puVar6 == (uint32_t /* width from decompiler */ *)0x0) {

        puVar6 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        FUN_0042b250();

        *puVar6 = &PTR_LAB_009d7b00;

        puVar6[4] = 0;

        puVar6[3] = 0;

        *(uint8_t *)(puVar6 + 5) = 0;

      }

      piVar2 = (int *)puVar5[2];

      local_4 = 0xffffffff;

      if (piVar2 != (int *)0x0) {

        piVar1 = piVar2 + 2;

        *piVar1 = *piVar1 + -1;

        if (*piVar1 == 0) {

          (**(code **)(*piVar2 + 8))();

        }

      }

      puVar5[2] = puVar6;

      if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

        puVar6[2] = puVar6[2] + 1;

      }

      iVar3 = puVar5[2];

      if (*(char *)(iVar3 + 0x14) != '\0') {

        *(uint8_t *)(iVar3 + 0x14) = 0;

        free(*(void **)(iVar3 + 0xc));

      }

      *(void **)(iVar3 + 0xc) = pvVar4;

      *(uint *)(iVar3 + 0x10) = _Size;

      *(uint8_t *)(iVar3 + 0x14) = 1;

      puVar5[3] = *(uint32_t /* width from decompiler */ *)(puVar5[2] + 0xc);

      puVar5[4] = 0x40;

      FUN_005b2d70(&local_14);

      local_18 = local_18 - 1;

    } while (local_18 != 0);

  }

  ExceptionList = local_c;

  return;

}
