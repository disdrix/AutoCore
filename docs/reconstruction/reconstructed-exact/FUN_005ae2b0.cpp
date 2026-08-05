// =============================================================================
// FUN_005ae2b0 / StdTree_AllocNode_0x1c_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005ae2b0
// Address:   0x005ae2b0  (autoassault.exe, image base 0x400000)
// System:    util / container (MSVC _Tree / map node)
// Generated: 2026-07-29 W16-G dual seal (from raw + live decompile + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// =============================================================================
//
// PURPOSE:
//   operator_new(0x1C) a red-black tree node shell:
//     +0/+4/+8  left/parent/right = 0
//     +0x18     color = 1 (black)
//     +0x19     isnil = 0  (map head ctors overwrite to 1 and self-link L/P/R)
//   Value region +0x0C..+0x17 left uninitialized.
//
// ABI:
//   No args. EAX = node* (Ghidra decompile incorrectly shows void).
//   Plain ret (C3). cdecl operator_new.
//
// CALLERS (sample): InventoryGrid_ctor_Inferred, Skill_GetCategoryCooldownMap,
//   FUN_004e7420 map ctor, FUN_005adb20, FUN_00572ab0, FUN_005e12b0, ...
//
// SIBLINGS:
//   FUN_005ae270 = same pattern for 0x24 nodes (color@+0x20, isnil@+0x21)
//   FUN_0058d9c0 = MapFloatTfid_AllocNode (0x30, color@+0x28)

void *operator_new(unsigned int size);

// Faithful to raw CF; return type corrected to match EAX / callers.
void *FUN_005ae2b0(void)
{
  unsigned int *puVar1;

  puVar1 = (unsigned int *)operator_new(0x1c);
  if (puVar1 != (unsigned int *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (unsigned int *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (unsigned int *)0x0) {
    puVar1[2] = 0;
  }
  *(unsigned char *)(puVar1 + 6) = 1;                 // +0x18
  *(unsigned char *)((int)puVar1 + 0x19) = 0;
  return puVar1; // EAX — raw decompile omitted this return
}
