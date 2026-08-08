# Review A (reconstruction fidelity): `aa_008aa490` MissionDialog_SetTurnInReadyFlag_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa490` |
| **VA** | `0x008aa490` |
| **Canonical name** | `MissionDialog_SetTurnInReadyFlag_Inferred` (Ghidra `FUN_008aa490`) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_008aa490_MissionDialog_SetTurnInReadyFlag_Inferred.md` |
| **System tag** | `missions-progression` |
| **Agent** | OWN-ONLY dual **MEGA-078** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Pre-present setup** on the NPC mission dialog host:

1. Store turn-in readiness **char** at `dialog+0x580`.
2. If optional child at `dialog+0x6e8` non-null: `vtbl[+4](flag)`.

Sole caller `Client_ShowNpcMissionDialogUI` invokes this immediately after `FUN_0052b420` (turn-in readiness) and before `Client_NpcDialog_PrepareResponseOpcode` / panel fill / reward chrome.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra | `decompile_function` + `analyze_function_complete` @ `0x008aa490` |
| Body bytes | `read_memory` length 32 → 23 B body + `CC` pad |
| Full disasm | `disassemble_function` (8 instructions; **no** `disassemble_bytes`) |
| Callers / xrefs | `get_function_callers` + `get_function_xrefs` + `get_xrefs_to` |
| Caller framing | `get_assembly_context` @ `00943a57`; decompile `Client_ShowNpcMissionDialogUI` |
| Flag source | decompile `FUN_0052b420` (turn-in readiness probe) |
| Raw | `docs/reconstruction/raw/aa_008aa490_FUN_008aa490.md` (+ MEGA-078 append) |
| Annotated | `docs/reconstruction/raw/aa_008aa490_FUN_008aa490.annotated.md` |
| Clean | `reconstructed-exact/MissionDialog_SetTurnInReadyFlag_Inferred.cpp` |
| Twin | `reconstructed-exact/FUN_008aa490.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 23 B / `0x17` | **High** | disasm end `C3` @ `008aa4a6`; hex match |
| EAX = dialog host | **High** | caller `MOV EAX,EBX` @ `00943a55` |
| DL = flag char | **High** | `MOV DL,[ESP+0x1c]`; store `MOV [EAX+0x580],DL` |
| No stack args / bare RET | **High** | ends `C3`; no `RET n` |
| `+0x580` flag store | **High** | `88 90 80 05 00 00` |
| `+0x6e8` child load | **High** | `8B 88 E8 06 00 00` |
| Optional `vtbl[+4]` | **High** | `PUSH EDX; CALL [EAX+4]` |
| Sole xref parent show UI | **High** | xrefs count 1 @ `00943a57` |
| Flag = turn-in readiness | **High** role | from `FUN_0052b420` path; product English open |
| Product field/method names | **Tentative** | `_Inferred` |
| Runtime | **Open** | Terminal false |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Raw | Live | Clean |
|---|---|---|---|
| Load child @ +0x6e8 | Yes | Yes | Yes |
| Store flag @ +0x580 | Yes | Yes | Yes |
| Null-check child / JZ | Yes | Yes | Yes |
| PUSH flag + vcall +4 | Yes | Yes | Yes |
| Bare RET | Yes | Yes | Yes |
| Invented branches | — | — | **None** |

**Result:** Clean CF ≡ raw ≡ live Ghidra. ABI corrected from decompiler `in_EAX` / fake `__fastcall` formals via assembly + call site.

---

## 5. Assembly seals (no disassemble_bytes)

| Bytes | Meaning |
|---|---|
| `8B 88 E8 06 00 00` | `MOV ECX,[EAX+0x6e8]` |
| `85 C9` | `TEST ECX,ECX` |
| `88 90 80 05 00 00` | `MOV [EAX+0x580],DL` |
| `74 06` | `JZ` skip notify |
| `8B 01` / `52` / `FF 50 04` | vtbl load, push EDX, call [+4] |
| `C3` | bare RET |

### Caller seal

```
00943a43  CALL 0x0052b420
00943a48  TEST AL,AL
00943a4a  JZ   0x00943a51
00943a4c  MOV  byte ptr [ESP+0x1c],0x1
00943a51  MOV  DL,byte ptr [ESP+0x1c]
00943a55  MOV  EAX,EBX
00943a57  CALL 0x008aa490
00943a5c  … PrepareResponseOpcode / panel fill …
```

---

## 6. Gaps

1. Product/PDB name for dialog host class.
2. Product names for fields `+0x580` / `+0x6e8` and child `vtbl[+4]`.
3. Whether EDX upper bits are contractually zero at the child vcall.
4. Runtime / bit-exact / differential.

---

## 7. Verdict

**accept-with-gaps** — CF/ABI/offsets/sole-caller pre-present role sealed; product English open. Terminal **false**.
