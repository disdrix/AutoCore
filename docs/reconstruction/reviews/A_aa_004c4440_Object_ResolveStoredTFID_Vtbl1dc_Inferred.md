# Review A (reconstruction fidelity): `aa_004c4440` Object_ResolveStoredTFID_Vtbl1dc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4440` |
| **VA** | `0x004c4440`–`0x004c44bc` |
| **Canonical name** | `Object_ResolveStoredTFID_Vtbl1dc_Inferred` |
| **Ghidra name** | `FUN_004c4440` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W27-G) |
| **Counterpart** | `reviews/B_aa_004c4440_Object_ResolveStoredTFID_Vtbl1dc_Inferred.md` |
| **System** | object / TFID resolve / vtbl query |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; DATA xrefs; sibling TFID units |
| **Verdict** | **accept** |

---

## 1. Purpose

When the object's stored **TFID_16** is assigned/valid, resolve it to a live object and return the result of that object's **vtbl+0x1dc** virtual (or 0 on any failure / invalid TFID).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c4440_FUN_004c4440.md` (+ 2026-07-29 W27-G append) |
| Annotated | `docs/reconstruction/raw/aa_004c4440_FUN_004c4440.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_ResolveStoredTFID_Vtbl1dc_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c4440.cpp` |
| Function | `docs/reconstruction/functions/aa_004c4440_FUN_004c4440.md` |
| Named record | `docs/reconstruction/functions/aa_004c4440_Object_ResolveStoredTFID_Vtbl1dc_Inferred.md` |
| Live | decompile ≡ raw; `read_memory` 125 B; epilogue `… 83 C4 10 C3` |
| Callee dual | `Object_ResolveFromTFID` `0x004bb950` (rel32 sealed) |
| Sibling | `FUN_004c4620` mode leaf / `FUN_004c4880` mode writer |

---

## 3. Signature (sealed)

```c
// thiscall; 0 stack formals; EAX return; RET 0
int Object_ResolveStoredTFID_Vtbl1dc_Inferred(int this);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX | **High** |
| cleanup | `RET` (no `RET n`) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if TFID invalid ((lo&hi)==~0 && (char)w2==0):
  return 0
copy TFID_16 local from this+0x108
ctx = manager chain (+0xA8 / +0xE4E8)   // surface residual
obj = Object_ResolveFromTFID(ctx, &local)
if obj == 0: return 0
r = obj->vtbl[+0x1dc]()
return (r != 0) ? r : 0
```

| Stage | Match | Conf |
|---|---|---|
| Invalid gate | **Yes** | **High** |
| TFID_16 copy | **Yes** | **High** |
| Resolve call → 0x004bb950 | **Yes** | **High** |
| Manager ECX in bytes | **Yes** (surface omits) | **High** |
| vtbl+0x1dc thiscall | **Yes** | **High** |
| thiscall RET 0 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Hex body (125 B):
```
83ec1053568bf18d86080100008bd88b13578b7b048b4b088b5b0c23d783faff895c2418750484c9744a8b088b5004894c240c8b4808895424108b500c8b4604894c2414895424188b48048b9431a80000008b8ae8e400008d44240c50e8ae74ffff85c0740e8b108bc8ff92dc01000085c0750233c05f5e5b83c410c3
```

Epilogue: `5F 5E 5B 83 C4 10 C3`. Call at `0x004c449d` → `0x004bb950`. Virtual `FF 92 DC 01 00 00` (`CALL [EDX+0x1DC]`).

---

## 6. Gaps

- Product English for **vtbl+0x1dc** return value.
- Product type of resolve ctx / host at `+0xE4E8`.
- Owning class of DATA vtable slots (`0x009cbf30`, `0x009cfe50`).
- Runtime / bit-exact — open.

---

## 7. Verdict

CF, ABI, invalid predicate, resolve callee, and virtual dispatch are sealed against live decompile, full-body bytes, and dual-sealed callee. Naming is evidence-backed (`TFID_16` + `Object_ResolveFromTFID` + vtbl offset) with `_Inferred` for the virtual's product role. → **accept**.
