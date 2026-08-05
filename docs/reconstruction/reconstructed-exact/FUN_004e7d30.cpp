// =============================================================================
// FUN_004e7d30  (Ghidra symbol twin of CNDHash_InsertDualKey)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e7d30
// Address:   0x004e7d30 – 0x004e7e5d  (autoassault.exe, image base 0x400000)
// Named:     CNDHash_InsertDualKey
// Generated: 2026-07-29 W23-L dual seal
// Exactness: Behavior-preserving. Bit-for-bit: DEFERRED.
// See:       reconstructed-exact/CNDHash_InsertDualKey.cpp
// =============================================================================

uint32_t __thiscall FUN_004e7d30(
    int table,
    uint32_t keyLo,
    uint32_t keyHi,
    int value,
    char soft)
{
  int node;
  undefined4 *neu;

  if (value == 0) {
    return 0x80004003;
  }
  if (*(char *)(table + 0x1d) != '\0') {
    FUN_007a4480(0, "HashError:insert, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  if (soft != '\0') {
    node = FUN_004e23d0(keyLo, keyHi, &soft);
    if ((node != 0) && (*(int *)(node + 0xc) != 0)) {
      return 1;
    }
  }
  node = FUN_004e23d0(keyLo, keyHi, &soft);
  if ((node != 0) && (*(int *)(node + 0xc) != 0)) {
    FUN_007a4480(0, "Duplicate hash insert %u, failing out", keyLo, keyHi);
    return 0x80004005;
  }
  neu = (undefined4 *)FUN_00589890();
  neu[4] = 0;
  *neu = &PTR_FUN_009cc208;
  neu[8] = 0;
  neu[9] = 0;
  *(undefined1 *)(neu + 2) = 0;
  neu[3] = value;
  neu[6] = keyLo;
  neu[7] = keyHi;
  node = *(int *)(*(int *)(table + 0x10) + (*(uint32_t *)(table + 8) & keyLo) * 4);
  neu[4] = *(undefined4 *)(node + 4);
  *(undefined4 **)(node + 4) = neu;
  FUN_004e2360();
  if (*(int *)(table + 0x18) != 0) {
    *(undefined4 **)(*(int *)(table + 0x18) + 0x20) = neu;
    neu[8] = 0;
    neu[9] = *(undefined4 *)(table + 0x18);
    *(int *)(table + 0xc) = *(int *)(table + 0xc) + 1;
    *(undefined4 **)(table + 0x18) = neu;
    return 0;
  }
  *(undefined4 **)(table + 0x18) = neu;
  *(undefined4 **)(table + 0x14) = neu;
  neu[9] = 0;
  neu[8] = 0;
  *(int *)(table + 0xc) = *(int *)(table + 0xc) + 1;
  return 0;
}
