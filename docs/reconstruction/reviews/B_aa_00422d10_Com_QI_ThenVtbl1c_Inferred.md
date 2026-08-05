# Review B (skeptical / adversarial): `aa_00422d10` Com_QI_ThenVtbl1c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00422d10` |
| **VA** | `0x00422d10` |
| **Canonical name** | `Com_QI_ThenVtbl1c_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00422d10_Com_QI_ThenVtbl1c_Inferred.md` |
| **System** | COM / DB / locale bind chain |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Pure MultiByteToWideChar lives here | No Win32 string APIs; parent owns MB2WC | **Falsified** — this VA is COM only |
| 2 | Single QI only (no prep) | First call is `FUN_00422d70` (second IID family) | **Falsified** single-QI |
| 3 | Method is vtbl+0 (QI only) | Second call uses **+0x1c** | **Falsified** |
| 4 | Failure of prep still runs QI | `jl` skip after `00422d70` | **Falsified** — early return |
| 5 | No locking | enter/leave pair around QI/method | **Falsified** lock-free claim |
| 6 | IID is random immediate | Fixed `DAT_00a85fec`; only xref from this body | **Attack fails** — dedicated IID |
| 7 | Same as `FUN_0041de50` | Sibling post-success bind; different CF | **Falsified** merge |
| 8 | Decompiler `__fastcall` formals complete | Register/stack noise; parent passes wide | **Agree** formals Tentative |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| HRESULT pipeline + prep gate | **Confirmed** | Dropping prep breaks bind |
| QI IID a85fec + method +0x1c | **Confirmed** | Wrong interface method |
| CS sandwich | **High** | Race if stripped |
| Locale/DB parent usage | **High** | Wrong subsystem ownership |
| Product interface name | **Open** | Docs only |
| Full arg list to +0x1c | **Tentative** | Port stubs incomplete |

---

## 3. Cross-check against raw / live / bytes

```
batch_decompile ≡ raw scaffold CF.
bytes @ 0x00422d10:
  call FUN_00422d70
  test eax,eax / jl skip
  call FUN_00437cd0          ; enter
  push &local / push a85fec / call [vtbl+0]
  ... call [vtbl+0x1c] ...
  call FUN_0041d7b0          ; leave
```

### Merge trap

Do **not** fold this into `0041a810` or `0041de50`. Parent:

```
rc = FUN_00422d10(...);
if (rc >= 0) FUN_0041de50(...);
```

Each VA owns a stage.

### Prep trap

Skipping `FUN_00422d70` (different IID `a8601c`, method +0xc) and only doing QI `a85fec` will not match retail bind order.

---

## 4. Surviving contract for AutoCore

```
Com_QI_ThenVtbl1c(...):
  hr = Prep_QI_a8601c_Vtbl0c()     // 00422d70
  if (hr < 0) return hr
  CS_Enter
  hr = QI(IID_a85fec, &p)
  if (hr >= 0) hr = p->vtbl[0x1c/4](...)
  CS_Leave
  return hr

Parent: Locale_MbcsToWideThenInvoke (0041a810)
Sibling on success: FUN_0041de50

AutoCore must NOT:
  - put MultiByteToWideChar in this VA
  - skip prep or CS
  - call wrong vtbl slot (use +0x1c, not +0)
  - merge with 0041de50
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Prep then QI a85fec then +0x1c | **Agree Confirmed** |
| CS enter/leave | **Agree High** |
| Parent 0041a810 usage | **Agree High** |
| Interface product name Open | **Agree** |
| accept-with-gaps | **Agree** |

---

## 6. Open questions

1. Name GUIDs at `a85fec` / `a8601c`.
2. Document +0x1c method parameters from a successful DB-load dual.
3. Runtime HRESULT capture.

**Verdict:** **accept-with-gaps** — agree with A; block MB2WC/merge/prep-skip mistakes.
