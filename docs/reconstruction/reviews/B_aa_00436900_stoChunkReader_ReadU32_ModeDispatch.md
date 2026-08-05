# Review B (skeptical / adversarial): `aa_00436900` stoChunkReader_ReadU32_ModeDispatch

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436900` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W22-R) |
| **Counterpart** | `reviews/A_aa_00436900_stoChunkReader_ReadU32_ModeDispatch.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is only a void helper with no return contract | **Falsified** — both callees return 0/−1 in EAX; epilogues do not clobber EAX |
| 2 | Mode lives somewhere other than `+0x4044` | **Falsified** — immediate `cmp [eax+0x4044],0` |
| 3 | Binary arm is the text parser | **Falsified** — rel32 targets sealed `ReadU32` @ `00437050` |
| 4 | Text arm uses same EAX-reader ABI as binary ReadU32 | **Falsified** — text requires `mov edi,eax` (EDI-this for `007689e0`) |
| 5 | Out pointer is stack-only at entry (cdecl full) | **Falsified** — entry uses **ECX** then `push ecx` |
| 6 | Function owns stream ensure/copy math | **Falsified** — 27 B trampoline; no window field touch |
| 7 | Prior scaffold name `Named_CalleeOf_Named_anmAnimMaster_*` is product role | **Falsified as product name** — xrefs are gfx unserialize / chunk readers, not anim master semantics |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Mode offset +0x4044 | **High** | Wrong format branch on port |
| Binary vs text callee split | **High** | Binary files parsed as text / vice versa |
| Out* in ECX | **High** | Corrupted stack formals at call sites |
| Status return | **High** | Callers skip error checks if treated void |
| Product class English | Medium | Naming only |
| Text reader full semantics | Out of scope | Must not invent parse rules here |

---

## 3. Cross-check against raw + bytes

```
cmp [eax+0x4044],0
  jz  binary: push ecx → call ReadU32 → ret
  jnz text:   push edi; push ecx; mov edi,eax → call textU32 → pop edi → ret
```

Clean must **not** invent stream buffer math, SEH, or string parse loops — those live in callees.

Do **not** treat decompiler `void` / `in_EAX` awkwardness as missing thiscall; retail is **EAX-reader + ECX-out**.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape (chunk IO)
int StoChunkReader_ReadU32_ModeDispatch(StoChunkReader reader, out uint value)
{
    if (reader.ModeAt0x4044 == 0)
        return StoChunkReader_ReadU32_Binary(reader, out value);
    return StoChunkReader_ReadU32_Text(reader, out value); // EDI-this in retail
}
// Callers: if (status < 0) fail unserialize.
```

---

## 5. Open questions

1. Whether AutoCore already has a unified ReadU32 that should absorb this dispatch.
2. Text mode sticky-error interactions (`reader+0x402c`) — owned by `007689e0`, not this VA.

**Verdict:** **accept**
