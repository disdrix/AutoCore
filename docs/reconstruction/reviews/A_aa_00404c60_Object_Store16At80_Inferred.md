# Review A (reconstruction fidelity): `aa_00404c60` Object_Store16At80_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404c60` |
| **VA** | `0x00404c60`–`0x00404c88` inclusive (**41 B** / `0x29`) |
| **Canonical name** | `Object_Store16At80_Inferred` |
| **Ghidra name** | `FUN_00404c60` |
| **Review date** | `2026-08-05` (MEGA-053 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00404c60_Object_Store16At80_Inferred.md` |
| **System** | skills-abilities (partition); generic object field-store leaf |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + caller `batch_decompile`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **16-byte store** into object field block at **`this+0x80..0x8c`**:

```text
src = [ESP+4]
this[0x80] = src[0]
this[0x84] = src[1]
this[0x88] = src[2]
this[0x8c] = src[3]
RET 4
```

Shared setter used by skill spawn / creature apply / physics load / client net consumers. Twin `FUN_00404c30` writes the contiguous next 16 bytes at **`+0x90..0x9c`**. Partition hint ("Skill invalid creature/template string") names **parents**, not this body.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00404c60_FUN_00404c60.md` (+ MEGA-053 append) |
| Annotated | `docs/reconstruction/raw/aa_00404c60_FUN_00404c60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_Store16At80_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00404c60.cpp` |
| Function record | `docs/reconstruction/functions/aa_00404c60_FUN_00404c60.md` |
| Named record | `docs/reconstruction/functions/aa_00404c60_Object_Store16At80_Inferred.md` |
| Live | decompile ≡ CF; body hex; RET 4; 4 CALL xrefs; call-site ECX/PUSH; twin +0x90 |

---

## 3. Signature (sealed)

```c
// ECX = object*; stack const uint32_t src[4]*; void; RET 4
void __thiscall Object_Store16At80_Inferred(void *thisObj, const uint32_t *src16);
```

| Slot | Source | Conf |
|---|---|---|
| this (dst) | **ECX** | **High** |
| src16 | stack `[ESP+4]` after entry | **High** |
| cleanup | **`RET 4`** | **High** |
| field | **`+0x80..+0x8c`** (16 B) | **High** |

**Note:** Caller decompiles often omit the stack arg or invent wrong arity; body + call-site assembly (`PUSH src` / `MOV ECX,obj` / `CALL`) seals ABI.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Load src from stack | **Yes** | **High** |
| Four dword stores @ +0x80..0x8c | **Yes** | **High** |
| No branches / SEH | **Yes** | **High** |
| Leaf (no callees) | **Yes** | **High** |
| `RET 4` | **Yes** | **High** |
| Product field English | open | **Inferred** |

Body hex seal:

```text
8b442404 8b10 899180000000 8b5004 899184000000
8b5008 899188000000 8b400c 89818c000000 c20400
```

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf |
| External callers | `FUN_0058a1b0`, `FUN_005c76f0`, `FUN_00620480`, `FUN_0091da70` |
| xref_count | **4** UNCONDITIONAL_CALL |
| Site roles | skill/creature apply; `CLoadNode::_initPhysics` type-0xe; skill template spawn; client net local-player pack |
| Callees | none |
| Twin | store @ +0x90 `FUN_00404c30` |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| 16 B store @ +0x80 sealed | **Yes** |
| thiscall + RET 4 | **Yes** |
| Direction = into this (not out-copy) | **Yes** |
| Distinct from TFID out-copy peers | **Yes** |
| Product/PDB English for field | **No** |
| Body owns skill invalid strings | **No** |

**Decision:** promote **`Object_Store16At80_Inferred`**. Reject skill-string plate identity; reject merge with twin `00404c30`; reject getter / out-copy mislabel; reject `Named_CalleeOf_*` scaffolds (retired).

---

## 7. Gaps / open

1. Product English for +0x80 field (and +0x90 twin half — pos/quat/generic).
2. Shared multi-inh object layout plate for call-site `this + *(this+4) + 4`.
3. Twin `00404c30` residual (not MEGA-053 OWN).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
