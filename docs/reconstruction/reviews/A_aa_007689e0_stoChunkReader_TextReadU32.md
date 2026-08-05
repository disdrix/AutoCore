# Review A (reconstruction fidelity): `aa_007689e0` stoChunkReader_TextReadU32

| Field | Value |
|---|---|
| **Stable ID** | `aa_007689e0` |
| **VA** | `0x007689e0`–`0x00768c50` |
| **Canonical name** | `stoChunkReader_TextReadU32` (**Inferred**) |
| **Prior scaffold** | `FUN_007689e0` / `Named_stoChunk_007689e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity — OWN-ONLY W22-Q |
| **Counterpart** | `reviews/B_aa_007689e0_stoChunkReader_TextReadU32.md` |
| **System** | `storage` / arda2 `stoChunk` |
| **Verdict** | **accept-with-gaps** — EDI/stack/RET4 ABI, token scan, pushback, parse call shape, 0/−1 returns sealed; parse helper body + product English open |

**Tools:** Ghidra `decompile_function` + `read_memory` (body + mode dispatcher). No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Read the next **uint32** from a stoChunk **text** stream into a caller-provided `uint32_t*`:

1. Bail if sticky status `reader+0x402c < 0`.
2. Either consume pushback string (`+0x4060` / `+0x404c`) or scan whitespace/quoted token from the window buffer.
3. If token is `"}"` → past-end log, sticky −1, re-push token.
4. Else parse via `FUN_00767600(out, 4, 0)`; success → return **0**.
5. Else log `"Expected uint32 but got \"%s\" in chunk \"%s\""` → return **−1**.

Binary peer: `stoChunkReader_ReadU32` @ `0x00437050`. Dispatcher: `FUN_00436900` on `reader+0x4044`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007689e0_FUN_007689e0.md` (+ W22-Q live seal) |
| Annotated | `docs/reconstruction/raw/aa_007689e0_FUN_007689e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_TextReadU32.cpp` |
| Function record | `docs/reconstruction/functions/aa_007689e0_stoChunkReader_TextReadU32.md` |
| Live decompile | Ghidra `decompile_function` `0x007689e0` — **≡** raw |
| Live bytes | `read_memory` `0x007689e0` / `0x00768ae0` / `0x00768be0` (`C2 04 00`) |
| Dispatcher | `decompile_function` + `read_memory` `0x00436900` (context; not owned) |
| Sibling | binary `stoChunkReader_ReadU32` dual (W18-N) |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Reader | **EDI** (`unaff_EDI`; dispatcher `mov edi,eax`) |
| Out dword | stack arg (`param_1`) |
| Epilogue | **`RET 4`** (`C2 04 00`) |
| Return | **0** success; **`0xffffffff`** fail |
| Body | `0x007689e0`–`0x00768c50` |

```c
int32_t stoChunkReader_TextReadU32(
    /* EDI */ StoChunkReader* reader,
    /* stack */ uint32_t* out);
```

**Caller proof (mode dispatcher `FUN_00436900`):**

```
cmp  dword [eax+0x4044], 0
jnz  text
push ecx / call FUN_00437050 / ret     ; binary
text:
push edi / push ecx / mov edi,eax / call FUN_007689e0 / pop edi / ret
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
| Ensure when `available < cursor+1` via `FUN_00435df0(window, base+cursor)` | **High** |
| Fail ensure without content → status −1 → type-error path | **High** |
| Whitespace skip / end-on-ws after content | **High** |
| `'`/`"` quote mode with matching closer | **High** |
| Char from `reader+0x2c+cursor`; cursor++ | **High** |

### 3.4 Parse + errors — **SEALED** (call shape)

```
FUN_00767600(out, 4, 0)   // token in EAX (lea); hr >= 0 → return 0
// else:
FUN_00436250()            // chunk name
FUN_0076cec0(..., "Expected uint32 but got \"%s\" in chunk \"%s\"", ...)
vog_LogMessage(stoChunk.cpp, 0x40b, 3, msg)
return -1
```

| Fact | Confidence |
|---|---|
| Size arg **4** + flags **0** | **High** |
| Success return **0** | **High** |
| Fail return **0xffffffff** | **High** |
| Full parse rules of `FUN_00767600` | **Not owned** |

### 3.5 Three-rep — **SEALED**

live ≡ raw CF/strings ≡ annotated ≡ clean plate control flow.

---

## 4. Gaps (owned)

| Gap | Severity | Notes |
|---|---|---|
| Product English name | Doc | Inferred peer naming; not in binary strings as method name |
| `FUN_00767600` body | Medium | Number base, overflow, signed/unsigned |
| Outer `while(true)` after quote | Low | Decompiler CF; exits only via gotos — sealed intent is single-token |
| Ensure `FUN_00435df0` body | Out of scope | Shared with binary path |
| Runtime | Open | Not run |

---

## 5. Confidence summary

| Area | Confidence |
|---|---|
| Text peer of binary ReadU32 | **High** |
| EDI/stack/ret4 / 0/−1 | **High** |
| Token/pushback/`}`/log paths | **High** |
| Parse helper semantics | **Probable** |
| Canonical name | **Inferred** |
| Runtime | **Open** |

**Verdict: accept-with-gaps**
