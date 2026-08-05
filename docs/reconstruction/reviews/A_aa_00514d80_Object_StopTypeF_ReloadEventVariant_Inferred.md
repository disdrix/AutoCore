# Review A (reconstruction fidelity): `aa_00514d80` Object_StopTypeF_ReloadEventVariant_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00514d80` |
| **VA** | `0x00514d80`–`0x00514df3` (**116 B / `0x74`**) |
| **Canonical name** | `Object_StopTypeF_ReloadEventVariant_Inferred` |
| **Ghidra name** | `FUN_00514d80` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B W28-H) |
| **Reviewer role** | Reconstruction fidelity (clean ≡ raw ≡ live decompile ≡ bytes) |
| **Counterpart** | `reviews/B_aa_00514d80_Object_StopTypeF_ReloadEventVariant_Inferred.md` |
| **System** | client-fx / type-0xF stop + event-variant reload |
| **Dual status** | **Present (first full dual)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Type-filtered SpecialFX stop + reload on the same primary object vector used by teardown (`+0x124/+0x128`):

1. For each FX* with type `*(fx+0x28) == 0x0F` → `NDSpecialFX_StopFinalize_Inferred(fx)` (**no delete**).
2. `linked = *(this+0xA8)`; `FUN_004eb3b0(linked)` Ensure catalog resource.
3. If `*(linked+0x88) != 0`: Ensure again; `fx = FxMaster_LoadEventVariant_Inferred(catalog, 0xF, 1, -1)`; if non-null → `this->vtbl[+0xF8](fx, 1, 0)`.

Closes residual from W27-D (manager caller of StopFinalize type-0xF batch) and sealed LoadEventVariant dual.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00514d80_FUN_00514d80.md` (+ W28-H append) |
| Annotated | `docs/reconstruction/raw/aa_00514d80_FUN_00514d80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00514d80.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/Object_StopTypeF_ReloadEventVariant_Inferred.cpp` |
| Function | `docs/reconstruction/functions/aa_00514d80_*` |
| Live | decompile ≡ raw outer CF; `read_memory` full body; bounds `00514d80`–`00514df3` |
| Nested seals | W27-D StopFinalize; LoadEventVariant `004a16d0`; thunk `00581500` |

**Not performed:** Launcher, runtime, bit-exact, dual of Ensure/`vtbl+0xF8` target.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 116 B | **Confirmed** | bounds + pad `CC` |
| thiscall impl plain `RET` | **Confirmed** | `C3` |
| Type gate `+0x28 == 0x0F` | **Confirmed** | `cmp dword [ecx+0x28], 0x0F` |
| StopFinalize ECX = entry | **Confirmed** | `mov ecx,[edi]` before call |
| Ensure ECX = `*(this+0xA8)` | **Confirmed** | `mov edi,[esi+0xA8]; mov ecx,edi` |
| LoadEvent pack `(0xF,1,-1)` | **Confirmed** | `push -1; push 1; push 0xF` |
| Catalog ECX = `*(linked+0x88)` | **Confirmed** | `mov ecx,[edi+0x88]` |
| Virtual `[vtbl+0xF8](fx,1,0)` | **Confirmed** | `call [edx+0xF8]` |
| Public thunk `ret 4` | **Confirmed** | `FUN_00581500` end |
| Product English | **Inferred** | `_Inferred` |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Type-0xF StopFinalize walk | **Yes** |
| Ensure linked host | **Yes** |
| Gate on catalog `+0x88` | **Yes** |
| LoadEventVariant reload | **Yes** |
| Virtual apply | **Yes** |
| No free/delete of fx in this unit | **Yes** |

### 4.1 Sealed contract

```
// thiscall impl; plain ret
// public virtual thunk 00581500: vb-adjust this; ret 4 (1 ignored stack dword)
void Object_StopTypeF_ReloadEventVariant_Inferred(void *self);

// for fx in primary vector:
//   if type(+0x28)==0xF: StopFinalize(fx)
// Ensure(*(self+0xA8)); if catalog:
//   Ensure again; fx=LoadEventVariant(catalog,0xF,1,-1)
//   if fx: vtbl[+0xF8](self, fx, 1, 0)
```

---

## 5. Callers / callees (live)

**CODE callers:** `FUN_00581500` only (MI thunk).  
**Callees:** `FUN_004ba0a0`, `FUN_004eb3b0`×2, `FUN_004a16d0`, virtual `+0xF8`.

---

## 6. Gaps

1. Product name for event 0xF and `vtbl+0xF8`.  
2. Full type of `+0xA8` linked host (not OWN).  
3. Runtime / bit-exact / differential.

**Verdict:** **accept** — CF, ABI, type gate, LoadEvent pack, and virtual apply sealed; product name inferred only.
