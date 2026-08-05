// =============================================================================
// FUN_00748960  (clean twin of MeshHost0xC4_BaseCtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00748960
// Address:   0x00748960  (autoassault.exe, image base 0x400000)
// Body:      0x00748960–0x00748aaf (336 B)
// System:    mesh / host graphics (0xC4 shell)
// Generated: 2026-07-29 W36-H dual seal
// Exactness: Behavior-preserving; ECX this; returns self.
// Named twin: MeshHost0xC4_BaseCtor_Inferred.cpp
// =============================================================================

/*
 * ECX = preallocated 0xC4 mesh-host shell.
 * See named twin for full field map and helpers.
 */

#include <stdint.h>

extern void *ExceptionList;
extern void *LAB_009ad90d;
extern void *PTR_FUN_00a9db64;
extern void *PTR_LAB_00a9db0c;
extern void *PTR_LAB_00a9db58;
extern void *PTR_FUN_00a9da80;
extern uint32_t DAT_00aaa630;
extern uint32_t DAT_00aaa63c;

extern void __stdcall eh_vector_constructor_iterator_(
    void *array, uint32_t size, uint32_t count,
    void (__fastcall *ctor)(void *), void (__fastcall *dtor)(void *));
extern void __fastcall FUN_00437440(void *elem);
extern void __fastcall FUN_00437450(void *elem);
extern int FUN_00437680(void *sub);

uint32_t *__fastcall FUN_00748960(uint32_t *param_1 /* ECX */)
{
  void *local_c;
  void *puStack_8;

  puStack_8 = &LAB_009ad90d;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  param_1[1] = (uint32_t)&PTR_LAB_00a9db0c;
  param_1[0] = (uint32_t)&PTR_FUN_00a9db64;
  param_1[1] = (uint32_t)&PTR_LAB_00a9db58;
  param_1[3] = 0;
  param_1[2] = (uint32_t)&PTR_FUN_00a9da80;

  eh_vector_constructor_iterator_(param_1 + 4, 8, 2, FUN_00437440, FUN_00437450);

  param_1[8] = 0;
  *(uint8_t *)(param_1 + 9) = 0;
  *((uint8_t *)param_1 + 0x25) = 0;
  *((uint8_t *)param_1 + 0x26) = 0;

  param_1[10] = 0;
  param_1[11] = 0;
  param_1[12] = 0;
  param_1[13] = 0;
  param_1[14] = 0;
  param_1[15] = DAT_00aaa630;
  param_1[16] = DAT_00aaa630;
  param_1[17] = DAT_00aaa630;
  param_1[18] = DAT_00aaa63c;
  param_1[19] = DAT_00aaa63c;
  param_1[20] = DAT_00aaa63c;

  *(uint8_t *)(param_1 + 0x15) = 1;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0xFFFFFFFFu;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;

  FUN_00437680(param_1 + 0x1e);

  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2b] = 0xFFFFFFFFu;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  *(uint8_t *)(param_1 + 0x2f) =
      (uint8_t)(*(uint8_t *)(param_1 + 0x2f) | 0x81);

  ExceptionList = local_c;
  return param_1;
}
