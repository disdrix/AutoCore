# Review A (reconstruction fidelity): `aa_0092a590` Tracker_SetActiveMissionObjective_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092a590` |
| **VA** | `0x0092a590`–`0x0092a5fe` (**111 B** / `0x6F`) |
| **Canonical name** | `Tracker_SetActiveMissionObjective_Inferred` |
| **Ghidra name** | `FUN_0092a590` |
| **Prior names** | `Named_CalleeOf_Named_CalleeOf_Client_MissionDialogHandleButton_0092a590` (**retired**) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-010) |
| **Counterpart** | `reviews/B_aa_0092a590_Tracker_SetActiveMissionObjective_Inferred.md` |
| **System** | `missions-progression` |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_function_xrefs` + `analyze_control_flow` + `get_assembly_context` @ `0x0092fd4c`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Bind or clear the **active mission objective** on the client mission tracker (`client+0x4d0`):

- Always write `tracker+0x10 = missionId` and `tracker+0x6 = 1`.
- **missionId == 0:** clear objective vector + display fields; zero `+0x10`/`+0xc`; return **1**.
- **missionId != 0:** resolve character via `(*tracker)+0xe98`; `CNDHash_LookupByKey(char+0x548, id)`; on hit stamp `tracker+0xc = **(node+0x14c)`, set `tracker+0x4 = 1`, return **1**.
- Miss / null character: same clear as zero-id, return **0**.

Sole caller: dualed parent `Client_TryBindActiveMissionTracker` (`0x0092fd00`) after eligibility gate.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-010 append) | `docs/reconstruction/raw/aa_0092a590_FUN_0092a590.md` |
| Annotated | `docs/reconstruction/raw/aa_0092a590_FUN_0092a590.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Tracker_SetActiveMissionObjective_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0092a590.cpp` |
| Function records | `functions/aa_0092a590_FUN_0092a590.md` + named |
| Live decompile | Ghidra `decompile_function` `0x0092a590` |
| Live listing | `disassemble_function` `0x0092a590` |
| Live bytes | `read_memory` 120 B @ entry |
| Call site | `get_assembly_context` @ `0x0092fd4c` |
| Parent (evidence only) | dualed `Client_TryBindActiveMissionTracker` + live decompile `0x0092fd00` |
| Callees (evidence) | `FUN_0092a3d0`, `FUN_00929c00`, `CNDHash_LookupByKey` decompiled |

**Not performed:** `disassemble_bytes`, Launcher, runtime Confirmed, dual of residual clear helpers.

---

## 3. Body (listing seals)

```text
0092a590  PUSH ESI / PUSH EDI
0092a592  MOV  EDI,ECX                 ; tracker
0092a594  XOR  ESI,ESI
0092a596  CMP  EAX,ESI
0092a598  MOV  [EDI+0x10],EAX          ; activeMissionId
0092a59b  MOV  byte [EDI+0x6],1        ; dirty
0092a59f  JNZ  lookup
; clear success (id==0)
0092a5a1  CALL FUN_0092a3d0            ; EDI=tracker
0092a5a6  MOV  EAX,EDI
0092a5a8  CALL FUN_00929c00            ; EAX=tracker
0092a5ad  MOV  [EDI+0x10],ESI / MOV [EDI+0xc],ESI
0092a5b3  POP EDI / MOV AL,1 / POP ESI / RET
; lookup
0092a5b8  MOV  ECX,[EDI] / MOV ECX,[ECX+0xe98]
0092a5c0  CMP  ECX,ESI / JZ fail
0092a5c4  MOV  ECX,[ECX+0x548] / PUSH EAX
0092a5cb  CALL CNDHash_LookupByKey     ; 0x005b0920
0092a5d0  CMP  EAX,ESI / JZ fail
0092a5d4  MOV  EDX,[EAX+0x14c] / MOV EAX,[EDX]
0092a5dc  MOV  [EDI+0xc],EAX
0092a5df  MOV  byte [EDI+0x4],1
0092a5e3  POP EDI / MOV AL,1 / POP ESI / RET
; fail clear
0092a5e8  CALL FUN_0092a3d0 / MOV EAX,EDI / CALL FUN_00929c00
0092a5f4  MOV  [EDI+0x10],ESI / MOV [EDI+0xc],ESI
0092a5fa  POP EDI / XOR AL,AL / POP ESI / RET
```

Live decompile CF ≡ frozen raw 2026-07-23 ≡ live 2026-08-05.  
Body hex 111 B sealed; pad `CC` @ `0x0092a5ff`.

---

## 4. ABI / signature (High)

```c
// Retail: ECX = tracker; EAX = missionId; AL = bool; bare RET (C3)
char __fastcall Tracker_SetActiveMissionObjective_Inferred(
    MissionTracker* tracker /*ECX*/,
    uint32_t missionId /*EAX*/);
```

| Formal | Source | Conf |
|---|---|---|
| tracker | **ECX** → EDI (`MOV EDI,ECX`; parent `MOV ECX,[EDI+0x4d0]`) | **High** |
| missionId | **EAX** (`CMP EAX,ESI`; parent `MOV EAX,EBX`) | **High** |
| return | **AL** bool (`MOV AL,1` / `XOR AL,AL`) | **High** |
| stack | none; bare `C3` ×3 | **High** |
| pure ECX-thiscall only | **No** — EAX carries missionId | **High** |

---

## 5. Control flow (bytes authority)

| Stage | Match | Conf |
|---|---|---|
| Stamp `+0x10` / `+0x6` | `89 47 10` / `C6 47 06 01` | **High** |
| Zero-id clear → 1 | CALL pair; zero fields; `B0 01` | **High** |
| Character via `*tracker+0xe98` | `8B 0F` / `8B 89 98 0E 00 00` | **High** |
| Hash `char+0x548` + push key | `8B 89 48 05 00 00` / `50` | **High** |
| Objective head `node+0x14c` | `8B 90 4C 01 00 00` / `8B 02` / `89 47 0C` | **High** |
| Bind flag `+0x4` | `C6 47 04 01` | **High** |
| Fail → 0 | clear pair; `32 C0` | **High** |
| 3 returns / no loops | CF metrics | **High** |

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Code callers | **1** — `FUN_0092fd00` / `Client_TryBindActiveMissionTracker` @ `0x0092fd4c` |
| Xrefs | 1× UNCONDITIONAL_CALL |
| Callees | `FUN_0092a3d0`, `FUN_00929c00`, `CNDHash_LookupByKey` |
| Parent sequence | gate hash+`FUN_0059dc50` (non-zero) → **this** → optional UI `vtbl+0x3d8`/`+0x448` |

---

## 7. Confidence

| Claim | Confidence |
|---|---|
| Role = bind/clear active mission objective on tracker | **High** (parent dual + CF) |
| ECX/EAX/AL ABI | **High** (call-site sealed) |
| Offsets `+0x10`, `+0xc`, `+0x6`, `+0x4`, host `+0xe98`, hash `+0x548`, node `+0x14c` | **High** |
| Clear helpers EDI/EAX custom ABI | **High** (call setup in body) |
| Product English for tracker / objective-head | **Open** → `_Inferred` |
| Runtime | **Open** |

---

## 8. Gaps

1. Product class name for tracker at `client+0x4d0`.  
2. Product English for `node+0x14c` payload (objective list head vs primary objective*).  
3. Named duals for residual clear helpers `FUN_0092a3d0` / `FUN_00929c00`.  
4. Runtime / bit-exact / differential — open.  

**Verdict:** **accept-with-gaps** — ABI + CF + offsets + sole-caller role sealed; product English open. Terminal **false**.
