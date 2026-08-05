# Review A (reconstruction fidelity): `aa_0051b8a0` ObjectCsList_ClearDestroy_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b8a0` |
| **VA** | `0x0051b8a0`–`0x0051b99c` exclusive (**252 B** / `0xFC`) |
| **Canonical name** | `ObjectCsList_ClearDestroy_Inferred` |
| **Ghidra name** | `FUN_0051b8a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-F) |
| **Counterpart** | `reviews/B_aa_0051b8a0_ObjectCsList_ClearDestroy_Inferred.md` |
| **System** | object core / CS-owned list teardown |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

CS-protected **clear/destroy all nodes** on Object SharedBase helper list (`core+0xB0`, `sizeof 0x2C`, vtbl `PTR_FUN_009ce154`):

1. `EnterCriticalSection(list+4)`.
2. If TraversalLock flag `list+0x28 ≠ 0`: `Leave` + throw `0x80070005`.
3. Walk head `list+0x1C`; next @ `node+8`; clear `node+4`; scalar-delete `vtbl[0](1)`.
4. Zero `+0x24`, `+0x20`, `+0x1C`.
5. `LeaveCriticalSection`.

Does **not** free the list object (caller scalar-deletes after).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W30-F) | `docs/reconstruction/raw/aa_0051b8a0_FUN_0051b8a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051b8a0_FUN_0051b8a0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/ObjectCsList_ClearDestroy_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051b8a0.cpp` |
| Function records | `functions/aa_0051b8a0_FUN_0051b8a0.md`, `functions/aa_0051b8a0_ObjectCsList_ClearDestroy_Inferred.md` |
| Owner ctor | `Object_SharedBase_Ctor` W22-B (`new(0x2C)` + CS init @ `+0xB0`) |
| Owner dtor | `Object_SharedBase_Dtor` W29-G (`mov ecx,[esi+0xB0]` then this) |
| Sibling | `List_ClearDestroy` `0x0040dc40` (next@+0x10) |
| Live | decompile ≡ raw; entry `55 8B EC` + chkstk `0x1004`; epilogue frame `C3`; call-site ECX |

---

## 3. Signature (sealed)

```c
// __thiscall/__fastcall; ECX=list*; void; bare RET
void __fastcall ObjectCsList_ClearDestroy_Inferred(void *list);
```

| Formal | Source | Conf |
|---|---|---|
| list | ECX (`8B F1`); call sites load `[obj+0xB0]` | **High** |
| return | void | **High** |
| cleanup | frame epilogue `8B E5 5D C3` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
SEH LAB_009a3510 + chkstk 0x1004
EnterCS(list+4)
if list+0x28: LeaveCS; throw 0x80070005
while head=list+0x1C:
  head = node->next (+8)
  node+4 = 0
  (*node->vtbl)(1)
zero +0x24/+0x20/+0x1C
LeaveCS
RET
```

| Stage | Match | Conf |
|---|---|---|
| EnterCS then flag check | **Yes** | **High** |
| Throw `0x80070005` | **Yes** (`C7 … 05 00 07 80`) | **High** |
| Next @ +8; clear +4; scalar dtor | **Yes** | **High** |
| Zero three dwords | **Yes** | **High** |
| ECX = SharedBase`+0xB0` | **Yes** (bytes at call sites) | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Note |
|---|---|
| Entry | `55 8B EC 6A FF 68 10 35 9A 00` … `B8 04 10 00 00` (chkstk size) |
| Body | `8D 7E 04` CS ptr; `FF 15 …` EnterCS IAT; `38 5E 28` flag test; `C7 45 EC 05 00 07 80` |
| Drain | `8B 51 08 89 56 1C 89 59 04` next/clear; `6A 01` scalar flag |
| Epilogue | `5F 5E 64 89 0D … 5B 8B E5 5D C3` |
| Size | **252 B** exclusive end `0x0051b99c` |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- Product / MSVC demangle for CS-list class (`PTR_FUN_009ce154`).
- Field English for `+0x20` / `+0x24`.
- Node payload product type.
- Runtime under concurrent TraversalLock — open.

---

## 7. Verdict

CF, ABI, list/node layout, SharedBase ownership, and throw path sealed → **accept-with-gaps** (product English residual).
