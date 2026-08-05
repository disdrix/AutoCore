# Review B (skeptical / adversarial): `stoChunkReader_readF32` @ `0x00767fd0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767fd0` |
| **VA** | `0x00767fd0` |
| **Body span** | `00767fd0` – `00768254` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — W17-G; live Ghidra; independent of Review A wording) |
| **Counterpart** | `reviews/A_aa_00767fd0_stoChunkReader_readF32.md` |
| **System** | `sto-chunk` / arda2 storage |
| **Verdict** | **accept-with-gaps** on OWN CF/ABI; **needs-more-evidence** on quote-loop edge cases + product field names |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is a binary endian-swap of one f32 | **Falsified** — body tokenizes text and `sscanf("%f")`; no 4-byte load/store swap loop. Prior `readF32Array` plate “byte-swap” is wrong for this callee. |
| 2 | Always returns success | **Falsified** — fail returns `0xffffffff`; success only on `sscanf == 1`. |
| 3 | `__stdcall` / free function with reader on stack | **Falsified** — ECX is reader (`thiscall`); only out-float is stack; `ret 4`. |
| 4 | Mode `+0x4060` is the same as array binary flag `+0x4044` | **Not established on OWN body** — this unit never reads `+0x4044`. Collapsing them is a layout hypothesis, not sealed here. |
| 5 | Past-end always hard-errors the caller | **Overstated** — sets sticky `+0x402c = -1` and returns fail **this call**; subsequent calls short-circuit on validity gate. Callers may ignore status. |
| 6 | Quoted tokens strip the quote characters | **Falsified for CF as printed** — opening quote sets mode and still `operator+=` the quote char into the token before continue; closer also appended. Ports that strip quotes may desync `sscanf` (often still ok for `"1.0"`). |
| 7 | Clean is bit-exact retail | **Falsified** — CF scaffold; SEH/SSO details simplified; not EXE-proof. |
| 8 | Runtime verified | **Falsified** — open / deferred. |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX reader / stack float* / `ret 4` | **High** | Wrong ABI → stack smash on unserialize |
| Text token + `sscanf %f` | **High** | Treating as binary breaks text assets |
| Sticky `+0x402c` | **High** | Infinite fail vs silent wrong floats |
| Pushback `+0x404c` / mode `+0x4060` | **High CF** | Token re-read / skip desync |
| Quote char inclusion in token | **High CF / product impact Medium** | Parse fail on quoted floats if port strips differently |
| Outer loop after closer | **Medium** | Multi-token lines |
| Callee format helpers | **Out of scope** | Log text only |
| Clean ≡ raw stages | **High** as map | Unsafe as sealed codec without golden |

---

## 3. Surviving contract for AutoCore

```
status = stoChunkReader_readF32(reader /*ECX*/, out /*stack*/):  // ret 4
  if reader.valid402c < 0: goto fail
  if reader.mode4060 == 0:
    token = scan stream with isspace / quotes / refill(FUN_00435df0)
    if empty EOF: reader.valid402c = -1; goto fail
  else:
    token = reader.pushback404c; reader.pushback404c.clear()
  if token == "}":
    log past-end; reader.valid402c = -1; pushback = token
    // fall to fail (no successful float)
  else if sscanf(token, "%f", out) == 1:
    return 0
fail:
  log "Expected float32 but got \"%s\" in chunk \"%s\""
  return 0xffffffff
```

**Port rules that survive adversarial review:**

1. Do **not** implement this as bswap/load of 4 binary bytes — that path lives in `readF32Array` when `+0x4044==0`.
2. Honor sticky validity: after past-end, further reads must fail without advancing.
3. Preserve quote characters in the token string unless a golden proves retail strips them (decomp does not strip).
4. Surface `0xffffffff` to callers that check status; do not invent zero-fill of `*out` on failure (out may be stale).

---

## 4. CF cross-check vs three-rep

| Check | Result |
|---|---|
| Live decompile vs raw body | **Match** |
| Live epilogue `ret 4` vs raw/annotated ABI | **Match** |
| Named clean stages vs raw | **Match** (SSO/SEH simplified) |
| Prior scaffold “Named_stoChunk” only | **Upgraded** with string + caller evidence to `stoChunkReader_readF32` |

---

## 5. Open questions (OWN residual only)

1. Whether retail ever emits quoted float tokens in shipping chunks (if not, quote path is defensive only).
2. Whether any caller relies on `*out` unchanged on fail.
3. Relationship between `+0x4044` and `+0x4060` under a full reader dual (not this VA).
4. Runtime golden on a known text chunk with multi-float lines.

**Verdict:** **accept-with-gaps** on OWN control flow, ABI, and text-float role; **needs-more-evidence** before asserting product field names or quote-stripping semantics. Safe behavioral map for AutoCore non-binary single-float chunk reads once sticky-fail and `sscanf` contract are honored.
