# Review A (reconstruction fidelity): `aa_00767840` stoChunkReader_ReadTextToken

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767840` |
| **VA** | `0x00767840`–`0x007679d3` |
| **Canonical name** | `stoChunkReader_ReadTextToken` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (text token read) |
| **Counterpart** | `reviews/B_aa_00767840_stoChunkReader_ReadTextToken.md` |
| **System** | storage / arda2 stoChunk |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` `0x00767840` + `read_memory` prologue/epilogue + `analyze_function_complete` + xrefs. No `disassemble_bytes`. No ledgers / Launcher.

---

## 1. Purpose

General-purpose **text token reader** on `stoChunkReader`:

1. Optional sticky early-out when `allowEndBrace==0`.
2. Pushback consume (`+0x4060` / `+0x404c`) or stream scan (isspace / quotes / refill).
3. `"}"` + `allowEndBrace==0` → past-end log + sticky fail + re-stash.
4. Else success with token in EDI out-string (quotes retained).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00767840_FUN_00767840.md` (+ live seal append) |
| Annotated | `docs/reconstruction/raw/aa_00767840_FUN_00767840.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_ReadTextToken.cpp` |
| Function record | `docs/reconstruction/functions/aa_00767840_stoChunkReader_ReadTextToken.md` |
| Live Ghidra | decompile + meta + memory + xrefs |
| Strings | path `0x00a9d738`; msg `0x00a9d498`; line `0x2a0` |
| Sibling | LeaveChunk `aa_00769e40`; PeekChunkTag `aa_0076a900`; ReadQuotedTag `aa_00769b70` |

---

## 3. Signature

```c
/* EDI = std::string *outToken */
uint32_t __stdcall stoChunkReader_ReadTextToken(
    stoChunkReader *reader, char allowEndBrace);
// ret 8; EAX = 0 / 0xffffffff
```

| Item | Evidence |
|---|---|
| Stack reader + flag | `mov ebp,[esp+…]`; `cmp byte [esp+0x10],0` |
| EDI out | `mov ecx,edi` into string ops; decompiler `unaff_EDI` |
| Cleanup | epilogue `C2 08 00` |
| Body | `00767840`–`007679d3` |

---

## 4. Control flow (sealed)

```
if allowEndBrace==0 and sticky<0: return -1
if pushback_nonempty(+0x4060):
  out = pushback(+0x404c); clear pushback
else:
  clear out; scan:
    refill if need byte
    skip leading isspace
    optional open quote (' or ") — quote char included
    accumulate until: unquoted whitespace | matching close quote
    EOF empty → sticky=-1 return -1; EOF partial → finish
if out=="}" and allowEndBrace==0:
  log past-end; sticky=-1; pushback=out; clear out; return -1
return 0
```

---

## 5. Machine bytes (selected)

```
83 EC 08 80 7C 24 10 00 55 8B 6C 24 10 … C2 08 00
; success tail: 33 C0 … C2 08 00
```

---

## 6. Confidence

| Claim | Level |
|---|---|
| ABI EDI + stack2 + ret 8 | **High** |
| Pushback / scan / quote rules | **High** |
| allowEndBrace gates `}` sticky | **High** |
| Shared offsets with typed text readers | **High** |
| Product symbol spelling | **Probable** |
| Runtime / bit-exact | **Open** |

---

## 7. Gaps (do not block seal)

1. Product English name (ReadToken vs GetNextToken).
2. Exhaustive SSO layout English for `std::string` proxy field.
3. Runtime golden.

---

## Verdict

**accept** — ABI, CF, offsets, past-end policy, and allowEndBrace semantics sealed static against live Ghidra + bytes.
