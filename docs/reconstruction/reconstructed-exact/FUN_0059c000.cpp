// =============================================================================
// FUN_0059c000  (scaffold alias → CloneBase_AllocAndLoadByType)
// -----------------------------------------------------------------------------
// Stable ID: aa_0059c000
// Address:   0x0059c000–0x0059c443  (autoassault.exe, image base 0x400000)
// System:    gamedata / clonebase materialize
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W19-F)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Prefer clean plate: reconstructed-exact/CloneBase_AllocAndLoadByType.cpp
// This scaffold keeps the Ghidra FUN_* name for inventory tooling.

#include <cstdint>
#include <cstring>

extern "C" void* operator_new(uint32_t size);
extern int FUN_00540850(uint32_t cbid);
extern int FUN_007e59d0(void* a, void* b);
extern int FUN_0059c680();
extern int FUN_007edf30(void* a, void* b, void* c);
extern int FUN_0059c6c0();
extern int DB_ReadPowerPlantSpecific(void* db, char* base, void* specific);
extern int FUN_0059c660();
extern int FUN_007ee340(void* a, void* b, void* c);
extern int FUN_0059a1b0();
extern int VehicleDb_LoadCloneBase(void* a, void* b, void* c);
extern int FUN_0059c6e0();
extern int FUN_007ed3b0(void* a, void* b, void* c);
extern int FUN_0059b110();
extern int FUN_007eaf20(void* a, void* b, void* c);
extern int FUN_0059b620(int rec);
extern int FUN_0059c620();
extern int FUN_007ef3f0(void* a, void* b, void* c);
extern int FUN_0059c700();
extern int FUN_007ec7e0(void* a, void* b, void* c);
extern int FUN_0059c6a0();
extern int FUN_007edb20(void* a, void* b, void* c);
extern void FUN_00403450(void* dstNameSlot, void* wideSrc);
extern void* ExceptionList;
extern char DAT_00b04694;
extern void* DAT_00b0469c;
extern void* PTR_FUN_009d55fc;
extern void* (*PTR_FUN_00af8c9c)();
extern void free(void* p);
extern char* strncpy(char* d, const char* s, size_t n);
extern uint8_t LAB_009a5c7c;

int FUN_0059c000(int param_1)
{
  char cVar1;
  int iVar2;
  uint32_t* puVar3;
  uint32_t uVar4;
  char* pcVar5;
  void* pvVar6;
  char acStack_110[128];
  char* local_90;
  char local_8c[128];
  void* local_c;
  uint8_t* puStack_8;
  uint32_t local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a5c7c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (DAT_00b04694 != '\0') {
    ExceptionList = &local_c;
    iVar2 = FUN_00540850(*(uint32_t*)(param_1 + 0x34));
    *(int*)(param_1 + 0x3c) = iVar2;
    if ((DAT_00b04694 != '\0') && (iVar2 != 0))
      goto LAB_0059c0aa;
  }
  switch (*(uint32_t*)(param_1 + 0x38)) {
  case 1:
  case 3:
  case 4:
  case 6:
  case 0x16:
  case 0x1e:
  case 0x20:
  case 0x22:
  case 0x30:
  case 0x36:
  case 0x38:
  case 0x3a:
  case 0x3c:
  case 0x3e:
  case 0x42:
  case 0x48:
    puVar3 = (uint32_t*)operator_new(0x4c0);
    if (puVar3 == nullptr) {
      puVar3 = nullptr;
    } else {
      *puVar3 = (uint32_t)&PTR_FUN_009d55fc;
    }
    *(uint32_t**)(param_1 + 0x3c) = puVar3;
    puVar3[1] = *(uint32_t*)(param_1 + 0x34);
    iVar2 = FUN_007e59d0((void*)(*(int*)(param_1 + 0x3c) + 4),
                         (void*)(*(int*)(param_1 + 0x3c) + 0x3b8));
    break;
  default:
    ExceptionList = local_c;
    return (int)0x80004005;
  case 8:
    pvVar6 = operator_new(0x4c8);
    iVar2 = (pvVar6 == nullptr) ? 0 : FUN_0059c680();
    *(int*)(param_1 + 0x3c) = iVar2;
    *(uint32_t*)(iVar2 + 4) = *(uint32_t*)(param_1 + 0x34);
    iVar2 = *(int*)(param_1 + 0x3c);
    iVar2 = FUN_007edf30((void*)(iVar2 + 4), (void*)(iVar2 + 0x3b8), (void*)(iVar2 + 0x4c0));
    break;
  case 10:
    pvVar6 = operator_new(0x4cc);
    iVar2 = (pvVar6 == nullptr) ? 0 : FUN_0059c6c0();
    *(int*)(param_1 + 0x3c) = iVar2;
    *(uint32_t*)(iVar2 + 4) = *(uint32_t*)(param_1 + 0x34);
    iVar2 = DB_ReadPowerPlantSpecific(
        DAT_00b0469c, (char*)(*(int*)(param_1 + 0x3c) + 4),
        (void*)(*(int*)(param_1 + 0x3c) + 0x3b8));
    break;
  case 0xc:
  case 0x18:
    pvVar6 = operator_new(0x544);
    iVar2 = (pvVar6 == nullptr) ? 0 : FUN_0059c660();
    *(int*)(param_1 + 0x3c) = iVar2;
    *(uint32_t*)(iVar2 + 4) = *(uint32_t*)(param_1 + 0x34);
    iVar2 = *(int*)(param_1 + 0x3c);
    iVar2 = FUN_007ee340((void*)(iVar2 + 4), (void*)(iVar2 + 0x3b8), (void*)(iVar2 + 0x4c0));
    break;
  case 0xe:
    pvVar6 = operator_new(0x744);
    iVar2 = (pvVar6 == nullptr) ? 0 : FUN_0059a1b0();
    *(int*)(param_1 + 0x3c) = iVar2;
    *(uint32_t*)(iVar2 + 4) = *(uint32_t*)(param_1 + 0x34);
    iVar2 = *(int*)(param_1 + 0x3c);
    iVar2 = VehicleDb_LoadCloneBase((void*)(iVar2 + 4), (void*)(iVar2 + 0x3b8),
                                    (void*)(iVar2 + 0x4c0));
    break;
  case 0x10:
    pvVar6 = operator_new(0x5d4);
    iVar2 = (pvVar6 == nullptr) ? 0 : FUN_0059c6e0();
    *(int*)(param_1 + 0x3c) = iVar2;
    *(uint32_t*)(iVar2 + 4) = *(uint32_t*)(param_1 + 0x34);
    iVar2 = *(int*)(param_1 + 0x3c);
    iVar2 = FUN_007ed3b0((void*)(iVar2 + 4), (void*)(iVar2 + 0x3b8), (void*)(iVar2 + 0x4c0));
    break;
  case 0x12:
    pvVar6 = operator_new(0x528);
    local_4 = 0;
    iVar2 = (pvVar6 == nullptr) ? 0 : FUN_0059b110();
    *(int*)(param_1 + 0x3c) = iVar2;
    *(uint32_t*)(iVar2 + 4) = *(uint32_t*)(param_1 + 0x34);
    iVar2 = *(int*)(param_1 + 0x3c);
    local_4 = 0xffffffff;
    iVar2 = FUN_007eaf20((void*)(iVar2 + 4), (void*)(iVar2 + 0x3b8), (void*)(iVar2 + 0x4c0));
    break;
  case 0x14:
    iVar2 = FUN_0059b620(param_1);
    break;
  case 0x1a:
    pvVar6 = operator_new(0x4e8);
    iVar2 = (pvVar6 == nullptr) ? 0 : FUN_0059c620();
    *(int*)(param_1 + 0x3c) = iVar2;
    *(uint32_t*)(iVar2 + 4) = *(uint32_t*)(param_1 + 0x34);
    iVar2 = *(int*)(param_1 + 0x3c);
    iVar2 = FUN_007ef3f0((void*)(iVar2 + 4), (void*)(iVar2 + 0x3b8), (void*)(iVar2 + 0x4c0));
    break;
  case 0x1c:
    pvVar6 = operator_new(0x4d4);
    iVar2 = (pvVar6 == nullptr) ? 0 : FUN_0059c700();
    *(int*)(param_1 + 0x3c) = iVar2;
    *(uint32_t*)(iVar2 + 4) = *(uint32_t*)(param_1 + 0x34);
    iVar2 = *(int*)(param_1 + 0x3c);
    iVar2 = FUN_007ec7e0((void*)(iVar2 + 4), (void*)(iVar2 + 0x3b8), (void*)(iVar2 + 0x4c0));
    break;
  case 0x32:
    pvVar6 = operator_new(0x4c8);
    iVar2 = (pvVar6 == nullptr) ? 0 : FUN_0059c6a0();
    *(int*)(param_1 + 0x3c) = iVar2;
    *(uint32_t*)(iVar2 + 4) = *(uint32_t*)(param_1 + 0x34);
    iVar2 = *(int*)(param_1 + 0x3c);
    iVar2 = FUN_007edb20((void*)(iVar2 + 4), (void*)(iVar2 + 0x3b8), (void*)(iVar2 + 0x4c0));
  }
  if (iVar2 != 0) {
    ExceptionList = local_c;
    return iVar2;
  }
LAB_0059c0aa:
  iVar2 = *(int*)(param_1 + 0x3c);
  local_90 = local_8c;
  uVar4 = (uint32_t)PTR_FUN_00af8c9c();
  FUN_00403450((void*)(iVar2 + 0x10), (void*)uVar4);
  pcVar5 = local_90;
  do {
    cVar1 = *pcVar5;
    pcVar5[(param_1 + 0x40) - (int)local_90] = cVar1;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (local_90 != local_8c) {
    free(local_90);
  }
  iVar2 = *(int*)(param_1 + 0x3c);
  uVar4 = (uint32_t)PTR_FUN_00af8c9c();
  FUN_00403450((void*)(iVar2 + 0x10), (void*)uVar4);
  strncpy((char*)(param_1 + 0x188), acStack_110, 0x41);
  ExceptionList = local_c;
  return 0;
}
