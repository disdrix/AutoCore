# Review A (reconstruction fidelity): `aa_009373e0` Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009373e0` |
| **VA** | `0x009373e0`–`0x00937462` (**131 B** / `0x83`) |
| **Canonical name** | `Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred` |
| **Ghidra name** | `FUN_009373e0` |
| **Prior names** | scaffold `FUN_009373e0` only (no Named_CalleeOf_*) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-024) |
| **Counterpart** | `reviews/B_aa_009373e0_Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred.md` |
| **System** | `input-drive-control` |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_xrefs` / `get_xrefs_to` + `get_assembly_context` @ `0x00952b25` + dualed callee plates. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **dialog-host gate** worker: when `client+0xf40` is non-null and `**(client+0xf40) == *(client+0xf38)`, open dialog table index **10**, stamp/clear the mission-dialog caption host at `client+0x1058` from the stack formal, then if a vehicle entity is linked (`client+0xe98` → `+0x250`) **park drive axes** — longitudinal **0**, steer **0**, handbrake **1**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-024 append) | `docs/reconstruction/raw/aa_009373e0_FUN_009373e0.md` |
| Annotated | `docs/reconstruction/raw/aa_009373e0_FUN_009373e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_009373e0.cpp` |
| Function records | `functions/aa_009373e0_FUN_009373e0.md` + named |
| Live decompile | Ghidra `decompile_function` `0x009373e0` |
| Live listing | `disassemble_function` `0x009373e0` |
| Live bytes | `read_memory` 128 B @ entry + tail @ `0x00937450` |
| Call site | `get_assembly_context` @ `0x00952b25` / `0x00952b20` |
| Callees | dualed `Client_OpenDialogByIndex`, `MissionDialog_SetNpcObjectAndNameCaption_Inferred`, vehicle setters |

**Not performed:** `disassemble_bytes`, Launcher, runtime Confirmed, dual of caller stub / dialog index enum.

---

## 3. Body (listing seals)

```text
009373e0  MOV  EAX,[EDI+0xf40] / TEST / JZ exit
009373ea  MOV  EAX,[EAX] / CMP [EDI+0xf38] / SETZ / TEST / JZ exit
009373f9  PUSH ESI
009373fa  PUSH 0 / PUSH 0 / PUSH 0xA
00937400  MOV  ECX,EDI
00937402  CALL Client_OpenDialogByIndex          ; index 10
00937407  MOV  EAX,[ESP+8]                       ; stack formal
0093740b  MOV  ESI,[EDI+0x1058]
00937411  CALL MissionDialog_SetNpcObject…     ; ESI/EAX custom
00937416  MOV  EAX,[EDI+0xe98] / TEST / POP ESI / JZ exit
00937421  MOV  EAX,[EAX+0x250] / TEST / JZ exit
0093742b  PUSH 0 / MOV ECX,EAX / CALL SetLongitudinalInput
00937434  reload vehicle / PUSH 0 / CALL SetSteerInput
00937447  reload vehicle / MOV [ESP+4],1 / JMP SetHandbrake  ; HB=1 tail
00937460  RET 4
```

Live decompile CF ≡ frozen raw 2026-07-23 for control structure.  
Machine corrects scaffold ABI (RET 4, stack formal, HB=1 tail).  
Body hex 131 B sealed; pad `CC` after `0x00937462`.

---

## 4. ABI / signature (High)

```c
// Retail: EDI = Client*; stack dword stamp; RET 4 (C2 04 00)
void Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred(Client* client /*EDI*/,
                                                          int npcOrClear);
```

| Formal | Source | Conf |
|---|---|---|
| client | **EDI** (body uses EDI offsets; caller `MOV EDI,ECX`) | **High** |
| npcOrClear | stack dword; `MOV EAX,[ESP+8]` after ESI push → `008aa4b0` | **High** |
| return | void; early `RET 4`; vehicle path tail-returns via SetHandbrake `RET 4` | **High** |
| ECX-thiscall on entry | **No** (ECX only nested) | **High** |

---

## 5. Control flow (bytes authority)

| Stage | Match | Conf |
|---|---|---|
| Gate `+0xf40` null check | `8B 87 40 0F 00 00` / `TEST` / `JZ` | **High** |
| Gate `**f40 == *f38` | `8B 00` / `3B 87 38 0F 00 00` / `SETZ` | **High** |
| Open dialog index 10 | `6A 00 6A 00 6A 0A` / `MOV ECX,EDI` / `CALL 007fef20` | **High** |
| Caption ESI=`+0x1058`, EAX=stack | `8B 44 24 08` / `8B B7 58 10 00 00` / `CALL 008aa4b0` | **High** |
| Vehicle `e98` / `+0x250` | loads + dual `TEST`/`JZ` | **High** |
| thr0 / steer0 | `PUSH 0` + `CALL 004f5650` / `004f5620` | **High** |
| HB=1 tail | `C7 44 24 04 01 00 00 00` / `E9 … → 004f3620` | **High** |
| Epilogue `RET 4` | `C2 04 00` | **High** |

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Code callers | **1** site @ `0x00952b25` (thin stub `0x00952b20`: push 0, EDI=ECX, call, return 1, `RET 8`) |
| Xrefs | 1× UNCONDITIONAL_CALL |
| Callees | `007fef20`, `008aa4b0`, `004f5650`, `004f5620`, `004f3620` |

---

## 7. Gaps

1. Product English for dialog index **10**.  
2. Product name / class of vmethod stub @ `0x00952b20` (why two stack formals / RET 8).  
3. Product English for `f40`/`f38` host equality beyond structural gate.  
4. Sibling pure-park `0x0092f090` residual (MEGA-021 partition).  
5. Runtime / bit-exact / differential — open.

---

## 8. Verdict

CF/ABI/EDI-host/dialog-index-10/caption ESI+0x1058/vehicle thr0+steer0+HB1/tail-JMP/sole-caller sealed. Product dialog-slot English residual → **accept-with-gaps**. Terminal **false**.
