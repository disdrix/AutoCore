# Review A (reconstruction fidelity): `aa_00636370` Phys_ActionBase_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636370` |
| **VA** | `0x00636370` |
| **Body** | `0x00636370`–`0x006363b2` (`ret 4` inclusive) |
| **Canonical name** | `Phys_ActionBase_ctor` |
| **Prior / alias** | `FUN_00636370`; parent-seed `Named_CalleeOf_…_CVO_00636370` (**misleading**) |
| **Review date** | `2026-07-29` (W17-P OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00636370_Phys_ActionBase_ctor.md` |
| **System** | physics / Havok-like action base |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_xrefs`, `analyze_function_complete`, `audit_globals_in_function` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Base constructor** for dual-vtable action-like objects used by vehicle drive (`VehicleAction_ctor`), flipper constraint, and a third sibling (`FUN_00658bf0`).

Establishes:

- Havok-like **refcount** halfword at `this+6 = 1`
- **Primary** base vtable `PTR_FUN_009e39f4` and **secondary** base vtable `PTR_LAB_009e5e78` (with intermediate secondary `PTR_LAB_009e3a68` during construction)
- Optional **host link** at `this+0x18` with host-list registration + host addref when non-null

Derived ctors always overwrite class vtables after this returns.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00636370_FUN_00636370.md` |
| Annotated | `docs/reconstruction/raw/aa_00636370_FUN_00636370.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phys_ActionBase_ctor.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00636370.cpp` |
| Function record | `docs/reconstruction/functions/aa_00636370_Phys_ActionBase_ctor.md` |
| Live decompile | ≡ frozen raw CF |
| Live bytes | `read_memory` @ `0x00636370` (hex seal in raw) |
| Callee bytes | `read_memory` @ `0x00507290` (vector push @ host+0x94) |
| Vtbls | `read_memory` @ `0x009e39f4`, `0x009e3a68`, `0x009e5e78` |
| Callers | `VehicleAction_ctor`, `FUN_00600140`, `FUN_00658bf0` |
| Peer plate | `physics/verified/fn_00597e90_vehicleActionCtor.md` |

---

## 3. Byte seal (summary)

```
push esi
mov  esi, ecx                 ; this
mov  ecx, [esp+8]             ; host (after push)
xor  eax, eax
cmp  ecx, eax
mov  word [esi+6], 1
mov  dword [esi+8], 0x009e3a68   ; intermediate secondary
mov  [esi+0xc], eax
mov  [esi+0x14], eax
mov  dword [esi], 0x009e39f4     ; primary
mov  dword [esi+8], 0x009e5e78   ; final secondary
mov  [esi+0x18], ecx             ; host
jz   skip
push esi                         ; action*
call FUN_00507290                ; ECX still host
mov  eax, [esi+0x18]
add  word [eax+6], 1             ; host addref
skip:
mov  eax, esi
pop  esi
ret  4
```

| Claim | Evidence | Conf |
|---|---|---|
| `__thiscall` + `ret 4` | ECX this; `c2 04 00` | **High** |
| Refcount `+6 = 1` | `66 c7 46 06 01 00` | **High** |
| Intermediate then final secondary | two stores to `[esi+8]` | **High** |
| Primary `0x009e39f4` | immediate in bytes | **High** |
| Host `+0x18` | `89 4e 18` | **High** |
| Register only if host ≠ 0 | `74 0e` | **High** |
| `FUN_00507290` ECX=host, stack=this | ECX not restored; push esi | **High** |
| Host addref `+6` | `66 83 40 06 01` | **High** |
| Returns this | `8b c6` | **High** |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Refcount + dual vtbl + clears | **Yes** |
| Host link + optional register/addref | **Yes** |
| FUN_00507290 arg shape | Clean/annotated **correct** ECX=host (decomp alone incomplete) |
| No invent class-specific VehicleAction fields | **Yes** (those live in `0x00597f90`) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Base ctor for action family | **High** | 3 callers all overwrite vtbls after |
| Dual-vtbl MI construction | **High** | intermediate + final secondary |
| Host list @ host+0x94 via `FUN_00507290` | **High** | callee bytes |
| Product name is exactly Havok `hkAction` | **Probable / Inferred** | layout matches; no RTTI string in body |
| `+0xc` / `+0x14` field product names | **Open** | zeroed only |
| Host concrete type unified across callers | **Open** | peer duals differ (framework vs host+8) |

---

## 6. Gaps / open

1. PDB / Havok product symbol.
2. Full primary base vtbl slot map (slots sample sealed; names residual).
3. Dual of sibling dtor `FUN_00636290` (not owned).
4. Dual of `FUN_00507290` host vector helper (not owned).
5. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps**
