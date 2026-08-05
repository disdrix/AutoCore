# Review A (reconstruction fidelity): `aa_00769660` stoChunkReader_TextReadBool

| Field | Value |
|---|---|
| **Stable ID** | `aa_00769660` |
| **VA** | `0x00769660`–`0x007698d0` |
| **Canonical name** | `stoChunkReader_TextReadBool` (**Inferred**) |
| **Prior scaffold** | `FUN_00769660` / `Named_stoChunk_00769660` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction fidelity — OWN-ONLY W38-J |
| **Counterpart** | `reviews/B_aa_00769660_stoChunkReader_TextReadBool.md` |
| **System** | `storage` / arda2 `stoChunk` |
| **Verdict** | **accept** — EDI/stack/RET4 ABI, token scan, pushback, `ConvertToInteger(out,1,0)`, 0/−1, Expected-bool log sealed |

**Tools:** Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + xrefs + assembly context on dispatcher. **No** `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Read the next **bool** from a stoChunk **text** stream into a caller-provided 1-byte out:

1. Bail if sticky status `reader+0x402c < 0`.
2. Either consume pushback string (`+0x4060` / `+0x404c`) or scan whitespace/quoted token from the window buffer.
3. If token is `"}"` → past-end log, sticky −1, re-push token.
4. Else parse via `FUN_00767600(out, 1, 0)`; success → return **0**.
5. Else log `"Expected bool but got \"%s\" in chunk \"%s\""` → return **−1**.

Binary peer: `FUN_00437000`. Dispatcher: `FUN_00439a50` on `reader+0x4044`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00769660_FUN_00769660.md` (+ W38-J live seal) |
| Annotated | `docs/reconstruction/raw/aa_00769660_FUN_00769660.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_TextReadBool.cpp` |
| Function record | `docs/reconstruction/functions/aa_00769660_stoChunkReader_TextReadBool.md` |
| Live decompile | Ghidra `decompile_function` `0x00769660` — **≡** raw CF |
| Live bytes | `read_memory` entry + epilogue `C2 04 00` @ `0x007698ce` |
| Bounds | `get_function_by_address` → `00769660`–`007698d0` |
| Dispatcher | `read_memory` `0x00439a50` (context; not owned) |
| Sibling family | TextReadU32 `aa_007689e0`; ConvertToInteger `aa_00767600` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Reader | **EDI** (`unaff_EDI`; dispatcher `mov edi,eax`) |
| Out byte | stack arg (`param_1`) |
| Epilogue | **`RET 4`** (`C2 04 00`) |
| Return | **0** success; **`0xffffffff`** fail |
| Body | `0x00769660`–`0x007698d0` (**624 B**) |

```c
int32_t stoChunkReader_TextReadBool(
    /* EDI */ StoChunkReader* reader,
    /* stack */ uint8_t* out);
```

### 3.2 Sticky + pushback + token scan — **SEALED**

Same family as sealed TextReadU32 / ReadTextToken:

| Fact | Confidence |
|---|---|
| Early out if `+0x402c < 0` | **High** |
| `+0x4060==0` → scan; else assign from `+0x404c` and clear | **High** |
| Ensure / `isspace` / `'`/`"` quote mode | **High** |
| `"}"` → log `0x2a0`, status=−1, pushback=token | **High** |

### 3.3 Parse + errors — **SEALED**

```
FUN_00767600(out, 1, 0)   // token in EAX; hr >= 0 → return 0
// else:
FUN_00436250()
FUN_0076cec0(..., "Expected bool but got \"%s\" in chunk \"%s\"", ...)
vog_LogMessage(stoChunk.cpp, 0x3dd, 3, msg)
return -1
```

| Fact | Confidence |
|---|---|
| Size arg **1** + flags **0** | **High** (bytes `push 0; push 1; push out`) |
| Error string at `0x00a9d414` | **High** |
| Line **0x3dd** | **High** |

### 3.4 Three-rep — **SEALED**

live decompile ≡ scaffold raw CF ≡ annotated ≡ clean plate control flow.

---

## 4. Gaps (owned)

| Gap | Severity | Notes |
|---|---|---|
| Product/PDB English name | Low | Structural Inferred name only |
| ConvertToInteger bool digit set (0/1 only vs any u8) | Low | Owned by `0x00767600` (sealed W25-R) |
| Runtime / bit-exact / differential | Open | Not run |

---

## 5. Verdict

**accept** — owned CF, ABI, parse call shape, and product error strings are sealed without contradiction.
