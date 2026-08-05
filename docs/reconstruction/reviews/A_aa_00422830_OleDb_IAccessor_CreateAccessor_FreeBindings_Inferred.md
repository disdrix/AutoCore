# Review A (reconstruction fidelity): `aa_00422830` OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00422830` |
| **VA** | `0x00422830`–`0x00422879` |
| **Canonical name** | `OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred` |
| **Ghidra name** | `FUN_00422830` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W20-J) |
| **Counterpart** | `reviews/B_aa_00422830_OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred.md` |
| **System** | COM / OLE DB IAccessor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` body; callers `FUN_00421677`, `FUN_004229e0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Create an OLE DB accessor via **IAccessor::CreateAccessor** (`vtbl+0x10`), then free temporary per-binding heap pointers at **`+0x14`** across `cBindings` rows (stride **`0x48`**). Returns CreateAccessor **HRESULT**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00422830_FUN_00422830.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_00422830_FUN_00422830.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00422830.cpp` |
| Function record | `docs/reconstruction/functions/aa_00422830_FUN_00422830.md` |
| Related dual | `reviews/A_aa_004229e0_Com_QI_a860ac_ExtractThenRelease_Inferred.md` |
| Sibling create | `reviews/A_aa_004231d0_OleDb_CreateAccessorFromBindings_Inferred.md` |
| Live | `decompile_function` `0x00422830`; `read_memory` 128 B; callers/xrefs |

---

## 3. Signature

```c
// Custom ABI — not plain 2-arg __fastcall
// EAX = IAccessor* iface
// ECX = cBindings
// EDX = bindings base
// [esp+4] = phAccessor*, [esp+8] = cbRowSize (inferred labels)
// return HRESULT in EAX; plain RET
```

| Item | Evidence | Conf |
|---|---|---|
| iface EAX | `MOV EDX,[EAX]` vtbl | **High** |
| ECX count / EDX base | `MOV ESI,ECX` / `MOV EDI,EDX` + free loop | **High** |
| Stack formals | `MOV EBX,[ESP+8]` / `[ESP+0x1C]` after pushes | **High** presence; names **Probable** |
| vtbl+0x10 CreateAccessor | `CALL [EDX+0x10]` + IAccessor sibling pattern | **High** slot; product name **Probable** |

---

## 4. Control flow (sealed from bytes)

```
flags = (*(int*)(bindings+0x24) != 0) ? 3 : 2
hr = iface->vtbl[CreateAccessor](iface, flags, cBindings, bindings, cbRowSize, phAccessor, NULL)
for i in 0..cBindings-1:
  operator_delete(*(void**)(bindings + i*0x48 + 0x14))
return hr
```

| Stage | Match | Conf |
|---|---|---|
| flags 2\|3 via SETNE+LEA | **Yes** | **High** |
| 7-arg CreateAccessor push order | **Yes** | **High** |
| Free loop stride 0x48, field +0x14 | **Yes** | **High** |
| Free runs when count≠0 independent of hr | **Yes** | **High** |
| operator_delete returns (not noreturn) | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Hex body:
```
538b5c240856578bf18bfa8b1033c9394f246a00538b5c241c0f95c15357568d4c09025150ff521085f68bd8761683c7148b0750e8b96f060083c40483c73483ee0175ed5f5e8bc35bc3
```

**Decompiler ⇏ full image CF** — raw decompile is a collapsed residual. Clean/annotated restore byte CF. **No `disassemble_bytes` used.**

---

## 6. Call surface (owned unit list only)

| Caller | VA |
|---|---|
| `FUN_00421677` | `0x00421677` |
| `FUN_004229e0` | `0x004229e0` |

Xrefs: **2**.

---

## 7. Confidence

| Claim | Level |
|---|---|
| CreateAccessor + free loop CF | **High** |
| Binding free offset/stride | **High** |
| OLE DB flag/product names | **Probable** |
| Stack formal product names | **Probable** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Exact 0x48-byte binding row typedef vs stock `DBBINDING`.
2. Semantic of `[bindings+0x24]` (first row vs header).
3. Full parent arg provenance in `FUN_00421677` / `004229e0` (not owned).
4. Live HRESULT / SEH behavior.

**Verdict:** **accept-with-gaps** — image CF sealed; product naming remains inferred.
