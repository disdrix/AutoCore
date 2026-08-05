// =============================================================================
// FUN_008f66c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008f66c0
// Address:   0x008f66c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f66c0 @ 0x008f66c0
// Stable ID: aa_008f66c0
// Embedded strings (evidence for future rename):
//   - "%s-%04d-%02d-%02d-%02d.%02d.%02d.txt"
//   - "[%s] %s => %s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×7, for×1, do×1, while×1, return×1.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_008f66c0, GetLocalTime, fclose, fopen, fprintf, sprintf.
//  - Strings: "%s-%04d-%02d-%02d-%02d.%02d.%02d.txt"; "wt+"; "[%s] %s => %s\n".
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

void FUN_008f66c0(int param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  int iVar1;

  FILE *_File;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  _SYSTEMTIME local_120;

  char local_110;

  uint32_t /* width from decompiler */ local_10f;

  

  FUN_007a69d0();

  local_110 = '\0';

  puVar5 = &local_10f;

  for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  *(uint8_t *)((int)puVar5 + 2) = 0;

  GetLocalTime(&local_120);

  sprintf(&local_110,"%s-%04d-%02d-%02d-%02d.%02d.%02d.txt",param_2,(uint)local_120.wYear,

          (uint)local_120.wMonth,(uint)local_120.wDay,(uint)local_120.wHour,(uint)local_120.wMinute,

          (uint)local_120.wSecond);

  _File = fopen(&local_110,"wt+");

  if (_File != (FILE *)0x0) {

    iVar4 = *(int *)(param_1 + 0x540);

    if (iVar4 != 0) {

      param_3 = *(int *)(iVar4 + 0x518) - param_3;

      if (param_3 < 0) {

        if (*(char *)(iVar4 + 0x500) == '\0') {

          param_3 = 0;

        }

        else {

          param_3 = param_3 + 0x96;

        }

      }

      if (param_3 != *(int *)(iVar4 + 0x518)) {

        do {

          uVar6 = *(uint32_t /* width from decompiler */ *)(param_3 * 0x10 + 0x524 + iVar4);

          iVar1 = param_3 * 0x10 + iVar4;

          uVar7 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x528);

          uVar2 = *(uint *)(iVar1 + 0x52c);

          if (0xc < uVar2) {

            uVar2 = 0xc;

          }

          uVar3 = FUN_007a6de0((&PTR_DAT_00a36b4c)[uVar2],0xffffffff);

          fprintf(_File,"[%s] %s => %s\n",uVar3,uVar6,uVar7);

          param_3 = param_3 + 1;

          if (0x95 < param_3) {

            param_3 = 0;

          }

        } while (param_3 != *(int *)(iVar4 + 0x518));

      }

    }

    fclose(_File);

  }

  return;

}
