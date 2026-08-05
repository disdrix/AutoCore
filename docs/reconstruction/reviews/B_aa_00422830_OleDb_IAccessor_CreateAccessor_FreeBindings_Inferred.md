# Review B (skeptical / adversarial): `aa_00422830` OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00422830` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00422830_OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Decompiler body is complete | Bytes show multi-push CreateAccessor + counted free loop | **Falsified** decompiler completeness — **bytes win** |
| 2 | Thin “call vtbl+0x10 only” helper | Free loop + flags derivation present | **Falsified** if claimed thin-only |
| 3 | `operator_delete` is noreturn | Loop continues after call; `ADD ESP,4` | **Falsified** Ghidra WARNING |
| 4 | `__fastcall` 2-arg only | EAX iface + 2 stack args required | **Over-narrow** — multi-reg + stack ABI |
| 5 | Always flags=2 | `SETNE`/`LEA` yields 2 or 3 | **Falsified** constant-2 |
| 6 | Free only on success HRESULT | Loop gated only on count≠0 | **Falsified** success-only free |
| 7 | Stock `DBBINDING` size 0x34 | Image stride 0x48 | **Clarify** — image row ≥/≠ stock layout |
| 8 | Name must be mission-related | Callers are OleDb/QI bind path (`DAT_00a860ac`) | **Reject** mission-chain alias as primary |
| 9 | PASSBYREF / phAccessor labels exact | Inferred from OLE DB + push order | **Needs-more-evidence** for product English — does not break CF seal |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CreateAccessor call + free loop | **High** | DB load use-after-free / leak ports |
| flags 2\|3 | **High** | Wrong accessor bind mode |
| stride 0x48 / +0x14 | **High** | Heap corruption if wrong |
| Stack formal names | **Medium** | Doc-only risk |
| IAccessor product identity | **High** (IID sibling) / names **Medium** | Mis-tag COM iface |

---

## 3. Cross-check against raw / bytes

```
raw decompile:  (*vtbl+0x10)(); if (param_1) delete *(param_2+0x14); return
bytes:          push 7 args; CALL [vtbl+0x10]; loop delete *(p+0x14); p+=0x48; count--
```

Clean **must not** ship decompiler-collapsed single-delete as authoritative. Annotated + named clean follow bytes.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape (HRESULT path; server may not need OLE DB at all)
int CreateAccessorThenFreeBindMem(
    IAccessor iface, int cBindings, byte[] bindings, int bindStride = 0x48,
    int flagsFieldOff = 0x24, int freePtrOff = 0x14)
{
    int flags = BitConverter.ToInt32(bindings, flagsFieldOff) != 0 ? 3 : 2;
    int hr = iface.CreateAccessor(flags, cBindings, bindings, cbRowSize, out accessor, null);
    for (int i = 0; i < cBindings; i++) {
        // free pointer at bindings + i*stride + 0x14  (retail always if cBindings!=0)
    }
    return hr;
}
```

**Port traps to reject:**

- Trusting Ghidra decompile alone for this VA.
- Skipping free on failed HRESULT.
- Using stride 0x34 stock DBBINDING without image proof.
- Treating unit as mission gameplay logic.

---

## 5. Residual gaps (do not fully block CF seal)

1. Product English for flag bit 0x1 and stack formals.
2. Binding row schema documentation.
3. Parent residual wiring in `00421677` / `004229e0`.
4. Runtime / bit-exact.

---

## Verdict

**accept-with-gaps** — adversarial review breaks decompiler-complete and thin-wrapper claims; cannot break the byte-level CreateAccessor + free-loop kernel. Gaps are naming/typedef, not control flow.
