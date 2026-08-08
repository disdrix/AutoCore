# ADV-MEGA independent adversarial spot-check — dual-sealed MEGA residual sample

| Field | Value |
|---|---|
| **Agent** | **ADV-MEGA** (independent adversarial verifier — **not** dual author) |
| **Date** | `2026-08-05` |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | MEGA residual duals (OWN-ONLY landings MEGA-001…021 sample) |
| **Scope** | Eight dual-sealed units spanning inventory / skills / missions / input — try to **falsify** dual A/B claims |
| **Tools** | Ghidra MCP `batch_decompile`, `read_memory`; dual A/B + raw + clean + function-record read-through |
| **Forbidden** | Parent ledgers; dual A/B rewrite; Launcher; inventing product names; `disassemble_bytes` |
| **Image** | `autoassault.exe` base `0x400000` |
| **Terminal** | **false** (no dual claim forced re-queue) |

---

## Sample units

| # | VA | Canonical name | System | MEGA |
|---|---|---|---|---|
| 1 | `0x00520dc0` | `CVOGCharacter_CleanupDraggingObject` | inventory-transfer | 001 |
| 2 | `0x00522060` | `Character_CountType1aCraftableBatches` | inventory-transfer | 002 |
| 3 | `0x005310a0` | `Character_GiveItemByCbid_Inventory_Inferred` | missions + inventory | 003 |
| 4 | `0x00589c70` | `Skill_HB_ApplyHpDelta_Inferred` | skills-abilities | 006 |
| 5 | `0x0092a590` | `Tracker_SetActiveMissionObjective_Inferred` | missions-progression | 010 |
| 6 | `0x00513eb0` | `Item_TryConcatStackWithPeer` | inventory-transfer | 012 |
| 7 | `0x007f6db0` | `ActionMap_FindSlotByKeyMod_Inferred` | input-drive-control | 018 |
| 8 | `0x0092f090` | `MissionUI_ParkDriveAxes_Inferred` | input-drive-control | 021 |

---

## Inspected evidence (all eight)

| Kind | Paths |
|---|---|
| Dual A/B | `docs/reconstruction/reviews/A_aa_*` + `B_aa_*` for each VA above |
| Dual reports | `docs/agents/task-dual-ab-*-mega-0{01,02,03,06,10,12,18,21}-report.md` |
| Raw | `docs/reconstruction/raw/aa_<va>_FUN_*.md` (+ annotated twins) |
| Function records | `docs/reconstruction/functions/aa_<va>_*.md` |
| Clean | `docs/reconstruction/reconstructed-exact/<Canonical>.cpp` (+ `FUN_*` twins) |
| Live | `batch_decompile` of all eight VAs |
| Bytes | `read_memory` entry / body / epilogue / JT / product plate samples |

**Not performed:** dual A/B overwrite; Launcher / runtime Confirmed; `disassemble_bytes`.

---

## Summary table

| VA | Canonical | Dual verdict | **ADV** | Why |
|---|---|---|---|---|
| `0x00520dc0` | `CVOGCharacter_CleanupDraggingObject` | accept-with-gaps | **PASS** | Plate Class::Method; RET 4 / AL bool; cargo≠locker ECX; decomp this-bind trap disclosed |
| `0x00522060` | `Character_CountType1aCraftableBatches` | accept-with-gaps | **PASS** | thiscall RET 0x10; type 0x1a; dual-grid; mode 1/2 polarity; ADD not min |
| `0x005310a0` | `Character_GiveItemByCbid_Inventory_Inferred` | accept-with-gaps | **PASS** | RET 8 + count loop sealed vs decomp arity/while; factory+SendAdd; gate +0x7e |
| `0x00589c70` | `Skill_HB_ApplyHpDelta_Inferred` | accept-with-gaps | **PASS** | cdecl bare RET; +heal/−damage; percent max HP; leave-1 floor; not heat/shield |
| `0x0092a590` | `Tracker_SetActiveMissionObjective_Inferred` | accept-with-gaps | **PASS** | ECX tracker / EAX id / AL bool; +0x10/+0xc/+0x6/+0x4; sole parent binder leaf |
| `0x00513eb0` | `Item_TryConcatStackWithPeer` | accept-with-gaps | **PASS** | thiscall RET 4; CBID; limit **+0x4BC**; early fit skips SetQty; rem0→limit |
| `0x007f6db0` | `ActionMap_FindSlotByKeyMod_Inferred` | accept-with-gaps | **PASS** | EAX mode / EDI map / SI key / DX mod; stride 0x34; JT; leaf; sole caller mode 0 |
| `0x0092f090` | `MissionUI_ParkDriveAxes_Inferred` | accept-with-gaps | **PASS** | ESI host; thr0/steer0/HB1; +0xe98/+0x250; bare RET; not PushDriveAxes |

**Score: 8/8 PASS. 0 FAIL. Terminal false.**

---

## Unit 1 — `0x00520dc0` CVOGCharacter_CleanupDraggingObject

### Dual claims under attack

| # | Attack | Result |
|---|---|---|
| 1 | Scaffold / `_Inferred` only (no product plate) | **Survives dual** — live plate `"CVOGCharacter::CleanupDraggingObject"` @ `0x009cf0b0` |
| 2 | Decompiler `__fastcall` sole-ECX / no stack cleanup | **Survives** — dual seals `RET 4`; entry `8B F9` this→EDI |
| 3 | FindFree/Place this = drag item (decomp surface) | **Survives dual honesty** — dual **rejects** decomp; clean restores cargo/locker grid ECX |
| 4 | Cargo and locker use the same grid | **Survives** — Path A `*(*(this+0x250)+0x2B0)`; Path B `[this+0xCBC]` |
| 5 | Clears `+0xCD0` when drag null | **Survives** — early-out returns before clear |
| 6 | Always equip-switch | **Survives** — only after both place fails + status ∈ `{0,1,0xA,0xD,0xF}` |
| 7 | Vehicle-paint-only reading of `+0xCD0` for this method | **Survives** — plate + place/equip item flow |

### Live seal

```text
read_memory 0x00520dc0 len=32:
6a ff 68 f7 37 9a 00 64 a1 … 83 ec 10 53 56 57 8b f9 8b 0d 7c …
; SEH prolog + MOV EDI,ECX

read_memory 0x009cf0b0:
"CVOGCharacter::CleanupDraggingObject"
```

Live decompile ≡ frozen raw CF (null early-out → dual FindFree/Place → TryEquip → clear → 0/1) **and** still mis-binds ECX for callees — dual already flags this; clean is assembly-corrected.

| Claim | Conf |
|---|---|
| ABI ECX-this / RET 4 / AL bool | **High** |
| Product Class::Method plate | **High** |
| Cargo vs locker grid split | **High** |
| Direct callers | **Open** (dual gap honest) |
| Equip status English | **Open** |

### Residual risks

- Zero Ghidra code xrefs → integration edges open (not proof of dead code).
- Unread stack dword meaning open.
- Runtime / bit-exact open.

### ADV verdict

**PASS** — keep dual **accept-with-gaps**. Decomp traps disclosed; no false sealed claim. No re-queue.

---

## Unit 2 — `0x00522060` Character_CountType1aCraftableBatches

### Dual claims under attack

| # | Attack | Result |
|---|---|---|
| 1 | This **is** `ValidateCraftAffordability` | **Survives** — distinct character batch counter; craft parent is consumer |
| 2 | Single inventory only | **Survives** — cargo `*( *(this+0x250)+0x2b0 )` **plus** locker `*(this+0xcbc)` |
| 3 | cdecl / plain RET | **Survives** — epilogue `C2 10 00` (RET 0x10) |
| 4 | `min(primary, secondary)` | **Survives** — assembly **ADD**s secondary min into `*out` |
| 5 | Mode 1 skips secondary / mode 2 skips primary | **Survives** — inverted: mode **1** skips primary; mode **2** skips secondary |
| 6 | Simple path uses primary CBID `+0x4d0` | **Survives** — simple uses **`+0x4c0`** |
| 7 | Type-agnostic | **Survives** — hard `CMP [obj+0x38],0x1a` |

### Live seal

```text
read_memory 0x00522060:
53 8B 5C 24 0C 55 8B E9 C7 03 00 00 00 00   ; EBX=out; EBP=this; *out=0
8B 85 50 02 00 00                             ; cargoHolder +0x250
8B 88 B0 02 00 00                             ; cargo +0x2b0
83 BD BC 0C 00 00 …                           ; locker +0xcbc

read_memory 0x005221f0 epilogues:
… 0F 9F C0 5B C2 10 00   ; SETG AL; RET 0x10
… 32 C0 5B C2 10 00       ; XOR AL,AL; RET 0x10
```

Live decompile hides dual-grid this on `FUN_005711c0` (passes CBID as if free function) — dual/clean restore ECX from assembly. Mode/simple CF matches dual.

| Claim | Conf |
|---|---|
| thiscall + RET 0x10 + 4 stack args | **High** |
| Type `0x1a` + dual cargo/locker | **High** |
| Mode matrix + simple `+0x4c0` | **High** |
| Primary floor-div + secondary min ADD | **High** |
| Product field English | Open → name without `_Inferred` is role-strong, not PDB |

### Residual risks

- Product English for primary/secondary/simple banks.
- Runtime / bit-exact open.

### ADV verdict

**PASS** — keep dual **accept-with-gaps**. No re-queue.

---

## Unit 3 — `0x005310a0` Character_GiveItemByCbid_Inventory_Inferred

### Dual claims under attack

| # | Attack | Result |
|---|---|---|
| 1 | Log-only `"Invalid CBID"` reporter | **Survives** — factory + serial + `Client_SendInventoryAddItem` primary path |
| 2 | Same as factory `CVOGReaction_GiveItemByCbid` | **Survives** — factory is callee; this owns count loop + insert |
| 3 | Decompiler arity `(this, cbid)` / `while(factory)` infinite | **Survives dual honesty** — assembly `remaining=count` / `SUB` / `JNZ`; **`RET 8`** |
| 4 | Free function / ECX unused | **Survives** — `MOV EDI,ECX`; dual-base char |
| 5 | Gate `+0x7e` clear → fail | **Survives** — clear → **success** early (`AL=1`) |
| 6 | Always returns false after loop | **Survives** — decomp false fall-through; asm success after count exhaust |

### Live seal

```text
read_memory 0x005310a0:
83 EC 18 53 55 56 57 8B F9     ; prolog; EDI=this
8B 47 04 8B 48 04 8B 84 39 A8 00 00 00  ; dual-base +0xa8
8A 40 7E 84 C0 0F 84 5F 01 00 00        ; gate +0x7e
8B 54 24 30 89 54 24 14                 ; remaining = count

read_memory 0x00531240:
… C2 08 00 CC…                         ; RET 8
```

Live decompile still shows `(this, cbid)` only and `while (GiveItemByCbid)` ending in always-fail log — **exactly** the trap dual seals. Clean uses assembly arity/loop.

| Claim | Conf |
|---|---|
| thiscall + RET 8; cbid+count | **High** |
| Count-down grant + factory null fail | **High** |
| Fail string @ `0x009cfea4` | **High** (dual; string not re-read this pass) |
| Character class / vtbl English | Open → `_Inferred` correct |
| Runtime | Open |

### Residual risks

- First-item `FUN_00513e70` bind collapse English residual.
- Decompiler surface alone must never be ported.

### ADV verdict

**PASS** — keep dual **accept-with-gaps**. Critical decomp falsification already owned by dual. No re-queue.

---

## Unit 4 — `0x00589c70` Skill_HB_ApplyHpDelta_Inferred

### Dual claims under attack

| # | Attack | Result |
|---|---|---|
| 1 | Heat apply (`00589bc0`) or shield (`00589d90`) | **Survives** — HP vtbls + `FUN_004d7e30`; distinct VAs |
| 2 | Positive amount = damage | **Survives** — `deltaInt = -trunc(amount)`; `HP' = HP - deltaInt` |
| 3 | `__thiscall` / ECX = skill | **Survives** — prolog only PUSH regs; stack formals; bare `C3` |
| 4 | Percent uses current HP | **Survives** — multiplies **vtbl+0x244** (max) |
| 5 | Floor recomputes return | **Survives** — applied delta only; return uses unclamped projected |
| 6 | Multiple callees / network send | **Survives** — sole CALL `FUN_004d7e30` |

### Live seal

```text
read_memory 0x00589c70:
53 55 56 57 8B 7C 24 18 85 FF … FF 90 9C 01 00 00
; PUSH regs; load target from stack; CALL [EAX+0x19C]

read_memory 0x00589d70:
… 8B C7 2B C5 5F 5E 5D 5B C3   ; projected-cur; bare RET
… 33 C0 5B C3                    ; ret0; bare RET
```

Live decompile CF ≡ dual: resolve entity → percent window `DAT_00aaa668`/`g_flOne` → max/cur HP → floor → apply → return projected−cur. cdecl 4-arg surface matches callers cleaning `0x10`.

| Claim | Conf |
|---|---|
| cdecl 4-arg + bare RET | **High** |
| Sign + percent-of-max + leave-1 | **High** |
| Return unclamped projected−cur | **High** |
| Product `Skill_HB_*` demangle | Open → `_Inferred` correct |
| `FUN_004d7e30` full floater contract | Med (disclosed) |

### Residual risks

- Shared apply dual residual; runtime open.
- Do not merge with heat/shield siblings.

### ADV verdict

**PASS** — keep dual **accept-with-gaps**. No re-queue.

---

## Unit 5 — `0x0092a590` Tracker_SetActiveMissionObjective_Inferred

### Dual claims under attack

| # | Attack | Result |
|---|---|---|
| 1 | Full mission-bind path (gate + UI) | **Survives** — tracker write leaf only; parent owns gate/UI |
| 2 | Pure ECX-thiscall with stack missionId | **Survives** — missionId in **EAX**; bare `C3` |
| 3 | Void / undefined return | **Survives** — `B0 01` / `32 C0` → AL bool |
| 4 | Zero-id returns failure | **Survives** — clear then `MOV AL,1` |
| 5 | Hash miss leaves stale `+0x10` | **Survives** — fail zeros `+0x10`/`+0xc` |
| 6 | Multi-caller dialog leaf | **Survives** — sole xref parent `0x0092fd00` |
| 7 | Bind flag dword at `param_1[1]` | **Survives** — `C6 47 04 01` **byte** `+0x4` |

### Live seal

```text
read_memory 0x0092a590 len=112 (body 111 B + CC):
56 57 8B F9 33 F6 3B C6 89 47 10 C6 47 06 01 75 17
E8 … 8B C7 E8 … 89 77 10 89 77 0C 5F B0 01 5E C3   ; zero-id → AL=1
8B 0F 8B 89 98 0E 00 00 … 8B 89 48 05 00 00 50     ; char+0xe98; hash+0x548
… 8B 90 4C 01 00 00 8B 02 89 47 0C C6 47 04 01 … B0 01 C3  ; hit
… 32 C0 5E C3 CC                                     ; fail AL=0
```

Byte-for-byte match to dual A listing. Live decompile CF ≡ raw ≡ clean (with register ABI documented).

| Claim | Conf |
|---|---|
| ECX=tracker / EAX=id / AL=bool / bare RET | **High** |
| Offsets +0x10 / +0xc / +0x6 / +0x4 | **High** |
| Host `*tracker→+0xe98→hash+0x548` / node+0x14c | **High** |
| Sole-caller binder role | **High** |
| Product tracker/objective English | Open → `_Inferred` |

### Residual risks

- Clear helpers `0092a3d0` / `00929c00` custom ABI (EDI/EAX) residual peers.
- Runtime open.

### ADV verdict

**PASS** — keep dual **accept-with-gaps**. No re-queue.

---

## Unit 6 — `0x00513eb0` Item_TryConcatStackWithPeer

### Dual claims under attack

| # | Attack | Result |
|---|---|---|
| 1 | Capacity predicate only (`Item_CanAcceptStackQty`) | **Survives** — mutates; different VA; max sibling uses **+0x4BA** |
| 2 | Limit is def **`+0x4BA`** | **Survives** — body `MOV DX,[EAX+0x4BC]` |
| 3 | `this` is peer / inverted merge | **Survives** — call sites: ECX=destination; stack=absorbed |
| 4 | Always merges vfunc qty on success | **Survives** — early fit returns before SetQty |
| 5 | rem0 leaves field 0 | **Survives** — rem0 → full limit |
| 6 | Fastcall / no cleanup | **Survives** — three exits `C2 04 00` |

### Live seal

```text
read_memory 0x00513eb0:
56 8B F1 8B 4C 24 08 85 C9 …           ; ESI=this; ECX=peer; null fail
8B 91 A8 00 00 00 8B 86 A8 00 00 00    ; clonebases
8B 52 34 3B 50 34 …                     ; CBID @ +0x34
8B 40 3C 66 8B 90 BC 04 00 00          ; def; limit +0x4BC
… 66 89 86 80 01 00 00 … B0 01 5E C2 04 00  ; fit store +0x180; RET 4 early
… FF 92 5C 02 00 00 … FF 97 60 02 00 00     ; GetQty +0x25C / SetQty +0x260
… B0 01 5E C2 04 00
32 C0 5E C2 04 00                       ; fail RET 4
```

Live decompile ≡ dual CF (limit **0x4bc**, early return, rem0→limit, qty sum). Clean matches.

| Claim | Conf |
|---|---|
| thiscall RET 4 / AL bool / this=dest | **High** |
| CBID + `+0x180` / `+0x4BC` math | **High** |
| Early fit skips SetQty | **High** |
| English for `+0x180` / `+0x4BC` | Open |
| Runtime / server parity of rem rule | Open |

### Residual risks

- Product field English residual only.
- Do not equate `+0x180` with vfunc qty.

### ADV verdict

**PASS** — keep dual **accept-with-gaps**. No re-queue.

---

## Unit 7 — `0x007f6db0` ActionMap_FindSlotByKeyMod_Inferred

### Dual claims under attack

| # | Attack | Result |
|---|---|---|
| 1 | Plain `__fastcall(param_1,param_2)` only | **Survives** — EAX=mode, EDI=map, SI=key, DX=mod |
| 2 | Keybind writer / mutator | **Survives** — pure scan; returns pointer; no stores |
| 3 | Single mode / single lane | **Survives** — 4-mode JT + primary/alt |
| 4 | Key-only (ignores mod) | **Survives** — mod zeroness + override flag |
| 5 | thiscall ECX=ActionMap / RET 4 | **Survives** — EDI base; bare `C3` |
| 6 | Many callers | **Survives** — sole caller `0x00911429` (mode 0) |

### Live seal

```text
read_memory 0x007f6db0:
83 F8 03 77 77 FF 24 85 A4 6F 7F 00   ; CMP EAX,3; JA fail; JMP [EAX*4+JT]
33 C9 8D 47 30 66 39 70 D6 …           ; mode0: i=0; cursor=EDI+0x30; CMP key0,SI

read_memory 0x007f6fa4 (JT):
BC 6D 7F 00  2F 6E 7F 00  AB 6E 7F 00  27 6F 7F 00
→ 0x007f6dbc, 0x007f6e2f, 0x007f6eab, 0x007f6f27
```

Live decompile CF ≡ dual: mode switch, bounds 5/6/0x78/0x14, stride 0x34 (`psVar1+0x1a`), return `map+key0Base+i*0x34`. Clean tables match.

| Claim | Conf |
|---|---|
| Register ABI + bare RET | **High** |
| Mode JT / stride / dual-lane / override | **High** |
| Leaf / sole caller mode 0 | **High** |
| Mode product English | Tentative (disclosed) |
| Modes 1–3 live use via this path | Unobserved (disclosed) |

### Residual risks

- Product mode group names open.
- Keep modes 1–3 for parity with `TrySetSlotBind` even if OnKeyDown only uses 0.

### ADV verdict

**PASS** — keep dual **accept-with-gaps**. No re-queue.

---

## Unit 8 — `0x0092f090` MissionUI_ParkDriveAxes_Inferred

### Dual claims under attack

| # | Attack | Result |
|---|---|---|
| 1 | ECX-thiscall on park helper | **Survives** — body reads **ESI+0xe98**; sites `MOV ESI,EBP` |
| 2 | Stack formals / RET 4 | **Survives** — bare `C3` |
| 3 | Only thr parked / HB cleared | **Survives** — thr0, steer0, **HB=1** |
| 4 | Calls `PushDriveAxes` | **Survives** — only three dualed setters |
| 5 | Exclusive ShowNpcMissionDialogUI callee | **Survives** — also `FUN_0093e450` ×3 |
| 6 | Always parks (no gate) | **Survives** — null char / null vehicle early-out |
| 7 | Product demangle known | **Survives** — `_Inferred` required |

### Live seal

```text
read_memory 0x0092f090 len=70 (66 B body + CC pad):
8B 86 98 0E 00 00 85 C0 74 37          ; char = [ESI+0xe98]
8B 88 50 02 00 00 85 C9 74 2D          ; veh  = [char+0x250]
6A 00 E8 …                             ; SetLongitudinalInput(0) → 0x004f5650
… 6A 00 E8 …                           ; SetSteerInput(0)        → 0x004f5620
… 6A 01 E8 … C3 CC CC CC CC            ; SetHandbrake(1)         → 0x004f3620; RET
```

Rel32 targets and immediates match dual A listing exactly. Live decompile ≡ raw 2026-07-23 ≡ clean.

| Claim | Conf |
|---|---|
| ABI ESI-host / bare RET | **High** |
| Offsets +0xe98 / +0x250 | **High** |
| thr0 / steer0 / HB1 constants | **High** |
| 5 sites / 2 parents | **High** (dual evidence; not re-enumerated this pass) |
| Product host English | Open → `_Inferred` |

### Residual risks

- Thr/steer may suppress under setter 0xC7 while HB still writes (dual nuance).
- Runtime open.

### ADV verdict

**PASS** — keep dual **accept-with-gaps**. No re-queue.

---

## Cross-cutting findings

| Theme | Finding |
|---|---|
| Decompiler traps | **Recurring and correctly dualed**: ECX this-bind collapse (`00520dc0`, `00522060`), arity/loop collapse (`005310a0`), register ABI phantoms (`007f6db0`, `0092a590`, `0092f090`) |
| Clean vs raw | Clean sources are assembly-corrected where dual documents traps; raw frozen decomp remains intentionally uncorrected |
| Naming | Product plate only on CleanupDraggingObject; remaining `_Inferred` / role names appropriate |
| Gaps | All eight duals leave runtime / bit-exact open; product English residual honest |
| Overwrite | **None** — dual A/B files untouched |

---

## Terminal decision

| Metric | Value |
|---|---|
| Units sampled | **8** |
| PASS | **8** |
| FAIL | **0** |
| Dual re-queue required | **No** |
| **Terminal** | **false** |

No dual claim in this sample was falsified as over-sealed. Residual risks are disclosed gaps (product English, callers/xrefs residual, runtime), not hidden contradictions.

---

## Artifacts written

- `docs/reconstruction/reviews/ADV_mega_spotcheck.md` (this file)
