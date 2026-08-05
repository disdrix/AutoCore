# Review A (reconstruction fidelity): `aa_0043e970` GuardedVector_PushBack_Stride2_U32x2

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e970` |
| **VA** | `0x0043e970`–`0x0043e9dd` (**110 B**) |
| **Canonical name** | `GuardedVector_PushBack_Stride2_U32x2` (**Inferred**) |
| **Ghidra name** | `FUN_0043e970` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-J) |
| **Counterpart** | `reviews/B_aa_0043e970_GuardedVector_PushBack_Stride2_U32x2.md` |
| **System** | STL / guarded ring-deque (stride-2) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 110 B + store helper) + `get_function_by_address` + `analyze_function_complete`; 2 callers / 2 xrefs; callees GrowBlockMap_Stride2 / new / Pod8 |
| **Verdict** | **accept** |

---

## 1. Purpose

Ring-deque **push_back** of one 8-byte (two-dword) POD: optional stride-2 block-map grow, write at absolute `begin+size` with page wrap, lazy 0x10 page alloc, null-safe Pod8 store, `size++` only (`begin` unchanged).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043e970_FUN_0043e970.md` (+ 2026-07-29 W31-J append) |
| Annotated | `docs/reconstruction/raw/aa_0043e970_FUN_0043e970.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushBack_Stride2_U32x2.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e970.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043e970_FUN_0043e970.md` |
| Named record | `docs/reconstruction/functions/aa_0043e970_GuardedVector_PushBack_Stride2_U32x2.md` |
| Live | decompile ≡ raw CF; full body hex; RET 0x4; store helper hex |

---

## 3. Signature (sealed)

```c
// EAX=container; stdcall 1 stack formal (value*); RET 0x4
void GuardedVector_PushBack_Stride2_U32x2(GuardedVectorHeader* container /*EAX*/,
                                          const PodU32x2* value /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| container | **EAX** (`MOV EBX,EAX` entry) | **High** |
| value* | Stack; loaded as ECX via `[ESP+0x10]` pre-store | **High** |
| cleanup | `RET 0x4` | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if ((begin+size)&1)==0 && capacity <= (size+2)>>1:
  GrowBlockMap_Stride2(1)   // EBX=container
abs = begin + size
page = abs >> 1; if capacity <= page: page -= capacity
if pages[page]==0: pages[page] = new(0x10)
slot = pages[page] + (abs&1)*8
Pod8_CopyIfNonNull(slot, value)  // FUN_0043ece0
size++   // begin unchanged
```

| Stage | Match | Conf |
|---|---|---|
| Map-grow gate (even end + capacity) | **Yes** | **High** |
| Page wrap by capacity (`>>1`) | **Yes** | **High** |
| Page alloc 0x10 + LEA *8 | **Yes** | **High** |
| 8-byte store helper | **Yes** | **High** |
| size++ only (no begin write) | **Yes** | **High** |
| Nested GrowBlockMap free | sealed W30-A | **High** (callee) |

---

## 5. Machine bytes (`read_memory`)

Entry / grow:

```
53 8B D8 8B 43 10 8B 4B 0C 03 C8 F6 C1 01 56 57 75 11 83 C0 02 D1 E8 39 43 08 77 07 6A 01 E8 CD 00 00 00
```

Slot + store + epilogue:

```
83 E6 01 8D 04 F0 E8 0C 03 00 00   ; AND ESI,1; LEA EAX,[EAX+ESI*8]; CALL 0043ece0
83 43 10 01 5F 5E 5B C2 04 00       ; size++; pops; RET 4
```

Body length **110 B**. Full hex in raw W31-J append.  
Next function: sibling push `FUN_0043e9e0` @ `0x0043e9e0` after `CC` pad.

---

## 6. Gaps

- Product/PDB class / element English.
- Runtime / bit-exact under multi-caller parents (`00971280`, `00972140`).
- `operator_new` null: store skipped (`TEST EAX`) but size still increments (matches helper bytes).

---

## 7. Verdict

ABI, back polarity, stride-2 page math, and 8-byte store sealed from live decompile + full-body `read_memory` + twin store-helper seal → **accept**.
