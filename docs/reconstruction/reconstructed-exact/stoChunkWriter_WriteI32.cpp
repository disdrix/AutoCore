// =============================================================================
// stoChunkWriter_WriteI32
// -----------------------------------------------------------------------------
// Stable ID: aa_00439870
// Address:   0x00439870  (autoassault.exe, image base 0x400000)
// System:    storage / arda2.stoChunk
// Generated: 2026-07-23 scaffold; refined 2026-07-29 W19-Q dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes (dual A/B sealed 2026-07-29):
 * - Write one signed int32 through stoChunkWriter.
 * - Binary (writer+0x1c == 0): stream vtbl+0x18 write 4 raw bytes.
 * - Text: stoChunkWriter_WriteFormatted("%i", value) then textCol=0 then "\r\n".
 * - ABI: ESI = writer*, EAX = const int32_t* (decompiler in_EAX / unaff_ESI).
 * - DAT_00a37c64 = "%i"; DAT_00a97b84 = "\r\n".
 * - Sibling 0x00439810 = WriteU32 with "%u".
 * - Runtime / differential verification: OPEN.
 *
 * Readability:
 * - CF preserved from live Ghidra; undefined4 → uint32_t.
 * - Register ABI documented; not rewritten as formal C parameters (call convention
 *   is register-based, matching retail call sites).
 */

#include <stdint.h>

extern char DAT_00a37c64[];  /* "%i" */
extern char DAT_00a97b84[];  /* "\r\n" */

/* Dual-sealed: writer in EAX, format at [esp+4], varargs follow */
extern uint32_t FUN_00767160(char *format, ...);  /* stoChunkWriter_WriteFormatted */

uint32_t stoChunkWriter_WriteI32(void)
{
  uint32_t *in_EAX;      /* const int32_t* value pointer on entry */
  uint32_t uVar1;
  uint32_t *unaff_ESI;   /* stoChunkWriter* on entry */
  uint32_t local_4;

  local_4 = *in_EAX;
  if (unaff_ESI[7] == 0) {
    uVar1 = (**(uint32_t (**)(void *, uint32_t))(*(int *)*unaff_ESI + 0x18))(&local_4, 4);
    unaff_ESI[1] = unaff_ESI[1] | uVar1;
    return unaff_ESI[1];
  }
  uVar1 = FUN_00767160(&DAT_00a37c64[0], local_4);
  unaff_ESI[1] = unaff_ESI[1] | uVar1;
  unaff_ESI[8] = 0;
  uVar1 = (**(uint32_t (**)(void *, uint32_t))(*(int *)*unaff_ESI + 0x18))(&DAT_00a97b84[0], 2);
  unaff_ESI[1] = unaff_ESI[1] | uVar1;
  return unaff_ESI[1];
}
