# Review B (skeptical / adversarial): `aa_00722790` CSoundManager_AppendOggOrLxxExt_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00722790` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W38-AG) |
| **Counterpart** | `reviews/A_aa_00722790_CSoundManager_AppendOggOrLxxExt_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Function **replaces** existing extension | **Falsified** — pure append at C-string end; no scan for `.` |
| 2 | Flag polarity inverted (0 = `_lxx`) | **Falsified** — `cmp [ecx+0x308],0` then load `.ogg` only on zero; default path is `_lxx.ogg` |
| 3 | cdecl / bare `RET` | **Falsified** — `C2 04 00` = `RET 4`; thiscall + one stack arg |
| 4 | Returns bool success | **Falsified** — void; no AL/EAX contract used by callers |
| 5 | Always CSoundManager instance in ECX | **Nuanced** — Probe passes CSoundManager this; 5/6 sites load ECX from `Client_GetMissionCompleteAudioTable` (`&DAT_00d20210`). Shared **`+0x308`** flag layout sealed; product type identity open |
| 6 | Bounds-checks path buffer | **Falsified** — no capacity test; callers own stack buffers |
| 7 | Product name proven | **Sustained as gap** — structural `_Inferred` only |
| 8 | `_lxx` means language-xx locale | **Open** — string literal only; no English comment in image |
| 9 | Calls CRT `strcat` | **Falsified** — inline strlen + `rep movs*`; equivalent effect |
| 10 | Non-leaf / side effects | **Falsified** — no CALL; only mutates `pathBuf` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Suffix selection by +0x308 | **Confirmed** | Wrong audio file family |
| thiscall + RET 4 | **Confirmed** | Stack imbalance |
| Append-not-replace | **Confirmed** | Double-extension if caller already has `.ogg` |
| Host type == CSoundManager | **Medium** | Over-typed singleton if table is distinct class |
| `_lxx` product meaning | **Open** | Wrong localization model in port docs |
| Buffer always large enough | **Caller-owned** | Overflow if path near buffer end |

---

## 3. Cross-check against raw + bytes

```
if (*(u8*)(ecx+0x308) == 0)
  src = ".ogg";        // 5 B incl NUL
else
  src = "_lxx.ogg";    // 9 B incl NUL
// edi = end of pathBuf
// rep movsd + rep movsb  (len includes NUL)
// ret 4
```

Clean must **not** invent: extension strip, heap alloc, PathFileExists, locale lookup tables, or return codes.

Reject canonicalizing the long `Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_*` alias — that only describes one caller family.

---

## 4. Surviving contract for AutoCore

```c
// Client path normalization only. Server play authority does not need this.
// Ensure pathBuf has room for +8 chars + NUL worst case ("_lxx.ogg").
void SoundHost_AppendOggOrLxxExt(void* host, char* pathBuf);
// host+0x308 == 0 → ".ogg"; else → "_lxx.ogg"
```

Port note: if a DevTool mirrors client path resolution (with ProbeSoundFileExists), honor the same flag and suffixes. Do **not** assume the buffer already lacks an extension — retail always appends.

---

## 5. Open questions

1. Product symbol / `_lxx` English.
2. Exact type identity of `Client_GetMissionCompleteAudioTable` return vs CSoundManager.
3. Who writes `host+0x308` (init / options / locale).
4. Runtime / bit-exact / image diff.

**Verdict:** **accept** — adversarial checks leave only naming/host-type nuance; CF and ABI sealed.
