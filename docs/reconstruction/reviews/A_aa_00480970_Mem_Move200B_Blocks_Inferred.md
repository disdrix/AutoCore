# Review A (reconstruction fidelity): `aa_00480970` Mem_Move200B_Blocks_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00480970` |
| **VA** | `0x00480970` |
| **Body** | `0x00480970`–`0x004809a0` (49 bytes) |
| **Canonical name** | `Mem_Move200B_Blocks_Inferred` |
| **Ghidra name** | `FUN_00480970` |
| **Review date** | `2026-07-29` (W21-M dual seal) |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00480970_Mem_Move200B_Blocks_Inferred.md` |
| **System** | container / mem / 200-byte record range move |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). Supporting: `analyze_function_complete`, callers, assembly_context.

---

## 1. Purpose

Leaf **range block-move**: copy `[src, srcEnd)` to `dest` in fixed **200-byte** chunks (`REP MOVSD` × 50 dwords). Callers use it to shift vector tails after erasing one 200-byte record.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00480970_FUN_00480970.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_00480970_FUN_00480970.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mem_Move200B_Blocks_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00480970.cpp` |
| Function record | `docs/reconstruction/functions/aa_00480970_FUN_00480970.md` |
| Live decompile | `0x00480970` |
| Bytes | `read_memory` 49 B @ entry |
| Call sites | `0x0072003a`, `0x00480579`, `0x00721f0e` (+ second erase site) |

---

## 3. Byte / ABI seal

| Claim | Confidence | Evidence |
|---|---|---|
| Body 49 B ends `pop ebx; ret` | **Confirmed** | `read_memory`; Ghidra body `00480970`–`004809a0` |
| `EDX←[esp+4]` src | **Confirmed** | prologue `8B 54 24 04` |
| `EAX←[esp+0xC]` dest | **Confirmed** | `8B 44 24 0C` |
| `EBX←end` after push | **Confirmed** | `53; 8B 5C 24 0C` |
| Stride **0xC8** / count **0x32** | **Confirmed** | `81 C2 C8…`; `B9 32…`; `05 C8…`; `F3 A5` |
| Bare `RET` (cdecl) | **Confirmed** | `C3`; callers `ADD ESP,0x10` when 4 pushes |
| Leaf (no callees) | **Confirmed** | complete analysis |
| Erase composition end-=200 | **Confirmed** | callers `ADD …, 0xFFFFFF38` |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| src==end → return | **Yes** |
| loop: copy 200 B, advance both | **Yes** |
| Invented free/destruct/lock | **None** |

---

## 5. Gaps

1. Product/CRT symbol name — open (`_Inferred`).
2. Overlap contract documentation (erase path is left-shift; rightward overlap untested).
3. Element product type beyond shared 200 B stride with sound records.
4. Runtime / bit-exact / image diff — open.

**Verdict:** **accept-with-gaps**
