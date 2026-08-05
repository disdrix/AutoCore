# Review B (skeptical / adversarial): `ChatLog_FileAppendLine` @ `0x008f6800`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008f6800` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008f6800_ChatLog_FileAppendLine.md` |
| **Verdict** | **accept-with-gaps** on file-sink role + ABI; helper English / buffer bounds open |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `void FUN_008f6800(param_1, param_2)` with only two stack strings | **Falsified shape** — `param_1` is int key (channel at sole site); path/style are **EAX/EBX**, not stack |
| 2 | `param_1` is unused / phantom | **Falsified** — `MOV EAX,[EBP+8]` before `FUN_008f6030`; HL drops it |
| 3 | `in_EAX` / `unaff_EBX` are decompiler noise | **Falsified** — real custom ABI; sole caller sets both |
| 4 | This function chooses `chat_log.txt` vs combat path | **Falsified for OWN body** — path is caller-supplied in EAX; choice lives in `0x008f8200` |
| 5 | Body is pure `sprintf` of message | **Falsified** — style via `FUN_008f6030`+`sprintf`; message is **memcpy** onto buffer tail |
| 6 | Multiple call sites / shared utility | **Falsified count** — Ghidra xrefs: **one** call (`008f82ec`) |
| 7 | `thiscall` / CDlgChatLog member | **Falsified** — no ECX use; freestanding with register path |
| 8 | `"at"` always succeeds so `"wt+"` is dead | **Attack fails** — sequential fallback is live CF; `"wt+"` on first fail |
| 9 | Timestamp always written | **Falsified** — only if style **or** text non-empty; both empty → empty prefix |
| 10 | Scaffold alias “callee of RecvBroadcast only” | **Partial** — sole direct caller is AppendChannelMessage; RecvBroadcast is **indirect** parent only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| File open `"at"` / `"wt+"` | **Confirmed** | Wrong create vs append behavior |
| fprintf `"%s%s\n"` | **Confirmed** | Wrong line terminator/join |
| Timestamp format string | **Confirmed** | Wrong log parse tools |
| Month/DOW table indices | **Confirmed** | Off-by-one month (table[0]=-1) |
| EAX path + EBX style | **Confirmed** | Silent mis-wire of AutoCore port |
| `RET 0x8` stack arity | **Confirmed** | Stack smash if cdecl assumed |
| `nStyleKey` always channel | **High** sole site / **not universal** | Future second caller could pass other key |
| Style format product (`FUN_008f6030`) | **Tentative** | Wrong body prefix in port |
| Buffer capacity safe for all chat lengths | **Open** | Truncation/overflow unknown |
| Working name `ChatLog_FileAppendLine` | **High role / Tentative product** | Rename when PDB/strings appear |

---

## 3. Surviving contract for AutoCore

```c
// Custom + __stdcall (RET 8). Not a CDlgChatLog method.
void ChatLog_FileAppendLine(
    const char* pszPath,   // EAX
    const char* pszStyle,  // EBX; NULL or "" skips style branch
    int nStyleKey,         // stack0 — channel from sole caller
    const char* pszText)   // stack1 — message body
{
  FILE* fp = fopen(pszPath, "at");
  if (!fp) fp = fopen(pszPath, "wt+");
  if (!fp) return;

  void* nameCtx = FUN_007a69d0();  // ESI; product open

  char ts[/* ~0x103 zeroed */] = {0};
  char body[/* ~0x103 zeroed */] = {0};

  if ((pszStyle && *pszStyle) || (pszText && *pszText)) {
    SYSTEMTIME st;
    GetLocalTime(&st);
    const char* mon = resolve_cstr(nameCtx, g_monthNames[st.wMonth], -1); // DAT_00af921c
    const char* dow = resolve_cstr(nameCtx, g_dowNames[st.wDayOfWeek], -1); // DAT_00af9250
    sprintf(ts, "[%s %s %02d %02d:%02d:%02d %04d] ",
            dow, mon, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wYear);
  }

  if (pszStyle && *pszStyle) {
    const char* fmt = FUN_008f6030(/*EAX*/ nStyleKey, /*stack*/ pszStyle);
    sprintf(body, fmt);  // format produced by helper (may bake style)
  }
  if (pszText && *pszText) {
    // append pszText at end of body (strlen body + memcpy)
  }

  fprintf(fp, "%s%s\n", ts, body);
  fclose(fp);
}
```

**Sole call pattern (parent `0x008f8200` — for orientation only):**

```text
EAX = (channel in [0x10,0x18]) ? "chat_log_combat.txt" : "chat_log.txt"
EBX = styleBuf  // GM-prefix + style snprintf result
PUSH messageHeap
PUSH channel
CALL ChatLog_FileAppendLine
```

---

## 4. Decompiler hazards (must not trust bare HL)

| Hazard | Fix |
|---|---|
| Signature `void(undefined4,char*)` without registers | Recover **EAX path**, **EBX style**, stack key+text, **`RET 0x8`** |
| `param_1` appears unused | Asm loads `[EBP+8]` into EAX for `FUN_008f6030` |
| `FUN_008f6030()` zero-arg display | `EAX=nStyleKey`, stack `pszStyle` |
| `sprintf(&local_218, pcVar6)` looks format-only | Return value **is** format; style already consumed by helper |
| `local_228.wMilliseconds+1` body end pointer | Decompiler stack alias noise for **end of body buffer** |
| Path strings not referenced in this function’s DATA xrefs | Owned by caller; do not claim path selection here |
| `FUN_007a69d0` / `FUN_007a6de0` as pure no-ops | Real name resolution; do not strip in a bit-exact port |

---

## 5. Open questions

1. Exact `FUN_008f6030` format table vs channel (OWN dual deferred).
2. `FUN_007a69d0` identity (TLS / string pool / locale?).
3. Message longer than body buffer — CRT overflow vs silent truncate (no length clamp in this body).
4. Retail name (no direct path string inside this VA).
5. Multi-thread safety of fopen/fprintf pair (none).

**Verdict:** Treat as **shared file-append leaf** for chat logs. Port with custom EAX/EBX + stdcall-2. Keep path selection and UI ring logic in `CDlgChatLog_AppendChannelMessage`. Accept with gaps on style-helper English and buffer limits.
