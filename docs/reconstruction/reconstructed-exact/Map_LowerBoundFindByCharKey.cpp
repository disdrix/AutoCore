// =============================================================================
// Map_LowerBoundFindByCharKey
// -----------------------------------------------------------------------------
// Stable ID: aa_00402210
// Address:   0x00402210  (autoassault.exe, image base 0x400000)
// System:    skills-abilities (shared ordered-map find; char key)
// Generated: 2026-07-29 refined dual pass (scaffold was 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Leaf MSVC-style ordered-tree exact find for a single char key.
 * - ABI (asm): __thiscall, two stack args, ret 8.
 *     this      = map header (ECX); end/head at this+4
 *     pOutIt    = Node** result
 *     pKey      = char*  (one signed char)
 * - Decompiler may print a phantom third char* and swap pOut/pKey names — ignore.
 * - Node layout (this family only):
 *     +0x00 left, +0x08 right, +0x0C char key, +0x21 nil (0 = live)
 * - Walk is lower_bound-shaped; post-check (cand!=end && key<=search) seals equality.
 * - Read-only: writes *pOutIt only.
 *
 * Distinct from:
 *   Map_LowerBoundFindByIntKey      nil+0x15 key[3] int
 *   StdMap_LowerBoundByIntKey_INF   nil+0x1d key[3] int
 *   Map_ExactFindByIntKey         nil+0x29 key+0x10 int
 */

#include <stdint.h>

/* Map header: only +4 (end/head) is used here. */
/* Node: left@0, right@8, key char@0x0C, isnil@0x21. */

void __thiscall Map_LowerBoundFindByCharKey(void *this, void *pOutIt, void *pKey)
{
  uint32_t *cand;
  uint32_t *cur;
  uint32_t *next;
  uint32_t *end;

  end  = *(uint32_t **)((int)this + 4);
  cand = end;
  cur  = (uint32_t *)end[1];

  if (*(char *)((int)cur + 0x21) == '\0') {
    do {
      if (*(char *)(cur + 3) < *(char *)pKey) {
        next = (uint32_t *)cur[2];
      }
      else {
        next = (uint32_t *)*cur;
        cand = cur;
      }
      cur = next;
    } while (*(char *)((int)next + 0x21) == '\0');
  }

  if ((cand != end) && (*(char *)(cand + 3) <= *(char *)pKey)) {
    *(uint32_t **)pOutIt = cand;
    return;
  }
  *(uint32_t **)pOutIt = end;
  return;
}
