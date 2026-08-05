# Review B (skeptical / adversarial): `aa_0076a2c0` stoChunkReader_OpenChunk

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076a2c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual A/B seal) |
| **Counterpart** | `reviews/A_aa_0076a2c0_stoChunkReader_OpenChunk.md` |
| **Verdict** | **accept-with-gaps** (binary/text CF + returns sealed; callee renames / ring depth open) |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). Own VA `0x0076a2c0` only; callees inspected for register contract, not dual-reviewed here.

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Always parses text `CHUNK` keyword | Binary path (`+0x4044==0`) skips all string tokens | **Falsified** — binary is pure 16 B header |
| 2 | Text mode uses binary header reader | Binary `FUN_004368b0` only on zero mode gate | **Falsified** as always-on |
| 3 | Success returns 1 / true | Success tail `xor eax,eax` @ join after `FUN_00436340` | **Falsified** — success is **0** |
| 4 | Fail returns 0 | Fail paths `return 0xffffffff` | **Falsified** — fail is **−1** |
| 5 | Sticky error is a bool set only | Sticky is **OR-accumulated** (`or [this+0x402c], status`); also direct `= -1` stores | **Falsified as pure bool** |
| 6 | Ring lives at `this+0x4034` as base pointer | Bytes: `lea eax,[ebp+0x4030]` then callee uses `eax+4..+10` | **Partial** — bookkeeping at `+0x4034..0x4040`; **object base** is **`+0x4030`** |
| 7 | Mode `+0x4044==0` means text | Plate + CF: 0 = binary, non-zero = text | **Falsified** if inverted |
| 8 | Tag length can be any string | Text requires `local_14 == 4` else “not FOURCC” | **Falsified** |
| 9 | OpenChunk allocates ring storage itself | Ring push is `FUN_00436340`; OpenChunk only supplies header + ring base | **Falsified as owner of alloc** |
| 10 | Version always read via binary int helper | On text entry, version goes through `FUN_007689e0`; `FUN_00437050` branch is dead unless mode changes | **Mostly falsified** for normal text open |
| 11 | Pending token at `+0x404c` always ignored | When `+0x4060 != 0`, first token is **moved from** `+0x404c` | **Falsified** |
| 12 | Three-rep CF diverges from live decompile | 2026-07-29 re-decompile ≡ raw/annotated/clean body | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Mode gate `this+0x4044` (0=bin, ≠0=text) | **High** | Wrong serializer path |
| Sticky `this+0x402c` OR / signed-fail | **High** | Silent continue after parse fail |
| Binary 16 B header + cursor `+0x18` | **High** | Misaligned chunk stream |
| Stream window `this+0x14` → `+0x18/+0x1c/+0x20/+0x2c` | **High** | Buffer underrun / wrong base |
| Success return **0** / fail **−1** | **High** | Inverted caller checks |
| Ring base `this+0x4030`, fields `+0x4034..0x4040` | **High** | Wrong push / nested open |
| Text grammar CHUNK / FOURCC×4 / version / `{` | **High** | Asset load abort |
| FOURCC pack byte order (decomp CONCAT reverse) | **Probable** | Tag mismatch vs binary LE |
| `+0x4060` pending-token flag English | **Probable** | Re-entry / peek semantics |
| Full ring element layout (0x14 dwords) | **Probable** | Nested scope depth bugs |
| Callee product names | **Tentative** | Naming only |
| Runtime / bit-exact | **Open** | Shipping loaders |

---

## 3. Cross-check contract (portable)

```
// stoChunkReader_OpenChunk  @ 0x0076a2c0
// this = ECX
// returns 0 on success, 0xffffffff on failure

uint32_t OpenChunk(stoChunkReader* r) {
  // SEH frame omitted

  if (r->fTextMode /* +0x4044 */ == 0) {
    // ESI = &r->streamWindow (+0x14), EDI = &header16
    status = ReadBinaryHeader16(r);          // FUN_004368b0
    r->stickyError /* +0x402c */ |= status;
    if ((int)r->stickyError < 0) return 0xffffffff;
    // header on stack; compute absolute end using size word
    goto push_ring;
  }

  // ---- text mode ----
  string tok;
  if ((int)r->stickyError < 0) status = -1;
  else {
    if (r->usePending /* +0x4060 */ == 0)
      status = ReadToken(r, &tok);           // inlined tokenizer
    else {
      tok = r->pending /* +0x404c */;
      r->pending.clear();
      status = 0;
    }
    if (tok == "}") {
      log("Attempt to read past end of chunk...");
      r->stickyError = -1;
      r->pending = tok; tok.clear();
      status = -1;
    }
  }
  r->stickyError |= status;
  if ((int)r->stickyError < 0) {
    log("Error finding chunk token");
    return 0xffffffff;
  }
  if (_stricmp(tok.c_str(), "CHUNK") != 0) {
    r->stickyError = -1;
    log("Expected \"CHUNK\" keyword but got \"%s\"", tok);
    return 0xffffffff;
  }
  status = ReadQuotedTag(r, &tagStr);        // FUN_00769b70
  r->stickyError |= status;
  if ((int)r->stickyError < 0) {
    log("Invalid chunk tag: \"%s\"", tagStr);
    return 0xffffffff;
  }
  if (tagStr.size() != 4) {
    r->stickyError = -1;
    log("Chunk tag not FOURCC: \"%s\"", tagStr);
    return 0xffffffff;
  }
  header.tag = pack_fourcc_be_chars(tagStr); // decomp CONCAT reverse
  status = ReadVersionText(r, &header.ver);  // FUN_007689e0 on text
  r->stickyError |= status;
  if ((int)r->stickyError < 0) {
    log("Could not read chunk version");
    return 0xffffffff;
  }
  status = ReadToken(r, &tok2);
  r->stickyError |= status;
  if ((int)r->stickyError < 0) {
    log("Error reading text block marker");
    return 0xffffffff;
  }
  if (tok2 != "{") {
    r->stickyError = -1;
    log("Expected block marker \"{\" but got: \"%s\"", tok2);
    return 0xffffffff;
  }

push_ring:
  // EAX = &r->chunkRing (+0x4030), EDI = &header
  PushChunkRing(r);                          // FUN_00436340
  return 0;
}
```

**Adversarial note on FOURCC pack:** decompiler emits byte-reverse CONCAT into `local_40`. Treat on-disk/binary tag endianness as **Probable** until a known asset (e.g. writer `BeginChunk` tag `0x494e4458` / `"INDX"`) is round-tripped against this pack — not owned in this dual.

---

## 4. What clean must not invent

- No mission/net/UI coupling (pure storage parser).
- No automatic `EnterChunkScope` / leave — **callers** pair open with scope helpers (`stoChunkReader_EnterChunkScope` is a **caller**, not a callee).
- No assumption that success returns boolean true.
- No claim that text path validates binary 16 B layout, or that binary path validates `"CHUNK"` spelling.
- Do not place ring **base** at `+0x4034`; plate’s `+0x4034..0x4040` are **fields of** the object at `+0x4030`.

---

## 5. Three-rep status

| Layer | Status |
|---|---|
| Raw | Present; ≡ live decompile 2026-07-29 |
| Annotated | Present (scaffold notes; CF complete) |
| Clean | Present; CF-preserving; names still `FUN_*` for callees |
| Function record | Updated dual seal (same day) |
| Dual A/B | **This pair** |

No raw body rewrite required (integrity: append-only if ever re-captured).

---

## 6. Open questions (residual)

1. Confirm FOURCC pack endian vs `stoChunkWriter_BeginChunk` / retail assets.
2. Rename wave for binary ReadHeader / PushRing / text version readers (separate OWN VAs).
3. Whether any caller opens with sticky already negative intentionally (short-circuit).
4. Depth limit / overflow behavior of ring (`FUN_00436340` grow path).
5. Runtime open of a known `.chunk` / physics serialize file under both modes.

**Verdict:** **accept-with-gaps**
