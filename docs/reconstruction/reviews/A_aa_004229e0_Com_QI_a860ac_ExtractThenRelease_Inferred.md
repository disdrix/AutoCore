# Review A (reconstruction fidelity): `aa_004229e0` Com_QI_a860ac_ExtractThenRelease_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004229e0` |
| **VA** | `0x004229e0` |
| **Canonical name** | `Com_QI_a860ac_ExtractThenRelease_Inferred` (structural) |
| **Ghidra name** | `FUN_004229e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_004229e0_Com_QI_a860ac_ExtractThenRelease_Inferred.md` |
| **System** | COM / DB / locale bind chain |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

COM helper on the bind-continuation path: when a gate flag is zero, **QueryInterface** against IID `DAT_00a860ac`, extract a field into the out-pointer, run `FUN_00422830` (vtbl+0x10 method), then **Release** the QI result (vtbl+8).

Called from `Com_BindContinuation_Inferred` (`0x0041de50`) when `*(ctx+0x0c) != 0`:

```
hr = FUN_004229e0(*(ctx+0x24), &local_c);
if (hr < 0) return hr;
// build {1, *(ctx+0x28)} blob for FUN_00421aa0
```

Also xref from `FUN_004211e9` (sibling COM path).

Recovered CF (decompile; register-heavy):

1. SEH frame install (`ExceptionList` / `LAB_009bcd88`).
2. `hr = 0` default.
3. If `*gate == 0` (`unaff_EBX` — caller-provided gate):
   - QI: `(*iface->vtbl)(iface, &DAT_00a860ac, &pIface)`.
   - On success (`hr >= 0`):
     - `*out = *(*(ctx_like + 0xc) + 0x10)` — extract dword into `param_2`.
     - If `*(*(ctx_like + 0xc) + 4) < 1`: `RaiseException(0xC000008C, …)` (array bounds / STATUS_ARRAY_BOUNDS_EXCEEDED).
     - `hr = FUN_00422830()` — method at **vtbl+0x10** (fastcall helper).
   - SEH unwind: if `pIface != NULL`, `pIface->Release()` (vtbl+8).
4. Restore ExceptionList; return hr.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_004229e0_*`, `reconstructed-exact/FUN_004229e0.cpp` |
| Function record | `functions/aa_004229e0_FUN_004229e0.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x004229e0` (2026-07-29) |
| Callee | `FUN_00422830` — `(*vtbl+0x10)()` then optional `operator_delete` |
| Parent dual | `A_aa_0041de50_Com_BindContinuation_Inferred.md` |
| Callers | `FUN_0041de50` @ `0041de69`; `FUN_004211e9` |

**Not performed:** disassemble_bytes, Launcher, GUID product decode, runtime.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| QI IID = `DAT_00a860ac` | **Confirmed** | decompile |
| Gate `*EBX==0` enables QI path; else hr stays 0 | **High** | body; registers from parent |
| Extract to `*param_2` from `*(…+0xc)+0x10` | **High** | body |
| Bounds check then `RaiseException(0xC000008C)` | **Confirmed** | body |
| Post-success `FUN_00422830` (vtbl+0x10) | **Confirmed** | decompile pair |
| Release QI out via vtbl+8 | **Confirmed** | SEH cleanup |
| Used by bind continuation when ctx+0xc set | **High** | parent dual |
| Full formal/register map (EBX/EDI sources) | **Tentative** | decompiler unaff_* |
| Product interface English | **Open** | |
| clean ≡ raw CF | **High** | scaffold |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH install | Yes |
| Gate-zero → QI a860ac | Yes |
| Success extract + bounds + 00422830 | Yes |
| Release on non-null | Yes |
| Return hr (0 if gate non-zero) | Yes |

### Recovered CF

```c
// HRESULT Com_QI_a860ac_ExtractThenRelease(IUnknown* iface, uint32_t* outExtract, … gate/ctx regs)
HRESULT hr = 0;
if (*gate == 0) {
  IUnknown* p = nullptr;
  hr = iface->QueryInterface(IID_a860ac, (void**)&p);
  if (hr >= 0) {
    *outExtract = *(uint32_t*)(*(ctx+0xc) + 0x10);
    if (*(int*)(*(ctx+0xc) + 4) < 1)
      RaiseException(0xC000008C, 1, 0, NULL);
    hr = Method_Vtbl10_00422830(...);
  }
  if (p) p->Release();
}
return hr;
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_0041de50` | bind continuation optional extract |
| Caller | `FUN_004211e9` | sibling COM path |
| Callee | vtbl[0] / vtbl[+8] | QI / Release |
| Callee | `FUN_00422830` | vtbl+0x10 method wrapper |
| Callee | `RaiseException` | bounds fail |

---

## 6. Gaps / open

1. Decode GUID `DAT_00a860ac`.
2. Seal EBX/EDI formal origins (parent-only High vs absolute).
3. Exact field English for extract slot `+0x10` / length `+4`.
4. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — QI `a860ac` + extract + Release CF sealed; register formals Tentative.
