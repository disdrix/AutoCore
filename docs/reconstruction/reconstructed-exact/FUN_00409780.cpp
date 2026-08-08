// =============================================================================
// FUN_00409780  (named: StdTree_BuyHeadNode_Isnil2D_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409780
// Address:   0x00409780–0x00409809 inclusive (138 B / 0x8A)
// Module:    autoassault.exe (image base 0x400000)
// System:    STL / map-set head node (isnil@+0x2d, size 0x30)
// Generated: 2026-08-05 WQ9J-G dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// Prefer: StdTree_BuyHeadNode_Isnil2D_Inferred.cpp

#include <stdint.h>

extern void* operator_new(unsigned int size);

// EAX = node*; bare RET. Decompiler void is false.
void* FUN_00409780(void)
{
  uint32_t* node;
  void* local_10;
  uint8_t* puStack_c;
  uint32_t local_8;

  local_8 = 0xffffffff;
  puStack_c = (uint8_t*)0x009bc660; /* LAB_009bc660 */
  local_10 = 0; /* ExceptionList slot in plate */
  (void)local_10;
  (void)puStack_c;
  (void)local_8;

  node = (uint32_t*)operator_new(0x30);
  if (node != 0) {
    *node = 0;
  }
  if (node + 1 != 0) {
    node[1] = 0;
  }
  if (node + 2 != 0) {
    node[2] = 0;
  }
  *(uint8_t*)(node + 0xb) = 1;              /* color @ +0x2c */
  *(uint8_t*)((int)node + 0x2d) = 0;        /* isnil @ +0x2d */
  return node;
}
