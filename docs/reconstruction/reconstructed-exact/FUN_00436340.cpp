// =============================================================================
// FUN_00436340
// -----------------------------------------------------------------------------
// Stable ID: aa_00436340
// Address:   0x00436340 – 0x004363aa  (autoassault.exe, image base 0x400000)
// System:    container / circular pointer-buffer utility
// Generated: 2026-07-29 OWN dual W16-H (decompile + read_memory; assembly-faithful)
// Exactness: Behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Push/copy a 0x14-byte (5-dword) POD element into a circular pointer buffer.
//   this in EAX; source struct in EDI.
//
// ABI (assembly-sealed):
//   EAX  = buffer object*
//   EDI  = const source* (0x14 bytes)
//   ret  = void (plain ret; no stack cleanup)
//
// Layout (this):
//   +0x04  void** slots
//   +0x08  uint  capacity
//   +0x0c  int   head
//   +0x10  int   count
//
// READABILITY:
//   - Grow when capacity <= count+1 via FUN_00436650(1) (EBX=this).
//   - writeIndex = (head + count) % capacity
//   - Lazy operator_new(0x14) if slots[writeIndex] is null
//   - Copy 5 dwords if non-null; always count++

/*
 * Behavioral notes:
 * - Derived from live Ghidra decompile + read_memory body.
 * - Ghidra plate uses in_EAX / unaff_EDI — matches asm mov ebx,eax / [edi] loads.
 * - Grow callee FUN_00436650 residual (circular reallocate) — not dual-owned.
 * - Null after failed new: skip copy but still increment count.
 */

void FUN_00436340(void)
{
  uint32_t *puVar1;
  int in_EAX;           /* this — buffer object */
  void *pvVar2;
  uint uVar3;           /* write index */
  uint32_t *unaff_EDI;  /* source 0x14-byte POD */

  if (*(uint *)(in_EAX + 8) <= (uint)(*(int *)(in_EAX + 0x10) + 1)) {
    FUN_00436650(1);    /* EBX = this after prologue mov ebx,eax */
  }

  uVar3 = *(int *)(in_EAX + 0xc) + *(int *)(in_EAX + 0x10);
  if (*(uint *)(in_EAX + 8) <= uVar3) {
    uVar3 = uVar3 - *(uint *)(in_EAX + 8);
  }

  if (*(int *)(*(int *)(in_EAX + 4) + uVar3 * 4) == 0) {
    pvVar2 = operator_new(0x14);
    *(void **)(*(int *)(in_EAX + 4) + uVar3 * 4) = pvVar2;
  }

  puVar1 = *(uint32_t **)(*(int *)(in_EAX + 4) + uVar3 * 4);
  if (puVar1 != (uint32_t *)0x0) {
    *puVar1 = *unaff_EDI;
    puVar1[1] = unaff_EDI[1];
    puVar1[2] = unaff_EDI[2];
    puVar1[3] = unaff_EDI[3];
    puVar1[4] = unaff_EDI[4];
  }

  *(int *)(in_EAX + 0x10) = *(int *)(in_EAX + 0x10) + 1;
  return;
}
