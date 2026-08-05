# Review A (reconstruction fidelity): `aa_004bafe0` Object_ResolveTarget_VCall1d4

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bafe0` |
| **VA** | `0x004bafe0`–`0x004bafff` (body; `ret 0x0c`) |
| **Canonical name** | `Object_ResolveTarget_VCall1d4` (**INFERRED**) |
| **Aliases** | `FUN_004bafe0`, `Named_CalleeOf_Client_RecvInventoryEquip_004bafe0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004bafe0_Object_ResolveTarget_VCall1d4.md` |
| **System** | `inventory-transfer` / object-resolve (equip path) |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` body (2026-07-29); callers `get_function_callers` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin **resolve-then-vcall** wrapper used by equip / create / unequip paths:

1. Call `CVOGReaction_ResolveObjectTarget` with the same ECX context and three stack args (`bGlobal`, `coidLo`, `coidHi`).
2. If resolved object is non-null → **thiscall** vfunc **`+0x1d4`** on that object; return its result.
3. Else return **0**.

Used by `Client_RecvInventoryEquip` to obtain the vehicle* for packet vehicle TFID (`pkt+0x18/+0x1c` + realm/global at `+0x20`).

**No mutation** in this body.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004bafe0_FUN_004bafe0.md` |
| Annotated | `docs/reconstruction/raw/aa_004bafe0_FUN_004bafe0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004bafe0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004bafe0_FUN_004bafe0.md` |
| Callee dual | `reviews/A_aa_004bae70_CVOGReaction_ResolveObjectTarget.md` |
| Counterpart B | `reviews/B_aa_004bafe0_Object_ResolveTarget_VCall1d4.md` |

---

## 3. Signature (assembly-sealed)

```c
// __thiscall  ECX = resolve context (passed through to ResolveObjectTarget)
// stack cleaned by ret 0x0c
void * Object_ResolveTarget_VCall1d4(
    void *ctx,              // this ECX
    unsigned /*bGlobal*/,   // stack arg0 → Resolve
    unsigned coidLo,        // stack arg1
    unsigned coidHi);       // stack arg2
// returns result of object->vfunc[+0x1d4](), or NULL
```

### Image body (`read_memory` 2026-07-29)

```
mov eax, [esp+0xc]   ; coidHi
mov edx, [esp+8]     ; coidLo
push eax
mov eax, [esp+8]     ; bGlobal (after one push)
push edx
push eax
call CVOGReaction_ResolveObjectTarget   ; ECX unchanged = ctx
test eax, eax
jz   ret0
mov  edx, [eax]
mov  ecx, eax
call [edx+0x1d4]
ret  0xc
xor  eax, eax
ret  0xc
```

| Stage | Match | Confidence |
|---|---|---|
| ECX passthrough into Resolve (no `mov ecx` reload) | **Yes** | **High** (bytes) |
| Three stack args; `ret 0x0c` | **Yes** | **Confirmed** |
| Null → 0; else vfunc `+0x1d4` | **Yes** | **High** |
| No stores | **Yes** | **High** |

---

## 4. Callers (fan-in)

| Caller | VA | Role |
|---|---|---|
| `Client_RecvInventoryEquip` | `0x00813f40` | Vehicle TFID → vehicle* |
| `Client_RecvInventoryUnequipNotify` | `0x00813bf0` | Same resolve shape |
| `CVOGCharacter_CreateFromPacket` | `0x005237a0` | Create path resolve |
| `CVOGCreature_PostCreateFromPacket` | `0x004c5c30` | Create path |
| `FUN_00521310` | `0x00521310` | Related |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Function @ `0x004bafe0` | **Confirmed** | Ghidra + bytes |
| `__thiscall` + 3 stack args | **High** | `ret 0x0c`; ECX passthrough |
| Delegates to `ResolveObjectTarget` | **High** | CALL rel32 → `0x004bae70` |
| Post-resolve vfunc offset `0x1d4` | **High** | `ff 92 d4 01 00 00` |
| Equip uses return as vehicle* | **High** | caller contract RecvInventoryEquip |
| Product English for vfunc `+0x1d4` | **Open** | cast/get-root/get-vehicle residual |
| Product name of this unit | **Tentative** | inferred from CF |

---

## 6. Gaps / open

1. Exact product meaning of vtable slot `+0x1d4` (identity vs cast vs owning vehicle).
2. Whether all callers expect the same return type.

**Verdict:** **accept-with-gaps**
