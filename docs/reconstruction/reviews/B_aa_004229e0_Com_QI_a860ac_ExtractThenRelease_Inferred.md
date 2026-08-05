# Review B (skeptical / adversarial): `aa_004229e0` Com_QI_a860ac_ExtractThenRelease_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004229e0` |
| **VA** | `0x004229e0` |
| **Canonical name** | `Com_QI_a860ac_ExtractThenRelease_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004229e0_Com_QI_a860ac_ExtractThenRelease_Inferred.md` |
| **System** | COM / DB / locale bind chain |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as prep `00422d70` | Different IID (`a860ac` vs `a8601c`); extract+Release vs method +0xc | **Falsified** merge |
| 2 | Same as outer `00422d10` | Different IID/method; no CS sandwich here | **Falsified** |
| 3 | Always QI (no gate) | `if (*EBX==0)` wraps whole QI path | **Falsified** always-QI |
| 4 | No Release / leak | SEH path calls vtbl+8 when non-null | **Falsified** leak claim |
| 5 | Pure field copy, no QI | First success work is QI then extract | **Falsified** |
| 6 | RaiseException is debug-only optional | Hard call when length field &lt; 1 | **Attack fails** — real |
| 7 | Decompiler formals complete | unaff_EBX / unaff_EDI | **Agree** formals Tentative |
| 8 | Can skip and call only `00422830` | Parent depends on extract out + hr | **Falsified** skip |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| QI a860ac + Release | **Confirmed** | COM leak / wrong iface |
| Extract + bounds RaiseException | **Confirmed** | Silent wrong data |
| Gate-zero enable | **High** | Extra QI or skip |
| Parent bind-continuation role | **High** | Wrong stage ownership |
| Register formal map | **Tentative** | Port ABI stubs |
| Product interface name | **Open** | Docs only |

---

## 3. Cross-check against raw / live / bytes

```
batch_decompile ≡ clean:
  if (*unaff_EBX == 0) {
    QI(DAT_00a860ac, &p);
    if (hr >= 0) {
      *param_2 = *(*(unaff_EDI+0xc)+0x10);
      if (*(…+4) < 1) RaiseException(0xC000008C,…);
      hr = FUN_00422830();  // vtbl+0x10
    }
    if (p) Release(p);      // vtbl+8
  }
  return hr;
```

### Merge trap

Pipeline stages (do not collapse):

| VA | Stage |
|---|---|
| `00422d70` | prep QI a8601c / +0xc |
| `00422d10` | QI a85fec / +0x1c |
| `004229e0` | **this** — optional extract QI a860ac |
| `0041de50` | bind continuation orchestrator |
| `00422830` | thin vtbl+0x10 (+ optional delete) |

### Gate trap

Treating the gate as “always on” will QI when retail returns 0 without touching COM.

---

## 4. Surviving contract for AutoCore

```
Com_QI_a860ac_ExtractThenRelease(iface, out, gate, ctx…):
  hr = 0
  if *gate == 0:
    hr = QI(IID_a860ac, &p)
    if hr >= 0:
      *out = field_from_ctx
      if length < 1: RaiseException(ARRAY_BOUNDS)
      hr = Vtbl10()
    if p: Release(p)
  return hr
```

**Verdict:** **accept-with-gaps** — adversarial review does not break QI/extract/Release contract; register formals remain Tentative.
