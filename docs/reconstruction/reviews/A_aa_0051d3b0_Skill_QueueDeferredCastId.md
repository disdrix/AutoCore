# Review A (reconstruction fidelity): `aa_0051d3b0` Skill_QueueDeferredCastId

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d3b0` |
| **VA** | `0x0051d3b0` |
| **Body** | `0x0051d3b0`–`0x0051d424` |
| **Canonical name** | `Skill_QueueDeferredCastId` |
| **Review date** | `2026-07-29` (full dual residual; prior 2026-07-23 scaffold) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0051d3b0_Skill_QueueDeferredCastId.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Push one deferred skill-id dword** onto the cast-slot ring/deque (`__thiscall`, `this` = lazy 0x14 slot from `FUN_005169c0`).

Not cast execute, not validate, not network. Pure container mutator: optional map grow → ensure block → store `*pSkillId` → `size++`.

Sole caller: `Skill_ClearActiveCastCounterAndQueueId` (`0x00517b90` @ `0x00517bd4`) after lazy-get of the same slot.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051d3b0_Skill_QueueDeferredCastId.md` |
| Annotated | `docs/reconstruction/raw/aa_0051d3b0_Skill_QueueDeferredCastId.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_QueueDeferredCastId.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051d3b0_Skill_QueueDeferredCastId.md` |
| Live Ghidra | `decompile_function` `0x0051d3b0`; `read_memory` body 120 B; pcode basic |
| Grow helper | `FUN_0051c3b0` `0x0051c3b0` (deque map realloc; leave-FUN) |
| Too-long throw | `FUN_0051b5f0` — string **`"deque<T> too long"`** (MSVC STL) |
| Slot lazy-get | `FUN_005169c0` `0x005169c0` (zeros +4/+8/+0xC/+0x10 on first use) |
| Caller dual | `A\|B_aa_00517b90_Skill_ClearActiveCastCounterAndQueueId` |
| Call site asm | `0x00517bc2`–`0x00517bd4` (`get_assembly_context`) |
| Xrefs | **1** UNCONDITIONAL_CALL (`get_function_callers` / `get_xrefs_to`) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| **ABI:** ECX = slot `this`; stack `uint32_t *pId`; `RET 4` | **Confirmed** | asm `MOV ESI,ECX`; epilogue `C2 04 00` |
| Not immediate cast / no packet | **Confirmed** | body is container only |
| Slot fields: **+4 map**, **+8 mapsize**, **+0xC off**, **+0x10 size** | **Confirmed** | all loads/stores in body |
| Element = **one dword** (`*pId` write) | **Confirmed** | `MOV EDX,[ECX]; MOV [EAX],EDX` |
| Block size **0x10** = **4** dwords | **Confirmed** | `PUSH 0x10` / `operator_new`; index `& 3` / `>> 2` |
| Grow when `(off+size)&3==0` **and** `mapsize <= (size+4)>>2` | **Confirmed** | pcode + bytes `ADD EAX,4; SHR EAX,2; CMP [ESI+8],EAX; JA skip` |
| Grow callee `FUN_0051c3b0(this, 1)` thiscall | **Confirmed** | `PUSH 1; MOV ECX,ESI; CALL` |
| Block index wrap: if `mapsize <= block` then `block -= mapsize` (single subtract) | **Confirmed** | `CMP/JA/SUB` |
| Lazy block alloc when map[block]==0 | **Confirmed** | null check + `operator_new(0x10)` |
| Always `size++` at end | **Confirmed** | `ADD dword [ESI+0x10],1` |
| Null element ptr skips store (still inc size) | **Confirmed** | `TEST EAX,EAX / JZ` before store |
| MSVC **`deque<uint32_t>`-shaped** push_back | **High** | layout + grow + `"deque<T> too long"` on overflow path |
| Product C++ symbol / exact STL instantiation | **Open** | role name sealed; STL type INFERRED High |
| `this+0` unused in body | **Confirmed** | no load of `[ESI+0]` |
| Sole caller ClearActiveCastCounter | **Confirmed** | 1 xref |
| Caller passes **slot** not outer owner | **Confirmed** | `CALL FUN_005169c0; MOV ECX,EAX; CALL Queue` |
| Payload is skill id | **High** | caller pushes `&nSkillId`; name/registry |

---

## 4. Control flow: clean ≡ raw ≡ live asm

| Stage | Match |
|---|---|
| Prologue `PUSH ESI; MOV ESI,ECX` | Yes (asm; decomp omits) |
| Gate grow on block boundary + map full | Yes |
| `FUN_0051c3b0(1)` | Yes |
| `linear = off + size`; `block = linear>>2`; wrap | Yes |
| Ensure block; write dword; size++ | Yes |
| `RET 4` | Yes (asm) |
| No invented cast / wire | Yes |

### Recovered CF (asm-sealed)

```c
/* thiscall: ECX = cast-slot (0x14 block); stack = uint32_t *pSkillId; RET 4 */
void __thiscall Skill_QueueDeferredCastId(void *pSlot, uint32_t *pSkillId)
{
  uint32_t size = *(uint32_t *)((char *)pSlot + 0x10);
  uint32_t off  = *(uint32_t *)((char *)pSlot + 0x0C);

  if (((off + size) & 3) == 0) {
    if (*(uint32_t *)((char *)pSlot + 0x08) <= ((size + 4) >> 2)) {
      FUN_0051c3b0(pSlot, 1);   /* thiscall grow map by ≥1 (often max(map/2,8)) */
    }
  }

  uint32_t mapsize = *(uint32_t *)((char *)pSlot + 0x08);
  uint32_t linear  = *(uint32_t *)((char *)pSlot + 0x0C)
                   + *(uint32_t *)((char *)pSlot + 0x10);
  uint32_t block   = linear >> 2;
  if (mapsize <= block)
    block -= mapsize;

  uint32_t *map = *(uint32_t **)((char *)pSlot + 0x04);
  if (map[block] == 0)
    map[block] = (uint32_t)operator_new(0x10);   /* 4×dword block; no zero-fill here */

  uint32_t *elem = (uint32_t *)(map[block] + (linear & 3) * 4);
  if (elem != 0)
    *elem = *pSkillId;

  *(uint32_t *)((char *)pSlot + 0x10) = *(uint32_t *)((char *)pSlot + 0x10) + 1;
}
```

### Machine bytes (entry…epilogue)

`56 8B F1 … 83 46 10 01 5E C2 04 00` — body ends `ADD [ESI+0x10],1; POP ESI; RET 4`.

### Slot layout (shared with `FUN_005169c0` / LocalCastValidate / Clear)

| Off | Size | Role in **this** body | Confidence |
|---:|---:|---|---|
| +0x0 | 4 | unused here | Confirmed unused |
| +0x4 | 4 | map = `T**` block pointer array | **Confirmed** |
| +0x8 | 4 | mapsize (block count) | **Confirmed** |
| +0xC | 4 | off / head element index | **Confirmed** |
| +0x10 | 4 | size / element count (also busy gate elsewhere) | **Confirmed** |

Block: 0x10 bytes → 4× `uint32_t`. Indexing: `block = i>>2`, `sub = i&3`.

---

## 5. Callees / callers

### Callees

| Symbol | VA | Role |
|---|---|---|
| `FUN_0051c3b0` | `0x0051c3b0` | Grow map (`deque` map realloc); may throw via `FUN_0051b5f0` |
| `operator_new` | CRT | Allocate 0x10 block |

### Callers (1)

| Caller | Site | Setup |
|---|---|---|
| `Skill_ClearActiveCastCounterAndQueueId` | `0x00517bd4` | `PUSH &nSkillId`; `FUN_005169c0(owner)` → `ECX = slot`; `CALL Queue` |

---

## 6. Gaps / open

1. Product / PDB name for the slot type and exact `std::deque` instantiation (layout match is High, not a sealed typename).
2. Whether `operator_new(0x10)` block is zero-filled (this body does not zero; store only one dword).
3. Full semantics of Clear’s size-- then this size++ (pairing contract; owned by Clear dual).
4. Runtime / bit-exact / image diff (matrix policy).
5. Decompiler displays grow as `FUN_0051c3b0(1)` without explicit `this` — asm supplies ECX.

**Verdict:** **accept-with-gaps** — CF/ABI/offsets/element width/grow gate **sealed Confirmed**; product STL type name open.
