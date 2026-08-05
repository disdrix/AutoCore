# Review B (skeptical / adversarial): `aa_008a2020` Client_IsLocalMissionJournalReady

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a2020` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008a2020_Client_IsLocalMissionJournalReady.md` |
| **Agent** | W21-F OWN-ONLY |
| **Verdict** | **accept** on sealed gates; **needs-more-evidence** only on product names / global identity |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function is `__thiscall` with character this | Image loads ECX from global; no `mov ecx, this` of a formal this | **Falsified** — **cdecl** wrapper |
| 2 | Returns full EAX / uint semantics matter | Caller only `test al`; null path `xor al,al` | **Falsified** as wide-uint contract — **bool AL** |
| 3 | Null path returns garbage / preserves EAX | Image `32 C0` clears AL before ret | **Falsified** — returns **0** |
| 4 | Reimplements last-obj / hash / mode-0 | Body is 2 branches + one call | **Falsified** — pure forward to `0052b3b0` |
| 5 | Same as turn-in ready | Callee dual is journal mode-0, not `0052b420` | **Falsified** |
| 6 | Multiple callers | `get_xrefs_to` → only `008a384b` | **Falsified** as multi-caller — **1** site |
| 7 | Caller is stdcall (callee cleans) | Site `add esp,4` after call | **Falsified** — **cdecl** |
| 8 | Can call `0052b3b0` with null this | Null check **before** call | **Falsified** — null-safe |
| 9 | Clean invents ECX setup not in decompile | Image bytes show mov/test/push/call; decompiler omitted this | **Falsified as invention** — image-backed |
| 10 | `"  [Complete]"` string lives in this VA | String in `FUN_008a3510` only | **Survives refined** — wrapper supplies bool only |
| 11 | Dead / unused | Live call from detail panel | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl + 1 arg + bool AL | **High** | Wrong calling convention in port |
| Null global → false | **High** | Crash on empty local char |
| Forward only to journal ready | **High** | Wrong mode/NPC gate |
| Sole UI consumer | **High** | Missed alternate call sites |
| Product name of wrapper | **Tentative** | Docs only |
| `DAT_00d1b6d8` identity | **Probable** (local char) | Wrong actor evaluated |

---

## 3. Cross-check against raw / image

### 3.1 Spine (authoritative)

```
if g_localChar(DAT_00d1b6d8) == 0: return 0
return IsMissionJournalReady(g_localChar, mission)  // 0052b3b0
```

### 3.2 Image seals (`read_memory` @ `0x008a2020`)

| Fact | Bytes / pattern |
|---|---|
| Load global | `8B 0D D8 B6 D1 00` |
| Null → 0 | `85 C9 75 03 32 C0 C3` |
| Push stack arg | `8B 44 24 04 50` |
| Call journal ready | `E8 …` → `0x0052b3b0` |
| Near ret | `C3` (not `C2 xx 00`) |

### 3.3 Call-site seals (`0x008a384b`)

| Fact | Pattern |
|---|---|
| cdecl cleanup | `83 C4 04` |
| Bool test | `84 C0` / `jz` skip Complete chrome |
| Mode gate around call | decompile: `param_1+0x50c == 0` |

Clean preserves spine. **No deleted branches. No invented NPC/mode logic.**

---

## 4. Surviving contract for AutoCore

```
// Client UI: local-character journal-ready probe (NOT turn-in)
bool IsLocalMissionJournalReady(MissionDef* mission):
  if LocalCharacter == null: return false
  return IsMissionJournalReady(LocalCharacter, mission)  // mode 0, no NPC

// Do NOT implement objective hash here.
// Do NOT call IsMissionTurnInReady (0x0052b420) from this site.
// UI: true → detail panel may show "_done" / "  [Complete]" when mode==0.
```

---

## 5. Open questions

1. Retail symbol for `0x008a2020`.
2. Product English for `FUN_008a3510`.
3. Runtime capture of `DAT_00d1b6d8` across UI contexts.
4. Bit-diff vs retail EXE.

**Verdict:** Adversarial review **accepts** cdecl wrapper, null-safe forward, and journal-ready callee. Residual gaps are naming/runtime only — not CF.
