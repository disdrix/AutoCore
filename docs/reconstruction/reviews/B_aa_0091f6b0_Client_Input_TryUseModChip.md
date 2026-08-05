# Review B (skeptical / adversarial): `aa_0091f6b0` Client_Input_TryUseModChip

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091f6b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0091f6b0_Client_Input_TryUseModChip.md` |
| **Verdict** | **accept-with-gaps** on CF/opcode/callers; **falsify** drive-axis / RequestCast confusions |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Part of thr/steer Push path | Body never touches `+0x614/618/61c` or PushDriveAxes | **Falsified** — skill/mod-chip side-path only |
| 2 | Same as `Client_RequestCastSkill` / `0x2030` | Sends **`0x202c`**, not `0x2030`; no skillId field in this pkt | **Falsified** |
| 3 | Only one caller (DriveControlTick) | Second CALL `@0x008c5132` in `FUN_008c50f4` | **Falsified** — **two** sites |
| 4 | Always validates before send | `player+0x6b9` path **skips** LocalCastValidate | **Falsified** |
| 5 | Decompiler second path omits opcode → no `0x202c` | Asm `MOV [ESP+8],0x202c` @ `0x0091f7ac` | **Falsified** — opcode sealed both paths |
| 6 | `FUN_0040ce50` shared widely | `get_function_callers` → **only** this unit | **Falsified** as shared helper |
| 7 | Failure always shows modal | Validate fail uses FormatFailureMessage + `FUN_008f8200` when `DAT_00d1b8dc`; modal only for **no chip** | **Falsified** as single UX path |
| 8 | `__stdcall` with stack client | `EDX` client; `RET` no arg pop | **Falsified** |
| 9 | Name must stay DriveControlTick-callee only | Also UI hazard/case-8 path | **Falsified** as exclusive DCT leaf |
| 10 | Packet is opcode + 20B TFID continuous | 4B gap at +4 unwritten | **Sealed gap** — do not invent zero-fill without runtime |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Opcode `0x202c` / size `0x18` | **High** | Wrong C2S handler on server |
| Self TFID @ `+0x164` | **High** | Wrong identity on wire |
| Validate polarity `0`=allow | **High** | Invert cast / toast |
| `+0x6b9` bypass | **High** | Double-gate reimpl |
| `FUN_0040ce50` = mod-chip skill | **High** role / **Med** type | Skill id vs object* |
| `client+0xc2c` consumer | **Tentative** | Cooldown UX drift |
| Flag English | **Tentative** | Misnamed binds |
| Product name | **Open** | Registry only |

---

## 3. Cross-check against raw + call sites

```
; entry 0x0091f6b0
SUB ESP,0x118
gates: [d1b6d8], [d1b644+0xf5]==0, [player+0x6bb]==0
MOV [EDX+0xc2c], 0x98967f          ; 9999999
if [player+0x6b9]:
  pkt[0]=0x202c; copy TFID; SendSectorPacket(0x18); RET
vehicle=[player+0x250]
if !vehicle || FUN_0040ce50()==-1:
  toast "You have no mod chip!"
else:
  skill=FUN_0040ce50(); skip=vtbl+0x234()
  rc=Skill_LocalCastValidate(char,0,skip,skill)
  if rc==0: pkt 0x202c+TFID; send; RET
  else: FormatFailureMessage; maybe FUN_008f8200
```

DriveControlTick site:

```
0092364b  CMP [DAT_00d1cafa],0
00923654  CMP [DAT_00d1cafb],0
0092365f  MOV [DAT_00d1cafb],0     ; edge clear
0092365d  MOV EDX,EBX             ; client
00923666  CALL 0x0091f6b0
; then PushDriveAxes if vehicle+0x101==0  — sibling, not this unit
```

UI site (`FUN_008c50f4`):

```
if player+0x6b8 && !player+0x6b9 → FUN_008c4fc0 (QB skill path)
else if DAT_00d1b778 && vtbl+0x3d8() → CALL 0x0091f6b0
```

Body re-decompile 2026-07-29 ≡ 2026-07-23 raw (no CF drift).

---

## 4. Naming attack

| Proposed | Status |
|---|---|
| `Client_Input_TryUseModChip` | **Accept INFERRED** — string + vehicle skill + input callers |
| `Named_CalleeOf_Client_Input_DriveControlTick_0091f6b0` | **Deprecate** as sole name — second caller exists |
| `Client_RequestCastSkill` | **Reject** — wrong opcode / shape |
| `Input_TryFireSecondaryWeapons` sibling | **Reject** — different body (heat/fire) |
| `FUN_0091f6b0` | Keep Ghidra residual synonym |

---

## 5. Surviving contract for AutoCore

```
On mod-chip action edge:
  if blocked globals/flags: no-op
  client.timer_c2c = 9999999
  if armed(+0x6b9): send 0x202c(self TFID); return
  if no vehicle or no mod-chip skill: modal "You have no mod chip!"
  else LocalCastValidate(self, null, skipBusy, skill):
    0 → send 0x202c(self TFID)
    else → failure toast (FormatFailureMessage)
Do NOT fold into RequestCast 0x2030 or drive-axis Push.
```

---

## 6. Residual opens (do not block seal)

1. English names for `+0x6b9`, `+0x6bb`, `DAT_00d1b644+0xf5`, ActionMap `DAT_00d1cafa`.
2. Packet dword at `+4` (zero? reserved? garbage).
3. `FUN_0040ce50` product name + whether `+0x3bc` is skill object* vs id.
4. Consumer of `client+0xc2c`.
5. PDB/product symbol; live wire capture of `0x202c`.
6. Deep identity of `FUN_008c50f4` / hazard UI product name.

**Verdict:** **accept-with-gaps**
