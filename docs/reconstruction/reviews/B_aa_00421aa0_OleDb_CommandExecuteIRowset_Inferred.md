# Review B (skeptical / adversarial): `aa_00421aa0` OleDb_CommandExecuteIRowset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00421aa0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W18-D) |
| **Counterpart** | `reviews/A_aa_00421aa0_OleDb_CommandExecuteIRowset_Inferred.md` |
| **Verdict** | **accept-with-gaps** (CF + IIDs sealed; decompiler residual noted) |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a generic COM QI helper only | **Falsified** — main work is **Execute** + optional **SetProperties** |
| 2 | SetProperties is invoked on `param_1` (decompiler) | **Falsified** — bytes load iface from **param_4 QI slot**, then `call [ecx+0x10]` with `(cSets, EBX)` |
| 3 | `DAT_00a8608c` is some AA-private GUID | **Falsified** — **IID_IRowset** `{0C733A7C-…}` |
| 4 | `DAT_00a860e8` is IAccessor | **Falsified** — **IID_ICommandProperties** `{0C733A79-…}` (IAccessor is `a860ac` / `0C733A8C` elsewhere) |
| 5 | `DAT_00a860f8` is write-back of rowset pointer | **Falsified** — second **QI** for **IID_IRowsetChange** into `ctx+0x14` |
| 6 | EBX is unused / unaffiliated garbage | **Falsified** — gate + `rgPropertySets`; caller loads parent `param_1` into EBX |
| 7 | cdecl / no stack cleanup | **Falsified** — **`ret 0x10`** stdcall four formals |
| 8 | Always applies SetProperties | **Falsified** — skipped when EBX==0 |
| 9 | Name is PDB-proven product symbol | **Unproven** — **Inferred** from IIDs + CF |
| 10 | Post-QI IRowsetChange failure fails the function | **Falsified** — QI return **not** folded into returned hr |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| IID three-pack identities | **High** | Wrong OLE DB surface entirely |
| Execute arg order | **High** | Rowset/params swapped → hard-to-debug bind fails |
| SetProperties this-ptr | **High** | Crash / no-op if ported from decompiler |
| ctx+0x24 / +0x10 / +0x14 field roles | **High** structural | Wrong ctx layout |
| Product English names | **Low / open** | Docs only |
| DBPARAMS blob layout | **Open** | Param binding wrong |

---

## 3. Cross-check against raw + bytes

```
if (EBX) {
  QI(cmd, ICommandProperties) → SetProperties(cSets, EBX) → Release
}
hr = Execute(cmd, NULL, IID_IRowset, pParams, pcRowsAffected|scratch, ppRowset)
if (ok && rowset) QI(rowset, IRowsetChange, ctx+0x14)  // ignore
return hr
```

Scaffold `FUN_00421aa0.cpp` intentionally tracks **decompiler** CF (including the wrong SetProperties target) for raw≡scaffold hygiene. **Named clean** is the port authority.

---

## 4. Surviving contract for AutoCore

```c
// Port sketch — do not trust Ghidra param_1 as SetProperties this.
HRESULT OleDb_CommandExecuteIRowset(
    BindCtx* ctx,            // EAX
    DBPROPSET* props,        // EBX nullable
    IUnknown** ppRowset,     // &ctx->rowset (+0x10)
    DBPARAMS* params,
    DBROWCOUNT* rowsAffected,// nullable
    ULONG cPropertySets)     // 0 → 1 if props
{
  if (props) {
    ULONG c = cPropertySets ? cPropertySets : 1;
    CComPtr<ICommandProperties> pCP;
    HRESULT hr = GetCommand(ctx)->QueryInterface(IID_ICommandProperties, (void**)&pCP);
    if (FAILED(hr)) return hr;
    hr = pCP->SetProperties(c, props);
    if (FAILED(hr)) return hr;
  }
  DBROWCOUNT scratch;
  if (!rowsAffected) rowsAffected = &scratch;
  HRESULT hr = GetCommand(ctx)->Execute(
      NULL, IID_IRowset, params, rowsAffected, ppRowset);
  if (SUCCEEDED(hr) && ctx->rowset)
    ctx->rowset->QueryInterface(IID_IRowsetChange, (void**)&ctx->rowsetChange);
  return hr;
}
```

---

## 5. Open questions

1. Exact type of `*(ctx+0x24)` (ICommand vs ICommandText).
2. Layout of continuation `pParams` blob.
3. Call-sites beyond `0041de50` (Ghidra sole xref — trust but verify if more dynamic).
4. Runtime golden.

**Verdict:** **accept-with-gaps**
