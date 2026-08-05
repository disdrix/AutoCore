# Review B (skeptical / adversarial): `aa_00769b70` stoChunkReader_ReadQuotedTag

| Field | Value |
|---|---|
| **Stable ID** | `aa_00769b70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00769b70_stoChunkReader_ReadQuotedTag.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Same function as ReadTextToken | Different body end, SEH, ret 4, strip path, no allowEndBrace | **Distinct** |
| 2 | Returns 0 for any successful scan | Bare/`'`/`{` fall through to final `-1` | **Falsified** — strict filter |
| 3 | Strips both `'` and `"` | Bytes compare `0x22` only; substr only on `"` | **Double-quote only** |
| 4 | substr(1) without length | Bytes `push size-2; push 1` | **Falsified** — count sealed |
| 5 | ECX thiscall | Stack reader + ret 4 | **Hybrid EDI+stack** |
| 6 | Always clears sticky on entry | Only sets sticky on empty EOF / `}` | **No clear-to-0** |
| 7 | OpenChunk binary uses this | OpenChunk text path only; binary uses header helper | **Text tag path** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Strip success filter | **High** | OpenChunk accepts unquoted tags wrongly |
| ret 4 / SEH | **High** | Stack imbalance |
| Twin scan with 00767840 | **High** | Divergent token rules break pushback |
| Product spelling | **Medium** | Doc only |

---

## 3. Cross-check against raw / bytes

```
raw: sticky gate; scan/pushback; } fail; else if quoted-double strip return 0; else -1
bytes: ret 4; substr pos=1 count=size-2; cmp 0x22 both ends
```

Clean must not return 0 on bare tags and must not strip single quotes.

---

## 4. Surviving contract for AutoCore

```csharp
int ReadQuotedTag(StoChunkReader r, ref string outTag)
{
    if (r.Sticky < 0) return -1;
    if (!r.PushbackNonEmpty) {
        if (!ScanToken(r, ref outTag)) return -1;
    } else outTag = r.TakePushback();

    if (outTag == "}") {
        LogPastEnd(); r.Sticky = -1; r.Pushback = outTag; outTag = "";
        return -1;
    }
    if (outTag.Length > 1 && outTag[0] == '"' && outTag[^1] == '"') {
        outTag = outTag.Substring(1, outTag.Length - 2);
        return 0;
    }
    return -1;
}
```

---

## 5. Gaps

1. Product symbol spelling.
2. Single-quote rejection rationale (product).
3. Runtime / differential.

---

## Verdict

**accept** — adversarial review confirms strict double-quote success contract; no contradiction with raw/live/bytes.
