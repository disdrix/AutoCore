# Review A (reconstruction fidelity): `aa_00724870` CSoundManager_ProbeSoundFileExists_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00724870` |
| **VA** | `0x00724870` |
| **Body** | `0x00724870`–`0x007249b0` (320 / `0x140` bytes) |
| **Canonical name** | `CSoundManager_ProbeSoundFileExists_Inferred` |
| **Ghidra name** | `FUN_00724870` |
| **Review date** | `2026-07-29` (W21-M dual seal) |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00724870_CSoundManager_ProbeSoundFileExists_Inferred.md` |
| **System** | client audio / CSoundManager path probe |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). Supporting: complete analysis, callers, assembly_context, callee decompiles.

---

## 1. Purpose

Existence probe for a sound path: append ogg extension, try `PathFileExistsA`, try search-root + basename combos, then config VFS fallback. Optional outs for normalized path and kind code **2**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00724870_FUN_00724870.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_00724870_FUN_00724870.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CSoundManager_ProbeSoundFileExists_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00724870.cpp` |
| Function record | `docs/reconstruction/functions/aa_00724870_FUN_00724870.md` |
| Live decompile | `0x00724870` + callees `00722790`, `007b6a20`, `007b6420`, `007b66c0` |
| Bytes | `read_memory` 320 B @ entry |
| Call sites | `0x00724a69`, `0x00724b6d`, `0x00726493`, `0x007271ac` |
| Parent | `FUN_007249c0` ResolveSoundPath |

---

## 3. Byte / ABI seal

| Claim | Confidence | Evidence |
|---|---|---|
| Body `0x140` B; `RET 0x0C` | **Confirmed** | `read_memory` tail `C2 0C 00`; Ghidra body end |
| EAX = path | **Confirmed** | callers `MOV EAX, path` immediately before CALL |
| Stack0 = this | **Confirmed** | `mov ecx,[esp+0x214]` → `FUN_00722790` thiscall |
| Stack1/2 out optional | **Confirmed** | decompile + success path; parents push 0,0 often |
| Extension append | **Confirmed** | callee `FUN_00722790` (`.ogg` / `_lxx.ogg`) |
| `PathFileExistsA` dual use | **Confirmed** | import + two call sites in body |
| Root table stride `0x1c` to `0xd1e7a4` | **Confirmed** | `add ebx,0x1c`; cmp end |
| Success `*outKind=2` | **Confirmed** | `C7 00 02 00 00 00` |
| Return AL bool | **Confirmed** | `mov al,1` / fail `xor` path; parents `TEST AL` |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| copy path → append ext | **Yes** |
| cfg bit0 → FS probe + root walk | **Yes** |
| fallback `007b66c0` → fail 0 | **Yes** |
| success outs + return 1 | **Yes** |
| Invented server RPC / play | **None** |

---

## 5. Gaps

1. Product helper name — open (`_Inferred`).
2. Semantic English for outKind **`2`**.
3. Who fills `DAT_00d1e574` roots at runtime.
4. Dual seal of extension / fallback callees.
5. Runtime / bit-exact / image diff — open.

**Verdict:** **accept-with-gaps**
