// =============================================================================
// LCD_CLCDGfx_Initialize
// -----------------------------------------------------------------------------
// Stable ID: aa_00805900
// Address:   0x00805900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for LCD_CLCDGfx_Initialize @ 0x00805900
// Stable ID: aa_00805900
// Embedded strings (evidence for future rename):
//   - "CLCDGfx::Initialize(): failed to create compatible DC.\n"
//   - "CLCDGfx::Initialize(): failed to allocate bitmap info.\n"
//   - "CLCDGfx::Initialize(): failed to create bitmap.\n"
//   - "CLCDGfx::Initialize(): failed to allocate the lcd screen structure.\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: return×5, if×4, for×1, do×1, while×1.
//  - Notable callees: CLCDGfx::Initialize×4, FUN_007a4480×4, FUN_00805860×4, CreateCompatibleDC, CreateDIBSection, LCD_CLCDGfx_Initialize.
//  - Strings: "CLCDGfx::Initialize(): failed to create compatible DC.\n"; "CLCDGfx::Initialize(): failed to allocate bitmap info.\n"; "CLCDGfx::Initialize(): failed to create bitmap.\n".
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CLCDGfx::Initialize(): failed to allocate the lcd screen structure.
"
 * Domain alias of FUN_00805900 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall LCD_CLCDGfx_Initialize(uint32_t /* width from decompiler */ param_1,int param_2)



{

  uint32_t /* width from decompiler */ in_EAX;

  HDC pHVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  HBITMAP pHVar4;

  void *pvVar5;

  char cVar6;

  int iVar7;

  

  *(uint32_t /* width from decompiler */ *)(param_2 + 4) = in_EAX;

  *(uint32_t /* width from decompiler */ *)(param_2 + 8) = param_1;

  pHVar1 = CreateCompatibleDC((HDC)0x0);

  *(HDC *)(param_2 + 0x14) = pHVar1;

  if (pHVar1 == (HDC)0x0) {

    FUN_007a4480(0xffffffff,&DAT_00a2c2a4,"CLCDGfx::Initialize(): failed to create compatible DC.\n"

                );

    FUN_00805860();

    return 0x80004005;

  }

  puVar2 = operator_new__(0x42c);

  *(uint32_t /* width from decompiler */ **)(param_2 + 0x10) = puVar2;

  if (puVar2 == (uint32_t /* width from decompiler */ *)0x0) {

    FUN_007a4480(0xffffffff,&DAT_00a2c2a4,"CLCDGfx::Initialize(): failed to allocate bitmap info.\n"

                );

    FUN_00805860();

    return 0x8007000e;

  }

  for (iVar7 = 0x10b; iVar7 != 0; iVar7 = iVar7 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  **(uint32_t /* width from decompiler */ **)(param_2 + 0x10) = 0x28;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x10) + 4) = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

  *(int *)(*(int *)(param_2 + 0x10) + 8) = -*(int *)(param_2 + 8);

  *(uint16_t *)(*(int *)(param_2 + 0x10) + 0xc) = 1;

  *(uint16_t *)(*(int *)(param_2 + 0x10) + 0xe) = 8;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x10) + 0x10) = 0;

  iVar7 = *(int *)(param_2 + 0x10);

  iVar3 = (uint)*(ushort *)(iVar7 + 0xe) * *(int *)(iVar7 + 8) * *(int *)(iVar7 + 4);

  *(int *)(iVar7 + 0x14) = (int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x10) + 0x18) = 0xc80;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x10) + 0x1c) = 0xc80;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x10) + 0x20) = 0x100;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x10) + 0x24) = 0x100;

  iVar7 = 0;

  do {

    cVar6 = (iVar7 < 0x81) + -1;

    iVar7 = iVar7 + 1;

    *(char *)(*(int *)(param_2 + 0x10) + 0x26 + iVar7 * 4) = cVar6;

    *(char *)(*(int *)(param_2 + 0x10) + 0x25 + iVar7 * 4) = cVar6;

    *(char *)(*(int *)(param_2 + 0x10) + 0x24 + iVar7 * 4) = cVar6;

    *(uint8_t *)(*(int *)(param_2 + 0x10) + 0x27 + iVar7 * 4) = 0;

  } while (iVar7 < 0x100);

  pHVar4 = CreateDIBSection(*(HDC *)(param_2 + 0x14),*(BITMAPINFO **)(param_2 + 0x10),0,

                            (void **)(param_2 + 0x20),(HANDLE)0x0,0);

  *(HBITMAP *)(param_2 + 0x18) = pHVar4;

  if (pHVar4 == (HBITMAP)0x0) {

    FUN_007a4480(0xffffffff,&DAT_00a2c2a4,"CLCDGfx::Initialize(): failed to create bitmap.\n");

    FUN_00805860();

    return 0x80004005;

  }

  pvVar5 = operator_new(0x1ae4);

  *(void **)(param_2 + 0xc) = pvVar5;

  if (pvVar5 == (void *)0x0) {

    FUN_007a4480(0xffffffff,&DAT_00a2c2a4,

                 "CLCDGfx::Initialize(): failed to allocate the lcd screen structure.\n");

    FUN_00805860();

    return 0x8007000e;

  }

  return 0;

}
