# Review A (reconstruction fidelity): `aa_0062a410` ActionManager_NotifyListenersAndCompact_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0062a410` |
| **VA** | `0x0062a410`–`0x0062a444` exclusive (**52** B) |
| **Canonical name** | `ActionManager_NotifyListenersAndCompact_Inferred` |
| **Ghidra symbol** | `FUN_0062a410` |
| **Prior / alias** | scaffold `FUN_0062a410` / Named_CalleeOf_* |
| **Review date** | `2026-07-29` (W24-P OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0062a410_ActionManager_NotifyListenersAndCompact_Inferred.md` |
| **System** | vehicle / world action lifecycle |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, callers/callees (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Notify action-manager listeners then compact the listener pointer vector:

1. `count = *(manager+0x40)`; reverse `i = count-1 … 0`.
2. `listener = *(*(manager+0x3c) + i*4)`; if non-null, `(*listener->vtbl + 0xC)(action)`.
3. Tail `JMP FUN_005fff20` with `EAX = manager+0x3c` (strip nulls).

Called only from `ActionManager_UnregisterAndRelease_Inferred` (`FUN_0055df40`) in the live Ghidra caller set.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `raw/aa_0062a410_FUN_0062a410.md` (+ W24-P append) |
| Annotated | `raw/aa_0062a410_FUN_0062a410.annotated.md` |
| Clean | `reconstructed-exact/ActionManager_NotifyListenersAndCompact_Inferred.cpp` |
| Scaffold | `reconstructed-exact/FUN_0062a410.cpp` |
| Function record | `functions/aa_0062a410_ActionManager_NotifyListenersAndCompact_Inferred.md` |
| Live decompile | ≡ raw body |
| Live body bytes | `read_memory` @ `0x0062a410` length 52 |
| Parent dual | `A_aa_0055df40_ActionManager_UnregisterAndRelease_Inferred` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte seal (`read_memory` @ `0x0062a410`)

```
push esi / push edi
mov  edi, [esp+0xC]       ; manager
mov  esi, [edi+0x40]      ; count
add  edi, 0x3c            ; vec header
sub  esi, 1 / js after
push ebx
mov  ebx, [esp+0x14]      ; action
loop:
  mov  eax, [edi]         ; base
  mov  ecx, [eax+esi*4]   ; listener
  test ecx / jz next
  mov  edx, [ecx]
  push ebx / call [edx+0xC]
next:
  sub  esi, 1 / jns loop
pop  ebx
after:
mov  eax, edi             ; EAX = manager+0x3c
pop  edi / pop esi
jmp  FUN_005fff20
```

Hex (52 B):

```
56578b7c240c8b774083c73c83ee01781a538b5c24148b078b0cb085c974068b1153ff520c83ee0179ec5b8bc75f5ee9dc5afdff
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Body 52 B, bounds `0062a410`–`0062a444` excl. | **High** |
| cdecl 2 stack args (parent ADD ESP,8) | **High** |
| +0x3c base / +0x40 count | **High** |
| reverse walk; null skip; vtbl+0xC | **High** |
| EAX=vec tail compact residual vs decomp | **High** |
| Product English | **Inferred** |
| Nested dual `005fff20` | **Open** (not owned) |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps**

---

## 5. Gaps

1. Product / PDB names for manager and listener interfaces.
2. Dual seal of `FUN_005fff20`.
3. Semantic label of vtbl+0xC (remove/notify).
4. Runtime / differential verification.
