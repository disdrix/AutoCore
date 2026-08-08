# Review B (skeptical / adversarial): `aa_0090c9a0` MedalUi_ApplyAchievementSlotButton_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090c9a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-095) |
| **Counterpart** | `reviews/A_aa_0090c9a0_MedalUi_ApplyAchievementSlotButton_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `Named_CalleeOf_Named_VOG_DEBUG_STOP` purpose | **Falsified** — sole useful work is medal button apply; `VOG_DEBUG_STOP` is parent hash-lock error path only |
| 2 | Free-standing `void` / no formals (Ghidra) | **Falsified** — parent pushes 2 dwords; epilogue **`RET 8`**; body consumes ESI/EBX |
| 3 | `__cdecl` / caller cleans stack | **Falsified** — `C2 08 00` callee cleans 8 |
| 4 | ECX thiscall-only (no ESI host) | **Falsified** — host is ESI; widget thiscall uses ECX after load from slot table |
| 5 | Skill / combat floater / inventory helper | **Falsified** — string is achievement button XML; parent is medal list/hash fill |
| 6 | Award medal / grant medal logic | **Falsified** — no award/write to character medal set; UI construct/bind only |
| 7 | `earnedFlag` is visibility bool inverted | **Clarify** — flag==0 triggers dim path; parent passes **1** for owned vector, **0** for unowned hash remainder — polarity sealed by call sites |
| 8 | 4-column or free-form layout | **Falsified** — `MOV EDI,3; IDIV EDI` forces **3** columns |
| 9 | Plate name `UI_a_btn_achievement` is product demangle | **Overclaim** — XML stem only; host class English open → keep `_Inferred` dual name |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RET 8 + two stack args | **High** | Stack imbalance in ports |
| ESI host / EBX slot | **High** | Wrong object/slot binding |
| Medal UI apply role | **High** | Mis-system tagging |
| 3-col grid math | **High** | Wrong layout port |
| `.dds` append | **High** | Missing texture suffix |
| Dim path = “unowned” English | **Med** | Art/UX wording only |
| Vtable method English | **Low** | Doc only |
| `FUN_007b5dd0` type name | **Low** | Widget class label |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean MedalUi_ApplyAchievementSlotButton_Inferred.cpp

Body: 0090c9a0 – 0090cbbb (540 B)
Entry:  6A FF 68 AB 3A 9B 00 64 A1 00 00 00 00 50 64 89 25 …  ; SEH
        81 EC 30 01 00 00 68 88 04 00 00                     ; SUB ESP,0x130; PUSH 0x488
Epilog: 81 C4 3C 01 00 00 C2 08 00                           ; ADD ESP,0x13C; RET 8

Slot store: MOV [ESI + EBX*4 + 0x540], EAX
Grid:       CDQ; MOV EDI,3; IDIV EDI   ; row=EAX, col=EDX
String:     PUSH 0x00a31024            ; "i_d_a_2d_btn_achievement.xml"
Suffix:     MOV EAX,[0x00a2c53c]       ; ".dds"
Flag test:  CMP byte [ESP+0x14c], 0    ; earnedFlag after PUSH EBP/EDI

Parent site1: PUSH 1; PUSH medalDef; MOV EBX,EBP; CALL 0090c9a0
Parent site2: PUSH 0; PUSH medalDef; CALL 0090c9a0
Xrefs: only those two UNCONDITIONAL_CALL from FUN_0090cbc0
```

Reject ports that:

- Treat this as VOG_DEBUG_STOP / hash-lock helper.
- Use cdecl without popping 8 bytes.
- Ignore ESI/EBX register formals.
- Award medals or mutate character medal inventory.
- Assume 4-column grid or free layout.
- Claim runtime Confirmed without Launcher evidence.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail: medal UI slot button apply/toggle
// Port: create achievement-button control for one grid cell.

void MedalUi_ApplyAchievementSlotButton(
    MedalUiHost host,      // ESI
    int slotIndex,         // EBX, 0..23 panel cells
    MedalDef medalDef,     // stack
    bool earned)           // stack; false → dim/lock visual
{
    var btn = new AchievementSlotButton(); // FUN_007b5dd0 / 0x488
    host.SlotWidgets[slotIndex] = btn;
    host.AttachChild(btn);
    btn.LoadLayout("i_d_a_2d_btn_achievement.xml");
    // 3-col grid placement from slotIndex
    btn.SetTexture(medalDef.IconName + ".dds");
    btn.SetControlId(slotIndex + 0x9c43);
    if (!earned) btn.ApplyUnownedVisual(mode: 2);
}
```

Pair with parent panel fill `FUN_0090cbc0` and `MedalDef_LookupById` (`0x0051a0e0`).

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/callers/string/grid/flag polarity. Remaining gaps are product English + runtime only → **accept-with-gaps**. Terminal **false**.
