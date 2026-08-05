# Review B (skeptical / adversarial): `aa_00769e40` stoChunkReader_LeaveChunk

| Field | Value |
|---|---|
| **Stable ID** | `aa_00769e40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00769e40_stoChunkReader_LeaveChunk.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is OpenChunk / EnterChunkScope | Different VA; Open pushes ring, this seeks+pops | **Falsified** — **Leave**, not open |
| 2 | `__stdcall` / stack args | Bytes: ECX-this only, plain `RET` | **Falsified** — no stack cleanup |
| 3 | Sticky is assigned absolute always | Bytes use `or [esi+0x402c],eax` after clear-0 | **Clarify** — clear then OR |
| 4 | Text path always returns 0 | Fail path logs + `return 0xffffffff` before pop | **Partial** — fail skips ring pop |
| 5 | Ring always pops on text fail | Early return after dtor before write-- | **Confirmed gap** — fail-before-pop |
| 6 | entry+0x10 is tag/version | Enter uses tag@0 version@8; this loads +0x10 | **Falsified for tag** — end absolute |
| 7 | Depth starts at 0 | Body `iVar4 = 1` before loop | **Falsified** — starts **1** (already inside `{`) |
| 8 | Mode flag polarity inverted | OpenChunk plate: 0=binary; same compare here | **Consistent** with Open/readF32Array |
| 9 | Name LeaveChunkScope required | Body operates on **reader**, not ChunkScope* | **LeaveChunk** correct; scope gate is thunk `0x00437120` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Binary end seek + window reposition | **High** | Asset parse desync after leave |
| Text brace balance | **High** | Text chunk early exit / hang risk if wrong |
| Sticky return codes | **High** | Callers map success via signed sticky |
| Fail path skips pop | **High** | Ports that always pop would desync ring |
| endAbs product name | **Medium** | Doc only |
| `+0x28` exact English | **Medium** | Bound may be file size vs window max |

---

## 3. Cross-check against raw / bytes

```
raw: sticky=0; if binary: ring end@+0x10 → window; else brace loop; pop write; return sticky
bytes: mov [esi+0x402c],0 ; cmp [esi+0x4044],0 ; or sticky; plain ret
```

Clean must not invent stack args, must preserve **OR** sticky (not pure assign on fail after clear), and must not pop ring on the text early-fail return.

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior sketch — client stoChunk leave (not a full port of tokenizer)
int LeaveChunk(StoChunkReader r)
{
    r.Sticky = 0;
    if (!r.TextMode)
    {
        var idx = Wrap(r.Write + r.Base - 1, r.Capacity);
        int end = r.Entries[idx].EndAbs; // entry+0x10
        if (end < 0 || end > r.Limit) r.Sticky |= -1;
        else if (end < r.Base || end >= r.Base + r.Remain)
        { r.Base = end; r.Remain = 0; r.Cursor = 0; }
        else r.Cursor = end - r.Base;
    }
    else
    {
        int depth = 1;
        do {
            r.Sticky |= ReadToken(r, allowPastEnd: true);
            if (r.Sticky < 0) { Log("Could not find end of text chunk"); return -1; /* no pop */ }
            // adjust depth on "{" / "}"
        } while (depth != 0);
    }
    if (r.Write != 0) { if (--r.Write == 0) r.BaseIdx = 0; }
    return r.Sticky;
}
```

**Port traps to reject:**

- Treating leave as scope-thiscall with reader on stack (that is Enter's inverse shape, not this body).
- Always popping ring even when text fail returns early.
- Assuming sticky is only assigned, never OR'd.
- Starting brace depth at 0.

---

## 5. Residual gaps (do not block seal)

1. Tokenizer product dual for `FUN_00767840`.
2. Ring entry full 0x14 product fields beyond endAbs use.
3. Runtime live / bit-exact.
4. Whether any caller relies on sticky bits other than sign.

---

## Verdict

**accept-with-gaps** — adversarial review cannot break leave CF, ABI, mode split, binary end seek, text brace nest, or ring pop. Main port traps: **early-fail no-pop**, **depth starts at 1**, **sticky OR after clear**, and **not** confusing with EnterChunkScope ABI.
