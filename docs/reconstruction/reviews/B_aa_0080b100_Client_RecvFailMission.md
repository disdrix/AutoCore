# Review B (skeptical / adversarial): `aa_0080b100` Client_RecvFailMission

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080b100` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual re-seal — UF-012 framing + full body image) |
| **Counterpart** | `reviews/A_aa_0080b100_Client_RecvFailMission.md` |
| **Chain** | `reviews/CHAIN_2026-07-29_abandon_failmission.md` |
| **Scratch** | `tmp/a_0080b100.md` |
| **Verdict** | **accept-with-gaps** on handler identity; opcode + full framing **sealed High**; secondary cleanup still **needs-more-evidence** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Name `Client_RecvFailMission` is retail symbol | No string/export; **inferred** from opcode + callee | **Inference OK, not symbol-proof** |
| 2 | Handler also owns C2S abandon | C2S is `FUN_00911840` case `0x4e46`; this is recv-only | **Falsified if overclaimed** |
| 3 | Always fails the mission id in the packet | Outer gate requires `game+0xe98`; FailMission itself requires active live node | **Conditional** (kernel may return 0) |
| 4 | `in_EAX+0x10` is definitely missionId | Image: `MOV EDX,[EAX+0x10]; PUSH EDX` before FailMission | **Sealed High (asm)** |
| 5 | FailMission `this` is character | Image: `MOV ECX,[EDI+0xe98]` then CALL `0x0052da30` | **Sealed High** |
| 6 | FailMission success is required for end-quest | Body **never tests AL** after FailMission; always calls `FUN_005307e0` | **Sealed: return ignored** |
| 7 | Secondary path still uses packet | `MOV EAX,[EDI+0xe98]` @ `0x0080b121` clobbers packet base | **Sealed: packet dead after FailMission** |
| 8 | `FUN_005307e0` is only fail teardown | Body is large end-quest walker + "Failed" toast; role holds, name may be broader | **Probable** (thiscall on char **sealed**) |
| 9 | Secondary `+0x548` lookup is required for fail correctness | Optional; miss → `FUN_0092fd00` only | **Overstated if required** |
| 10 | Same opcode means C2S and S2C share one handler | Client dispatch is S2C switch; C2S is send-only | **Must not merge** |
| 11 | Opcode wiring is unsealed (UF-012) | Sole xref `0x00815d97` + case `0x20b2` + enum (re-confirmed) | **Sealed High (UF-012 closed)** |
| 12 | Packet formal is ECX | Call site `MOV EAX,ESI; MOV ECX,EBP` — ECX is client | **Fail** — packet is EAX |
| 13 | UI `+0x448` is a normal call | Image: `POP EDI; JMP [EDX+0x448]` | **Sealed: tail jmp** (Ghidra "jumptable" noise) |
| 14 | `DAT_00d1ad10+0x10` is a static constant | Image: load **pointer** from global, then `[ptr+0x10]` | **Shape sealed**; identity open |

---

## 2. Decompiler hazards (re-attacked with full image)

```
// Decompiler:
void __fastcall FUN_0080b100(int param_1) {
  int in_EAX;  // packet base — unaffiliated register
  if (*(int *)(param_1 + 0xe98) != 0) {
    CVOGReaction_FailMission(*(undefined4 *)(in_EAX + 0x10));
    FUN_005307e0();
    // then reuses param_1; objective key *(DAT_00d1ad10+0x10)
    ...
    (**(code **)(**(int **)(param_1 + 0x107c) + 0x448))();  // "call"
  }
}

// Image truth (call site 0x00815d93 + body 0x0080b100..0x0080b174):
//   EAX = packet (from ESI), ECX = client (from EBP)
//   EDI = client; ECX = *(EDI+0xe98) before FailMission and before FUN_005307e0
//   missionId = *(EAX+0x10) pushed; FailMission AL discarded
//   @0x0080b121 EAX = *(EDI+0xe98)  — packet base dead for secondary path
//   DAT_00d1ad10: MOV ECX,[imm]; MOV EDX,[ECX+0x10]  — pointer global
//   UI path: POP EDI; JMP [vtbl+0x448]  — not CALL
```

| Hazard | Prior risk | Residual status |
|---|---|---|
| `param_1` vs `in_EAX` split | Wrong object | **Sealed** — client ECX/EDI, packet EAX (until clobber) |
| FailMission thiscall ECX omitted | Wrong `this` | **Sealed** — explicit load |
| FailMission return drives cleanup | Conditional teardown | **Falsified** — cleanup always runs when char live |
| Jumptable warning on UI vtbl `+0x448` | Incomplete | **Sealed CF** — tail jmp (Ghidra noise only) |
| `FUN_005307e0()` no visible args | thiscall hazard | **Sealed framing**; product name open |
| `DAT_00d1ad10 + 0x10` as absolute | Wrong key source | **Shape sealed** as `(*global)+0x10` |

**Attack result:** core story (recv fail → FailMission → end-quest drain → optional probe/UI) survives. **Parameter binding, opcode wiring, return-ignored, EAX lifetime, and UI tail are no longer soft underbellies.**

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Opcode binding `0x20B2` → this VA | **High / Confirmed** | Wrong handler wire-up |
| Calls FailMission + end-quest helper | **High** | Incomplete local apply |
| Packet `+0x10` = missionId | **High** (asm) | Fail wrong mission |
| Character as FailMission `this` | **High** | Crash / no-op |
| End-quest always after FailMission (when char live) | **High** | Missed toast / hash ghost if inverted |
| Full cleanup completeness / helper names | **Medium** | Active mission ghost in UI |
| Rename necessity vs `FUN_0080b100` | **High utility** | Cosmetic only if refused |

---

## 4. Surviving contract for AutoCore

```
// S2C only — after server accepts abandon / reaction fail
// Call framing (from PacketDispatch): EAX = packet, ECX = game
on_recv_0x20B2(game, packet):
  char = game.character(+0xe98)
  if !char: return
  missionId = packet.missionId(+0x10)
  FailMission(char, missionId)          // thiscall ECX=char; notify + dirty bit; may return 0
  HandleEndQuest(char)                  // FUN_005307e0 thiscall — ALWAYS when char was live
  // optional: objective-hash probe (no packet fields) / UI tail refresh
  // do not block core fail on DAT_00d1ad10 / FUN_0092fd00 unknowns
```

**Server responsibility:** handle C2S `0x20B2`, strip cargo / DB active row, **echo** S2C so this handler runs. Client abandon UI does **not** optimistically call FailMission.

**Lifecycle note (cross-unit):** FailMission only **pushes** end-quest id + dirty bit; **`FUN_005307e0` drains** the vector and removes active hash nodes. This unit is the S2C glue that pairs them in fixed order.

---

## 5. What would upgrade remaining gaps

1. ~~Short asm of dispatch call site~~ **Done**.
2. ~~Full body image (return-ignored, EAX clobber, tail jmp, DAT load shape)~~ **Done this residual**.
3. Dual review of `FUN_005307e0` as `Mission_Client_HandleEndQuest` (or tighter name).
4. Live CE/packet capture: abandon click → C2S 0x20B2 → S2C 0x20B2 → FailMission returns 1 → end-quest toast.
5. Semantics of `DAT_00d1ad10` object / `FUN_0092fd00`.

---

## 6. Verdict

Do **not** reject the FailMission recv identity — dispatch + callee + full image make that hard to attack. Do **reject** any claim that this unit is the abandon button, that secondary helpers are fully understood, that FailMission success gates end-quest, or that runtime is sealed.

**UF-012 framing residual is closed High.** Remaining gaps are helper product duals and runtime.

**Verdict: accept-with-gaps** (identity + framing **High**; secondary cleanup / runtime open).
