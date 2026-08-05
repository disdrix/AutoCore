# Review B (skeptical / adversarial): `aa_008800e0` UI_VehicleInvSheet_RefreshHardpointWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008800e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008800e0_UI_VehicleInvSheet_RefreshHardpointWidgets_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF (ESI + slots + gates sealed) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Standard `__thiscall` ECX | Body never loads ECX from stack; uses **ESI** | **Falsified** as ECX-thiscall |
| 2 | Always refreshes even when sheet closed | `vtbl+0x3d8` early-out if false | **Falsified** |
| 3 | Works with no local player | `DAT_00d1b6d8==0` early-out | **Falsified** |
| 4 | `FUN_00862b70` is destroy/free | Callee sets mode 0/1/2 + optional redraw | **Falsified** as free |
| 5 | Slot list is sequential `+0x588` only | Ten distinct offsets; order 0x5a0/0x5a8/0x5a4 first | **Falsified as sequential-only** |
| 6 | Passes vehicle in ECX to 00862b70 | EDI=`+0xcd0`; EAX=widget | **Falsified** as ECX vehicle |
| 7 | This is mission UI refresh itself | Mission refresh **calls** sibling `0088ef70`; this is vehicle sheet only | **Falsified** |
| 8 | Hidden third caller | 2 UNCONDITIONAL_CALL | **Falsified** |
| 9 | Decompiler empty signature is final product ABI | ESI register contract required | **Survives as decompiler artifact** — document ESI |
| 10 | Slot English is Confirmed | No strings in this leaf | **Gap** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI = sheet this | **High** | Wrong UI host |
| Gates DAT + vtbl+0x3d8 | **High** | Refresh when closed / no char |
| Ten offsets listed | **High** | Miss kits |
| EDI vehicle + EAX widget into 00862b70 | **High** | Wrong mode state |
| Tail 0087d810(sheet) | **High** | Stale labels/DPS |
| Slot product names | **Open** | Doc only |
| 0087d810 full CF | **Open** | Out of unit scope |
| Runtime | **Open** | |

---

## 3. Cross-check live body head

```
008800e0  cmp  dword [DAT_00d1b6d8], 0
008800e7  jz   exit
008800ed  mov  eax, [esi]
008800ef  mov  ecx, esi
008800f1  call dword [eax+0x3d8]
008800f7  test al, al
008800f9  jz   exit
008800ff  mov  eax, [esi+0x5a0]
00880105  test eax, eax
00880107  mov  ecx, [DAT_00d1b6d8]
0088010d  push edi
0088010e  mov  edi, [ecx+0xcd0]
00880114  jz   skip1
00880116  call FUN_00862b70
...
008801xx  push esi
008801xx  call FUN_0087d810
```

---

## 4. Surviving contract for AutoCore

```c
// custom: sheet in ESI
void UI_VehicleInvSheet_RefreshHardpointWidgets(VehicleInvSheet* sheet /*ESI*/);
```

- No-op if no local char host or sheet not open.
- Recomputes each present hardpoint widget vs `*(charHost+0xcd0)`.
- Rebuilds sheet labels via `FUN_0087d810`.

---

## 5. Verdict

**accept-with-gaps** — do not “fix” empty prototype without ESI; do not treat as mission or character bag refresh.
