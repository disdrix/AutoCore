# Review A (reconstruction fidelity): `aa_0092f090` MissionUI_ParkDriveAxes_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092f090` |
| **VA** | `0x0092f090`–`0x0092f0d1` (**66 B** / `0x42`) |
| **Canonical name** | `MissionUI_ParkDriveAxes_Inferred` |
| **Ghidra name** | `FUN_0092f090` |
| **Prior names** | `Named_CalleeOf_Client_ShowNpcMissionDialogUI_0092f090` (retired) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-021) |
| **Counterpart** | `reviews/B_aa_0092f090_MissionUI_ParkDriveAxes_Inferred.md` |
| **System** | `input-drive-control` |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` @ 5 sites. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Mission / NPC dialog UI **drive-axis park**: if the client host has a character and a vehicle entity, force **thr=0**, **steer=0**, **handbrake=1** through the dualed `VehicleEntity_*` setters. Shared by `Client_ShowNpcMissionDialogUI` and dialog-case dispatcher `FUN_0093e450`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-021 append) | `docs/reconstruction/raw/aa_0092f090_FUN_0092f090.md` |
| Annotated | `docs/reconstruction/raw/aa_0092f090_FUN_0092f090.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionUI_ParkDriveAxes_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0092f090.cpp` |
| Function records | `functions/aa_0092f090_FUN_0092f090.md` + named |
| Live decompile | Ghidra `decompile_function` `0x0092f090` |
| Live listing | `disassemble_function` `0x0092f090` |
| Live bytes | `read_memory` 80 B @ entry (66 B body + `CC` pad) |
| Call sites | `get_assembly_context` @ `00943989`, `00943b72`, `0093e6ce`, `0093e745`, `0093e76f` |
| Parents (evidence only) | `Client_ShowNpcMissionDialogUI`, `FUN_0093e450` decompiles |
| Callees (dualed) | SetLongitudinalInput / SetSteerInput / SetHandbrake |

**Not performed:** `disassemble_bytes`, Launcher, runtime Confirmed, dual of parents.

---

## 3. Body (listing seals)

```text
0092f090  MOV  EAX,[ESI+0xe98]
0092f096  TEST EAX,EAX / JZ ret
0092f09a  MOV  ECX,[EAX+0x250]
0092f0a0  TEST ECX,ECX / JZ ret
0092f0a4  PUSH 0 / CALL 0x004f5650     ; SetLongitudinalInput(0)
0092f0ab  MOV  EAX,[ESI+0xe98]
0092f0b1  MOV  ECX,[EAX+0x250]
0092f0b7  PUSH 0 / CALL 0x004f5620     ; SetSteerInput(0)
0092f0be  MOV  ECX,[ESI+0xe98]
0092f0c4  MOV  ECX,[ECX+0x250]
0092f0ca  PUSH 1 / CALL 0x004f3620     ; SetHandbrake(1)
0092f0d1  RET
```

Live decompile CF ≡ frozen raw 2026-07-23 ≡ live 2026-08-05.  
Body hex 66 B sealed; pad `CC` after RET.

---

## 4. ABI / signature (High)

```c
// Retail: ESI = client host; no stack args; bare RET (C3)
void MissionUI_ParkDriveAxes_Inferred(void);
```

| Formal | Source | Conf |
|---|---|---|
| client host | **ESI** (`[ESI+0xe98]`; callers `MOV ESI,EBP`) | **High** |
| stack | none | **High** |
| return | void; bare `C3` | **High** |
| ECX-thiscall for this unit | **No** (ECX only for nested vehicle setters) | **High** |

---

## 5. Control flow (bytes authority)

| Stage | Match | Conf |
|---|---|---|
| Character load `+0xe98` | `8B 86 98 0E 00 00` | **High** |
| Null character early-out | `TEST EAX` / `JZ ret` | **High** |
| Vehicle load `+0x250` | `8B 88 50 02 00 00` | **High** |
| Null vehicle early-out | `TEST ECX` / `JZ ret` | **High** |
| thr=0 via `0x004f5650` | `6A 00` / rel32 → SetLongitudinal | **High** |
| steer=0 via `0x004f5620` | `6A 00` / rel32 → SetSteer | **High** |
| HB=1 via `0x004f3620` | `6A 01` / rel32 → SetHandbrake | **High** |
| Bare RET | `C3` | **High** |
| Reload vehicle between calls | three reload sequences | **High** |

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Static callees | 3 dualed vehicle setters |
| Code callers | **2 functions / 5 sites** |
| Sites | ShowNpcMissionDialogUI ×2; FUN_0093e450 ×3 |
| Xrefs | 5× UNCONDITIONAL_CALL |

---

## 7. Gaps

1. Product English for ESI client-host class.  
2. Product English for residual parent `FUN_0093e450`.  
3. Interaction when thr/steer setters suppress under 0xC7 while HB still writes.  
4. Runtime / bit-exact / differential — open.  
5. Sibling axis-park units (`0x009373e0` dialog, `0x005d73a0` AI, etc.) not dualled here.

---

## 8. Verdict

CF/ABI/ESI/offsets/callees/5 call sites sealed against live image. Product host English and runtime open → **accept-with-gaps**. Terminal **false**.
