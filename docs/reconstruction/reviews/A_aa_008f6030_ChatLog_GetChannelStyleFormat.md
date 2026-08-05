# Review A (reconstruction fidelity): `aa_008f6030` ChatLog_GetChannelStyleFormat

| Field | Value |
|---|---|
| **Stable ID** | `aa_008f6030` |
| **VA** | `0x008f6030` |
| **Canonical name** | `ChatLog_GetChannelStyleFormat` (structural; product/PDB open) |
| **Ghidra name** | `FUN_008f6030` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_008f6030_ChatLog_GetChannelStyleFormat.md` |
| **System** | chat UI / file logging |
| **Verdict** | **accept** on CF / channel→format map / EAX formal; product name **open** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Leaf lookup**: map a **chat channel / style key** (in **EAX**) to a **printf format C-string** used when building log/UI style prefixes (e.g. `"%s tells you: "`, `"[1. General] %s: "`).

No I/O, no heap, no globals. Sole static callers:

- `ChatLog_FileAppendLine` @ `0x008f6800` — after channel pushed as style key; `sprintf(body, format, …)` with speaker style.
- `FUN_008f7cf0` @ `0x008f7cf0` — chat UI rebuild path (sibling of `CDlgChatLog_AppendChannelMessage`).

Parent dual `A_aa_008f6800_ChatLog_FileAppendLine` already notes: decompiler may show `void` formals; asm feeds **EAX = channel**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record / raw / annotated / clean | `aa_008f6030_*`, `FUN_008f6030.cpp` |
| Live decompile | Ghidra `batch_decompile` + `analyze_function_complete` (2026-07-29) |
| Live body bytes | `read_memory` `0x008f6030` length 128 — jump-table switch |
| Callers / xrefs | `008f6909` (`008f6800`), `008f7e1f` (`008f7cf0`) |
| Parent duals | `A_aa_008f6800_ChatLog_FileAppendLine.md`, `A_aa_008f8200_CDlgChatLog_AppendChannelMessage.md` |

**Not performed:** Launcher, runtime chat capture, bit-exact, dual of `008f7cf0`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Formal: channel key in **EAX** | **Confirmed** | `sub eax,1` + table; parent dual `MOV EAX,[EBP+8]` before call |
| Return: `const char*` format in **EAX** | **Confirmed** | `mov eax, imm32; ret` per case |
| Leaf: no callees | **Confirmed** | `analyze_function_complete` callees empty |
| Switch range after `eax−1` vs `0x17` | **Confirmed** | bytes `83 c0 ff; 83 f8 17; ja default` |
| Channel map strings (below) | **Confirmed** | decompile + string content |
| Cases 6 / 10 / 0x18 share `"%s: "` | **Confirmed** | fall-through in decompile |
| Default `"%s"` | **Confirmed** | out-of-range / 0 / unlisted |
| Product symbol | **Open** | structural |
| Clean ≡ raw ≡ live CF | **Confirmed** | |

---

## 4. Channel → format map (sealed)

| Key (EAX) | Format string |
|---|---|
| 1 | `"%s broadcasts: "` |
| 2 | `"%s tells you: "` |
| 3 | `"%s tells the convoy: "` |
| 4 | `"%s tells the clan: "` |
| 5 | `"[1. General] %s: "` |
| 6, 10, 0x18 | `"%s: "` |
| 7 | `"You told %s: "` |
| 8 | `"[5. Looking For Convoy] %s: "` |
| 9 | `"[4. Trade] %s: "` |
| 0xB | `"%s tells the new users clan: "` |
| 0xC | `"%s says "` |
| 0xD | `"[6. Faction] %s: "` |
| 0xE | `"[2. French] %s: "` |
| 0xF | `"[3. German] %s: "` |
| default (0, 0x10–0x17 except listed, >0x18, etc.) | `"%s"` |

Note: parent chat log clamps channels to `0…0x18` before use; keys **0x10–0x17** (combat dual-pane band per `008f8200`) mostly fall to **default** `"%s"` unless equal to a listed case (none in that band except via 0x18 which is listed as `"%s: "`).

---

## 5. Control flow / recovered CF

```c
// custom: key in EAX; returns const char*
const char *ChatLog_GetChannelStyleFormat(unsigned key /*EAX*/)
{
    switch (key) {
    case 1:  return "%s broadcasts: ";
    case 2:  return "%s tells you: ";
    case 3:  return "%s tells the convoy: ";
    case 4:  return "%s tells the clan: ";
    case 5:  return "[1. General] %s: ";
    case 6: case 10: case 0x18: return "%s: ";
    case 7:  return "You told %s: ";
    case 8:  return "[5. Looking For Convoy] %s: ";
    case 9:  return "[4. Trade] %s: ";
    case 0xB: return "%s tells the new users clan: ";
    case 0xC: return "%s says ";
    case 0xD: return "[6. Faction] %s: ";
    case 0xE: return "[2. French] %s: ";
    case 0xF: return "[3. German] %s: ";
    default: return "%s";
    }
}
```

### Assembly sketch (`read_memory`)

```
008f6030  83c0ff          add  eax, -1          ; key-1
008f6033  83f817          cmp  eax, 0x17
008f6036  775b            ja   default
008f6038  ff24859c608f00  jmp  dword ptr [eax*4 + 0x008f609c]  ; jump table
; case bodies: mov eax, &string; ret
```

---

## 6. Gaps

1. Product / PDB name.
2. Full product enum for every channel id (labels High from strings; numeric product doc open).
3. Whether UI path `008f7cf0` passes the same key domain as file log — residual of caller.

**Verdict:** **accept** — sealed leaf switch, EAX formal, format map, and chat-style-format role.
