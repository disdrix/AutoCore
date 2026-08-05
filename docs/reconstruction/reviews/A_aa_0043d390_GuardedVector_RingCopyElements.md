# Review A (reconstruction fidelity): `aa_0043d390` GuardedVector_RingCopyElements

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d390` |
| **VA** | `0x0043d390`–`0x0043d411` |
| **Canonical name** | `GuardedVector_RingCopyElements` |
| **Ghidra name** | `FUN_0043d390` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-A) |
| **Counterpart** | `reviews/B_aa_0043d390_GuardedVector_RingCopyElements.md` |
| **System** | STL / guarded ring container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; multi-caller xrefs |
| **Verdict** | **accept** |

---

## 1. Purpose

Shared **leaf** that copies dword elements along ring/deque-like map-of-blocks storage:

1. While `(srcCont,srcIdx) != (endCont,endIdx)`:
2. Resolve src/dst slots via `block = idx>>2`, `slot = idx%4`, wrap if `block >= capacity`.
3. Store one `uint32_t`; advance both indices.
4. Write `*outPair = {dstCont, finalDstIdx}`.

Used by RingCopyRange shim, EraseRange forward path, and related helpers.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043d390_FUN_0043d390.md` (+ 2026-07-29 W28-A append) |
| Annotated | `docs/reconstruction/raw/aa_0043d390_FUN_0043d390.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingCopyElements.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d390.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043d390_FUN_0043d390.md` |
| Named record | `docs/reconstruction/functions/aa_0043d390_GuardedVector_RingCopyElements.md` |
| Live | decompile ≡ raw; body 130 B; 7 stack formals; 0 callees; 7 xrefs |

---

## 3. Signature (sealed)

```c
// cdecl; plain RET (caller cleans)
void GuardedVector_RingCopyElements(
    int* outPair,
    void* srcCont, uint32_t srcIdx,
    void* srcEndCont, uint32_t srcEndIdx,
    void* dstCont, uint32_t dstIdx);
```

| Formal | Stack | Conf |
|---|---|---|
| outPair | `[esp+4]` | **High** |
| srcCont | `[esp+8]` | **High** |
| srcIdx | `[esp+c]` | **High** |
| srcEndCont | `[esp+10]` | **High** |
| srcEndIdx | `[esp+14]` | **High** |
| dstCont | `[esp+18]` | **High** |
| dstIdx | `[esp+1c]` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
push ebx/ebp/esi/edi
load srcIdx→ebx, dstIdx→ebp
if (srcCont==endCont && srcIdx==endIdx) goto done
loop:
  resolve src block/slot with wrap via srcCont.capacity
  resolve dst block/slot with wrap via dstCont.capacity
  *dst_slot = *src_slot
  ++dstIdx; ++srcIdx
  if not equal end: goto loop
done:
  outPair[1] = finalDstIdx; outPair[0] = dstCont
  pop*; ret
```

| Stage | Match | Conf |
|---|---|---|
| Iterator equality exit | **Yes** | **High** |
| `>>2` / `%4` block math | **Yes** | **High** |
| capacity wrap (`if cap <= block: block -= cap`) | **Yes** | **High** |
| map@+4 load | **Yes** | **High** |
| one dword store per step | **Yes** | **High** |
| out-pair write | **Yes** | **High** |
| leaf (0 callees) | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory` 130 B)

```
53 8B 5C 24 10 55 8B 6C 24 24 56 57 8B 44 24 18
3B 44 24 20 75 06 3B 5C 24 24 74 58 ... 89 68 04 5D 89 08 5B C3
```

Body exclusive end `0x0043d411` (RET).

---

## 6. Gaps

- Product / STL original template English (deque vs custom).
- Full formal surfaces of non-OWN callers `0043cb00` / `0043cf40`.
- Capacity field dual-use vs map length.
- Runtime / bit-exact — open.

---

## 7. Verdict

CF, cdecl 7-arg ABI, block-map addressing, multi-caller leaf role sealed. Closes W27-B/W27-C residual on this body. Product English residual only → **accept**.
