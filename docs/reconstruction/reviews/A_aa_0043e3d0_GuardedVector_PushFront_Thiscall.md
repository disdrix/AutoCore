# Review A (reconstruction fidelity): `aa_0043e3d0` GuardedVector_PushFront_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e3d0` |
| **VA** | `0x0043e3d0`–`0x0043e447` (**120 B**) |
| **Canonical name** | `GuardedVector_PushFront_Thiscall` (**Inferred**) |
| **Ghidra name** | `FUN_0043e3d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-I) |
| **Counterpart** | `reviews/B_aa_0043e3d0_GuardedVector_PushFront_Thiscall.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 120 B) + callers/callees; 5 callers; callees `0043d990`/`operator_new`/`0043d420` |
| **Verdict** | **accept** |

---

## 1. Purpose

Ring-deque **push_front** of one dword under **thiscall**: optional block-map grow, wrap `begin==0` through `capacity*4`, lazy 0x10 page alloc, store via `FUN_0043d420`, `size++` and `begin=new_begin`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043e3d0_FUN_0043e3d0.md` (+ 2026-07-29 W31-I append) |
| Annotated | `docs/reconstruction/raw/aa_0043e3d0_FUN_0043e3d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushFront_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e3d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043e3d0_FUN_0043e3d0.md` |
| Named record | `docs/reconstruction/functions/aa_0043e3d0_GuardedVector_PushFront_Thiscall.md` |
| Live | decompile ≡ raw CF; full body hex; RET 0x4; 5 callers |

---

## 3. Signature (sealed)

```c
// ECX=container; stdcall 1 stack formal (value*); RET 0x4
void GuardedVector_PushFront_Thiscall(GuardedVectorHeader* container /*ECX*/,
                                      const uint32_t* value /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| container | **ECX** (`MOV ESI,ECX` entry) | **High** |
| value* | Stack[+4] after ret | **High** |
| cleanup | `RET 0x4` | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if (begin&3)==0 && capacity <= (size+4)>>2:
  GrowBlockMap_Thiscall(1)   // ECX preserved from entry
if begin==0: begin = capacity*4
new_begin = begin - 1
page = new_begin >> 2
if pages[page]==0: pages[page] = new(0x10)
FUN_0043d420(slot, value*)
size++; begin = new_begin
```

| Stage | Match | Conf |
|---|---|---|
| Map-grow gate (begin align + capacity) | **Yes** | **High** |
| begin==0 wrap through capacity*4 | **Yes** | **High** |
| Page alloc 0x10 + assign helper | **Yes** | **High** |
| size++ and begin commit | **Yes** | **High** |
| Nested GrowBlockMap_Thiscall | sealed W30-A | **High** (callee) |

---

## 5. Machine bytes (`read_memory`)

Entry: `PUSH EBX; PUSH ESI; MOV ESI,ECX`.  
Grow: `TEST [ESI+0xC],3`; capacity gate; `PUSH 1; CALL FUN_0043d990` (**ECX not reloaded** — still entry this).  
Front: `if begin==0: begin=capacity*4`; `DEC`; page `>>2`; `new(0x10)?`; `FUN_0043d420`.  
Epilogue: `ADD [ESI+0x10],1; MOV [ESI+0xC],EDI; POP*; RET 4`.  
Full 120 B hex sealed in raw W31-I append. Live decompile 2026-07-29 ≡ raw 2026-07-23.

---

## 6. Gaps (non-blocking)

- Product/PDB class English.  
- Runtime / bit-exact.  
- Null-`operator_new` still advances size/begin (bytes).  
- Element type beyond dword POD.

---

## 7. Verdict

Fidelity pass seals ABI, CF, layout, and callees. Product residual only → **accept**.
