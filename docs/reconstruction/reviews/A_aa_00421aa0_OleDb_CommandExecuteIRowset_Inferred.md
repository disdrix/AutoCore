# Review A (reconstruction fidelity): `aa_00421aa0` OleDb_CommandExecuteIRowset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00421aa0` |
| **VA** | `0x00421aa0`–`0x00421b4f` |
| **Canonical name** | `OleDb_CommandExecuteIRowset_Inferred` (structural) |
| **Ghidra name** | `FUN_00421aa0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W18-D) |
| **Counterpart** | `reviews/B_aa_00421aa0_OleDb_CommandExecuteIRowset_Inferred.md` |
| **System** | COM / OLE DB command execute |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Primary **command Execute** step on the bind-continuation path (`Com_BindContinuation_Inferred` `0x0041de50`).

1. If **EBX ≠ 0** (property-set pointer from parent `param_1`):
   - Coerce `cPropertySets` (`param_4`) **0 → 1**.
   - Clear out-slot; **QI** `*(ctx+0x24)` for **IID_ICommandProperties** (`DAT_00a860e8`).
   - Fail → Release slot, return hr.
   - **SetProperties** at **vtbl+0x10** on the QI iface with `(cSets, EBX)`.
   - Release QI iface; fail → return hr.
2. If `pcRowsAffected` (`param_3`) is null, use 4-byte stack scratch (`push ecx` slot).
3. **Execute** at **vtbl+0x10** on `*(ctx+0x24)`:
   `(pUnkOuter=0, riid=IID_IRowset DAT_00a8608c, pParams=param_2, pcRowsAffected, ppRowset=param_1)`.
4. If hr ≥ 0 and `*(ctx+0x10) ≠ 0`: **QI** that object for **IID_IRowsetChange** (`DAT_00a860f8`) into **`ctx+0x14`** (return ignored).
5. Return Execute HRESULT.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00421aa0_*`, `reconstructed-exact/FUN_00421aa0.cpp`, `OleDb_CommandExecuteIRowset_Inferred.cpp` |
| Function record | `functions/aa_00421aa0_OleDb_CommandExecuteIRowset_Inferred.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x00421aa0` (2026-07-29) ≡ raw 2026-07-23 |
| Bytes | `read_memory` 256 B — body through `ret 0x10` |
| Sole caller | `FUN_0041de50` @ `0x0041de9e` (bytes wire EAX=ctx, EBX=parent.param_1) |
| Parent dual | `A_aa_0041de50_Com_BindContinuation_Inferred.md` |
| Helpers | `FUN_00437cd0` ClearSlot; `FUN_0041d7b0` ReleaseIfNonNull |

**Not performed:** `disassemble_bytes`, Launcher, runtime.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ctx in EAX; props ptr in EBX | **Confirmed** | bytes + caller |
| stdcall 4 args / `ret 0x10` | **Confirmed** | epilogue |
| IID_ICommandProperties / IRowset / IRowsetChange | **Confirmed** | GUID bytes + OLE DB catalog |
| SetProperties on QI iface (not param_1) | **Confirmed** | `FF 51 10` after load from slot |
| Execute shape (0, IID_IRowset, p2, p3, p1) | **Confirmed** | push order |
| Post-success QI into ctx+0x14 | **Confirmed** | `add edi,0x14` |
| Decompiler SetProperties target | **Falsified vs bytes** | residual documented |
| Exact DBPARAMS product layout | **Open** | continuation blob |
| ICommand vs ICommandText English | **Open** | same Execute slot |
| clean scaffold ≡ decompiler (incl. bug) | **Yes** | named clean is byte-correct |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Live decompile ≡ raw 2026-07-23 | **Yes** |
| EBX gate for properties path | **Yes** |
| QI props → SetProperties → Release | **Yes** (bytes for this-ptr) |
| Execute + optional IRowsetChange QI | **Yes** |
| Three HRESULT return sites | **Yes** |

### Recovered CF

```c
// EAX=ctx, EBX=rgPropertySets
if (EBX) {
  c = param_4 ? param_4 : 1;
  clear(slot);
  hr = QI(*(ctx+0x24), IID_ICommandProperties, &slot);
  if (FAILED(hr)) { Release(slot); return hr; }
  hr = SetProperties(slot, c, EBX);  // vtbl+0x10
  Release(slot);
  if (FAILED(hr)) return hr;
}
if (!param_3) param_3 = &scratch;
hr = Execute(*(ctx+0x24), 0, IID_IRowset, param_2, param_3, param_1);
if (SUCCEEDED(hr) && *(ctx+0x10))
  QI(*(ctx+0x10), IID_IRowsetChange, ctx+0x14); // ignore hr
return hr;
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_0041de50` | sole bind continuation |
| Callee | `FUN_00437cd0` / `FUN_0041d7b0` | com_ptr zero / Release |
| Callee | COM vtbl | QI / SetProperties / Execute |

---

## 6. Gaps / open

1. Product English for command iface class at `ctx+0x24`.
2. Full layout of optional `pParams` blob from `004229e0` extract + `{1, *(ctx+0x28)}`.
3. Whether IRowsetChange QI failure is ever observed (ignored).
4. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — OLE DB execute contract + IIDs sealed; product field English Open.
