// =============================================================================
// TFID_NotEquals
// -----------------------------------------------------------------------------
// Stable ID: aa_0040b150
// Address:   0x0040b150  (autoassault.exe, image base 0x400000)
// Body:      0x0040b150 – 0x0040b188
// System:    tfid-identity
// Generated: 2026-07-23 scaffold; dual residual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual A/B:  docs/reconstruction/reviews/A|B_aa_0040b150_TFID_NotEquals.md
// =============================================================================

/*
 * Behavioral notes:
 * - Leaf __cdecl predicate over two TFID-like buffers.
 * - Compares ONLY ObjectId key: int32 @+0, int32 @+4, int8 @+8.
 * - Does NOT compare TFID bytes +9..+15 (not full 16-byte equality).
 * - Returns 0 if equal, 1 if not equal (opposite of TFID_EqualsObjectId @ 0x00404aa0).
 * - Assembly equal path: eax=1; sete invert → AL=0.
 * - Assembly unequal path: eax=0; sete invert → AL=1.
 *
 * Readability pass:
 * - Control flow and compare order preserved from authoritative raw + body bytes.
 */

int __cdecl TFID_NotEquals(void *pA, void *pB)
{
  if (((*(int *)pA == *(int *)pB) && (*(int *)((int)pA + 4) == *(int *)((int)pB + 4))) &&
     (*(char *)((int)pA + 8) == *(char *)((int)pB + 8))) {
    return 0;
  }
  return 1;
}
