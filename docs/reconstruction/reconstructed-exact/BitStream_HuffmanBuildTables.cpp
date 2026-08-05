// =============================================================================
// BitStream_HuffmanBuildTables
// -----------------------------------------------------------------------------
// Stable ID: aa_0077d520
// Address:   0x0077d520 – 0x0077d952  (autoassault.exe, image base 0x400000)
// System:    net / TNL BitStream Huffman
// Dual:      W25-T 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   One-shot builder for global Huffman tables used by BitStream_writeString /
//   BitStream_readString. Seeds 256 alphabet entries from DAT_00a1ea68
//   frequencies, constructs the binary tree into DAT_00d1eab0 (8 B nodes),
//   then walks the tree via FUN_0077d440 to fill bit lengths and codes.
//
//   Callers gate: if (DAT_00d17a28 == 0) BitStream_HuffmanBuildTables();
//   This function sets DAT_00d17a28 = 1 at entry.
//
// ABI (machine):
//   no args; void return
//   frame SUB ESP,0x154 / ADD ESP,0x154; RET
// =============================================================================

#include <cstdint>
#include <cstdlib>
#include <cstring>

extern "C" void FUN_00433c00(void);
extern "C" void FUN_00433ba0(std::uint32_t n);
extern "C" void FUN_0077d440(void* ctx, int nodeOrLeaf, int depth);
extern "C" void* operator_new__(std::size_t);     // operator new[]
extern "C" void operator_delete__(void*);         // operator delete[]

// Globals (image)
extern std::uint8_t DAT_00d17a28;
extern std::uint32_t DAT_00a1ea68[];   // freq seed [256]
extern std::uint8_t* DAT_00d1eabc;     // alphabet base
extern std::uint32_t* DAT_00d1eab0;    // tree base (pairs of dwords)
extern std::uint32_t DAT_00d1eaa8;     // tree count
extern std::uint32_t DAT_00d1eaac;     // tree capacity
extern std::uint32_t DAT_00d1eab4;     // alphabet size/cap related
extern void* PTR_LAB_009d7b94;
extern void* PTR_LAB_009d7b00;

// Alphabet stride 0xC; tree node stride 8.
// Worklist entry: { int* nodeOrNull, int* leafOrNull } — 8 bytes.

void BitStream_HuffmanBuildTables(void)
{
  DAT_00d17a28 = 1;
  FUN_00433c00();

  if (DAT_00d1eab4 < 0x100 || DAT_00d1eab4 > 0x100) {
    DAT_00d1eab4 = 0x100;
  }
  FUN_00433ba0(0x100);

  std::uint32_t uVar15 = DAT_00d1eaa8 + 1;
  FUN_00433ba0(uVar15);
  // Decompiler free-on-shrink-to-zero pattern (vector-like):
  std::uint32_t uVar16 = uVar15;
  if ((uVar15 <= DAT_00d1eaa8) && (uVar16 = DAT_00d1eaa8, uVar15 < DAT_00d1eaa8) &&
      (uVar16 = uVar15, uVar15 == 0)) {
    DAT_00d1eaa8 = uVar15;
    free(DAT_00d1eab0);
    DAT_00d1eab0 = nullptr;
    DAT_00d1eaac = 0;
    uVar16 = DAT_00d1eaa8;
  }
  DAT_00d1eaa8 = uVar16;

  // Seed alphabet leaves
  int iVar9 = 0;
  int iVar13 = 0;
  do {
    int iVar11 = static_cast<int>(DAT_00a1ea68[iVar9]);
    int* piVar4 = reinterpret_cast<int*>(DAT_00d1eabc + iVar13);
    *reinterpret_cast<char*>(reinterpret_cast<std::uint8_t*>(piVar4) + 5) =
        static_cast<char>(iVar9);
    iVar9 = iVar9 + 1;
    *piVar4 = iVar11 + 1;  // weight = freq + 1
    iVar13 = iVar13 + 0xc;
    piVar4[2] = 0;         // code bits
    *reinterpret_cast<std::uint8_t*>(piVar4 + 1) = 0;  // bitlen
  } while (iVar9 < 0x100);

  int local_150 = 0x100;  // worklist live count
  int* piVar4 = reinterpret_cast<int*>(operator_new__(0x800));
  if (piVar4 != nullptr) {
    int i = 0x100;
    int* p = piVar4;
    do {
      p[0] = 0;
      p[1] = 0;
      p += 2;
      i = i - 1;
    } while (i != 0);
  }

  // Point worklist slots at alphabet leaves
  iVar9 = 0;
  int* piVar10 = piVar4;
  do {
    int iVar13b = reinterpret_cast<int>(DAT_00d1eabc) + iVar9;
    piVar10[0] = 0;
    piVar10[1] = iVar13b;
    iVar9 = iVar9 + 0xc;
    piVar10 = piVar10 + 2;
  } while (iVar9 < 0xc00);

  int* local_14c = piVar4 + 0x1fe;  // last slot pointer (swap-from-end)

  // Classic Huffman: repeatedly merge two lightest
  do {
    int i_best = -1;
    int i_scan = 0;
    std::uint32_t second_w = 0xffffffffu;
    int local_148 = -1;
    int local_154 = -1;  // second-best index
    std::uint32_t best_w = 0xfffffffeu;
    int i_hold = i_best;

    if (local_150 > 0) {
      do {
        std::uint32_t* puVar5 = reinterpret_cast<std::uint32_t*>(piVar4[i_scan * 2]);
        std::uint32_t uVar7;
        if (puVar5 == nullptr) {
          uVar7 = *reinterpret_cast<std::uint32_t*>(piVar4[i_scan * 2 + 1]);
        } else {
          uVar7 = *puVar5;
        }
        std::uint32_t uVar14;
        if (uVar7 < best_w) {
          if (puVar5 == nullptr) {
            puVar5 = reinterpret_cast<std::uint32_t*>(piVar4[i_scan * 2 + 1]);
          }
          uVar14 = *puVar5;
          i_best = i_scan;
          second_w = best_w;
          local_154 = i_hold;
          local_148 = i_scan;
        } else {
          if (puVar5 == nullptr) {
            uVar7 = *reinterpret_cast<std::uint32_t*>(piVar4[i_scan * 2 + 1]);
          } else {
            uVar7 = *puVar5;
          }
          uVar14 = best_w;
          i_best = i_hold;
          if (uVar7 < second_w) {
            if (puVar5 == nullptr) {
              puVar5 = reinterpret_cast<std::uint32_t*>(piVar4[i_scan * 2 + 1]);
            }
            second_w = *puVar5;
            local_154 = i_scan;
          }
        }
        i_scan = i_scan + 1;
        best_w = uVar14;
        i_hold = i_best;
      } while (i_scan < local_150);
    }

    // Ensure capacity for one more tree node
    std::uint32_t newCount = DAT_00d1eaa8 + 1;
    if (DAT_00d1eaac < newCount) {
      std::uint32_t newCap = (newCount - (newCount & 0xf)) + 0x10;
      std::uint32_t* neu = reinterpret_cast<std::uint32_t*>(malloc(newCap * 8));
      std::uint32_t* old = DAT_00d1eab0;
      std::uint32_t oldCount = DAT_00d1eaa8;
      DAT_00d1eab0 = neu;
      std::uint32_t k = 0;
      if (oldCount != 0) {
        do {
          std::uint32_t* dst = DAT_00d1eab0 + k * 2;
          if (dst != nullptr) {
            dst[0] = old[k * 2];
            dst[1] = old[k * 2 + 1];
          }
          k = k + 1;
        } while (k < oldCount);
      }
      DAT_00d1eab0 = old;
      free(old);
      i_best = local_148;
      DAT_00d1eaac = newCap;
      DAT_00d1eab0 = neu;
    }

    // Vector size bump (+ free-on-zero shrink pattern)
    std::uint32_t uVar15b = newCount;
    if ((newCount <= DAT_00d1eaa8) && (uVar15b = DAT_00d1eaa8, newCount < DAT_00d1eaa8) &&
        (uVar15b = newCount, newCount == 0)) {
      DAT_00d1eaa8 = newCount;
      free(DAT_00d1eab0);
      DAT_00d1eab0 = nullptr;
      DAT_00d1eaac = 0;
      uVar15b = DAT_00d1eaa8;
    }
    DAT_00d1eaa8 = uVar15b;

    int* parent = reinterpret_cast<int*>(DAT_00d1eab0 + DAT_00d1eaa8 * 2 - 2);
    int* leftObj = reinterpret_cast<int*>(piVar4[i_best * 2]);
    if (leftObj == nullptr) {
      leftObj = reinterpret_cast<int*>(piVar4[i_best * 2 + 1]);
    }
    int* rightObj = reinterpret_cast<int*>(piVar4[local_154 * 2]);
    if (rightObj == nullptr) {
      rightObj = reinterpret_cast<int*>(piVar4[local_154 * 2 + 1]);
    }
    parent[0] = rightObj[0] + leftObj[0];

    // Encode children as short indices
    short sLeft;
    if (piVar4[i_best * 2 + 1] == 0) {
      sLeft = static_cast<short>(
          (piVar4[i_best * 2] - reinterpret_cast<int>(DAT_00d1eab0)) >> 3);
    } else {
      int delta = piVar4[i_best * 2 + 1] - reinterpret_cast<int>(DAT_00d1eabc);
      // decompiler: -1 - (delta / 0xC) with signed div magic
      sLeft = static_cast<short>(
          -1 - (((static_cast<short>(delta / 0xc) + static_cast<short>(delta >> 31)) -
                 static_cast<short>((static_cast<long long>(delta) * 0x2aaaaaabLL) >> 63))));
    }
    *reinterpret_cast<short*>(parent + 1) = sLeft;

    short sRight;
    if (piVar4[local_154 * 2 + 1] == 0) {
      sRight = static_cast<short>(
          (piVar4[local_154 * 2] - reinterpret_cast<int>(DAT_00d1eab0)) >> 3);
    } else {
      sRight = static_cast<short>(
          -1 - static_cast<short>(
                   (piVar4[local_154 * 2 + 1] - reinterpret_cast<int>(DAT_00d1eabc)) / 0xc));
    }
    *reinterpret_cast<short*>(reinterpret_cast<char*>(parent) + 6) = sRight;

    // Compact worklist: keep parent at min(i_best, second); drop other via end-swap
    int keep = local_154;
    int drop = i_best;
    if (i_best <= local_154) {
      keep = i_best;
      drop = local_154;
    }
    piVar4[keep * 2 + 1] = 0;
    piVar4[keep * 2] = reinterpret_cast<int>(parent);
    local_150 = local_150 - 1;
    if (local_154 != local_150) {
      piVar4[drop * 2] = local_14c[0];
      piVar4[drop * 2 + 1] = local_14c[1];
    }
    local_14c = local_14c - 2;
  } while (local_150 != 1);

  // Root into tree[0]
  std::uint32_t* root = reinterpret_cast<std::uint32_t*>(*piVar4);
  DAT_00d1eab0[0] = root[0];
  DAT_00d1eab0[1] = root[1];
  operator_delete__(piVar4);

  // Scratch BitStream-shaped object for code assignment
  std::uint32_t local_13c = 0;
  void** local_138 = &PTR_LAB_009d7b94;
  std::uint32_t* local_134 = nullptr;
  std::uint32_t local_130 = 0;
  std::uint32_t* local_12c = &local_13c;
  std::uint32_t local_128 = 4;
  char local_124 = 0;
  std::uint32_t local_120 = 0;
  std::uint8_t local_11c = 0;
  std::uint8_t local_11b = 0;
  std::uint32_t local_10c = 0x20;
  std::uint32_t local_108 = 0x20;
  std::uint32_t local_104 = 0;
  std::uint8_t local_100 = 0;

  // layout: pass address of vtable slot (&local_138)
  FUN_0077d440(&local_138, 0, 0);

  local_138 = &PTR_LAB_009d7b00;
  if (local_124 != 0) {
    free(local_12c);
  }
  while (local_134 != nullptr) {
    std::uint32_t* next = reinterpret_cast<std::uint32_t*>(local_134[2]);
    local_134[0] = 0;
    local_134[1] = 0;
    local_134[2] = 0;
    local_134 = next;
  }
}

extern "C" void FUN_0077d520(void)
{
  BitStream_HuffmanBuildTables();
}
