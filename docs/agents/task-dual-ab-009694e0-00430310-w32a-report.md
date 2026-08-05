# Dual A/B report — W32-A OWN `aa_009694e0` + `aa_00430310`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W32-A  
**Scope:** VAs `0x009694e0`, `0x00430310` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address` + callee decompiles for role only. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave32_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_009694e0` BasicString_CopyEnsureTrailingDirSep | **accept-with-gaps** — trailing-sep CF/ABI/SSO sealed; product English + nested `FUN_00416510` open |
| `aa_00430310` StringVec_InsertOne | **accept-with-gaps** — thiscall insert-one + 0x1c index rebuild sealed; nested `FUN_004306b0` (W32-B) + product English open |

---

## VA `0x009694e0` — sealed facts

1. **Body:** `0x009694e0`–`0x009695b1` exclusive (**209 B** / `0xD1`; final `C3` @ `0x009695B0`; pad `CC…`).
2. **ABI:** **cdecl**; stack **out\***, **src\***; returns **out\*** in EAX; SEH `LAB_009ab825`; frame cleanup `add esp,0x28; ret`.
3. **Semantics:** MSVC `basic_string` (sizeof **0x1c**) copy with optional trailing dir sep:
   - If `_Mysize == 0` → copy-ctor(out, src).
   - Else read last char via SSO (`_Myres < 0x10` → data @ `src+4`) or heap (`*(char**)(src+4)`).
   - If last ∉ {`':' (0x3A)`, `'/' (0x2F)`, `'\\' (0x5C)`}: `FUN_00416510(tmp, src, '/')` then copy to out; dtor tmp.
   - Else plain copy-ctor(out, src).
4. **Classification:** worker.
5. **Callers:** `FUN_009696c0` @ `0x009696e3`; `FUN_009697a0` @ `0x009697c3`; `FUN_00969830` @ `0x00969852`.
6. **Callees:** IAT `basic_string` copy-ctor `[0x009c62ec]`; IAT dtor `[0x009c62f4]`; `FUN_00416510`.
7. **Name:** `BasicString_CopyEnsureTrailingDirSep` (Ghidra `FUN_009694e0`; **Inferred** structural). Reject scaffold `Named_CalleeOf_Named_CalleeOf_Named_assManager_009694e0`.
8. **Decompile ≡ bytes** for empty/SSO/charset/append-`/` paths.  
   Full hex: raw W32-A append (209 B).

### Gaps

- Product English for path-list / search-root role.  
- Nested `FUN_00416510` not dual-owned here.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_009694e0_BasicString_CopyEnsureTrailingDirSep.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_009694e0_BasicString_CopyEnsureTrailingDirSep.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_009694e0_FUN_009694e0.md` |
| Annotated | `docs/reconstruction/raw/aa_009694e0_FUN_009694e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BasicString_CopyEnsureTrailingDirSep.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009694e0.cpp` |
| Function | `docs/reconstruction/functions/aa_009694e0_FUN_009694e0.md` |
| Function named | `docs/reconstruction/functions/aa_009694e0_BasicString_CopyEnsureTrailingDirSep.md` |
| Scratch | `docs/reconstruction/tmp/a_009694e0.md` |

---

## VA `0x00430310` — sealed facts

1. **Body:** `0x00430310`–`0x00430383` exclusive (**115 B** / `0x73`; epilogue `C2 0C 00`).
2. **ABI:** **`__thiscall`** ECX=`StringVecShell*`; stack **out_iterator\***, **pos**, **value\***; **RET 12**; void.
3. **Semantics:** Insert **one** `basic_string` (stride **0x1c**) at `pos`:
   - If begin null or `(end-begin)/0x1c == 0` → index **0**; else index = `(pos-begin)/0x1c` (signed div magic `0x92492493`).
   - `FUN_004306b0(this, pos, count=1, value)` — nested insert/grow (W32-B).
   - `*out_iterator = begin' + index * 0x1c` (valid after possible reallocation).
4. **Classification:** worker.
5. **Callers:** `FUN_004301f0` @ `0x0043026d` (insert at **end** when capacity exhausted); `FUN_00969830` @ `0x00969871` (insert at **begin** / push_front).
6. **Callees:** `FUN_004306b0` only.
7. **Name:** `StringVec_InsertOne` (Ghidra `FUN_00430310`; **Inferred**). Reject scaffold `Named_CalleeOf_*VOG_DEBUG*_00430310`.
8. **Decompile ≡ bytes** for index/count/out-rebuild; bare `undefined4` on value avoided in clean (`const void*` / string\*).  
   Full hex: raw W32-A append (115 B).

### Gaps

- Nested `FUN_004306b0` dual owned by W32-B (grow thresholds not re-sealed here).  
- Product English for path-list container beyond structural `StringVecShell`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00430310_StringVec_InsertOne.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00430310_StringVec_InsertOne.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00430310_FUN_00430310.md` |
| Annotated | `docs/reconstruction/raw/aa_00430310_FUN_00430310.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StringVec_InsertOne.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00430310.cpp` |
| Function | `docs/reconstruction/functions/aa_00430310_FUN_00430310.md` |
| Function named | `docs/reconstruction/functions/aa_00430310_StringVec_InsertOne.md` |
| Scratch | `docs/reconstruction/tmp/a_00430310.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `009694e0` | Port as **pure path normalize/copy**: empty or last ∈ `{':','/','\\'}` → copy; else `src + '/'`. Use MSVC `basic_string` layout only if bit-exact; behavior matches `std::string` + `'/'`. Do **not** append `'\\'`; do **not** mutate src. Closes nested residual named by W31-E `StringVec_PushFront_EnsureTrailingDirSep`. |
| `00430310` | Port as **`vector<string>::insert(pos, value)` returning iterator**: snapshot index, insert one, return `begin()+index`. Callers: push_front (`pos=begin`) and push_back-via-insert (`pos=end`). Element stride **must** be `0x1c` for this binary's string. Nested grow stays in `FUN_004306b0`. |
| Pair with | Parent `StringVec_PushFront_EnsureTrailingDirSep` (`0x00969830`, W31-E); nested grow `FUN_004306b0` (`0x004306b0`, W32-B); find helpers `FUN_009696c0` / `FUN_009697a0`; push_back gate `FUN_004301f0`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callee decompile for role). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Rejected assManager / VOG_DEBUG scaffold alias plates.  
- Avoided bare `undefined4` in clean (`uint8_t*` / `const void*` / explicit structs).
