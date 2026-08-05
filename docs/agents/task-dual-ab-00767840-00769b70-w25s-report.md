# Dual A/B report — W25-S OWN-ONLY (`0x00767840`, `0x00769b70`)

**Date:** 2026-07-29  
**Agent:** W25-S OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00767840`, `0x00769b70`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / complete analysis). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_00767840` stoChunkReader_ReadTextToken | **accept** — **EDI out + stack reader/flag + ret 8; scan/pushback/allowEndBrace sealed** |
| `aa_00769b70` stoChunkReader_ReadQuotedTag | **accept** — **EDI out + ret 4 + SEH; double-quote strip-only success sealed** |

---

## `aa_00767840` — stoChunkReader_ReadTextToken

### Sealed facts

1. **Body:** `0x00767840`–`0x007679d3` exclusive. Final `C2 08 00`; following `CC` pad.

2. **ABI:** **EDI = `std::string* outToken`**; stack **`reader*`**, **`char allowEndBrace`**; **`ret 8`**. Not ECX-thiscall.

3. **Early gate:** if `allowEndBrace==0` and sticky `+0x402c < 0` → return **−1**.

4. **Pushback:** if `+0x4060 != 0`, assign out from `+0x404c` and clear pushback string; else scan window at `+0x2c` with cursor `+0x18`, refill `FUN_00435df0`, skip `isspace`, optional `'`/`"` (quotes **kept** in token).

5. **Past-end:** token `"}"` and `allowEndBrace==0` → log `stoChunk.cpp:0x2a0` *"Attempt to read past end of chunk…"*, sticky=−1, re-stash pushback, clear out, return **−1**. With `allowEndBrace!=0`, `"}"` is a normal success token.

6. **Callees:** `FUN_00435df0`, `vog_LogMessage`, `isspace`, `std::string` ops.

7. **Callers (2):** LeaveChunk `0x00769e40` @ `00769f07` (**allow=1**); PeekChunkTag `0x0076a900` @ `0076a96d`.

8. **Name:** structural `stoChunkReader_ReadTextToken` (product spelling residual).

### Gaps

1. Product/PDB symbol spelling.  
2. Runtime / bit-exact / differential — open.  
3. Full reader struct product layout beyond touched offsets.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00767840_stoChunkReader_ReadTextToken.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00767840_stoChunkReader_ReadTextToken.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00767840_stoChunkReader_ReadTextToken.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00767840_stoChunkReader_ReadTextToken.md` |
| Function record | `docs/reconstruction/functions/aa_00767840_stoChunkReader_ReadTextToken.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_00767840_FUN_00767840.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_ReadTextToken.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00767840.cpp` |
| Raw | `docs/reconstruction/raw/aa_00767840_FUN_00767840.md` |
| Annotated | `docs/reconstruction/raw/aa_00767840_FUN_00767840.annotated.md` |

---

## `aa_00769b70` — stoChunkReader_ReadQuotedTag

### Sealed facts

1. **Body:** `0x00769b70`–`0x00769d79` exclusive. SEH `LAB_009affaf`. Final `C2 04 00`.

2. **ABI:** **EDI = `std::string* outTag`**; stack **`reader*`**; **`ret 4`**.

3. **Entry:** sticky `< 0` → **−1** (no scan).

4. **Token obtain:** same pushback/scan family as ReadTextToken (quotes kept in raw token).

5. **Success filter (critical):** return **0** only when `size > 1` and first/last bytes are `0x22` (`"`), after `substr(1, size-2)`. Bare, single-quoted, `{`, unstripped tokens → **−1**.

6. **Past-end:** token `"}"` → same log/sticky/re-stash as tokenizer → **−1**.

7. **Callees:** `FUN_00435df0`, `vog_LogMessage`, `isspace`, `std::string` (+ `substr`/dtor).

8. **Callers (3):** `FUN_0076a200` @ `0076a21c`; OpenChunk `0x0076a2c0` @ `0076a539`; PeekChunkTag `0x0076a900` @ `0076a9b8`.

9. **Name:** structural `stoChunkReader_ReadQuotedTag` (matches OpenChunk dual residual name).

### Gaps

1. Product/PDB symbol spelling.  
2. Single-quote rejection product rationale.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00769b70_stoChunkReader_ReadQuotedTag.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00769b70_stoChunkReader_ReadQuotedTag.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00769b70_stoChunkReader_ReadQuotedTag.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00769b70_stoChunkReader_ReadQuotedTag.md` |
| Function record | `docs/reconstruction/functions/aa_00769b70_stoChunkReader_ReadQuotedTag.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_00769b70_FUN_00769b70.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_ReadQuotedTag.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00769b70.cpp` |
| Raw | `docs/reconstruction/raw/aa_00769b70_FUN_00769b70.md` |
| Annotated | `docs/reconstruction/raw/aa_00769b70_FUN_00769b70.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### ReadTextToken (`0x00767840`)

- Port as the **shared text tokenizer** for stoChunk leave / peek / brace walks.
- Preserve **EDI out** (or explicit out-string) + **allowEndBrace** flag — LeaveChunk **must** pass true so `}` is not sticky-failed mid-walk.
- Keep quotes **inside** the token when quoted; do not invent strip here.
- Pushback at `+0x404c` / non-empty `+0x4060` must round-trip with past-end restash.

### ReadQuotedTag (`0x00769b70`)

- Port as OpenChunk/Peek **tag** reader — **strict double-quote** success only.
- Do not accept bare tag names; strip exactly `substr(1, size-2)`.
- Distinct from ReadTextToken: no allowEndBrace, ret 4, SEH, success filter.

---

## This report

`docs/agents/task-dual-ab-00767840-00769b70-w25s-report.md`
