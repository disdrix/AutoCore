// Twin of AssPackObject_OpenFromPath_Inferred.cpp (aa_0071a9d0 / FUN_0071a9d0).
// See AssPackObject_OpenFromPath_Inferred.cpp for sealed clean body (W37-X).

#include <cstdint>

extern "C" char* _strdup(const char*);
extern "C" int stat(const char*, void*);
extern "C" void FUN_0076b190();
extern "C" int FUN_007669d0(...);
extern "C" int FUN_0071a4a0(...);

extern "C" uint32_t FUN_0071a9d0(void)
{
  char* in_EAX;
  char* pcVar1;
  int iVar2;
  int iVar3;
  uint32_t uVar4;
  int* unaff_EDI;
  uint8_t local_128[6];
  uint32_t local_122;
  uint8_t local_104[248];
  uint32_t uStack_c;

  pcVar1 = _strdup(in_EAX);
  unaff_EDI[10] = (int)pcVar1;
  FUN_0076b190();
  uVar4 = 3;
  if ((char)unaff_EDI[0x10] != '\0') {
    uVar4 = 1;
  }
  iVar2 = stat(reinterpret_cast<char*>(local_104), local_128);
  if ((iVar2 == 0) && ((local_122 >> 15 & 1) != 0)) {
    iVar2 = FUN_007669d0(local_104, uVar4, 0x10000000);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    iVar2 = FUN_007669d0(local_104, uVar4, 0x10000000);
  } else {
    iVar2 = FUN_007669d0(local_104, 6, 0x10000000);
  }
  if (iVar2 == 0) {
    iVar2 = (**(int(**)())(*unaff_EDI + 0x1c))();
    if (iVar2 == 0) {
      return 0;
    }
    if (((iVar2 != -1) &&
         (iVar3 = (**(int(**)())(*unaff_EDI + 4))(iVar2 + -4, 0), iVar3 == 0)) &&
        (iVar3 = (**(int(**)())(*unaff_EDI + 0x14))(&uStack_c /*approx*/, 4), iVar3 == 0)) {
      uVar4 = FUN_0071a4a0(unaff_EDI, uStack_c, iVar2);
      return uVar4;
    }
  }
  return 0xffffffff;
}
