# Review A (reconstruction fidelity): `aa_00517250` Object_RemovePrimaryFxEntry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00517250` |
| **VA** | `0x00517250`–`0x005172c1` (**114 B / `0x72`**) |
| **Canonical name** | `Object_RemovePrimaryFxEntry_Inferred` |
| **Ghidra name** | `FUN_00517250` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B W29-N) |
| **Reviewer role** | Reconstruction fidelity (clean ≡ raw ≡ live decompile ≡ bytes) |
| **Counterpart** | `reviews/B_aa_00517250_Object_RemovePrimaryFxEntry_Inferred.md` |
| **System** | client-fx / object primary NDSpecialFX ptr-vector single-remove |
| **Dual status** | **Present (first full dual)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Remove a single SpecialFX pointer from the object **primary** vector:

1. Gate: `fx != NULL && *(char*)(fx+9) == 0`.
2. Linear search `+0x124`..`+0x128` for pointer equality.
3. Not found → return (no free).
4. Found → `memmove` erase; `*(this+0x128) -= 4`; if entry non-null → TeardownCore + `operator_delete`.

Used for sticky `+0x130` clear during owned-list teardown and by `CVOGObject_SetInteractSpecialFX` when replacing interact FX.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00517250_FUN_00517250.md` (+ W29-N append) |
| Annotated | `docs/reconstruction/raw/aa_00517250_FUN_00517250.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00517250.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/Object_RemovePrimaryFxEntry_Inferred.cpp` |
| Function | `docs/reconstruction/functions/aa_00517250_*` |
| Live | decompile ≡ raw outer CF; `read_memory` full body; bounds `00517250`–`005172c1` |
| Nested seals | TeardownCore `004b99c0`; parent W28-H; SetInteractSpecialFX dual |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 114 B | **Confirmed** | `get_function_by_address` + pad `CC` |
| thiscall + stack `fx*` | **Confirmed** | `mov edx,[esp+4]`; `mov edi,ecx` |
| **`ret 4`** all paths | **Confirmed** | early not-found + success |
| Gate `fx!=0 && +9==0` | **Confirmed** | decomp ≡ bytes |
| Linear search + memmove erase | **Confirmed** | IAT `0x009c652c` |
| TeardownCore ECX = entry | **Confirmed** | `mov ecx,esi` |
| **No** DeactivateClear in body | **Confirmed** | callees: memmove, `004b99c0`, delete only |
| Product English | **Inferred** | `_Inferred` |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Null / +9 gate | **Yes** |
| Empty vector early out | **Yes** |
| Search / not-found return | **Yes** |
| Erase + end shrink | **Yes** |
| TeardownCore + delete | **Yes** |

### 4.1 Sealed contract

```
// thiscall; stack formal fx*; ret 4
void Object_RemovePrimaryFxEntry_Inferred(void *self, void *fx);

// if !fx || fx+9 != 0: return
// find fx in [+0x124, +0x128); if miss: return
// memmove erase; end -= 4
// if entry: TeardownCore(entry); delete entry
```

---

## 5. Callers / callees (live)

**CODE callers:** `FUN_005179e0` (sticky `+0x130`), `CVOGObject_SetInteractSpecialFX` (`0x005179a0`).  
**Callees:** `memmove`, `FUN_004b99c0`, `operator_delete`.

---

## 6. Gaps

1. Product English for `fx+9`.  
2. Not-found sticky handling (caller clears `+0x130` after call in teardown path).  
3. Runtime / bit-exact / differential.

**Verdict:** **accept** — CF, ABI, free gate, erase math, and absence of DeactivateClear sealed; product name inferred only.
