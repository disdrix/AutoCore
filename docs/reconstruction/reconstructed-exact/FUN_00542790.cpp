// =============================================================================
// FUN_00542790  (scaffold alias → FxCache_ApplyWithNfxEnsure)
// -----------------------------------------------------------------------------
// Stable ID: aa_00542790
// Address:   0x00542790  (autoassault.exe, image base 0x400000)
// System:    client-fx / skills-abilities
// Generated: 2026-07-29 W20-I dual A/B (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Prefer clean: reconstructed-exact/FxCache_ApplyWithNfxEnsure.cpp
// Ghidra name retained for xref continuity.
// =============================================================================

#include <cstdint>
#include <cstring>

extern "C" void* ExceptionList;
extern "C" uint8_t* DAT_00d1f050;
extern "C" uint32_t DAT_009d00a8;
extern "C" uint32_t DAT_009ca184;
extern "C" uint32_t DAT_009ca188;
extern "C" uint8_t DAT_009ca18c;
extern "C" void LAB_009a40df(void);

extern "C" void* CNDHash_LookupByKey(void* hash, uint32_t key);
extern "C" uint32_t FUN_0054b480(void);
extern "C" void FUN_00418890(void* a, void* b);
extern "C" void FUN_00540090(int src, int dst, uint32_t cap);
extern "C" void FUN_00989e00(void* a, int path);
extern "C" void FUN_0043d670(void* a);
extern "C" char FUN_004ed310(void* a, void* b, void* c);
extern "C" void FUN_004a6390(int baseName);
extern "C" void FUN_00971820(void* a);
extern "C" void FUN_0043d650(int a);
extern "C" void FUN_004a04f0(void* a, int b, int c, int d);
extern "C" int FUN_004a16d0(uint32_t a, int b, int c);
extern "C" void FUN_00545d70(void* a);
extern "C" void FUN_005b2ba0(void);

// Decompiler-shaped body (authoritative CF from raw aa_00542790).
uint32_t __thiscall FUN_00542790(
    int param_1,
    uint32_t param_2,
    uint32_t param_3,
    uint32_t param_4,
    uint32_t param_5,
    int param_6,
    int* param_7,
    uint32_t param_8)
{
  int* piVar1;
  char cVar2;
  uint32_t* puVar3;
  int* piVar4;
  void* pvVar5;
  int iVar6;
  char* pcVar7;
  uint32_t* puVar8;
  int local_46c;
  int local_468;
  uint32_t local_464;
  uint32_t local_460;
  uint32_t local_45c;
  uint32_t local_458;
  int local_454;
  int local_450;
  int local_44c;
  int local_448;
  uint32_t local_444;
  uint32_t local_440;
  uint32_t local_43c;
  uint32_t local_438;
  uint32_t local_434;
  uint32_t local_430;
  uint8_t local_42c[4];
  uint8_t local_428[4];
  uint32_t local_424;
  uint32_t local_420;
  uint32_t local_41c;
  uint32_t local_418;
  uint8_t local_414;
  uint32_t uStack_40d;
  uint8_t local_404[1016];
  void* local_c;
  uint8_t* puStack_8;
  uint32_t local_4;

  piVar1 = param_7;
  puStack_8 = reinterpret_cast<uint8_t*>(&LAB_009a40df);
  local_c = ExceptionList;
  if (*(int*)(DAT_00d1f050 + 0x6c) == 0) {
    return 0;
  }
  local_424 = 0;
  local_420 = 0;
  local_41c = 0;
  local_418 = 0;
  local_43c = param_4;
  local_444 = param_3;
  local_438 = param_5;
  local_4 = 0;
  local_414 = 0;
  local_42c[0] = 0;
  local_430 = 0;
  local_440 = param_2;
  if (param_6 == 0) {
    puVar3 = &DAT_009d00a8;
  } else {
    puVar3 = reinterpret_cast<uint32_t*>(param_6 + 0x160);
  }
  local_464 = *puVar3;
  local_460 = puVar3[1];
  local_45c = puVar3[2];
  local_458 = puVar3[3];
  piVar4 = param_7 + 0x58;
  if (param_7 == nullptr) {
    piVar4 = reinterpret_cast<int*>(&DAT_009d00a8);
  }
  local_454 = *piVar4;
  local_450 = piVar4[1];
  local_44c = piVar4[2];
  local_448 = piVar4[3];
  local_434 = param_8;
  ExceptionList = &local_c;
  local_468 = param_1;
  pvVar5 = CNDHash_LookupByKey(*reinterpret_cast<void**>(param_1 + 0xf0c), param_2);
  if (pvVar5 == nullptr) goto LAB_00542a35;
  if (*(char*)(reinterpret_cast<int>(pvVar5) + 10) == '\0') {
    puVar3 = &param_2;
    piVar4 = &local_46c;
    FUN_0054b480();
    FUN_00418890(piVar4, puVar3);
    iVar6 = (int)FUN_0054b480();
    if (local_46c == *(int*)(iVar6 + 4)) goto LAB_00542a35;
    FUN_00540090(local_46c + 0x10, reinterpret_cast<int>(&uStack_40d) + 1, 0x400);
    puVar3 = &uStack_40d;
    do {
      puVar8 = puVar3;
      puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<int>(puVar8) + 1);
    } while (*(char*)(reinterpret_cast<int>(puVar8) + 1) != '\0');
    *(uint32_t*)(reinterpret_cast<int>(puVar8) + 1) = DAT_009ca184;
    *(uint32_t*)(reinterpret_cast<int>(puVar8) + 5) = DAT_009ca188;
    *(uint8_t*)(reinterpret_cast<int>(puVar8) + 9) = DAT_009ca18c;
    FUN_00989e00(&local_46c, reinterpret_cast<int>(&uStack_40d) + 1);
    FUN_0043d670(&local_46c);
    cVar2 = FUN_004ed310(local_428, local_42c, &local_430);
    if (cVar2 != '\0') {
      pcVar7 = std::strstr(reinterpret_cast<char*>(reinterpret_cast<int>(&uStack_40d) + 1),
                           "_nfx.xml");
      if (pcVar7 != nullptr) {
        *pcVar7 = '\0';
        FUN_004a6390(reinterpret_cast<int>(&uStack_40d) + 1);
      }
      goto LAB_005429aa;
    }
    FUN_00971820(local_428);
    local_414 = 1;
  } else {
  LAB_005429aa:
    FUN_0043d650(0);
    local_42c[0] = 0;
    local_430 = 0;
    FUN_004a04f0(local_428, 1, 1, 1);
    cVar2 = FUN_004ed310(local_428, local_42c, &local_430);
    if (cVar2 != '\0') {
      iVar6 = FUN_004a16d0(local_444, 1, 0xffffffff);
      if ((iVar6 == 0) || (piVar1 == nullptr)) {
      LAB_00542a35:
        FUN_005b2ba0();
        ExceptionList = local_c;
        return 0;
      }
      (**(void(__thiscall***)(int*, uint32_t, uint32_t, uint32_t, uint32_t, int, uint32_t, int,
                              int))(*piVar1 + 0x238))(
          piVar1, local_444, local_440, local_43c, local_438, param_6, local_434, 1, iVar6);
      goto LAB_00542a68;
    }
    FUN_00971820(local_428);
  }
  FUN_00545d70(&local_464);
LAB_00542a68:
  FUN_005b2ba0();
  ExceptionList = local_c;
  return 1;
}
