// =============================================================================
// FUN_008024d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008024d0
// Address:   0x008024d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008024d0 @ 0x008024d0
// Stable ID: aa_008024d0
// Embedded strings (evidence for future rename):
//   - "Getting Data..."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00401430×3, FUN_00401380, FUN_008024d0, FUN_00844b60, FUN_00844c00, FUN_0084d140, FUN_0092f000.
//  - Strings: "Getting Data...".
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

void __thiscall

FUN_008024d0(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,int param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  void *pvVar1;

  int *piVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ uStack0000001c;

  uint32_t /* width from decompiler */ uStack00000020;

  int local_20;

  void *pvStack_1c;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bb4b7;

  local_c = ExceptionList;

  if (param_1 != 0) {

    uStack0000001c = *(uint32_t /* width from decompiler */ *)(param_1 + 0x160);

    uStack00000020 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x164);

    ExceptionList = &local_c;

    FUN_00401430();

    if ((local_20 == *(int *)(param_2 + 0x3094)) || (*(int **)(local_20 + 0x18) == (int *)0x0)) {

      pvVar1 = operator_new(0x570);

      local_4 = 0;

      if (pvVar1 == (void *)0x0) {

        piVar2 = (int *)0x0;

      }

      else {

        piVar2 = (int *)FUN_0084d140(pvVar1,*(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0xe04) + 0xe890));

      }

      local_4 = 0xffffffff;

      *(uint8_t *)(piVar2 + 0x14a) = 1;

      (**(code **)(*piVar2 + 0x43c))();

      FUN_00844b60();

      FUN_00844c00(param_3,param_4,param_5,param_6);

      (**(code **)(*piVar2 + 0x1d8))("Getting Data...",1,1);

      FUN_00401430();

      if (param_4 == *(int *)(puStack_8 + 0x3094)) {

        FUN_00401380();

        piVar3 = (int *)FUN_00401430();

        param_4 = *piVar3;

        if (param_4 == *(int *)(puStack_8 + 0x3094)) {

          (**(code **)*piVar2)(1);

          ExceptionList = pvStack_1c;

          return;

        }

      }

      *(int **)(param_4 + 0x18) = piVar2;

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(puStack_8 + 0xf40) + 0xa8))(piVar2);

      (**(code **)(*piVar2 + 4))(1);

    }

    else {

      (**(code **)(**(int **)(local_20 + 0x18) + 0x94))();

    }

    FUN_0092f000();

  }

  ExceptionList = local_c;

  return;

}
