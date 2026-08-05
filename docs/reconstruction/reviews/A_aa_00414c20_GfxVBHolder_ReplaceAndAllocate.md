# Review A (reconstruction fidelity): `aa_00414c20` GfxVBHolder_ReplaceAndAllocate

| Field | Value |
|---|---|
| **Stable ID** | `aa_00414c20` |
| **VA** | `0x00414c20` |
| **Body** | `0x00414c20`–`0x00414cc0` (161 bytes) |
| **Canonical name** | `GfxVBHolder_ReplaceAndAllocate` |
| **Prior scaffold** | `FUN_00414c20` |
| **Review date** | `2026-07-29` (W21-L dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00414c20_GfxVBHolder_ReplaceAndAllocate.md` |
| **System** | graphics / gfxVertexBufferImpl |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Replace the **vertex buffer impl*** at **`holder+4`** with a **pool-constructed** gfxVertexBufferImpl, then **allocate** GPU/system VB resources via `FUN_0099a8e0`. Shared by terrain, tac-arc, geometry piece, and many mesh builders.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00414c20` |
| Bytes | `read_memory` 161 B @ entry — SEH, pool imm, ctor, refcount, allocate, `ret 0x10` |
| Bounds | `get_function_by_address` body `00414c20`–`00414cc0` |
| Callees | `get_function_callees` → `00414cd0`, `00999960`, `0099a8e0` |
| Callers | `get_function_callers` (40+) |
| Nested | decompile `00414cd0`, `00999960`, `0099a8e0` (allocate plate) |
| Raw / clean | `aa_00414c20_*`, `GfxVBHolder_ReplaceAndAllocate.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` + 4 stack args + `ret 0x10` | **Confirmed** | epilogue `c2 10 00` |
| Pool via `DAT_00d218e0` | **Confirmed** | `B9 E0 18 D2 00` then `call 00414cd0` |
| Ctor `00999960` / vtbl `00aa161c` | **Confirmed** | decompile ctor + `read_memory` vtbl |
| Refcount +4; first-ref vtbl+4; release vtbl+8 | **Confirmed** | decompile ≡ bytes |
| Store new at `holder+4` before allocate | **Confirmed** | `89 77 04` then call allocate |
| Allocate = `FUN_0099a8e0` | **Confirmed** | rel32 + plate in callee |
| Return EAX = allocate status | **Confirmed** | no EAX clobber after call; callers `iVar < 0` |
| Decompiler `void` return | **Confirmed residual** | understates |
| Formal product names for 4 args | **Inferred** | terrain count/0x20/0 pattern |
| Product English symbol | **Inferred** | role-sealed |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH install | Yes |
| Freelist pop | Yes (global head forced in bytes) |
| Null → skip ctor | Yes |
| Ctor on node | Yes |
| AddRef-style + first vfunc | Yes |
| Release old slot | Yes |
| holder+4 = new | Yes |
| Allocate + return status | Yes (clean returns int) |

---

## 5. Gaps / open

1. Product names of four stack formals and holder C++ type.
2. Full freelist slab layout (`FUN_00414cd0` owned elsewhere).
3. Runtime / bit-exact / differential.
4. Whether allocate is invoked with null `this` when pool fails (bytes still call with ESI=0) — caller must handle; not expanded here.

**Verdict:** **accept**
