# Review B (skeptical / adversarial): `aa_008c50f4` Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c50f4` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (gap-close) |
| **Counterpart** | `reviews/A_aa_008c50f4_Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/callees; **falsify** free-standing void, inventory, and pure-modchip-only confusions |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Ghidra `void FUN_008c50f4(void)` is full ABI | Body ends `POP ESI; RET 8`; gate pushes ESI and loads this into ESI; two stack formals on logical entry | **Falsified** as free-standing void — **bytes win** |
| 2 | `unaff_ESI` is decompiler noise / undefined | Gate `MOV ESI,ECX` then `JZ` into body; body uses `[ESI+0x514]` | **Falsified** as noise — ESI is **this** |
| 3 | Callable with multiple CALL sites | `get_function_callers` empty; only CONDITIONAL_JUMP xref from `0x008c50e5` | **Falsified** as multi-CALL entry |
| 4 | Always host cast | Requires `+0x6b8 && !+0x6b9`; else mod-chip branch | **Falsified** as always-cast |
| 5 | Always mod-chip | Host branch takes priority when both flags host-clean | **Falsified** as always-modchip |
| 6 | Inventory grab/drop/equip | No inventory opcodes; only dualed cast/mod-chip leaves + widget float | **Falsified** |
| 7 | Same as `UI_Window_OnCommand_Class8` full switch | This body is one specialized `(8,0x9c40)` island; class-8 switch lives at `0x0082f510` | **Falsified** as full class-8 map |
| 8 | `DAT_00d1b778` is local player | Player is `DAT_00d1b6d8`; `DAT_00d1b778` is separate UI probe/EDX for TryUseModChip | **Falsified** |
| 9 | Widget path is physics `+0x514` hardpoint table | Context is UI `this`; vtbl float get/set — not VehSpec hardpoint array | **Falsified** |
| 10 | Product name Confirmed | No string/RTTI on VA | **Open** — keep `_Inferred` |
| 11 | Gate at `0x008c50d0` is dual-owned | Task exclusive VA is `0x008c50f4` only; gate is context | **Sealed** as context, not owned |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI this + RET 8 ABI | **High** | Port wrong convention → stack corruption |
| Host vs mod-chip flag gate | **High** | Wrong skill/mod-chip branch in UI |
| Callee identities (dualed leaves) | **High** | Wrong system attribution |
| Always return 1 | **High** | Caller thinks unhandled |
| `(8, 0x9c40)` product English | **Tentative** | Mislabel close vs activate |
| `DAT_00d1b778` type | **Open** | Wrong UI dependency |
| Widget `+0x514` purpose | **Open** | Spurious UI side-effect in port |
| Runtime | **Open** | |

---

## 3. Cross-check against raw + siblings

Host cast sibling (`aa_008c4fc0`) documents sole caller as this VA when `+0x6b8 && !+0x6b9` — **matches** live call @ `0x008c510f`.

Mod-chip sibling (`aa_0091f6b0`) lists caller @ `0x008c5132` “UI path; vtbl`+0x3d8` on `DAT_00d1b778`” — **matches** live body.

Gate bytes and body epilogue form one thiscall frame — treating Ghidra’s function start as a **jump target**, not a new frame.

---

## 4. Naming attack

| Proposed | Status |
|---|---|
| `Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred` | **Accept INFERRED** — cmd pair + dualed branches |
| `FUN_008c50f4` | Keep Ghidra residual synonym |
| `Client_CastFirstHardpoint…` | **Reject** — parent dispatcher, not the cast leaf |
| `Client_Input_TryUseModChip` | **Reject** — callee only |
| `UI_Window_OnCommand_Class8_Inferred` | **Reject** — different VA / full switch |
| `Client_Inventory_*` | **Reject** — no transfer wire |

---

## 5. Surviving contract for AutoCore

```
// Logical thiscall (gate 0x008c50d0 + body 0x008c50f4):
//   bool __thiscall OnCmd(self, cmdClass, cmdId)
// Special case only: (8, 0x9c40)

if player host(+0x6b8) and not enhanced(+0x6b9):
  Client_CastFirstHardpointSkillFlag200_Inferred()
else if DAT_00d1b778 and vtbl[+0x3d8]():
  Client_Input_TryUseModChip(EDX=DAT_00d1b778)
if self[+0x514]:
  f = getFloat(widget); setFloat(widget, f)
return true  // RET 8
```

Port must **not** invent a bare `void f(void)` with no stack cleanup, and must **not** treat `unaff_ESI` as optional.

---

## 6. Verdict

**accept-with-gaps** — ABI/CF/callees sealed; product UI class, cmd English, widget type, runtime open. Not reject: reconstruction is port-ready for the sealed contract.
