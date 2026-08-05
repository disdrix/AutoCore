# Annotated low-level: Skill_QueueDeferredCastId

| Field | Value |
|---|---|
| Stable ID | `aa_0051d3b0` |
| VA | `0x0051d3b0`–`0x0051d424` |
| System | skills-abilities |
| Date | 2026-07-29 (refresh; raw body unchanged) |

## Machine-level notes

- Source: raw capture + live `decompile_function` / `read_memory` / pcode (2026-07-29).
- Prefer assembly when decompiler conflicts (this unit: decomp CF matches; ABI/this explicit only in asm).
- **ABI sealed:** `thiscall`, ECX = **slot** (not outer owner), one stack arg `uint32_t *`, **`RET 4`**.
- Container is MSVC **deque-shaped**: map of blocks, 4×dword blocks (0x10), fields at +4/+8/+0xC/+0x10.
- Grow helper `FUN_0051c3b0`; overflow path throws **`"deque<T> too long"`** (`FUN_0051b5f0`).
- C precedence trap: `size + 4U >> 2` in raw means **`(size + 4) >> 2`** (asm: `ADD 4; SHR 2`).

## Pseudocode (annotated, asm-corrected)

```c
/* Skill_QueueDeferredCastId
   Push deferred skill-id dword onto cast-slot ring/deque.

   this (ECX) = 0x14 slot from FUN_005169c0 (owner+0x64)
     +0x4  map      (uint32_t ** / block*)
     +0x8  mapsize  (block count)
     +0xC  off      (head element index)
     +0x10 size     (element count; busy if ≠0 in LocalCastValidate)

   param_2 = &skillId (uint32_t *)
   RET 4
*/

void __thiscall Skill_QueueDeferredCastId(void *pSlot, uint32_t *pSkillId)
{
  uint32_t size = *(uint32_t *)((char *)pSlot + 0x10);
  uint32_t off  = *(uint32_t *)((char *)pSlot + 0x0C);

  /* Need a new block (write index on 4-element boundary) and map full? */
  if (((off + size) & 3U) == 0 &&
      (*(uint32_t *)((char *)pSlot + 0x08) <= ((size + 4U) >> 2))) {
    FUN_0051c3b0(pSlot, 1);   /* thiscall; decomp shows FUN_0051c3b0(1) */
  }

  uint32_t linear = *(uint32_t *)((char *)pSlot + 0x0C)
                  + *(uint32_t *)((char *)pSlot + 0x10);
  uint32_t block  = linear >> 2;
  uint32_t mapsize = *(uint32_t *)((char *)pSlot + 0x08);
  if (mapsize <= block)
    block -= mapsize;         /* single wrap subtract */

  uint32_t *map = *(uint32_t **)((char *)pSlot + 0x04);
  if (map[block] == 0) {
    void *blk = operator_new(0x10);   /* 4 dwords; no zero-fill in this fn */
    map[block] = (uint32_t)blk;
  }

  uint32_t *elem =
    (uint32_t *)(*(uint32_t *)((char *)map + block * 4) + (linear & 3) * 4);
  /* cleaner: (uint32_t *)map[block] + (linear & 3) */
  if (elem != 0)
    *elem = *pSkillId;

  *(uint32_t *)((char *)pSlot + 0x10) =
    *(uint32_t *)((char *)pSlot + 0x10) + 1;
}
```

## Call site (sole caller)

`Skill_ClearActiveCastCounterAndQueueId` @ `0x00517bd4`:

```asm
LEA  ECX, [ESP+0xC]      ; &nSkillId
PUSH ECX
MOV  ECX, ESI            ; owner
CALL FUN_005169c0        ; EAX = slot
MOV  ECX, EAX            ; Queue this = slot
CALL Skill_QueueDeferredCastId
```

## Open questions

- Product STL typename (layout High as deque).
- Drain/pop consumer of this ring.
- OOM: `operator_new` null → skip store, still size++.
