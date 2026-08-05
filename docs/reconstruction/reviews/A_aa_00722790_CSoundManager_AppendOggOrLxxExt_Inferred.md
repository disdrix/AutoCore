# Review A (reconstruction fidelity): `aa_00722790` CSoundManager_AppendOggOrLxxExt_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00722790` |
| **VA** | `0x00722790` |
| **Body** | `0x00722790`–`0x007227de` (78 / `0x4E` bytes) |
| **Canonical name** | `CSoundManager_AppendOggOrLxxExt_Inferred` |
| **Ghidra name** | `FUN_00722790` |
| **Review date** | `2026-08-04` (W38-AG dual seal) |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00722790_CSoundManager_AppendOggOrLxxExt_Inferred.md` |
| **System** | client audio / sound path extension |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). Supporting: `analyze_function_complete`, `get_function_xrefs`, `get_assembly_context`.

---

## 1. Purpose

Leaf **thiscall** helper: append Ogg extension to a mutable path buffer. Host flag at **`+0x308`** chooses plain **`.ogg`** vs variant **`_lxx.ogg`**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00722790_FUN_00722790.md` (+ W38-AG append) |
| Annotated | `docs/reconstruction/raw/aa_00722790_FUN_00722790.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CSoundManager_AppendOggOrLxxExt_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00722790.cpp` |
| Function record | `docs/reconstruction/functions/aa_00722790_FUN_00722790.md` |
| Named record | `docs/reconstruction/functions/aa_00722790_CSoundManager_AppendOggOrLxxExt_Inferred.md` |
| Live decompile | `0x00722790` |
| Bytes | `read_memory` 128 B @ entry (78 B body + pad + next prologue) |
| String VAs | `read_memory` @ `0x00AA91A0`, `0x00A9D9A4` |
| Call sites | 6 xrefs (see raw append) |

---

## 3. Byte / ABI seal

| Claim | Confidence | Evidence |
|---|---|---|
| Body 78 B; ends `RET 4` | **Confirmed** | hex tail `C2 04 00`; Ghidra body `00722790`–`007227de`; pad `CC` |
| ECX = host | **Confirmed** | `cmp byte ptr [ecx+0x308],0`; callers set ECX before CALL |
| Stack0 = pathBuf | **Confirmed** | `mov edi,[esp+0xC]` after push esi/edi; Probe path `LEA`+`PUSH` |
| Flag 0 → `.ogg` | **Confirmed** | jz-path `mov eax,0x00A9D9A4`; string `2E6F676700` |
| Flag ≠0 → `_lxx.ogg` | **Confirmed** | default `mov eax,0x00AA91A0`; string `5F6C78782E6F676700` |
| strcat incl NUL | **Confirmed** | strlen walks past NUL; `rep movsd`/`movsb` length includes terminator |
| Leaf | **Confirmed** | callees empty; no CALL in body |
| Void return | **Confirmed** | no useful EAX set; callers ignore return |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Select suffix from host+0x308 | **Yes** |
| Measure suffix length incl NUL | **Yes** |
| Find path end | **Yes** |
| Bulk copy suffix | **Yes** |
| RET 4 | **Yes** |
| Invented bounds check / alloc / FS | **None** |

---

## 5. Gaps (non-blocking)

1. Product/PDB helper name — open (`_Inferred`).
2. Semantic English for **`_lxx`** (locale pack? low-bitrate? language code placeholder).
3. Whether every ECX is the same singleton type as Probe's CSoundManager (GetMissionCompleteAudioTable path shares `+0x308` layout).
4. Runtime / bit-exact / image diff — open.

**Verdict:** **accept** — structural contract fully sealed; gaps are naming/product only.
