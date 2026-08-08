# Review B (skeptical / adversarial): `FUN_008ab0a0` @ `0x008ab0a0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ab0a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_008ab0a0_Client_NpcMissionDialog_InitRuntimeFields_Inferred.md` |
| **Verdict** | **accept-with-gaps** on ECX ABI + field pack + banks + sole CALL; **needs-more-evidence** on product English and float4 roles |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | ESI register-this like `008ab340` | Body uses `[ECX+disp]` exclusively; ESI only scratch for float stores; `PUSH/POP ESI` | **Falsified ESI-this** — ECX thiscall |
| 2 | This **builds** response buttons / loads XML | No CALL; no `operator_new`; no string push; ReloadInterface is **caller** after return | **Falsified** — field pack only |
| 3 | Same as `MissionDialog_ClearResponseButtonSlots` (`008aa560`) | Clear destroys widgets via vtbl+0xBC; this only writes −1/0 with no virtual calls | **Falsified as destroy** — init/sentinel only |
| 4 | Stack-arg this (ctor style of parent) | Parent is stack-this→EDI; this unit is ECX; plain RET not RET 4 | **Falsified stack-this** |
| 5 | Multiple CALL sites | xrefs: 1 UNCONDITIONAL_CALL + 1 DATA vtbl | **Survives** as sole CALL; DATA is vtbl slot not call |
| 6 | Scaffold `Named_CalleeOf_Mission_i_d_npc_xml_*` is product | Parent-string auto plate only | **Demote** — retired alias |
| 7 | Floats are identity matrix rows (0,0,0,1) | Parent ctor writes (0,0,0,1) then **this overwrites** with (0,1,0,α) / (0,0,0,0.6) | **Falsified as identity** for final state after this runs |
| 8 | `+0x64c` is panel mode | Panel mode is `+0x648` (ApplyPanelMode); `+0x64c` is turn-in byte (registry + ShowUI dual) | **Falsified as panel mode** |
| 9 | Not leaf — hidden helpers | disasm has no CALL; only MOVSS/MOV stores | **Falsified** — leaf sealed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX host this | **High** | Wrong object wiped |
| Response bank offsets | **High** | Break BuildResponseButtons pairing |
| Reward/chrome 4-slot pattern | **High** | ApplyPanelMode hide wrong grid |
| Float constants | **High** | Wrong default colors/scales |
| Sole ctor CALL | **High** | Miss re-init paths if any virtual dispatch |
| Product names | **Open** | Registry noise |
| Float4 meaning | **Tentative** | Wrong UI theme if mis-ported labels |

---

## 3. Cross-check spine

```
// ECX = NpcMissionDialogHost* host  (ctor EDI)
zero many widget/scalar fields
for i in 0..3:
  host+0x558+i*8 = (-1,-1)
  host+0x698/6a8/6b8/6c8 + i*4 = 0
for i in 0..7:
  host+0x518+i*8 = (-1,-1)
  host+0x708+i*4 = 0
host+0x578/57c = -1
host+0x594 = (0,0,0,0.6)
host+0x584 = (0,1,0,0.157)
host+0x5a4 = (0,1,0,0.549)
host+0x64c = 0  // turn-in
// return to ctor → ReloadInterface("i_d_npc.xml") → BuildResponseButtons
```

### What this unit is **not**

| Non-claim | Why |
|---|---|
| Response button clear (`008aa560`) | destroy virtuals; EBX ABI |
| Panel mode applicator (`008ab550`) | mode table + visibility + title fill |
| Host ctor (`008ac3f0`) | parent; stack this; RET 4 |
| XML reload / widget build | callees of parent after this returns |
| Packet / sector send | no network |

---

## 4. Residual attacks left open

1. Exact product labels for float4 banks (RGBA theme? layout?).
2. Whether vtbl+0x3AC is ever called virtually after construction (DATA only; no other CALL xrefs).
3. Full semantic map of every zeroed pointer field (title vs list vs chrome).
4. Image variants with different default constants.

---

## 5. Verdict

**accept-with-gaps** — adversarial pass cannot break ECX ABI, leaf field-pack role, bank offsets, constants, or sole ctor CALL; product English and float4 roles remain open. No runtime Confirmed.
