# Review B (skeptical / adversarial): `aa_0041de50` Com_BindContinuation_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041de50` |
| **VA** | `0x0041de50` |
| **Canonical name** | `Com_BindContinuation_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0041de50_Com_BindContinuation_Inferred.md` |
| **System** | COM / DB / locale bind chain |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is QueryInterface | No IID constants; no vtbl[0] QI | **Falsified** |
| 2 | Always runs `FUN_004229e0` | Gated by `*(ctx+0xc)!=0` | **Falsified** always-run |
| 3 | Remap always applies | Requires `hr>=0 && param_3 && *(ctx+4)` | **Falsified** unconditional remap |
| 4 | Remap: +0x10 set → E_FAIL | Arithmetic: +0x10 set → **0**; clear → **E_FAIL** | **Falsified** inverted reading |
| 5 | Same unit as `00422d10` | Parent sequences QI then this | **Falsified** merge |
| 6 | Multi-caller public API | Ghidra callers: only `0041a810` | **Agree** narrow surface |
| 7 | param_3 is “wide string pointer” | Body tests **char** ≠ 0 only | **Falsified** pointer claim — mode flag |
| 8 | Scaffold clean invents CF | Matches live decompile | **Attack fails** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Optional +0xc / 004229e0 gate | **Confirmed** | Wrong optional bind |
| 00421aa0 primary | **Confirmed** | Miss real work |
| Remap polarity (+0x10 → 0 else E_FAIL) | **High** | Inverted success/fail |
| Mode char + *(+4) gate | **Confirmed** | Always-fail ports |
| EAX context ABI | **High** | Wrong this |
| Formal map completeness | **Tentative** | Parent arm differences |
| Product names | **Open** | |

---

## 3. Cross-check against raw / live / bytes

```
batch_decompile ≡ raw/clean scaffold CF.
bytes: cmp [edi+0xc],0 ; call 004229e0 ; call 00421aa0 ;
post: test mode char; compare [ctx+4]; compute hr from [ctx+0x10]
HRESULT pack uses 0x80004005 / 0x7fffbffb — classic E_FAIL family.
```

### Polarity trap

```
hr = (-(uint)(*(ctx+0x10)!=0) & 0x7fffbffb) + 0x80004005;
// *(+0x10)!=0  =>  0x00000000  (S_OK)
// *(+0x10)==0  =>  0x80004005  (E_FAIL)
```

Do **not** invert this when porting “already open” style checks.

### Stage trap

`00422d10` = prep+QI+method. **`0041de50` = continuation only.** Parent owns ordering.

---

## 4. Surviving contract for AutoCore

```
Com_BindContinuation(ctx/*EAX*/, ..., modeChar, ...):
  opt = null
  if (*(ctx+0xc)) {
    hr = FUN_004229e0(*(ctx+0x24), &tmp); if (hr<0) return hr
    opt = &{1, *(ctx+0x28), ...}
  }
  hr = FUN_00421aa0(ctx+0x10, opt, ...)
  if (hr>=0 && modeChar && *(ctx+4))
    hr = (*(ctx+0x10) != 0) ? 0 : 0x80004005
  return hr

Caller: Locale_MbcsToWideThenInvoke after Com_QI_ThenVtbl1c success

AutoCore must NOT:
  - QI here
  - invert +0x10 remap polarity
  - skip optional 004229e0 gate
  - treat param_3 as wide LPCWSTR
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Continuation after 00422d10 | **Agree High** |
| Optional 004229e0 when +0xc | **Agree Confirmed** |
| Remap polarity | **Agree High** (A’s arithmetic note correct) |
| Mode char gate | **Agree Confirmed** |
| accept-with-gaps | **Agree** |

---

## 6. Open questions

1. Dual `FUN_00421aa0` / `FUN_004229e0`.
2. Why parent null-string arm passes fewer stack args (stack noise vs real overload).
3. Runtime.

**Verdict:** **accept-with-gaps** — agree with A; block QI-merge and inverted HRESULT remap.
