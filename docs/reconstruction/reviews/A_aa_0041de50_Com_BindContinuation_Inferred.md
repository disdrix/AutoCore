# Review A (reconstruction fidelity): `aa_0041de50` Com_BindContinuation_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041de50` |
| **VA** | `0x0041de50` |
| **Canonical name** | `Com_BindContinuation_Inferred` (structural) |
| **Ghidra name** | `FUN_0041de50` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0041de50_Com_BindContinuation_Inferred.md` |
| **System** | COM / DB / locale bind chain |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Post-QI bind continuation** invoked by `Locale_MbcsToWideThenInvoke_Inferred` (`0x0041a810`) only when `FUN_00422d10` returned HRESULT ≥ 0.

`this`/context in **EAX** (decompiler `in_EAX`). Stack formals (Ghidra): four values; parent often passes two in the null-string arm and four in the wide-string arm.

CF:

1. If `*(ctx+0x0c) == 0`: optional descriptor pointer `puVar2 = NULL`.
2. Else:
   - `hr = FUN_004229e0(*(ctx+0x24), &local_c)`; if `hr < 0` **return hr**.
   - Build small stack blob: `local_8 = 1`, `local_4 = *(ctx+0x28)`, `puVar2 = &local_c`.
3. `hr = FUN_00421aa0((int*)(ctx+0x10), puVar2, param_2, param_4)`.
4. If `hr >= 0` **and** `param_3 != 0` **and** `*(ctx+4) != 0`:
   - Remap: `hr = (-(uint)(*(ctx+0x10) != 0) & 0x7fffbffb) + 0x80004005`
     - `*(ctx+0x10) != 0` → **0** (`S_OK`)
     - `*(ctx+0x10) == 0` → **`0x80004005`** (`E_FAIL`)
5. Return `hr`.

This is **not** the QI stage (`00422d10`); it finishes bind and optionally forces a status from object flag `+0x10` when mode char `param_3` and `*(ctx+4)` are set.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_0041de50_*`, `reconstructed-exact/FUN_0041de50.cpp` |
| Function record | `functions/aa_0041de50_FUN_0041de50.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x0041de50` (2026-07-29) |
| Bytes | `read_memory` 96 B — `cmp dword [edi+0xc],0`; calls `004229e0`, `00421aa0` |
| Parent dual | `A_aa_0041a810_Locale_MbcsToWideThenInvoke_Inferred.md` |
| Sibling QI stage | `A_aa_00422d10_Com_QI_ThenVtbl1c_Inferred.md` |
| Sole direct caller (Ghidra) | `FUN_0041a810` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Context in EAX; fields +0x04/+0x0c/+0x10/+0x24/+0x28 | **High** | body |
| Optional path when `+0x0c==0` skips `004229e0` | **Confirmed** | body |
| Fail-fast on `004229e0` hr &lt; 0 | **Confirmed** | body |
| Core work `FUN_00421aa0(ctx+0x10, …)` | **Confirmed** | body |
| Mode char `param_3` gates post-success remap | **Confirmed** | body |
| Remap uses `*(ctx+0x10)` and HRESULT constants | **High** | arithmetic sealed; semantic name of flag Open |
| Called only after `00422d10` success from parent | **High** | parent dual |
| Full product field names | **Open** | |
| Exact meaning of `00421aa0` / `004229e0` | **Open** | sibling duals |

### HRESULT remap (authoritative)

```c
// after successful FUN_00421aa0, if param_3 && *(ctx+4):
hr = ( *(ctx+0x10) != 0 )
     ? 0x00000000                      // 0x7fffbffb + 0x80004005
     : 0x80004005;                     // E_FAIL
```

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| +0xc zero → null optional blob | Yes |
| Else 004229e0 + build local {1, *(+0x28)} | Yes |
| 00421aa0 on ctx+0x10 | Yes |
| Optional remap on param_3 & *(+4) | Yes |
| Two return sites | Yes |

### Recovered CF

```c
// int Com_BindContinuation(ctx /*EAX*/, p1, p2, char mode, p4)
void *opt = NULL;
if (*(ctx+0xc) != 0) {
  hr = FUN_004229e0(*(ctx+0x24), &tmp);
  if (hr < 0) return hr;
  local = { flag:1, data:*(ctx+0x28), ... };
  opt = &local;
}
hr = FUN_00421aa0((int*)(ctx+0x10), opt, p2, p4);
if (hr >= 0 && mode != 0 && *(ctx+4) != 0)
  hr = (*(ctx+0x10) != 0) ? 0 : 0x80004005;
return hr;
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_0041a810` | success-gated continuation after `00422d10` |
| Callee | `FUN_004229e0` | optional prep when `+0xc` set |
| Callee | `FUN_00421aa0` | primary bind/open |

---

## 6. Gaps / open

1. Name `FUN_00421aa0` / `FUN_004229e0` (COM property vs stream Open residual).
2. Seal full formal list vs parent null-string vs wide-string call shapes.
3. Semantic name for `ctx+0x10` flag (exists/open/bound).
4. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — continuation + remap CF High; product types Open.
