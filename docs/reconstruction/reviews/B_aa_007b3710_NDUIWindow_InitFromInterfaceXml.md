# Review B (skeptical / adversarial): `aa_007b3710` NDUIWindow_InitFromInterfaceXml

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b3710` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007b3710_NDUIWindow_InitFromInterfaceXml.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Resolves `../interface/` + locale paths | Body never builds paths; only opens given string | **Falsified** — path resolve is `LoadInterfaceFile` (`0x007b0ef0`) |
| 2 | Parses NAME/INCLUDE/TOOLTIP attrs itself | Only calls `ApplyXmlNodeAttributes` | **Falsified** — attr walk is `0x007b1ec0` |
| 3 | Sends sector/UI packets | No `Client_Send*` / bitstream | **Falsified** — pure client UI/XML |
| 4 | `param_1` is the window `this` | Stack[0x4] is path (`%s` logs); window is ECX | **Falsified for stack formal** — Ghidra labels are path/flag, not this |
| 5 | Empty file when `childCount==0` | Loop condition `0 < local_14` skips body; no empty log | **Do not claim** empty log on zero children — only on failed/null child fetch |
| 6 | Direct xrefs = many CALL sites | All bulk xrefs are **DATA** (vtables); callers API empty | **Survives as virtual default** — do not invent named direct callers |
| 7 | Open return 0 means failure | `if (iVar3 != 0)` fail branch; Open returns 1 on load fail | **Survives** — nonzero = fail (**High**) |
| 8 | Clean plate is bit-exact ABI | Clean is 2-arg cdecl-looking rewrite of decompiler | **Gap** — real ABI thiscall + path + flag |

---

## 2. Cross-check: live decompile ≡ raw body

Live `decompile_function(0x007b3710)` (2026-07-29) matches raw / annotated / clean control flow:

- `FUN_00799940` → `NDXml_OpenTaggedDocument(..., "XML")`
- Fail: `DAT_00d1794c=0`, `"Unable to open .xml file for init: %s"`, `FUN_007989b0`
- Success: `DAT_00d1794c=&local_20`, child vfunc `+0x1c`, `ApplyXmlNodeAttributes`, node vfunc `+8`
- Empty: `"Empty interface file %s"` + `vog_LogMessage(...NDUIWindow.cpp, 0x1b9f, 3, ...)`
- Cleanup: vtbl restore, dual Release, `operator_delete[]`

No material drift. Scaffold clean must **not** invent path building or attribute tables.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Role = XML init virtual | **High** | Wrong UI load stage |
| vtbl **+0x3a4** | **High** | Wrong dispatch from LoadInterfaceFile |
| path / flag stack formals | **High** | Wrong call reconstruction |
| Open fail vs empty fail | **High** | Wrong diagnostics |
| Zero-child soft success | **High** | False “empty file” claims |
| ECX `this` in body | **Probable** | Decompiler silence; seal via site + Apply |
| `reinitFlag` product English | **Tentative** | Over-name Apply’s param_4 |
| Server / wire impact | **None** | N/A |

---

## 4. Surviving contract for AutoCore

```
// Client UI — no wire protocol.
// Virtual NDUIWindow::InitFromInterfaceXml @ vtbl+0x3A4 (aa_007b3710)
//
// Entry (from LoadInterfaceFile when path ends in .xml):
//   ECX = window
//   arg0 = resolved filesystem path (char*)
//   arg1 = reinitFlag (LoadInterfaceFile passes 0)
//
// Body:
//   stackDoc = MSXML holder (FUN_00799940 / CoCreate)
//   if NDXml_OpenTaggedDocument(stackDoc, path, "XML") fails:
//       log "Unable to open .xml file for init: %s"; cleanup; return
//   DAT_00d1794c = &stackDoc
//   for i in [0, childCount):
//       node = childList.Get(i)
//       if fail or null: log empty interface @ NDUIWindow.cpp:0x1b9f; break
//       ApplyXmlNodeAttributes(window, node, path, reinitFlag)
//       node->Release()
//   DAT_00d1794c = 0
//   destroy stackDoc (path copy delete[])
//
// Not this unit:
//   path compose ../interface/ + locale  → LoadInterfaceFile
//   attribute name switch table          → ApplyXmlNodeAttributes
//   non-.xml branch vtbl+0x3A0           → sibling virtual
```

---

## 5. Open questions (residual)

1. Recover a saved `this` local or force better decompiler prototype so ECX is visible in the body.
2. Name `FUN_007989b0` / confirm it is the stackDoc dtor twin of the success cleanup block.
3. Whether any derived class **overrides** vtbl+0x3a4 with a non-default implementation (this VA is the shared default only).
4. Runtime: open a known `i_d_*.xml` and confirm child Apply order matches root XML order.

**Verdict:** Adversarial checks kill path-resolve / attr-parse / packet overclaims; sealed contract is open+walk+Apply+cleanup. **accept-with-gaps.**
