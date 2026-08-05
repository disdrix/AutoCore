# Dual A/B report — W38-AG OWN `aa_00722790`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-AG  
**Scope:** VA `0x00722790` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs + call-site context. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-AG).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00722790` CSoundManager_AppendOggOrLxxExt_Inferred | **accept** — thiscall leaf / RET 4 / +0x308 → `.ogg`\|`_lxx.ogg` strcat sealed |

---

## VA `0x00722790` — sealed facts

1. **Body:** `0x00722790`–`0x007227de` exclusive (**78 B** / `0x4E`; pad `CC` then next @ `0x007227e0`).
2. **ABI:** **thiscall** **ECX=`host*`**, stack **`char* pathBuf`**, **`RET 4`**, void. Leaf (no callees).
3. **Semantics:** MSVC-style **append Ogg extension**:
   - `*(char*)(host+0x308) == 0` → strcat **`".ogg"`** @ `0x00A9D9A4` (5 B incl NUL).
   - else → strcat **`"_lxx.ogg"`** @ `0x00AA91A0` (9 B incl NUL).
   - Find path end; `rep movsd` + residual `rep movsb` copies suffix **including NUL**.
   - **No** capacity check; **no** strip of existing extension.
4. **Classification:** worker (leaf).
5. **Callers (6):**
   - `FUN_00724870` ProbeSoundFileExists @ `0x007248A0` (ECX = CSoundManager this)
   - `FUN_004B88E0` MissionHost CollectMediaPreloads @ `0x004B8CE9`, `0x004B8D4B`
   - `FUN_00720DA0` @ `0x00720E6A`
   - `FUN_00721A80` @ `0x00721C06`
   - `FUN_007217C0` @ `0x00721968`  
   Sites 2–6 load ECX from **`Client_GetMissionCompleteAudioTable`** (`0x00723820` → `&DAT_00d20210`) which shares the **`+0x308`** flag layout.
6. **Callees:** none.
7. **Name:** `CSoundManager_AppendOggOrLxxExt_Inferred` (Ghidra `FUN_00722790`; **Inferred**). **Reject** long `Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_00722790` as canonical.
8. **Decompile vs bytes:** CF ≡ raw scaffold ≡ live decompile; **bytes win** on RET 4, flag polarity, string VAs.  
   Full hex: raw W38-AG append (78 B).

### Gaps

- Product/PDB English; meaning of **`_lxx`**.  
- Host type identity (CSoundManager vs audio-table singleton) beyond shared `+0x308`.  
- Who writes `host+0x308`.  
- Runtime / bit-exact / image diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00722790_CSoundManager_AppendOggOrLxxExt_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00722790_CSoundManager_AppendOggOrLxxExt_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00722790_FUN_00722790.md` |
| Annotated | `docs/reconstruction/raw/aa_00722790_FUN_00722790.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CSoundManager_AppendOggOrLxxExt_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00722790.cpp` |
| Function | `docs/reconstruction/functions/aa_00722790_FUN_00722790.md` |
| Function named | `docs/reconstruction/functions/aa_00722790_CSoundManager_AppendOggOrLxxExt_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00722790` | Port as **path suffix append** only: **ECX=host**, stack path, **RET 4**. Flag@**+0x308**: 0→`.ogg`, else→`_lxx.ogg`. No FS I/O. Client path-resolution / DevTool mirrors of ProbeSoundFileExists must honor both suffixes. Server authoritative play does **not** require this helper. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00724870` | `CSoundManager_ProbeSoundFileExists_Inferred` (W21-M) — primary parent |
| `0x004B88E0` | MissionHost CollectMediaPreloads (W32-H) — media preload caller |
| `0x00723820` | `Client_GetMissionCompleteAudioTable` — common ECX supplier |
| `0x00A9D9A4` | `".ogg"` literal |
| `0x00AA91A0` | `"_lxx.ogg"` literal |
| `host+0x308` | char flag selecting suffix |

Closes W38-AG OWN single: undualed **ogg extension append** leaf left open under ProbeSoundFileExists / mission media / play paths.

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural name only.  
- Rejected long Named_CalleeOf scaffold alias as canonical.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Distinguished append-not-replace; flag polarity sealed against inversion.  
- Terminal coverage: **false** always.
