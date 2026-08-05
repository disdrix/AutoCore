// =============================================================================
// FUN_0047c940
// -----------------------------------------------------------------------------
// Stable ID: aa_0047c940
// Address:   0x0047c940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047c940 @ 0x0047c940
// Stable ID: aa_0047c940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~104 non-empty decompiler lines.
//  - Control keywords: if×16, return×8, while×1.
//  - Notable callees: FUN_00476d60×4, free×4, FUN_00476cc0×3, FUN_00470740, FUN_00477740, FUN_0047a420, FUN_0047a480, FUN_0047a620.
//  - Return sites: 8.

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

void FUN_0047c940(uint32_t /* width from decompiler */ param_1,int param_2)



{

  char cVar1;

  uint uVar2;

  int in_EAX;

  char *_Memory;

  int iVar3;

  void *_Memory_00;

  uint32_t /* width from decompiler */ *_Memory_01;

  uint32_t /* width from decompiler */ uVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ local_4;

  

  uVar2 = *(uint *)(in_EAX + 0x68);

  if ((uVar2 & 1) == 0) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0();

  }

  if ((uVar2 & 4) != 0) {

    *(uint *)(in_EAX + 0x68) = uVar2 | 8;

  }

  _Memory = (char *)FUN_00477740();

  if (_Memory == (char *)0x0) {

    FUN_00476d60();

    return;

  }

  FUN_0047a420();

  iVar3 = FUN_0047a480();

  if (iVar3 != 0) {

    if (*(code **)(in_EAX + 0x24c) != (code *)0x0) {

      (**(code **)(in_EAX + 0x24c))();

      return;

    }

    free(_Memory);

    return;

  }

  _Memory[param_2] = '\0';

  cVar1 = *_Memory;

  pcVar5 = _Memory;

  while (cVar1 != '\0') {

    pcVar5 = pcVar5 + 1;

    cVar1 = *pcVar5;

  }

  if (pcVar5 == _Memory + param_2) {

    uVar4 = 0xffffffff;

    FUN_00476d60();

  }

  else {

    if (pcVar5[1] != '\0') {

      FUN_00476d60();

    }

    uVar4 = 0;

    pcVar5 = pcVar5 + 2;

  }

  _Memory_00 = (void *)FUN_0047a620();

  uVar2 = *(uint *)(in_EAX + 0x6c);

  *(uint *)(in_EAX + 0x6c) = uVar2 | 0x100000;

  if (*(code **)(in_EAX + 0x248) == (code *)0x0) {

    _Memory_01 = malloc(0x10);

  }

  else {

    _Memory_01 = (uint32_t /* width from decompiler */ *)(**(code **)(in_EAX + 0x248))();

  }

  if ((_Memory_01 == (uint32_t /* width from decompiler */ *)0x0) && ((*(byte *)(in_EAX + 0x6e) & 0x10) == 0)) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0();

  }

  *(uint *)(in_EAX + 0x6c) = uVar2;

  if (_Memory_01 == (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00476d60();

    if (_Memory_00 != (void *)0x0) {

      if (*(code **)(in_EAX + 0x24c) == (code *)0x0) {

        free(_Memory_00);

        return;

      }

      (**(code **)(in_EAX + 0x24c))();

    }

  }

  else {

    *_Memory_01 = uVar4;

    _Memory_01[1] = _Memory_00;

    _Memory_01[2] = ((int)pcVar5 - (int)_Memory) + (int)_Memory_00;

    _Memory_01[3] = local_4;

    iVar3 = FUN_00470740();

    if (*(code **)(in_EAX + 0x24c) == (code *)0x0) {

      free(_Memory_01);

    }

    else {

      (**(code **)(in_EAX + 0x24c))();

    }

    if (_Memory_00 != (void *)0x0) {

      if (*(code **)(in_EAX + 0x24c) == (code *)0x0) {

        free(_Memory_00);

      }

      else {

        (**(code **)(in_EAX + 0x24c))();

      }

    }

    if (iVar3 != 0) {

                    /* WARNING: Subroutine does not return */

      FUN_00476cc0();

    }

  }

  return;

}
