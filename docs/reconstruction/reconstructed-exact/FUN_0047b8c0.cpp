// =============================================================================
// FUN_0047b8c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0047b8c0
// Address:   0x0047b8c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047b8c0 @ 0x0047b8c0
// Stable ID: aa_0047b8c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~118 non-empty decompiler lines.
//  - Control keywords: if×16, return×12, while×2, do×1.
//  - Notable callees: FUN_00476d60×7, free×5, FUN_0047a480×2, FUN_00470a10, FUN_00476cc0, FUN_004776d0, FUN_00477740, FUN_0047a420.
//  - Return sites: 12.

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

void __thiscall FUN_0047b8c0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int in_EAX;

  char *_Memory;

  int iVar2;

  uint uVar3;

  ushort *puVar4;

  char *pcVar5;

  byte *pbVar6;

  byte *pbVar7;

  char *local_10;

  char local_c;

  void *local_8;

  uint local_4;

  

  if ((*(uint *)(param_1 + 0x68) & 1) == 0) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0(param_1);

  }

  if ((*(uint *)(param_1 + 0x68) & 4) != 0) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  _Memory = (char *)FUN_004776d0();

  FUN_0047a420();

  iVar2 = FUN_0047a480();

  if (iVar2 == 0) {

    _Memory[in_EAX] = '\0';

    cVar1 = *_Memory;

    pcVar5 = _Memory;

    while (cVar1 != '\0') {

      pcVar5 = pcVar5 + 1;

      cVar1 = *pcVar5;

    }

    if (_Memory + in_EAX < pcVar5 + 1) {

      if (*(code **)(param_1 + 0x24c) != (code *)0x0) {

        (**(code **)(param_1 + 0x24c))(param_1);

        FUN_00476d60();

        return;

      }

      free(_Memory);

      FUN_00476d60();

      return;

    }

    local_c = pcVar5[1];

    pbVar6 = (byte *)(pcVar5 + 2);

    iVar2 = (uint)(local_c != '\b') * 4 + 6;

    uVar3 = (int)(_Memory + (in_EAX - (int)pbVar6)) / iVar2;

    if ((int)(_Memory + (in_EAX - (int)pbVar6)) % iVar2 != 0) {

      if (*(code **)(param_1 + 0x24c) != (code *)0x0) {

        (**(code **)(param_1 + 0x24c))(param_1);

        FUN_00476d60();

        return;

      }

      free(_Memory);

      FUN_00476d60();

      return;

    }

    local_4 = uVar3;

    if (0x19999999 < uVar3) {

      FUN_00476d60();

      return;

    }

    local_8 = (void *)FUN_00477740();

    if (local_8 == (void *)0x0) {

      FUN_00476d60();

      return;

    }

    if (0 < (int)uVar3) {

      puVar4 = (ushort *)((int)local_8 + 4);

      do {

        if (local_c == '\b') {

          puVar4[-2] = (ushort)*pbVar6;

          puVar4[-1] = (ushort)pbVar6[1];

          *puVar4 = (ushort)pbVar6[2];

          puVar4[1] = (ushort)pbVar6[3];

          pbVar7 = pbVar6 + 4;

        }

        else {

          puVar4[-2] = (ushort)*pbVar6 * 0x100 + (ushort)pbVar6[1];

          puVar4[-1] = (ushort)pbVar6[2] * 0x100 + (ushort)pbVar6[3];

          *puVar4 = (ushort)pbVar6[4] * 0x100 + (ushort)pbVar6[5];

          puVar4[1] = (ushort)pbVar6[6] * 0x100 + (ushort)pbVar6[7];

          pbVar7 = pbVar6 + 8;

        }

        pbVar6 = pbVar7 + 2;

        uVar3 = uVar3 - 1;

        puVar4[2] = (ushort)*pbVar7 * 0x100 + (ushort)pbVar7[1];

        puVar4 = puVar4 + 5;

      } while (uVar3 != 0);

    }

    local_10 = _Memory;

    FUN_00470a10(param_1,param_2,&local_10,1);

    if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

      free(_Memory);

    }

    else {

      (**(code **)(param_1 + 0x24c))(param_1);

    }

    if (local_8 != (void *)0x0) {

      if (*(code **)(param_1 + 0x24c) != (code *)0x0) {

        (**(code **)(param_1 + 0x24c))(param_1);

        return;

      }

      free(local_8);

    }

  }

  else if (_Memory != (char *)0x0) {

    if (*(code **)(param_1 + 0x24c) != (code *)0x0) {

      (**(code **)(param_1 + 0x24c))(param_1);

      return;

    }

    free(_Memory);

    return;

  }

  return;

}
