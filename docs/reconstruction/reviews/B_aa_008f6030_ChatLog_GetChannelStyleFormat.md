# Review B (skeptical / adversarial): `ChatLog_GetChannelStyleFormat` / `FUN_008f6030` @ `0x008f6030`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008f6030` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008f6030_ChatLog_GetChannelStyleFormat.md` |
| **Verdict** | **accept** — reject stack-arg / void-return / “writes chat” overclaims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Takes channel on stack / ECX | **Falsified** — key in **EAX**; jump table on `eax-1` |
| 2 | Writes log files / UI | **Falsified** — returns pointer only; leaf |
| 3 | Decompiler `void FUN_008f6030(void)` means no inputs | **Falsified as ABI** — EAX is the formal (parent dual sealed) |
| 4 | Return type void | **Falsified** — `mov eax, string; ret` |
| 5 | Case 0x18 is combat-only exclusive format | **Overstated** — shares `"%s: "` with 6 and 10 |
| 6 | All channels 0x10–0x17 have unique labels | **Falsified** — most default to `"%s"` |
| 7 | Exclusive to file append | **Falsified** — also `FUN_008f7cf0` |
| 8 | Product enum names sealed | **Open** — English strings High, symbols open |
| 9 | Runtime verified | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX key formal | **Confirmed** | Wrong register → garbage format |
| Format map 1–0xF / 0x18 | **Confirmed** | Wrong log prefixes |
| Default `"%s"` | **Confirmed** | Silent wrong style |
| Leaf purity | **Confirmed** | Low |
| Role = style format lookup | **High** | Mis-wire as message body |
| Product name | **Open** | Docs |

---

## 3. Surviving contract for AutoCore

```
// key in EAX (not stack)
const char* ChatLog_GetChannelStyleFormat(unsigned channelKey):
  return kChannelFormats[channelKey] or "%s"

// Consumer pattern (file log):
//   fmt = GetChannelStyleFormat(channel)
//   sprintf(body, fmt, styleOrSpeaker)
//   append message text
//
// NOT fopen/fprintf. NOT ring-buffer UI.
```

---

## 4. Falsification notes

### 4.1 Decompiler void trap

Ghidra classification may say `void` / no params because there is no stack formal. Ports must still accept **EAX**. Parent `ChatLog_FileAppendLine` dual documents the call site.

### 4.2 Channel 0x18 / RequestCast fail

`CDlgChatLog_AppendChannelMessage` uses channel **0x18** for cast-fail feedback. This helper maps 0x18 → `"%s: "` (same as 6/10), not a special “error” string — error text is the **message body**, not the format.

### 4.3 Scaffold “tells the convoy” name

Record alias `Named_tells_convoy` is **one case string**, not the whole function.

---

## 5. Open questions

1. Retail name / enum.
2. Why 0x10–0x17 mostly unlabelled here while UI dual-panes them (likely style elsewhere).
3. Bit-exact string VAs across builds — open.

**Verdict:** **accept**. Sealed map + EAX ABI. Reject I/O identity, void-no-input, and convoy-only naming.
