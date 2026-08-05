# Dual A/B report — `aa_00925580` Client_SendItemPickup (opcode **0x2055**)

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x00925580`. Dual A/B + artifacts. Seal opcode **0x2055** / size **0x30**.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG.  
**Ghidra:** `decompile_function` + `read_memory` only.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00925580` Client_SendItemPickup | **accept-with-gaps** — **0x2055 / 0x30 sealed** |

---

## Sealed facts

1. **Opcode `0x2055`** (`GameOpcode.ItemPickup`) written as dword at packet base  
   (`mov imm 0x2055`; signature imm **8277**).

2. **Size `0x30`** (48 decimal) pushed to **`Client_SendSectorPacket(&DAT_00d1a840, 0x30, pkt)`**  
   with **`EAX = 8`** → Ordered reliability.

3. **Sector layout** (opcode included):

   | Off | Field |
   |----:|-------|
   | +0x00 | `0x2055` |
   | +0x04 | pad (unwritten) → server `UnknownField` |
   | +0x08 | TFID d0 ← `ESI[0]` |
   | +0x0c | TFID d1 ← `ESI[1]` |
   | +0x10..+0x17 | zero (Global/pad forced 0) |
   | +0x18..+0x27 | zero |
   | +0x28 | float **0.001** (`g_flMsToSeconds_Inferred` @ `0x00a0f72c`) |
   | +0x2c | unwritten trailer |

4. **ABI:** **ESI** = gather TFID pair (`uint32[2]*`); no stack params.  
   Valid when `(ESI[0] & ESI[1]) != 0xFFFFFFFF`.

5. **Gates (all must pass):** `DAT_00d1b4b0==0`, `char+0xcd0==0`,  
   `(char+0xcd8 & char+0xcdc)==-1`, ESI valid, char vtbl`+0x194==0`,  
   `DAT_00d1b958`/`DAT_00d1b95c` vtbl`+0x3d8==0`.

6. **Callers (exactly 3):**
   - `Client_Input_PollBoundActions` `0x0092794c` — Activate exclusive 20f gather (no UseObject)
   - `FUN_00925670` `0x00925707` — ~100 ms auto gather
   - `FUN_00925820` `0x00925be3` — interact hub; clears select `[0x1d6]`

7. **Not** UseObject `0x2072` / size `0x20`; **not** QuestItemPickup `0x205D`.

---

## Gaps

1. Product names for character `+0xcd0/+0xcd8/+0xcdc` and UI globals `DAT_00d1b958/95c`.  
2. Design intent of float **0.001** at `+0x28` (constant, not live time).  
3. Runtime wire capture.  
4. Server range policy (AutoCore 10u) vs client gather **20.0f** — out of unit.  
5. Scaffold clean still shows decompiler `unaff_ESI` — call-site sealed separately.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00925580_Client_SendItemPickup.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00925580_Client_SendItemPickup.md` |
| Function record | `docs/reconstruction/functions/aa_00925580_Client_SendItemPickup.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SendItemPickup.cpp` |
| Raw (authoritative + live) | `docs/reconstruction/raw/aa_00925580_FUN_00925580.md` |
| Annotated | `docs/reconstruction/raw/aa_00925580_FUN_00925580.annotated.md` |
| Scratch | `tmp/a_00925580.md` |
| This report | `docs/agents/task-dual-ab-00925580-item-pickup-report.md` |

Server mirrors (pre-existing):  
`src/AutoCore.Game/Packets/Sector/ItemPickupPacket.cs`,  
`src/AutoCore.Game/Constants/GameOpcode.cs` (`ItemPickup = 0x2055`),  
`TNLConnection.Sector.cs` → `HandleItemPickupPacket`.

Legacy scaffold names retained on disk:  
`reconstructed-exact/FUN_00925580.cpp`,  
`Named_CalleeOf_Client_Input_PollBoundActions_00925580.cpp`,  
`functions/aa_00925580_FUN_00925580.md` (superseded by `…_Client_SendItemPickup.md`).

---

## AutoCore impact

- C2S **`0x2055`** size **`0x30`** (opcode included): after strip, **pad4 + TFID16** is the meaningful head; trailing zeros/float may be ignored.  
- **`UnknownField`** is client-unwritten pad — do not require a specific value.  
- TFID **Global** arrives **0** (local world loot).  
- Activate key may send **only** ItemPickup (exclusive early path) — not always UseObject.
