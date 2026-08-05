# Review A (reconstruction fidelity): `aa_00518ec0` Object_SharedBase_Dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518ec0` |
| **VA** | `0x00518ec0`–`0x005190b1` exclusive (**497 B** / `0x1F1`) |
| **Canonical name** | `Object_SharedBase_Dtor` |
| **Ghidra name** | `FUN_00518ec0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-G) |
| **Counterpart** | `reviews/B_aa_00518ec0_Object_SharedBase_Dtor.md` |
| **System** | object core / dual-base shared field destructor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **shared dual-base / virtual-base field destructor** for the client object core (twin of `Object_SharedBase_Ctor` `0x00518940`):

1. CO-list safety: if still resolvable via TFID@`+0x160`, log + `FUN_004bb970`.
2. Stop interface@`+0x14` (vcall +0x2C arg 0).
3. Stamp `GetTickCount` → `+0x18`.
4. Double-list predicate remove (`this & ~0xFF` pack).
5. `FUN_0051b8a0`; destroy CS helper@`+0xb0` (scalar flag 1).
6. `Object_TeardownOwnedFxLists_Inferred` (`FUN_005179e0`).
7. Free owned `+0x15c/+0x6c/+0x68/+0x64/+0x70/+0x158` and buffer triples `+0x148/+0x138/+0x124`.

Not scalar-deleting (no `delete this`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W29-G) | `docs/reconstruction/raw/aa_00518ec0_FUN_00518ec0.md` |
| Annotated | `docs/reconstruction/raw/aa_00518ec0_FUN_00518ec0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Object_SharedBase_Dtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00518ec0.cpp` |
| Function records | `functions/aa_00518ec0_FUN_00518ec0.md`, `functions/aa_00518ec0_Object_SharedBase_Dtor.md` |
| Ctor twin | `Object_SharedBase_Ctor` W22-B |
| FX peer | `Object_TeardownOwnedFxLists_Inferred` W28-H |
| Live | decompile; 53 xrefs; epilogue `C3`; false-noreturn fall-through |

---

## 3. Signature (sealed)

```c
// __thiscall/__fastcall; ECX=this; void; bare RET
void __fastcall Object_SharedBase_Dtor(void *self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| return | void | **High** |
| cleanup | bare `C3` | **High** |

---

## 4. Control flow (clean ≡ raw; delete fall-through sealed)

```
if world(+0xa4) && gate:
  if ResolveTFID(this+0x160)==this: log; FUN_004bb970
if +0x14: vcall+0x2C(0); clear
+0x18=GetTickCount
local=this&~0xFF; CNDDoubleList_InvokePredicateAndRemove(...)
FUN_0051b8a0
scalar_delete(+0xb0); clear
Object_TeardownOwnedFxLists
free chain +0x15c..+0x64, +0x70, delete[] +0x158
optional FUN_004eb010
free triples +0x148, +0x138, +0x124
RET
```

| Stage | Match | Conf |
|---|---|---|
| CO-list string path | **Yes** | **High** |
| operator_delete fall-through | **Yes** (bytes end) | **High** |
| SharedBase_Ctor twin role | **Yes** | **High** |
| Multi-caller complete-dtor chain | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Note |
|---|---|
| Entry | `51 53 56 8B F1` |
| Epilogue | `5E 5B 59 C3` + `CC` pad |
| Size | **497 B** exclusive end `0x005190b1` |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- Product C++ class English for shared base.
- Full owned-subobject product types at each free site.
- Runtime / bit-exact / differential — open.

---

## 7. Verdict

CF, ABI, CO-list check, teardown order, and SharedBase pairing sealed → **accept-with-gaps**.
