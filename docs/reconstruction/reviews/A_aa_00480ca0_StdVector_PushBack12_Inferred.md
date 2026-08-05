# Review A (reconstruction fidelity): `aa_00480ca0` StdVector_PushBack12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00480ca0` |
| **VA** | `0x00480ca0` |
| **Body** | `0x00480ca0`–`0x00480d17` (120 bytes) |
| **Canonical name** | `StdVector_PushBack12_Inferred` |
| **Ghidra name** | `FUN_00480ca0` |
| **Review date** | `2026-07-29` (W18-O dual seal) |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00480ca0_StdVector_PushBack12_Inferred.md` |
| **System** | container / std::vector&lt;Element12&gt; push |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`).

---

## 1. Purpose

Push **exactly one 12-byte element** onto a 3-pointer MSVC-style vector in **EAX**, source pointed by **EBX**. Capacity-hit fast path copies via `FUN_0042acc0`; else grow via `FUN_0042a710`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00480ca0_FUN_00480ca0.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_00480ca0_FUN_00480ca0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_PushBack12_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00480ca0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00480ca0_FUN_00480ca0.md` |
| Live decompile | `0x00480ca0` |
| Bytes | `read_memory` 120 B @ entry |
| Call sites | `0x0071dfb4` (`LEA EBX,[esp+10]`), `0x007867f9` (`LEA EBX,[esp+1c]; MOV EAX,EDI`) |
| Callees | `FUN_0042acc0`, `FUN_0042a710` decompiles |

---

## 3. Byte / ABI seal

| Claim | Confidence | Evidence |
|---|---|---|
| Body 120 B ends dual `pop;ret` | **Confirmed** | `read_memory`; Ghidra body end `00480d17` |
| `EDI←EAX` vector this | **Confirmed** | prologue `8B F8` |
| Layout +4/+8/+0xc | **High** | begin/end/capEnd loads |
| Stride **0xC** | **Confirmed** | `83 C6 0C`; `/0xc` via `B8 AB AA AA 2A` |
| Fast: `ECX=1`, `EDX=EBX`, `EAX=end` → `0042acc0` | **Confirmed** | imm `B9 01 00 00 00`, `8B D3` |
| Slow: `0042a710` with EBX pushed | **Confirmed** | `53` before call |
| EBX = Element12* | **Confirmed** | both callers `LEA EBX, local12` |
| Bare `RET` (no stack args) | **Confirmed** | `C3` |
| Decompiler `param_1` as value dword | **Noisy** | overridden by bytes |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| begin==0 or full → slow | **Yes** |
| size &lt; cap → copy 1×12 + end+=12 | **Yes** |
| No other branches | **Yes** |
| Invented clamps/locks | **None** |

---

## 5. Gaps

1. Product/STL symbol name — open (`_Inferred`).
2. Dual seal of grow chain `FUN_0042a710` / `FUN_00480d20`.
3. Element12 semantic type is caller-specific (not a single product struct).
4. Runtime / bit-exact / image diff — open.

**Verdict:** **accept-with-gaps**
