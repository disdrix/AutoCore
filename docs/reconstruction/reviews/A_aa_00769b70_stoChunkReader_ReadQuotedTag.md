# Review A (reconstruction fidelity): `aa_00769b70` stoChunkReader_ReadQuotedTag

| Field | Value |
|---|---|
| **Stable ID** | `aa_00769b70` |
| **VA** | `0x00769b70`–`0x00769d79` |
| **Canonical name** | `stoChunkReader_ReadQuotedTag` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (quoted tag read) |
| **Counterpart** | `reviews/B_aa_00769b70_stoChunkReader_ReadQuotedTag.md` |
| **System** | storage / arda2 stoChunk |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` `0x00769b70` + `read_memory` prologue/strip/epilogue + `analyze_function_complete` + xrefs. No `disassemble_bytes`. No ledgers / Launcher.

---

## 1. Purpose

Strict **double-quoted tag** reader for text-mode OpenChunk / Peek:

1. Fail if sticky already `<0`.
2. Obtain token (pushback or shared scan).
3. `"}"` → past-end fail path.
4. Success **only** if token is `"…"` with `size>1`, then strip quotes via `substr(1, size-2)`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00769b70_FUN_00769b70.md` (+ live seal) |
| Annotated | `docs/reconstruction/raw/aa_00769b70_FUN_00769b70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_ReadQuotedTag.cpp` |
| Function record | `docs/reconstruction/functions/aa_00769b70_stoChunkReader_ReadQuotedTag.md` |
| Live Ghidra | decompile + meta + memory + xrefs |
| Callers | OpenChunk, PeekChunkTag, FUN_0076a200 |
| Twin | ReadTextToken `aa_00767840` |

---

## 3. Signature

```c
/* EDI = std::string *outTag */
uint32_t __stdcall stoChunkReader_ReadQuotedTag(stoChunkReader *reader);
// ret 4; SEH LAB_009affaf; EAX = 0 / 0xffffffff
```

| Item | Evidence |
|---|---|
| Stack reader | `mov ebp,[esp+0x3c]` after SEH frame |
| EDI out | string methods on edi; size `[edi+0x14]` |
| Cleanup | `C2 04 00` |
| Body | `00769b70`–`00769d79` |

---

## 4. Control flow (sealed)

```
if sticky < 0: return -1
if pushback empty (+0x4060==0):
  scan (same as ReadTextToken)
else:
  out = take pushback
if out == "}":
  log past-end; sticky=-1; restash; clear out
else if size > 1 and data[0]=='"' and data[size-1]=='"':
  out = substr(1, size-2); return 0
return -1
```

---

## 5. Machine bytes (selected)

```
; SEH + sticky gate
64 A1 00 00 00 00 6A FF 68 AF FF 9A 00 … 83 BD 2C 40 00 00 00

; strip
8B 77 14 83 FE 02 … 80 39 22 … 80 7C 30 FF 22 83 C6 FE 56 6A 01 … substr

; epilogue
83 C4 30 C2 04 00
```

---

## 6. Confidence

| Claim | Level |
|---|---|
| ABI EDI + stack1 + ret 4 + SEH | **High** |
| Scan twin of ReadTextToken | **High** |
| Success = double-quote strip only | **High** |
| `}` past-end | **High** |
| Product spelling | **Probable** |
| Runtime / bit-exact | **Open** |

---

## 7. Gaps (do not block seal)

1. Product English name.
2. Why single-quoted tags rejected (policy residual).
3. Runtime golden.

---

## Verdict

**accept** — ABI, CF, strip math, and fail policy sealed static against live Ghidra + bytes.
