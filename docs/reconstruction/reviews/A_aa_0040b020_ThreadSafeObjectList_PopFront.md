# Review A (reconstruction fidelity): `aa_0040b020` ThreadSafeObjectList_PopFront

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b020` |
| **VA** | `0x0040b020`–`0x0040b136` |
| **Canonical name** | `ThreadSafeObjectList_PopFront` |
| **Ghidra name** | `FUN_0040b020` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W24-S) |
| **Counterpart** | `reviews/B_aa_0040b020_ThreadSafeObjectList_PopFront.md` |
| **System** | client::util / lock-protected object list |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; push `FUN_004024d0`; dtor `FUN_004bcbf0`; skill `FUN_0058c850` |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC-style **thread-safe pop-front** for a singly-linked object list protected by **two critical sections**:

1. If `head == 0` → return **0** (no lock).
2. `EnterCriticalSection(list+0x28)` (outer).
3. If `count < 2` → also enter inner CS at `list+0x10`.
4. Capture `payload = head[+4]`; advance `head = head[+8]`; if empty clear tail `+8`.
5. Clear node payload; **`(*vtbl)(node, 1)`** destroy.
6. Leave CS(s); **`InterlockedDecrement(count@+0xC)`**; return payload.

Used as the iterator primitive for multi-target skill hits, mission notify cleanup, and list dtor drain.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0040b020_FUN_0040b020.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_0040b020_FUN_0040b020.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ThreadSafeObjectList_PopFront.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040b020.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040b020_ThreadSafeObjectList_PopFront.md` |
| Push twin | `FUN_004024d0` (new 0xC node, append) |
| Dtor twin | `FUN_004bcbf0` (drain + DeleteCriticalSection ×2) |
| Live | decompile ≡ raw; body 278 B; epilogue `C3` |

---

## 3. Signature (sealed)

```c
// ECX = list*; no stack formals; return payload*; RET
void *ThreadSafeObjectList_PopFront(ThreadSafeObjectList *list);
```

| Formal | Source | Conf |
|---|---|---|
| list | ECX → ESI | **High** |
| return | payload @ node+4, or 0 | **High** |
| cleanup | `RET` (no stack args) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if head==0: return 0
EnterCS(+0x28)
node=head; takeInner=(count<2)
if takeInner: EnterCS(+0x10)
payload=node[+4]
head=node[+8]; if !head: tail=0
node[+4]=0; node.dtor(1)
if takeInner: LeaveCS(+0x10)
LeaveCS(+0x28)
InterlockedDecrement(+0xC)
return payload
```

| Stage | Match | Conf |
|---|---|---|
| Empty early return | **Yes** | **High** |
| Dual CS policy | **Yes** | **High** |
| Head/tail advance | **Yes** | **High** |
| Node dtor flag 1 | **Yes** | **High** |
| Interlocked count | **Yes** | **High** |
| Push/dtor twins consistent | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Body @ `0x0040b020`: SEH `55 8B EC 6A FF 68 90 C5 9B 00`; `mov esi,ecx`; CS IAT calls; `push 1` before node virtual; empty path `xor eax,eax` + `ret`.

---

## 6. Gaps

- Product English type name (Inferred structural only).
- Nested-CS threshold rationale vs push’s `count < 4` outer policy — English residual; bytes sealed.
- Runtime / bit-exact.

**Verdict:** **accept** — CF/ABI/list+node layout sealed; only naming/English residual (not CF gaps).
