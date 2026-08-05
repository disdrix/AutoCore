# Review A (reconstruction fidelity): `aa_0043df90` GuardedVector_EraseRange_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043df90` |
| **VA** | `0x0043df90`–`0x0043e07d` (**238 B**) |
| **Canonical name** | `GuardedVector_EraseRange_Thiscall` (**Inferred**) |
| **Ghidra name** | `FUN_0043df90` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-L) |
| **Counterpart** | `reviews/B_aa_0043df90_GuardedVector_EraseRange_Thiscall.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 238 B) + `analyze_function_complete`; callers 5; callees sealed W33-K/W33-J; shrink site `0043d96c` |
| **Verdict** | **accept** |

---

## 1. Purpose

Erase absolute ring range `[erase_from, erase_to)` under thiscall:

1. `prefix = erase_from_i - begin`; `erase_cnt = erase_to_i - erase_from_i`.
2. If `prefix < suffix` → reverse pack (`0043ebb0`) then advance `begin` (wrap at `capacity*4`) and shrink `size`.
3. Else → forward pack (`0043ec50`) then size-only shrink (`begin=0` when emptied).
4. Write out-iterator `{this, begin+prefix}`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043df90_FUN_0043df90.md` (+ 2026-07-29 W34-L append) |
| Annotated | `docs/reconstruction/raw/aa_0043df90_FUN_0043df90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_EraseRange_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043df90.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043df90_FUN_0043df90.md` |
| Named record | `docs/reconstruction/functions/aa_0043df90_GuardedVector_EraseRange_Thiscall.md` |
| Live | decompile ≡ raw CF; full 238 B hex; `C2 14 00`; `MOV ESI,ECX` |
| Context | twin W27-C EraseRange; parent Resize_Thiscall W33-L; callees W33-K/J |

---

## 3. Signature (sealed)

```c
// ECX=container; stdcall 5 stack args; RET 0x14
void GuardedVector_EraseRange_Thiscall(
    GuardedVectorHeader* container /*ECX*/,
    GuardedVectorIteratorPair* out,
    uint32_t erase_from_c, int erase_from_i,
    uint32_t erase_to_c,   int erase_to_i);
```

| Slot | Source | Conf |
|---|---|---|
| container | **ECX** (`MOV ESI,ECX`) | **High** |
| out | Stack[+4] | **High** |
| erase_from / erase_to | Stack[+0xc]/[+0x14] | **High** |
| cleanup | `RET 0x14` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
begin = [ESI+0xc]; size = [ESI+0x10]
prefix = from_i - begin
erase_cnt = to_i - from_i
suffix = (size+begin) - to_i
if prefix < suffix:
  CALL 0043ebb0  // RingAssignBackwardChecked
  loop erase_cnt: begin++ (wrap capacity*4), size--
else:
  CALL 0043ec50  // RingAssignForward
  loop erase_cnt: size-- (begin=0 if empty)
out = {ESI, begin+prefix}; RET 0x14
```

| Stage | Match | Conf |
|---|---|---|
| Shorter-side branch | **Yes** | **High** |
| begin wrap `capacity*4` | **Yes** (`ADD EBX,EBX`×2) | **High** |
| Callee rel32 → ebb0 / ec50 | **Yes** | **High** |
| RET 0x14 / ECX this | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 238 B hex in raw W34-L append. Epilogue:

```
8B 4E 0C  8B 44 24 24  03 4C 24 10  5F  89 30  5E  5D  89 48 04  5B  83 C4 10  C2 14 00
```

Entry: `SUB ESP,10; …; MOV ESI,ECX; MOV EBX,[ESI+0xC]`.

---

## 6. Gaps

- Product/PDB class English.  
- Runtime / bit-exact golden on wrap edges.

**Verdict:** **accept**
