# Review A (reconstruction fidelity): `aa_008ac890` UI_MissionDialog_SetResponseCountAndRebuild_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac890` |
| **VA** | `0x008ac890`–`0x008ac8af` exclusive |
| **Body size** | **31** B (`0x1F`) |
| **Canonical name** | `UI_MissionDialog_SetResponseCountAndRebuild_Inferred` |
| **Ghidra symbol** | `FUN_008ac890` |
| **Review date** | `2026-08-05` (MEGA-109 OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_008ac890_UI_MissionDialog_SetResponseCountAndRebuild_Inferred.md` |
| **System** | missions-progression / client UI mission dialog response chrome |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `disassemble_function`, `get_function_by_address`, `get_function_callers` / `get_xrefs_to`, `get_function_callees`, `read_memory` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

On mission dialog **this** (**ECX** → **EDI**), store requested response count from **EAX** into `dialog+0x510`, clamp to **max 8**, then call dualed peer **`UI_MissionDialog_BuildResponseButtons_Inferred`** (`FUN_008ac110`) to rebuild the NPC 2d response-button strip.

UI-only wrapper; no mission-state mutation, no packet send.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ MEGA-109 append) | `docs/reconstruction/raw/aa_008ac890_FUN_008ac890.md` |
| Annotated | `docs/reconstruction/raw/aa_008ac890_FUN_008ac890.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_MissionDialog_SetResponseCountAndRebuild_Inferred.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_008ac890.cpp` |
| Function records | `functions/aa_008ac890_FUN_008ac890.md`, `functions/aa_008ac890_UI_MissionDialog_SetResponseCountAndRebuild_Inferred.md` |
| Live decompile | CF ≡ raw store / clamp / call |
| Live body bytes | full 31 B via `read_memory` + `disassemble_function` |
| Peer dual | `A/B_aa_008ac110_UI_MissionDialog_BuildResponseButtons_Inferred` (WQ7R-B) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte seal

```
008ac890  83 F8 08                 CMP  EAX, 8
008ac893  57                      PUSH EDI
008ac894  8B F9                   MOV  EDI, ECX
008ac896  89 87 10 05 00 00       MOV  [EDI+0x510], EAX
008ac89c  7E 0A                   JLE  008ac8a8          ; count <= 8 → skip
008ac89e  C7 87 10 05 00 00 08 00 00 00
                                  MOV  [EDI+0x510], 8
008ac8a8  E8 63 F8 FF FF          CALL FUN_008ac110
008ac8ad  5F                      POP  EDI
008ac8ae  C3                      RET
008ac8af  CC                      INT3 pad → FUN_008ac8b0
```

### Primary call site (`FUN_008ac8b0` / NUM_RESPONSES)

```
008acafc  MOV  EAX, [ESP+0x20]    ; first %d from swscanf("%d;%d")
008acb00  MOV  ECX, EDI           ; dialog this
008acb02  CALL FUN_008ac890
```

### Third call site (`FUN_0093e450`)

```
0093e6e2  CALL FUN_005795b0       ; EAX = (end-begin)>>2 vector size
0093e6e7  MOV  ECX, EBX           ; dialog
0093e6e9  CALL FUN_008ac890
```

(Contrast early path in same parent: `MOV [EBX+0x510],1; CALL FUN_008ac110` — hardcodes count 1 without this wrapper.)

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body 31 B exclusive end `0x008ac8af` | **pass** |
| Store offset `+0x510` | **pass** (bytes + peer dual) |
| Clamp max **8** (`CMP`/`JLE`/`MOV imm`) | **pass** |
| Callee `0x008ac110` only | **pass** |
| ECX this + EAX count + bare RET | **pass** |
| 3 UNCONDITIONAL_CALL xrefs | **pass** |
| Product PDB name | **gap** (inferred) |
| Runtime / bit-exact | **gap** |

---

## 5. Naming

| Candidate | Status |
|---|---|
| `UI_MissionDialog_SetResponseCountAndRebuild_Inferred` | **Accepted inferred** — field dual + NUM_RESPONSES callers + rebuild peer |
| `Named_CalleeOf_Named_NUM_RESPONSE_COLUMNS_*` | **Retired** — misattributes to columns (`+0x640`); this unit is count (`+0x510`) |

---

## 6. Gaps

- Product / PDB English.
- Dual of callers `FUN_008ac8b0` / `FUN_0093e450` (not OWN).
- Why max 8 (design chrome capacity) — observed only as immediate.
- Runtime / differential.

---

## 7. Verdict

**accept-with-gaps** — CF/ABI/RET/clamp/field/peer fully sealed from live decompile + bytes + call sites; product plate open; no runtime Confirmed.
