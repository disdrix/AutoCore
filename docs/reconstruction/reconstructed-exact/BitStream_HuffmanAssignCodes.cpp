// =============================================================================
// BitStream_HuffmanAssignCodes
// -----------------------------------------------------------------------------
// Stable ID: aa_0077d440
// Address:   0x0077d440 – 0x0077d514  (autoassault.exe, image base 0x400000)
// System:    net / TNL BitStream Huffman (code assignment walk)
// Dual:      W26-C 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Recursive walk of the Huffman tree (DAT_00d1eab0, 8 B nodes) that fills
//   each alphabet leaf (DAT_00d1eabc, stride 0xC) with:
//     +4  bit length (uint8)
//     +8  code bits  (uint32) — path bits written into scratch BitStream buffer
//   Left child edge writes bit 0; right writes bit 1. Leaves encoded as
//   negative shorts: nodeOrLeaf = -1 - leafIndex.
//
//   Sole external caller: BitStream_HuffmanBuildTables (FUN_0077d520)
//     FUN_0077d440(&scratch, 0, 0);
//
// ABI (machine):
//   cdecl; 3 stack formals; plain RET; void
// =============================================================================

#include <cstdint>

extern "C" std::uint8_t FUN_0042b450(/* this in EDI; needBits in ECX */);

// Image globals
extern std::uint8_t*  DAT_00d1eabc;  // alphabet base, stride 0xC
extern std::uint8_t*  DAT_00d1eab0;  // tree base, stride 8

// Minimal BitStream-like offsets used by this walker (from parent scratch):
//   +0x0C  uint8_t*  bit buffer base (also used as ** for current dword)
//   +0x18  int       bit position
//   +0x30  uint32_t  bit capacity

extern "C" void BitStream_HuffmanAssignCodes(
    void* ctx, int nodeOrLeaf, int depth)
{
  auto* c = static_cast<std::uint8_t*>(ctx);

  if (nodeOrLeaf < 0) {
    // alphabet row: base + (-1 - nodeOrLeaf) * 0xC
    // decompiler: DAT_00d1eabc + (nodeOrLeaf * 3 + 3) * -4
    std::uint8_t* row =
        DAT_00d1eabc + (nodeOrLeaf * 3 + 3) * -4;
    *reinterpret_cast<std::uint32_t*>(row + 8) =
        **reinterpret_cast<std::uint32_t**>(c + 0xc);
    *(row + 4) = static_cast<std::uint8_t>(depth);
    return;
  }

  int savedBitPos = *reinterpret_cast<int*>(c + 0x18);
  std::uint8_t* node = DAT_00d1eab0 + nodeOrLeaf * 8;

  // ---- left edge: write bit 0 ----
  {
    int bitPos = *reinterpret_cast<int*>(c + 0x18);
    if (*reinterpret_cast<std::uint32_t*>(c + 0x30) <
        static_cast<std::uint32_t>(bitPos + 1)) {
      // FUN_0042b450: expand; AL != 0 → proceed to write
      // (EDI=ctx, ECX=1 at call site)
      std::uint8_t ok = FUN_0042b450();
      if (ok != 0) {
        goto write_zero;
      }
      // expand failed: skip write, still recurse
    } else {
    write_zero:
      std::uint8_t* pb =
          *reinterpret_cast<std::uint8_t**>(c + 0xc) +
          (static_cast<std::uint32_t>(*reinterpret_cast<int*>(c + 0x18)) >> 3);
      *pb = static_cast<std::uint8_t>(
          *pb &
          ~static_cast<std::uint8_t>(
              1u << (*reinterpret_cast<std::uint32_t*>(c + 0x18) & 7u)));
      *reinterpret_cast<int*>(c + 0x18) =
          *reinterpret_cast<int*>(c + 0x18) + 1;
    }
  }
  BitStream_HuffmanAssignCodes(
      ctx, static_cast<int>(*reinterpret_cast<std::int16_t*>(node + 4)),
      depth + 1);
  *reinterpret_cast<int*>(c + 0x18) = savedBitPos;

  // ---- right edge: write bit 1 ----
  {
    int bitPos = *reinterpret_cast<int*>(c + 0x18);
    if (*reinterpret_cast<std::uint32_t*>(c + 0x30) <
        static_cast<std::uint32_t>(bitPos + 1)) {
      std::uint8_t ok = FUN_0042b450();
      if (ok == 0) {
        goto recurse_right;
      }
    }
    {
      std::uint8_t* pb =
          *reinterpret_cast<std::uint8_t**>(c + 0xc) +
          (static_cast<std::uint32_t>(*reinterpret_cast<int*>(c + 0x18)) >> 3);
      *pb = static_cast<std::uint8_t>(
          *pb |
          static_cast<std::uint8_t>(
              1u << (*reinterpret_cast<std::uint32_t*>(c + 0x18) & 7u)));
      *reinterpret_cast<int*>(c + 0x18) =
          *reinterpret_cast<int*>(c + 0x18) + 1;
    }
  }
recurse_right:
  BitStream_HuffmanAssignCodes(
      ctx, static_cast<int>(*reinterpret_cast<std::int16_t*>(node + 6)),
      depth + 1);
  *reinterpret_cast<int*>(c + 0x18) = savedBitPos;
}

extern "C" void FUN_0077d440(void* ctx, int nodeOrLeaf, int depth)
{
  BitStream_HuffmanAssignCodes(ctx, nodeOrLeaf, depth);
}
