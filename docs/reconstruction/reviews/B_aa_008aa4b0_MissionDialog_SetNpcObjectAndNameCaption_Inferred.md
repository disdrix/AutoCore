# Review B (skeptical / adversarial): `aa_008aa4b0` MissionDialog_SetNpcObjectAndNameCaption_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa4b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-058 OWN dual) |
| **Counterpart** | `reviews/A_aa_008aa4b0_MissionDialog_SetNpcObjectAndNameCaption_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Pure `__thiscall` with ECX = dialog | **Falsified** — entry uses **ESI** dialog / **EAX** npc; ECX loaded from `[ESI+0x6d8]` |
| 2 | Stack formals / `RET 4` | **Falsified** — plain **`C3`**; no stack pops |
| 3 | Only callee of ShowNpc | **Falsified** — also **`FUN_009373e0`** @ `0x00937411` (3 xrefs total) |
| 4 | Header caption helper (`+0x6e0`) | **Falsified** — widget bank is **`+0x6d8`**; header unit is dualed `008aaf60` |
| 5 | Writes chrome mode `+0x510` / turn-in `+0x64c` / opcode `+0x650` | **Falsified** — only **`+0x644`** store + widget vcalls |
| 6 | Same SetText arity both branches | **Falsified** — clear **3** args (`"",1,1`); bind **1** arg (name) |
| 7 | `CALL` refresh then return | **Falsified** — **`JMP [vtbl+0x34c]`** tail; decompiler "jumptable" is noise |
| 8 | `DAT_00a1419b` is a non-empty product string | **Falsified** — first byte **`00`** (shared empty C-string; sits after `"ode string"`) |
| 9 | Drive-axis park / thr/steer itself | **Falsified** — park is **parent** `FUN_009373e0` after this returns/jumps; this only stamps NPC + caption |
| 10 | Product PDB name sealed | **Fails** — `_Inferred` required |
| 11 | Runtime Confirmed | **Fails** — open (no Launcher; terminal false) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI dialog / EAX npc ABI | **Confirmed** | Wrong host or wrong NPC stamp |
| `+0x644` always written | **Confirmed** | Already-active compare / HandleButton NPC mismatch |
| `+0x6d8` null gate | **Confirmed** | Crash vs silent skip |
| Clear vs bind branch | **Confirmed** | Stuck NPC name text |
| SetText arity split | **Confirmed** | Stack smash if both ported as 3-arg or 1-arg |
| Tail JMP `+0x34c` | **Confirmed** | Extra RET / wrong stack if forced CALL |
| 3 call sites | **Confirmed** | Incomplete caller set |
| GetName secondary-vtbl walk | **High** (bytes) | Wrong name if object layout differs |
| Product English / vtbl names | **Open** | Docs only |
| Runtime | **Open** | No Confirmed |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean MissionDialog_SetNpcObjectAndNameCaption_Inferred.cpp

8B 8E D8 06 00 00     MOV ECX,[ESI+0x6d8]
85 C9                 TEST ECX,ECX
89 86 44 06 00 00     MOV [ESI+0x644],EAX
74 4E                 JZ ret
…
6A 01 6A 01 68 9B 41 A1 00   clear: push 1,1,&empty
FF 90 D8 01 00 00            CALL [EAX+0x1d8]
…
FF A2 4C 03 00 00            JMP [EDX+0x34c]
C3                           RET

Body 95 B; pad CC; next FUN_008aa510 @ 0x008aa510
```

Reject ports that:

- Treat ECX as dialog thiscall at entry.
- Name this as header caption (`+0x6e0`) or thr/steer park.
- Assume only ShowNpc calls it.
- Collapse SetText to a single arity.
- Invent stack args / `RET n`.
- Claim runtime Confirmed.

---

## 4. Surviving contract for AutoCore

```csharp
// Register contract (not stack thiscall):
//   ESI = MissionDialogHost*
//   EAX = NpcObject* or null
//
// MissionDialog_SetNpcObjectAndNameCaption_Inferred():
//   host.NpcObject = npc                    // +0x644
//   var w = host.NameCaptionWidget            // +0x6d8
//   if (w == null) return
//   if (npc == null)
//       w.SetText("", flags1:1, flags2:1)     // vtbl+0x1d8, 3 args
//   else
//       var name = npc.GetDisplayName(1, 1)   // secondary vtbl+0x160
//       w.SetText(name)                       // vtbl+0x1d8, 1 arg
//   w.Refresh()                               // tail JMP vtbl+0x34c
//
// Call before thr/steer/HB park (FUN_009373e0) and on ShowNpc present.
// Distinct from Client_MissionDialog_SetHeaderCaption_Inferred (+0x6e0).
```

---

## 5. Verdict

**accept-with-gaps** — adversarial attacks on thiscall/stack/header-merge/park-merge/single-arity/ShowNpc-only claims **falsified** against bytes + 3-site framing. Product English and runtime remain open; `_Inferred` name retained.
