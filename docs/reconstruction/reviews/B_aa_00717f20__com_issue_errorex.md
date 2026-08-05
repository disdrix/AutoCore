# Review B (skeptical / adversarial): `_com_issue_errorex` @ `0x00717f20`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717f20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00717f20__com_issue_errorex.md` |
| **Verdict** | **accept** library CF; **reject** game-domain ownership |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Game-authored error helper | **Falsified** — MSVC library match |
| 2 | Always attaches IErrorInfo | **Falsified** — many paths leave pei NULL (null punk / QI fail / Supports fail / GetErrorInfo fail) |
| 3 | QI targets arbitrary IID (the param) | **Falsified** — QI is always **ISupportErrorInfo**; param GUID is for SupportsErrorInfo only |
| 4 | Twin of `_com_issue_error` is identical | **Falsified** — simple twin never QI; this may pass non-null pei |
| 5 | `__cdecl` | **Falsified** — `ret 0xC` |
| 6 | Clean wrong on GetErrorInfo polarity | **Attack weak** — decomp: if GetErrorInfo **fails** (`HVar1 != 0`) force pei NULL (standard) |
| 7 | Must port for AutoCore sector/auth | **Falsified** — client COM only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF skeleton | **Confirmed** | Low |
| GUID identity ISupportErrorInfo | **Confirmed** | Wrong QI → always bare raise |
| HRESULT success test style | **High** | `-1 < HVar1` is SUCCEEDED |
| SupportsErrorInfo return test (`iVar2 == 0`) | **High** | S_OK |
| Product-critical for missions/skills | **None** | N/A |

---

## 3. Surviving contract

```
void __stdcall _com_issue_errorex(long hr, IUnknown* punk, const GUID& iid)
{
  IErrorInfo* pei = nullptr;
  if (punk) {
    ISupportErrorInfo* psi = nullptr;
    if (SUCCEEDED(punk->QueryInterface(IID_ISupportErrorInfo, (void**)&psi))) {
      HRESULT sup = psi->InterfaceSupportsErrorInfo(iid);
      psi->Release();
      if (sup == S_OK && FAILED(GetErrorInfo(0, &pei)))
        pei = nullptr;
    }
  }
  (*PTR_FUN_00af8b20)(hr, pei);
}
```

**Verdict:** **accept**; keep with CRT COM twins; do not invent game semantics.
