// =============================================================================
// FUN_0042b450  (Ghidra name twin of BitStream_GrowForBits)
// -----------------------------------------------------------------------------
// Stable ID: aa_0042b450
// Address:   0x0042b450  (autoassault.exe, image base 0x400000)
// System:    network-bitstream
// Generated: 2026-07-29 W22-D dual A/B (replaces 2026-07-23 scaffold)
// Exactness: Decompiler-surface CF preserved; see BitStream_GrowForBits.cpp for
//            byte-corrected formula grouping and AL bool returns.
// Named plate: reconstructed-exact/BitStream_GrowForBits.cpp
// =============================================================================

// Decompiler surface (authoritative raw body). unaff_EDI = BitStream* this.
// NewSize line has C-precedence hazard — true math is
//   ((param_1 + bitCap + 7) >> 3) + 0x5dc
// per read_memory seal.

uint __fastcall FUN_0042b450(int param_1)
{
  int iVar1;
  void *pvVar2;
  uint _NewSize;
  int unaff_EDI;

  _NewSize = (param_1 + 7 + *(uint *)(unaff_EDI + 0x30) >> 3) + 0x5dc;
  if (*(uint *)(unaff_EDI + 0x10) < _NewSize) {
    if (*(char *)(unaff_EDI + 0x14) != '\0') {
      *(uint *)(unaff_EDI + 0x10) = _NewSize;
      pvVar2 = realloc(*(void **)(unaff_EDI + 0xc), _NewSize);
      *(void **)(unaff_EDI + 0xc) = pvVar2;
      iVar1 = _NewSize * 8;
      *(int *)(unaff_EDI + 0x2c) = iVar1;
      *(int *)(unaff_EDI + 0x30) = iVar1;
      return CONCAT31((int3)((uint)iVar1 >> 8), 1);
    }
  }
  else {
    *(uint *)(unaff_EDI + 0x10) = _NewSize;
  }
  *(undefined1 *)(unaff_EDI + 0x1c) = 1;
  return *(uint *)(unaff_EDI + 0x30) & 0xffffff00;
}
