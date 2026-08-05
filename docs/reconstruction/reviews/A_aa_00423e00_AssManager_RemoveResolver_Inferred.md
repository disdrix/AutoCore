# Review A (reconstruction fidelity): `aa_00423e00` AssManager_RemoveResolver_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423e00` |
| **VA** | `0x00423e00`–`0x00423e43` (**68 B**) |
| **Canonical name** | `AssManager_RemoveResolver_Inferred` |
| **Ghidra name** | `FUN_00423e00` |
| **Review date** | `2026-07-29` (W29-C dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-C) |
| **Counterpart** | `reviews/B_aa_00423e00_AssManager_RemoveResolver_Inferred.md` |
| **System** | `assets` / `assManager` |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 68 B); caller `007b65d0`; callees find/log/erase |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

**assManager** remove-resolver worker:

1. Store key from **EAX**; set container **ESI = ECX + 0x58**.
2. `FUN_0043e5b0(&key)` with **EAX = container** → membership bool.
3. On miss: `vog_LogMessage(assManager.cpp, 0x27b, 3, "Removing resolver not found")` and return.
4. On hit: `FUN_0043c550(&key)` / `GuardedVector_EraseFirstEqual` with **ESI = container**.

Soft-fail (log) on miss — **not** a throw path.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00423e00_FUN_00423e00.md` (+ 2026-07-29 W29-C append) |
| Annotated | `docs/reconstruction/raw/aa_00423e00_FUN_00423e00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssManager_RemoveResolver_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00423e00.cpp` |
| Function record | `docs/reconstruction/functions/aa_00423e00_FUN_00423e00.md` |
| Named record | `docs/reconstruction/functions/aa_00423e00_AssManager_RemoveResolver_Inferred.md` |
| Live | decompile ≡ raw CF; body 68 B; strings `read_memory` @ `0x00a9e888` / `0x00a9e930` |
| Caller bytes | `007b65d0`: `MOV EAX,[EBX+8]`; `MOV ECX,[DAT_00d1f058]`; `CALL 00423e00` |
| Context | Erase callee sealed W28-C; find sibling pattern in parent for `[EBX+0xC]` |

---

## 3. Signature (sealed)

```c
// ECX=assManager*; EAX=key; plain RET
void AssManager_RemoveResolver_Inferred(void *assManager /*ECX*/, int key /*EAX*/);
```

| Slot | Source | Conf |
|---|---|---|
| assManager | **ECX** | **High** |
| key | **EAX** | **High** |
| container | `this+0x58` → ESI | **High** |
| cleanup | plain `RET` | **High** |
| miss | log + return | **High** |
| hit | EraseFirstEqual | **High** |

Decompiler `void(void)` is incomplete — do not trust as full ABI.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
key = EAX; cont = this+0x58
if !Contains(cont, key):
  vog_LogMessage(assManager.cpp, 0x27b, 3, "Removing resolver not found")
  return
EraseFirstEqual(cont, key)
return
```

| Stage | Match | Conf |
|---|---|---|
| ECX this / EAX key | **Yes** | **High** |
| +0x58 container | **Yes** | **High** |
| Find then branch | **Yes** | **High** |
| Soft log miss | **Yes** | **High** |
| Erase hit | **Yes** | **High** |
| Product method English | shape only | **Inferred** |

---

## 5. Gaps / open

1. Product/PDB method name on assManager class.
2. Exact resolver key type beyond dword equality (object* vs id).
3. Nested find/erase internals owned by other duals (not re-sealed here).
4. Runtime / bit-exact / differential.

**Verdict:** **accept**
