// =============================================================================
// StdMap_InsertWithHint_IntKey_Inferred
// -----------------------------------------------------------------------------
// Purpose:  MSVC std::map/set insert-with-hint by int key. Validates hint
//           position (empty / leftmost / end / neighbor via pred-succ); if
//           valid, RB-insert via FUN_005690a0; else fall back to full
//           insert-or-find (FUN_00569320) and return the iterator.
//
// Address:  0x00569560  (autoassault.exe, image base 0x400000)
// Body:     0x00569560–0x005696c3 (356 bytes; ret 0x0C)
// Stable:   aa_00569560
// System:   container / ordered map
// Ghidra:   FUN_00569560
//
// ABI:      __thiscall
//             ECX = MapShell *map   (+4 head, +8 size)
//             stack: outIt*, hintNode*, int *pKey
//             ret 0x0C
//
// Node:     left+0 parent+4 right+8 key+0xC isnil+0x49
//           (color+0x48 used inside FUN_005690a0)
//
// Exactness: CF mirrors raw + live decompile; names cleaned / INFERRED.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W21-G).
// =============================================================================

#include <cstdint>

// RB insert + rebalance; throws "map/set<T> too long" if size huge
// (decompiler thiscall form: this=map, out, addLeft, parent, pKey)
void *__thiscall FUN_005690a0(void *map, void *outIt, char addLeft, void *parent, int *pKey);

// Map predecessor (dual aa_00537770) — iterator via ECX (mutates)
void FUN_00537770(void);

// Map successor — iterator via ECX (mutates)
void FUN_00568200(void);

// Full insert-or-find (dual aa_00569320)
void *__thiscall FUN_00569320(int map, uint8_t *outPair, int *pKey);

// Ghidra SBORROW4: signed subtract overflow flag
static inline int SBORROW4(int a, int b)
{
    int r = a - b;
    return (((a ^ b) & (a ^ r)) >> 31) & 1;
}

/* StdMap_InsertWithHint_IntKey_Inferred — plate-faithful CF.

   Parameters:
     map:    this / ECX — shell with head* at +4, size at +8
     outIt:  out iterator node*
     hint:   hint node* (may be head/end or interior)
     pKey:   pointer to int key (also payload for node factory)

   Algorithm:
     1) size==0 → insert left of head
     2) hint==*head (leftmost): if *key < hint.key → insert left of hint
     3) hint==head (end): if rightmost.key < *key → insert right of rightmost
     4) else: if *key < hint.key, predecessor; if order allows, insert by isnil(right)
        else if overflow-aware key>hint.key, successor; if order allows, insert
     5) else FUN_00569320 full insert-or-find; *outIt = pair.it

   Sole caller: FUN_005697d0 (lower-bound then value at node+0x10). */

uint32_t *__thiscall StdMap_InsertWithHint_IntKey_Inferred(
    int map,
    uint32_t *outIt,
    int *hint,
    int *pKey)
{
    int *head;
    int key;
    int hintKey;
    int delta;
    uint32_t *pair;
    uint8_t local_pair[8];

    if (*(int *)(map + 8) == 0) {
        FUN_005690a0((void *)(intptr_t)map, outIt, 1, *(void **)(map + 4), pKey);
        return outIt;
    }
    head = *(int **)(map + 4);
    if (hint == (int *)*head) {
        if (*pKey < hint[3]) {
            FUN_005690a0((void *)(intptr_t)map, outIt, 1, hint, pKey);
            return outIt;
        }
    } else if (hint == head) {
        if (*(int *)(head[2] + 0xc) < *pKey) {
            FUN_005690a0((void *)(intptr_t)map, outIt, 0, (void *)(intptr_t)head[2], pKey);
            return outIt;
        }
    } else {
        key = *pKey;
        hintKey = hint[3];
        delta = hintKey - key;
        if (key < hintKey) {
            FUN_00537770();
            if (hint[3] < key) {
                if (*(char *)(hint[2] + 0x49) != '\0') {
                    FUN_005690a0((void *)(intptr_t)map, outIt, 0, hint, pKey);
                    return outIt;
                }
                FUN_005690a0((void *)(intptr_t)map, outIt, 1, hint, pKey);
                return outIt;
            }
            hintKey = hint[3];
            delta = hintKey - key;
        }
        if (SBORROW4(hintKey, key) != (delta < 0)) {
            FUN_00568200();
            if ((hint == *(int **)(map + 4)) || (key < hint[3])) {
                if (*(char *)(hint[2] + 0x49) != '\0') {
                    FUN_005690a0((void *)(intptr_t)map, outIt, 0, hint, pKey);
                    return outIt;
                }
                FUN_005690a0((void *)(intptr_t)map, outIt, 1, hint, pKey);
                return outIt;
            }
        }
    }
    pair = (uint32_t *)FUN_00569320(map, local_pair, pKey);
    *outIt = *pair;
    return outIt;
}
