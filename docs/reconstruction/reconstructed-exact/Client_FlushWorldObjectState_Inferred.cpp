// =============================================================================
// Client_FlushWorldObjectState_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00943b80
// Address:   0x00943b80–0x00943dae  (autoassault.exe, image base 0x400000)
// System:    client-session / world-object containers
// Generated: 2026-07-23 scaffold as FUN_00943b80; **sealed 2026-07-29** W23-E dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-07-29)
// =============================================================================

/*
 * Behavioral notes (2026-07-29 seal):
 * - Client world/container flush used on gameplay teardown (flag=0), sector net
 *   reconnect, and one hard path with flag=1 (FUN_009466f0).
 * - ABI: this in EDI (not ECX); stack char flag; RET 4.
 * - Clears host interaction flag via e04→e894→+0x8c; optional EquipGfxHost clear
 *   (FUN_004962b0); drains object container at +0xd28 with vtbl+4(1) releases;
 *   two-pass FUN_004bae00 + ObjectList_ExportTfidsToMap (FUN_00933370).
 * - flag!=0 enables UI vtbl +0x2a8/+0x2a4 and insert into list at +0xf00.
 * - Nested callee product names largely open (not owned).
 */

#include <cstdint>

using code = void;

extern "C" void FUN_004962b0(void);
extern "C" void FUN_0093e120(int);
extern "C" void FUN_00997120(int);
extern "C" void FUN_0051f400(void);
extern "C" void FUN_00415e90(void);
extern "C" int FUN_00418700(int, int, void *);
extern "C" void FUN_00418790(void);
extern "C" void FUN_009306d0(void);
extern "C" void FUN_008026a0(void);
extern "C" void FUN_004040a0(void);
extern "C" void FUN_004bfcb0(void);
extern "C" int FUN_004bae00(std::uint32_t, void *);
extern "C" void FUN_00933370(int);
extern "C" void FUN_004bbeb0(void);
extern "C" void FUN_0092f3b0(void);
extern "C" void FUN_00406b80(std::uint32_t);
extern "C" void operator_delete(void *);

// Image ABI: this in EDI, one stack char, RET 4.
// Clean presents (self, flag) for readability; call order ≡ decompile.
extern "C" void Client_FlushWorldObjectState_Inferred(void *self, char flag)
{
  void *pvVar1;
  std::uint32_t uVar2;
  int iVar3;
  int iVar4;
  int client = reinterpret_cast<int>(self);
  bool bVar5;
  std::uint32_t uStack_8;
  std::uint32_t uStack_4;

  *(std::uint8_t *)(*(int *)(*(int *)(client + 0xe04) + 0xe894) + 0x8c) = 0;
  if ((*(int *)(client + 0xe04) != 0) &&
      (*(int *)(*(int *)(client + 0xe04) + 0xe898) != 0)) {
    FUN_004962b0();
  }
  FUN_0093e120(0);
  FUN_00997120(client);

  if (flag != '\0') {
    // vtbl slot +0x2a8 on nested object at client+0xe98
    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(client + 0xe98) + 4) + 4) + 4 +
                         *(int *)(client + 0xe98)) +
                 0x2a8))(*(std::uint32_t *)(client + 0xd34));
    FUN_0051f400();
  }

  FUN_00415e90();
  FUN_00415e90();

  if (flag != '\0') {
    iVar4 = *(int *)(client + 0xf00);
    uStack_8 = *(std::uint32_t *)(*(int *)(client + 0xe98) + 0x250);
    iVar3 = FUN_00418700(iVar4, *(int *)(iVar4 + 4), &uStack_8);
    FUN_00418790();
    *(int *)(iVar4 + 4) = iVar3;
    **(int **)(iVar3 + 4) = iVar3;
  }

  FUN_009306d0();
  FUN_008026a0();
  *(std::uint32_t *)(client + 0xe08) = 0;

  if ((*(int *)(client + 0xf38) != 0) && (flag == '\0')) {
    *(std::uint32_t *)(*(int *)(client + 0xf38) + 0xc70) = 0;
  }

  uStack_8 = **(std::uint32_t **)(client + 0xd28);
  if ((int *)uStack_8 != *(int **)(client + 0xd28)) {
    do {
      if (*(int **)(uStack_8 + 0x20) != (int *)0x0) {
        (**(code **)(**(int **)(uStack_8 + 0x20) + 4))(1);
      }
      FUN_004040a0();
    } while (uStack_8 != *(std::uint32_t *)(client + 0xd28));
  }

  pvVar1 = *(void **)(*(int *)(client + 0xd28) + 4);
  if (*(char *)(reinterpret_cast<int>(pvVar1) + 0x29) != '\0') {
    *(int *)(*(int *)(client + 0xd28) + 4) = *(int *)(client + 0xd28);
    *(std::uint32_t *)(client + 0xd2c) = 0;
    *(std::uint32_t *)*(std::uint32_t *)(client + 0xd28) =
        *(std::uint32_t *)(client + 0xd28);
    *(int *)(*(int *)(client + 0xd28) + 8) = *(int *)(client + 0xd28);
    if (*(int *)(client + 0xe04) != 0) {
      FUN_004bfcb0();
    }
    bVar5 = false;
    uStack_8 = uStack_8 & 0xffffff00;
    iVar4 = 2;
    do {
      uVar2 = uStack_8;
      uStack_4 = 0;
      iVar3 = FUN_004bae00(uStack_8, &uStack_4);
      while (iVar3 != 0) {
        FUN_00933370(client);
        iVar3 = FUN_004bae00(uVar2, &uStack_4);
      }
      bVar5 = (bVar5 == false);
      iVar4 = iVar4 + -1;
      uVar2 = uStack_8 >> 8;
      uStack_8 = (uVar2 << 8) | (bVar5 ? 1u : 0u);
    } while (iVar4 != 0);
    FUN_004bbeb0();
    FUN_0092f3b0();
    if (flag != '\0') {
      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(client + 0xe98) + 4) + 4) + 4 +
                           *(int *)(client + 0xe98)) +
                   0x2a4))(*(std::uint32_t *)(client + 0xd34));
    }
    return;
  }

  FUN_00406b80(*(std::uint32_t *)(reinterpret_cast<int>(pvVar1) + 8));
  // WARNING: retail may free remaining nodes; decompiler marks delete noreturn
  operator_delete(pvVar1);
}
