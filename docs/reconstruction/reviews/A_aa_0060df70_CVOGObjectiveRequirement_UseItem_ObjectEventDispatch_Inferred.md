# Review A (reconstruction fidelity): `aa_0060df70` CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060df70` |
| **VA** | `0x0060df70`–`0x0060e06a` (**251 B** / `0xFB`) |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred` |
| **Ghidra name** | `FUN_0060df70` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-038) |
| **Counterpart** | `reviews/B_aa_0060df70_CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred.md` |
| **System** | missions-progression |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. Sibling duals MatchTargetCore / ApplyObjectUseProgress / Eval. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

UseItem requirement **virtual object-event dispatch** (vtbl **+0x04**): on events **9|10** only, gate by Eval-incomplete + optional `req+0x54`, run **MatchTargetCore**, then either **ApplyObjectUseProgress** (event 10 or `req+0x34==0`) or **FUN_005319d0** UI/logic packet arm (event 9 + flag).

Sole code caller of dualed `ApplyObjectUseProgress` (`0x0060d630`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-038 append) | `docs/reconstruction/raw/aa_0060df70_FUN_0060df70.md` |
| Annotated | `docs/reconstruction/raw/aa_0060df70_FUN_0060df70.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0060df70.cpp` |
| Sibling Apply | `aa_0060d630` dual sealed WQ7R-H |
| Sibling Match | `aa_0060d460` dual sealed |
| Vtable | `PTR_FUN_009dfc1c`; slot `009dfc20` → this |

**Not performed:** `disassemble_bytes`; Launcher runtime Confirmed.

---

## 3. Signature (sealed)

```c
// ECX = UseItemReq*; 7 stack dwords; RET 0x1C; AL status
uint8_t __thiscall ObjectEventDispatch(
    UseItemReq* self,
    void* charCtx,       // +0x04
    void* progress,      // +0x08
    int eventId,         // +0x0C  ∈ {9,10}
    uint32_t a4,         // +0x10 unread
    uint32_t a5,         // +0x14 unread
    uint32_t a6,         // +0x18 unread
    void* worldObj);     // +0x1C
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| charCtx | `[ESP+0x14]` after 4 pushes → EBP | **High** |
| progress | `[ESP+0x18]` → EBX | **High** |
| eventId | `[ESP+0x1C]` → EDI; CMP 9/10 | **High** |
| worldObj | `[ESP+0x2C]` after 4 pushes = entry+0x1C | **High** |
| cleanup | `C2 1C 00` both exits | **High** |
| fail AL | `32 C0` at `0060e04f` | **High** |

---

## 4. Control flow (bytes authority)

| Stage | Match | Conf |
|---|---|---|
| Event ∉ {9,10} → fail | `CMP EDI,9/A` / `JNZ e04f` | **High** |
| Eval vcall +8 incomplete | `CALL [EAX+8]; TEST AL; JNZ` | **High** |
| `req+0x54` optional MI `+0xFC` | `MOV EAX,[ESI+54]; CMP -1` | **High** |
| MatchTargetCore | `CALL 0060d460; TEST AL; JZ` | **High** |
| event10 OR `+0x34==0` → Apply | `CMP EDI,A; JZ e058` / `CMP [ESI+34],0` | **High** |
| Apply call + return AL | `CALL 0060d630` then pop/ret (no XOR) | **High** |
| else scan parent `+0x158` vector | loop `CMP ESI,[EAX+ECX*4]` | **High** |
| packet `FUN_005319d0` + COID×4 | stack build from `worldObj+0x160` | **High** |
| packet path → XOR AL | fall to `e04f` | **High** |

Clean named CF ≡ raw decompile CF ≡ live disassembly stages above.

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | virtual worker (vtbl +0x04) |
| Code callers | **none** (virtual only) |
| DATA xrefs | `0x009dfc20` |
| Downstream | sole caller of `ApplyObjectUseProgress` |

---

## 6. Gaps

1. Product English for **event 9 vs 10**.
2. Full product contract of `FUN_005319d0` / LogicUi type `0xE`.
3. Names of unread stack slots +0x10..+0x18 (base signature).
4. Why packet arm forces AL=0 after call.
5. Runtime / bit-exact / differential — open.

---

## 7. Verdict

CF/ABI/RET0x1C/event gate/Match+Apply branch/vtbl slot/UseItem class sealed via image + sibling duals. Product residual on event English and packet helper → **accept-with-gaps**.
