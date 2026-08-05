
# Review A (reconstruction fidelity): `aa_0075dae0` Owner_ClearDestroyGuardedPtrDequeAt28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075dae0` |
| **VA** | `0x0075dae0`–`0x0075db93` (**180 B**) |
| **Canonical name** | `Owner_ClearDestroyGuardedPtrDequeAt28` (**Inferred**) |
| **Ghidra name** | `FUN_0075dae0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-C) |
| **Counterpart** | `reviews/B_aa_0075dae0_Owner_ClearDestroyGuardedPtrDequeAt28.md` |
| **System** | owner + GuardedVector of owned pointers |
| **Evidence pass** | Live `decompile_function` + `analyze_function_complete` + `read_memory` (full 180 B); callees ClearAndSwap + 0040d9c0; **0** callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

On owner `ECX`, clear the GuardedVector of owned pointers at **`+0x28`**: steal via `GuardedVector_ClearAndSwap`, scalar-delete each non-null element in ring order, free the stolen page map via `FUN_0040d9c0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0075dae0_FUN_0075dae0.md` (+ 2026-07-29 W30-C append) |
| Annotated | `docs/reconstruction/raw/aa_0075dae0_FUN_0075dae0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Owner_ClearDestroyGuardedPtrDequeAt28.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075dae0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0075dae0_FUN_0075dae0.md` |
| Named record | `docs/reconstruction/functions/aa_0075dae0_Owner_ClearDestroyGuardedPtrDequeAt28.md` |
| Live | full body hex; decompile **diverges** (dead loop) — bytes win |
| Context | sole consumer of sealed W29-A ClearAndSwap |

---

## 3. Signature (sealed)

```c
// ECX=owner; SEH; ADD ESP,0x20; RET
void Owner_ClearDestroyGuardedPtrDequeAt28(void* owner /*ECX*/);
```

| Slot | Source | Conf |
|---|---|---|
| owner | **ECX** (`MOV EDI,ECX; ADD EDI,0x28`) | **High** |
| field | `owner+0x28` as EDI into ClearAndSwap | **High** |
| local A | LEA ESI, stack header zeros | **High** |
| free | ESI=local → `FUN_0040d9c0` | **High** |

---

## 4. Control flow (clean ≡ bytes; decompile partial)

```
SEH
zero local header +4..+10
ClearAndSwap(local, owner+0x28)
for idx = begin; idx != begin+size; ++idx:
  page/sub wrap lookup
  if elem: vtbl[0](elem, 1)
FUN_0040d9c0(local)
SEH teardown; RET
```

| Stage | Match | Conf |
|---|---|---|
| Steal via ClearAndSwap | **Yes** (call site bytes) | **High** |
| Ring walk bounds | **Yes** (bytes; decompile **no**) | **High** |
| Scalar deleting dtor | **Yes** (`PUSH 1; CALL [EDX]`) | **High** |
| Map free | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full **180 B** hex sealed in raw append. Key sites:

- Entry SEH: `6A FF 68 4B FE 9A 00 …`
- Field: `8B F9 83 C7 28`
- ClearAndSwap: `E8 …` → `0043c660`
- Dtor: `6A 01 FF 12`
- Free: `E8 …` → `0040d9c0`
- Epilogue: `83 C4 20 C3`

---

## 6. Gaps

- Owner product/PDB class and field English.
- **Zero** Ghidra code xrefs — reachability unknown (vtable/data miss vs dead).
- Element static type beyond owned vobject.
- Runtime / CS contention.
- Nested `FUN_0040d9c0` product naming residual (W18-M).

---

## 7. Verdict

Fidelity: CF/ABI/offsets sealed from bytes; decompile residual documented; ownership/xrefs residual → **accept-with-gaps**.

