# Dual A/B report — `aa_00941fb0` Client_SendChatOrMacro_Inferred (opcode **0x2021**)

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x00941fb0`. Dual A/B + artifacts. Seal opcode **0x2021**.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG.  
**Ghidra:** `decompile_function` + `read_memory` only.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00941fb0` Client_SendChatOrMacro_Inferred | **accept-with-gaps** — **0x2021 sealed** |

---

## Sealed facts

1. **Opcode `0x2021`** is written as a **C2S** dword at the sector packet base (`mov imm 0x2021`); sent with  
   **`Client_SendSectorPacket(client, msgLen + 0x29, &pkt)`** via **`client+0xc78`**.

2. **Sector layout** (opcode included):

   | Off | Field |
   |----:|-------|
   | +0x00 | `0x2021` |
   | +0x04 | ChatType (`param_4`) |
   | +0x08 | SenderCoid u64 (`char adj+0x164/168` or −1) |
   | +0x10 | IsGM = 0 |
   | +0x11 | pad (unwritten) |
   | +0x12 | MessageLength = `strlen` |
   | +0x14 | Sender[17] — **not written** |
   | +0x25 | Message + NUL |

3. **Companion global path** opcode **`0x8000`**, size **`msgLen + 0x31`**, via **`FUN_008073b0`** / **`client+0xc7c`**. Layout: ChatType, IsGM, recipient[17], sender[17], pad, length, message — matches `ChatPacket`.

4. **ABI:** `ECX=recipientName*`, `EDX=message*`, stack `client*, chatType, doFilters`; **`ret 0x0C`**.

5. **Type → path** (jump table `0x0094239c`):  
   - Global: 1,2,4,13,14,15  
   - Convoy (3): flag `*(meta+0xf6)` → global if 0 else sector  
   - Sector: 5,8,9,10 (+ rate stamp `client+0x30e8/0x30ec`)  
   - No-send: 6,7,11,12  

6. **Channel mask** `DAT_00af9218` bit-test; empty message → **`0x80070057`**.

7. **Not** combat power — quick-bar type-5 macro bank callee (prior residual).

---

## Gaps

1. Sector **Sender[17]** unfilled (server should force name from connection).  
2. `FUN_0093bd10` / `FUN_00865970` prefilter bodies.  
3. Size slack (`+0x29` / `+0x31` vs minimal header+NUL).  
4. Parent decompiles under-show args (use sealed ABI).  
5. Runtime wire capture.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00941fb0_Client_SendChatOrMacro_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00941fb0_Client_SendChatOrMacro_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00941fb0_Client_SendChatOrMacro_Inferred.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SendChatOrMacro_Inferred.cpp` |
| Raw (authoritative body) | `docs/reconstruction/raw/aa_00941fb0_FUN_00941fb0.md` |
| Annotated + residual | `docs/reconstruction/raw/aa_00941fb0_FUN_00941fb0.annotated.md` |
| Scratch | `tmp/a_00941fb0.md` |
| This report | `docs/agents/task-dual-ab-00941fb0-send-chat-macro-report.md` |

Server mirrors (pre-existing):  
`src/AutoCore.Game/Packets/Sector/BroadcastPacket.cs`,  
`src/AutoCore.Game/Packets/Global/ChatPacket.cs`,  
`src/AutoCore.Game/Constants/ChatType.cs`,  
`GameOpcode.Broadcast = 0x2021`, `GameOpcode.Chat = 0x8000`.

---

## AutoCore impact

- C2S sector chat must accept **`0x2021`** with variable size **`4 + body`** where client size = **`msgLen + 0x29`** (opcode included).  
- Do **not** require client-filled Sender on C2S; prefer connection character name.  
- Global public/PM/clan/faction(/FR/DE labels) may arrive on **`0x8000`**, not only `0x2021`.  
- Chat-macro quick-bar (type 5) is a **caller** of this unit, not a separate combat opcode.
