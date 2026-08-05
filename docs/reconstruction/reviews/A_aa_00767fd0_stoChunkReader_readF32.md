# Review A (reconstruction fidelity): `aa_00767fd0` stoChunkReader_readF32

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767fd0` |
| **VA** | `0x00767fd0` |
| **Body span** | `00767fd0` – `00768254` |
| **Canonical name** | `stoChunkReader_readF32` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W17-G; live Ghidra `decompile_function` + `read_memory`) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_00767fd0_stoChunkReader_readF32.md` |
| **System** | `sto-chunk` / arda2 storage |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Read **one float32** from a `stoChunkReader` on the **text/token** path:

1. Guard on sticky validity `*(reader+0x402c) >= 0`.
2. If `*(reader+0x4060) == 0`, scan stream window (`+0x2c` + cursor `+0x18`) for next token (optional `'`/`"` quotes; skip leading `isspace`; refill via `FUN_00435df0`).
3. Else copy pushback string at `+0x404c` and clear it.
4. If token is `"}"` → log past-end (`stoChunk.cpp:0x2a0`), sticky-fail `+0x402c = -1`, re-stash token.
5. Else `sscanf(token, "%f", out)` — one conversion → **return 0**.
6. Else format/log *“Expected float32 but got \"%s\" in chunk \"%s\"”* (`stoChunk.cpp:0x434`) → **return 0xffffffff**.

Used by `stoChunkReader_readF32Array` non-binary loop and many direct unserialize call sites (`phyBone_unserialize`, etc.).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00767fd0_FUN_00767fd0.md` (+ live seal append) |
| Annotated | `docs/reconstruction/raw/aa_00767fd0_FUN_00767fd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_readF32.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00767fd0.cpp` / `Named_stoChunk_00767fd0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00767fd0_stoChunkReader_readF32.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x00767fd0` (2026-07-29) |
| Bytes | `read_memory` entry 128 B; epilogue @ `0x00768240` → `C2 04 00` |
| Bounds | `get_function_by_address` → `00767fd0`–`00768254` |
| Callers | `get_function_callers` (incl. `stoChunkReader_readF32Array`, `phyBone_unserialize`) |
| Callees | `get_function_callees` |
| Strings | `read_memory` `0x00a9d738` (path), `0x00a28404` (`%f`), `0x00a6bfd0` (`}`) |

**Not performed:** Launcher, runtime golden, bit-exact EXE diff; **no ownership** of callees `0x00435df0` / `0x00436250` / `0x0076cec0`.

---

## 3. Calling convention (assembly-sealed on OWN body)

| Slot | Role | Evidence |
|---|---|---|
| **ECX** | `stoChunkReader *this` | prolog `mov edi,ecx`; field ops via EDI |
| **[esp+4]** pre-call | `float *out` | `sscanf(..., param_2)`; `ret 4` |
| **Return** | `0` / `0xffffffff` | success path xor-free 0; fail `or eax,0xffffffff` + `ret 4` |
| **Cleanup** | `ret 4` @ `0x00768251` | `read_memory` |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + `ret 4` | **High** | bounds + epilogue bytes |
| `__thiscall(reader, float* out)` | **High** | prolog + call sites in `readF32Array` (`push dest; mov ecx,reader; call`) |
| Token scan + quote/`isspace` rules | **High** | live decompile ≡ raw |
| `sscanf "%f"` success → 0 | **High** | decompile + string `%f` |
| Past-end `"}"` sticky + log line `0x2a0` | **High** | decompile + path string |
| Error format line `0x434` → `0xffffffff` | **High** | decompile |
| Offsets `+0x18/+0x1c/+0x20/+0x2c` | **High** | shared with `readF32Array` map |
| `+0x402c` validity sticky | **High** | both arms set `-1` |
| `+0x404c` pushback string | **High** | assign/clear in both modes |
| `+0x4060` mode: 0=scan else pushback | **High** | decompile branch |
| Product names for mode flags | **Probable** | structural only |
| Outer loop after quote close | **Probable** | decompiler `while(true)` residual |
| Clean ≡ raw CF | **High** | named clean preserves stages |
| Bit-for-bit / runtime | **Open** | deferred |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Validity gate `+0x402c >= 0` | **Yes** |
| Mode `+0x4060 == 0` scan vs pushback | **Yes** |
| Refill when cursor would exceed avail | **Yes** |
| Quote / isspace / accumulate token | **Yes** |
| Empty EOF → sticky fail | **Yes** |
| Token `"}"` past-end log + re-stash | **Yes** |
| `sscanf` one float → return 0 | **Yes** |
| Format error + return `0xffffffff` | **Yes** |
| No invent binary dword load | **Yes** (text path only) |

### Recovered CF (contract)

```c
// uint32 __thiscall stoChunkReader_readF32(reader, float *out)  // ret 4
if (reader->valid402c < 0) goto fail;
if (reader->mode4060 == 0)
  token = scan_next_token(reader);   // may sticky-fail on empty EOF
else {
  token = reader->pushback404c;
  reader->pushback404c.clear();
}
if (token == "}") {
  log_past_end(); reader->valid402c = -1; reader->pushback404c = token;
} else if (sscanf(token, "%f", out) == 1) {
  return 0;
}
fail:
  log_expected_float32(token, chunk_name);
  return 0xffffffff;
```

---

## 6. Gaps

1. Exact post-quote outer-loop continuation (decompiler infinite outer) — ports should golden-token against retail on quoted multi-token lines.
2. `FUN_00436250` / `FUN_0076cec0` string packaging not dual-owned here.
3. Interaction of `+0x4044` (array binary mode) vs `+0x4060` (this unit’s pushback mode) is **cross-unit** — do not collapse them without layout dual.
4. Runtime / differential **Open**.

**Verdict:** **accept-with-gaps** — CF and ABI sealed High for AutoCore sto-chunk text float reads; residual quote-loop / callee packaging only.
