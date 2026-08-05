# Review A (reconstruction fidelity): `aa_0043c830` GuardedVector_PushBack

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c830` |
| **VA** | `0x0043c830`–`0x0043c8a2` (**115 B**) |
| **Canonical name** | `GuardedVector_PushBack` (**Inferred**) |
| **Ghidra name** | `FUN_0043c830` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-B) |
| **Counterpart** | `reviews/B_aa_0043c830_GuardedVector_PushBack.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 115 B) + `analyze_function_complete`; 5 callers / 10 xrefs; callees `0043c9b0`/`operator_new` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Ring-deque **push_back** of one dword: optional block-map grow, write at absolute `begin+size` with page wrap, lazy 0x10 page alloc, store `*value`, `size++` only (`begin` unchanged).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043c830_FUN_0043c830.md` (+ 2026-07-29 W29-B append) |
| Annotated | `docs/reconstruction/raw/aa_0043c830_FUN_0043c830.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushBack.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c830.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043c830_FUN_0043c830.md` |
| Named record | `docs/reconstruction/functions/aa_0043c830_GuardedVector_PushBack.md` |
| Live | decompile ≡ raw CF; full body hex; RET 0x4; 10 xrefs |

---

## 3. Signature (sealed)

```c
// EAX=container; stdcall 1 stack formal (value*); RET 0x4
void GuardedVector_PushBack(GuardedVectorHeader* container /*EAX*/,
                            const uint32_t* value /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| container | **EAX** (`MOV EBX,EAX` entry) | **High** |
| value* | Stack[+4] after ret (`[ESP+8]` post-pops) | **High** |
| cleanup | `RET 0x4` | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if ((begin+size)&3)==0 && capacity <= (size+4)>>2:
  GrowBlockMap(1)   // EBX=container
abs = begin + size
page = abs >> 2; if capacity <= page: page -= capacity
if pages[page]==0: pages[page] = new(0x10)
*slot = *value
size++   // begin unchanged
```

| Stage | Match | Conf |
|---|---|---|
| Map-grow gate (end align + capacity) | **Yes** | **High** |
| Page wrap by capacity | **Yes** | **High** |
| Page alloc 0x10 + dword store | **Yes** | **High** |
| size++ only (no begin write) | **Yes** | **High** |
| Nested GrowBlockMap free | shape sealed W28-B | **High** (callee) |

---

## 5. Machine bytes (`read_memory`)

Entry:

```
53 8B D8 8B 43 10 8B 4B 0C 03 C8 F6 C1 03 75 12 83 C0 04 C1 E8 02 39 43 08 77 07 6A 01 E8 …
```

Epilogue:

```
83 43 10 01       ; ADD [EBX+0x10], 1
5B C2 04 00       ; POP EBX; RET 4
```

Body length **115 B**. Full hex in raw W29-B append.  
Next function: `FUN_0043c8c0` EraseRange @ `0x0043c8c0` after `CC` pad.

---

## 6. Gaps

- Product/PDB class English.
- Element type beyond dword POD copy.
- Runtime / bit-exact under multi-caller parents (including high-VA `007b75b0` / `009668a0`).
- `operator_new` null: store skipped but size still increments (matches bytes).

---

## 7. Verdict

ABI, back polarity, page wrap, and dword store sealed from live decompile + full-body `read_memory` + multi-caller graph → **accept-with-gaps**.
