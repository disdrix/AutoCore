# Review A (reconstruction fidelity): `aa_00507290` Host_ActionList_Push

| Field | Value |
|---|---|
| **Stable ID** | `aa_00507290` |
| **VA** | `0x00507290` |
| **Body** | `0x00507290`–`0x005072c5` |
| **Canonical name** | `Host_ActionList_Push` |
| **Former name** | `FUN_00507290` |
| **Review date** | `2026-07-29` (W19-O) |
| **Reviewer role** | Reconstruction fidelity (host action pointer vector push) |
| **Counterpart** | `reviews/B_aa_00507290_Host_ActionList_Push.md` |
| **System** | physics / action host list |
| **Verdict** | **accept** |

---

## 1. Purpose

Append one pointer onto a growable **pointer vector** rooted at **`host+0x94`**. Used by physics action base construction (`Phys_ActionBase_ctor` and siblings) to register the new action with its host object.

---

## 2. Inspected evidence

| Source | Detail |
|---|---|
| Live Ghidra | `decompile_function` `0x00507290`; grow callee `0x005b3370`; xrefs from `0x00636370`, `0x00636220`, `0x0066e660` |
| `read_memory` | full body @ `0x00507290` (54B); call-site windows @ `0x00636390`, `0x00636230`, `0x0066e680` |
| Raw | `docs/reconstruction/raw/aa_00507290_FUN_00507290.md` (+ 2026-07-29 re-verify) |
| Annotated | `docs/reconstruction/raw/aa_00507290_FUN_00507290.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_ActionList_Push.cpp` |
| Peer dual | `Phys_ActionBase_ctor` (`aa_00636370`) — already seals ECX=host |

**Tools:** decompile + read_memory (+ xrefs). **No** `disassemble_bytes`. **No** Launcher.

---

## 3. Signature

```c
// MSVC __thiscall: ECX = host; stack = void* item; RET 4
void __thiscall Host_ActionList_Push(void *host, void *itemPtr);
```

| Claim | Evidence | Conf |
|---|---|---|
| ECX = host | body `lea esi,[ecx+0x94]` | **High** |
| One stack arg | `mov eax,[esp+8]` after push esi; `ret 4` | **High** |
| Void return | no EAX setup | **High** |

---

## 4. Control flow (sealed)

```
cap = *(host+0x9c) & 0x7fffffff
if *(host+0x98) == cap:
  FUN_005b3370(&*(host+0x94), 4)   // cdecl grow, elem size 4
data = *(host+0x94)
data[count] = item
count++
ret 4
```

### Vector layout

| Off | Field |
|---:|---|
| +0x94 | `void**` data |
| +0x98 | `int` count |
| +0x9c | `uint` capacity (+ optional high bit) |

---

## 5. Call-site ABI (critical)

Decompiler at callers often prints `FUN_00507290(action)` implying self-as-this. **Machine falsifies:**

| Site | Bytes pattern | ECX |
|---|---|---|
| `0x006363a1` | host already in ECX; `push esi` (action) | **host** |
| `0x00636246` | `mov ecx,[edi+4]`; `push esi` | **host** |
| `0x0066e698` | `mov ecx,[esi+0x18]`; `push esi` | **host** |
| `0x0066e6ac` | `mov ecx,[esi+0x1c]`; `push esi` | **host** (2nd) |

This unit does **not** addref; callers bump `*(u16*)(host+6)` themselves when required.

---

## 6. Confidence

| Area | Level |
|---|---|
| CF + bytes | **High** |
| Offsets + grow | **High** |
| Caller ECX=host | **High** |
| Product host type English | **Low** |
| Capacity high-bit | **Medium** |

---

## 7. Gaps

1. Product C++ host type across callers.
2. Capacity high-bit allocator semantics.
3. List vs world-register path distinction (sibling `FUN_0055fe50` different).
4. Runtime / bit-exact open.

**Verdict:** **accept** (behavior fully sealed; naming descriptive; residual = product type English only).
