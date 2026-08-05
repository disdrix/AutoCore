# Review A (reconstruction fidelity): `aa_00566f00` CNDDoubleList_InsertTail_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00566f00` |
| **VA** | `0x00566f00` |
| **Canonical name** | `CNDDoubleList_InsertTail_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw bytes / decompile) |
| **Counterpart** | `reviews/B_aa_00566f00_CNDDoubleList_InsertTail_Inferred.md` |
| **Residual scratch** | `reviews/a_00566f00.md` |
| **System** | `inventory-transfer` (primary consumer) + generic list utility |
| **Dual status** | **Present** (byte-sealed list append) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Append a payload pointer** to a critical-section protected doubly-linked list (CNDDoubleList family layout). On inventory place, the host is the embedded item list at **`InventoryGrid+0x2c`** and the payload is the **item object**.

```text
CNDDoubleList_InsertTail_Inferred(list, payload):
  EnterCriticalSection(list+4)
  if list.traversalLock (+0x28):  // non-zero
    VOG_DEBUG_STOP; throw E_ACCESSDENIED (0x80070005)
  node = list.vtbl[1](0)          // vtbl+4 — allocate node
  if node == NULL:
    throw E_OUTOFMEMORY (0x8007000e)
  if list.head (+0x1c) == NULL:
    list.head = node
  node.prev (+0xc) = list.tail (+0x20)
  if list.tail != NULL:
    list.tail.next (+0x8) = node
  node.payload (+0x4) = payload
  list.count (+0x24)++
  list.tail = node
  LeaveCriticalSection(list+4)
  return 0
```

**Calling convention:** MSVC `__thiscall` — list in `ECX`. Callee `RET 4` → **one** stack dword (payload).

| Slot | Role | Evidence |
|------|------|----------|
| `this` | list object | Prologue `ESI=ECX`; CS `LEA EDI,[ESI+4]` |
| stack0 | payload (`ItemObject*` at place) | `MOV EDX,[EBP+8]` → `[node+4]` |

**Returns:** `EAX = 0` on success. Fail paths throw (`_CxxThrowException`) and do not return.

**Side effects:** allocates list node via vtbl; links into head/tail; increments count; CS enter/leave. Does **not** stamp inventory cells (that is `PlaceItemFootprint`).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00566f00_FUN_00566f00.md` |
| Annotated | `docs/reconstruction/raw/aa_00566f00_FUN_00566f00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDDoubleList_InsertTail_Inferred.cpp` |
| Prior scaffold | `reconstructed-exact/FUN_00566f00.cpp`, `Named_VOG_DEBUG_STOP_00566f00.cpp` |
| Function record | `docs/reconstruction/functions/aa_00566f00_CNDDoubleList_InsertTail_Inferred.md` |
| Residual | `docs/reconstruction/reviews/a_00566f00.md` |
| Live decompile | Ghidra `decompile_function` @ `0x00566f00` |
| Live bytes | Ghidra `read_memory` `0x00566f00` len 128 + `0x00566f70` len 96 |
| Place site | `read_memory` `0x005717f0` — `LEA ECX,[EDI+0x2c]; CALL 0x00566f00` |
| Sibling list ops | `FUN_004022a0` IterateNext; `FUN_00415c00` Contains; `aa_004e2600` CNDDoubleList remove |
| Callers (Ghidra) | `0x00571620` Place, `0x00572730`, spawn `0x00564f60`/`0x00564290`, `0x00563a30`/`0x00563a70` |

**Not performed:** `disassemble_bytes`, Launcher, CE live list dump, bit-exact, PDB method string.

---

## 3. Byte body (sealed)

### Prologue / lock / alloc

```text
55 8B EC                 push ebp; mov ebp,esp
… SEH frame LAB_009a4bf0 …
8B F1                    mov  esi, ecx              ; this
8D 7E 04                 lea  edi, [esi+4]          ; CS
57                       push edi
FF 15 BC 61 9C 00        call [EnterCriticalSection]
80 7E 28 00              cmp  byte [esi+0x28], 0    ; traversal lock
74 …                     je   alloc
… FUN_007a4480(0,"VOG_DEBUG_STOP"); throw 0x80070005 …
8B 16                    mov  edx, [esi]            ; vtbl
6A 00                    push 0
8B CE                    mov  ecx, esi
FF 52 04                 call dword [edx+4]         ; allocate node
85 C0                    test eax, eax
75 …                     jnz  link
… throw 0x8007000e …
```

### Link / count / unlock / return

```text
83 7E 1C 00              cmp  dword [esi+0x1c], 0   ; head
75 03                    jnz  +3
89 46 1C                 mov  [esi+0x1c], eax       ; head = node if empty
8B 4E 20                 mov  ecx, [esi+0x20]       ; old tail
89 48 0C                 mov  [eax+0xc], ecx        ; node.prev = old tail
8B 4E 20                 mov  ecx, [esi+0x20]
85 C9                    test ecx, ecx
74 03                    jz   +3
89 41 08                 mov  [ecx+0x8], eax        ; old_tail.next = node
8B 55 08                 mov  edx, [ebp+8]          ; payload
89 50 04                 mov  [eax+0x4], edx        ; node.payload
83 46 24 01              add  dword [esi+0x24], 1   ; count++
57                       push edi                   ; CS
89 46 20                 mov  [esi+0x20], eax       ; tail = node
FF 15 B8 61 9C 00        call [LeaveCriticalSection]
33 C0                    xor  eax, eax              ; return 0
… SEH restore; pop edi/esi/ebx …
C2 04 00                 ret  4
```

| Claim | Byte seal |
|-------|-----------|
| `thiscall` list + 1 stack arg | `ESI=ECX`; `RET 4` (`C2 04 00`) |
| CS at `list+4` | `LEA EDI,[ESI+4]` + Enter/Leave IAT |
| Traversal-lock reject at `+0x28` | `CMP BYTE [ESI+0x28],0` then throw `0x80070005` |
| Alloc via vtbl `+4` with arg `0` | `PUSH 0; CALL [EDX+4]` |
| Head `+0x1c`, tail `+0x20`, count `+0x24` | link sequence above |
| Node payload `+4`, next `+8`, prev `+0xc` | stores; matches IterateNext / remove dual |
| Success return `0` | `XOR EAX,EAX` |
| Append (insert at tail) | new becomes `tail`; linked after old tail |

### Place call site (consumer, not owned)

`0x005717f0` post-stamp:

```text
8D 4F 2C     lea  ecx, [edi+0x2c]     ; grid+0x2c
E8 …         call 0x00566f00
83 8E 7C 01 00 00 10   or [esi+0x17c], 0x10
```

Type-4 early place path uses the same `LEA ECX,[EDI+0x2c]; CALL` (prior place dual).

---

## 4. Control flow: clean ≡ bytes / decompile

| Stage | Match |
|---|---|
| SEH + Enter CS(+4) | **Yes** |
| Lock flag → VOG_DEBUG_STOP + throw 0x80070005 | **Yes** |
| vtbl+4(0) allocate; null → throw 0x8007000e | **Yes** |
| Empty head set | **Yes** |
| Doubly-link at tail | **Yes** |
| Payload store; count++; tail update | **Yes** |
| Leave CS; return 0; RET 4 | **Yes** |

### Corrections vs scaffold

| Topic | Correction |
|-------|------------|
| Name `FUN_00566f00` / `Named_VOG_DEBUG_STOP` | Role = **list insert tail**; string only on locked assert |
| System `unknown` | Primary inventory consumer = place → `grid+0x2c`; family = CNDDoubleList |
| `param_2` opaque | Payload pointer (item at place) |
| “Insert after Place footprint” only | Also used by spawn / grid-repack callers — **generic** list method |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Append-at-tail CF | **Confirmed** | Full link bytes |
| List layout CS/head/tail/count/lock | **Confirmed** | Matches `004e2600` / IterateNext |
| Node payload/next/prev | **Confirmed** | Bytes + sibling iterate |
| Place uses `this=grid+0x2c` | **Confirmed** | `8D 4F 2C` |
| Success `EAX=0` | **Confirmed** | `XOR EAX,EAX` |
| Traversal lock throws E_ACCESSDENIED | **Confirmed** | constant + flag |
| Alloc OOM throws E_OUTOFMEMORY | **Confirmed** | constant |
| Product method mangling | **Open** | `_Inferred` required |
| Product class exact for inventory embed | **High** family / **Open** template arg |
| Node fields zeroed by allocator | **High** (convention); not proven in this unit |
| Runtime multi-item list dump | **Open** | |
| Bit-exact | **Open** | matrix policy |

---

## 6. Gaps / open (do not block accept-with-gaps)

1. **PDB / demangled method name** — insert vs Add vs PushBack unknown.
2. **Exact CNDDoubleList template** for inventory (`PAV…` item type) — layout sealed; RTTI string for this embed not read here.
3. **vtbl+4 implementor** — allocate-node identity open (role sealed).
4. **Runtime** — no CE walk of head→tail after place.
5. **Duplicate insert** — no de-dupe; place relies on Contains / type-4 paths separately.

---

## 7. Verdict

### **accept-with-gaps**

Byte-sealed **CNDDoubleList-family insert-at-tail**. Inventory place post-stamp (and type-4 light bind) call it with `this = grid+0x2c`. Not cell stamping. Method product name remains `_Inferred`.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw + bytes | **Pass** |
| Head/tail/count/link offsets sealed | **Pass** |
| Place consumer `grid+0x2c` sealed | **Pass** |
| No invented PDB symbol | **Pass** |
| Runtime / bit-exact | **Open** |
| Verdict | **accept-with-gaps** |
