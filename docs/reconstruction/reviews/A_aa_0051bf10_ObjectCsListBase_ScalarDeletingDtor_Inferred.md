# Review A (reconstruction fidelity): `aa_0051bf10` ObjectCsListBase_ScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bf10` |
| **VA** | `0x0051bf10`–`0x0051bf3e` exclusive (**46 B** / `0x2E`) |
| **Canonical name** | `ObjectCsListBase_ScalarDeletingDtor_Inferred` |
| **Ghidra name** | `FUN_0051bf10` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-R) |
| **Counterpart** | `reviews/B_aa_0051bf10_ObjectCsListBase_ScalarDeletingDtor_Inferred.md` |
| **System** | object core / CS-owned list teardown |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **scalar deleting destructor** for **base** CS-list vtbl `PTR_FUN_009ce07c` (slot0):

1. Install base vtbl `PTR_FUN_009ce07c` @ `this+0`.
2. `FUN_0051bc90(this)` drain under CS.
3. `DeleteCriticalSection(this+4)`.
4. If `flags & 1`: `operator_delete(this)` (cdecl).
5. Return `this` (`RET 4`).

No derived-vtbl (`009ce154`) phase.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-R) | `docs/reconstruction/raw/aa_0051bf10_FUN_0051bf10.md` |
| Annotated | `docs/reconstruction/raw/aa_0051bf10_FUN_0051bf10.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/ObjectCsListBase_ScalarDeletingDtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051bf10.cpp` |
| Function records | `functions/aa_0051bf10_FUN_0051bf10.md`, `functions/aa_0051bf10_ObjectCsListBase_ScalarDeletingDtor_Inferred.md` |
| Complete twin | `FUN_0051d0e0` (this dual pair) |
| Live | decompile ≡ raw; DATA xref vtbl slot0; body hex 46 B |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=list*; stack flags; RET 4; returns this
void * __thiscall ObjectCsListBase_ScalarDeletingDtor_Inferred(void *list, uint8_t flags);
```

| Formal | Source | Conf |
|---|---|---|
| list | ECX (`56 8B F1`) | **High** |
| flags | stack; `TEST [ESP+8],1` after push ESI | **High** |
| return | EAX=`this`; `C2 04 00` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
MOV ESI,ECX
*this = PTR_FUN_009ce07c
CALL FUN_0051bc90
LEA EAX,[ESI+4]; PUSH EAX
CALL [IAT DeleteCriticalSection]
TEST [ESP+8],1
JZ skip
  PUSH ESI; CALL operator_delete; ADD ESP,4
skip:
MOV EAX,ESI; POP ESI; RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Base vtbl only | **Yes** | **High** |
| DeleteCS @ +4 | **Yes** | **High** |
| flags bit0 free | **Yes** | **High** |
| Fall-through after delete | **Yes** (bytes; decompiler noreturn false) | **High** |
| No derived vtbl phase | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Note |
|---|---|
| Entry | `56 8B F1 C7 06 7C E0 9C 00` |
| DeleteCS | `8D 46 04 50 FF 15 F0 61 9C 00` |
| Flag / free | `F6 44 24 08 01 74 09 56 E8 … 83 C4 04` |
| Epilogue | `8B C6 5E C2 04 00` |
| Size | **46 B** exclusive end `0x0051bf3e` |
| Full hex | raw W31-R append |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- Product base class English for `PTR_FUN_009ce07c`.
- No `flags&2` array path in body (normal for scalar-only thunk).
- When runtime uses base vs derived scalar path — open beyond vtbl identity.
- Runtime / bit-exact / differential.

---

## 7. Verdict

CF, ABI, base-only phase, DeleteCS, flags&1 free sealed → **accept-with-gaps** (product English residual).
