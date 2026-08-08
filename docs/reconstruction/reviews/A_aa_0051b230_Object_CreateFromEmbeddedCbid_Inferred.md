# Review A (reconstruction fidelity): `aa_0051b230` Object_CreateFromEmbeddedCbid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b230` |
| **VA** | `0x0051b230`–`0x0051b298` exclusive |
| **Canonical name** | `Object_CreateFromEmbeddedCbid_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (embedded-CBID virtual factory) |
| **Counterpart** | `reviews/B_aa_0051b230_Object_CreateFromEmbeddedCbid_Inferred.md` |
| **System** | object-spawn / CVOGClonedObjectBase |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` `0x0051b230` + `read_memory` body + `analyze_function_complete` + call-site `get_assembly_context` (`0x004c8f23`, `0x0056b0c2`). No `disassemble_bytes`. No ledgers / Launcher.

---

## 1. Purpose

Shared virtual method on the cloned-object hierarchy that **allocates and initializes a new game object** from a CBID stored under `*(this+0xA8)+0x34`, using the global factory `CVOGReaction_GiveItemByCbid`. Post-create init mirrors the `AllocateNewObjectFromCbid` family (vtbl+8 with host and flag 1, plus name path via `FUN_00516720`). Callers immediately `dynamic_cast` the result to `CVOGCreature*` or `CVOGWeapon*`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051b230_FUN_0051b230.md` |
| Annotated | `docs/reconstruction/raw/aa_0051b230_FUN_0051b230.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_CreateFromEmbeddedCbid_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051b230_Object_CreateFromEmbeddedCbid_Inferred.md` |
| Live Ghidra | decompile + read_memory + callers |
| RTTI | `.?AVCVOGCreature@@` `0x00af8d0c`, `.?AVCVOGClonedObjectBase@@` `0x00af8e10`, `.?AVCVOGWeapon@@` `0x00aff630` |
| Sibling | `AllocateNewObjectFromCbid` `0x004cf120` |

---

## 3. Signature

```c
void * __thiscall Object_CreateFromEmbeddedCbid_Inferred(void *self);
// ECX = host; bare RET; EAX = obj* | NULL
```

| Item | Evidence |
|---|---|
| Body size | 104 B; range `0051b230`–`0051b298` |
| This bind | `MOV EDI,ECX` |
| Factory | `PUSH 0; PUSH cbid; CALL 0x0051a170; ADD ESP,8` |
| Return | `MOV EAX,ESI; POP ESI; RET` |

---

## 4. Control flow (sealed)

```
cbid = *(*(this+0xA8)+0x34)
obj  = CVOGReaction_GiveItemByCbid(cbid, 0)
if obj == NULL: return NULL
obj->vtbl+8 (cbid, *(this+0xA4), 1)
obj->vtbl+0xB8 (*(this+0xB8))
FUN_00516720(obj, *(this+0x158))
*(obj+0xC4) = *(this+0xC4)
return obj
```

No SEH, no logging, no loops.

---

## 5. Machine bytes (`read_memory` @ `0x0051b230`)

```
56 57                PUSH ESI / EDI
8B F9                MOV  EDI, ECX
8B 87 A8 00 00 00    MOV  EAX, [EDI+0xA8]
8B 40 34             MOV  EAX, [EAX+0x34]   ; cbid
6A 00 50             PUSH 0 / PUSH EAX
E8 2B EF FF FF       CALL CVOGReaction_GiveItemByCbid
8B F0 83 C4 08       MOV  ESI,EAX / ADD ESP,8
85 F6 74 45          TEST ESI / JZ fail
… vtbl+8, vtbl+0xB8, FUN_00516720, copy +0xC4 …
5F 8B C6 5E C3       POP EDI / MOV EAX,ESI / POP ESI / RET
```

---

## 6. Confirmations

| # | Claim | Status |
|---|---|---|
| 1 | thiscall, no stack formals | **Confirmed** (bytes + call sites) |
| 2 | GiveItem two-arg cdecl | **Confirmed** (`ADD ESP,8`) |
| 3 | Init vtbl+8 (cbid, host@+0xA4, 1) | **Confirmed** |
| 4 | FUN_00516720(obj, this+0x158) | **Confirmed** (ECX=ESI, push string) |
| 5 | Shared virtual; creature/weapon cast consumers | **Confirmed** (RTTI + assembly context) |
| 6 | Decompile CF ≡ image CF | **Confirmed** after trap fixes |

---

## 7. Residual gaps

- Product MSVC name / plate for the virtual slot.
- Concrete type of descriptor at `this+0xA8` (field English for +0x34 cbid source).
- Semantics of `+0xB8` and `+0xC4` beyond “copied to new object” (weapon path rewrites `+0xC4` as byte post-cast).
- Runtime Confirmed / bit-exact / differential.

---

## 8. Verdict

Structural factory role, ABI, offsets, and callee chain sealed from decompile + read_memory + RTTI call sites. Product English open → **accept-with-gaps**.
