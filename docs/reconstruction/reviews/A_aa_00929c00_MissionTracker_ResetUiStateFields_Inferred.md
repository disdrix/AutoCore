# Review A (reconstruction fidelity): `aa_00929c00` MissionTracker_ResetUiStateFields_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00929c00` |
| **VA** | `0x00929c00`–`0x00929c50` inclusive (**81 B** / `0x51`) |
| **Canonical name** | `MissionTracker_ResetUiStateFields_Inferred` |
| **Ghidra name** | `FUN_00929c00` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-087) |
| **Counterpart** | `reviews/B_aa_00929c00_MissionTracker_ResetUiStateFields_Inferred.md` |
| **System** | missions-progression / mission-tracker UI state |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` (body 81 B + `DAT_00aaa6fc`) + callers/xrefs + parent call-site disasm (`FUN_0092a590`, `FUN_0092c080`). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leaf **tracker UI/state field reset**: write default sentinels and zero flags on the mission-tracker object, restore default range float **25.0f**, return `1`. Used when clearing active mission bind and when tracker region context changes.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-087 append) | `docs/reconstruction/raw/aa_00929c00_FUN_00929c00.md` |
| Annotated | `docs/reconstruction/raw/aa_00929c00_FUN_00929c00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionTracker_ResetUiStateFields_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00929c00.cpp` |
| Function records | `aa_00929c00_FUN_00929c00.md`, `aa_00929c00_MissionTracker_ResetUiStateFields_Inferred.md` |
| Related duals (read-only) | `Client_TryBindActiveMissionTracker` `aa_0092fd00`; `Client_MissionTrackerHud_Refresh_Inferred` `aa_008a8770` |
| Live | decompile ≡ raw CF ≡ full-body hex; ABI sealed via disasm + call sites |

---

## 3. Signature (sealed)

```c
// EAX = tracker*; no stack formals; AL = 1; bare C3
uint8_t __register MissionTracker_ResetUiStateFields_Inferred(void *tracker /*EAX*/);
```

| Formal | Source | Conf |
|---|---|---|
| tracker | **EAX** (`MOV EAX,EDI/ESI` at callers; decompiler `in_EAX`) | **High** |
| return | `AL = 1` (`B0 01`) | **High** |
| cleanup | bare `C3` | **High** |
| stack formals | none | **High** |
| ECX thiscall | **falsified** — ECX used only as zero scratch (`XOR ECX,ECX`) | **High** |

---

## 4. Control flow (bytes authority)

```
MOVSS XMM0,[DAT_00aaa6fc]     ; 25.0f
XOR   ECX,ECX                 ; zero
OR    EDX,0xFFFFFFFF          ; -1
[EAX+0x18] = EDX
[EAX+0x20] = EDX
[EAX+0x24] = EDX
[EAX+0x54] = ECX
[EAX+0x80] = ECX
[EAX+0xac] = ECX
[EAX+0x28] = ECX
[EAX+0x100..0x102] = CL
[EAX+0x104] = XMM0            ; float store
[EAX+0x108] = EDX
[EAX+0x10c] = EDX
AL = 1
RET
```

| Stage | Match | Conf |
|---|---|---|
| Single BB / no branches | `analyze_function_complete` BB=1, edges=0 | **High** |
| Leaf (0 callees) | analyze + disasm | **High** |
| Decompile ≡ raw 2026-07-23 | identical stores + return 1 | **High** |
| MOVSS float path | disasm + `read_memory` DAT `00 00 C8 41` | **High** |
| Pad after RET | `CC` fill before next function | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 81 B hex — see raw MEGA-087 append.  
Entry: `F3 0F 10 05 FC A6 AA 00 …`  
Epilogue: `B0 01 C3`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | **leaf** worker (tracker UI/state companion) |
| Code callers | `FUN_0092a590` ×2; `FUN_0092c080` ×1 |
| DATA xrefs | none |
| Parent chain | dualed `Client_TryBindActiveMissionTracker` → `FUN_0092a590`; `FUN_0092c640` → `FUN_0092c080` |
| Object home | tracker at **client+0x4d0** (sealed by dualed bind clean + parent plate) |

Call-site authority (`disassemble_function` on `FUN_0092a590`):

```
0092a5a6  MOV EAX,EDI
0092a5a8  CALL 0x00929c00
…
0092a5ed  MOV EAX,EDI
0092a5ef  CALL 0x00929c00
```

---

## 7. Name decision

| Candidate | Result |
|---|---|
| `Named_CalleeOf_*MissionDial*` | **Reject** — seed plate; not dialog-button primary |
| `MissionTracker_Init` / ctor | **Reject** — partial field write only; not full object ctor |
| `MissionTracker_ResetUiStateFields_Inferred` | **Accept** — role from parents + field plate; product English open → `_Inferred` |

---

## 8. Gaps (non-blocking)

- Product English for each offset (HUD range vs waypoint TFID vs region key).
- Formal RTTI / C++ class name of tracker blob.
- Dual seal of residual parents `0092a590` / `0092c080` / `0092a3d0`.
- Runtime / bit-exact / differential.

---

## 9. Verdict rationale

CF, ABI (EAX object + bare RET + AL=1), body range, float constant, and caller wiring are **image-sealed**. Role as mission-tracker UI/state reset companion is **High** via dualed bind path and partition hint. Product field dictionary remains open → **accept-with-gaps** (not reject: no CF/ABI conflict).
