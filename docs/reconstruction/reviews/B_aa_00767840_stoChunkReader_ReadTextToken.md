# Review B (skeptical / adversarial): `aa_00767840` stoChunkReader_ReadTextToken

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767840` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00767840_stoChunkReader_ReadTextToken.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | ECX-thiscall like `readF32` | Bytes: stack reader, `ret 8`, no `mov reg,ecx` of this | **Falsified** — hybrid EDI+stack |
| 2 | Same as ReadQuotedTag | Different VA; no quote-strip; has allowEndBrace; ret 8 vs 4 | **Distinct unit** |
| 3 | `}` always fails | CF: only when `allowEndBrace==0` | **Falsified** — LeaveChunk uses 1 |
| 4 | Pushback flag is free-standing int unrelated to string | `+0x4060` = size field of string at `+0x404c` (+0x14) | **Clarify** — non-empty test; sibling docs call it mode |
| 5 | Binary chunk path | No `+0x4044` branch; pure text token | **Text-only** |
| 6 | Quotes stripped | `operator+=` keeps open/close quote chars | **Kept in token** |
| 7 | Name must be LeaveChunk helper only | Also called from PeekChunkTag | **Shared tokenizer** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI out + ret 8 | **High** | Wrong port ABI corrupts caller strings |
| allowEndBrace polarity | **High** | LeaveChunk brace walk sticky-fails wrongly |
| Quote inclusion | **High** | Tag compare mismatches |
| Pushback restash on `}` | **High** | Nested read desync |
| Product spelling | **Medium** | Doc only |

---

## 3. Cross-check against raw / bytes

```
raw: early sticky if !flag; pushback or scan; } & !flag → log+fail; else 0
bytes: cmp [esp+flag]; ret 8; mov ecx,edi for string
```

Clean must not invent ECX-this, must not strip quotes, must honor allowEndBrace.

---

## 4. Surviving contract for AutoCore

```csharp
// Hybrid ABI sketch — EDI out omitted as explicit param in ports
int ReadTextToken(StoChunkReader r, ref string outTok, bool allowEndBrace)
{
    if (!allowEndBrace && r.Sticky < 0) return -1;
    if (r.PushbackNonEmpty) { outTok = r.TakePushback(); }
    else if (!ScanToken(r, ref outTok)) return -1; // sets sticky on empty EOF
    if (outTok == "}" && !allowEndBrace) {
        LogPastEnd(); r.Sticky = -1; r.Pushback = outTok; outTok = "";
        return -1;
    }
    return 0;
}
```

---

## 5. Gaps

1. Product symbol spelling.
2. Runtime / differential.
3. Whether any DATA xref exists (none observed — code-only leaf surface).

---

## Verdict

**accept** — adversarial checks reinforce hybrid ABI and allowEndBrace policy; no CF contradiction with raw/live/bytes.
