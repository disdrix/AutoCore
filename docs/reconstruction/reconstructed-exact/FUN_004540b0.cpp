// =============================================================================
// FUN_004540b0  (alias scaffold → StdVector_ThrowTooLong)
// -----------------------------------------------------------------------------
// Stable ID: aa_004540b0
// Address:   0x004540b0  (autoassault.exe, image base 0x400000)
// Canonical: StdVector_ThrowTooLong
// Dual A/B:  accept (2026-07-29 W19-B)
// Named clean: reconstructed-exact/StdVector_ThrowTooLong.cpp (authoritative)
// =============================================================================

/* Scaffold alias — keep FUN_* name for coverage index; prefer named clean. */

#include <stdint.h>
#include <string>

struct ThrowInfo;
extern "C" void __stdcall _CxxThrowException(void *exception_object,
                                             ThrowInfo *throw_info);
extern void *__thiscall ExceptionFromString_00401a40(void *exception_this,
                                                     void *message_string);

void FUN_004540b0(void)
{
  std::string local_50;
  uint8_t local_34[40];
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;

  local_4 = 0xffffffffu;
  puStack_8 = (uint8_t *)0x009bc919; /* LAB_009bc919 */
  pvStack_c = 0; /* ExceptionList / FS:[0] — runtime SEH link */
  (void)pvStack_c;
  (void)puStack_8;

  local_50 = "vector<T> too long";
  local_4 = 0;
  ExceptionFromString_00401a40(local_34, &local_50);
  /* WARNING: Subroutine does not return */
  _CxxThrowException(local_34, (ThrowInfo *)0x00acc388);
}
