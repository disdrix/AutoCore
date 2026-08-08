# Review A (reconstruction fidelity): `aa_008aa510` MissionDialog_StampResponseSlot_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa510` |
| **VA** | `0x008aa510` |
| **Canonical name** | `MissionDialog_StampResponseSlot_Inferred` (Ghidra `FUN_008aa510`) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_008aa510_MissionDialog_StampResponseSlot_Inferred.md` |
| **System tag** | `missions-progression` |
| **Work item** | MEGA-046 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Stamp **one** mission-dialog **response-button slot**:

1. Bounds: `0 <= ESI < dialog+0x510`.
2. If widget `dialog+0x708+ESI*4` non-null: `vtbl+0x1d8(caption,1,1)` then `vtbl+0x34c()`.
3. Write TFID pair to `dialog+0x518+ESI*8` / `+0x51c`.

Inverse of dualed wipe `MissionDialog_ClearResponseButtonSlots_Inferred` (`0x008aa560`). Callers rebuild chrome via `FUN_008ac110` then stamp captions/TFIDs here.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra | `decompile_function` + `analyze_function_complete` @ `0x008aa510` |
| Body bounds | `get_function_by_address` → `008aa510`–`008aa55b` |
| Assembly | `disassemble_function` (full body; no `disassemble_bytes`) |
| Full bytes | `read_memory` length 96 (body 75 B + pad into clear) |
| Callers | `get_function_callers` + `get_function_xrefs` (6 sites) |
| Call framing | `get_assembly_context` @ all 6 xrefs |
| Caption strings | `read_memory` @ `a2d328`/`a2d330`/`a2d338`/`a2d33c`/`a2d364` |
| Parent decompiles | `Client_ShowNpcMissionDialogUI` @ `009438f0`; `FUN_0093e450` @ `0093e450` |
| Raw (+ MEGA-046 append) | `docs/reconstruction/raw/aa_008aa510_FUN_008aa510.md` |
| Annotated | `docs/reconstruction/raw/aa_008aa510_FUN_008aa510.annotated.md` |
| Clean | `reconstructed-exact/MissionDialog_StampResponseSlot_Inferred.cpp` |
| Twin | `reconstructed-exact/FUN_008aa510.cpp` |
| Peer dual | `A/B_aa_008aa560_MissionDialog_ClearResponseButtonSlots_Inferred.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 75 B / `0x4B` | **High** | bounds + full hex + `RET 8` + `CC` pad |
| EDI = dialog host | **High** | all callers `MOV EDI,EBX` (or keep EDI=EBX) |
| ESI = slot index | **High** | `XOR ESI,ESI` / `MOV ESI,1` / loop ESI |
| EDX = caption C-string | **High** | `MOV EDX,imm` string VAs; `PUSH EDX` → vtbl+0x1d8 |
| Stack TFID lo/hi + `RET 8` | **High** | `MOV ECX/EDX,[ESP+4/8]`; bytes `C2 08 00` |
| Bounds vs `+0x510` | **High** | `CMP ESI,[EDI+0x510]` / `JGE` out |
| Widget bank `+0x708` | **High** | shared with dualed clear |
| TFID bank `+0x518/+0x51c` | **High** | shared with dualed clear |
| vtbl+0x1d8 set-text role | **High** role / **Tentative** product name | captions "Accept"/"Decline"/… |
| vtbl+0x34c refresh role | **High** role / **Tentative** product name | always follows set-text |
| 6 call sites only | **High** | xrefs count 6 |
| Product function name | **Open** | `_Inferred` |
| Dynamic TFID domain | **Tentative** | from `FUN_0057a250` in choice loop |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Raw | Live | Clean |
|---|---|---|---|
| ESI < 0 early out | Yes | Yes | Yes |
| ESI ≥ count early out | Yes | Yes | Yes |
| Null widget skip caption | Yes | Yes | Yes |
| vtbl+0x1d8(caption,1,1) | Yes | Yes | Yes |
| vtbl+0x34c refresh | Yes | Yes | Yes |
| TFID lo/hi stores | Yes | Yes | Yes |
| Invented branches | — | — | **None** |

**Result:** Clean CF ≡ raw ≡ live Ghidra.

---

## 5. Assembly seals (no disassemble_bytes)

| Bytes / insn | Meaning |
|---|---|
| `85 F6` / `7C 45` | `TEST ESI,ESI` / `JL out` |
| `3B B7 10 05 00 00` | `CMP ESI,[EDI+0x510]` |
| `8B 8C B7 08 07 00 00` | `MOV ECX,[EDI+ESI*4+0x708]` |
| `6A 01 6A 01 52` | push 1,1,EDX |
| `FF 90 D8 01 00 00` | `CALL [EAX+0x1D8]` |
| `FF 90 4C 03 00 00` | `CALL [EAX+0x34C]` |
| `8B 4C 24 04` / `8B 54 24 08` | load stack TFID |
| `89 8C F7 18 05 00 00` | store lo @ `+0x518` |
| `89 94 F7 1C 05 00 00` | store hi @ `+0x51c` |
| `C2 08 00` | `RET 8` |

### Caller seals (sample)

```
; Accept/Decline pair in Client_ShowNpcMissionDialogUI
00943b2e  MOV [EBX+0x510], 2
00943b38  CALL 0x008ac110          ; rebuild widgets
00943b3d  PUSH -1 / PUSH -1
00943b41  MOV EDX, 0xa2d330        ; "Accept"
00943b46  XOR ESI, ESI
00943b48  CALL 0x008aa510          ; slot 0
00943b4d  PUSH -1 / PUSH -1
00943b51  MOV EDX, 0xa2d328        ; "Decline"
00943b56  MOV ESI, 1
00943b5b  CALL 0x008aa510          ; slot 1
```

```
; No-choices path in FUN_0093e450
0093e6ad  MOV [EBX+0x510], 1
0093e6b7  CALL 0x008ac110
0093e6bc  PUSH -1 / PUSH -1
0093e6c0  MOV EDX, 0xa2d364        ; "Work in progress"
0093e6c5  XOR ESI, ESI
0093e6c7  CALL 0x008aa510
```

---

## 6. Gaps

1. Product/PDB symbol English.
2. Product names for vtbl+0x1d8 / +0x34c.
3. Dynamic choice TFID semantics (`FUN_0057a250` residual).
4. Runtime / bit-exact / differential.

---

## 7. Verdict

**accept-with-gaps** — single-slot stamp CF, EDI/ESI/EDX+RET8 ABI, shared +0x518/+0x708 banks, caption string seals, and 6 call sites sealed; product English and dynamic TFID domain open. No runtime Confirmed.
