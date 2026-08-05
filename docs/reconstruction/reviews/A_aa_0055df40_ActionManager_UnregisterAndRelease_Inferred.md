# Review A (reconstruction fidelity): `aa_0055df40` ActionManager_UnregisterAndRelease_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055df40` |
| **VA** | `0x0055df40`–`0x0055df76` exclusive (**54** B) |
| **Canonical name** | `ActionManager_UnregisterAndRelease_Inferred` |
| **Ghidra symbol** | `FUN_0055df40` |
| **Prior / alias** | `Named_CalleeOf_…SERVER_GOT_GIGO…` (misleading parent-seed) |
| **Review date** | `2026-07-29` (W23-P OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0055df40_ActionManager_UnregisterAndRelease_Inferred.md` |
| **System** | vehicle / world action lifecycle |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, callers/callees/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Unregister an action from its action-manager:

1. `FUN_0062a410(manager, action)` — notify each non-null listener in `manager+0x3c[0..count)`.
2. `FUN_00628f10(*(action+0x10), action)` — remove from reverse host pointer list.
3. Decrement short refcount at `action+6`; store `0` at `action+0xC`.
4. If refcount == 0, `(*action->vtbl[0])(action, 1)`.

Used from vehicle action teardown (`Vehicle_DestroyVehicleAction_Inferred`) and other held-action clear paths.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `raw/aa_0055df40_FUN_0055df40.md` (+ W23-P append) |
| Annotated | `raw/aa_0055df40_FUN_0055df40.annotated.md` |
| Clean | `reconstructed-exact/ActionManager_UnregisterAndRelease_Inferred.cpp` |
| Scaffold | `reconstructed-exact/FUN_0055df40.cpp` |
| Function record | `functions/aa_0055df40_ActionManager_UnregisterAndRelease_Inferred.md` |
| Live decompile | ≡ raw body |
| Live body bytes | `read_memory` @ `0x0055df40` length 54+ |
| Parent dual | `A_aa_004f7d60_Vehicle_DestroyVehicleAction_Inferred` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte seal (`read_memory` @ `0x0055df40`)

```
push esi
mov  esi, [esp+8]           ; action
push esi / push ecx         ; FUN_0062a410(manager, action)
call FUN_0062a410
mov  ecx, [esi+0x10]        ; host = *(action+0x10)
add  esp, 8
push esi
call FUN_00628f10           ; thiscall ECX=host
add  word [esi+6], -1
cmp  word [esi+6], 0
mov  dword [esi+0xC], 0
jne  skip_dtor
mov  eax, [esi]
push 1 / mov ecx, esi / call [eax]
pop  esi
ret  4
```

Hex (54 B):

```
568b7424085651e8c4c40c008b4e1083c40856e8b8af0c0066834606ff66837e0600c7460c0000000075088b066a018bceff105ec20400
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Body 54 B, `ret 4` | **High** |
| ECX=manager, stack=action | **High** |
| Notify then reverse-list remove then release | **High** |
| `FUN_00628f10` this = `*(action+0x10)` (decomp residual) | **High** |
| short@+6 / clear@+0xC / vtbl[0](1) | **High** |
| Manager often `*(world+0xe4a4)` | **High** (call sites) |
| Product English | **Inferred** |
| Nested duals complete | **Open** (not owned) |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps**

---

## 5. Gaps

1. Product / PDB names for manager and action classes.  
2. Dual seal of `FUN_0062a410`, `FUN_00628f10`, `FUN_005fff20`.  
3. Whether vtbl[0](1) is scalar dtor vs IUnknown-style Release.  
4. Runtime / differential verification.
