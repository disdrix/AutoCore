// =============================================================================
// FUN_00434b30  (canonical clean: NDAssetImage_DecodeTgaRleRow_Inferred.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_00434b30
// Address:   0x00434b30  (autoassault.exe, image base 0x400000)
// Body:      0x00434b30–0x00434d99 (617 / 0x269 bytes)
// System:    gfx-asset / NDAssetImage / TGA RLE row
// W22-P dual seal 2026-07-29 — scaffold alias; prefer named clean.
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// PURPOSE: TGA RLE one-row decoder used by NDAssetImage_LoadTGA (RLE path).
// ABI: thiscall ECX=stream*; 6 stack args; RET 0x18; AL = RLE state carry.
// See: NDAssetImage_DecodeTgaRleRow_Inferred.cpp and
//      reviews/A|B_aa_00434b30_NDAssetImage_DecodeTgaRleRow_Inferred.md

std::uint32_t /* AL = RLE state */ __thiscall
FUN_00434b30(int* param_1, int param_2, int param_3, int param_4, int param_5,
             std::uint32_t param_6, std::uint8_t param_7)
{
  std::uint16_t* puVar1;
  std::uint16_t* puVar2;
  std::uint8_t bVar3;
  int iVar4;
  std::uint32_t uVar5;
  void* pvVar6;
  int iVar7;
  std::uint16_t uStack_44;
  std::uint8_t uStack_42;
  std::uint32_t uStack_41;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int local_2c;
  std::uint32_t local_28;
  std::uint16_t uStack_24;
  std::uint8_t uStack_22;
  std::uint16_t uStack_20;
  std::uint8_t bStack_1e;
  std::uint16_t auStack_1c[3];
  std::uint8_t uStack_16;
  std::uint8_t local_15;

  iVar7 = 0;
  local_28 = 0;
  do {
    bVar3 = param_7;
    if (param_5 <= iVar7) {
      return param_7;
    }
    local_2c = iVar7;
    if (param_7 == 0xff) {
      (**(code**)(*param_1 + 8))(&local_15, 1, 1);
    } else {
      param_7 = 0xff;
      local_15 = bVar3;
    }
    if ((char)local_15 < '\0') {
      uVar5 = local_15 - 0x7f;
      local_15 = (std::uint8_t)uVar5;
      if (param_5 < (int)((uVar5 & 0xff) + iVar7)) {
        param_7 = (local_15 - (char)param_5) + '\x7f' + (char)iVar7;
        local_28 = (**(code**)(*param_1 + 0x14))();
        uVar5 = param_5 - iVar7;
        local_15 = (std::uint8_t)uVar5;
      }
      switch (*(std::uint8_t*)(param_4 + 0x10)) {
      case 8:
        (**(code**)(*param_1 + 8))(&uStack_16, 1, 1);
        for (iStack_3c = 0; uVar5 = (std::uint32_t)local_15, iStack_3c < (int)uVar5;
             iStack_3c = iStack_3c + 1) {
          *(std::uint8_t*)(iStack_3c + param_3) = uStack_16;
        }
        break;
      case 0xf:
      case 0x10:
        (**(code**)(*param_1 + 8))(auStack_1c, 2, 1);
        uStack_20 = (std::uint16_t)(
            ((((std::uint16_t)(auStack_1c[0] >> 2)) << 8) |
             (std::uint8_t)(auStack_1c[0] * 8)) &
            0xf8ff);
        bStack_1e = (std::uint8_t)(auStack_1c[0] >> 7) & 0xf8;
        for (iStack_38 = 0; uVar5 = (std::uint32_t)local_15, iStack_38 < (int)uVar5;
             iStack_38 = iStack_38 + 1) {
          puVar2 = (std::uint16_t*)(param_3 + iStack_38 * 3);
          *puVar2 = uStack_20;
          *(std::uint8_t*)(puVar2 + 1) = bStack_1e;
        }
        break;
      case 0x18:
        (**(code**)(*param_1 + 8))(&uStack_24, 3, 1);
        for (iStack_34 = 0; uVar5 = (std::uint32_t)local_15, iStack_34 < (int)uVar5;
             iStack_34 = iStack_34 + 1) {
          puVar1 = (std::uint16_t*)(param_3 + iStack_34 * 3);
          *puVar1 = uStack_24;
          *(std::uint8_t*)(puVar1 + 1) = uStack_22;
        }
        break;
      case 0x20:
        (**(code**)(*param_1 + 8))(&uStack_44, 4, 1);
        iStack_30 = 0;
        while (iVar4 = iStack_30, uVar5 = (std::uint32_t)local_15, iStack_30 < (int)uVar5) {
          puVar1 = (std::uint16_t*)(param_3 + iStack_30 * 3);
          *puVar1 = uStack_44;
          *(std::uint8_t*)(puVar1 + 1) = uStack_42;
          extern void FUN_00433280(std::uint32_t);
          FUN_00433280(uStack_41);
          iVar7 = local_2c;
          iStack_30 = iVar4 + 1;
        }
      }
      if (param_7 != 0xff) {
        (**(code**)(*param_1 + 0x10))(local_28, 0);
        goto LAB_00434d4a;
      }
    } else {
      uVar5 = local_15 + 1;
      local_15 = (std::uint8_t)uVar5;
      if (param_5 < (int)((uVar5 & 0xff) + iVar7)) {
        param_7 = (local_15 - (char)param_5) + -1 + (char)iVar7;
        uVar5 = param_5 - iVar7;
        local_15 = (std::uint8_t)uVar5;
      }
      extern void FUN_00434dd0(int, int, std::uint32_t, std::uint32_t, int);
      FUN_00434dd0(param_2, param_4, uVar5 & 0xff, param_6, iVar7);
    LAB_00434d4a:
      uVar5 = (std::uint32_t)local_15;
    }
    pvVar6 = (void*)(uVar5 & 0xff);
    if (*(short*)(param_2 + 0x16) == 0x18) {
      param_3 = (int)pvVar6 * 3 + param_3;
      iVar7 = iVar7 + (int)pvVar6;
    } else {
      param_3 = param_3 + (int)pvVar6;
      iVar7 = iVar7 + (int)pvVar6;
    }
  } while (true);
}
