# Review A (reconstruction fidelity): `aa_0043ce10` GuardedVector_PushFront

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ce10` |
| **VA** | `0x0043ce10`–`0x0043ce85` (**118 B**) |
| **Canonical name** | `GuardedVector_PushFront` (**Inferred**) |
| **Ghidra name** | `FUN_0043ce10` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-B) |
| **Counterpart** | `reviews/B_aa_0043ce10_GuardedVector_PushFront.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 118 B) + `analyze_function_complete`; callers `0043cb00`/`0043cf40`; callees `0043c9b0`/`operator_new` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Ring-deque **push_front** of one dword: optional block-map grow, wrap `begin` when 0 → `capacity*4`, lazy 0x10 page alloc, store `*value`, `size++`, commit new `begin`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043ce10_FUN_0043ce10.md` (+ 2026-07-29 W29-B append) |
| Annotated | `docs/reconstruction/raw/aa_0043ce10_FUN_0043ce10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushFront.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ce10.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043ce10_FUN_0043ce10.md` |
| Named record | `docs/reconstruction/functions/aa_0043ce10_GuardedVector_PushFront.md` |
| Live | decompile ≡ raw CF; full body hex; RET 0x4; 6 xrefs |

---

## 3. Signature (sealed)

```c
// EAX=container; stdcall 1 stack formal (value*); RET 0x4
void GuardedVector_PushFront(GuardedVectorHeader* container /*EAX*/,
                             const uint32_t* value /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| container | **EAX** (`MOV EBX,EAX` entry) | **High** |
| value* | Stack[+4] after ret (`[ESP+0xC]` post-pops) | **High** |
| cleanup | `RET 0x4` | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if (begin & 3)==0 && capacity <= (size+4)>>2:
  GrowBlockMap(1)   // EBX=container
begin = [+0xc]; if begin==0: begin = capacity*4
new_begin = begin - 1
page = new_begin >> 2
if pages[page]==0: pages[page] = new(0x10)
*slot = *value
size++; begin = new_begin
```

| Stage | Match | Conf |
|---|---|---|
| Map-grow gate (align + capacity) | **Yes** | **High** |
| begin==0 → capacity*4 wrap | **Yes** | **High** |
| Page alloc 0x10 + dword store | **Yes** | **High** |
| size++ and begin commit | **Yes** | **High** |
| Nested GrowBlockMap free | shape sealed W28-B | **High** (callee) |

---

## 5. Machine bytes (`read_memory`)

Entry:

```
53 8B D8 F6 43 0C 03 57 75 15 8B 43 10 83 C0 04 C1 E8 02 39 43 08 77 07 6A 01 E8 …
```

Epilogue:

```
83 43 10 01       ; ADD [EBX+0x10], 1
89 7B 0C          ; MOV [EBX+0x0C], EDI
5F 5B C2 04 00    ; POP EDI; POP EBX; RET 4
```

Body length **118 B**. Full hex in raw W29-B append.

---

## 6. Gaps

- Product/PDB class English (`GuardedVector_*` structural; retail map overflow says `deque<T> too long`).
- Element type beyond dword POD copy.
- Runtime / bit-exact golden under live allocators.
- `operator_new` null path: body still increments size/begin after null store skip (matches bytes).

---

## 7. Verdict

ABI, front polarity, wrap, page map, and dword store sealed from live decompile + full-body `read_memory` + exclusive grow/assign callers → **accept-with-gaps**.
