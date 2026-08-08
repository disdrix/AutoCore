# Review A (reconstruction fidelity): `aa_007f74a0` ActionMap_ClearAllSlotBindFields_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f74a0` |
| **VA** | `0x007f74a0`–`0x007f7560` |
| **Canonical name** | `ActionMap_ClearAllSlotBindFields_Inferred` |
| **Ghidra name** | `FUN_007f74a0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-019) |
| **Counterpart** | `reviews/B_aa_007f74a0_ActionMap_ClearAllSlotBindFields_Inferred.md` |
| **System** | input-drive-control |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leaf ActionMap **slot-field clear / prologue**: for every slot in four mode banks (counts `5 / 6 / 0x78 / 0x14`, stride `0x34`), zero primary+alt DIK/mod pairs, customized flag, and two status bytes. Sole static caller is `Client_InitDefaultKeybinds` (`0x007f8720`) as its first action.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-019 append) | `docs/reconstruction/raw/aa_007f74a0_FUN_007f74a0.md` |
| Annotated | `docs/reconstruction/raw/aa_007f74a0_FUN_007f74a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ActionMap_ClearAllSlotBindFields_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007f74a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_007f74a0_FUN_007f74a0.md` |
| Function named | `docs/reconstruction/functions/aa_007f74a0_ActionMap_ClearAllSlotBindFields_Inferred.md` |
| Parent | `Client_InitDefaultKeybinds` `0x007f8720` |
| Sibling | `ActionMap_TrySetSlotBind` `0x007f72e0` (dualed W21-P) |
| Live | decompile ≡ raw CF; body 193 B; final `C3`; 1 UNCONDITIONAL_CALL |

---

## 3. Signature (sealed)

```c
// ESI = ActionMap*; no stack args; void; bare RET
void ActionMap_ClearAllSlotBindFields_Inferred(uint8_t* actionMap /* ESI */);
```

| Formal | Source | Conf |
|---|---|---|
| actionMap | **ESI** (`MOV ESI,EDI` @ caller `0x007f8723`) | **High** |
| stack args | none | **High** |
| return | void (EAX left 0; unused) | **High** |
| epilogue | bare `RET` (`C3`) | **High** |
| not thiscall | ECX is loop cursor, not `this` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
ESI = map
for bank in { (+0x32,5), (+0x136,6), (+0x26e,0x78), (+0x1ace,0x14) }:
  ECX = ESI + bank.cursor
  EDX = bank.count
  EAX = 0
  do:
    zero key1/mod1/key0/mod0 (u16)
    zero clA/clB/flag (u8)
    ECX += 0x34
    EDX--
  while EDX != 0
RET
```

| Stage | Match | Conf |
|---|---|---|
| Four counted banks | **Yes** | **High** |
| Stride `0x34` | **Yes** | **High** |
| Bounds 5 / 6 / 0x78 / 0x14 | **Yes** | **High** |
| 7 fields/slot zero | **Yes** | **High** |
| Offsets ≡ TrySetSlotBind tables | **Yes** | **High** |
| Leaf / no callees | **Yes** | **High** |
| Sole caller InitDefaultKeybinds | **Yes** (static) | **High** |

---

## 5. Machine bytes (`read_memory` + `disassemble_function`)

Body **193 B** (`0xC1`) through final `RET` @ `0x007f7560`. Head:

```
8D 4E 32          LEA ECX,[ESI+0x32]
BA 05 00 00 00    MOV EDX,5
33 C0             XOR EAX,EAX
...
83 C1 34          ADD ECX,0x34
83 EA 01          SUB EDX,1
75 E0             JNZ loop
...
C3                RET
```

Pad `CC` after RET.

---

## 6. Gaps

- Product English for four mode groups.
- Exact product symbol (no demangle at VA).
- Runtime / bit-exact / differential (no Launcher).
- Theoretical non-static computed callers (none in static xrefs).

## Verdict rationale

All control flow, ABI (ESI base), bank counts, stride, and field offsets sealed **High** from live bytes + sole caller + dualed sibling tables. Residual is product naming only → **accept-with-gaps** (`_Inferred`).
