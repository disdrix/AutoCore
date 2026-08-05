# Review B (skeptical / adversarial): `aa_00422d70` Com_Prep_QI_a8601c_Vtbl0c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00422d70` |
| **VA** | `0x00422d70` |
| **Canonical name** | `Com_Prep_QI_a8601c_Vtbl0c_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00422d70_Com_Prep_QI_a8601c_Vtbl0c_Inferred.md` |
| **System** | COM / DB / locale bind chain |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is the outer QI stage (`00422d10`) | Different IID (`a8601c` vs `a85fec`); method +0xc not +0x1c | **Falsified** merge |
| 2 | Method is vtbl+0 only (QI only) | Second call uses **+0xc** | **Falsified** |
| 3 | Failure of QI still runs method | `jl` early leave+return after QI | **Falsified** |
| 4 | No locking | enter/leave around QI+method | **Falsified** lock-free |
| 5 | IID is random immediate | Fixed `DAT_00a8601c` | **Attack fails** |
| 6 | Multi-caller / shared util | Sole xref from `00422d10` | **Attack fails** sole |
| 7 | Same as post-bind `0041de50` | Prep only; no remap / `00421aa0` | **Falsified** merge |
| 8 | Decompiler 2-arg QI is complete | Bytes show 3-arg QI (this, IID, out) | **Agree** decompiler under-arity |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| HRESULT + QI gate | **Confirmed** | Broken bind order |
| IID a8601c + method +0xc | **Confirmed** | Wrong interface method |
| CS sandwich | **High** | Race if stripped |
| Sole prep role for `00422d10` | **Confirmed** | Wrong pipeline docs |
| Product interface name | **Open** | Docs only |
| Teardown exact semantics | **Tentative** | Residual open |

---

## 3. Cross-check against raw / live / bytes

```
batch_decompile ≡ clean scaffold.
read_memory @ 0x00422d70:
  call FUN_00423170
  call FUN_00437cd0          ; enter
  push out / push 00a8601c / push iface / call [vtbl+0]
  test / jl leave_fail
  call [vtbl+0xc]            ; middle 0, third DAT_00a8600c
  call FUN_0041d7b0          ; leave
  ret 4
```

### Merge trap

Do **not** fold into `00422d10` (second IID + +0x1c) or `0041de50` (post-success bind continuation). Pipeline:

```
hr = Com_Prep_QI_a8601c_Vtbl0c()   // THIS VA
if (hr >= 0) Com_QI_ThenVtbl1c remainder (a85fec / +0x1c)
if (hr >= 0) Com_BindContinuation (0041de50)
```

### IID trap

Skipping prep and only doing `a85fec` will not match retail bind order (parent dual already sealed).

---

## 4. Surviving contract for AutoCore

```
Com_Prep_QI_a8601c_Vtbl0c(...):
  Teardown()
  CS_Enter
  hr = QI(IID_a8601c, &p)
  if hr < 0: CS_Leave; return hr
  hr = p->vtbl[+0xc](p, 0, &DAT_00a8600c)
  CS_Leave
  return hr
```

**Verdict:** **accept-with-gaps** — adversarial review does not break prep QI / +0xc / CS contract.
