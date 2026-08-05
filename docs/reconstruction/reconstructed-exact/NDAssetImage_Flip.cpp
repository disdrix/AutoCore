// =============================================================================
// NDAssetImage_Flip
// -----------------------------------------------------------------------------
// Stable ID: aa_0098ae80
// Address:   0x0098ae80  (autoassault.exe, image base 0x400000)
// Body:      0x0098ae80 – 0x0098af4c
// System:    client assets / NDAssetImage (CxImage Flip)
// Dual:      W20-K 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   In-place vertical flip of NDAssetImage:
//     - temp clone new(0x1b8) + ctor + copy (incl +0x1b0)
//     - reverse-copy DIB rows via pitch@+0x30 / pBits@+0x34 / height@+0x10
//     - NDAssetImage_FlipVertical on temp (+0x1b0)
//     - transfer ownership temp→src (FUN_00432580); destroy temp
//   Caller: BMP top-down path (biHeight < 0) in FUN_00433dc0.
//
// ABI (machine):
//   stack arg0 = NDAssetImage* image
//   epilogue ret 4
//   returns 0 fail / 1 success in AL
// =============================================================================

#include <cstdint>

extern "C" void* operator_new(unsigned size);
extern "C" void FUN_004320d0(void); // NDAssetImage field ctor (ESI = this)
extern "C" void FUN_00432260(int src, char a, char b, char copyInfoBuf);
extern "C" std::uint32_t NDAssetImage_FlipVertical(void); // EBX = this
extern "C" std::uint32_t FUN_00432580(int dest); // transfer temp(EBX) → dest

extern void* PTR_FUN_00a9bcac; // NDAssetImage vtbl

std::uint32_t NDAssetImage_Flip(int param_1 /* NDAssetImage* image */)
{
  int* piVar1;
  int iVar2;
  std::uint32_t* puVar3;
  std::uint32_t* puVar4;
  std::uint32_t uVar5;
  std::uint32_t uVar6;
  std::uint32_t* puVar7;
  std::uint32_t* puVar8;
  std::uint32_t* puVar9;

  iVar2 = param_1;
  if (*(int*)(param_1 + 4) == 0) {
    return 0;
  }
  puVar3 = (std::uint32_t*)operator_new(0x1b8);
  if (puVar3 == nullptr) {
    return 0;
  }
  *puVar3 = (std::uint32_t)&PTR_FUN_00a9bcac;
  FUN_004320d0();
  FUN_00432260(param_1, 0, 0, 1);
  if (puVar3[1] != 0) {
    piVar1 = (int*)(param_1 + 0x10);
    puVar7 = (std::uint32_t*)puVar3[0xd]; // temp+0x34 pBits
    puVar4 = (std::uint32_t*)((*piVar1 + -1) * *(int*)(param_1 + 0x30) +
                              *(int*)(param_1 + 0x34));
    param_1 = 0;
    if (0 < *piVar1) {
      do {
        uVar6 = *(std::uint32_t*)(iVar2 + 0x30);
        puVar8 = puVar4;
        puVar9 = puVar7;
        for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar9 = puVar9 + 1;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(std::uint8_t*)puVar9 = *(std::uint8_t*)puVar8;
          puVar8 = (std::uint32_t*)((int)puVar8 + 1);
          puVar9 = (std::uint32_t*)((int)puVar9 + 1);
        }
        puVar4 = (std::uint32_t*)((int)puVar4 - *(int*)(iVar2 + 0x30));
        puVar7 = (std::uint32_t*)((int)puVar7 + *(int*)(iVar2 + 0x30));
        param_1 = param_1 + 1;
      } while (param_1 < *(int*)(iVar2 + 0x10));
    }
    NDAssetImage_FlipVertical(); // EBX = temp
    FUN_00432580(iVar2);
    (**(void(__thiscall***)(void*, int))*puVar3)(puVar3, 1);
    return 1;
  }
  return 0;
}
