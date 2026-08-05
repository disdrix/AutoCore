# Review B (skeptical / adversarial): `CDlgChatLog_AppendChannelMessage` @ `0x008f8200`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008f8200` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008f8200_CDlgChatLog_AppendChannelMessage.md` |
| **Verdict** | **accept-with-gaps** on sink role + channel math; product names / full channel enum open |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is part of RequestCast skill logic / C2S `0x2030` | **Falsified** — no packet, no skill object; pure UI/log |
| 2 | `param_3` is the message body | **Falsified** — body is `param_4`; `param_3` is style/name used for ignore match, file prefix, and channel-2 stash |
| 3 | `DAT_00a156cc` is always `"!"` message text | **Partial** — bytes are `"!"`, but it is the **style** arg; message is separate fail string |
| 4 | Decompiler shows full file-log setup | **Falsified** — decomp drops `MOV EAX, chat_log*.txt` and `LEA EBX, local_18` before `FUN_008f6800` |
| 5 | `FUN_00573af0(param_3)` is a free function of style alone | **Falsified** — `__thiscall` with `ECX = DAT_00d1da2c` |
| 6 | Host is always `DAT_00d1b8dc` | **Falsified** — RecvBroadcast passes RTDynamicCast result of `client+0x109c`; other sites pass globals or cast host |
| 7 | Channels `0x10`–`0x18` are "combat" product name | **Attack holds as naming** — only **CF split** sealed (file + pane index); product labels open |
| 8 | `local_18` is dead (unused after snprintf) | **Falsified** — becomes **EBX** file-log style prefix into `FUN_008f6800` |
| 9 | Early return when ignore hits leaks heap | **Falsified** — ignore runs **before** `operator_new[]` |
| 10 | Scaffold alias “callee of RecvBroadcast only” | **Falsified** — 60+ callers including RequestCast, CastBlockFeedback, inventory loot, missions |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Channel clamp 0..0x18 | **Confirmed** | Wrong toast channel clamp |
| Enable bitmask `DAT_00af9218` | **Confirmed** | Silent drop if options clear bits |
| Dual pane index from channel ≥ 0x10 | **Confirmed** | Messages go to wrong log tab |
| File names combat vs normal | **Confirmed** | Wrong disk log |
| GM prefix string | **Confirmed** | Wrong visual prefix when flag set |
| Empty non-GM prefix | **Confirmed** | — |
| Ignore-list suppress polarity (hit ⇒ drop) | **Confirmed CF** | Wrong if product is allow-list (body is find-by-name return entry or 0) |
| RequestCast toast channel `0x18` | **Confirmed** | Wrong UI surface |
| Working product name `CDlgChatLog_*` | **High** from RTTI host | Rename may refine |
| Ring field product names | **Tentative** | Layout open |

---

## 3. Surviving contract for AutoCore

```
void CDlgChatLog_AppendChannelMessage(
    CDlgChatLog* pHost,   // often DAT_00d1b8dc or cast of client+0x109c
    int nChannel,         // clamped to [0, 0x18]
    const char* pszStyle, // e.g. "!" / speaker name / empty-ish style
    const char* pszText,  // body
    char bGmPrefix)       // 0 → ""; nonzero → "(GM)"
{
  if (nChannel < 0 || nChannel > 0x18) nChannel = 0;
  if ((g_channelEnableMask_00af9218 & (1u << nChannel)) == 0) return;

  char styleBuf[20];
  const char* prefix = bGmPrefix ? "(GM)" : "";  // 0x00a36c9c / 0x00a1419b
  _snprintf(styleBuf, 0x14, "%s%s", prefix, pszStyle);

  // ignore list on STYLE, not body
  if (IgnoreList_Find(g_pIgnore_00d1da2c, pszStyle) != 0) return;

  char* heapText = strdup_heap(pszText);
  if (g_profanityCtx && g_profanityOn) ProfanityFilter(g_profanityCtx, heapText);

  // optional file append (flag pair in DAT_00d1775c) →
  //   fopen(channel in [0x10,0x18] ? "chat_log_combat.txt" : "chat_log.txt")
  //   line uses styleBuf + heapText (register convention into FUN_008f6800)

  int pane = (nChannel >= 0x10 && nChannel <= 0x18) ? 1 : 0;
  ChatPane* p = *(ChatPane**)((char*)pHost + 0x540 + pane * 4);
  if (p) {
    // ring 150 (0x96): store styleBuf+heapText slot; maybe rebuild UI
  }

  if (nChannel == 2 && g_obj_00d1b978)
    strcpy((char*)g_obj_00d1b978 + 0x924, pszStyle);

  free(heapText);
}
```

**RequestCast / cast-fail toast pattern (do not invent other channels for this UX):**

| Arg | Value |
|---|---|
| host | `DAT_00d1b8dc` (null-checked by caller) |
| channel | **`0x18`** |
| style | **`&DAT_00a156cc` → `"!"`** |
| text | `Skill_FormatFailureMessage(...)` result |
| gm | **`0`** |

---

## 4. Decompiler hazards (must not trust bare HL)

| Hazard | Fix |
|---|---|
| Missing `EAX` filename before `FUN_008f6800` | Asm: `0xa36c84` / `0xa36c70` |
| Missing `EBX = local_18` into file logger | Asm at `0x008f82e7` |
| `FUN_00573af0` appears 1-arg | Asm: `ECX = DAT_00d1da2c` |
| `local_18` looks dead | Consumed as file style prefix |
| Index expressions `piVar1[0x147]` etc. | Prefer byte offsets: `+0x51c`, `+0x518`, `+0x50c`, `+0x500`, `+0x508` |

---

## 5. Open questions

1. Full channel id → product name table (say, loot `0x17`, toast `0x18`, system `6`).
2. Ignore-list object type / settings UI that fills `DAT_00d1da2c`.
3. Whether `FUN_00573af0` is block-list only (survives as find-hit ⇒ drop).
4. Pane object product + XML (`i_d_chatlog_2d_wnd_chat.xml` appears in `FUN_008f7cf0`, not this body).
5. Runtime cast-fail line shape in UI vs `chat_log_combat.txt`.

**Verdict:** Treat as **shared chat append sink**. RequestCast only **uses** it for failure toasts on channel `0x18`. Do not merge with skill validate/send. Asm required for file-log and ignore-list this-pointer.
