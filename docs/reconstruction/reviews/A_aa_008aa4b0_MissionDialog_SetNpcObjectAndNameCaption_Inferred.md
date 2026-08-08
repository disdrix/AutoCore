# Review A (reconstruction fidelity): `aa_008aa4b0` MissionDialog_SetNpcObjectAndNameCaption_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa4b0` |
| **VA** | `0x008aa4b0`–`0x008aa50e` inclusive (**95 B** / `0x5F`) |
| **Canonical name** | `MissionDialog_SetNpcObjectAndNameCaption_Inferred` |
| **Ghidra name** | `FUN_008aa4b0` |
| **Prior scaffold** | `Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa4b0` (**retired**) |
| **Review date** | `2026-08-05` (MEGA-058 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_008aa4b0_MissionDialog_SetNpcObjectAndNameCaption_Inferred.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + caller disasm (`FUN_009373e0`, ShowNpc call-site framing). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Mission-dialog helper that:

1. Stamps **NPC object*** into `dialog+0x644`.
2. Binds or clears the **NPC-name caption** widget at `dialog+0x6d8` via **vtbl+0x1d8** / refresh **vtbl+0x34c**.

Used on ShowNpc present paths and as the **dialog helper immediately before thr/steer/HB park** in `FUN_009373e0`.

```text
MissionDialog_SetNpcObjectAndNameCaption_Inferred(ESI=dialog, EAX=npc):
  dialog+0x644 = npc
  w = dialog+0x6d8
  if !w: return
  if npc == 0:
    w->vtbl+0x1d8(&empty_cstr, 1, 1)
  else:
    name = npc_secondary->vtbl+0x160(1, 1)
    w->vtbl+0x1d8(name)          // one stack arg
  JMP w->vtbl+0x34c              // tail refresh
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold raw CF (2026-07-23) |
| Body bounds | `get_function_by_address` → `008aa4b0`–`008aa50e` |
| Full bytes | `read_memory` 95 B body + `CC` pad |
| Full disasm | `disassemble_function` (30 insns) |
| analyze complete | leaf; 3 xrefs; callers ShowNpc + `FUN_009373e0` |
| Parent dual | `A/B_aa_009438f0_Client_ShowNpcMissionDialogUI` (`+0x644` NPC) |
| Header sibling | dualed `Client_MissionDialog_SetHeaderCaption_Inferred` `+0x6e0` / same paint pair |
| Raw re-verify | `docs/reconstruction/raw/aa_008aa4b0_FUN_008aa4b0.md` MEGA-058 append |
| Clean | `reconstructed-exact/MissionDialog_SetNpcObjectAndNameCaption_Inferred.cpp` |

---

## 3. Signature (sealed)

```c
// ESI = dialog*; EAX = npcObject* (0 clear); plain RET
void MissionDialog_SetNpcObjectAndNameCaption_Inferred(void /* register formals */);
```

| Formal | Source | Conf |
|---|---|---|
| dialog | **ESI** (ShowNpc: EBX; park gate: `[client+0x1058]`) | **Confirmed** |
| npc | **EAX** (ShowNpc: `[ESP+0x18]` param_2; park: `[ESP+8]` arg) | **Confirmed** |
| cleanup | plain **`RET`** (`C3`) | **Confirmed** |
| stack args | none | **Confirmed** |
| classification | leaf (virtual only) | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Load `+0x6d8` / store `+0x644` / null widget RET | bytes + decomp | **Confirmed** |
| Clear branch three-arg `+0x1d8` empty cstr | `6A 01 6A 01 68 9B 41 A1 00` | **Confirmed** |
| Bind branch GetName `+0x160`(1,1) | `FF 92 60 01 00 00` | **Confirmed** |
| Bind branch one-arg `+0x1d8` | single `PUSH EAX` | **Confirmed** |
| Tail **JMP** `+0x34c` (not CALL) | `FF A2 4C 03 00 00` | **Confirmed** |
| Decompiler "jumptable" warning | false positive on tail JMP | **Confirmed** |
| Live ≡ raw ≡ clean CF | no invented branches | **Confirmed** |

---

## 5. Callers (sealed)

| Site | Parent | ESI | EAX |
|---|---|---|---|
| `0x0094397d` | ShowNpc multi-active early | EBX dialog | `[ESP+0x18]` NPC |
| `0x00943a75` | ShowNpc main present | EBX dialog | `[ESP+0x18]` NPC |
| `0x00937411` | `FUN_009373e0` pre thr/steer park | `[EDI+0x1058]` | `[ESP+8]` |

Xref count **3** UNCONDITIONAL_CALL. Scaffold "CalleeOf ShowNpc only" is **incomplete**.

---

## 6. Gaps

1. Product/PDB English (`_Inferred` retained).
2. Product names for vtbl `+0x160` / `+0x1d8` / `+0x34c` and widget class at `+0x6d8`.
3. Exact GetName return type (C-string vs string object*).
4. Why clear uses 3-arg SetText and bind uses 1-arg on the same slot (preserved).
5. Runtime / bit-exact / differential (terminal false).

---

## 7. Verdict

**accept-with-gaps** — register ABI, `+0x644` stamp, `+0x6d8` caption bind/clear, vcall arities, tail-jump refresh, and 3-site caller framing sealed; product English and vtable dictionary open.
