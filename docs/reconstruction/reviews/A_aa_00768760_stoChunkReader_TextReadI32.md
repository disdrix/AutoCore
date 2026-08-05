# Review A (reconstruction fidelity): `aa_00768760` stoChunkReader_TextReadI32

| Field | Value |
|---|---|
| **Stable ID** | `aa_00768760` |
| **VA** | `0x00768760`–`0x007689D0` |
| **Canonical name** | `stoChunkReader_TextReadI32` (**Inferred**) |
| **Prior scaffold** | `FUN_00768760` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction fidelity — OWN-ONLY W38-I |
| **Counterpart** | `reviews/B_aa_00768760_stoChunkReader_TextReadI32.md` |
| **System** | `storage` / arda2 `stoChunk` |
| **Verdict** | **accept-with-gaps** — EDI/stack/RET4 ABI, token scan, pushback, signed parse call, 0/−1 returns sealed; parse helper body + product English open |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs. No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Read the next **int32** from a stoChunk **text** stream into a caller-provided `int32_t*`:

1. Bail if sticky status `reader+0x402c < 0`.
2. Either consume pushback string (`+0x4060` / `+0x404c`) or scan whitespace/quoted token from the window buffer.
3. If token is `"}"` → past-end log, sticky −1, re-push token.
4. Else parse via `FUN_00767600(out, 4, 1)`; success → return **0**.
5. Else log `"Expected int32 but got \"%s\" in chunk \"%s\""` → return **−1**.

Unsigned peer: `stoChunkReader_TextReadU32` @ `0x007689e0` (`signedMode=0`, Expected uint32).  
Binary dual (common): `stoChunkReader_ReadU32` @ `0x00437050` (LE dword).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00768760_FUN_00768760.md` (+ W38-I live seal) |
| Annotated | `docs/reconstruction/raw/aa_00768760_FUN_00768760.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_TextReadI32.cpp` |
| Function record | `docs/reconstruction/functions/aa_00768760_stoChunkReader_TextReadI32.md` |
| Live decompile | Ghidra `decompile_function` `0x00768760` — **≡** raw |
| Live bytes | `read_memory` prologue + epilogue (`C2 04 00`) |
| Peer dual | `stoChunkReader_TextReadU32` (W22-Q); `stoChunk_ConvertToInteger` (W25-R) |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Reader | **EDI** (`unaff_EDI`) |
| Out dword | stack arg (`param_1`) |
| Epilogue | **`RET 4`** (`C2 04 00` @ `0x007689CE`) |
| Return | **0** success; **`0xffffffff`** fail (`OR EAX,-1`) |
| Body | `0x00768760`–`0x007689D0` |

```c
int32_t stoChunkReader_TextReadI32(
    /* EDI */ StoChunkReader* reader,
    /* stack */ int32_t* out);
```

### 3.2 Sticky + pushback — **SEALED**

| Fact | Confidence |
|---|---|
| Early out if `+0x402c < 0` | **High** |
| `+0x4060==0` → scan; else assign from `+0x404c` and clear | **High** |
| `"}"` → log line `0x2a0`, status=−1, pushback=token | **High** |

### 3.3 Token scan — **SEALED** (shape)

| Fact | Confidence |
|---|---|
| Ensure when `available < cursor+1` via `FUN_00435df0` | **High** |
| Fail ensure without content → status −1 → type-error path | **High** |
| Whitespace skip / end-on-ws after content | **High** |
| `'`/`"` quote mode with matching closer | **High** |
| Char from `reader+0x2c+cursor`; cursor++ | **High** |

### 3.4 Parse + errors — **SEALED** (call shape)

```
FUN_00767600(out, 4, 1)   // signedMode=1; hr >= 0 → return 0
// else:
FUN_00436250()            // chunk name
FUN_0076cec0(..., "Expected int32 but got \"%s\" in chunk \"%s\"", ...)
vog_LogMessage(stoChunk.cpp, 0x414, 3, ...)
return -1
```

---

## 4. Confidence table

| Area | Confidence | Notes |
|---|---|---|
| EDI / stack out / RET 4 / 0/−1 | **High** | epilogue bytes + decompile |
| Signed int32 role | **High** | plate string + signedMode=1 |
| Token / pushback / `}` | **High** | ≡ TextReadU32 structure |
| ConvertToInteger internals | **Out of scope** | sealed elsewhere (W25-R) |
| Product English | **Inferred** | error proves type not symbol |
| Runtime | **Open** | |

---

## 5. Gaps (non-blocking for CF seal)

1. Exact product C++ method name (Inferred only).
2. ConvertToInteger radix / overflow (unowned helper).
3. Ensure-window internals (unowned `FUN_00435df0`).
4. Runtime / bit-exact / differential.
