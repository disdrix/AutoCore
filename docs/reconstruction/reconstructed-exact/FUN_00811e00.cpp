// =============================================================================
// FUN_00811e00  /  Client_ProcessSectorUpdate_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00811e00
// Address:   0x00811e00 – 0x008120c8  (713 B; autoassault.exe base 0x400000)
// System:    client net / sector object update
// Generated: 2026-07-29 W26-M (refined from 2026-07-23 scaffold)
// Exactness: Decompiler CF preserved; types use fixed-width ints (no bare undefined4).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Client ProcessSectorUpdate for an existing world object.
// String:  "Requesting ProcessSectorUpdate\n"
// ABI:     ECX=packet*, EAX=object*, Stack[0x4]=game*, RET 4, void
// =============================================================================

#include <cstdint>

using uint = uint32_t;
using byte = uint8_t;

extern "C" void __stdcall OutputDebugStringA(const char* s);
void FUN_009972a0();
void FUN_008024d0(int game, uint32_t a, uint32_t b, int z0, int z1, int z2, int o58);
char FUN_0092a200();
uint32_t* FUN_004e87d0();
void FUN_004e88e0(int* a, int* b);

extern uint32_t DAT_00d1d86c;
extern uint32_t DAT_00d1d870;

// NOTE: Ghidra paints this as __thiscall(param_1=ECX packet, param_2=stack game)
// and object as phantom in_EAX. That multi-reg ABI is intentional and sealed.
void __thiscall FUN_00811e00(int param_1, int param_2)
{
  uint* puVar1;
  uint32_t* puVar2;
  char cVar3;
  int* in_EAX; // object* in EAX on entry
  int iVar4;
  int* piVar5;
  uint32_t* puVar6;
  byte bVar7;
  int iStack_70;
  int iStack_6c;
  uint32_t uStack_68;
  uint32_t uStack_64;
  uint8_t* puStack_60;
  uint* puStack_5c;
  uint8_t* puStack_58;
  uint local_44;
  uint8_t auStack_40[12];
  uint8_t auStack_34[4];
  int iStack_30;
  int iStack_2c;
  int aiStack_28[3];
  uint32_t uStack_1c;
  uint32_t uStack_18;
  uint32_t uStack_14;

  puStack_58 = (uint8_t*)0x811e1e;
  OutputDebugStringA("Requesting ProcessSectorUpdate\n");

  // packet+0xA1: special early apply path
  if (*(char*)(param_1 + 0xa1) != '\0') {
    uStack_64 = *(uint32_t*)(param_2 + 0xe04);
    puStack_58 = (uint8_t*)0x0;
    puStack_5c = (uint*)0x0;
    puStack_60 = (uint8_t*)0x0;
    uStack_68 = 2;
    iStack_70 = 0x811e43;
    iStack_6c = param_1;
    (**(code**)(*in_EAX + 0xc4))();
    iStack_70 = 0x811e4a;
    FUN_009972a0();
    iStack_70 = in_EAX[0x59];
    FUN_008024d0(param_2, DAT_00d1d86c, DAT_00d1d870, 0, 0, 0, in_EAX[0x58]);
    return;
  }

  // skip if object matches mission/sector bind
  if (*(int*)(param_2 + 0xe98) != 0) {
    iVar4 = *(int*)(*(int*)(param_2 + 0xe98) + 0x250);
    if (iVar4 != 0) {
      iVar4 = *(int*)(*(int*)(iVar4 + 4) + 4) + 4 + iVar4;
    }
    if (in_EAX[0x2b] == iVar4) {
      return;
    }
  }

  // partial identity → alternate vtbl path
  if ((*(uint*)(param_1 + 8) & *(uint*)(param_1 + 0xc)) != 0xffffffff) {
    puStack_58 = (uint8_t*)0x811ec3;
    (**(code**)(*in_EAX + 0x260))();
    return;
  }

  // merge packet+0xA8 into object flag bit 2 at +0x17C
  in_EAX[0x5f] = in_EAX[0x5f] ^ ((uint)*(byte*)(param_1 + 0xa8) * 4 ^ in_EAX[0x5f]) & 4;

  if (*(char*)(param_1 + 0xa8) == '\0') {
    local_44 = *(uint*)(param_2 + 0x4d0);
    cVar3 = FUN_0092a200();
    if (cVar3 != '\0') {
      *(uint8_t*)(local_44 + 4) = 1;
    }
  }

  piVar5 = (int*)(**(code**)(*in_EAX + 0x1cc))();
  if (piVar5 != (int*)0x0) {
    bVar7 = 0;
    if (((((*(uint*)(param_1 + 8) & *(uint*)(param_1 + 0xc)) == 0xffffffff) &&
          (*(char*)(param_1 + 0xc0) == '\0')) &&
         (*(char*)(param_1 + 0xa8) == '\0')) &&
        (*(char*)(param_1 + 0xa0) == '\0')) {
      bVar7 = 1;
    }

    uStack_14 = *(uint32_t*)(param_1 + 0x7c);
    iStack_30 = *(int*)(param_1 + 100);
    iStack_2c = *(int*)(param_1 + 0x68);
    aiStack_28[0] = *(int*)(param_1 + 0x6c);
    uStack_1c = *(uint32_t*)(param_1 + 0x74);
    uStack_18 = *(uint32_t*)(param_1 + 0x78);
    aiStack_28[2] = (int)*(uint32_t*)(param_1 + 0x70);
    aiStack_28[1] = 0;

    in_EAX[0x20] = iStack_30;
    in_EAX[0x21] = iStack_2c;
    in_EAX[0x22] = aiStack_28[0];
    in_EAX[0x23] = 0;

    // phys adj +0x188 bit0 := bVar7
    puVar1 = (uint*)((int)piVar5 + *(int*)(piVar5[1] + 4) + 0x188);
    *puVar1 = *puVar1 ^ ((uint)bVar7 ^ *(uint*)((int)piVar5 + *(int*)(piVar5[1] + 4) + 0x188)) & 1;

    if (((piVar5[2] == 0) && (*(char*)(param_1 + 0xa2) == '\0')) &&
        ((*(char*)(param_1 + 0xa8) == '\0' && (*(char*)(param_1 + 0xc0) == '\0')))) {
      if ((bVar7 != 0) || (local_44 = local_44 & 0xffffff00, *(char*)(param_1 + 0xa0) != '\0')) {
        local_44 = (local_44 & 0xffffff00) | 1;
      }
      puVar2 = (uint32_t*)*piVar5;
      puStack_58 = auStack_40;
      puStack_5c = (uint*)0x812023;
      puVar6 = (uint32_t*)FUN_004e87d0();
      uStack_64 = *puVar6;
      puStack_60 = (uint8_t*)puVar6[1];
      puStack_5c = (uint*)puVar6[2];
      puStack_58 = (uint8_t*)puVar6[3];
      FUN_004e88e0(&iStack_70, &iStack_30);
      (*(code*)*puVar2)(local_44);
      return;
    }

    puStack_58 = (uint8_t*)0x812082;
    (**(code**)(*piVar5 + 0x18))();
    if ((int*)piVar5[2] != (int*)0x0) {
      iVar4 = *(int*)piVar5[2];
      puStack_58 = auStack_34;
      puStack_5c = &local_44;
      puStack_60 = (uint8_t*)0x81209a;
      puStack_58 = (uint8_t*)FUN_004e88e0();
      puStack_5c = (uint*)0x8120a3;
      (**(code**)(iVar4 + 0x18))();
      iVar4 = *(int*)piVar5[2];
      puStack_5c = (uint*)aiStack_28;
      // decompiler: puStack_60 = &stack0xffffffb8 (frame temp for FUN_004e87d0 args)
      uStack_64 = 0x8120b7;
      puStack_5c = (uint*)FUN_004e87d0();
      puStack_60 = (uint8_t*)0x8120c0;
      (**(code**)(iVar4 + 0x14))();
    }
  }
  return;
}
