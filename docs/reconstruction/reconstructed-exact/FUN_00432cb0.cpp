// =============================================================================
// FUN_00432cb0  (canonical clean: NDAssetImage_DecodeByFormat_Inferred.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_00432cb0
// Address:   0x00432cb0  (autoassault.exe, image base 0x400000)
// Body:      0x00432cb0–0x004330bf (1039 / 0x40F bytes)
// System:    gfx-asset / NDAssetImage / multi-format decode dispatch
// W22-P dual seal 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// PURPOSE: Dispatch image decode by format mode (EAX).
//   0 auto: TGA → PNG → BMP → FUN_0098b5b0 (rewind stream between tries)
//   1 BMP  2 PNG  3 TGA  4 other  else "Decode: Unknown or wrong format"
// ABI: ECX=stream*, stack context*, EAX=mode, RET 4, return 1|0.
// Embedded string: "Decode: Unknown or wrong format"

extern "C" std::uint8_t NDAssetImage_LoadTGA(void* image, int* stream);
extern "C" std::uint8_t FUN_00435410(void* image, int* stream);
extern "C" std::uint8_t FUN_00433dc0(void* image);
extern "C" std::uint8_t FUN_0098b5b0(void* image);
extern "C" void FUN_004320d0();
extern "C" void FUN_004321b0();
extern "C" void FUN_00432580(int context);
extern "C" void FUN_00432af0();
extern "C" void FUN_00432b10();
extern "C" std::uint32_t FUN_004323c0();
extern void* PTR_FUN_00a9bcac;

std::uint32_t __thiscall FUN_00432cb0(int* param_1, int param_2)
{
  char cVar1;
  int in_EAX; // format mode — retail register formal
  int iVar2;
  char* pcVar3;
  std::uint32_t uVar4;
  int iVar5;
  std::uint32_t unaff_ESI;
  std::uint32_t* puVar6;
  std::uint32_t* puVar7;
  void** local_378;
  int local_374;
  std::uint32_t auStack_350[7];
  char local_334[356];
  void** ppuStack_1d0;
  void** ppuStack_1c8;
  int iStack_1c4;
  std::uint32_t auStack_198[101];

  // NOTE: in_EAX is EAX at entry; not assigned here in clean (matches decompiler form).

  if (in_EAX == 0) {
    iVar2 = (**(code**)(*param_1 + 0x14))();
    local_378 = (void**)&PTR_FUN_00a9bcac;
    FUN_004320d0();
    local_378 = (void**)&PTR_FUN_00a9bcac;
    if (local_374 == 0) {
      puVar6 = (std::uint32_t*)(param_2 + 0x30);
      puVar7 = auStack_350 + 2;
      for (iVar5 = 0x5f; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    cVar1 = NDAssetImage_LoadTGA(&local_378, param_1);
    if (cVar1 == '\0') {
      (**(code**)(*param_1 + 0x10))(iVar2, 0);
      FUN_004321b0();
      FUN_004320d0();
      if (iVar2 == 0) {
        puVar6 = (std::uint32_t*)(param_2 + 0x30);
        puVar7 = auStack_350;
        for (iVar5 = 0x5f; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
      }
      cVar1 = FUN_00435410((void*)&local_378 /* decomp: &stack0xfffffc80 */, param_1);
      if (cVar1 == '\0') {
        (**(code**)(*param_1 + 0x10))(iVar2, 0);
        local_378 = (void**)&PTR_FUN_00a9bcac;
        FUN_004321b0();
        local_378 = (void**)&PTR_FUN_00a9bcac;
        FUN_004320d0();
        local_378 = (void**)&PTR_FUN_00a9bcac;
        if (local_374 == 0) {
          puVar6 = (std::uint32_t*)(param_2 + 0x30);
          puVar7 = auStack_350 + 2;
          for (iVar5 = 0x5f; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          }
        }
        cVar1 = FUN_00433dc0(&local_378);
        if (cVar1 == '\0') {
          (**(code**)(*param_1 + 0x10))(iVar2, 0);
          FUN_004321b0();
          FUN_00432b10();
          if (iStack_1c4 == 0) {
            puVar6 = (std::uint32_t*)(param_2 + 0x30);
            puVar7 = auStack_198;
            for (iVar2 = 0x5f; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar7 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar7 = puVar7 + 1;
            }
          }
          cVar1 = FUN_0098b5b0(&ppuStack_1c8);
          if (cVar1 != '\0') {
            FUN_00432580(param_2);
            ppuStack_1c8 = (void**)&PTR_FUN_00a9bcac;
            FUN_004321b0();
            return 1;
          }
          (**(code**)(*param_1 + 0x10))(unaff_ESI, 0);
          ppuStack_1d0 = (void**)&PTR_FUN_00a9bcac;
          FUN_004321b0();
        LAB_00432ea6:
          pcVar3 = (char*)"Decode: Unknown or wrong format";
          puVar6 = (std::uint32_t*)(param_2 + 0x44);
          for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar6 = *(std::uint32_t*)pcVar3;
            pcVar3 = pcVar3 + 4;
            puVar6 = puVar6 + 1;
          }
          return 0;
        }
      }
    }
  } else if (in_EAX == 1) {
    local_378 = (void**)&PTR_FUN_00a9bcac;
    FUN_004320d0();
    local_378 = (void**)&PTR_FUN_00a9bcac;
    if (local_374 == 0) {
      puVar6 = (std::uint32_t*)(param_2 + 0x30);
      puVar7 = auStack_350 + 2;
      for (iVar2 = 0x5f; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    cVar1 = FUN_00433dc0(&local_378);
    if (cVar1 == '\0') {
      pcVar3 = local_334;
      iVar2 = (param_2 + 0x44) - (int)pcVar3;
      do {
        cVar1 = *pcVar3;
        pcVar3[iVar2] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      local_378 = (void**)&PTR_FUN_00a9bcac;
      FUN_004321b0();
      return 0;
    }
  } else if (in_EAX == 2) {
    local_378 = (void**)&PTR_FUN_00a9bcac;
    FUN_004320d0();
    local_378 = (void**)&PTR_FUN_00a9bcac;
    if (local_374 == 0) {
      puVar6 = (std::uint32_t*)(param_2 + 0x30);
      puVar7 = auStack_350 + 2;
      for (iVar2 = 0x5f; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    cVar1 = FUN_00435410(&local_378, param_1);
    if (cVar1 == '\0') {
      pcVar3 = local_334;
      iVar2 = (param_2 + 0x44) - (int)pcVar3;
      do {
        cVar1 = *pcVar3;
        pcVar3[iVar2] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      local_378 = (void**)&PTR_FUN_00a9bcac;
      FUN_004321b0();
      return 0;
    }
  } else if (in_EAX == 3) {
    FUN_00432af0();
    if (local_374 == 0) {
      puVar6 = (std::uint32_t*)(param_2 + 0x30);
      puVar7 = auStack_350 + 2;
      for (iVar2 = 0x5f; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    cVar1 = NDAssetImage_LoadTGA(&local_378, param_1);
    if (cVar1 == '\0') {
      pcVar3 = local_334;
      iVar2 = (param_2 + 0x44) - (int)pcVar3;
      do {
        cVar1 = *pcVar3;
        pcVar3[iVar2] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      local_378 = (void**)&PTR_FUN_00a9bcac;
      FUN_004321b0();
      return 0;
    }
  } else {
    if (in_EAX != 4) goto LAB_00432ea6;
    FUN_00432b10();
    uVar4 = FUN_004323c0();
    cVar1 = FUN_0098b5b0((void*)uVar4);
    if (cVar1 == '\0') {
      pcVar3 = local_334;
      iVar2 = (param_2 + 0x44) - (int)pcVar3;
      do {
        cVar1 = *pcVar3;
        pcVar3[iVar2] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      local_378 = (void**)&PTR_FUN_00a9bcac;
      FUN_004321b0();
      return 0;
    }
  }
  FUN_00432580(param_2);
  local_378 = (void**)&PTR_FUN_00a9bcac;
  FUN_004321b0();
  return 1;
}
