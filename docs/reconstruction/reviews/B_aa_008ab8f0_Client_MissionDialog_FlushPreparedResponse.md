# Review B (skeptical / adversarial): `Client_MissionDialog_FlushPreparedResponse` @ `0x008ab8f0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ab8f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (UF-011 residual seal — cancel-close +0x650) |
| **Counterpart** | `reviews/A_aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md` |
| **Verdict** | **accept-with-gaps** on rename + send site + invoker; **UF-011 sealed as real cancel risk** (not cancel-safe); do not overclaim exclusive emitter |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is *the* only C2S 0x206E send in the client | Other code could build a stack packet and send via `Client_SendSectorPacket` / another vtbl+0x18 path without embedding literal 0x206E | **Weakened but not fatal** — Prepare is the only **code** site writing imm `0x206E`. This function is the only proven consumer of dialog+0x650 at size 0x20. |
| 2 | Name “FlushPreparedResponse” is complete | Body also tears down widgets (`FUN_008aa320`), dialog `vtbl+0x3ac`, `FUN_00792490` | **Partial hit.** Name prioritizes wire-critical half; multi-duty close+flush. Accept with docs note. |
| 3 | HandleButton “never” sends 0x206E | True in body; state 0 sends **0x206F** size 0x18 | **Survives** for 0x206E specifically. |
| 4 | Always flushes after Accept | Prior gap: Hide does not call this. **Updated:** `FUN_008aec40` / `FUN_008af020` call `FUN_007fca10` when HandleButton returns non-zero; `FUN_007fca10` calls `vtbl+0x440` = this. | **Material gap closed (static).** Still not a live trace. |
| 5 | HideMissionDialogIfOpen is related | Hide targets `client+0x107c`; dialog lives at **`+0x1058`**. Class `+0x448` is empty stub `FUN_0056f570`. | **Hide is a red herring for Flush** — confirmed. |
| 6 | `g_pSectorNetConnection` is proven | Global inferred (`DAT_00d1b4b8`) | **Name weak, mechanism strong.** |
| 7 | Buffer layout always missionId + bool + TFID | Turn-in overloads `+0x658` with reward COIDs | **Layout tension** remains. |
| 8 | Close never sends garbage | Close id `0x9c40` → `FUN_007fca10` **without** HandleButton fill; Prepare already set 0x206E | **Falsified / UF-011 sealed** — close **can** flush unfilled 0x206E; no clear of `+0x650` on cancel path or in Flush body. |
| 9 | State 0 only sends 0x206F | Returns 1 → dispatcher still `FUN_007fca10` → Flush may emit 0x206E too | **Survives as residual risk** (static dual-packet; not UF-011). |

---

## 2. What the evidence actually proves

| Fact | Strength |
|---|---|
| Function at `0x008ab8f0` sends `0x20` bytes from `this+0x650` when dword nonzero | **Proven** (live decompile ≡ raw) |
| Vtable entry at `0x00a4a95c` points here | **Proven** (memory + DATA xref) |
| Vtable base `0x00a4a51c` installed by ctor `FUN_008ac3f0` | **Proven** |
| Method offset is **`vtbl+0x440`** | **Proven** (base+offset math) |
| Host object at client `+0x1058`, dialog index 10 | **Proven** (UI init + Show) |
| `FUN_007fca10` calls `*obj+0x440` when visible | **Proven** (decompile) |
| `FUN_008aec40` calls `FUN_007fca10` after successful HandleButton / close btn | **Proven** (decompile) |
| BuildWidgets zeroes opcode slot on construct | **Proven** |
| Prepare writes 0x206E into that slot | **Proven** |
| HandleButton fills body without 0x206E send | **Proven** |

| Fact | Strength |
|---|---|
| Every successful accept reaches Flush at runtime | **High static / runtime open** |
| Flush never double-sends | **Falsified for clear-gate** — Flush body has **no** post-send zero of `+0x650` (decompile + image). Double-send still needs a second close while buffer lives. |
| Cancel never sends 0x206E | **Falsified statically** — close `0x9c40` → same invoker; Prepare-on-show leaves opcode nonzero |
| No other 0x206E emitters exist | **Medium** |
| Cancel-close clears `+0x650` before flush (UF-011) | **Falsified** — no write on close path; BuildWidgets zero is construct-only |

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dialog method that can emit prepared packet | High | Miss real send site |
| Size 0x20 matches MissionDialogResponsePacket | High | Wrong packet family |
| Virtual dispatch via `+0x440` | High | Wrong caller search |
| Invoker = `FUN_007fca10` from dialog event dispatch | **High (static)** | Accept path never hits server |
| `client+0x1058` is this dialog | High | Wrong object |
| Global DAT_00d1b4b8 identity | Medium | Wrong channel |
| Cancel-safe | **None (static)** — UF-011 **sealed High**: not cancel-safe | Spurious/unfilled C2S 0x206E on close is **expected client behavior** |
| State0 exclusive 0x206F | Medium-Low | Extra 0x206E on accept-request |

---

## 4. Surviving contract for AutoCore

```
NPC mission dialog @ client+0x1058
  vtable base 0x00a4a51c
  method +0x440 = Client_MissionDialog_FlushPreparedResponse @ 0x008ab8f0

Invoker (static):
  FUN_008aec40 / FUN_008af020
    → FUN_007fca10 (if visible)
      → vtbl+0x440:
          if (*(dialog+0x650) != 0 && g_sectorConn != null)
            sector_send(buf=dialog+0x650, size=0x20, flags=0);
          // then UI teardown

Opcode 0x206E stamped by Prepare @ show (+0x650).
Body filled by HandleButton state 1 only.
Close button (0x9c40) can flush without fill.

Server: treat C2S 0x206E as missionId + accepted region + TFID16 giver.
Do NOT require Client_SendSectorPacket inside HandleButton for 0x206E.
Do NOT equate HideMissionDialogIfOpen (+0x107c) with this flush.
```

---

## 5. Open questions (must not be papered over)

1. ~~Which path `CALL`s vtable slot for Flush?~~ **Answered static:** `FUN_007fca10` → `+0x440`.
2. ~~After send, is `+0x650` cleared?~~ **Answered (UF-011 sealed):** **No** in Flush body; **no** on cancel-close path either. Zero only at BuildWidgets construct (`param_1[0x194..0x19b]=0`).
3. ~~Does pure cancel still send 0x206E?~~ **Answered static:** **Yes it can** — `case 40000` → `FUN_007fca10` → Flush with Prepare-stamped opcode and **unfilled** body (HandleButton never ran). Gate is nonzero opcode only.
4. Turn-in: does server ignore Accepted and only use missionId + TFID?
5. State 0: does live client emit both 0x206F and 0x206E?
6. Runtime: does live cancel actually hit wire (conn non-null + dialog visible)? Static path exists; live capture still open for product.

### 5.1 UF-011 adversarial residual — **sealed**

Attack “maybe close clears the buffer first” fails:

- Flush: send then teardown — **no** `dialog[0x194]=0` after `CALL [EDX+0x18]`.
- Close dispatch: **no** intermediate clear before `vtbl+0x440`.
- Prepare stamps `0x206E` at show **unconditionally** — cancel does not un-prepare.

Do **not** document client as “cancel-safe for 0x206E.” Server should tolerate cancel/unfilled body or AutoCore must not assume only filled accepts reach the wire.

---

## 6. Verdict

**accept-with-gaps.**

Adversarial position after UF-011 residual: **cancel-clear is closed** — answer is **no clear**, and **close can flush unfilled 0x206E**. UF-010 invoker remains statically proven. Do **not** upgrade to clean **accept** while runtime capture / state0 dual-packet remain open. Rename still warranted for the wire-critical half.
