# Review A (reconstruction fidelity): `aa_0076a200` stoChunkReader_TextReadString

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076a200` |
| **VA** | `0x0076a200`–`0x0076a2b5` |
| **Canonical name** | `stoChunkReader_TextReadString` (**Inferred**) |
| **Prior scaffold** | `FUN_0076a200` / `Named_stoChunk_0076a200` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction fidelity — OWN-ONLY W38-J |
| **Counterpart** | `reviews/B_aa_0076a200_stoChunkReader_TextReadString.md` |
| **System** | `storage` / arda2 `stoChunk` |
| **Verdict** | **accept** — ECX/EBX register ABI, ReadQuotedTag success, Expected-string fail log, 0/−1 sealed |

**Tools:** Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + xrefs + assembly context. **No** `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Read the next **double-quoted string** from a stoChunk **text** stream into a caller `std::string*`:

1. Call `stoChunkReader_ReadQuotedTag` (`0x00769b70`) with out=ECX, reader=EBX (pushed).
2. If tag read **≥ 0** → return **0** (out already holds stripped content).
3. Else format `"Expected string but got \"%s\" in chunk \"%s\""` using out + chunk name → log `stoChunk.cpp:0x44a` → return **−1**.

Binary peer: `FUN_00436f10`. Dispatcher: `FUN_00439a20` on `reader+0x4044`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0076a200_FUN_0076a200.md` (+ W38-J live seal) |
| Annotated | `docs/reconstruction/raw/aa_0076a200_FUN_0076a200.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_TextReadString.cpp` |
| Function record | `docs/reconstruction/functions/aa_0076a200_stoChunkReader_TextReadString.md` |
| Live decompile | Ghidra `decompile_function` `0x0076a200` — **≡** raw CF |
| Live bytes | `read_memory` full body; `C3` success/fail; pad then OpenChunk `0x0076a2c0` |
| Bounds | `get_function_by_address` → `0076a200`–`0076a2b5` |
| Inner helper | W25-S seal `stoChunkReader_ReadQuotedTag` |
| Call-site proof | `get_assembly_context` on `00458b95`, `009703a8`, `00439a40` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Out string | **ECX** → `mov edi,ecx` for ReadQuotedTag |
| Reader | **EBX** → `push ebx` as stack arg to ReadQuotedTag |
| Epilogue | **`C3`** plain ret |
| Return | **0** / **`0xffffffff`** |
| Body | `0x0076a200`–`0x0076a2b5` (**181 B**) |

```c
int32_t stoChunkReader_TextReadString(
    /* ECX */ std::string* out,
    /* EBX */ StoChunkReader* reader);
```

### 3.2 Success / fail — **SEALED**

| Path | CF |
|---|---|
| ReadQuotedTag ≥ 0 | restore SEH, `xor eax,eax`, `ret` |
| ReadQuotedTag < 0 | chunk name, SSO c_str on out + name, format, log line **0x44a**, `or eax,-1`, `ret` |

### 3.3 Error string — **SEALED**

`"Expected string but got \"%s\" in chunk \"%s\""` @ `0x00a9d22c` (image `read_memory`).

### 3.4 Three-rep — **SEALED**

live ≡ raw ≡ annotated ≡ clean plate CF.

---

## 4. Gaps (owned)

| Gap | Severity | Notes |
|---|---|---|
| Product/PDB English name | Low | Structural Inferred |
| Bare (unquoted) string acceptance | N/A | Rejected by ReadQuotedTag — intentional |
| Runtime / bit-exact / differential | Open | Not run |

---

## 5. Verdict

**accept** — thin sealed wrapper; ABI and fail log closed by bytes + sealed callee contract.
