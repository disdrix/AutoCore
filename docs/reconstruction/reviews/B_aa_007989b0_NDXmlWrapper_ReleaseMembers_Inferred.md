# Review B (skeptical / adversarial): `aa_007989b0` NDXmlWrapper_ReleaseMembers

| Field | Value |
|---|---|
| **Stable ID** | `aa_007989b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007989b0_NDXmlWrapper_ReleaseMembers_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Skill-only helper | Callers: UI, SpecialFX, missions, unwinds | **Falsified** — shared NDXml |
| 2 | Full object `delete this` | No `operator_delete(this)` — only members | **Falsified** if claimed heap free of wrapper |
| 3 | Release order +4 then +8 | Bytes: `[esi+8]` first, then `[esi+4]` | **Order is +8 then +4** |
| 4 | `delete` not `delete[]` on +0x10 | `operator_delete[]` | **Must array-delete** |
| 5 | Vtable slot 0 Release | Call is `vtbl+8` → slot **2** (IUnknown::Release) | **Clarify** COM Release |
| 6 | Null COM skipped safely | Both arms test null before call | **Confirmed** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Member layout + Release | **High** | COM leak / double-free |
| No delete-this | **High** | UAF if port adds it wrongly / leak if needed |
| Shared infra | **High** | Over-narrow skill ownership |
| Product type name | **Low** | Doc |

---

## 3. Surviving contract for AutoCore

```csharp
void NDXmlWrapper_ReleaseMembers(NDXmlWrapper* w)
{
    w->vtbl = NDXmlWrapper_vftable;
    if (w->ComB != null) { w->ComB.Release(); w->ComB = null; } // +8 first
    if (w->ComA != null) { w->ComA.Release(); w->ComA = null; } // +4
    delete[] w->Buffer; // +0x10 — array form
    // do NOT free w here unless matching caller ownership
}
```

**Port traps:**

- Scalar `delete` on buffer.
- Releasing +4 before +8 if order-sensitive (match retail: +8 first).
- Treating as skill-cast helper.

---

## 4. Residual gaps

1. COM interface IIDs (ctor dual).
2. Whether some paths are true C++ dtor entry.

**Verdict:** **accept-with-gaps**
