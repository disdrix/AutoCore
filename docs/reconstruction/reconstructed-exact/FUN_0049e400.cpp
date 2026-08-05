// =============================================================================
// FUN_0049e400
// -----------------------------------------------------------------------------
// Stable ID: aa_0049e400
// Address:   0x0049e400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0049e400 @ 0x0049e400
// Stable ID: aa_0049e400
// Embedded strings (evidence for future rename):
//   - "scale"
//   - "color"
//   - "alpha"
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_0049e400, FUN_005b8370, FUN_00798d90, FUN_00799200, FUN_00799350, FUN_007a4480.
//  - Strings: "scale"; "color"; "alpha"; "VOG_DEBUG_STOP".
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

uint32_t /* width from decompiler */ FUN_0049e400(int param_1,int *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  int iVar3;

  int *local_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  if (param_2 != (int *)0x0) {

    iVar3 = (**(code **)(*param_2 + 0x44))(param_2,&local_10);

    if ((iVar3 == 0) && (local_10 != (int *)0x0)) {

      puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0x328);

      *puVar1 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x318);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x32c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x31c);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x330) = *(uint32_t /* width from decompiler */ *)(param_1 + 800);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x334) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x324);

      cVar2 = FUN_00799200(local_10,L"scale",param_1 + 0x330,param_1 + 0x334,&param_2);

      if (cVar2 != '\0') {

        *(byte *)(param_1 + 0x3c9) = *(byte *)(param_1 + 0x3c9) | 1;

      }

      cVar2 = FUN_00798d90(local_10,&uStack_4,L"color",puVar1,param_1 + 0x32c,&param_2);

      FUN_005b8370(uStack_4,4,puVar1,param_1);

      if (cVar2 != '\0') {

        *(uint *)(param_1 + 0x3c8) = *(uint *)(param_1 + 0x3c8) | 0x40;

      }

      uStack_c = 0xff;

      uStack_8 = 0xff;

      cVar2 = FUN_00799350(local_10,L"alpha",&uStack_c,&uStack_8,&param_2);

      if (cVar2 != '\0') {

        *(byte *)(param_1 + 0x3c8) = *(byte *)(param_1 + 0x3c8) | 0x80;

        *(uint8_t *)(param_1 + 0x32b) = (uint8_t)uStack_c;

        *(uint8_t *)(param_1 + 0x32f) = (uint8_t)uStack_8;

      }

      (**(code **)(*local_10 + 8))(local_10);

      return 1;

    }

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  return 0;

}
