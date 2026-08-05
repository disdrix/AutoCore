// =============================================================================
// FUN_0047b6f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0047b6f0
// Address:   0x0047b6f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047b6f0 @ 0x0047b6f0
// Stable ID: aa_0047b6f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×12, return×9, while×1.
//  - Notable callees: FUN_00476d60×9, FUN_0047a480×3, FUN_00477710×2, free×2, CONCAT11, CONCAT21, CONCAT31, FUN_00470640.
//  - Return sites: 9.

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

void __thiscall FUN_0047b6f0(char *param_1,int param_2,int param_3)



{

  char cVar1;

  int in_EAX;

  char *_Memory;

  int iVar2;

  void *_Memory_00;

  uint uVar3;

  uint uVar4;

  char *pcVar5;

  

  uVar3 = *(uint *)(in_EAX + 0x68);

  if ((uVar3 & 1) == 0) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0();

  }

  if ((uVar3 & 4) != 0) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  if ((uVar3 & 2) != 0) {

    FUN_00476d60();

  }

  if ((param_2 != 0) && ((*(byte *)(param_2 + 9) & 0x10) != 0)) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  _Memory = (char *)FUN_004776d0();

  FUN_0047a420();

  iVar2 = FUN_0047a480();

  if (iVar2 == 0) {

    _Memory[param_3] = '\0';

    cVar1 = *_Memory;

    pcVar5 = _Memory;

    while (cVar1 != '\0') {

      pcVar5 = pcVar5 + 1;

      cVar1 = *pcVar5;

    }

    if (_Memory + param_3 <= pcVar5 + 1) {

      if (*(code **)(in_EAX + 0x24c) != (code *)0x0) {

        (**(code **)(in_EAX + 0x24c))();

        FUN_00476d60();

        return;

      }

      free(_Memory);

      FUN_00476d60();

      return;

    }

    if (pcVar5[1] != '\0') {

      FUN_00476d60();

    }

    pcVar5 = pcVar5 + (2 - (int)_Memory);

    _Memory_00 = (void *)FUN_0047a620();

    uVar3 = (int)param_1 - (int)pcVar5;

    if ((param_1 < pcVar5) || (uVar3 < 4)) {

      if (_Memory_00 != (void *)0x0) {

        if (*(code **)(in_EAX + 0x24c) != (code *)0x0) {

          (**(code **)(in_EAX + 0x24c))();

          FUN_00476d60();

          return;

        }

        free(_Memory_00);

      }

      FUN_00476d60();

      return;

    }

    uVar4 = CONCAT31(CONCAT21(CONCAT11(pcVar5[(int)_Memory_00],

                                       *(char *)((int)_Memory_00 + (int)(pcVar5 + 1))),

                              *(char *)((int)_Memory_00 + (int)(pcVar5 + 2))),

                     *(char *)((int)_Memory_00 + (int)(pcVar5 + 3)));

    if ((uVar3 <= uVar4) && (uVar3 < uVar4)) {

      FUN_00477710();

      FUN_00476d60();

      return;

    }

    FUN_00470640();

  }

  FUN_00477710();

  return;

}
