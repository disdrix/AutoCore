# Review A (reconstruction fidelity): `aa_008f6800` ChatLog_FileAppendLine

| Field | Value |
|---|---|
| **Stable ID** | `aa_008f6800` |
| **VA** | `0x008f6800` |
| **Canonical name (working)** | `ChatLog_FileAppendLine` (was `FUN_008f6800` / scaffold `Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_008f6800`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN VA only) |
| **Counterpart** | `reviews/B_aa_008f6800_ChatLog_FileAppendLine.md` |
| **System tag** | chat UI / file logging (callee of `CDlgChatLog_AppendChannelMessage` @ `0x008f8200`) |
| **Verdict** | **accept-with-gaps** (ABI + open modes + line format sealed; style-format helper product open) |

---

## 1. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008f6800_FUN_008f6800.md` |
| Annotated | `docs/reconstruction/raw/aa_008f6800_FUN_008f6800.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_008f6800.cpp` |
| Function record | `docs/reconstruction/functions/aa_008f6800_FUN_008f6800.md` |
| Parent dual | `reviews/A_aa_008f8200_CDlgChatLog_AppendChannelMessage.md` (file-log call site) |
| Live re-decompile | Ghidra MCP `force_decompile` + `decompile_function` @ `0x008f6800` (2026-07-29) — body ≡ raw |
| Live analysis | `analyze_function_complete` — sole xref `008f82ec` in `FUN_008f8200` |
| Live assembly context | prologue/call-site/epilogue via `get_assembly_context` (OWN body + sole call site for ABI) |
| Live strings | `read_memory` on mode/format/name tables |

**Not performed:** callee duals (`FUN_007a69d0`, `FUN_007a6de0`, `FUN_008f6030`), runtime file capture, bit-exact, ledgers.

---

## 2. Purpose

**Disk sink** for chat lines: open a log path, optionally stamp a local-time prefix, build a line body from a style prefix + message text, write one `fprintf` line, close.

Not a dialog method (no `this` / ECX). Not channel enable / ignore / ring / UI — pure file I/O.

Sole static caller: `CDlgChatLog_AppendChannelMessage` @ `0x008f8200` after combat/normal path selection (`chat_log_combat.txt` vs `chat_log.txt`).

---

## 3. Calling convention (sealed)

| Slot | Location | Role | Evidence |
|---|---|---|---|
| `pszPath` | **EAX** on entry | File path C-string | Prologue `MOV ESI,EAX` → `fopen(ESI, …)`; caller loads `0xa36c84` / `0xa36c70` |
| `pszStyle` | **EBX** on entry | Style / speaker prefix (nullable / empty) | `TEST EBX` / `CMP [EBX],0`; caller `LEA EBX,[ESP+0x14]` (styleBuf) |
| `nStyleKey` | stack `[EBP+0x8]` | First stdcall arg; fed to `FUN_008f6030` as **EAX** | Asm `MOV EAX,[EBP+0x8]; PUSH EBX; CALL 0x008f6030`; sole caller `PUSH EBP` (channel) |
| `pszText` | stack `[EBP+0xC]` | Message body | `MOV EDX,[EBP+0xC]`; sole caller `PUSH EDI` (heap text) |
| cleanup | **`RET 0x8`** | stdcall, **2** stack dwords | Epilogue `008f6988` |
| return | void | No meaningful EAX use at RET | Early/late fall-through to epilogue |

Decompiler phantom: `param_1` is **not** dead — it is the style-format key into `FUN_008f6030` (HL drops the `MOV EAX,[EBP+8]`).

```c
// Working signature (custom register + stdcall)
void __stdcall ChatLog_FileAppendLine(
    /* EAX */ const char* pszPath,
    /* EBX */ const char* pszStyle,   // may be NULL or ""
    int nStyleKey,                    // sole caller: chat channel
    const char* pszText);             // message body (may be NULL or "")
```

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| `fopen(path, "at")`; on fail `fopen(path, "wt+")` | **Yes** — modes `0xa2c41c` / `0xa2c404` |
| Both open fail → silent return (no write) | **Yes** — `JZ 0x008f6983` |
| `FUN_007a69d0()` → ESI ctx for name helpers | **Yes** (product of helper open) |
| Zero timestamp buf (~`0x40` STOSD + STOSW + STOSB) | **Yes** |
| If style **or** text non-empty → `GetLocalTime` + month/dow name + `sprintf` timestamp | **Yes** |
| Zero body buf (same clear pattern) | **Yes** |
| If style non-empty → `FUN_008f6030(nStyleKey, pszStyle)` → `sprintf(body, returnedFormat)` | **Yes** (asm; HL under-shows args) |
| If text non-empty → strlen + memcpy (dword then byte tail) onto end of body | **Yes** |
| `fprintf(fp, "%s%s\n", timestamp, body); fclose` | **Yes** — format `0xa36bec` |
| Live force_decompile 2026-07-29 ≡ frozen raw body | **Yes** |

---

## 5. Sealed string / constant plate

| Literal / constant | VA | Bytes / value | Role in this fn |
|---|---|---|---|
| `"at"` | `0x00a2c41c` | `61 74 00` | primary open mode (append text) |
| `"wt+"` | `0x00a2c404` | `77 74 2b 00` | fallback create/truncate+readwrite |
| `"[%s %s %02d %02d:%02d:%02d %04d] "` | `0x00a36bf4` | ascii | timestamp sprintf (dow, mon, day, h, m, s, year) |
| `"%s%s\n"` | `0x00a36bec` | `25 73 25 73 0a 00` | fprintf line format |
| Month name table | `DAT_00af921c` | ptr[0]=`-1`, ptr[1..12]→`Jan`..`Dec` | index = `SYSTEMTIME.wMonth` |
| Day-of-week table | `PTR_DAT_00af9250` | ptr[0..6]→`Sun`..`Sat` | index = `wDayOfWeek` |
| Month name block | `0x00a36c40`.. | `Dec`…`Jan` contiguous | pointed by month table |
| DOW name block | `0x00a36c18`.. | `Sat`…`Sun` contiguous | pointed by DOW table |

**Caller-owned paths (not DATA xrefs of this body; sealed at sole call site):**

| Path | VA | When (caller) |
|---|---|---|
| `chat_log_combat.txt` | `0x00a36c70` | channel ∈ `[0x10, 0x18]` |
| `chat_log.txt` | `0x00a36c84` | else |

---

## 6. Line shape contract

When at least one of style/text is non-empty:

```text
[Sun Jan 05 14:30:09 2026] <style-formatted><message>\n
```

- Bracket timestamp always uses **local** time (`GetLocalTime`).
- `%s %s` order: **day-of-week first**, **month second** (matches sprintf arg push order).
- Body = style-format result (if style non-empty) **concat** message bytes (if non-empty). No extra separator invented in this unit (separator lives in `FUN_008f6030` format, if any).
- If **both** style and text empty: still opens/closes file and may write `"\n"` only (empty `%s%s` + newline) — edge case, no sole-caller path currently feeds both empty after parent gates.

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role: chat log file line writer | **Confirmed** | fopen/fprintf + sole caller chat append |
| EAX path + EBX style ABI | **Confirmed** | prologue + call site |
| Stack `(nStyleKey, pszText)` + `RET 0x8` | **Confirmed** | `[EBP+8]/[EBP+0xC]` + epilogue |
| Open `"at"` then `"wt+"` | **Confirmed** | `read_memory` modes |
| Timestamp format + tables | **Confirmed** | format + DOW/month string blocks |
| fprintf `"%s%s\n"` | **Confirmed** | `0xa36bec` |
| Message append is memcpy tail, not second sprintf | **Confirmed** | REP MOVSD/MOVSB after strlen |
| `nStyleKey` product = channel | **High** (caller) | sole caller pushes channel in EBP; OWN body only passes through to `FUN_008f6030` |
| `FUN_008f6030` product format | **Open** | OWN-only: not dualed here |
| `FUN_007a69d0` / `FUN_007a6de0` product | **Open** | ctx + string resolve with `-1` bound |
| Retail symbol name | **Tentative** | working `ChatLog_FileAppendLine` |

---

## 8. Gaps / open questions

1. Product English for `FUN_008f6030` (style format by channel/key).
2. Whether `nStyleKey` is ever non-channel at a future call site (today: **one** xref).
3. Exact max buffer capacities vs long messages (stack ~0x228; body clear ≈ 0x103 bytes class — overflow risk if message huge; not audited for clamp).
4. Runtime sample line in `chat_log.txt` / `chat_log_combat.txt`.
5. Whether `"wt+"` fallback truncates an existing unreadable path case (CRT semantics).

**Verdict:** File-append leaf **sealed** for ABI, modes, and line assembly. Prefer working name `ChatLog_FileAppendLine`. Do not merge with UI ring append (`0x008f8200`).
