# Review A (reconstruction fidelity): `aa_00436900` stoChunkReader_ReadU32_ModeDispatch

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436900` |
| **VA** | `0x00436900` |
| **Body** | `0x00436900`–`0x0043691a` (27 bytes) |
| **Canonical name** | `stoChunkReader_ReadU32_ModeDispatch` |
| **Prior scaffold** | `FUN_00436900` |
| **Review date** | `2026-07-29` (W22-R dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00436900_stoChunkReader_ReadU32_ModeDispatch.md` |
| **System** | storage / arda2 stoChunk |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Dispatch a **single uint32** read on a `stoChunkReader` by **mode** at `reader+0x4044`:

| Mode | Branch | Callee |
|---|---|---|
| `== 0` | binary | `stoChunkReader_ReadU32` (`FUN_00437050`) |
| `≠ 0` | text | `FUN_007689e0` (token → uint32; plate `stoChunk.cpp`) |

Used from gfx unserialize paths (`gfxGeometryPiece_Unserialize`, `gfxVertexBufferImpl_Unserialize`, etc.).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00436900` |
| Bytes | `read_memory` 32 B @ entry — mode cmp, binary call, text EDI setup, rets |
| Bounds | `get_function_by_address` body `00436900`–`0043691a` |
| Callees | `get_function_callees` → `00437050`, `007689e0` |
| Callers | `get_function_callers` / xrefs → gfx + FUN_0095ef50 / FUN_00964690 |
| Nested | prior seals: ReadU32 W18-N; text path decompile (plate) |
| Raw / clean | `aa_00436900_*`, `stoChunkReader_ReadU32_ModeDispatch.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Mode gate `[eax+0x4044]==0` | **Confirmed** | `83 B8 44 40 00 00 00` |
| Binary → `FUN_00437050` | **Confirmed** | rel32 + sealed W18-N |
| Text → `FUN_007689e0` + `mov edi,eax` | **Confirmed** | bytes + text decompile `unaff_EDI` |
| ECX = out* (`push ecx`) | **Confirmed** | both arms |
| plain `ret` epilogues | **Confirmed** | `c3` both arms |
| Return status in EAX | **Confirmed** | callees return 0/−1; no EAX clobber after call |
| Decompiler `void` | **Confirmed residual** | understates |
| Product English name | **Inferred** | role-sealed ModeDispatch |
| `+0x4044` enum vs bool | **Probable** | only cmp-to-zero in this unit |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| cmp mode @ +0x4044 | Yes |
| binary call ReadU32 | Yes |
| text save EDI / mov EDI=reader / call text | Yes |
| status return | Yes (clean returns `int32_t`) |

---

## 5. Gaps / open

1. Product plate spelling of the dispatch helper (may be overload of `ReadU32` in source).
2. Full text-reader contract (`FUN_007689e0`) — out of owned scope (peer only).
3. Runtime / bit-exact / differential.
4. Whether any caller relies on EDI preservation across the binary arm (binary arm does **not** touch EDI).

**Verdict:** **accept**
