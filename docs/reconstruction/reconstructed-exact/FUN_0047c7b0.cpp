// =============================================================================
// FUN_0047c7b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0047c7b0
// Address:   0x0047c7b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047c7b0 @ 0x0047c7b0
// Stable ID: aa_0047c7b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×13, return×8, while×2, do×1.
//  - Notable callees: free×4, FUN_00476d60×3, FUN_00476cc0×2, FUN_00470740, FUN_00477740, FUN_0047a420, FUN_0047a480, FUN_0047c7b0.
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

void __thiscall FUN_0047c7b0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char *pcVar1;

  char cVar2;

  uint uVar3;

  int in_EAX;

  char *_Memory;

  int iVar4;

  uint32_t /* width from decompiler */ *_Memory_00;

  char *pcVar5;

  

  uVar3 = *(uint *)(param_1 + 0x68);

  if ((uVar3 & 1) == 0) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0(param_1);

  }

  if ((uVar3 & 4) != 0) {

    *(uint *)(param_1 + 0x68) = uVar3 | 8;

  }

  _Memory = (char *)FUN_00477740();

  if (_Memory == (char *)0x0) {

    FUN_00476d60();

    return;

  }

  FUN_0047a420();

  iVar4 = FUN_0047a480();

  if (iVar4 != 0) {

    if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

      free(_Memory);

      return;

    }

    (**(code **)(param_1 + 0x24c))(param_1);

    return;

  }

  _Memory[in_EAX] = '\0';

  cVar2 = *_Memory;

  pcVar5 = _Memory;

  while (cVar2 != '\0') {

    pcVar5 = pcVar5 + 1;

    cVar2 = *pcVar5;

  }

  if (pcVar5 != _Memory + in_EAX) {

    pcVar5 = pcVar5 + 1;

  }

  uVar3 = *(uint *)(param_1 + 0x6c);

  *(uint *)(param_1 + 0x6c) = uVar3 | 0x100000;

  if (*(code **)(param_1 + 0x248) == (code *)0x0) {

    _Memory_00 = malloc(0x10);

  }

  else {

    _Memory_00 = (uint32_t /* width from decompiler */ *)(**(code **)(param_1 + 0x248))(param_1);

  }

  if ((_Memory_00 == (uint32_t /* width from decompiler */ *)0x0) && ((*(byte *)(param_1 + 0x6e) & 0x10) == 0)) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0(param_1);

  }

  *(uint *)(param_1 + 0x6c) = uVar3;

  if (_Memory_00 != (uint32_t /* width from decompiler */ *)0x0) {

    _Memory_00[2] = pcVar5;

    *_Memory_00 = 0xffffffff;

    _Memory_00[1] = _Memory;

    pcVar1 = pcVar5 + 1;

    do {

      cVar2 = *pcVar5;

      pcVar5 = pcVar5 + 1;

    } while (cVar2 != '\0');

    _Memory_00[3] = (int)pcVar5 - (int)pcVar1;

    iVar4 = FUN_00470740(param_1,param_2,_Memory_00,1);

    if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

      free(_Memory);

    }

    else {

      (**(code **)(param_1 + 0x24c))(param_1);

    }

    if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

      free(_Memory_00);

    }

    else {

      (**(code **)(param_1 + 0x24c))(param_1);

    }

    if (iVar4 != 0) {

      FUN_00476d60();

    }

    return;

  }

  FUN_00476d60();

  if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

    free(_Memory);

    return;

  }

  (**(code **)(param_1 + 0x24c))(param_1);

  return;

}
