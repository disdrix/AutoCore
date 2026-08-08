# Review A (reconstruction fidelity): `aa_009430f0` Client_OnLocalCharacterReady_EnterWorldSetup_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009430f0` |
| **VA** | `0x009430f0`–`0x009432eb` inclusive (**508 B** / `0x1FC`) |
| **Canonical name** | `Client_OnLocalCharacterReady_EnterWorldSetup_Inferred` |
| **Ghidra name** | `FUN_009430f0` |
| **Prior scaffold** | `FUN_009430f0` / `Named_CalleeOf_Client_RecvCreateCharacter_009430f0` |
| **Rejected misname** | freestanding `void(void)` with no host; pure CreateCharacter-only helper; stack-arg thiscall |
| **Review date** | `2026-08-05` (R10-017 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_009430f0_Client_OnLocalCharacterReady_EnterWorldSetup_Inferred.md` |
| **System** | client enter-world / local character ready (partition residual tag: skills-abilities) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_function_xrefs` + `get_function_by_address` + `get_function_signature` + `get_function_hash` + caller/callee decompiles. **No** `disassemble_bytes`. No Launcher. `analyze_function_complete` unavailable on this instance (`Function not found: null`).

---

## 1. Purpose

Client **local-character-ready / enter-world setup** orchestrator:

```text
Client_OnLocalCharacterReady_EnterWorldSetup_Inferred()  // ESI=client
  FUN_004d9f00(worldRoot)                 // world enter object scan
  env+0x8c = 1
  optional FUN_004962b0(worldRoot+0xe898)
  if camera (client+0xf38):
    FUN_00923c50(cam)
    optional cam vfuncs (+0x318, sub+0xfc)
    cam+0xcc4 = 6; flags; vfunc+0x3c4(1)
    cam+0x530 = 10.0f or ~6.7f (worldRoot+0xf5)
    copy client+0x9d1 → cam+0xa83; clear client+0x31d9
  if tip gates: Client_MaybeShowFirstTimeTip ×3 (+ optional 0x30 via CNDHash)
  FUN_009301b0(client)                    // UI panel cascade
  if char bitfields incomplete & chat gate clear:
    FUN_00941fb0(..., "//rejoinchat", mode=3); FUN_00941fb0(..., mode=1)
  optional client+0x4d0+4=1; DAT_00d1ad1c=0; client+0xb6=0; +0xb7=1
```

Not a frame-tick body (adjacent dualed parent `0x00942e20` ends exclusive at this VA). Not CreateCharacter-packet parse (that is the parent receiver).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw CF; understates ESI host |
| Full body | `disassemble_function` 126 instr + `read_memory` 508 B |
| Hash | `1ad832af581bdcc60c4b4a75caf7bcfa85e02bf1830345b6fdc33c2df2316299` |
| Callers | 3 sites / 2 parents (`Client_RecvCreateCharacter`, `FUN_00946c00` ×2) |
| Floats | `read_memory` DAT_00a110d8=10.0f, DAT_00aaaccc≈6.7f |
| String | `"//rejoinchat"` @ `0x00a2cff8` |
| Clean | `reconstructed-exact/Client_OnLocalCharacterReady_EnterWorldSetup_Inferred.cpp` |

---

## 3. Signature (sealed)

```c
// ESI = client/session host; no stack args; bare RET; void
void Client_OnLocalCharacterReady_EnterWorldSetup_Inferred(void);
```

| Formal | Source | Conf |
|---|---|---|
| client host | **ESI** (all ` [ESI+imm] `) | **High** |
| stack args | none — epilog `POP EBX; POP ECX; RET` | **High** |
| return | void | **High** |
| EBX | zeroed scratch (`XOR EBX,EBX`) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Prologue PUSH ECX/EBX; CALL 004d9f00 | bytes | **High** |
| env+0x8c = 1 via worldRoot+0xe894 | bytes | **High** |
| Optional 004962b0 gate | CF | **High** |
| Camera block mode=6 + MOVSS zoom | disasm `MOVSS` | **High** |
| Tips 0x19/0x17/0x31 + optional 0x30 | PUSH imm + CALL 00801760 | **High** |
| CNDHash path 00541a80→005b0920 | disasm | **High** |
| UI refresh 009301b0 (EAX=ESI) | `MOV EAX,ESI; CALL` | **High** |
| Rejoinchat dual FUN_00941fb0 | string + modes 3/1 | **High** |
| Final flags + bare RET | bytes `5B 59 C3` | **High** |

---

## 5. Machine bytes (`read_memory`)

- Prologue: `51 8B 8E 04 0E 00 00 53 E8 03 6E B9 FF …`
- Epilogue: `5B 59 C3` (`POP EBX; POP ECX; RET`)
- Zoom: `F3 0F 10 05 D8 10 A1 00` / `… CC AC AA 00` + `MOVSS [reg+0x530],XMM0`
- Body size sealed: **508 B** (`0x009432eb − 0x009430f0 + 1`)

---

## 6. Callers (sealed)

| Site | Parent | Notes |
|---|---|---|
| `0x00814959` | `Client_RecvCreateCharacter` | Extended local create after quickbar; in_AL path |
| `0x00946ceb` | `FUN_00946c00` | switch case 3; `MOV ESI,EBX` |
| `0x009477ae` | `FUN_00946c00` | queue type 0x1e; `MOV ESI,EBX` |

---

## 7. Gaps

- Product English for camera / worldRoot / tip IDs / case-3 / 0x1e.
- `0x00a1419b` string identity for FUN_00941fb0 param_1.
- Full semantics of undualed callees (004d9f00, 00923c50, 009301b0, 00941fb0).
- Runtime / bit-exact / differential.
- Partition `skills-abilities` is residual adjacency to dualed frame-tick parent — not a static call edge.

---

## 8. Verdict rationale

**accept-with-gaps**: CF, ABI (ESI host, bare RET), body size, callers, floats, string, and staged semantics sealed from live tools. Product-level English and undualed helper depth remain open → `_Inferred` retained.
