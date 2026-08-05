# Review A (reconstruction fidelity): `aa_00769e40` stoChunkReader_LeaveChunk

| Field | Value |
|---|---|
| **Stable ID** | `aa_00769e40` |
| **VA** | `0x00769e40`–`0x00769fcc` |
| **Canonical name** | `stoChunkReader_LeaveChunk` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (chunk leave / ring pop) |
| **Counterpart** | `reviews/B_aa_00769e40_stoChunkReader_LeaveChunk.md` |
| **System** | storage / arda2 stoChunk |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` `0x00769e40` + `read_memory` prologue/mid/tail + callees/callers/xrefs + function meta. No `disassemble_bytes`. No ledgers / Launcher.

---

## 1. Purpose

Leave the current open chunk on a `stoChunkReader` after Unserialize work:

1. Reset sticky `this+0x402c` to **0**.
2. **Binary mode** (`+0x4044==0`): compute ring-top index, read **end absolute** from ring entry `+0x10`, either reposition the stream window to that end or OR sticky **−1** if end is invalid.
3. **Text mode** (`+0x4044!=0`): walk tokens with `FUN_00767840(this,1)` balancing `{` / `}` from depth **1**; log and return **−1** if sticky goes negative.
4. **Pop** ring write index; if write becomes 0, clear ring base.
5. Return sticky in **EAX**.

Pairs with `stoChunkReader_EnterChunkScope` / `OpenChunk` as the leave half of the scope pattern used across asset Unserialize.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00769e40_FUN_00769e40.md` |
| Annotated | `docs/reconstruction/raw/aa_00769e40_FUN_00769e40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_LeaveChunk.cpp` |
| Function record | `docs/reconstruction/functions/aa_00769e40_stoChunkReader_LeaveChunk.md` |
| Live Ghidra | `decompile_function` `0x00769e40`; `get_function_by_address`; `read_memory` body; callees/callers |
| Sibling sealed | EnterChunkScope `aa_004370b0`; OpenChunk `aa_0076a2c0` |
| Strings | `stoChunk.cpp` @ `0x00a9d738`; msg @ `0x00a9d4f0`; `"{"` `0x00a6c044`; `"}"` `0x00a6bfd0` |

---

## 3. Signature

```c
uint32_t __fastcall stoChunkReader_LeaveChunk(stoChunkReader *this /* ECX */);
// no stack args; plain RET; EAX = sticky (0 / 0xffffffff)
```

| Item | Evidence |
|---|---|
| Convention | `mov esi, ecx`; epilogue plain `C3` — **High** |
| Body range | `00769e40`–`00769fcc` (`get_function_by_address`) |
| SEH | `push -1` / `fs:[0]` / `LAB_009affc2` |
| Return | `mov eax,[esi+0x402c]` then restore SEH / `ret` |

---

## 4. Control flow (sealed)

```
sticky = 0
if textMode(+0x4044) == 0:
  idx = wrap(write + base - 1, capacity)
  end = entries[idx]->endAbs  // entry+0x10
  if end < 0 || limit(+0x28) < end:
    sticky |= -1
  else if end outside [base, base+remain):
    base=end; remain=0; cursor=0
  else:
    cursor = end - base
else:
  depth = 1
  do:
    sticky |= FUN_00767840(this, 1)
    if sticky < 0: log "Could not find end of text chunk"; return -1
    if token == "{": depth++
    if token == "}": depth--
  while depth != 0
if write != 0:
  write--
  if write == 0: baseIdx = 0
return sticky
```

---

## 5. Machine bytes (selected)

Prologue / mode:

```
6A FF 64 A1 00 00 00 00 68 C2 FF 9A 00 50 64 89 25 00 00 00 00
83 EC 1C 53 55 56 57 8B F1 33 FF
39 BE 44 40 00 00     ; cmp [esi+0x4044], edi(0)
89 BE 2C 40 00 00     ; mov [esi+0x402c], 0
75 74                 ; jnz text
```

Binary sticky fail uses `or eax,-1` / `or [esi+0x402c],eax`. Success path ORs **0** (no-op). Decompile's `*(sticky)=*(sticky)` is the OR-0 idiom.

---

## 6. Confidence

| Claim | Level |
|---|---|
| ABI + sticky clear/OR + mode gate | **High** |
| Ring wrap + pop write/base | **High** |
| Binary end seek via entry+0x10 | **High** |
| Text brace nest + log | **High** |
| endAbs / limit English names | **Probable** |
| Full ring element product layout | **Probable** (OpenChunk sibling) |
| Runtime / bit-exact | **Open** |

---

## 7. Gaps (do not block seal)

1. Product English for `entry+0x10` and `this+0x28`.
2. Tokenizer `FUN_00767840` dual (not owned).
3. Exhaustive caller catalog beyond sample Unserialize leave sites.
4. Runtime live verification.

---

## Verdict

**accept-with-gaps** — leave CF, ABI, offsets, binary seek, text brace walk, and ring pop sealed static. English field names and tokenizer product remain open.
