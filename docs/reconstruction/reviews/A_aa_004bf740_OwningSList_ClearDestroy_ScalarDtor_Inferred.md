# Review A (reconstruction fidelity): `aa_004bf740` OwningSList_ClearDestroy_ScalarDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bf740` |
| **VA** | `0x004bf740`–`0x004bf76f` exclusive (**47 B**) |
| **Canonical name** | `OwningSList_ClearDestroy_ScalarDtor_Inferred` |
| **Ghidra name** | `FUN_004bf740` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-B) |
| **Counterpart** | `reviews/B_aa_004bf740_OwningSList_ClearDestroy_ScalarDtor_Inferred.md` |
| **System** | owning singly-linked list clear |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (body hex) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Destroy every node in an owning singly-linked list hosted at ECX: head at `+0x04`, count at `+0x0c`. Each node is unlinked then destroyed via **scalar-deleting destructor** `vtbl[0](1)`. Does not free the list host.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-B append) | `docs/reconstruction/raw/aa_004bf740_FUN_004bf740.md` |
| Annotated | `docs/reconstruction/raw/aa_004bf740_FUN_004bf740.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/OwningSList_ClearDestroy_ScalarDtor_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004bf740.cpp` |
| Function record | `docs/reconstruction/functions/aa_004bf740_OwningSList_ClearDestroy_ScalarDtor_Inferred.md` |
| Consumer | `aa_004be2a0` ListTrackedObj_CompleteDtor (W30-P) |
| Live | decompile ≡ raw ≡ bytes for loop/ABI |

---

## 3. Signature (sealed)

```c
// ECX = list host; bare C3; void
void __fastcall OwningSList_ClearDestroy_ScalarDtor_Inferred(void* host);
```

| Formal | Source | Conf |
|---|---|---|
| host | ECX (`56 8B F1`) | **High** |
| return | void | **High** |
| cleanup | bare `C3` | **High** |

---

## 4. Control flow (bytes authority)

```
push esi; mov esi, ecx
if *(esi+4)==0: goto done
loop:
  ecx = *(esi+4)
  if ecx==0: skip dtor block
  else:
    *(esi+4) = *(ecx+4)     // head = next
    push 1; call [*(ecx)]   // vtbl[0] scalar dtor
    *(esi+0xc)--
  if *(esi+4)!=0: goto loop
done:
  pop esi; ret
```

| Stage | Match | Conf |
|---|---|---|
| Empty-head fast-out | decompile ≡ `83 7E 04 00; 74 24` | **High** |
| Unlink next@node+4 | decompile ≡ `8B 41 04; 89 46 04` | **High** |
| Scalar dtor `push 1; call [edx]` | decompile ≡ `6A 01; FF 12` | **High** |
| Count-- @+0xc | decompile ≡ `83 46 0C FF` | **High** |
| No static callees | analyze_function_complete | **High** |
| Sole CALL from ListTrackedObj | xref `004be321` | **High** |

---

## 5. Gaps

1. Product/MSVC demangle for node type T and list host class.  
2. Whether count always matches chain length (no assert).  
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — CF/ABI/offsets/dtor pattern **sealed**.
