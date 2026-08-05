# Review A (reconstruction fidelity): `aa_00628f10` ActionHost_RemoveReverseListEntry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00628f10` |
| **VA** | `0x00628f10`–`0x00628f64` exclusive (**84** B) |
| **Canonical name** | `ActionHost_RemoveReverseListEntry_Inferred` |
| **Ghidra symbol** | `FUN_00628f10` |
| **Prior / alias** | scaffold `FUN_00628f10` / Named_CalleeOf_* |
| **Review date** | `2026-07-29` (W24-P OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00628f10_ActionHost_RemoveReverseListEntry_Inferred.md` |
| **System** | vehicle / world action lifecycle |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, callers (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Remove `action` from host reverse-pointer list:

1. Linear search in `*(host+0x4c)` over `count@+0x50`.
2. `count--`; shift-left to close hole when `index < new_count`.
3. `*(action+0x10) = 0`.
4. `*(uint8*)(host+0x28) = 1`.

Used from unregister (`FUN_0055df40` with host=`*(action+0x10)`) and bulk clear paths `FUN_00560f70` / `FUN_00561580`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `raw/aa_00628f10_FUN_00628f10.md` (+ W24-P append) |
| Annotated | `raw/aa_00628f10_FUN_00628f10.annotated.md` |
| Clean | `reconstructed-exact/ActionHost_RemoveReverseListEntry_Inferred.cpp` |
| Scaffold | `reconstructed-exact/FUN_00628f10.cpp` |
| Function record | `functions/aa_00628f10_ActionHost_RemoveReverseListEntry_Inferred.md` |
| Live decompile | ≡ raw body |
| Live body bytes | `read_memory` @ `0x00628f10` length 84 |
| Parent dual | `A_aa_0055df40_ActionManager_UnregisterAndRelease_Inferred` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte seal (`read_memory` @ `0x00628f10`)

```
mov  edx, [ecx+0x50]        ; count
xor  eax, eax               ; index
... linear find action in [base=*(ecx+0x4c)] ...
or   eax, -1                ; miss
add  dword [ecx+0x50], -1   ; always
... shift-left while index < new_count ...
mov  dword [edi+0x10], 0
mov  byte  [ecx+0x28], 1
ret  4
```

Hex (84 B):

```
8b51505633c085d2578b7c240c7e118b714c393e740d83c00183c6043bc27cf283c8ff834150ff8b51503bc27d168bff8b514c8b7482048d148283c00189323b41507cecc74710000000005fc64128015ec20400
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Body 84 B, `ret 4` | **High** |
| ECX=host, stack=action | **High** |
| +0x4c base / +0x50 count | **High** |
| clear +0x10 / dirty +0x28 | **High** |
| order-preserving shift | **High** |
| Product English | **Inferred** |
| Not-found path safety | **Med** |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps**

---

## 5. Gaps

1. Product / PDB names for host class.
2. Dirty flag `+0x28` consumer.
3. Not-found decrement behavior (intentional vs latent bug).
4. Runtime / differential verification.
