# Review A (reconstruction fidelity): `aa_007f6db0` ActionMap_FindSlotByKeyMod_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f6db0` |
| **VA** | `0x007f6db0`–`0x007f6fa3` |
| **Canonical name** | `ActionMap_FindSlotByKeyMod_Inferred` |
| **Ghidra name** | `FUN_007f6db0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-018) |
| **Counterpart** | `reviews/B_aa_007f6db0_ActionMap_FindSlotByKeyMod_Inferred.md` |
| **System** | input-drive-control |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + parent decompile |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leaf ActionMap **slot lookup**: for mode group `0..3`, scan slots of stride `0x34` for a primary or alt DIK match against `keyCode`, accepting when mod-state zeroness agrees with the bound mod **or** when the per-slot override flag is set. Returns pointer to the matched slot's **key0** field (or NULL).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_007f6db0_FUN_007f6db0.md` |
| Annotated | `docs/reconstruction/raw/aa_007f6db0_FUN_007f6db0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ActionMap_FindSlotByKeyMod_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007f6db0.cpp` |
| Function record | `docs/reconstruction/functions/aa_007f6db0_FUN_007f6db0.md` |
| Function named | `docs/reconstruction/functions/aa_007f6db0_ActionMap_FindSlotByKeyMod_Inferred.md` |
| Parent | `Client_Input_OnKeyDown_MatchAction` `0x00911030` call `@0x00911429` |
| Sibling | dualed `ActionMap_TrySetSlotBind` `0x007f72e0` (same mode/offset family) |
| Live | decompile ≡ raw CF; body 756 B; JT `@0x007f6fa4`; all exits `C3` |

---

## 3. Signature (sealed)

```c
// EAX=mode EDI=map SI=key DX=modState; RET 0; EAX = &slot.key0 or NULL
uint16_t* ActionMap_FindSlotByKeyMod_Inferred(
    uint32_t mode, uint16_t keyCode, uint16_t modState, uint8_t* actionMap);
```

| Formal | Source | Conf |
|---|---|---|
| mode | **EAX** (`CMP EAX,3` + JT) | **High** |
| actionMap | **EDI** | **High** |
| keyCode | **SI** | **High** |
| modState | **DX** (`TEST DX,DX`) | **High** |
| return | **EAX** key0* / NULL; bare **RET** | **High** |

Decompiler `__fastcall` / `unaff_*` / `in_EAX` are phantoms of this register contract.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if mode > 3: return NULL
jmp jt[mode]
case m:
  i=0; cursor = base + mod0[m]
  while i < max[m]:
    if key0==SI: if same_zeroness(DX,mod0) OR flag: return key0_ptr
    if key1==SI: if same_zeroness(DX,mod1) OR flag: return key0_ptr
    i++; cursor += 0x34
  return NULL
```

| Stage | Match | Conf |
|---|---|---|
| Switch 0..3 + jump table | **Yes** | **High** |
| Stride 0x34 index math | **Yes** | **High** |
| Bounds 5 / 6 / 0x78 / 0x14 | **Yes** | **High** |
| Dual-lane key/mod + override | **Yes** | **High** |
| Leaf / no callees | **Yes** | **High** |
| Sole caller ABI (mode0/EDI/SI/DX) | **Yes** | **High** |
| Mode product English | open | Tentative |

---

## 5. Machine bytes (`read_memory` + `disassemble_function`)

- Body `0x007f6db0`–`0x007f6fa3` inclusive (**756 B** / `0x2F4`).
- Jump table dwords @ `0x007f6fa4`: `0x007f6dbc, 0x007f6e2f, 0x007f6eab, 0x007f6f27`.
- Index math: `lea [ecx*8]; sub ecx; add eax,eax; sub ecx; lea [edi+eax*4+off]` → `i*0x34`.
- All success/fail paths end in bare `RET` (`C3`).

Mode-0 key0/mod0 bases (`+0x06` / `+0x30`) match dualed TrySetSlotBind tables and parent fallback `DAT_00d1bbee` / `DAT_00d1bc18` = base+0x242 / +0x26c (mode 2 of same map `0x00d1b9ac`).

---

## 6. Gaps

- Product English for four mode groups.
- Product name of override flag (key0+0x30).
- Live call sites for modes 1–3 (only mode 0 observed).
- Runtime / bit-exact / differential (Terminal false).

## Verdict rationale

CF, register ABI, bounds, dual-lane match, and family offsets sealed **High** from bytes + sole caller + sibling setter. Residual is product naming / unobserved modes → **accept-with-gaps**.
