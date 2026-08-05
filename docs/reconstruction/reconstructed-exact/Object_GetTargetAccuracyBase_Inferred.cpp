// =============================================================================
// Object_GetTargetAccuracyBase_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Capped accuracy-base integer for combat / TargetAccuracy display:
//             score = min( min(*(i16*)(this+0x13e), 200)
//                          + *(i16*)(this+0x146), 250 )
//             thr   = (MI_vtbl_call(this, +0x1DC) != 0) ? 1 : -100
//             return max(score, thr)
//
// Address:  0x004c4070  (autoassault.exe, image base 0x400000)
// Body:     0x004c4070–0x004c413d
// Stable:   aa_004c4070
// System:   combat / accuracy stats
//
// Does NOT: apply level band used by Client_DebugDumpEntityCombatStats
//           for the printed "TargetAccuracy:" float (that is outside).
// Sibling:  FUN_004c41c0 same shape on +0x142/+0x14a; FUN_004c4140 on
//           +0x140/+0x148 with floor 1 and no vehicle thr.
//
// Exactness: CF mirrors raw + read_memory; names cleaned / product-inferred.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W17-O seal).
// =============================================================================

/* Object_GetTargetAccuracyBase_Inferred

   Parameters:
     this (ECX): combat object / character with short stats at +0x13e / +0x146

   Algorithm:
     score = clamp_sum(min(+0x13e, 200), +0x146, 250)
     thr   = (GetVehicleOrNull_MI(this) != 0) ? 1 : -100   // vtbl+0x1DC
     return (thr < score) ? score : thr

   Returns: int accuracy base (EAX). */

int __fastcall Object_GetTargetAccuracyBase_Inferred(void *self)
{
  short baseRaw = *(short *)((char *)self + 0x13e);
  int baseCap = baseRaw;
  if (baseRaw > 200) {
    baseCap = 200;
  }

  int score;
  if (baseCap + (int)*(short *)((char *)self + 0x146) < 250) {
    int b = baseRaw;
    if (baseRaw > 200) {
      b = 200;
    }
    score = b + (int)*(short *)((char *)self + 0x146);
  } else {
    score = 250;
  }

  /* Bytes: mov eax,[esi+4]; mov ecx,[eax+4];
            mov edx,[ecx+esi+4]; lea ecx,[esi+ecx+4]; call [edx+0x1DC]
     MI this-adjust then virtual probe (object* or null). */
  int miDelta = *(int *)(*(int *)((char *)self + 4) + 4);
  void *adjThis = (char *)self + miDelta + 4;
  int *vtbl = *(int **)adjThis;
  int probe = ((int (__fastcall *)(void *))vtbl[0x1DC / 4])(adjThis);
  int thr = (-(unsigned)(probe != 0) & 0x65) - 100; /* 1 or -100 */

  if (thr < score) {
    /* asm recomputes the same clamp rather than reusing EDI */
    short b2 = *(short *)((char *)self + 0x13e);
    int bc = b2;
    if (b2 > 200) {
      bc = 200;
    }
    if (bc + (int)*(short *)((char *)self + 0x146) < 250) {
      int b = b2;
      if (b2 > 200) {
        b = 200;
      }
      return b + (int)*(short *)((char *)self + 0x146);
    }
    return 250;
  }

  /* thr path: second vtbl+0x1DC call (not CSE'd in retail) */
  miDelta = *(int *)(*(int *)((char *)self + 4) + 4);
  adjThis = (char *)self + miDelta + 4;
  vtbl = *(int **)adjThis;
  probe = ((int (__fastcall *)(void *))vtbl[0x1DC / 4])(adjThis);
  return (-(unsigned)(probe != 0) & 0x65) - 100;
}
