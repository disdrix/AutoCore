// =============================================================================
// UI_DefaultMessageHandler
// -----------------------------------------------------------------------------
// Stable ID: aa_0087b500
// Address:   0x0087b500  (autoassault.exe, image base 0x400000)
// Body:      0x0087b500 – 0x0087b54f
// System:    UI dialog / window message base
// Generated: 2026-07-23 scaffold; 2026-07-29 dual A/B machine re-seal (W17-F)
// Exactness: Behavior-preserving rewrite of decompiler + machine control flow.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Default fallthrough for dialog message switches (~109 xrefs).
 * - __thiscall, 2 stack formals, ret 8.
 * - Swallows msg in [7, 15] → return 1.
 * - Else: this->vtbl+0xD8 predicate; if true and this+0x2B0 parent non-null,
 *   forward (msg, controlId) to parent->vtbl+0x338.
 * - else return 0.
 * - Name INFERRED (no product string on this body).
 */

// Predicate at this->vtbl + 0xD8 (returns char/bool).
// Parent message virtual at parent->vtbl + 0x338.

unsigned __thiscall UI_DefaultMessageHandler(void* pThis, int msg, unsigned controlId)
{
  char mayForward;
  void* parent;
  void** parentVtbl;
  unsigned result;

  /* Machine: cmp msg,7 / cmp msg,0x0F — inclusive range 7..15 */
  if ((msg > 6) && (msg < 0x10)) {
    return 1;
  }

  /* this->vtbl[0xD8/4](this) */
  mayForward = (*(char(__thiscall**)(void*))(*(unsigned*)pThis + 0xD8))(pThis);
  if (mayForward == 0) {
    return 0;
  }

  parent = *(void**)((unsigned char*)pThis + 0x2B0); /* decomp: ((int*)this)[0xAC] */
  if (parent == 0) {
    return 0;
  }

  parentVtbl = *(void***)parent;
  /* parent->vtbl[0x338/4](parent, msg, controlId) — thiscall via ECX=parent */
  result = (*(unsigned(__thiscall**)(void*, int, unsigned))((unsigned char*)parentVtbl + 0x338))(
      parent, msg, controlId);
  return result;
}
