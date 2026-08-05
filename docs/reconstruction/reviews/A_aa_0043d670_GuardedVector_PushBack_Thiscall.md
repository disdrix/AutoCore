# Review A (reconstruction fidelity): `aa_0043d670` GuardedVector_PushBack_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d670` |
| **VA** | `0x0043d670`–`0x0043d6e6` (**119 B**) |
| **Canonical name** | `GuardedVector_PushBack_Thiscall` (**Inferred**) |
| **Ghidra name** | `FUN_0043d670` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-I) |
| **Counterpart** | `reviews/B_aa_0043d670_GuardedVector_PushBack_Thiscall.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 119 B) + callers/callees; 16 callers; callees `0043d990`/`operator_new`/`0043d420` |
| **Verdict** | **accept** |

---

## 1. Purpose

Ring-deque **push_back** of one dword under **thiscall**: optional block-map grow, write at absolute `begin+size` with page wrap, lazy 0x10 page alloc, store via `FUN_0043d420`, `size++` only (`begin` unchanged).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043d670_FUN_0043d670.md` (+ 2026-07-29 W31-I append) |
| Annotated | `docs/reconstruction/raw/aa_0043d670_FUN_0043d670.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushBack_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d670.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043d670_FUN_0043d670.md` |
| Named record | `docs/reconstruction/functions/aa_0043d670_GuardedVector_PushBack_Thiscall.md` |
| Live | decompile ≡ raw CF; full body hex; RET 0x4; 16 callers |

---

## 3. Signature (sealed)

```c
// ECX=container; stdcall 1 stack formal (value*); RET 0x4
void GuardedVector_PushBack_Thiscall(GuardedVectorHeader* container /*ECX*/,
                                     const uint32_t* value /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| container | **ECX** (`MOV ESI,ECX` entry) | **High** |
| value* | Stack[+4] after ret (`[ESP+0x10]` at assign after 3 pushes) | **High** |
| cleanup | `RET 0x4` | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if ((begin+size)&3)==0 && capacity <= (size+4)>>2:
  GrowBlockMap_Thiscall(1)   // ECX=container (reload ESI)
abs = begin + size
page = abs >> 2; if capacity <= page: page -= capacity
if pages[page]==0: pages[page] = new(0x10)
FUN_0043d420(slot, value*)
size++   // begin unchanged
```

| Stage | Match | Conf |
|---|---|---|
| Map-grow gate (end align + capacity) | **Yes** | **High** |
| Page wrap by capacity | **Yes** | **High** |
| Page alloc 0x10 + assign helper | **Yes** | **High** |
| size++ only (no begin write) | **Yes** | **High** |
| Nested GrowBlockMap_Thiscall | sealed W30-A | **High** (callee) |

---

## 5. Machine bytes (`read_memory`)

Entry: `PUSH EBX; PUSH ESI; MOV ESI,ECX` — true thiscall.  
Grow: `PUSH 1; MOV ECX,ESI; CALL FUN_0043d990`.  
Store: stack value* + `CALL FUN_0043d420`.  
Epilogue: `ADD [ESI+0x10],1; ADD ESP,8; POP EDI; POP ESI; POP EBX; RET 4`.  
Full 119 B hex sealed in raw W31-I append. Live decompile 2026-07-29 ≡ raw 2026-07-23.

---

## 6. Gaps (non-blocking)

- Product/PDB class English.  
- Runtime / bit-exact.  
- Null-`operator_new` still advances size (bytes).  
- Element type beyond dword POD.

---

## 7. Verdict

Fidelity pass seals ABI, CF, layout, and callees. Product residual only → **accept**.
