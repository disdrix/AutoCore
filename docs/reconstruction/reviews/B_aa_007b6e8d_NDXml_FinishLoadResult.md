# Review B (skeptical / adversarial): `aa_007b6e8d` NDXml_FinishLoadResult

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b6e8d` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W19-S) |
| **Counterpart** | `reviews/A_aa_007b6e8d_NDXml_FinishLoadResult.md` |
| **Verdict** | **accept** (CF sealed; decomp residual corrected by bytes) |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus sole-caller xref).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Standalone general-purpose XML logger | **Falsified as sole role** — only called from LoadDocumentFromPath epilogue site |
| 2 | Fail log has only path (decomp as written) | **Falsified** — `push ESI` seals `%d` = HRESULT |
| 3 | Ordinary thiscall with own frame | **Falsified** — uses parent EBP; `ret 8` exits to grand-caller |
| 4 | Always dumps parseError | **Falsified** — only when VARIANT_BOOL ≠ VARIANT_TRUE |
| 5 | Success ignores HRESULT | **Falsified** — success arm `setge al` from ESI≥0 |
| 6 | parseError vtbl is bare IUnknown-only layout | **Falsified** — dual IDispatch (+0x20 url etc.) |
| 7 | Same as resource-miss parse dump inside Load body | **Related but distinct VA** — this unit is the **load-result** epilogue |
| 8 | Clean may drop SysFreeString / Release | **Falsified** — present in raw + live |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| HRESULT in fail log | **High** | silent wrong log / wrong repro |
| ret 8 contract | **High** | stack imbalance if ported as ret 0 |
| VARIANT_TRUE gate | **High** | false success on parse fail |
| Sole-caller ownership | **High** | wrong system factorization |
| Product name | **Open** | structural only |

---

## 3. Cross-check against raw + bytes

- Live decompile ≡ raw control skeleton.
- Entry hex **`56` after path load** is the sealed residual fix; clean includes `unaff_ESI` in log call.
- Epilogue hex ends both paths with **`c2 08 00`**.
- Parent dual already documented return via this VA — consistent.

---

## 4. Surviving contract for AutoCore

```c
// Parent frame still live: EBP+8 doc*, EBP+0xc path*, EBP-0x28 VARIANT_BOOL
// ESI = HRESULT from load
// Returns bool; ret 8 (cleans pXmlDom + pszPath)
bool NDXml_FinishLoadResult(void);

// Port:
// - Log failed HRESULT with path AND code.
// - On VARIANT_BOOL != TRUE: dump parseError fields, free BSTRs, Release, false.
// - Else true iff HRESULT >= 0.
// - Do not invent additional search-path / resource logic here (that is 0x007b6c70).
```

---

## 5. Open questions

1. Whether source lists this as a separate function or compiler-outlined tail.
2. Runtime log capture.

**Verdict:** **accept**
