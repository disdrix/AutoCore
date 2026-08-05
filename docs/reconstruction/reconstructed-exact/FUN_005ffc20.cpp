// =============================================================================
// CVOGHBToken_OnEnd
// -----------------------------------------------------------------------------
// Stable ID: aa_005ffc20
// Address:   0x005ffc20  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_005ffc20
// System:    heartbeat / CVOGHBToken
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W17-K)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes (dual A/B sealed 2026-07-29):
 * - RTTI Confirmed: .?AVCVOGHBToken@@ (type_info 0x00af4660).
 * - Virtual OnEnd at vtbl+0x14 (DATA 0x009dde40); no direct CALL sites.
 * - If this+0x18 related non-null: vcall related+0x1d4 → host.
 * - If host non-null AND this+0x10 < 1: resolve character via MI + vtbl+0x210(0),
 *   then Character_SetFlagByte_plus529_WithNetDirty(character, 1) (FUN_005208e0).
 * - Always tails to empty FUN_005081f0 (shared nop vfunc).
 * - Stack framing: push 1; push 0; vcall 0x210; same pattern as VehicleNet unpack.
 *   Decompiler may display vcall(0,1); end effect is flag=1 (High).
 *
 * Readability pass:
 * - Control flow and call order preserved from authoritative raw.
 */

#include <stdint.h>

struct CVOGHBToken;
void Character_SetFlagByte_plus529_WithNetDirty(void *character, char value); /* FUN_005208e0 */
void FUN_005081f0(void); /* empty ret */

void __thiscall CVOGHBToken_OnEnd(CVOGHBToken *self)
{
  int *related;
  int host;
  void *character;

  related = *(int **)((char *)self + 0x18);
  if (related != 0) {
    host = (**(int (**)(void))(*related + 0x1d4))();
    if ((host != 0) && (*(int *)((char *)self + 0x10) < 1)) {
      /* MI adjust: lea ecx, [host + *( *(host+4)+4 ) + 4]; vcall +0x210 with arg 0.
         Flag value 1 is framed on the stack for FUN_005208e0 (see raw machine seal). */
      character =
          (void *)(**(int (**)(int))(
                       *(int *)(*(int *)(*(int *)(host + 4) + 4) + 4 + host) + 0x210))(0);
      Character_SetFlagByte_plus529_WithNetDirty(character, 1);
    }
  }
  FUN_005081f0();
  return;
}

/* Ghidra name retained for xref continuity. */
void __fastcall FUN_005ffc20(int param_1)
{
  CVOGHBToken_OnEnd((CVOGHBToken *)param_1);
}
