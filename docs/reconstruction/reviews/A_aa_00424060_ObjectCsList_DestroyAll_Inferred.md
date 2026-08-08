# Review A (reconstruction fidelity): `aa_00424060` ObjectCsList_DestroyAll_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00424060` |
| **VA** | `0x00424060`–`0x0042415a` (**251 B** / `0xFB`) |
| **Canonical name** | `ObjectCsList_DestroyAll_Inferred` |
| **Ghidra name** | `FUN_00424060` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9L-E) |
| **Counterpart** | `reviews/B_aa_00424060_ObjectCsList_DestroyAll_Inferred.md` |
| **System** | object core / CS-owned list DestroyAll |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + RTTI COL on UI nested vtbls + product SEH string. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

CS-protected list **DestroyAll**: under CS at `+4`, throw if busy `+0x28`, else drain head `+0x1C` (next `@+8`) with scalar-delete flags=1, zero head/counts, LeaveCS. Product English from SEH string.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9L-E append) | `docs/reconstruction/raw/aa_00424060_FUN_00424060.md` |
| Annotated | `docs/reconstruction/raw/aa_00424060_FUN_00424060.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ObjectCsList_DestroyAll_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00424060.cpp` |
| Family twin | `ObjectCsList_ClearDestroyNoNode4_Inferred` (`0x0051bc90`) — CF clone |
| Product string | `"List Error!  DestroyAll Call Stack:\n%s\n"` @ `0x00a33af0` |
| UI RTTI | `CNDDoubleList` / `CNDDoubleListPtr` of `STextMarkup@CNDUIWindow` on nested vtbls |

---

## 3. Signature (sealed)

```c
// ECX = list*; SEH LAB_009bd790; __chkstk 0x1004; bare RET; void
void __fastcall ObjectCsList_DestroyAll_Inferred(void* list);
```

| Formal | Source | Conf |
|---|---|---|
| list | ECX (`8B F1`) | **High** |
| return | void (no free list) | **High** |
| cleanup | bare `C3` | **High** |

---

## 4. Control flow (bytes authority)

| Stage | Match | Conf |
|---|---|---|
| SEH + chkstk 0x1004 | entry hex | **High** |
| EnterCS(list+4) | `LEA EDI,[ESI+4]; CALL [EnterCS]` | **High** |
| Busy `+0x28` → throw 0x80070005 | disasm + decompile | **High** |
| Drain head `+0x1C`, next `@+8`, dtor(1) | loop body | **High** |
| No node+4 clear | no store to `[EAX+4]` | **High** |
| Zero +0x24/+0x20/+0x1C | epilogue stores | **High** |
| LeaveCS; RET | epilogue hex | **High** |
| Product DestroyAll string | SEH catch block | **High** |

---

## 5. Machine bytes

Body 251 B. Entry: `55 8B EC 6A FF 68 90 D7 9B 00 …`. Epilogue at `0x00424137`: zero triple + LeaveCS + `C3`. Full samples in raw append.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker list method |
| Callers | CNDUIWindow complete (×2 nested), list complete `00424160`, scalar `00424510`, `007aff00`, many UI/list dtors |
| xref_count | 38 |
| Does not | free list / DeleteCS (callers) |

---

## 7. Gaps

1. Shared base demangle for ObjectCsList family (UI specializations sealed as CNDDoubleList TextMarkup).  
2. Full caller-role audit beyond sample.  
3. Runtime / bit-exact / differential — open.

---

## 8. Verdict

CF/ABI/layout/NoNode4/throw/product DestroyAll string sealed. Residual only family demangle breadth → **accept** (product method English present; structural family name keeps `_Inferred`).
