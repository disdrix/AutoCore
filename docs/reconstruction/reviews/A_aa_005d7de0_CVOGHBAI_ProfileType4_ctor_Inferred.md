# Review A (reconstruction fidelity): `aa_005d7de0` CVOGHBAI_ProfileType4_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d7de0` |
| **VA** | `0x005d7de0`–`0x005d7df8` |
| **Canonical name** | `CVOGHBAI_ProfileType4_ctor_Inferred` |
| **Ghidra name** | `FUN_005d7de0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-K) |
| **Counterpart** | `reviews/B_aa_005d7de0_CVOGHBAI_ProfileType4_ctor_Inferred.md` |
| **System** | npc-ai / HBAI / profile-type-4 |
| **Evidence pass** | Live `decompile_function` + `read_memory` + xrefs; sealed DoLogic sibling `005d7ca0`; parent factory W27-I |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin HBAI subclass ctor for AI-profile factory type word **4**: run mid-base `FUN_005d1990(this, owner)`, install vtbl `PTR_FUN_009db08c`, return `this`. Object size **0xC0**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d7de0_FUN_005d7de0.md` (+ W28-K append) |
| Annotated | `docs/reconstruction/raw/aa_005d7de0_FUN_005d7de0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBAI_ProfileType4_ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d7de0.cpp` |
| Function | `docs/reconstruction/functions/aa_005d7de0_CVOGHBAI_ProfileType4_ctor_Inferred.md` |
| DoLogic sibling | `CVOGHBAI_ProfileType4_DoLogic_Inferred` (`aa_005d7ca0`) |
| Parent factory | `Object_EnsurePrimaryHBAI_FromAIProfile` case 4 |
| Vtbl + DoLogic slot | `009db08c`; DATA `009db0dc` = `005d7ca0` |

---

## 3. Signature

```c
// Ghidra: undefined4 * __thiscall FUN_005d7de0(undefined4 *param_1, undefined4 param_2)
// Bytes: push owner; call FUN_005d1990; mov [esi], 009db08c; ret 4
void * __thiscall CVOGHBAI_ProfileType4_ctor_Inferred(void *self, void *pOwner);
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX=this | `8B F1` | **High** |
| stack owner; RET 4 | push `[esp+4]`; `C2 04 00` | **High** |
| returns this | `8B C6` | **High** |
| No local SEH | 25-byte body; SEH in base | **High** |

---

## 4. Control flow (sealed)

1. `FUN_005d1990(self, pOwner)` — mid HBAI base (thiscall ECX preserved)
2. `*self = &PTR_FUN_009db08c`
3. return self

| Stage | Match | Conf |
|---|---|---|
| Base chain only callee | **Yes** | **High** |
| Single vtbl install | **Yes** | **High** |
| Factory case 4 / size 0xC0 | **Yes** (parent seal) | **High** |
| DoLogic vtbl+0x50 linkage | **Yes** (`009db0dc`) | **High** |
| No extra field init in leaf | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory` @ `0x005d7de0`)

```
8B 44 24 04       mov eax, [esp+4]
56                push esi
50                push eax
8B F1             mov esi, ecx
E8 A3 9B FF FF    call FUN_005d1990
C7 06 8C B0 9D 00 mov dword [esi], 009db08c
8B C6             mov eax, esi
5E                pop esi
C2 04 00          ret 4
```

---

## 6. Gaps / open

1. Product/PDB English class name for `009db08c`.
2. Base mid-ctor `FUN_005d1990` field map (not OWN).
3. Not AICode factory path (`CVOGHBAI_CreateByAICode`) — do not equate type word 4 to AICode 4 without evidence.
4. Runtime / bit-exact — open.

---

## 7. Verdict

CF/ABI/vtbl/factory sealed; product class + base mid residual → **accept-with-gaps**.
