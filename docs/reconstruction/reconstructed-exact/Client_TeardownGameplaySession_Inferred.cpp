// =============================================================================
// Client_TeardownGameplaySession_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00944b20
// Address:   0x00944b20–0x00944d03  (autoassault.exe, image base 0x400000)
// System:    client-session / login / return-to-login
// Generated: 2026-07-23 scaffold as FUN_00944b20; **sealed 2026-07-29** dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-07-29)
// =============================================================================

/*
 * Behavioral notes (2026-07-29 seal):
 * - Session / gameplay teardown used on login fail, account kick, auth return-
 *   to-login, and missing-map-content abort.
 * - ABI: this in EAX (not ECX); stack char fullTeardown; RET 4.
 * - Call sites: MOV EAX, 0x00d1a840 (global client); PUSH 1 (full) typical.
 * - fullTeardown!=0: release five UI COM slots (vtbl+4 arg 0), audio/mission
 *   helpers, zero 0x82-dword buffer at +0x31f0 (then *buf=-1).
 * - Always: delete[] +0xf44, clear +0x113/+0x134, FUN_008076c0, conditional
 *   leave paths for +0xf40 match and DAT_00d1b77c session.
 */

#include <cstdint>

using code = void;

extern "C" void FUN_007fc970(void);
extern "C" void FUN_007fc360(void);
extern "C" void Client_GetMissionCompleteAudioTable(void);
extern "C" void FUN_007246d0(void);
extern "C" void FUN_005742a0(void);
extern "C" void FUN_00943db0(void);
extern "C" void FUN_0079e7d0(std::uint32_t);
extern "C" void FUN_00943b80(int);
extern "C" void FUN_00442fa0(int, int, int, int, int);
extern "C" void FUN_00410420(int, int);
extern "C" void operator_delete[](void *);
extern "C" void FUN_008076c0(void);
extern "C" void FUN_00801c50(void *self);
extern "C" void FUN_009302b0(void);
extern "C" void FUN_00937560(void *self);
extern "C" void FUN_0048f370(void);
extern "C" void FUN_009133a0(int);

extern "C" int DAT_00d1b77c;

// Image ABI: this in EAX, one stack char, RET 4.
// Clean presents (self, flag) for readability; call order ≡ decompile.
extern "C" void Client_TeardownGameplaySession_Inferred(void *self, char fullTeardown)
{
  int iVar1;
  std::uint32_t *puVar2;
  int in_EAX = reinterpret_cast<int>(self);

  if (fullTeardown != '\0') {
    *(std::uint8_t *)(in_EAX + 0x30b4) = 1;
    *(std::uint8_t *)(in_EAX + 0x30b5) = 0;
    if (*(int **)(in_EAX + 0x309c) != (int *)0x0) {
      (**(code **)(**(int **)(in_EAX + 0x309c) + 4))(0);
    }
    FUN_007fc970();
    *(std::uint8_t *)(in_EAX + 0x30ba) = 1;
    *(std::uint8_t *)(in_EAX + 0x30bb) = 0;
    if (*(int **)(in_EAX + 0x30a8) != (int *)0x0) {
      (**(code **)(**(int **)(in_EAX + 0x30a8) + 4))(0);
    }
    *(std::uint8_t *)(in_EAX + 0x30b8) = 1;
    *(std::uint8_t *)(in_EAX + 0x30b9) = 0;
    if (*(int **)(in_EAX + 0x30a4) != (int *)0x0) {
      (**(code **)(**(int **)(in_EAX + 0x30a4) + 4))(0);
    }
    *(std::uint8_t *)(in_EAX + 0x30bc) = 1;
    *(std::uint8_t *)(in_EAX + 0x30bd) = 0;
    if (*(int **)(in_EAX + 0x30ac) != (int *)0x0) {
      (**(code **)(**(int **)(in_EAX + 0x30ac) + 4))(0);
    }
    *(std::uint8_t *)(in_EAX + 0x30be) = 1;
    *(std::uint8_t *)(in_EAX + 0x30bf) = 0;
    if (*(int **)(in_EAX + 0x30b0) != (int *)0x0) {
      (**(code **)(**(int **)(in_EAX + 0x30b0) + 4))(0);
    }
    FUN_007fc360();
    Client_GetMissionCompleteAudioTable();
    FUN_007246d0();
    if (*(int *)(in_EAX + 0x31ec) != 0) {
      FUN_005742a0();
    }
    if (*(std::uint32_t **)(in_EAX + 0x31f0) != (std::uint32_t *)0x0) {
      puVar2 = *(std::uint32_t **)(in_EAX + 0x31f0);
      for (iVar1 = 0x82; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
      **(std::uint32_t **)(in_EAX + 0x31f0) = 0xffffffffu;
    }
    FUN_00943db0();
    FUN_0079e7d0(*(std::uint32_t *)(in_EAX + 0xde8));
    FUN_00943b80(0);
    FUN_00442fa0(0, 0, 0, 0, 0);
    FUN_00410420(0, 0);
  }
  if (*(void **)(in_EAX + 0xf44) != (void *)0x0) {
    operator_delete[](*(void **)(in_EAX + 0xf44));
  }
  *(std::uint32_t *)(in_EAX + 0xf44) = 0;
  FUN_008076c0();
  *(std::uint8_t *)(in_EAX + 0x113) = 0;
  *(std::uint32_t *)(in_EAX + 0x134) = 0;
  if (fullTeardown != '\0') {
    FUN_00801c50(reinterpret_cast<void *>(in_EAX));
  }
  if ((*(int **)(in_EAX + 0xf40) != (int *)0x0) &&
      (**(int **)(in_EAX + 0xf40) == *(int *)(in_EAX + 0xf38))) {
    if (fullTeardown != '\0') {
      FUN_009302b0();
    }
    FUN_00937560(reinterpret_cast<void *>(in_EAX));
  }
  if (DAT_00d1b77c != 0) {
    if (fullTeardown != '\0') {
      FUN_0048f370();
    }
    FUN_009133a0(0);
  }
}
