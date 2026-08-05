// =============================================================================
// FUN_00439810  (alias scaffold → stoChunkWriter_WriteU32)
// -----------------------------------------------------------------------------
// Stable ID: aa_00439810
// Address:   0x00439810  (autoassault.exe, image base 0x400000)
// Body:      0x00439810–0x00439861
// System:    storage / arda2.stoChunk
// Generated: 2026-07-23 scaffold; refined 2026-07-29 W20-D dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Canonical named plate: stoChunkWriter_WriteU32.cpp
// =============================================================================

/*
 * Behavioral notes (dual A/B sealed 2026-07-29 W20-D):
 * - Write one unsigned int32 through stoChunkWriter.
 * - Binary (writer+0x1c == 0): stream vtbl+0x18 write 4 raw bytes.
 * - Text: WriteFormatted("%u", value) then textCol=0 then "\r\n".
 * - ABI: ESI = writer*, EAX = const uint32_t*.
 * - DAT_00a9d718 = "%u"; DAT_00a97b84 = "\r\n".
 * - Sibling 0x00439870 = WriteI32 with "%i".
 * - Runtime / differential verification: OPEN.
 */

#include <stdint.h>

extern char DAT_00a9d718[];  /* "%u" */
extern char DAT_00a97b84[];  /* "\r\n" */

extern uint32_t FUN_00767160(char *format, ...);  /* stoChunkWriter_WriteFormatted */

uint32_t FUN_00439810(void)
{
  uint32_t *in_EAX;
  uint32_t uVar1;
  uint32_t *unaff_ESI;
  uint32_t local_4;

  local_4 = *in_EAX;
  if (unaff_ESI[7] == 0) {
    uVar1 = (**(uint32_t (**)(void *, uint32_t))(*(int *)*unaff_ESI + 0x18))(&local_4, 4);
    unaff_ESI[1] = unaff_ESI[1] | uVar1;
    return unaff_ESI[1];
  }
  uVar1 = FUN_00767160(&DAT_00a9d718[0], local_4);
  unaff_ESI[1] = unaff_ESI[1] | uVar1;
  unaff_ESI[8] = 0;
  uVar1 = (**(uint32_t (**)(void *, uint32_t))(*(int *)*unaff_ESI + 0x18))(&DAT_00a97b84[0], 2);
  unaff_ESI[1] = unaff_ESI[1] | uVar1;
  return unaff_ESI[1];
}
