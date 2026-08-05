// =============================================================================
// CNDHash_Insert
// -----------------------------------------------------------------------------
// Stable ID: aa_0053c560
// Address:   0x0053c560  (autoassault.exe, image base 0x400000)
// System:    container (continent unlock / create-packet callers)
// Generated: 2026-07-23 from raw capture; dual A/B 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes (dual A/B sealed 2026-07-29):
 * - int __thiscall(this=hash, uint key, void *value, char allowDuplicate)
 * - allowDuplicate = soft-skip-if-exists (return 1, no mutation); NOT multi-value insert.
 * - Returns: 0 success; 1 soft-present; 0x80004003 E_POINTER; 0x80004005 E_FAIL.
 *   Decompiler shows signed -0x7fffbffd / -0x7fffbffb (same bits).
 * - Hash: +0x08 mask, +0x0c count, +0x10 buckets*, +0x14 listHead, +0x18 listTail,
 *   +0x1d lockedForTraversal (log only, does not abort).
 * - Node 0x1c via FUN_0053ada0 freelist: vtbl PTR_FUN_009cefd4, +4 touch, +8 value,
 *   +0xc bucketNext, +0x10 key, +0x14 listNext, +0x18 listPrev.
 * - Twins 0x0053c360 / 0x0053c660: same CF, different node vtbl (separate units).
 * - Callers: CVOGReaction_UnlockContinentObject (char+0x534); ApplyCreateFromPacket.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* Generic CNDHash insert(key, value). Used when applying CreateCharacterExtended continent slots
   and UnlockContinentObject. */

int __thiscall CNDHash_Insert(void *this,uint key,void *value,char allowDuplicate)

{
  int iVar1;
  void *pvVar2;
  uint32_t /* width from decompiler */ *puVar3;
  
  if (value == (void *)0x0) {
    return -0x7fffbffd; /* 0x80004003 E_POINTER */
  }
  if (*(char *)((int)this + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:insert, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  if (allowDuplicate != '\0') {
    pvVar2 = CNDHash_LookupByKey(this,key);
    if (pvVar2 != (void *)0x0) {
      return 1;
    }
  }
  pvVar2 = CNDHash_LookupByKey(this,key);
  if (pvVar2 != (void *)0x0) {
    FUN_007a4480(0,"Duplicate hash insert %u, failing out",key);
    return -0x7fffbffb; /* 0x80004005 E_FAIL */
  }
  puVar3 = (uint32_t /* width from decompiler */ *)FUN_0053ada0();
  puVar3[3] = 0;
  *puVar3 = &PTR_FUN_009cefd4;
  puVar3[5] = 0;
  puVar3[6] = 0;
  *(uint8_t *)(puVar3 + 1) = 0;
  puVar3[2] = value;
  puVar3[4] = key;
  iVar1 = *(int *)(*(int *)((int)this + 0x10) + (*(uint *)((int)this + 8) & key) * 4);
  puVar3[3] = *(uint32_t /* width from decompiler */ *)(iVar1 + 4);
  *(uint32_t /* width from decompiler */ **)(iVar1 + 4) = puVar3;
  FUN_00537d30();
  if (*(int *)((int)this + 0x18) != 0) {
    *(uint32_t /* width from decompiler */ **)(*(int *)((int)this + 0x18) + 0x14) = puVar3;
    puVar3[5] = 0;
    puVar3[6] = *(uint32_t /* width from decompiler */ *)((int)this + 0x18);
    *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
    *(uint32_t /* width from decompiler */ **)((int)this + 0x18) = puVar3;
    return 0;
  }
  *(uint32_t /* width from decompiler */ **)((int)this + 0x18) = puVar3;
  *(uint32_t /* width from decompiler */ **)((int)this + 0x14) = puVar3;
  puVar3[6] = 0;
  puVar3[5] = 0;
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
  return 0;
}
