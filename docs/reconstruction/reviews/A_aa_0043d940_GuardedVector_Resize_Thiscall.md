# Review A (reconstruction fidelity): `aa_0043d940` GuardedVector_Resize_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d940` |
| **VA** | `0x0043d940`–`0x0043d989` (**74 B**) |
| **Canonical name** | `GuardedVector_Resize_Thiscall` (**Inferred**) |
| **Ghidra name** | `FUN_0043d940` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-L) |
| **Counterpart** | `reviews/B_aa_0043d940_GuardedVector_Resize_Thiscall.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 74 B) + callers/callees; sole caller `0043d650`; callees e080/df90 |
| **Verdict** | **accept** |

---

## 1. Purpose

Resize ring container to absolute `new_size` under thiscall:

1. Read `size` from `[ECX+0x10]`.
2. If `size < new_size` → grow: `GuardedVector_InsertN_Thiscall` at `begin+size` with `N = new_size-size` and fill* to stack fill slot.
3. Else if `new_size < size` → shrink: `FUN_0043df90` erase `[begin+new_size, begin+size)`.
4. Else no-op.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043d940_FUN_0043d940.md` (+ 2026-07-29 W33-L append) |
| Annotated | `docs/reconstruction/raw/aa_0043d940_FUN_0043d940.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_Resize_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d940.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043d940_FUN_0043d940.md` |
| Named record | `docs/reconstruction/functions/aa_0043d940_GuardedVector_Resize_Thiscall.md` |
| Live | decompile ≡ raw CF; full 74 B hex; both epilogues `C2 08 00` |
| Context | twin W28-D Resize; grow callee sealed W32-F InsertN_Thiscall |

---

## 3. Signature (sealed)

```c
// ECX=container; stack (new_size, fill); RET 0x8
void GuardedVector_Resize_Thiscall(GuardedVectorHeader* container /*ECX*/,
                                   uint32_t new_size,
                                   uint32_t fill);
```

| Slot | Source | Conf |
|---|---|---|
| container | **ECX** (`MOV ESI,[ECX+0x10]`) | **High** |
| new_size | Stack[+4] (`MOV EAX,[ESP+4]`) | **High** |
| fill | Stack[+8] (grow LEA to slot; RET 8) | **High** |
| cleanup | `RET 0x8` both arms | **High** |

Decompiler drops fill formal — **bytes win**.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
size = [ECX+0x10]
if size < new_size:
  InsertN_Thiscall(ECX, ECX, begin+size, new_size-size, &fill)
  RET 8
if new_size < size:          // via JBE then JNB equal-skip
  FUN_0043df90(out, ECX, begin+new, ECX, begin+old)
RET 8
```

| Stage | Match | Conf |
|---|---|---|
| Grow/shrink/equal trichotomy | **Yes** | **High** |
| Grow → `0043e080` end-insert | **Yes** (rel32) | **High** |
| Shrink → `0043df90` range | **Yes** (rel32) | **High** |
| RET 8 / ECX this | **Yes** | **High** |
| Nested erase free | residual | **Medium** |

---

## 5. Machine bytes (`read_memory`)

Full 74 B hex:

```
8b44240483ec08568b71103bc6761d8b510c578d7c2418572bc65003d65251e81c0700005f5e83c408c2080073158b510c03f2565103d052518d44241450e80d0600005e83c408c20800
```

Entry: `MOV EAX,[ESP+4]; SUB ESP,8; PUSH ESI; MOV ESI,[ECX+0x10]`.  
Grow epilogue: `POP EDI; POP ESI; ADD ESP,8; RET 8`.  
Shrink epilogue: `POP ESI; ADD ESP,8; RET 8`.  
Callees: grow → `0043e080`, shrink → `0043df90`.

---

## 6. Gaps (non-blocking)

- Product/PDB English.  
- Nested `FUN_0043df90` free (thiscall erase twin of W27-C).  
- Runtime / bit-exact.

---

## 7. Verdict

Fidelity pass seals ABI (thiscall + RET 8 + fill), trichotomy, and grow callee. Nested shrink free + product residual only → **accept**.
