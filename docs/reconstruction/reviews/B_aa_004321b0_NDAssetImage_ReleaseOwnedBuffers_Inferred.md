# Review B (skeptical / adversarial): `aa_004321b0` NDAssetImage_ReleaseOwnedBuffers_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004321b0` |
| **VA** | `0x004321b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_004321b0_NDAssetImage_ReleaseOwnedBuffers_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always frees everything | Gate on +0x38 | **Falsified as unconditional** — busy path returns 0 with **zero** frees |
| 2 | thiscall ECX object | Decompiler `void` / unaff_ESI | **Falsified as ECX** — all refs are **ESI**; callers set ESI |
| 3 | Stack formal “self” | Create/transfer callers pass stack dest | **Countered** — dest loaded into ESI before call; this unit has **no** stack args |
| 4 | Clears count `+0x1a4` | Logical cleanup | **Falsified** — bytes never write `+0x1a4` |
| 5 | `vtbl[0](1)` is non-deleting | Flag 1 ambiguous | **Survives as unknown product** — pattern matches MSVC deleting-dtor flag, not proven |
| 6 | Proven product name CxImage / NDAssetImage | Sibling labels | **Survives as Probable only** — no string/RTTI on this VA; field family shared with TransferFields |
| 7 | Full object dtor | Releases some fields only | **Falsified as full dtor** — does not touch header blocks at +8 / +0x30 (those are separate) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Busy gate + free spine | **High** | Leak or silent create fail |
| ESI / AL ABI | **High** | Wrong calling convention in ports |
| Ownership slot list | **High** | Incomplete free → leak |
| Product class English | **Probable** | Mis-bucket under wrong subsystem |
| Sub-object type at +0x1b4 | **Low–Tentative** | Wrong dtor assumption |
| Runtime verified | **Open** | — |

---

## 3. Surviving contract

```
// ESI = image*; plain ret; AL bool
if (*(int*)(image+0x38) != 0) return 0;
if (array = *(image+0x1b4)) {
  for i in 0 .. *(image+0x1a4)-1:
    if (p = array[i]) p->vtbl[0](p, 1);
  free(array); *(image+0x1b4) = 0;
}
// free+null each of +0x1ac, +0x1b0, +4 if non-null
return 1;
// note: +0x1a4 count NOT cleared
```

---

## 4. Falsifications locked in

- **Reject** “always destroys” — `+0x38` short-circuit is real and used by TransferFields as a hard gate.
- **Reject** ECX/thiscall for this unit — ESI register convention only.
- **Reject** treating this as full object destructor (header blocks untouched).
- **Reject** assuming count at `+0x1a4` is zeroed.
- **Reject** hard product rename without string/RTTI (keep `_Inferred`).

---

## 5. Open questions

1. What sets `+0x38` and clears it (who owns the busy flag)?
2. Exact type behind `+0x1b4[i]`.
3. Interaction with decode paths that call this mid-function on failure cleanup.

**Verdict:** **accept-with-gaps**
