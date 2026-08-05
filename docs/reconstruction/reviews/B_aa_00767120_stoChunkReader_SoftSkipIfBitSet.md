# Review B (skeptical / adversarial): `aa_00767120` stoChunkReader_SoftSkipIfBitSet

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767120` |
| **Review type** | Skeptical / adversarial (OWN-ONLY dual B, W17-L) |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00767120_stoChunkReader_SoftSkipIfBitSet.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | ECX is ChunkScope* | Scope layout has tag @+0x0c, not bitset @+8; call sites `MOV ECX, reader_reg` after EnterChunkScope | **Falsified** — ECX is **reader** |
| 2 | Hard-fail when bit set | Callers return **0**, not −1; leave scope if okFlag | **Falsified** — soft-skip |
| 3 | `__stdcall` / stack arg | No stack push before CALL; plain RET | **Falsified** — ECX only |
| 4 | Zero id returns garbage upper EAX as "true" | `XOR AL,AL` + callers `TEST AL,AL` | **Clarify** — boolean false; upper EAX irrelevant |
| 5 | Decompile `in_EAX & 0xffffff00` is intentional full-EAX API | Bytes are `XOR AL,AL` | **Clarify** — decompiler quirk; sealed as false |
| 6 | Simple bit index = id-1 on base without (id>>5) pre-add | Bytes: `LEA ECX,[ECX+EDX*4]` after `SHR EDX,5` then further idx math | **Sealed** dual-stage formula |
| 7 | Dual decompiles disagree | force ≡ decompile | **No conflict** |
| 8 | Has callees | analyze complete: leaf | **Sealed** leaf |
| 9 | Name is studio-official | No string / RTTI in body | **Tentative** inferred only |
| 10 | id%32 always safe | `low-1` underflow when low==0 | **Gap survives** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Soft-skip vs hard-fail | **High** | Treating empty/skip as fatal error |
| ECX = reader | **High** | Wrong object → bad bit tests / crashes |
| Bit formula | **High** | Wrong skip decisions on assets |
| Field English | **Low–Medium** | Misleading docs |
| id%32 edge | **Low** | Rare asset class mis-skip |
| Inferred name | **Medium** | Rename churn |

---

## 3. Cross-check: decompile vs bytes vs pcode

| Step | Decompile | Bytes / pcode |
|---|---|---|
| Load id | `*param_1` | `MOV EDX,[ECX]`; LOAD ECX |
| Zero gate | `id==0` | `TEST/JNZ`; INT_EQUAL → early RET |
| Zero return | `in_EAX & ~0xff` | `XOR AL,AL` |
| Base | `param_1[2]` | `MOV ECX,[ECX+8]` |
| base+=(id>>5)*4 | yes | `SHR/LEA` |
| low=id&0x1f | yes | `AND 1F` |
| idx=low-1 | yes | `SUB 1` |
| mask & word | yes | `SHL/AND [EDX]` |
| booleanize | `!=0` | `NEG/SBB/NEG` |

**Consensus:** accept CF. Gaps remain on English/edges only.

---

## 4. Surviving contract for AutoCore

```csharp
// Soft-skip predicate — NOT a hard error.
// reader+0 = id; reader+8 = bitset base (u32 address).
static bool StoChunkReader_SoftSkipIfBitSet(StoChunkReaderView r)
{
    uint id = r.IdAt0;
    if (id == 0) return false;

    uint base = r.BitsetBaseAt8;
    base += (id >> 5) * 4u;
    uint low = id & 0x1fu;
    uint idx = unchecked(low - 1u);
    uint word = ReadU32(base + ((idx >> 5) * 4u));
    uint mask = 1u << (int)(idx & 0x1fu);
    return (word & mask) != 0;
}
// Caller: if (SoftSkip) { LeaveScopeIfOk(); return 0; }
```

**Port traps to reject:**

- Mapping soft-skip to exception / −1.
- Passing ChunkScope* instead of reader*.
- "Simplifying" to `bit = id - 1` without the `(id>>5)` pre-adjust (not equivalent for all id).
- Assuming studio name is final.

---

## 5. Residual questions

1. What sets `reader[+0]` and the bitset contents?
2. Is there a setter sibling near `0x00767160` (WriteFormatted is writer — different)?
3. Asset corpus: any id with `id & 0x1f == 0`?
