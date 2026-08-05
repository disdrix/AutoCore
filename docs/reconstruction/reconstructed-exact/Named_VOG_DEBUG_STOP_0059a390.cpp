// READABILITY (auto CF):
//  - Body size: ~266 non-empty decompiler lines.
//  - Control keywords: if×40, for×16, while×8, return×1.
//  - Notable callees: FUN_007a4480×32, fwrite×17, FUN_0059a200, FUN_0059a390.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_0059a390
// -----------------------------------------------------------------------------
// Stable ID: aa_0059a390
// Address:   0x0059a390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_VOG_DEBUG_STOP_0059a390(int param_1,FILE *param_2)



{

  int iVar1;

  FILE *_File;

  void *pvVar2;

  int iVar3;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  _File = param_2;

  FUN_0059a200(param_2);

  fwrite((void *)(param_1 + 0x528),0xc,1,_File);

  param_2 = *(FILE **)(*(int *)(param_1 + 0x534) + 0xc);

  fwrite(&param_2,4,1,_File);

  iVar1 = *(int *)(param_1 + 0x534);

  iVar3 = 0;

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  while( true ) {

    iVar1 = *(int *)(param_1 + 0x534);

    if (*(char *)(iVar1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar3 == 0) {

      iVar3 = *(int *)(iVar1 + 0x14);

    }

    else {

      iVar3 = *(int *)(iVar3 + 0x14);

    }

    if (iVar3 == 0) {

      pvVar2 = (void *)0x0;

    }

    else {

      pvVar2 = *(void **)(iVar3 + 8);

    }

    if (pvVar2 == (void *)0x0) break;

    fwrite(pvVar2,0x98,1,_File);

  }

  *(uint8_t *)(*(int *)(param_1 + 0x534) + 0x1d) = 0;

  local_1c = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x538) + 0xc);

  fwrite(&local_1c,4,1,_File);

  iVar1 = *(int *)(param_1 + 0x538);

  iVar3 = 0;

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  while( true ) {

    iVar1 = *(int *)(param_1 + 0x538);

    if (*(char *)(iVar1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar3 == 0) {

      iVar3 = *(int *)(iVar1 + 0x14);

    }

    else {

      iVar3 = *(int *)(iVar3 + 0x14);

    }

    if (iVar3 == 0) {

      pvVar2 = (void *)0x0;

    }

    else {

      pvVar2 = *(void **)(iVar3 + 8);

    }

    if (pvVar2 == (void *)0x0) break;

    fwrite(pvVar2,0x98,1,_File);

  }

  *(uint8_t *)(*(int *)(param_1 + 0x538) + 0x1d) = 0;

  local_18 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x53c) + 0xc);

  fwrite(&local_18,4,1,_File);

  iVar1 = *(int *)(param_1 + 0x53c);

  iVar3 = 0;

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  while( true ) {

    iVar1 = *(int *)(param_1 + 0x53c);

    if (*(char *)(iVar1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar3 == 0) {

      iVar3 = *(int *)(iVar1 + 0x14);

    }

    else {

      iVar3 = *(int *)(iVar3 + 0x14);

    }

    if (iVar3 == 0) {

      pvVar2 = (void *)0x0;

    }

    else {

      pvVar2 = *(void **)(iVar3 + 8);

    }

    if (pvVar2 == (void *)0x0) break;

    fwrite(pvVar2,0x98,1,_File);

  }

  *(uint8_t *)(*(int *)(param_1 + 0x53c) + 0x1d) = 0;

  local_14 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x540) + 0xc);

  fwrite(&local_14,4,1,_File);

  iVar1 = *(int *)(param_1 + 0x540);

  iVar3 = 0;

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  while( true ) {

    iVar1 = *(int *)(param_1 + 0x540);

    if (*(char *)(iVar1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar3 == 0) {

      iVar3 = *(int *)(iVar1 + 0x14);

    }

    else {

      iVar3 = *(int *)(iVar3 + 0x14);

    }

    if (iVar3 == 0) {

      pvVar2 = (void *)0x0;

    }

    else {

      pvVar2 = *(void **)(iVar3 + 8);

    }

    if (pvVar2 == (void *)0x0) break;

    fwrite(pvVar2,0x98,1,_File);

  }

  *(uint8_t *)(*(int *)(param_1 + 0x540) + 0x1d) = 0;

  local_10 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x544) + 0xc);

  fwrite(&local_10,4,1,_File);

  iVar1 = *(int *)(param_1 + 0x544);

  iVar3 = 0;

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  while( true ) {

    iVar1 = *(int *)(param_1 + 0x544);

    if (*(char *)(iVar1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar3 == 0) {

      iVar3 = *(int *)(iVar1 + 0x14);

    }

    else {

      iVar3 = *(int *)(iVar3 + 0x14);

    }

    if (iVar3 == 0) {

      pvVar2 = (void *)0x0;

    }

    else {

      pvVar2 = *(void **)(iVar3 + 8);

    }

    if (pvVar2 == (void *)0x0) break;

    fwrite(pvVar2,0x98,1,_File);

  }

  *(uint8_t *)(*(int *)(param_1 + 0x544) + 0x1d) = 0;

  local_c = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x548) + 0xc);

  fwrite(&local_c,4,1,_File);

  iVar1 = *(int *)(param_1 + 0x548);

  iVar3 = 0;

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  while( true ) {

    iVar1 = *(int *)(param_1 + 0x548);

    if (*(char *)(iVar1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar3 == 0) {

      iVar3 = *(int *)(iVar1 + 0x14);

    }

    else {

      iVar3 = *(int *)(iVar3 + 0x14);

    }

    if (iVar3 == 0) {

      pvVar2 = (void *)0x0;

    }

    else {

      pvVar2 = *(void **)(iVar3 + 8);

    }

    if (pvVar2 == (void *)0x0) break;

    fwrite(pvVar2,0x98,1,_File);

  }

  *(uint8_t *)(*(int *)(param_1 + 0x548) + 0x1d) = 0;

  local_8 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x54c) + 0xc);

  fwrite(&local_8,4,1,_File);

  iVar1 = *(int *)(param_1 + 0x54c);

  iVar3 = 0;

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  while( true ) {

    iVar1 = *(int *)(param_1 + 0x54c);

    if (*(char *)(iVar1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar3 == 0) {

      iVar3 = *(int *)(iVar1 + 0x14);

    }

    else {

      iVar3 = *(int *)(iVar3 + 0x14);

    }

    if (iVar3 == 0) {

      pvVar2 = (void *)0x0;

    }

    else {

      pvVar2 = *(void **)(iVar3 + 8);

    }

    if (pvVar2 == (void *)0x0) break;

    fwrite(pvVar2,0x98,1,_File);

  }

  *(uint8_t *)(*(int *)(param_1 + 0x54c) + 0x1d) = 0;

  local_4 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x550) + 0xc);

  fwrite(&local_4,4,1,_File);

  iVar1 = *(int *)(param_1 + 0x550);

  iVar3 = 0;

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  while( true ) {

    iVar1 = *(int *)(param_1 + 0x550);

    if (*(char *)(iVar1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar3 == 0) {

      iVar3 = *(int *)(iVar1 + 0x14);

    }

    else {

      iVar3 = *(int *)(iVar3 + 0x14);

    }

    if (iVar3 == 0) {

      pvVar2 = (void *)0x0;

    }

    else {

      pvVar2 = *(void **)(iVar3 + 8);

    }

    if (pvVar2 == (void *)0x0) break;

    fwrite(pvVar2,0x98,1,_File);

  }

  *(uint8_t *)(*(int *)(param_1 + 0x550) + 0x1d) = 0;

  return;

}
